using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include "HeapPriorityQueue.h"
int main(){

	ifstream myfile ("example.txt");		
	map<int, int> buildFrequencyTable(istream& input);
	map<int,int> freqTable = buildFrequencyTable(myfile);
	
	HeapPriorityQueue PQueue;
	for (map<int,int>::iterator it=freqTable.begin(); it!=freqTable.end(); ++it)
//	      cout << it->first << " => " << it->second << '\n';
		PQueue.enqueue(it->first,it->second);
	return 0;
}
