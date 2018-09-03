#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(int character, int count, HuffmanNode* zero, HuffmanNode* one){
	this->character=character;
	this->count=count;
	this->zero=zero;
	this->one=one;
}


bool operator <(const HuffmanNode& pqe1, const HuffmanNode& pqe2) {
    return pqe1.count < pqe2.count ||
            (pqe1.count == pqe2.count && pqe1.character < pqe2.character);
}

bool operator ==(const HuffmanNode& pqe1, const HuffmanNode& pqe2) {
    return pqe1.count == pqe2.count && pqe1.character == pqe2.character;
}

bool operator !=(const HuffmanNode& pqe1, const HuffmanNode& pqe2) {
    return !(pqe1 == pqe2);
}

bool operator <=(const HuffmanNode& pqe1, const HuffmanNode& pqe2) {
    return pqe1 < pqe2 || pqe1 == pqe2;
}

bool operator >(const HuffmanNode& pqe1, const HuffmanNode& pqe2) {
    return !(pqe1 <= pqe2);
}

bool operator >=(const HuffmanNode& pqe1, const HuffmanNode& pqe2) {
    return !(pqe1 < pqe2);
}

/**
ostream& operator <<(ostream& out, const HuffmanNode& pqe) {
    out << "\"" << pqe.character << "\":" << pqe.count;
    return out;
}
**/

ostream& operator <<(ostream& out, const HuffmanNode& pqe) {
	out << &pqe << '\t' << pqe.zero << '\t' << pqe.one ;
	return out;
}
