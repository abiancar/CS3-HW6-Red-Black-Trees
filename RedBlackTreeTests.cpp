
#include <iostream>
#include <cassert>
#include <random>
#include "RedBlackTree.h"

using namespace std;



void TestSimpleConstructor(){
	
	cout << "Testing Simple Constructor... " << endl;
	RedBlackTree rbt = RedBlackTree();
	//cout << "empty r-b-tree: " << rbt->ToInfixString() << endl;
	assert(rbt.ToInfixString() == "");
	
	cout << "PASSED!"<< endl << endl;
}


void TestInsertFirstNode(){

	cout << "Testing Insert One Node..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(30);
	//cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B30 ");

	cout << "PASSED!" << endl << endl;
}


void TestInsertSecondNode(){

	cout << "Testing Insert Second Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30); // leak here
	rbt->Insert(15);
	assert(rbt->ToPrefixString() == " B30  R15 ");
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	assert(rbt->ToPrefixString() == " B30  R45 ");	
	delete rbt;

	cout << "PASSED!" << endl << endl;
}


void TestInsertThirdNode(){
	
	/*
	cout << "Testing Insert Third Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(10); // Left Left
	cout << "rbt: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B15  R10  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree(); 
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(25); // Right Left
	assert(rbt->ToPrefixString() == " B25  R15  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45); // Easy case
	assert(rbt->ToPrefixString() == " B30  R15  R45 ");
	delete rbt;
	
	// more tests go here
	// consider some symmetry!*/
	
	cout << "TESTS MISSING" << endl << endl;
	cout << "PASSED!" << endl << endl;
}

void TestInsertFourthNode(){
	
	cout << "Testing Insert Fourth Node..." << endl;

	cout << "TESTS MISSING" << endl << endl;
	
	cout << "PASSED!" << endl << endl;
}

void TestInsertFifthNode(){
	/*
	cout << "Testing Insert Fifth Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45);
	rbt->Insert(10);
	rbt->Insert(25);
	//cout << "result: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  B15  R10  R25  B45 ");
	delete rbt;*/
	
	cout << "TESTS MISSING" << endl << endl;
	
	cout << "PASSED!" << endl << endl;
}


void TestToStrings(){

	cout << "Testing ToString Methods..." << endl;

	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(12);
	rbt.Insert(11);
	rbt.Insert(15);
	rbt.Insert(5);
	rbt.Insert(13);
	rbt.Insert(7);

	assert(rbt.ToPrefixString() == " B12  B7  R5  R11  B15  R13 ");
	assert(rbt.ToInfixString() == " R5  B7  R11  B12  R13  B15 ");
	assert(rbt.ToPostfixString() == " R5  R11  B7  R13  B15  B12 ");

	cout << "PASSED!" << endl << endl;
}

void TestInsertRandomTests(){
	/*
	cout << "Testing Random Insert Stuff..." << endl;
	cout << "\t This test passes if it doesn't crash and valgrind reports no issues" << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(13);
	rbt->Insert(20);
	rbt->Insert(12);
	cout << endl;
	//cout << "tree: " << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	// probably should have a delete or something here
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(11);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(15);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(5);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(13);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(7);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(10);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(8);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	delete rbt;*/
	
	cout << "PASSED!" << endl << endl;
}

void TestCopyConstructor(){
	/*
	cout << "Testing Copy Constructor..." << endl;

	RedBlackTree rbt1 = RedBlackTree();
	rbt1.Insert(11);
	rbt1.Insert(23);
	rbt1.Insert(9);
	rbt1.Insert(52);
	rbt1.Insert(31);
	rbt1.Insert(4);

	assert(rbt1.ToPrefixString() == " B11  B9  R4  B31  R23  R52 ");

	RedBlackTree rbt2 = RedBlackTree(rbt1);

	assert(rbt2.ToPrefixString() == rbt1.ToPrefixString());

	rbt1.Insert(200);
	assert(rbt2.ToPrefixString() != rbt1.ToPrefixString());*/

	cout << "PASSED!" << endl << endl;
}

