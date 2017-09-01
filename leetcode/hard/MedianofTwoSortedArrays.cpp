/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	int m = nums1.size();
	int n = nums2.size();
	vector<int> a;
	int i = 0;
	a.resize(m+n);
	copy(nums1.begin(),nums1.end(),a.begin());
	vector<int>::iterator it  = a.begin();
	while(i < m)
	{
		++i;
		++it;
	}
	copy(nums2.begin(),nums2.end(),it);
	sort(a.begin(),a.end());

	double median = double ( (m+n)%2 ? a[(n+m)>>1] : (a[(n+m)>>1]+a[(m+n-1)>>1])/2.0 );
	return median;
}

int main()
{
	int arr[] = {};
	int arr1[] = {2,3};
	vector<int> nums1;
	vector<int> nums2;
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
		nums1.push_back(arr[i]);
	for(int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); ++i)
		nums2.push_back(arr1[i]);
	
	cout<<findMedianSortedArrays(nums1,nums2)<<endl;
	

	return 0;
}
