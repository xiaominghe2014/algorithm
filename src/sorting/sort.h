//----------------------------------------------//
//  sort.h
//  algorithm
//
//  Copyright (c) __DATA__  Ximena.
//  Created by ximena on 16/6/22.
//  Copyright © 2016年 ximena. All rights reserved.
//  Contact Email: xiaominghe2014@gmail.com
//----------------------------------------------//

#ifndef sort_h
#define sort_h
#include <stdlib.h>
//#include	<malloc.h>
/**
 * 本程序默认按照从小到大排序
 */
namespace sort
{

template <class T>
void swap(T &a, T &b)
{
    T c(a);
    a = b;
    b = c;
}

/**
* 冒泡排序
* 相邻比较,每次冒出最小/大 为稳定排序
*/
template <class T, size_t N>
void bubble(T (&A)[N])
{
    for (int j = 0; j < N - 1; j++)
        for (int i = 0; i < N - j - 1; i++)
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
}

/**
* 选择排序
* 每次选出最小/大 为不稳定排序
*/
template <class T, size_t N>
void selection(T (&A)[N])
{
    for (int i = 0; i < N - 1; i++)
    {
        int cur_min = i; //选出第i个最小
        for (int j = i + 1; j < N; j++)
            if (A[j] < A[cur_min])
                cur_min = j;
        swap(A[i], A[cur_min]);
    }
}

/**
 * 插入排序
 * 每次插入一个数据使得有序,为稳定排序
 */
template <class T, size_t N>
void insertion(T (&A)[N])
{
    for (int i = 1; i <= N; i++)
    {
        decltype(A[i]) e = A[i];
        //每次插入的i和前面的j序列比较
        int j = i;
        while (j > 0)
        {
            if (A[j - 1] > e)
                A[j] = A[j - 1];
            else
                break;
            j--;
        }
        A[j] = e;
    }
}

/**
* 归并排序
* 将数列分为两个一组排列,依次合并,为稳定排序
*/
namespace merge
{

template <class T, size_t N>
void mergeSort(T (&A)[N], int Left, int Middle, int Right)
{
    //T* tmp = (T*)malloc(N*sizeof(T)) ;
    T *tmp = new T[N * sizeof(T)];
    int i = Left, j = Middle + 1;

    for (int step = 0; step < Right - Left + 1; ++step)
    {
        if ((j > Right || (i <= Middle && A[i] < A[j])))
        {
            tmp[step] = A[i++];
        }
        else
        {
            tmp[step] = A[j++];
        }
    }

    for (int step = 0; step < Right - Left + 1; ++step)
    {
        A[Left + step] = tmp[step];
    }
    //free(tmp);
    delete[] tmp;
    tmp = nullptr;
    return;
}
template <class T, size_t N>
void sort(T (&A)[N], int Left = 0, int Right = N - 1)
{
    if (Left >= Right)
        return;
    int Middle = (Left + Right) / 2;

    sort(A, Left, Middle);
    sort(A, Middle + 1, Right);
    mergeSort(A, Left, Middle, Right);
    return;
}

} //end merge

/**
* 快速排序
* 每次通过一个值降数组分为左右两个部分,然后左右递归,为不稳定排序
*/
namespace quick
{

template <class T, size_t N>
void sort(T (&A)[N], int low = 0, int high = N - 1)
{
    /**
             Considering the small number of cases
             */
    if (high - low + 1 < 10)
        return selection::sort(A);

    ///////////////////////////////
    int i = low;
    int j = high;
    int x = A[(low + high) / 2];
    do
    {
        while (A[i] < x)
            ++i;
        while (A[j] > x)
            --j;
        if (i <= j)
        {
            sort::swap(A[i], A[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (low < j)
        sort(A, low, j);
    if (i < high)
        sort(A, i, high);
}

} //end quick

/**
* 基数排序
* 每次从个位排序直到最高位,为稳定排序
*/
namespace radix
{

int maxbit(int data[], int n)
{
    int d = 1;
    int p = 10;
    for (int i = 0; i < n; ++i)
    {
        while (data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
template <size_t N>
void sort(int (&A)[N], int n = N)
{
    int d = maxbit(A, n);
    int *tmp = new int[n];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++)
    {
        for (j = 0; j < 10; j++)
            count[j] = 0;
        for (j = 0; j < n; j++)
        {
            k = (A[j] / radix) % 10;
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j];
        for (j = n - 1; j >= 0; j--)
        {
            k = (A[j] / radix) % 10;
            tmp[count[k] - 1] = A[j];
            count[k]--;
        }
        for (j = 0; j < n; j++)
            A[j] = tmp[j];
        radix = radix * 10;
    }
    delete[] tmp;
    tmp = nullptr;
    delete[] count;
    count = nullptr;
}
/**
 * 计数排序
 * 适合指定区间上大量数据的排序,为稳定排序
 */
}

} //end sort
#endif /* sort_h */
