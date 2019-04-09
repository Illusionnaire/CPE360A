#include <iostream>
using namespace std;

class TreeNode{
public:
    int value;
    TreeNode *right;
    TreeNode *left;

    //Constructor
    TreeNode() : value(0), right(NULL), left(NULL){}
};

class BST {
public:
    TreeNode *root;

    //Constructor
    BST() : root(NULL){}

    //Methods
    //Search for a value
    void searchBST(int key, TreeNode *start) {
        //Check if you did not find it
        if(start == NULL){
            cout << "Could not find it" << endl;
        }
        //Check to see if you found it
        else if(key == start->value){
            cout << "Found it!" << endl;
            return;
        }
        //Search one node deeper recursively
        else{
            if (key > start->value){
                searchBST(key,start->right);
            }
            else {
                searchBST(key,start->left);
            }
        }
    }

    //Add new values
    void addNodeBST(int key) {
        //start by searching for this value
        //If you find it, don't add it. If you don't find it, add it where you should have found it.
        TreeNode *slow, *fast;
        slow = fast = root;

        while ( fast != NULL){
            if (fast->value == key){
                cout << "Duplicate... not added" << endl;
            }
            else {
                if (key > fast->value){
                    slow = fast;
                    fast = fast->right;
                }    
                else {
                    slow = fast;
                    fast = fast->left;
                }
            }
        }
        //Once fast has fallen off of the tree, create the value that should be added.
        TreeNode *temp = new TreeNode;
        temp->value = key;
        //Insert it into the tree
        if (key < slow->value){
            slow->left = temp;
        }
        else {
            slow->right = temp;
        }
    }

    //Delete values
    

    //Display tree's contents

}