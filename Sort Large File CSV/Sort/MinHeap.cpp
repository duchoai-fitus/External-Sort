#include "MinHeap.h"

#pragma region MINHEAP

void MinHeap::minHeapify(int i)
{
    int dataSize = data.size();
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < dataSize && data[left].getID() < data[smallest].getID())
        smallest = left;
    if (right < dataSize && data[right].getID() < data[smallest].getID())
        smallest = right;

    if (smallest != i)
    {
        swap(data[smallest], data[i]);
        minHeapify(smallest);
    }
}

HeapNode MinHeap::top()
{
    return data[0];
}

void MinHeap::push(HeapNode value)
{
    data.push_back(value);
    int i = data.size() - 1;

    while (i != 0 && data[(i - 1) / 2].getID() > data[i].getID())
    {
        swap(data[i], data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::pop()
{
    int dataSize = data.size();
    if (dataSize == 0)
        return;
    data[0] = data[dataSize - 1];
    data.pop_back();
    minHeapify(0);
}

bool MinHeap::empty()
{
    return data.size() == 0;
}

#pragma endregion MINHEAP

#pragma region HEAPNODE
HeapNode::HeapNode(string rowContent, int index)
{
    this->rowContent = rowContent;
    this->index = index;
}

string HeapNode::getID()
{
    stringstream s(this->rowContent);
    string ID;
    getline(s, ID, ',');
    return ID;
}

string HeapNode::getContent()
{
    return this->rowContent;
}

int HeapNode::getIndex()
{
    return this->index;
}

#pragma endregion HEAPNODE