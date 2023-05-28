// #include "tp3.h"
// #include <QApplication>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

// MainWindow* w = nullptr;
// using std::size_t;

int binarySearch(vector<int>& sortedTab, int toSearch)
{
	int start = 0;
	int end = sortedTab.size()-1;
	
	while(start < end)
	{
		int middle = (start + end)/2;
		if(toSearch < sortedTab[middle])
		{
			end = middle;
		}
		if(toSearch > sortedTab[middle])
		{
			start = middle+1;
		}
		
		if(toSearch == sortedTab[middle])
		{
			return middle;
		}
	}
	
	return -1;
}

int main(int argc, char *argv[])
{
	// QApplication a(argc, argv);
	// MainWindow::instruction_duration = 500;
	// w = new BinarySearchWindow(binarySearch);
	// w->show();

	// return a.exec();
	vector<int> sorted;
    std::vector<int>::iterator i = sorted.begin();
    int array[] = {5,9,15,16,23,25,36,47,50,61,82,95,103};
    sorted.insert(i,array,array+13);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=sorted.begin(); it<sorted.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

	std::cout<<binarySearch(sorted,25)<<'\n';
	return 0;
}
