//
//  main.cpp
//  algorithm
//
//  Created by ximena on 16/6/22.
//  Copyright © 2016年 ximena. All rights reserved.
//

#include <iostream>

#include "src/base/tree.h"
#include "src/base/sort.h"

template<class T,size_t N>
void printArr(T (&A)[N])
{
	for(size_t i=0;i<N;i++) std::cout<<"arr["<<i<<"]="<<A[i]<<std::endl;
}

int main(int argc, const char * argv[]) {
    
	/**
	 *1. test bstree
	 * */
	tree::bstree::test().run();
	
	/**
 	* 2. test sort 	
 	**/

	int arr[100]={0};
	for(int i=0;i<100;i++) arr[i]=rand()%99999;
	std::cout<<"init arr......."<<std::endl;
	printArr(arr);
	//bubble sort
	sort::bubble::sort(arr);
	std::cout<<"after bubble sort......."<<std::endl;
	printArr(arr);
	return 0;
}
