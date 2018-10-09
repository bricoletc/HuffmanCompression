using namespace std;
#include <iostream>
#include <fstream>
#include "map.h"
#include "HeapPriorityQueue.h"
#include "bitstream.h"


void compress(istream& input, obitstream& output){
	
	Map<int, int> buildFrequencyTable(istream& input);
	Map<int,int> freqTable = buildFrequencyTable(input);

	output << freqTable;

	HuffmanNode* buildEncodingTree(Map <int,int>& freqTable);
	HuffmanNode* encodingTree = buildEncodingTree(freqTable);	


	Map<int, string> buildEncodingMap(HuffmanNode* encodingTree);
	Map<int,string> encodingMap=buildEncodingMap(encodingTree);

	
	void encodeData(istream& input, Map<int, string>& encodingMap,
		obitstream& output);

	void rewindStream(istream& input);
	rewindStream(input);

	encodeData(input, encodingMap, output);


}

void decompress(ibitstream& input, ostream& output){

	Map<int,int> freqTable;
	input >> freqTable;

	HuffmanNode* buildEncodingTree(Map <int,int>& freqTable);
	HuffmanNode* encodingTree = buildEncodingTree(freqTable);	
	
	void decodeData(ibitstream& input, HuffmanNode* encodingTree, ostream& out);
	decodeData(input, encodingTree, output);
}
