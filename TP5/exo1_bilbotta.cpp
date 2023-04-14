#include <time.h>
#include <vector>
#include <string>
std::vector<std::string> hash_table;

std::vector<sameHash> s_hash_table;



std::vector<std::string> names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});


int hash(std::string element)
{
    int hashCode;
    for(int index; index < element.length(); index++)
    {
       hashCode += (int) element[index] ;
    }
    return hashCode % hash_table.size() ;
}

typedef struct sameHash
{
    std::string word;
    int s_hash = hash(word);
    sameHash* next = nullptr;
}sameHash;


void insert(std::vector<std::string>& hash_table,std::string element)
{
    // use (*this)[i] or this->get(i) to get a value at index i
    hash_table[hash(element)] = element ;
}

void s_insert(std::vector<sameHash>& s_hash_table, std::string element)
{
    sameHash* s_element = new sameHash;
    s_element->word =element;
    s_element->s_hash=hash(element);
    if(s_hash_table[s_element->s_hash].word=="")
    {
        s_hash_table[s_element->s_hash]= *s_element;
    }
    else
    {
        sameHash* current = &s_hash_table[s_element->s_hash];
        while(current->next!=nullptr)
        {
            current = current->next;
        }
        current->next = s_element;
    }
}


/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fiil
 * @param names array of names to insert
 * @param namesCount size of names array
 */
void buildHashTable(std::vector<std::string>& hash_table, std::string* names, int namesCount)
{
 
    for(int index = 0 ; index < namesCount; index++)
    {
        hash_table.push_back(names[index]);
    }
}

void s_buildHashTable(std::vector<sameHash>& hash_table, std::string* names, int namesCount)
{
    for(int index = 0 ; index < namesCount ; index++)
    {
        sameHash* s_element =new sameHash;
        s_element->word = names[index];
        hash_table.push_back(*s_element);
    }
}

bool contains(std::string element)
{
    // Note: Do not use iteration (for, while, ...)
    if(hash_table[hash(element)] == element)
    {
        return true;
    }
    return false;
}

bool s_contains(std::string element)
{
    sameHash* current = &s_hash_table[hash(element)];
    while(current!=nullptr)
    {
        if(current->word==element)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}


int main(int argc, char *argv[])
{
    //table.resize(10);
}
