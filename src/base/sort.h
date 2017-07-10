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
#include	<stdlib.h>
//#include	<malloc.h>

namespace sort {
    
    template <class T> void swap ( T& a, T& b )
    {
        T c(a); a=b; b=c;
    }
    
    namespace bubble{
        
        template<class T,size_t N>
        void sort(T (&A)[N])
        {
            for (int j = 0; j < N-1; j++)
            for (int i = 0; i < N-j-1; i++)
            if (A[i] > A[i+1])
            sort::swap(A[i], A[i+1]);
        }
        
        
    }//end bubble
    
    namespace insertion{
        
        template<class T,size_t N>
        void sort(T (&A)[N])
        {
            for (int i = 1; i <= N; i++)
            {
               decltype(A[i]) e = A[i];
               int j = i;
               while (j > 0)
               {
                    if (A[j-1] > e)
                        A[j] = A[j-1];
                    else
                        break;
                    j--;
               }
                A[j] = e;
            }
        }
        
        
        
    }//end insertion
    
    namespace selection{
        
        template<class T,size_t N>
        void sort(T (&A)[N])
        {
            for (int i = 0; i < N-1; i++)
            {
                int cur_min = i;
                for (int j = i+1; j < N; j++)
                    if (A[j] < A[cur_min]) // each execution of this if-statement is counted as one comparison
                        cur_min = j;
                sort::swap(A[i], A[cur_min]);
            }
        }
        
        
    }//end selection
    
    namespace merge{
        
        template<class T,size_t N>
        void mergeSort(T (&A)[N], int Left, int Middle, int Right)
        {
            //T* tmp = (T*)malloc(N*sizeof(T)) ;
            T* tmp = new T[N*sizeof(T)];
            int i = Left, j = Middle + 1;
            
            for (int step = 0; step < Right - Left + 1; ++step)
            {
                if ((j > Right || (i <= Middle && A[i] < A[j])))
                {
                    tmp[step] = A[i];
                    ++i;
                }
                else
                {
                    tmp[step] = A[j];
                    ++j;
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
        template<class T,size_t N>
        void sort(T (&A)[N], int Left=0, int Right=N-1)
        {
            if (Left >= Right) return;
            int Middle = (Left + Right) / 2;
            
            sort(A, Left, Middle);
            sort(A, Middle + 1, Right);
            mergeSort(A, Left, Middle, Right);
            return;
        }
        
    }//end merge
    
    namespace quick{
        
        template<class T,size_t N>
        void sort(T (&A)[N], int low=0, int high=N-1)
        {
            /**
             Considering the small number of cases
             */
            if(high-low+1<10)
                return selection::sort(A);
            
            ///////////////////////////////
            int i = low;
            int j = high;
            int x = A[(low+high)/2];
            do {
                while(A[i] < x) ++i;
                while(A[j] > x) --j;
                if(i <= j)
                {
                    sort::swap(A[i], A[j]);
                    i++; j--;
                }
            } while(i < j);
            if(low < j)     sort(A, low, j);
            if(i < high)    sort(A, i, high);
        }
        
    }//end quick
    
    namespace radix{
        
        int maxbit(int data[], int n)
        {
            int d = 1;
            int p = 10;
            for(int i = 0; i < n; ++i)
            {
                while(data[i] >= p)
                {
                    p *= 10;
                    ++d;
                }
            }
            return d;
        }
        template<size_t N>
        void sort(int (&A)[N], int n=N)
        {
            int d = maxbit(A, n);
            int *tmp = new int[n];
            int *count = new int[10];
            int i, j, k;
            int radix = 1;
            for(i = 1; i <= d; i++)
            {
                for(j = 0; j < 10; j++)
                    count[j] = 0;
                for(j = 0; j < n; j++)
                {
                    k = (A[j] / radix) % 10;
                    count[k]++;
                }
                for(j = 1; j < 10; j++)
                    count[j] = count[j - 1] + count[j];
                for(j = n - 1; j >= 0; j--)
                {
                    k = (A[j] / radix) % 10;
                    tmp[count[k] - 1] = A[j];
                    count[k]--;
                }
                for(j = 0; j < n; j++)
                    A[j] = tmp[j];
                radix = radix * 10;
            }
            delete[]tmp;
            tmp = nullptr;
            delete[]count;
            count = nullptr;
        }
        
    }
    
}//end sort
#endif /* sort_h */
