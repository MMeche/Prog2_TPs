// #include <QApplication>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
// #include "tp2.h"


// MainWindow* w=nullptr;

// void recursivQuickSort(Array& toSort, int size)
// {
// 	// stop statement = condition + return (return stop the function even if it does not return anything)
	
// 	Array& lowerArray = w->newArray(size);
// 	Array& greaterArray= w->newArray(size);
// 	int lowerSize = 0, greaterSize = 0; // effectives sizes

// 	// split
	
// 	// recursiv sort of lowerArray and greaterArray

// 	// merge
// }

void recursivQuickSort(vector<int>& toSort, int size){
	if(size!=1 && size!=0){
        int pivot = toSort[0];
        std::cout << "affiche pivot : " << pivot << "\n";

        std::vector<int> lowers;
        std::vector<int> greaters;

        for(int k=1;k<size;k++){
            if(toSort[k]<pivot){
                lowers.push_back(toSort[k]);
            }
            else{
                greaters.push_back(toSort[k]);
            }
        }

        recursivQuickSort(lowers, lowers.size());
        recursivQuickSort(greaters, greaters.size());

        for(int i=0;i<lowers.size();i++){
            toSort[i] = lowers[i];
        }

        toSort[lowers.size()] = pivot;

        int temp = lowers.size()+1;

        for(temp;temp<size;temp++){
            toSort[temp] = greaters[temp-(lowers.size()+1)];
        }
    }
    else{
        return;
    }
}


int main(int argc, char *argv[])
{
	// QApplication a(argc, argv);
	// uint elementCount=20;
	// MainWindow::instruction_duration = 50;
    // w = new TestMainWindow(quickSort);
	// w->show();
	vector<int> toSort;
    std::vector<int>::iterator i = toSort.begin();
    int array[] = {1,9,15,2,6,7,4,5,8,10,6,7,3};
    toSort.insert(i,array,array+13);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    recursivQuickSort(toSort,toSort.size());
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

	return 0 ;//a.exec();
}
