#include <iostream>
#include <time.h>



long power(long value, long n)
{
    if(n==0)
    {
        return 1;
    }
    return value*power(value,n-1);

    // your code
    // return_and_display shows the result in the window and returns it
    
}

int main(int argc, char *argv[])
{
    long a;
    long n;
    std::cout<<"Entrez une valeur de puissance à calculer, a :"<<"\n";
    std::cin>>a;
    std::cout<<"n :"<<"\n";
    std::cin>>n;
    std::cout<<"C est egal a : "<<power(a,n)<<"\n";
}