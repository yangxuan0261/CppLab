#include <iostream>

#include "gtest/gtest.h"

using namespace std;

namespace MergeSort {

//------------------------归并排序----------------------------
//将有二个有序数列a[first...mid]和a[mid...last]合并。
    void mergearray(int a[], int first, int mid, int last, int temp[]) {
        int i = first, j = mid + 1;
        int m = mid, n = last;
        int k = 0;

        while (i <= m && j <= n) {
            if (a[i] < a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }

        while (i <= m)
            temp[k++] = a[i++];

        while (j <= n)
            temp[k++] = a[j++];

        for (i = 0; i < k; i++)
            a[first + i] = temp[i];
    }

    // 归并排序 就是个二叉树的 后序遍历
    void mergesort(int a[], int first, int last, int temp[]) {
        if (first < last) {
            int mid = (first + last) / 2;
            mergesort(a, first, mid, temp);    //左边有序
            mergesort(a, mid + 1, last, temp); //右边有序
            mergearray(a, first, mid, last, temp); //再将二个有序数列合并
        }
    }

    bool MergeSort(int a[], int n) {
        int *p = new int[n];
        if (p == NULL)
            return false;
        mergesort(a, 0, n - 1, p);
        return true;
    }

    void PrintArr(int a[], int len) {
        for (size_t i = 0; i < len; i++) {
            cout << a[i] << " - ";
        }
        cout << endl;
    }

    TEST(TestMergeSort, test_main) {
        int a[10] = {9, 12, 17, 30, 50, 20, 60, 65, 4, 49};
        int length = sizeof(a) / sizeof(int);
        PrintArr(a, length);

        MergeSort(a, length);
        PrintArr(a, length);
    }
}
