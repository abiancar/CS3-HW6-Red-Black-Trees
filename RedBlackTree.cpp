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
	{
		RBTNode* rbt = new RBTNode(); 
		rbt->data = x; 
		this->root = rbt; 
	}
	
}

bool RedBlackTree::Contains(int)
{
	return true; 
}

int RedBlackTree::GetMin()
{
	return 0; 
}

int RedBlackTree::GetMax()
{
	return 0; 
}

int RedBlackTree::Size()
{
	return 0; 
}

/*
string RedBlackTree::ToInfixString() const
{
	string s = "";
	return s; 
}
string RedBlackTree::ToPrefixString() const 
{
	string s = "";
	return s; 
}
string RedBlackTree::ToPostfixString() const 
{
	string s = "";
	return s; 
}

string InfixString(RBTNode*)
{
	string s = "";
	return s; 
}

string PrefixString(RBTNode*)
{
	string s = "";
	return s; 
}

string PostfixString(RBTNode*)
{
	string s = "";
	return s; 
}*/
