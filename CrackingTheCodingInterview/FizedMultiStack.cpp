#include<iostream>
#include<vector>
using namespace std;

class FixedMultiStack {
    int numberOfStacks = 3; //how many stacks to represent in the array
    int stackCapacity;      //capacity of each stack
    int values[];           //values stored in the array
    int sizes[];            //size of each stack during the process

    public:
    void FizedMultiStack(int stackSize) {
        stackCapacity = stackSize;  //assuming all the stacks have the same size
        values = new int[stackCapacity*numberOfStacks];
        sizes = new int[numberOfStacks];
    }

    bool isEmpty(int stackNum) {
        return sizes[stackNum] == 0;
    }

    bool isFull(int stackNum) {
        return sizes[stackNum] == stackCapacity;
    }

    int indexOfTop(int stackNum) {
        int offset = stackNum*stackCapacity;
        int size = sizes[stackNum];
        return offset + size - 1;
    }

    void push(int stackNum, int value) {
        if(isFull(stackNum)) {
            cout<<"Stack is full\n";
            return;
        }

        sizes[stackNum]++;
        values[indexOfTop(stackNum)] = value;
    }

    int pop(int stackNum) {
        if(isEmpty(stackNum)) {
            cout<<"Stack is empty\n";
            return -1;
        }
        int topIndex = indexOfTop(stackNum);
        int value = values[topIndex];
        values[topIndex] = 0;
        sizes[stackNum]--;
        return value;
    }

    int peek(int stackNum) {
        if(isEmpty(stackNum)) {
            cout<<"Stack is empty\n";
            return -1;
        }
        return values[indexOfTop(stackNum)];
    }
};