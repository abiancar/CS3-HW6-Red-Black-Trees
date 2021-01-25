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
{}

/*
1) if tree is empty, insert the newNode as Root node with color black and exit from operation
2) If tree is not empty, insert the newNode as leaf node with color red
3) If the parent of newNode is black then exit from the operation
4) If the parent of newNode is Red then check the color of parent's sibling
5) If uncle is colored black or null then make suitable rotation and recolor it
6) If uncle is colorded red then perform recolor. Repeat the same until tree becomes proper red black tree 
*/

void RedBlackTree::Insert(int x)
{
	// if the size of the tree is 0
	if (numItems == 0) // create a node, make the node the root node 
	{
		RBTNode* newNode = new RBTNode(); 
		newNode->color = 0; // set to black
        newNode->data = x; 
		this->root = newNode; 
        numItems++;
	}
    else{ // tree is not empty, insert newNode as leaf node with color red
        RBTNode* newNode = new RBTNode();
        newNode->data = x;
        newNode->color = 1; //set color as red
        
        RBTNode* parent =  this->root;
        RBTNode* child;

        if(x < parent->data){          // if the child should be on the left
            child = parent->left;
        }
        else{                          // if the child should be on the right
            child = parent->right;
        }
        while(child!= nullptr){
            if(x < parent->data){          // if the child should be on the left
                child = parent->left;
                parent = child;
            }
            else{                          // if the child should be on the right
                child = parent->right;
                parent = child;
            }
        }
        child = newNode;
        child-> parent = parent; // parent is still being stored at this point so we can do this

        if(parent->color != 0){ // if the new node's parent is red
            //check uncle color
        }
    }
	
}

bool RedBlackTree::Contains(int target) // FIXME: Prolly doesn't work yet
{
    // start at the root node, set it to currNode
    // if currNOde = target ... true
    // else: if the target is smaller than currNode, set currNode to left child
    //       if target is larger than currNode set currNode to right child
    // if the current node has no children, return false
    RBTNode* currNode = this->root;
    if(currNode->data == target){return true;};
    while(currNode->left != nullptr && currNode->right != nullptr){
    
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
    cout << endl;
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

string InfixString(RBTNode* a)
{
	string s = "";
	return s; 
}

string PrefixString(RBTNode* a)
{
	string s = "";
	return s; 
}

string PostfixString(RBTNode* a)
{
	string s = "";
	return s; 
}
