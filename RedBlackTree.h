#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <string>

using namespace std;
struct RBTNode {
	int data;
    unsigned short int color;
    RBTNode *left = nullptr;
    RBTNode *right = nullptr; 
};

class RBTree{
	
	public:
		RBTree();
        ~RBTree();
        
        void Insert(int);
        bool Contains(int);
        
        int GetMin();
        int GetMax();
        int Size();
        
        std::string ToInfixString() const {return InfixString(root);};
        std::string ToPrefixString() const {return PrefixString(root);};
        std::string ToPostfixString() const {return PostfixString(root);};
	private:
        RBTNode *root;
        unsigned long long int numItems;

        static std::string InfixString(RBTNode*);
        static std::string PrefixString(RBTNode*); 
        static std::string PostfixString(RBTNode*); 

};

#endif