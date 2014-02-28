/*      Median of two sorted arrays -- dcc Feb 2014

    This is the case where the arrays are of equal length.  The element type is int,
    but I do the solution works for negative values as well.
    
*/

#include <iostream>
#include <algorithm>

using namespace std;

inline bool odd(unsigned x) { return x & 1; }

float median(int a[], unsigned n) {
    if (odd(n))
        return a[n/2];
    else
        return (a[n/2] + a[(n-1)/2]) / 2.0;
}

float get_median_nn_via_merge( int a[], int b[], unsigned n )
{
    if (n <= 0) return -1;
    if (n == 1) return (a[0] + b[0]) / 2.0;
    if (n == 2) return (max(a[0], b[0]) + min(a[1], b[1])) / 2.0;
    if (a[n-1] <= b[0]) return (a[n-1] + b[0]) / 2.0;
    if (b[n-1] <= a[0]) return (b[n-1] + a[0]) / 2.0;
    
    // simulate merge of n elements from start of each array
    int last = -2147483648, cur = -2147483648;
    for (unsigned ct = 0, ax = 0, bx = 0; ct <= n; ++ct) {
        last = cur;
        if (a[ax] < b[bx]) {
            cur = a[ax];
            ++ax;
        }
        else {
            cur = b[bx];
            ++bx;
        }    
    }
    return (last + cur) / 2.0;
}

float get_median_nn( int a[], int b[], unsigned n )
{
    if (n <= 0) return -1;
    if (n == 1)
        return (a[0] + b[0]) / 2.0;
    if (n == 2)
        return (max(a[0], b[0]) + min(a[1], b[1])) / 2.0;
    
    float m_a = median(a, n);
    float m_b = median(b, n);
    
    if (m_a == m_b) {
        return m_a; // or m_b .. w.e
    }
    
    if (m_a < m_b) {
        // the median resides in a[m_a .. <end>] or in b[<start> .. m_b]
        if ( n & 0x1 )
            return get_median_nn(a + n/2, b, n - n/2);
        else
            return get_median_nn(a + n/2 - 1, b, n - n/2 + 1);
    }
    else {
        if ( n & 0x1 )
            return get_median_nn(b + n/2, a, n - n/2);
        else
            return get_median_nn(b + n/2 - 1, a, n - n/2 + 1);
    }
}

void median_driver( int a[], int b[], unsigned n ) {
    float merge_median = get_median_nn_via_merge(a, b, n);
    cout << merge_median << "\n";
    float logn_median = get_median_nn(a, b, n);
    cout << logn_median << "\n";
    if (merge_median != logn_median) cout << "ERROR!";
    cout << endl;
}

int main()
{
    // median is 2.5
    int a[] = { 1 };
    int b[] = { 4 };
    unsigned abn = 1;
    median_driver(a, b, abn);
    
    // median is 7.5
    int c[] = { 1, 10 };
    int d[] = { 5, 20 };
    unsigned cdn = 2;
    median_driver(c, d, cdn);
    
    // median is 15.5
    int e[] = { 1, 5, 21};
    int f[] = { 10, 25, 30 };
    unsigned efn = 3;
    median_driver(e, f, efn);

    // median is 15.5
    int e1[] = { 1, 5, 10 };
    int f1[] = { 21, 25, 30 };
    unsigned ef1n = 3;
    median_driver(e1, f1, ef1n);

    // median is 15.5
    int e2[] = { 21, 25, 30 };
    int f2[] = { 1, 5, 10 };
    unsigned ef2n = 3;
    median_driver(e2, f2, ef2n);

    // median is 7.5
    int g[] = { 1, 2, 3, 4, 10 };
    int h[] = { 5, 40, 50, 60, 70 };
    unsigned ghn = 5;
    median_driver(g, h, ghn);
    
    // median is 11
    int m[] = { 7, 14, 21, 28, 35, 42 };
    int n[] = { 2, 4, 6, 8, 10, 12 };
    unsigned mnn = 6;
    median_driver(m, n, mnn);
    
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
    
    return 0;   
}

