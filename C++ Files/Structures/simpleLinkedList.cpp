#include <iostream>
using namespace std;

class LinkedList{
public:
    Chunk* head;
    int length;

    //Constructor
    LinkedList(): head(NULL), length(0){}

    //Function to Add
    void insertAtPos(int x, int pos){
        if (pos > 0 && pos <= this->length + 1){
            //Able to add a valid chunk
            Chunk *temp = new Chunk;
            temp->value = x;

            //If adding to the front
            if (pos == 1){
                temp->next = this->head;
                head = temp;
            }
            //If adding to the end
            else if (pos == this->length + 1){
                Chunk *helper = this->head;
                for(int i = 1; i < length; i++){
                    helper = helper->next;
                } 
                    helper->next = temp;
            }
            //If adding to the middle
            else {
                Chunk *helper = head;
                for(int i = 1; i < pos - 1; i++){
                    helper = helper->next;
                }
                temp->next = helper->next;
                helper->next = temp;
            }
            
            this->length++;
        }   
        else {
            cout << "Invalid Position. Cannot Add Object." << endl;
        }

    }
    //Function to Delete
    void removeFromPos(int pos){
        //Is position valid?
        if(pos > 0 && pos <= this->length){
            Chunk *helper = this->head;
            //If removing from beginning
            if (pos == 1){
                this->head = this->head->next;
                delete helper;
            }
            //If removing from end
            if (pos == this->length){
                for(int i = 1; i < length - 1; i++){
                    helper = helper->next;
                }
                delete helper->next;
                helper->next = NULL;
            }
            //If removing from middle
            else {
                Chunk *deleteptr = head;
                for (int i = 1; i < pos; i++){
                    helper = deleteptr;
                    deleteptr = deleteptr->next;
                }
                helper->next = helper->next->next;
                delete deleteptr;
            }
        }
        else {
            cout << "Invalid Position, Cannot Delete Object." << endl;
        }
    }
    //Function to Display


};

class Chunk{
public:
    int value;
    Chunk* next;

    Chunk(): value(0), next(NULL){}

};

int main(){


    return 1;
}