#include "HuffmanNode.h"

using std::size_t;
using std::string;

#include <vector>

void processCharFrequences(string data, std::vector<int>& frequences);
void buildHuffmanHeap(const std::vector<int>& frequences, std::vector<HuffmanNode*>& priorityMinHeap, int& heapSize);
HuffmanNode* makeHuffmanSubTree(HuffmanNode* rightNode, HuffmanNode* leftNode);
HuffmanNode* buildHuffmanTree(std::vector<HuffmanNode*>& priorityMinHeap, int heapSize);
void insertHeapNode(std::vector<HuffmanNode*> heap, int heapSize, HuffmanNode* newNode);
string huffmanEncode(const string& toEncode, HuffmanNode* huffmanTree);
string huffmanDecode(const string& toDecode, const HuffmanNode& huffmanTreeRoot);



void processCharFrequences(string data, std::vector<int>& frequences)
{
    /**
      * Fill `frequences` array with each character frequence.
      * frequences is an array of 256 int. frequences[i]
      * is the frequence of the caracter with ASCII code i
     **/
    for(int i = 0 ; i<data.length() ; i++)
    {
        frequences[(int)data[i]]++;
    }
}

void insertHeapNode(std::vector<HuffmanNode*> heap, int heapSize, HuffmanNode* newNode)
{
    /**
      * Insert a HuffmanNode into the lower heap. A min-heap put the lowest value
      * as the first cell, so check the parent should be lower than children.
      * Instead of storing int, the cells of std::vector<HuffmanNode*> store HuffmanNode*.
      * To compare these nodes use their frequences.
      * this->get(i): HuffmanNode*  <-> this->get(i)->frequences
      * you can use `this->swap(firstIndex, secondIndex)`
     **/

    // Your code
    int i = heapSize;
    heap.push_back(newNode);
    while(i>0 && heap[i]->frequences < heap[(i-1)/2]->frequences)
    {
        HuffmanNode* tmp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = tmp;
        i = (i-1)/2;
    }

}

void buildHuffmanHeap(const std::vector<int>& frequences, std::vector<HuffmanNode*>& priorityMinHeap, int& heapSize)
{
    /**
      * Do like Heap::buildHeap. Use only non-null frequences
      * Define heapSize as numbers of inserted nodes
      * allocate a HuffmanNode with `new`
     **/

    // Your code
    heapSize = 0;
    for(int i = 0 ; i < frequences.size() ; i++)
    {
        if(frequences[i]!=0)
        {
            HuffmanNode* node = new HuffmanNode;
            node->character = (char)i;
            node->frequences = frequences[i];
            node->left =nullptr;
            node->right = nullptr;
            insertHeapNode(priorityMinHeap, heapSize, node);
        }
    }

}

void heapify(std::vector<HuffmanNode*> HuffmanTree, int heapSize, int nodeIndex)
{
    /**
      * Repair the heap starting from nodeIndex. this is a min-heap,
      * so check the parent should be lower than children.
      * this->get(i): HuffmanNode*  <-> this->get(i)->frequences
      * you can use `this->swap(firstIndex, secondIndex)`
     **/
    // Your code
    int lowest = nodeIndex;
    if(HuffmanTree[lowest]->frequences > HuffmanTree[lowest]->left->frequences)
    {
        lowest = 2*lowest+1 ; //Le fils de gauche est à l'indice 2*i+1
    }
    if(HuffmanTree[lowest]->frequences > HuffmanTree[lowest]->right->frequences)
    {
        lowest = 2*lowest+2 ; //Le fils de droite est à l'indice 2*i+2
    }
    if(lowest != nodeIndex)
    {
        HuffmanNode* tmp = HuffmanTree[lowest];
        HuffmanTree[lowest] = HuffmanTree[nodeIndex];
        HuffmanTree[nodeIndex] = tmp;
        heapify(HuffmanTree, heapSize, lowest);
    }


}


HuffmanNode* extractMinNode(std::vector<HuffmanNode*> HuffmanTree, int heapSize)
{
    /**
      * Extract the first cell, replace the first cell with the last one and
      * heapify the heap to get a new well-formed heap without the returned cell
      * you can use `this->swap`
     **/
    HuffmanNode* tmp = HuffmanTree[0];
    HuffmanTree[0] = HuffmanTree[HuffmanTree.size()-1];
    HuffmanTree[HuffmanTree.size()-1] = tmp ;
    
    std::vector<HuffmanNode*>::iterator it = HuffmanTree.begin();
    HuffmanTree.erase(it+HuffmanTree.size()-1);
    heapify(HuffmanTree,heapSize,0);
    
    return tmp;
}

