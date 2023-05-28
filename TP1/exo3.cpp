#include <iostream>
#include <time.h>
#include <vector>



int search(int value, std::vector<int> toSort, int size)
{
    if(size==0)
    {
        return -1;
    }
    if(toSort[size-1]==value)
    {
        return size;
    }
    else
    {
        size--;
        return search(value,toSort,size);
    }
    // your code
    // check the last cell and if it does not correspond
    // then consider a smaller array when recalling search
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
    int value;
    std::cout<<"Rentrez la valeur a chercher dans myvector :"<<"\n";
    std::cin>>value;
    if(search(value,sorted,sorted.size())!=-1)
    {
        std::cout<<value<<" est present a la position : "<<search(value,sorted,sorted.size())-1<<"\n";
        return 0;
    }
    std::cout<<"La valeur n'est pas presente";
    return 0;
     // main loop while window is opened
}








