// #include <QApplication>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

// #include "tp2.h"

// MainWindow* w=nullptr;


// void bubbleSort(Array& toSort){
// 	// bubbleSort
	
// }
void bubbleSort(vector<int>& toSort){
	for(int index = 0 ; index < toSort.size() ; index++){
		for(int jndex = 0 ; jndex < toSort.size()-1 ; jndex ++){
			if(toSort[jndex] > toSort[jndex+1]){
				int tmp = toSort[jndex] ;
				toSort[jndex] = toSort[jndex+1] ;
				toSort[jndex + 1] = tmp ;
			}
		}
	}
	
}

int main(int argc, char *argv[])
{
	// QApplication a(argc, argv);
	// uint elementCount=20;
	// MainWindow::instruction_duration = 100;
	// w = new TestMainWindow(bubbleSort);
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
    bubbleSort(toSort);
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
	return 0;//a.exec();
}
