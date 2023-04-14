// #include <QApplication>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

// #include "tp2.h"

// MainWindow* w = nullptr;

void selectionSort(vector<int>& toSort){ 
	// selectionSort
    
    for(int index = 0 ; index < toSort.size() ; index++){
        int min = toSort[index];
        for(int jndex = index ; jndex < toSort.size() ; jndex ++){
            if(min > toSort[jndex]){
                std::vector<int>::iterator it = toSort.begin();
                int new_min = toSort[jndex];
                toSort.erase(it+jndex);
                toSort.insert(it+index,new_min);
                min = new_min;
            }
       }
    }
}

int main(int argc, char *argv[])
{
	vector<int> toSort;
    std::vector<int>::iterator i = toSort.begin();
    int array[] = {5,9,15,2,6,7,4,5,8,10,6,7,3};
    toSort.insert(i,array,array+13);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    selectionSort(toSort);
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    
    // QApplication a(argc, argv);
    // uint elementCount=15; // number of elements to sort
    // MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    // w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    // w->show();

	return 0;//a.exec();
}
