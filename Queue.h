
#ifndef queue_h
#define queue_h
#include "Node.h"
class Queue {
	NodePtr headPtr,tailPtr;
	int size;
public:
    void enqueue(int);
    int dequeue();
    Queue();
    ~Queue();
};

void Queue::enqueue(int x){
    NodePtr new_node = new NODE(x);
    if(new_node){ 
        if(size > 0){
            tailPtr->set_next(new_node);
        }
        else{
            headPtr = new_node;
        }
        tailPtr = new_node;
        size++;
    }
}

int Queue::dequeue(){
    if(size > 0){
        NodePtr t = headPtr;
        int x = t->get_value(); 
        headPtr = headPtr->get_next();
        size--;

        if(size == 0){
            tailPtr = 0;
        }

        delete t;
        return x;
    }

    cout << "Empty Queue";
    return -1;
}

Queue::Queue(){
    size = 0;
    headPtr , tailPtr = 0;
}

Queue::~Queue(){
      cout << "Dequeue all" << endl;
    //delete all remaning Queue (i.e. DQ all) 
    int n= size;
    for(int i=0; i < n; i++){
        dequeue();
    } 
}


#endif
