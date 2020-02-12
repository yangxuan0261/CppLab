#include <iostream>
using namespace std;

// by MoreWindows( http://blog.csdn.net/MoreWindows )
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;


namespace QuickSort
{
    

//------------------------快速排序----------------------------
void quick_sort(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用 
		quick_sort(s, i + 1, r);
	}
}

void PrintArr(int a[], int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << a[i] << " - ";
	}
	cout << endl;
}

void main()
{
	int a[10] = { 9, 12, 17, 30, 50, 20, 60, 65, 4, 49 };
	int length = sizeof(a) / sizeof(int);
	PrintArr(a, length);

	quick_sort(a, 0, length-1);
	PrintArr(a, length);
}

} // QuickSort
