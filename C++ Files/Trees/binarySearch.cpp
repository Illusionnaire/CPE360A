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
        if(root == NULL){
            root = new TreeNode;
            root->value = key;
            return;
        }
        else {
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
    }

    //Delete values
    //a) Find the node 
    //b) Figure out what kind of a node this is..
    void deleteNodeBST(int key, TreeNode *start) {
        if (start->value == NULL){
            cout << "The Tree is empty";
        }
        else{
            //Loop through to find key value
            TreeNode *fast, *slow;
            fast = slow = start;

            while(fast != NULL){
                if(fast->value == key){
                    break;
                }
                else{
                    cout << "Value not found in tree";
                }
            }

            //Case I: leaf node( has not children)
            if(fast->left == NULL && fast->right == NULL){
                if(slow->left == fast){
                    delete fast;
                    slow->left = NULL;
                }
                else{
                    delete fast;
                    slow->right = NULL;
                }
            }
            //Case II: Has exactly one child
            //Four if statements to see if it is left/right and inner left/right that needs to be replaced
            else if(fast->left == NULL || fast->right == NULL){
                if (slow->right == fast){
                    if (fast->left == NULL){
                        slow->right = fast->right;
                }
                else{
                        slow->right = fast->left;
                }
                }
                else {
                    if (fast->left == NULL){
                        slow->left = fast->right;
                }
                else{
                        slow->left = fast->left;
                }
                }
            }
            //Case III: Has two children 
            else{
                int replace = minValRSubTree(fast->right);
                fast->value = replace;
                deleteNodeBST(replace, fast->right);
            }
        }
    }

    int minValRSubTree(TreeNode *start){
        TreeNode *temp = start;
        while(temp->left != NULL){
            temp =temp->left;
        }
        return temp->value;
    }


    //Display tree's contents
    //Left -> Current -> Right
    void inorder(TreeNode *start){
        if(start == NULL){
            return;
        }
        else {
            inorder(start->left);
            cout << start->value << " " << endl;
            inorder(start->right);
        }
    }

    // Current -> Left -> Right : Pre = Root first
    void preorder(TreeNode *start){
        if(start == NULL){
            return;
        }
        else {
            cout << start->value << " " << endl;
            preorder(start->left);
            preorder(start->right);
        }
    }

    // Left -> Right -> Current : Post = Root Last
    void postorder(TreeNode *start){
        if(start == NULL){
            return;
            }
        else {
            inorder(start->left);
            inorder(start->right);
            cout << start->value << " " << endl;
        }
    }

};


int main() {
BST myTree;
int choice, value;
value = 0;
while(value < 7) {
    cout << "Press 1 to add to BST" << endl;
    cout << "Press 2 to search" << endl;
    cout << "Press 3 to delete" << endl;
    cout << "Press 4 for in-order" << endl;
    cout << "Press 5 for pre-order" << endl;
    cout << "Press 6 for post-order" << endl;
    cin >> choice;

    switch (choice){
        case 1: cout << "Add what?" << endl;
                cin >> value;
                myTree.addNodeBST(value);
                break;
        case 2: cout << "What are you looking for?" << endl;
                cin >> value;
                myTree.searchBST(value, myTree.root);
                break;
        case 3: cout << "That's the assignment!" << endl;
                break;
        case 4: myTree.inorder(myTree.root);
                break;
        case 5: myTree.preorder(myTree.root);
                break;
        case 6: myTree.postorder(myTree.root);
                break;
        default: return 0;
    }
}

return 0;
}