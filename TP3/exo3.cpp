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

 struct Node {
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


struct SearchTreeNode : public Node
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
        Node* new_node = new Node;
        new_node->value = value;
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

	void allLeaves(Node* leaves[],     unsigned int& leavesCount) {
        // fill leaves array with all leaves of this tree
        if(this->isLeaf())
        {
            Node* copy_leaves[leavesCount+1];
            for(int index = 0 ; index < leavesCount ; index++)
            {
                copy_leaves[index] = leaves[index];
            }
            copy_leaves[leavesCount] = this;
            leaves = copy_leaves;
            leavesCount ++;
        }
        this->right->allLeaves(leaves,leavesCount);
        this->left->allLeaves(leaves,leavesCount);
	}

	void inorderTravel(Node* nodes[],      unsigned int& nodesCount) {
        // fill nodes array with all nodes with inorder travel : (left,parent,right)
        int nb_relatives ;
        if(this->isLeaf())
        {
            return;
        }//il faut jouer avec les indices 2*i+1 2*i-1...
        Node* copy_leaves[nodesCount+nb_relatives];
            for(int index = 0 ; index < nodesCount ; index++)
            {
                copy_leaves[index] = nodes[index];
            }
            copy_leaves[nodesCount] = this;
            nodes = copy_leaves;
            nodesCount ++;

	}

	void preorderTravel(Node* nodes[],     unsigned int& nodesCount) {
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(Node* nodes[],    unsigned int& nodesCount) {
        // fill nodes array with all nodes with postorder travel
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

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	// QApplication a(argc, argv);
	// MainWindow::instruction_duration = 200;
    // w = new BinarySearchTreeWindow<SearchTreeNode>();
	// w->show();

	// return a.exec();
    return ;
}
