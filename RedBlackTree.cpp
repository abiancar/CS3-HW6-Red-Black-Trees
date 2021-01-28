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

// copy constructor 
RedBlackTree::RedBlackTree(const RedBlackTree &rbt)
{
	root = rbt.root; 
	numItems = rbt.numItems; 
	
	/*
	InfixString(root) = rbt.InfixString(rbt.root);
	PrefixString(root) = rbt.PrefixString(rbt.root);
	PostfixString(root) = rbt.PostfixString(rbt.root); */
 
}

RedBlackTree::~RedBlackTree()
{
	// starting from the maximum
	// delete the tree
}

void RedBlackTree::Insert(int x)
{    
    int red = 1;
    int black = 0;
    
    RBTNode* newNode = new RBTNode(); 
  
    // 1: If tree is empty, insert the newNode as Root node with color black and exit from operation	
	if (this->root == nullptr) // create a node, make the node the root node 
	{
		//RBTNode* newNode = new RBTNode(); 
		newNode->color = black; // set to black
        newNode->data = x; 
		this->root = newNode; 
		numItems += 1; 
	}
	
    // 2 : If tree is not empty, insert the newNode as leaf node with color red
    else{ 
        //RBTNode* newNode = new RBTNode();
        newNode->data = x;
        newNode->color = red; //set color as red
       
        RBTNode* parent = this->root;
        RBTNode* child = nullptr;

		if(x < parent->data)
		{
            child = parent->left;
        }
        else
        {
            child = parent->right;
        }
        
		while(child != nullptr)
		{
			if(x < child->data)
			{
				parent = child;
				child = parent->left;                    
			}
			else
			{
				parent = child;
				child = parent->right;

			}

		}

        child = newNode;
        child->parent = parent;

        if(child->data < parent-> data)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        
        this->numItems++; 
        
        // 4 :If the parent of newNode is Red then check the color of uncle     
		while (child->parent->color != black)
        {  
            // 5: if the uncle is null or the uncle is black, make suitable rotation and recolor 
			// NO UNCLE 
            if (this->GetUncle(child) ==  nullptr || this->GetUncle(child)->color == black)
            {
			
				// right right case 
				if (child->parent == child->parent->parent->right)
				{
					
					if (child == child->parent->left) 
					{
						// right left case 
						child = child->parent;
						RightRotation(child); 

					}
					child->parent->color = black;
					child->parent->parent->color = red;
					LeftRotation(child->parent->parent); 

				}
				
				// left left case
				else if (child->parent == child->parent->parent->left)
				{
					
					if (child == child->parent->right)
					{
						// left right case
						child = child->parent;
						LeftRotation(child);
					}
					
					child->parent->color = black;
					child->parent->parent->color = red;
					RightRotation(child->parent->parent);

				}
             

			}

			// 6: if uncle is red
			// parent->black, uncle->black, grandparent->red, and then traverse up to grand-parent
			// so it's not FlipColor() it's just parent->black
			else if(this->GetUncle(child)->color == red)
			{
				child->parent->color = black; 
				this->GetUncle(child)->color = black; 
				//child = child->parent->parent;
			}
			
			// 3. If the parent of newNode is Black 
			// then exit from the operation 
			if (child->parent->color == black)
			{
				break; 
			}
			
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

void RedBlackTree::LeftRotation(RBTNode* currNode)
{
	RBTNode* temp = currNode->right;
    
	currNode->right = temp->left;
	if (temp->left != nullptr)
	{
		temp->left->parent = currNode;
	}
	
	temp->parent = currNode->parent;
	

    // if the currNode is root, change color with what is swapping with root
	if (currNode->parent == nullptr)
	{
		this->root = temp;
        //this->ColorSwap(root,currNode);
	}
	else if (currNode == currNode->parent->left)
	{
		currNode->parent->left = temp;
	}
	else
	{
		currNode->parent->right = temp;
	}
	
	temp->left = currNode;
	currNode->parent = temp;
}

void RedBlackTree::RightRotation(RBTNode* currNode)
{
	RBTNode* temp = currNode->left;
	
	currNode->left = temp->right;
	
	if (temp->right != nullptr)
	{
		temp->right->parent = currNode;
	}
	
	temp->parent = currNode->parent;
	if (currNode->parent == nullptr)
	{

		this->root = temp;
        //this->ColorSwap(root,currNode);

	}
	else if (currNode == currNode->parent->right)
	{
		currNode->parent->right = temp;
	}
	else
	{
		currNode->parent->left = temp;
	}
	
	temp->right = currNode;
	currNode->parent = temp;
}

void RedBlackTree::ColorSwap(RBTNode* rbn1, RBTNode* rbn2)
{
    int tmpColor = 0;
    tmpColor = rbn1->color;
    rbn1->color = rbn2->color;
    rbn2->color = tmpColor;
}

bool hasFather(RBTNode* currNode){
    if(currNode->parent == nullptr){
        return false;
    }
    return true;
}

bool hasGrandFather(RBTNode* currNode){
    if(currNode->parent == nullptr){
        return false;
    }
    if(currNode->parent->parent == nullptr){
        return false;
    }
    return true;
}
