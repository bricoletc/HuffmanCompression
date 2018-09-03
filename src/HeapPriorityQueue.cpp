// This is a .cpp file you will edit and turn in.
// We have provided a skeleton for you,
// but you must finish it as described in the spec.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include "HeapPriorityQueue.h"
#include <cmath>

HeapPriorityQueue::HeapPriorityQueue(int binSize) {
	this->binSize = binSize;
	this->fillPoint = 0;
	this->binHeap = new HuffmanNode*[binSize];
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] this->binHeap;
}

void HeapPriorityQueue::changePriority(int character, int newPriority) {

	for (int i=1;i<=this->fillPoint;i++){
		if (this->binHeap[i-1]->character==character){
			int oldPriority=this->binHeap[i-1]->count;
			this->binHeap[i-1]->count=newPriority;
			if (oldPriority>newPriority) bubbleUp(i);
			else if (newPriority>oldPriority) bubbleDown(i);
			break;
		}
	}
}

void HeapPriorityQueue::clear() {
	while (this->fillPoint>0){
		this->binHeap[this->fillPoint--]=NULL;
//		cout << this->fillPoint << endl;
	}		
}

HuffmanNode* HeapPriorityQueue::dequeue() {
	if (fillPoint==0){
		throw "Cannot dequeue, as the PQueue is empty.";
	}
	HuffmanNode* dequeued=this->binHeap[0];
	this->binHeap[0]=this->binHeap[this->fillPoint-1];
	this->binHeap[this->fillPoint-1]=NULL;
	this->fillPoint--;
	bubbleDown(1);
    return dequeued;   
}

void HeapPriorityQueue::enqueue(HuffmanNode* hf) {
	binHeap[this->fillPoint++]=hf;
//If we've reached binHeap capacity, create a new binHeap, copying the old elements into it. Size gets doubled.
	if (this->fillPoint==this->binSize){
		HuffmanNode** new_binHeap=new HuffmanNode*[this->binSize*2]; 
		for (int i=1;i<=this->fillPoint;i++){
			new_binHeap[i-1]=this->binHeap[i-1];
		}
		delete[] this->binHeap;
		this->binHeap = new_binHeap;
		this->binSize*=2;
	}
	int curPos=this->fillPoint;
	bubbleUp(curPos);
	}	 


bool HeapPriorityQueue::isEmpty() const {
	if (this->fillPoint==0){
		return true;
	}
    return false;   // remove this
}

int HeapPriorityQueue::peek() const {
	if (this->fillPoint==0){
		throw "The PQueue is empty!";
	}
    return this->binHeap[0]->character;   // remove this
}

int HeapPriorityQueue::peekPriority() const {
	if (this->fillPoint==0){
		throw "The PQueue is empty!";
	}

    return this->binHeap[0]->count;   // remove this
}

int HeapPriorityQueue::size() const {
    return this->fillPoint;   // remove this
}

void HeapPriorityQueue::bubbleUp(int curPos) {
	
	//Bubble up
	while (curPos>1){	
	int parentPos=floor(curPos/2);
	if (this->binHeap[curPos-1]->count>=this->binHeap[parentPos-1]->count) break; //Priority ordering is respected, done bubbling.

	HuffmanNodeSwap(curPos-1,parentPos-1);
	}
}


void HeapPriorityQueue::bubbleDown(int curPos){
	while (curPos*2<=this->fillPoint){
		HuffmanNode* child1=this->binHeap[curPos*2-1];
		HuffmanNode* lowest=child1; //Default to child1
		int lowest_pos=curPos*2-1;
		if (curPos*2+1<=this->fillPoint) { //Test if the second child is present, computing lowest (count then character)
			HuffmanNode* child2=this->binHeap[curPos*2];
			if (*child2<*child1) {
				lowest=child2;
				lowest_pos++;
			}
		}	

		if (*(this->binHeap[curPos-1])<=*lowest) break; //Priority order is good, stop.

		HuffmanNodeSwap(curPos-1, lowest_pos);

		curPos=lowest_pos;

	}	
}

void HeapPriorityQueue::HuffmanNodeSwap(int pos1, int pos2) {
	
	HuffmanNode* tmp_ptr=this->binHeap[pos1];
	this->binHeap[pos1]=this->binHeap[pos2];
	this->binHeap[pos2]=tmp_ptr;
}

ostream& operator<<(ostream& out, const HeapPriorityQueue& queue) {
	out << "{";
	for (int i=1;i<=queue.fillPoint;i++){
		out << queue.binHeap[i-1] << ", " ;
	}
	out << "}";
    return out;
}
