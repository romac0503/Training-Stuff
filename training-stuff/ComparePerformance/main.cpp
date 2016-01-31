// ComparePerformance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "priorityqueue.h"
#include "maxheap.h"
#include <ctime>
#include <windows.h>
#include <list>
#include <random>
#include <algorithm>

//#import "C:\\Program Files\\Microsoft Office 15\\root\\vfs\\ProgramFilesCommonX86\\Microsoft Shared\\OFFICE15\\MSO.DLL" \
//
//using namespace Office;
//
//#import "C:\\Program Files\\Microsoft Office 15\\root\\vfs\\ProgramFilesCommonX86\\Microsoft Shared\\VBA\\VBA6\\VBE6EXT.OLB" \
//
//using namespace VBIDE;
//
//#import "C:\\Program Files\\Microsoft Office 15\\Data\\Delta\\root\\office15\\EXCEL.EXE" \
//	 rename( "DialogBox", "ExcelDialogBox" ) \
//	 rename( "RGB", "ExcelRGB" ) \
//	 rename( "CopyFile", "ExcelCopyFile" ) \
//	 rename( "ReplaceText", "ExcelReplaceText" ) \
//	 exclude( "IFont", "IPicture" ) no_dual_interfaces


using namespace std;

int myRandom(int i)
{
	return rand() % i;
}

void createRandomNumbers(int amount, vector<int>& myVector)
{
	srand(unsigned(time(0)));

	// set some values:
	for (int i = 1; i < amount; ++i) myVector.push_back(i);

	// using built-in random generator:
	random_shuffle(myVector.begin(), myVector.end());

	// using myRandom:
	random_shuffle(myVector.begin(), myVector.end(), myRandom);
}


void TestPrioQueue(vector<int>& myVector)
{
	PriorityQueue<int> pq;
	vector<int> pq_vec = myVector;
	double elapsed_secs_enqueue, elapsed_secs_dequeue;

	long int begin = GetTickCount();
	// enqueue
	for (vector<int>::iterator it = pq_vec.begin(); it != pq_vec.end(); ++it)
	{
		pq.enqueue(*it);
	}
	long int end = GetTickCount();
	elapsed_secs_enqueue = double(end - begin) / CLOCKS_PER_SEC;
	cout << "PriorityQueue: Time for enqueue = \t" << elapsed_secs_enqueue << " seconds" << endl;

	begin = GetTickCount();
	// dequeue
	for (vector<int>::iterator it = pq_vec.begin(); it != pq_vec.end(); ++it)
	{
		pq.dequeue();
	}
	end = GetTickCount();
	elapsed_secs_dequeue = double(end - begin) / CLOCKS_PER_SEC;
	cout << "PriorityQueue: Time for dequeue = \t" << elapsed_secs_dequeue << " seconds" << endl << endl;
}

void TestMaxHeap(vector<int> myVector)
{
	MaxHeap<int> mh;
	vector<int> mh_vec = myVector;
	double elapsed_secs_enqueue, elapsed_secs_dequeue;

	// enqueue
	long int begin = GetTickCount();
	for (vector<int>::iterator it = mh_vec.begin(); it != mh_vec.end(); ++it)
	{
		mh.enqueue(*it);
	}
	long int end = GetTickCount();
	elapsed_secs_enqueue = double(end - begin) / CLOCKS_PER_SEC;
	cout << "MaxHeap: Time for enqueue = \t" << elapsed_secs_enqueue << " seconds" << endl;

	// dequeue
	begin = GetTickCount();
	for (vector<int>::iterator it = mh_vec.begin(); it != mh_vec.end(); ++it)
	{
		mh.dequeue();
	}
	end = GetTickCount();
	elapsed_secs_dequeue = double(end - begin) / CLOCKS_PER_SEC;
	cout << "MaxHeap: Time for dequeue = \t" << elapsed_secs_dequeue << " seconds" << endl << endl;
}

int main(int argc, char* argv[])
{
	vector<int> vector1;
	vector<int> vector2;
	vector<int> vector3;

	createRandomNumbers(10000, vector1);
	createRandomNumbers(50000, vector2);
	createRandomNumbers(100000, vector3);

	TestPrioQueue(vector1);
	TestMaxHeap(vector1);

	TestPrioQueue(vector2);
	TestMaxHeap(vector2);

	TestPrioQueue(vector3);
	TestMaxHeap(vector3);

	cin.get();
	return 0;
}



