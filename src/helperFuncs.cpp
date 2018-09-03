using namespace std;
#include <map>
#include <istream>
#include "HeapPriorityQueue.h"
#include "HuffmanNode.h"

map<int, int> buildFrequencyTable(istream& input){
	map<int, int> freqTable;
	char ch;
	while (input.get(ch)){
		if (freqTable.count(ch)>0)
			freqTable[ch]++;
		else
			freqTable[ch]=1;
	}
	return freqTable;
}

HuffmanNode* buildEncodingTree(map<int, int>& freqTable){
	
	HeapPriorityQueue PQueue;
	for (map<int,int>::iterator it=freqTable.begin(); it!=freqTable.end(); ++it){
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


void DFS_traversal(map<int,string>* m, string curBits, HuffmanNode* root){
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
map<int, string> buildEncodingMap(HuffmanNode* encodingTree){
	map<int,string> encodingMap;
//	map<int,string>* m=&encodingMap;
	string curBits="";
	DFS_traversal(&encodingMap, curBits, encodingTree);
	return encodingMap;
}
