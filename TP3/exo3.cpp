// #include "mainwindow.h"
// #include "tp3.h"
// #include <QApplication>
 #include <time.h>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

// MainWindow* w = nullptr;
 using std::size_t;

struct Node 
{
    Node* left;
    Node* right;
    int value;
    void print()
    {
        if(this->left != nullptr)
            std::cout<<" left :" << this->left->value << std::endl;
        if(this->right!= nullptr)
            std::cout<<"right : "<<this->right->value << std::endl;
        std::cout<<"this : " << this->value << std::endl;
    }
};


struct SearchTreeNode
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->value = value;
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        SearchTreeNode* new_node = new SearchTreeNode;
        new_node->value = value;
        if(this->left==nullptr)
        {
            this->left=new_node;
            return;
        }
        if(this->right==nullptr)
        {
            this->right=new_node;
            return;
        }

        if(value < this->value)    
            this->left->insertNumber(value);
        else
        {
            this->right->insertNumber(value);
        }
    }

	unsigned int height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        if(this->left == nullptr && this->right == nullptr)
        {
            return 1;
        }
        if(this->left == nullptr)
        {
            return 1 + this->right->height();
        }
        if(this->right == nullptr)
        {
            return 1 + this->left->height();
        }

        if(this->left->height() < this->right->height())
        {
            return 1+this->right->height();
        }

        else
        {
           return 1+this->left->height(); 
        }
    }

    unsigned int nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        if(this->left == nullptr && this->right == nullptr)
        {
            return 1;
        }
        return this->left->nodesCount() + this->right->nodesCount();
	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->nodesCount()==1)
        {
            return true;
        }
        return false;
	}

	void allLeaves(SearchTreeNode* leaves[],     unsigned int& leavesCount) {
        // fill leaves array with all leaves of this tree
        if(this->isLeaf())
        {
            SearchTreeNode* copy_leaves[leavesCount+1];
            for(int index = 0 ; index < leavesCount ; index++)
            {
                copy_leaves[index] = leaves[index];
            }
            copy_leaves[leavesCount] = this;
            leaves = copy_leaves;
            leavesCount ++;
        }
        if(this->right!=nullptr)
        {
            this->right->allLeaves(leaves,leavesCount);
        }
        if(this->left!=nullptr)
        {
            this->left->allLeaves(leaves,leavesCount);
        }
    }



	void inorderTravel(std::vector<SearchTreeNode*> nodes, std::vector<SearchTreeNode*>::iterator it) {
        // fill nodes array with all nodes with inorder travel : (left,parent,right)

        if(it == nodes.begin())
        {
            nodes.push_back(this);
            it=next(it);
        }
        
        if(this->right!=nullptr)
        {
            if(it>=nodes.cend())
            {
                nodes.push_back(this->right);
            }
            else
            {
                nodes.insert(it,this->right);
            }
            this->right->inorderTravel(nodes,it+1);
        }
        if(this->right!=nullptr)
        {
            nodes.insert(it-1,this->left);
            this->left->inorderTravel(nodes,it);
        }


	}

	void preorderTravel(std::vector<SearchTreeNode*> nodes) {
        // fill nodes array with all nodes with preorder travel
        nodes.push_back(this);
        if(this->left!=nullptr)
        {
            this->left->preorderTravel(nodes);
        }
        if(this->right!=nullptr)
        {
            this->right->preorderTravel(nodes);
        }
	}

	void postorderTravel(std::vector<SearchTreeNode*> nodes) {
        // fill nodes array with all nodes with postorder travel
        if(this->left!=nullptr)
        {
            this->left->preorderTravel(nodes);
        }
        if(this->right!=nullptr)
        {
            this->right->preorderTravel(nodes);
        }
        nodes.push_back(this);
	}

	Node* find(int value) {
        // find the node containing value
		return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    /*SearchTreeNode(int value) : SearchTreeNode(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}*/
};

SearchTreeNode* createNode(int value) {
     SearchTreeNode* new_node = new SearchTreeNode;
    new_node->value = value;
    return new_node;
}

int main(int argc, char *argv[])
{
	SearchTreeNode* Tree = new SearchTreeNode;
    std::vector<SearchTreeNode*> nodes;
    std::vector<SearchTreeNode*> leaves;
    unsigned int leavesCount = 0;
    Tree->initNode(9);
    Tree->insertNumber(4);
    Tree->insertNumber(11);
    
    int nodesCount  = Tree->nodesCount();

    Tree->inorderTravel(nodes,nodes.begin());
    for(int i = 0; i<nodes.size(); i++)
    {
        if(nodes[i]->isLeaf())
        {
            leavesCount ++;
        }
    }

    std::cout<<"Il y a "<<nodesCount<<" nodes dans l'arbre\n";
    std::cout<<"Dont "<<leavesCount<<" sont des feuilles\n";
    
    //Tree->allLeaves(leaves,leavesCount);
    return 0;
}
