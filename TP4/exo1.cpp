// #include "tp4.h"
// #include "mainwindow.h"

// #include <QApplication>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <vector>
#include<math.h>
using namespace std;

// MainWindow* w = nullptr;

struct Heap
{
	vector<int> tab;

	int leftChild(int nodeIndex)
	{
		return nodeIndex*2+1;
	};
	
	int rightChild(int nodeIndex)
	{
		return nodeIndex*2+2;
	};
	
	void insertHeapNode(int value)
	{
		this->tab.push_back(value);
		int i = this->tab.size()-1 ;
		while(i>0 && this->tab[i]>this->tab[(i-1)/2])
		{
			int  tmp = this->tab[(i-1)/2];
			this->tab[(i-1)/2] = this->tab[i];
			this->tab[i] = tmp;
			i=(i-1)/2;
		};
	};
	
	void heapify(int nodeIndex)
	{	
		int largest = nodeIndex ;
		if (this->tab[largest]<this->tab[rightChild(largest)])
		{
			largest = rightChild(largest);
		};
		if (this->tab[largest]<this->tab[leftChild(largest)])
		{
			largest = leftChild(largest);
		};
		if (largest!=nodeIndex)
		{
			int  tmp = this->tab[largest];
			this->tab[largest] = this->tab[nodeIndex];
			this->tab[nodeIndex] = tmp;
			heapify(largest);
		};
	}

	void buildHeap(vector<int> Numbers)
	{
		this->tab = Numbers;
		for(int i=0;i<Numbers.size();i++)
		{

			this->heapify(i);
		}
	}

	void sort()
	{
		for(int i = this->tab.size()-1 ; i>-1 ; i--)
		{
			int tmp = this->tab[0];
			this->tab[0] = this->tab[i];
			this->tab[i] = tmp;
			this->heapify(i);
		}
	}
};

struct Node
{
	int nodeIndex;
	int value;
	Node* filsgauche;
	Node* filsdroit;
	Node* parent;
};


int main(int argc, char *argv[])
{

	
	return 0;
}
