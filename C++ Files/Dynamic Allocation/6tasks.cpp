#include <iostream>
using namespace std;

class Chunk {
public:
    int x;
    Chunk *next;

    Chunk() : x(0), next(NULL) {}
};



int main(){

    Chunk *head, *helper;

    //Task 0: Create three chunks in the heap, such that they are linked together in a linear way. 
    head = new Chunk;
    head->next = new Chunk;
    head->next->next = new Chunk;

    //Task 1: Insert a new chunk at the very beginning of this list 
    helper = new Chunk;
    helper->next = head;
    head = helper;

    //Task 2: Delete this chunk 
    helper = head;
    head = head->next;
    delete helper;

    // Task 3: Insert a chunk at the very end of the list 
    helper = new Chunk;
    head->next->next->next = helper;
        //Can also just do: head->next->next->next = new Chunk;

    // Task 4: Delete this chunk 
    helper = head->next->next->next;
    head->next->next->next = NULL;
    delete helper;

    // Task 5: Insert a new chunk somewhere in the middle of the list 
    helper = new Chunk;
    helper->next = head->next;
    head->next = helper;

    // Task 6: Delete this chunk 
    helper = head->next;
    head->next = head->next->next;
    delete helper;

    return 0;
}