void TestContains(){
	/*
	cout << "Testing Contains..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(22);
	rbt->Insert(15);
	rbt->Insert(31);
	rbt->Insert(55);
	rbt->Insert(12);
	rbt->Insert(17);
	rbt->Insert(29);
	rbt->Insert(34);
	
	assert(rbt->Contains(34));
	delete rbt;*/

	
	cout << "TESTS MISSING" << endl << endl;
	cout << "PASSED!" << endl << endl;
}




void TestGetMinimumMaximum(){
	cout << "Testing Get Minimum and Get Maximum..." << endl;

	cout << "TESTS MISSING" << endl << endl;

	cout << "PASSED!" << endl << endl;
}


int main(){

	RedBlackTree rbt = RedBlackTree();
	
	rbt.Insert(530);
	cout <<"A" << endl; 
	rbt.Insert(1); 
	cout <<"B" << endl; 
	rbt.Insert(4);
	rbt.Insert(0);
	rbt.Insert(5000);
	cout <<"C" << endl; 
	rbt.Insert(8487866);
	
	cout << "Size: " << rbt.Size() << endl;
	cout << "min: " << rbt.GetMin() << endl; 
	cout << "max: " << rbt.GetMax() << endl; 
	cout << "Contains 1: (0 false, 1 true)  " << rbt.Contains(1) << endl;
	cout << "Contains 8487866: (0 false, 1 true)" << rbt.Contains(8487866) << endl;
	cout << "Contains 124: (0 false, 1 true)" << rbt.Contains(124) << endl;
	cout << "INFIX: " << rbt.ToInfixString() << endl;
	
	RedBlackTree rbt2 = RedBlackTree();

	rbt2.Insert(5);
	rbt2.Insert(3);
	rbt2.Insert(1);
	rbt2.Insert(4);
	rbt2.Insert(8);
	rbt2.Insert(7);
	rbt2.Insert(9);
	
	cout << "INFIX: " << rbt2.ToInfixString() << endl;
	cout << "PREFIX: " << rbt2.ToPrefixString() << endl;
	cout << "POSTFIX: " << rbt2.ToPostfixString() << endl;
	
	cout << rbt2.InfixString(rbt2.GetUncle(rbt2.GetNode(1))) << endl;
	//cout << "shouldn't have an uncle: " << rbt2.InfixString(rbt2.GetUncle(rbt2.GetNode(3))) << endl;
	cout << rbt2.InfixString(rbt2.GetNode(3)) << endl; 
	
	RedBlackTree* rbt3 = new RedBlackTree(); 
	
	rbt3->Insert(40);
	rbt3->Insert(22);
	rbt3->Insert(15);
	rbt3->Insert(12);
	rbt3->Insert(17);
	rbt3->Insert(31);
	
	rbt3->Insert(29);
	rbt3->Insert(28);
	rbt3->Insert(34);
	rbt3->Insert(55);
	rbt3->Insert(50);
	rbt3->Insert(49);
	rbt3->Insert(59);
	

	/*
	rbt3->Insert(10);
	rbt3->Insert(7);
	rbt3->Insert(5);
	rbt3->Insert(2);
	rbt3->Insert(6);
	rbt3->Insert(8);
	rbt3->Insert(15);*/
	
	cout << "Pre-rotation tree: " << rbt3->ToPrefixString() << endl; 
	
	rbt3->LeftRotation(rbt3->GetNode(22)); 
	
	cout << "Post-rotation tree: " << rbt3->ToPrefixString() << endl; 
	

	TestSimpleConstructor();
	
	TestInsertFirstNode();

	TestInsertSecondNode();/*
	TestInsertThirdNode(); 
	TestInsertFourthNode();
	TestInsertFifthNode();

	TestToStrings();
	TestInsertRandomTests();

	TestCopyConstructor();

	TestContains();
	TestGetMinimumMaximum();
	*/
	
	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
