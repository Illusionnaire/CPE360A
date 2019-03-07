#include <iostream>
using namespace std;

class Chunk{
public:
    int value;
    Chunk *next;

    Chunk() : value(0), next(NULL){}
};

class Queue{
    public:
    Chunk *head;

    Queue(): head(NULL){}

    //1. Function that lets you add chunks to the Queue (enqueue)
    void enqueue(int value){
        if (head == NULL){
            head = new Chunk;
            head->value = value;
        }
        else {
        Chunk *helper = new Chunk;
        helper->value = value;
        helper->next = head;
        head = helper;
        }
    }

    //2. Function that lets you remove things from the Queue (dequeue)
    void dequeue(){
        if(head == NULL){
            cout << "Error. Nothing to delete.";
        }
        else if(head->next == NULL){
            cout << "About to delete: " << head->value << endl;
            delete head;
            head = NULL;
        }
        else{
            Chunk *helper,*follow;
            helper = follow = head;
            //While there is a next chunk, go to the next chunk
            while(helper->next != NULL){
                follow = helper;
                helper= helper->next;
            }
            //Helper now at the last chunk
            follow->next = NULL;
            cout << "About to delete: " << helper->value << endl;
            delete helper;
        }
    }

    //3. Display contents of the Queue
    void display(){
        if (head == NULL){
            cout << "Empty Queue" << endl;
        }
        else{
            Chunk *helper = head;
            while(helper != NULL){
                cout << "[" << helper->value << "]";
                helper = helper->next;
            }
                cout << endl;
        }

    }

};


int main(){
    Queue q;
    int choice, value;
    while(true){
        cout << "Press 1 to add" << endl;
        cout << "Press 2 to delete" << endl;
        cout << "Press 3 to display" << endl;
        cin >> choice;
        switch(choice){
            case(1): 
                cout << "Add what?" << endl;
                cin >> value;
                q.enqueue(value);
                break;
            case(2):
                q.dequeue();
                break;
            case(3):
                q.display();
                break;
        }
    }


    return 0;
}