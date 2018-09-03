
#ifndef _heappriorityqueue_h
#define _heappriorityqueue_h

#include <iostream>
#include <string>
#include "HuffmanNode.h"
using namespace std;

/*
 * For documentation of each member, see VectorPriorityQueue.h.
 */
class HeapPriorityQueue {
public:
    HeapPriorityQueue(int binSize = 10);
    ~HeapPriorityQueue();
    void changePriority(int character, int newPriority);
    void clear();
    HuffmanNode* dequeue();
    void enqueue(HuffmanNode* hf);
    bool isEmpty() const;
    int peek() const;
    int peekPriority() const;
    int size() const;
    friend ostream& operator <<(ostream& out, const HeapPriorityQueue& queue);

private:
    int binSize;
    int fillPoint;
    HuffmanNode** binHeap;
    void bubbleUp(int curPos);
    void bubbleDown(int curPos);
    void HuffmanNodeSwap(int pos1,int pos2);

};

#endif
