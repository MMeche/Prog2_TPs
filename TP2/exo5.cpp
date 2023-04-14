// #include <QApplication>
#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int> first, vector<int> second, vector<int> result);
// #include "tp2.h"

// MainWindow* w=nullptr;

// void merge(Array& first, Array& second, Array& result);

void splitAndMerge(vector<int>& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	if(origin.size()==1)
	{
		return;
	}
	// initialisation
	vector<int> first;
	vector<int> second;
	
	// split
	for(int index = 0; index < origin.size(); index++)
	{
		if(index < origin.size()/2){
			first.push_back(origin[index]);
		}
		else
		{
			second.push_back(origin[index]);
		}
	}

	// recursiv splitAndMerge of lowerArray and greaterArray
	splitAndMerge(first);
	splitAndMerge(second);
	// merge
	merge(first,second,origin);
}

int min(vector<int> first , vector<int> second)
{
	int i_min_first = 0;
	int i_min_sec = 0;
	int min = first[0];

	std::vector<int>::iterator it_f = first.begin();
	std::vector<int>::iterator it_s = second.begin();

	if(first.size()==0)
	{
		int min = second[0];
		second.erase(it_s);
		return min;
	}

	if(second.size()==0)
	{
		int min = first[0];
		first.erase(it_f);
		return min;
	}
	
	if(second[0] < first[0])
	{
		int min = second[0];
		second.erase(it_s);
		return min;
	}
	else
	{
		int min = first[0];
		first.erase(it_f);
		return min;
	}
}

void merge(vector<int> first, vector<int> second, vector<int> result)
{
	for(int index = 0 ; index < result.size() ; index++)
	{
		result[index] = min(first,second);
	}
}

void mergeSort(vector<int>& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	vector<int> toSort;
    std::vector<int>::iterator i = toSort.begin();
    int array[] = {1,9,15,2,6,7,4,5,8,10,6,7,3};
    toSort.insert(i,array,array+13);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
    mergeSort(toSort);
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=toSort.begin(); it<toSort.end(); it++){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

	return 0 ;
	
	// QApplication a(argc, argv);
	// MainWindow::instruction_duration = 50;
    // w = new TestMainWindow(mergeSort);
	// w->show();

	// return a.exec();
}
