// #include "tp3.h"
// #include <QApplication>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// MainWindow* w = nullptr;
// using std::size_t;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 */
void binarySearchAll(vector<int>& sortedTab, int toSearch, int& indexMin, int& indexMax)
{
	// do not use increments, use two different binary search loop
	int indexAll = -1;
	
	//First loop : indexMin
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
			indexAll = middle;
			break;
		}
	}
	indexMin = indexAll;
	indexMax = indexAll;
	if(indexAll!=-1){
		//First Loop : indexMin
		while(indexMin != 0 )
		{
			if(sortedTab[indexMin] == sortedTab[indexMin-1])
				{
					indexMin --;
				}
			else
				{
					break;
				}
		}

		//Second Loop : indexMax
		while(indexMax != sortedTab.size()-1 )
			{
				if(sortedTab[indexMax] == sortedTab[indexMax+1])
					{
						indexMax ++;
					}
				else
					{
						break;
					}
			}
    
	}
}

int main(int argc, char *argv[])
{
	// QApplication a(argc, argv);
	// MainWindow::instruction_duration = 500;
	// w = new BinarySearchAllWindow(binarySearchAll);
	// w->show();

	// return a.exec();
	vector<int> sorted;
	int indexMin;
	int indexMax;
    std::vector<int>::iterator i = sorted.begin();
    int array[] = {5,9,15,16,23,23,23,25,36,47,50,50,61,82,95,103};
    sorted.insert(i,array,array+16);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=sorted.begin(); it<sorted.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
	binarySearchAll(sorted,23
	,indexMin,indexMax);
	std::cout<<"indexMin = "<<indexMin<<'\n'<<"indexMax = "<<indexMax<<'\n';
	return 0;
}
