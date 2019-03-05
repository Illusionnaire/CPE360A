#include <iostream>
using namespace std;

class Chunk {
public:
    int x;
    Chunk *next;

    Chunk() : x(0), next(NULL){}
};

//class called "Stack" which is going to create a stack of Chunks
class Stack {
public:
    Chunk *top; //main pointer is called "top"
    
    Stack() : top(NULL) {}
    
    //three function that Stack should perform: add, remove, and display
    //l: function to add chunks to our stack
    void push(int value) {
        //If it is empty:
        if(top == NULL){
            top = new Chunk;
            top->x = value;
        }
        else{
            Chunk *temp;
            temp = new Chunk;
            temp->x = value;
            temp->next = top;
            top = temp;
        }
    }

    //2: a function that deletes from the stack
    void pop(){
        if(top == NULL){
            cout << "Nothing to delete" << endl;
            return;
        }
        else {
            Chunk *temp;
            temp = top;
            top = top->next;
            delete temp;

        }
    }

    //3: Display all the chunks that you have
    void display() {
        //if it is empty:
        if(top == NULL){
            cout << "Empty Stack" << endl;
        }
        else{
            Chunk *temp = top;
            while(temp != NULL){
                cout << temp->x << "-->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main(){
    Stack myStack;
    int choice = 0;
    int value;
    while(true){
        cout << "Press 1 to add" << endl;
        cout << "Press 2 to delete" << endl;
        cout << "Press 3 to display" << endl;
        cin >> choice;
        switch(choice){
            case(1): 
                cout << "Add what?" << endl;
                cin >> value;
                myStack.push(value);
                break;
            case(2):
                myStack.pop();
                break;
            case(3):
                myStack.display();
                break;
        }
    }


    return 0;
}


