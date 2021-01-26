#include <iostream>
#include <string>
#include "RedBlackTree.h"
#include <assert.h>

using namespace std; 

// constructor 
RedBlackTree::RedBlackTree()
{   
	// no action needed 
}
RedBlackTree::~RedBlackTree()
{
	// starting from the maximum
	// delete the tree
}

/*

2) If tree is not empty, insert the newNode as leaf node with color red
3) If the parent of newNode is black then exit from the operation
4) If the parent of newNode is Red then check the color of parent's sibling
5) If uncle is colored black or null then make suitable rotation and recolor it
6) If uncle is colorded red then perform recolor. Repeat the same until tree becomes proper red black tree 
*/

void RedBlackTree::Insert(int x)
{    
    int red = 1;
    int black = 0;
    // 1: If tree is empty, insert the newNode as Root node with color black and exit from operation
	if (numItems == 0) // create a node, make the node the root node 
	{
		RBTNode* newNode = new RBTNode(); 
		newNode->color = black; // set to black
        newNode->data = x; 
		this->root = newNode; 
		numItems += 1; 
	}
	
    // 2 : If tree is not empty, insert the newNode as leaf node with color red
    else{ // everything inside this else = if tree != empty 

        RBTNode* newNode = new RBTNode();
        newNode->data = x;
        newNode->color = red; //set color as red
        
        //RBTNode* parent =  this->root;
        RBTNode* parent = this->root;
        RBTNode* child;

		if(x < parent->data){
            child = parent->left;
        }
        else{
            child = parent->right;
        }
        // we know that the child is not in a while loop

        if(child != nullptr){
            while(child != nullptr){
                if(x < child->data){
                    parent = child;
                    child = parent->left;                    
                }
                else{
                    parent = child;
                    child = parent->right;

                }
                // child->parent = parent;
                // parent = child->parent;
            }
        }

        child = newNode;
        child->parent = parent;

        if(child->data < parent-> data){
            parent->left = child;
        }else{
            parent->right = child;
        }
        this->numItems++;
        
        // We have just inserted a new RED leaf, finished with Step# 2


        // 3: If the parent of newNode is black then exit from the operation

        //what is the color of the parent of the newNode
        //WHILE LOOP STARTING HERE?

        if(child->parent->color == black){
        }

        // 4 :If the parent of newNode is Red then check the color of uncle
        else if(child->parent->color == red){  
            cout << "STEP 4 Executing " << endl;
            
            // 5: if uncle == black or null, make suitable rotation and recolor the uncle
            // if(this->GetUncle(child)->color == black || this->GetUncle(child) == nullptr){
            //     cout << "STEP 5 WORKIN" << endl;
            //     //do some stuff

            // }
            // 6: if uncle is red, make uncle black
            if(this->GetUncle(child)->color == red){
                this->FlipColor(this->GetUncle(child)); //flip the uncle's color
                //do otha stuff
            }

            // 7? : Repeat till we get the correct tree
        }

        
    }
}

bool RedBlackTree::Contains(int target) 
{
    // start at the root node, set it to currNode
    // if currNOde = target ... true
    // else: if the target is smaller than currNode, set currNode to left child
    //       if target is larger than currNode set currNode to right child
    // if the current node has no children, return false
    RBTNode* currNode = this->root;
    
    if(currNode == nullptr){return false;};
    if(currNode->data == target){return true;};
    
    while(currNode != nullptr){
        if(currNode->data == target){
            return true;
        }
        else if(target < currNode->data){
            currNode = currNode->left;
        }
        else{
            currNode = currNode->right;
        }
    }
    return false;
}


int RedBlackTree::GetMin()
{
    RBTNode* currNode = this->root;
    while(currNode-> left != nullptr){
        currNode = currNode->left;
    }
    return currNode->data;
}

int RedBlackTree::GetMax()
{
    RBTNode* currNode = this->root;
    while(currNode-> right != nullptr){
        currNode = currNode->right;
    }
    return currNode->data;
}

int RedBlackTree::Size()
{
	return numItems; 
}


string RedBlackTree::InfixString(RBTNode* currNode)
{
    // take a node
    // print the left hand side of the node
    // print the current node
    // print the right node
    
    // emptry RBT scenario
    // cout << "K" << endl;
    // cout << currNode->data << " CURRNODE DATA " << endl;
    if(currNode == nullptr){
       return "";
    }

    string colorString;
    string infixStr = "";
    string nodeString;
    int color = currNode->color;

    if(color == 0){
        colorString = " B";
    }
    else{
        colorString = " R";
    }
// cout << "O" << endl;
    nodeString = colorString + to_string(currNode->data) + " ";

    infixStr = infixStr + InfixString(currNode->left) + nodeString + InfixString(currNode->right);

    
	return infixStr; 
}


