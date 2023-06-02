#include <time.h>
#include <vector>
#include <string>
#include <iostream>


std::vector<std::string> hash_table;



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
    
    return (int)element[0] % hash_table.size() ;
}


typedef struct sameHash
{
    std::string word;
    int s_hash = hash(word);
    sameHash* next = nullptr;
}sameHash;
std::vector<sameHash> s_hash_table;




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
void buildHashTable(std::vector<std::string>& hash_table, std::vector<std::string> names, int namesCount)
{
 
    for(int index = 0 ; index < namesCount; index++)
    {
        hash_table.push_back("");
    }
    for(int index = 0 ; index < hash_table.size() ; index++)
    {
        insert(hash_table,names[index]);
    }
        
}

void s_buildHashTable(std::vector<sameHash>& s_hash_table, std::vector<std::string> names, int namesCount)
{
    for(int index = 0 ; index < namesCount ; index++)
    {
        sameHash* s_element =new sameHash;
        s_element->word = "";
        s_hash_table.push_back(*s_element);
    }

    for(int index =0 ; index < s_hash_table.size();index++ )
    {
        s_insert(s_hash_table,names[index]);
    }
}

bool contains(std::string element)
{
    // Note: Do not use iteration (for, while, ...)
    return hash_table[hash(element)] == element;
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
    std::cout<<"Tests pour l'implementation sans possibilite de doublon de hash\n";
    buildHashTable(hash_table,names,names.size());
    std::cout<<"La table contient Marie : "<<contains("Marie")<<"\n"; 
    /*C'est bien ma veine j'ai choisi la seule qui se fait écraser :) */
    std::cout<<hash("Marie")<<"\n";
    std::cout<<hash_table[hash("Marie")]<<"\n";
    std::cout<<"La table contient Matteo : "<<contains("Matteo")<<"\n";
    std::cout<<"La table contient Matthieu : "<<contains("Matthieu")<<"\n";

    std::cout<<"Tests pour l'implementation avec possibilite de doublon de hash\n";
    s_buildHashTable(s_hash_table,names,names.size());
    std::cout<<"La table contient Marie : "<<s_contains("Marie")<<"\n"; 
    std::cout<<hash("Marie")<<"\n";
    std::cout<<"La table contient Matteo : "<<s_contains("Matteo")<<"\n";
    std::cout<<hash("Matteo")<<"\n";
    std::cout<<"La table contient Matthieu : "<<s_contains("Matthieu")<<"\n";


    return 0;
}
