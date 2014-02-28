/*      Median of two sorted arrays -- dcc Feb 2014

	Adaptation to call leetcode class Solution function member

*/

#include <iostream>
// #include <algorithm>

#include "solution.h"

Solution s;

using namespace std;

int main()
{
	double answer;

	// median is 1
	int a[1]; // treating as length zero but must define with nonzero size.
	int b[] = { 1 }; 
	answer =  s.findMedianSortedArrays(a, 0, b, 1);
	cout << "should be 1, is " << answer << "\n";

    // median is 2.5
    int a1[] = { 1 };
    int b1[] = { 4 };
	answer =  s.findMedianSortedArrays(a1, 1, b1, 1);
	cout << "should be 2.5, is " << answer << "\n";
    
    // median is 4
    int a2[] = { 1 };
    int b2[] = { 4, 6 };
	answer =  s.findMedianSortedArrays(a2, 1, b2, 2);
	cout << "should be 4, is " << answer << "\n";
    
    // median is 7.5
    int c[] = { 1, 10 };
    int d[] = { 5, 20 };
    answer =  s.findMedianSortedArrays(c, 2, d, 2);
	cout << "should be 7.5, is " << answer << "\n";
    
    // median is 10
    int e[] = { 1, 5, 21};
    int f[] = { 10, 30 };
    answer =  s.findMedianSortedArrays(e, 3, f, 2);
	cout << "should be 10, is " << answer << "\n";

    // median is 15.5
    int e2[] = { 1, 5, 21};
    int f2[] = { 10, 25, 30 };
    answer =  s.findMedianSortedArrays(e2, 3, f2, 3);
	cout << "should be 15.5, is " << answer << "\n";

    // median is 15.5
    int e1[] = { 1, 5, 10 };
    int f1[] = { 21, 25, 30 };
    answer =  s.findMedianSortedArrays(e1, 3, f1, 3);
	cout << "should be 15.5, is " << answer << "\n";
	
    // median is 15.5
    int e3[] = { 21, 25, 30 };
    int f3[] = { 1, 5, 10 };
    answer =  s.findMedianSortedArrays(e3, 3, f3, 3);
	cout << "should be 15.5, is " << answer << "\n";

    // median is 7.5
    int g[] = { 1, 2, 3, 4, 10 };
    int h[] = { 5, 40, 50, 60, 70 };
    answer =  s.findMedianSortedArrays(g, 5, h, 5);
	cout << "should be 7.5, is " << answer << "\n";

    // median is 11
    int m[] = { 7, 14, 21, 28, 35, 42 };
    int n[] = { 2, 4, 6, 8, 10, 12 };
    answer =  s.findMedianSortedArrays(m, 6, n, 6);
	cout << "should be 11, is " << answer << "\n";
  
    // median is 12
    int m1[] = { 7, 14, 21, 28, 35, 42 };
    int n1[] = { 2, 4, 6, 8, 10, 12, 15 };
    answer =  s.findMedianSortedArrays(m1, 6, n1, 7);
	cout << "should be 12, is " << answer << "\n";
	
/*	
    // median is 6.5
    int x[] = {1,3,5,7,9,11};
    int y[] = {2,4,6,8,10,12};
    unsigned xyn = 6;
    median_driver(x, y, xyn);
    
    // median is 11
    int a1[ ]= { 2, 10, 15 };
    int a2[] = { 4, 12, 20 };
    unsigned an = 3;
    median_driver(a1, a2, an);
    
    // median is 50
    int z1[] = { 1, 2, 98, 99 };
    int z2[] = { 48, 49, 51, 52 };
    unsigned zn = 4;
    median_driver(z1, z2, zn);
*/

	// median is 40
	int ss[] = { 1, 34, 35, 36, 100 };
	int tt[] = { 20, 40, 60, 80, 110, 120 };
	answer =  s.findMedianSortedArrays(ss, 5, tt, 6);
	cout << "should be 40, is " << answer << "\n";
    
    return 0;   
}

