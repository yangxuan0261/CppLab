#include <iostream>
using namespace std;

namespace HeapSort
{

inline void Swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

//  新加入i结点  其父结点为(i - 1) / 2
void MinHeapFixup(int a[], int i)
{
	int j, temp;

	temp = a[i];
	j = (i - 1) / 2; //父结点
	while (j >= 0 && i != 0)
	{
		if (a[j] <= temp)
			break;

		a[i] = a[j]; //把较大的子结点往下移动,替换它的子结点
		i = j;
		j = (i - 1) / 2;
	}
	a[i] = temp;
}

//在最小堆中加入新的数据nNum
void MinHeapAddNumber(int a[], int n, int nNum)
{
	a[n] = nNum;
	MinHeapFixup(a, n);
}

//  从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2
void MinHeapFixdown(int a[], int i, int n)
{
	int j, temp;

	temp = a[i];
	j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1 < n && a[j + 1] < a[j]) //在左右孩子中找最小的
			j++;

		if (a[j] >= temp)
			break;

		a[i] = a[j]; //把较小的子结点往上移动,替换它的父结点
		i = j;
		j = 2 * i + 1;
	}
	a[i] = temp;
}
//在最小堆中删除数
void MinHeapDeleteNumber(int a[], int n)
{
	Swap(a[0], a[n - 1]);
	MinHeapFixdown(a, 0, n - 1);
}

//建立最小堆
void MakeMinHeap(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		MinHeapFixdown(a, i, n);
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

	int a[10] = {9, 12, 17, 30, 50, 20, 60, 65, 4, 49};
	int length = sizeof(a) / sizeof(int);
	PrintArr(a, length);

	MakeMinHeap(a, length);
	PrintArr(a, length);
}

/*
算法思想：存储结构为数组，逻辑结构为二叉树
1、堆化数组，数组从0~length-1化成二叉树结构
2、向下调整，从下标为length / 2 - 1的位置开始依次向前向下调整，因为这个下标是最后一个拥有孩子节点的位置
3、删除最小（最大值），从堆顶删除，最后一个元素补上堆顶，堆顶再向下调整
3、添加值，从堆尾添加，再向上调整
*/

} // namespace HeapSort
