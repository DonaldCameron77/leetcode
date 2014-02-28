class Solution {
public:
    double findMedianSortedArrays(int A[], unsigned m, int B[], unsigned n)
	{
		return get_median_via_merge(A, m, B, n);
	}
private:

	double median(int a[], unsigned n) {
		if (n & 0x1)
			return a[n/2];
		else
			return (a[n/2] + a[(n-1)/2]) / 2.0;
	}

	double get_median_via_merge(int a[], unsigned m, int b[], unsigned n)
	{
		if (m == 0) return median(b, n);
		if (n == 0) return median(a, m);
		// if (n == 1) return (a[0] + b[0]) / 2.0;
		// if (n == 2) return (max(a[0], b[0]) + min(a[1], b[1])) / 2.0;
		// if (a[n-1] <= b[0]) return (a[n-1] + b[0]) / 2.0;
		// if (b[n-1] <= a[0]) return (b[n-1] + a[0]) / 2.0;

		// simulate merge of n elements from start of each array
		int prev = -1, cur = -1;
		for (unsigned ct = 0, ax = 0, bx = 0; ct <= (m + n) / 2; ++ct) {
			prev = cur;
			if (bx == n) cur = a[ax++];
			else if (ax == m) cur = b[bx++];
			else if (a[ax] < b[bx]) cur = a[ax++];
			else cur = b[bx++];
		}
		if ((m + n) & 1)
			return cur;
		else
			return (prev + cur) / 2.0;
	}

};
