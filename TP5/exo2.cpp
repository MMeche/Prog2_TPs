#include <time.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>


using std::size_t;
using std::string;


std::vector<string> names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});

unsigned long int hash(string key)
{
    unsigned long int h = 0;
    for(int i = 0 ; i < key.length(); i++)
    {
        h += (int)pow((int)key[i],key.length()-i-1)%139; 
        /*Modulo un nombre premier, askip c'est mieux*/
    }
    return h;
}

struct MapNode
{

    string key;
    unsigned long int key_hash;

    int value;

    MapNode* left;
    MapNode* right;

    MapNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->key_hash = hash(key);

        this->left = this->right = nullptr;
    }

    /**
     * @brief insertNode insert a new node according to the key hash
     * @param node
     */
    void insertNode(MapNode* node)
    {
        /*Il ne faut pas que la root soit nullptr*/
        if(this->key_hash>=node->key_hash)
        {
            if(this->left==nullptr)
            {
                this->left = node;
            }else
            {
                this->left->insertNode(node);
            }
        }else
        {
            if(this->right==nullptr)
            {
                this->right = node;
            }else
            {
                this->right->insertNode(node);
            }
        }
    }

    void insertNode(string key, int value)
    {
        this->insertNode(new MapNode(key, value));
    }

};

struct Map
{

    MapNode* root;
    Map() {
        this->root = nullptr;
    }

    /**
     * @brief insert create a node and insert it to the map
     * @param key
     * @param value
     */
    void insert(string key, int value)
    {
        MapNode* newNode = new MapNode(key,value);
        if(this->root == nullptr)
        {
            this->root = newNode;
        }
        else
        {   
            this->root->insertNode(newNode);
        }
    }

    /**
     * @brief get return the value of the node corresponding to key
     * @param key
     * @return
     */
    int get(string key)
    {   
        int hash_key = hash(key);
        MapNode* current;
        current = this->root;
        while(current != nullptr)
        {
            if(hash_key==current->key_hash)
            {
                return current->value;
            }
            else{    
                if(hash_key<current->key_hash)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            };
        } ;
        return -1;
    };
};


int main(int argc, char *argv[])
{
    srand(time(NULL));
	Map map;

    map.insert("Yolo", 20);
    for (std::string& name : names)
    {
        if (rand() % 3 == 0)
        {
            map.insert(name, rand() % 21);
        }
    }

    printf("map[\"Margot\"]=%d\n", map.get("Margot"));
    printf("map[\"Jolan\"]=%d\n", map.get("Jolan"));
    printf("map[\"Lucas\"]=%d\n", map.get("Lucas"));
    printf("map[\"Clemence\"]=%d\n", map.get("Clemence"));
    printf("map[\"Yolo\"]=%d\n", map.get("Yolo"));
    printf("map[\"Tanguy\"]=%d\n", map.get("Tanguy"));
}
