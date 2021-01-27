
#include <iostream>
#include <cassert>
#include <random>
#include "RedBlackTree.h"

using namespace std;

void TestGetUncle(){
	cout << "Testing Get Uncle..." << endl;
	
	RedBlackTree rbt2 = RedBlackTree();

	rbt2.Insert(5);
	rbt2.Insert(3);
	rbt2.Insert(1);
	rbt2.Insert(0);
	rbt2.Insert(2);
	//cout << "A" << endl;
	//cout << rbt2.ToPrefixString() << endl;

	rbt2.Insert(4);
	//cout << "B" << endl;
	//cout << rbt2.ToPrefixString() << endl;

	rbt2.Insert(8);
	//cout << rbt2.ToPrefixString() << endl;
	rbt2.Insert(7);
	rbt2.Insert(9);
	//cout << "GOOOD MORNING" << endl;
	//cout << rbt2.ToPrefixString() << endl;


	try{
		rbt2.GetUncle(rbt2.GetNode(5));
		assert(false);
	}
	catch(invalid_argument& e){
	}

	try{
		rbt2.GetUncle(rbt2.GetNode(3));
		assert(false);
	}
	catch(invalid_argument& e){
	}


	// two ndoes share that share the same uncle should return the same uncle
	assert(rbt2.GetUncle(rbt2.GetNode(7))->data == 4);
	assert(rbt2.GetUncle(rbt2.GetNode(9))->data == 4);


	cout << "PASSED!" << endl << endl;
}

void TestSimpleConstructor()
{
	
	cout << "Testing Simple Constructor... " << endl;
	RedBlackTree rbt = RedBlackTree();
	//cout << "empty r-b-tree: " << rbt.ToInfixString() << endl;
	assert(rbt.ToInfixString() == "");
	
	cout << "PASSED!"<< endl << endl;
}

void TestInsertFirstNode()
{

	cout << "Testing Insert One Node..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(30);
	//cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B30 ");

	cout << "PASSED!" << endl << endl;
}

void TestInsertSecondNode()
{

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

void TestInsertThirdNode()
{
	
	cout << "Testing Insert Third Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(10); // Left Left
	// cout << "rbt 1: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B15  R10  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree(); 
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(25); // Right Left
	// cout << rbt->ToPrefixString() << endl;
	//cout << "rbt: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B25  R15  R30 ");
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45); // Easy case
	// cout << "rbt: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  R15  R45 ");
	delete rbt;
	
	// more tests go here
	// consider some symmetry!*/
	
	cout << "PASSED!" << endl << endl;
}

void TestInsertFourthNode()
{
	
	cout << "Testing Insert Fourth Node..." << endl;


	// inserting a left to a balanced tree
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(10); 
	rbt->Insert(5);
	//cout << "rbt 1: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B15  B10  R5  B30 ");
	delete rbt;
	
	rbt = new RedBlackTree(); 
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(25); // Right Left
	rbt->Insert(35);
	//cout << "rbt: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B25  B15  B30  R35 ");
	delete rbt;
	
	rbt = new RedBlackTree();
	rbt->Insert(35);
	rbt->Insert(15);
	rbt->Insert(45); // Left right
	rbt->Insert(20);
	// cout << "rbt: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B35  B15  R20  B45 ");
	delete rbt;
	
	// more tests go here
	// consider some symmetry!*/	
	cout << "PASSED!" << endl << endl;
}

void TestInsertFifthNode()
{
	
	cout << "Testing Insert Fifth Node..." << endl;

	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	rbt->Insert(35);
	rbt->Insert(20);
	rbt->Insert(21);
	assert(rbt->ToPrefixString() == " B35  B21  R20  R30  B45 ");
	delete rbt;
	
	
	rbt = new RedBlackTree();
	rbt->Insert(50);
	rbt->Insert(30);
	rbt->Insert(60);
	rbt->Insert(55);
	rbt->Insert(56);
	assert(rbt->ToPrefixString() == " B50  B30  B56  R55  R60 ");
	delete rbt;
	
	cout << "PASSED!" << endl << endl;
}


void TestToStrings()
{

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
	
	cout << "Testing Random Insert Stuff..." << endl;
	cout << "\t This test passes if it doesn't crash and valgrind reports no issues" << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(13);
	rbt->Insert(20);
	rbt->Insert(12);
	cout << endl;

	assert(rbt->ToPrefixString() == " B15  B13  R12  B20 ");

	delete rbt;
	
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

	cout << rbt->ToPrefixString() << endl; 
	assert(rbt->ToPrefixString() == " B12  B7  R5  R11  B15  R13 ");

	delete rbt;
	
	
	rbt = new RedBlackTree();
	
	rbt->Insert(12);
	rbt->Insert(11);
	rbt->Insert(15);
	rbt->Insert(5);
	rbt->Insert(13);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(7);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(10);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(8);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(40);
	rbt->Insert(9);
	
	cout << rbt->ToPrefixString() << endl; 
	assert(rbt->ToPrefixString() == " B10  R7  B5  B8  R9  R12  B11  B15  R13  R40 ");
	
	delete rbt;
	
	cout << "PASSED!" << endl << endl;
}

void TestCopyConstructor()
{
	
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
	assert(rbt2.ToPrefixString() != rbt1.ToPrefixString());

	cout << "PASSED!" << endl << endl;
}

void TestContains()
{
	
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
	delete rbt;

	
	cout << "TESTS MISSING" << endl;
	cout << "PASSED!" << endl << endl;
}

void TestGetMinimumMaximum()
{
	cout << "Testing Get Minimum and Get Maximum..." << endl;

	cout << "TESTS MISSING" << endl << endl;

	cout << "PASSED!" << endl << endl;
}

int main(){


	TestGetUncle();
	
	TestSimpleConstructor();
	TestContains();

	TestInsertFirstNode();
	TestInsertSecondNode();
	TestInsertThirdNode();
	TestInsertFourthNode();
	TestInsertFifthNode();

	TestToStrings();
	TestInsertRandomTests();/*
	TestCopyConstructor();
	TestGetMinimumMaximum();
	*/
	
	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
