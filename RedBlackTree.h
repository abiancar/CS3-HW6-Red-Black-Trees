#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <string>

using namespace std;
struct RBTNode {
	int data;
    unsigned short int color;
    RBTNode *left = nullptr;
    RBTNode *right = nullptr; 
    RBTNode *parent = nullptr;
};

class RedBlackTree{
	
	public:
		RedBlackTree();
        ~RedBlackTree();
        
        void Insert(int x);
        bool Contains(int target);
        
        int GetMin();
        int GetMax();
        int Size();
        
        std::string ToInfixString() const {return InfixString(root);};
        std::string ToPrefixString() const {return PrefixString(root);};
        std::string ToPostfixString() const {return PostfixString(root);};

        void LeftRotation(RBTNode* rbn);
        void RightRotation(RBTNode* rbn);
        void FLipColor(RBTNode* rbn); // may need more coloring methods
        RBTNode* GetUncle(RBTNode* rbn);

//	private:
        RBTNode *root;
        unsigned long long int numItems;

        static std::string InfixString(RBTNode* a);
        static std::string PrefixString(RBTNode* a); 
        static std::string PostfixString(RBTNode* a); 

};

#endif
