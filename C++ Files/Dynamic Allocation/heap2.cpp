#include <iostream>
using namespace std;

class Tab{
public:
    int width;
    int height;
    Tab *next;

    Tab() : width(30),height(30), next(NULL){}

};

int main(){
    Tab *head, *helper;

    //First Tab is created
    head = new Tab;

    //Chain tabs together such that previous points to it
    head->next = new Tab;
    head->next->next = new Tab;
    head->next->next->next = new Tab;

    //task1 : Delete the last chunk
    helper = head->next->next->next;
    delete helper;
    head->next->next->next = NULL;

    //task2 : add the fourth chunk back
    head->next->next->next = new Tab;

    //task3 : remove third chunk but do not lose fourth chunk
    helper = head->next->next;
    head->next->next = head->next->next->next;
    delete helper;

    //task4 : add chunk back into the third position
    helper = new Tab;
    helper->width = 412;
    helper->next = head->next->next->next;
    head->next->next = helper;

    cout << head->next->next->width;

    return 0;
}