using namespace std;
#include "map.h" 
#include <map>
#include <istream>
#include "bitstream.h"
#include "HeapPriorityQueue.h"
#include "HuffmanNode.h"

Map<int, int> buildFrequencyTable(istream& input){
	Map<int, int> freqTable;
	char ch;
	while (input.get(ch)){
		if (freqTable.containsKey(ch)>0)
			freqTable[ch]++;
		else
			freqTable[ch]=1;
	}
	freqTable[PSEUDO_EOF]=1;
	return freqTable;
}

HuffmanNode* buildEncodingTree(Map<int, int>& freqTable){
	
	HeapPriorityQueue PQueue;
    	map<int,int> stlMap=freqTable.toStlMap(); //Convert to STL map to use ->first and ->second iterator access

	for (map<int,int>::iterator it=stlMap.begin(); it!=stlMap.end(); ++it){
//	      cout << it->first << " => " << it->second << '\n';
		HuffmanNode* hf=new HuffmanNode(it->first,it->second);
		PQueue.enqueue(hf);
	}

	int queueSize=PQueue.size();

	while (queueSize>1){
		HuffmanNode* hf1=PQueue.dequeue();
		HuffmanNode* hf2=PQueue.dequeue();
		int parent_count=hf1->count+hf2->count;
		int parent_char=NOT_A_CHAR;
		HuffmanNode* parent= new HuffmanNode(parent_char,parent_count,hf1,hf2);
		PQueue.enqueue(parent);
		queueSize=PQueue.size();
	}
	HuffmanNode* root=PQueue.dequeue();
	return root;
}


void DFS_traversal(Map<int,string>* m, string curBits, HuffmanNode* root){
	if (root->character!=NOT_A_CHAR){
		(*m)[root->character]=curBits;
	}

	else {
		HuffmanNode* zero_node=root->zero;
		HuffmanNode* one_node=root->one;

		string newBits=curBits+"0";
		DFS_traversal(m,newBits,zero_node);	

		newBits=curBits+"1";
		DFS_traversal(m,newBits,one_node);
	}

}

Map<int, string> buildEncodingMap(HuffmanNode* encodingTree){
	Map<int,string> encodingMap;
//	Map<int,string>* m=&encodingMap;
	string curBits="";
	DFS_traversal(&encodingMap, curBits, encodingTree);
	return encodingMap;
}

//Write out compressed representation to obitstream
void encodeData(istream& input, Map<int, string>& encodingMap,
		obitstream& output){
	
	char ch;
	string codeBits;
	int i;
	while (input.get(ch)){
		codeBits=encodingMap[ch];
			for (i=0;codeBits[i]!='\0';i++){
				output.writeBit(codeBits[i]-'0');
			}
	}

	//Write EOF mark 
	codeBits=encodingMap[PSEUDO_EOF];
	for (i=0;codeBits[i]!='\0';i++){
		output.writeBit(codeBits[i]-'0');
	}
}


void rewindStream(std::istream& input) {
    input.clear();                  // removes any current eof/failure flags
    input.seekg(0, std::ios::beg);  // tells the stream to seek back to the beginning
}

void decodeData(ibitstream& input, HuffmanNode* encodingTree, ostream& out){
	int decoded;
	int bit;
	HuffmanNode* curPos=encodingTree;
	while(true){
		bit=input.readBit();
		if (bit==0) curPos=curPos->zero;
		else if (bit==1) curPos=curPos->one;
		else exit(1);

		decoded=curPos->character;

		if (decoded!=NOT_A_CHAR){
			if (decoded==PSEUDO_EOF) break; //Found terminating mark, stop decoding.
			out.put(decoded);
			curPos=encodingTree; //Reset the positioning in the encoding tree.
		}
		
	}

}