HuffmanNode* makeHuffmanSubTree(HuffmanNode* rightNode, HuffmanNode* leftNode)
{
    /**
     * Make a subtree (parent + 2 children) with the given 2 nodes.
     * These 2 characters will be the children of a new parent node which character is '\0'
     * and frequence is the sum of the 2 children frequences
     * Return the new HuffmanNode* parent
     **/
    // Your code
    HuffmanNode* parent = new HuffmanNode('\0',rightNode->frequences+leftNode->frequences);
    parent->right = rightNode ;
    parent->left = leftNode ;
    return parent;
}

HuffmanNode* buildHuffmanTree(std::vector<HuffmanNode*>& priorityMinHeap, int heapSize)
{
    /**
      * Build Huffman Tree from the priorityMinHeap, pick nodes from the heap until having
      * one node in the heap. For every 2 min nodes, create a subtree and put the new parent
      * into the heap. The last node of the heap is the HuffmanTree;
      * use extractMinNode()
     **/

    // Your code
    while(heapSize > 1)
    {
        HuffmanNode* left = extractMinNode(priorityMinHeap, heapSize);
        heapSize --;
        HuffmanNode* right = extractMinNode(priorityMinHeap,heapSize);
        heapSize --;
        HuffmanNode* parent = makeHuffmanSubTree(right,left);
        insertHeapNode(priorityMinHeap, heapSize, parent);
        heapSize ++;
    }

    return priorityMinHeap[0];
}

void HuffmanNode::processCodes(const std::string baseCode)
{
    /**
      * Travel whole tree of HuffmanNode to determine the code of each
      * leaf/character.
      * Each time you call the left child, add '0' to the baseCode
      * and each time call the right child, add '1'.
      * If the node is a leaf, it takes the baseCode.
     **/

    // Your code
    if(this->isLeaf())
    {
        this->code = baseCode;
    };
    this->processCodes(this->right->code+"1");
    this->processCodes(this->left->code + "0");
}

void HuffmanNode::fillCharactersArray(std::string charactersCodes[])
{
    /**
      * Fill the string array with all nodes codes of the tree
      * It store a node into the cell corresponding to its ascii code
      * For example: the node describing 'O' should be at index 79
     **/
    if (!this->left && !this->right)
        charactersCodes[this->character] = this->code;
    else {
        if (this->left)
            this->left->fillCharactersArray(charactersCodes);
        if (this->right)
            this->right->fillCharactersArray(charactersCodes);
    }
}

string huffmanEncode(const string& toEncode, HuffmanNode* huffmanTree)
{
    /**
      * Encode a string by using the huffman compression.
      * With the huffmanTree, determine the code for each character
     **/

    // Your code
    std::string charactersCodes[256]; // array of 256 huffman codes for each character
    huffmanTree->fillCharactersArray(charactersCodes);
    string encoded = "";
    for(int i = 0; i< toEncode.size();i++){
        encoded += charactersCodes[(int)toEncode[i]];
    }
    return encoded;
}


string huffmanDecode(const string& toDecode, HuffmanNode& huffmanTreeRoot)
{
    /**
      * Use each caracters of toDecode, which is '0' either '1',
      * to travel the Huffman tree. Each time you get a leaf, get
      * the decoded character of this node.
     **/
    // Your code
    HuffmanNode& current = huffmanTreeRoot;
    string decoded = "";
    for(int i = 0 ; i<toDecode.size(); i++)
    {
        if(current.isLeaf())
        {
            decoded += current.character;
        }
        if(toDecode[i]=='0')
        {
            current = *(current.left);
        };
        if(toDecode[i]=='1')
        {
            current = *(current.right);
        };
    }
    return decoded;
}


int main(int argc, char *argv[])
{
    HuffmanNode* root; 
    string data = "Ce matin j'ai mangé une salade de patate.";

    // this array store each caracter frequences indexed by their ascii code
    std::vector<int> characterFrequences;
    for (int i = 0 ; i < 256 ; i++){
        characterFrequences.push_back(0);
    }

    // this array store each caracter code indexed by their ascii code
    string characterCodes[256];
    std::vector<HuffmanNode*> priorityMinHeap;
    int heapSize = 0;

    processCharFrequences(data, characterFrequences);
    // afficher characterFrequences
    buildHuffmanHeap(characterFrequences, priorityMinHeap, heapSize);
    
    // afficher le heap

    root = buildHuffmanTree(priorityMinHeap, heapSize);
    root->processCodes("");
    string encoded = huffmanEncode(data, root);
    string decoded = huffmanDecode(encoded, *root);

    printf("Encoded: %s\n", encoded.c_str());
    printf("Decoded: %s\n", decoded.c_str());
}
