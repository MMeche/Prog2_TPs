#include <iostream>
#include <time.h>

int fibonacci(int value)
{
    if(value == 1 | value == 2)
    {
        return 1;
    }
    return fibonacci(value-1)+fibonacci(value-2);
    

    // your code

    
}

int main(int argc, char *argv[])
{
    int value;
    std::cout<<"Entrez le numero du nombre de fibonacci a calculer :"<<"\n";
    std::cin>>value;

    std::cout<<"C est egal a : "<<fibonacci(value)<<"\n";
    return 0;
}
