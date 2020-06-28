#ifndef Testsearch_h__
#define Testsearch_h__

#include <iostream>
#include <vector>
using namespace std;

//二分法查找
int BinarySearch(vector<int> v, int value, int low, int high) {
	if (v.size() <= 0) {
		return -1;
	}
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (v[mid] == value) {
			return mid;
		}
		else if (v[mid] > value) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
}
void test_binarysearch()
{
std:vector<int> vec;
	for (int i = 0; i < 100; i++)
	{
		vec.push_back(i);
	}
	int ret = BinarySearch(vec, 30, 0, 100);
}

#endif // Testsearch_h__
