#ifndef _huffmanNode_h
#define _huffmanNode_h

#include <string>
#include <iostream>
#include <bitstream.h>

using namespace std;

struct HuffmanNode {
public:
    int character;
    int count;
    HuffmanNode* zero;
    HuffmanNode* one;

    HuffmanNode(int character = NOT_A_CHAR, int count = 0, HuffmanNode* one=NULL, HuffmanNode* zero=NULL);
};


bool operator <(const HuffmanNode& pqe1, const HuffmanNode& pqe2);
bool operator <=(const HuffmanNode& pqe1, const HuffmanNode& pqe2);
bool operator ==(const HuffmanNode& pqe1, const HuffmanNode& pqe2);
bool operator !=(const HuffmanNode& pqe1, const HuffmanNode& pqe2);
bool operator >(const HuffmanNode& pqe1, const HuffmanNode& pqe2);
bool operator >=(const HuffmanNode& pqe1, const HuffmanNode& pqe2);
ostream& operator <<(ostream& out, const HuffmanNode& pqe);


#endif