string RedBlackTree::PrefixString(RBTNode* currNode)
{
    // take a node
    // print the left hand side of the node
    // print the current node
    // print the right node
    
    // emptry RBT scenario

    if(currNode == nullptr){
       return "";
    }

    string colorString;
    string prefixStr = "";
    string nodeString;
    int color = currNode->color;

    if(color == 0){
        colorString = " B";
    }
    else{
        colorString = " R";
    }

    nodeString = colorString + to_string(currNode->data) + " ";

    prefixStr = prefixStr + nodeString + PrefixString(currNode->left) + PrefixString(currNode->right);

    
	return prefixStr; 
}

string RedBlackTree::PostfixString(RBTNode* currNode)
{
    // take a node
    // print the left hand side of the node
    // print the current node
    // print the right node
    
    // emptry RBT scenario

    if(currNode == nullptr){
       return "";
    }

    string colorString;
    string postfixStr = "";
    string nodeString;
    int color = currNode->color;

    if(color == 0){
        colorString = " B";
    }
    else{
        colorString = " R";
    }

    nodeString = colorString + to_string(currNode->data) + " ";

    postfixStr = postfixStr + PostfixString(currNode->left) + PostfixString(currNode->right) + nodeString;

    
	return postfixStr; 
}

// WORKING ?!!
// if we get the root node, and we try to call
// this function, it shouldn't work and catch that error 
// if a node does NOT have an uncle
// make sure we catch that exception

RBTNode* RedBlackTree::GetUncle(RBTNode* rbn){ 
    // if the current node is a root
    // there is no uncle 
    if (rbn == this->root)
    {
    throw invalid_argument("This is the root, no uncle possible"); 
    }

    // if the grandfather does not exist 
    // there is no uncle 
    if (rbn->parent->parent == nullptr)
    {
    throw invalid_argument("This node has no grandfather, no uncle possible"); 
    } 
        
    RBTNode* father = rbn->parent;
    RBTNode* grandFather = father->parent;

    if(grandFather->left == father){
        return grandFather->right;
    }
    else{return grandFather->left;};
}

RBTNode* RedBlackTree::GetNode(int x)
{
	RBTNode* currNode = this->root;

    if(currNode->data == x){return currNode;};
    
    while(currNode != nullptr)
    {
        if(currNode->data == x)
        {
			return currNode; 
        }
        else if(x < currNode->data)
        {
            currNode = currNode->left;
        }
        else
        {
            currNode = currNode->right;
        }
    }
    
    return currNode; 
	
}

// Working 
void RedBlackTree::LeftRotation(RBTNode* currNode){ 
    //the curr node's parent is going to change their son to the currNode's left child
    RBTNode* father = currNode->parent;
    RBTNode* rightChild = currNode->right;
    RBTNode* adoptedChild = rightChild->left;

    //handle the father interaction
    if(father->right == currNode){
        father->right = rightChild;
    }
    else{
        father->left = rightChild;
    }
    rightChild->parent = father;

    // have the right child become the currNode's father
    rightChild->left = currNode;
    currNode->parent = rightChild;

    // have the adopted child become the CurrNode's son
    adoptedChild->parent = currNode;
    currNode->right = adoptedChild;
}

// Working
void RedBlackTree::RightRotation(RBTNode* currNode){ 
    //the curr node's parent is going to change their son to the currNode's left child
    RBTNode* father = currNode->parent;
    RBTNode* leftChild = currNode->left;
    RBTNode* adoptedChild = leftChild->right;

    //handle the father interaction
    if(father->left == currNode){
        father->left = leftChild;
    }
    else{
        father->right = leftChild;
    }
    leftChild->parent = father;

    // have the left child become the currNode's father
    leftChild->right = currNode;
    currNode->parent =leftChild;

    // have the adopted child become the CurrNode's son
    adoptedChild->parent = currNode;
    currNode->left = adoptedChild;
}

void RedBlackTree::FlipColor(RBTNode* rbn){ //requires testing
    if(rbn->color == 0){
        rbn->color =1;
    }else{
        rbn->color =0;
    }

}
