using namespace std;

#include "bitstream.h"


int main(){


	//Declare compression and decompression routines
	void compress(istream& input, obitstream& output);
	void decompress(ibitstream& input, ostream& output);

	//Compress
	ifstream myfile ("example.txt");		
	ofbitstream encodedData("Encoded.txt");
	compress(myfile,encodedData);
	encodedData.flush();

	//Decompress
	ifbitstream enData("Encoded.txt");
	ofstream decodedData("Decoded.txt");
	decompress(enData,decodedData);

}
