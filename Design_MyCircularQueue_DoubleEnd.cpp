// 641. 设计循环双端队列
#include<vector>

class MyCircularQueue{
private:
    int front;
    int rear;
    int capacity;
    std::vector<int> elements;

public:
    MyCircularQueue(int k) {
        this->capacity = k + 1;
        this->elements = std::vector<int>(this->capacity);
        rear = front = 0;
    }
    
    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }

        front = (front - 1 + capacity) % capacity;
        elements[front] = value;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;

        elements[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;

        front = (front + 1) % capacity;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        
        return elements[front];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        
        return elements[(rear -1 + capacity) % capacity] ;
    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};