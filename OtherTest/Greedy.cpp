//Ì°ÐÄËã·¨
#include<iostream>
using namespace std;

namespace Greedy {
	int GreedySelect(int *s, int *f, int length, int *a) {
		int i, j = 2;
		a[1] = 1;
		i = 1;
		for (int m = 2; m <= length; m++) {
			if (s[m] >= f[i]) {
				a[j++] = m;
				i = m;
			}
		}
		return j;
	}
	extern void main() {
		int s[12] = { 0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
		int f[12] = { 0, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
		int a[13];
		int i = GreedySelect(s, f, 11, a);
		for (int j = 1; j < i; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
	}
}