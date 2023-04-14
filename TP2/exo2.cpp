//#include <QApplication>
#include <time.h>
#include<iostream>
#include <vector>
using namespace std;

//#include "tp2.h"

//MainWindow* w=nullptr;

// void insertionSort(vector<int> toSort){
	// Array& sorted=w->newArray(toSort.size());

	// insertion sort from toSort to sorted
	
	// toSort=sorted; // update the original array
// }

void insertionSort(vector<int>& toSort)
{
	vector<int> selection;
    selection.push_back(toSort[0]);
    for(int index = 1 ; index < toSort.size() ; index++){
       for (int j = 0 ; j < selection.size() ; j++){
            if (selection[j] > toSort[index]){
                std::vector<int>::iterator it = selection.begin();
                selection.insert(it+j,toSort[index]);
                break;
            }
            selection.push_back(toSort[index]);
       }
    }
	toSort = selection;
}

int main(int argc, char *argv[])
{
	// QApplication a(argc, argv);
    // uint elementCount=15; // number of elements to sort
    // MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    // w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	// w->show();
	
	vector<int> toSort;
    std::vector<int>::iterator i = toSort.begin();
    int array[] = {5,9,15,2,6,7,4,5,8,10,6,7,3};
    toSort.insert(i,array,array+13);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    insertionSort(toSort);
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

	return 0 ; //a.exec();
}
