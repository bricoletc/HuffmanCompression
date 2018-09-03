using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include "HeapPriorityQueue.h"
int main(){

	ifstream myfile ("example.txt");		
	map<int, int> buildFrequencyTable(istream& input);
	map<int,int> freqTable = buildFrequencyTable(myfile);

	HuffmanNode* buildEncodingTree(map <int,int>& freqTable);
	HuffmanNode* encodingTree = buildEncodingTree(freqTable);	


	map<int, string> buildEncodingMap(HuffmanNode* encodingTree);
	map<int,string> encodingMap=buildEncodingMap(encodingTree);

	

	for (map<int,string>::iterator it=encodingMap.begin(); it!=encodingMap.end(); ++it){
	      cout << it->first << " => " << it->second << '\n';
	}

}
