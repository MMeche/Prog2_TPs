#include <time.h>
#include<vector>
#include<iostream>
void allEvens(std::vector<int> evens, std::vector<int> array, int evenSize, int arraySize)
{
    if(arraySize<=0)
    {
        return;
    }
    if(array[arraySize-1]%2==0)
    {
        evens.push_back(array[arraySize-1]);
        evenSize++;
    }
    arraySize--;

    return allEvens(evens,array,evenSize,arraySize);
}

int main(int argc, char *argv[])
{
    std::vector<int> sorted;
    std::vector<int>::iterator i = sorted.begin();
    int array[] = {5,9,15,16,23,25,36,47,50,61,82,95,103};
    sorted.insert(i,array,array+13);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=sorted.begin(); it<sorted.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    std::vector<int> Evens;
    allEvens(Evens,sorted,0,sorted.size());
    std::cout << "Evens contains:";
    for (std::vector<int>::iterator it=Evens.begin(); it<Evens.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

    
    return 0;
}



