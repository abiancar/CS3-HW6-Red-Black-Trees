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

void RedBlackTree::Insert(int x)
{
	// if the size of the tree is 0
	if (numItems == 0)
	// create a node, make the node the root node 

    //Steps:



	{
		RBTNode* rbt = new RBTNode(); 
		rbt->data = x; 
		this->root = rbt; 
        numItems++;
	}
	
}

bool RedBlackTree::Contains(int target) // FIXME: Prolly doesn't work yet
{
    // start at the root node, set it to currNode
    // if currNOde = target ... true
    // else: if the target is smaller than currNode, set currNode to left child
    //       if target is larger than currNode set currNode to right child
    // if the current node has no children, return false
    bool result = false;
    RBTNode* currNode = this->root;
    
    while(result != true){
    
        if(currNode->data == target){
            return true;
        }
        else if(currNode->left == nullptr && currNode->right == nullptr){
            return false;
        }
        else if(target < currNode->data){
            currNode = currNode->left;
        }
        else if(target > currNode-> data){
            currNode = currNode->right;
        }
    }
    return result;

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
