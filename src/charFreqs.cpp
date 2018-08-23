using namespace std;
#include <map>
#include <istream>
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
