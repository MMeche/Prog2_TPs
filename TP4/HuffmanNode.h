#ifndef HUFFMANNNODE_H
#define HUFFMANNNODE_H

// #include <QString>

#include <string>

struct HuffmanNode
{
    HuffmanNode* left;
    HuffmanNode* right;

    int frequences;
    unsigned char character;
    std::string code;

    HuffmanNode(unsigned char c='\0', int frequences=0)
    {
        this->frequences = frequences;
        this->character = c;
        this->code = std::string();
        this->left = this->right = NULL;
    }

    HuffmanNode(const HuffmanNode& node)
    {
        this->frequences = node.frequences;
        this->character = node.character;
        this->code = std::string(node.code);
        this->left = this->right = NULL;
    }

    virtual bool isLeaf() const {return !this->left && !this->right;}

    void insertNode(HuffmanNode*);
    void processCodes(std::string baseCode);
    void fillCharactersArray(std::string nodes_for_chars[]);
};


/*class HuffmanHeap : public TemplateArray<HuffmanNode>
{
public:
    virtual ~HuffmanHeap() {}

    HuffmanHeap(uint size=100) : TemplateArray<HuffmanNode>()
    {
        if (size>0)
        {
            _data.resize(size);
            for (uint i=0; i<size; ++i)
                _data[i] = -1;
        }
    }

    void insertHeapNode(int heapSize, unsigned char c, int frequences);
};
*/
#endif // HUFFMANNNODE_H
