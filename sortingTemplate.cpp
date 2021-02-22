#include<stdio.h>
/*
main github account 		: https://github.com/david-yappeter
secondary github account	: https://github.com/davidyappeterMikroskil

Author		: David Yappeter
Created At	: 22/02/2021 
About		: Sorting Template (C language)
For			: 2nd Semester STMIK Mikroskil

Content:
	- Sorting Template 
		- Bubble Sort
		- Merge  Sort
		- Quick  Sort
*/

//	Sort Function
void BubbleSort(int arr[], int len);
void MergePivot(int arr[], int left, int right);
void MergeSort(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);
int  QuickSortPivot(int arr[], int left, int right);

//	tools
void swapVal(int *a, int *b);
void printArr(int arr[]);

//Global Variable
int arrSize = 20; 		// Init Array Size
bool sortAsc = true;	// true -> ascending, false -> descending

//main function
int main() {
	//Array variable size Must Match the 'arrSize'
	int arr[arrSize] = {5,1,2,6,7,9,28,19,258,9,2,8,58,2,7,28,18,59,2,59};
	
	printf("Before Sort : ");
	printArr(arr);
	
//	Example Of Sorting Function Call
//	MergeSort(arr, 0, arrSize - 1);
//	QuickSort(arr, 0, arrSize - 1);
//	BubbleSort(arr, arrSize);

	printf("After Sort : ");
	printArr(arr);
	
	return 0;
}

//BubbleSort Normal O(n^2) Bubble Sort
void BubbleSort(int arr[], int len){
	for(int j = len - 1; j >= 1; j--){
		for(int i = 0; i < j; i++){
			if(arr[i] > arr[j] ^ !sortAsc){
				swapVal(&arr[i], &arr[j]);
			}
		}
	}
}

//MergePivot to Merge 2 sorted sub Array
void MergePivot(int arr[], int left, int right){
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = 0;
	
	int temp[right - left + 1];
	
	while(i <= mid && j <= right) {
		if(arr[i] <= arr[j] ^ !sortAsc){
			temp[k] = arr[i];
			i++;
		}
		else{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	
	while(i <= mid){
		temp[k] = arr[i];
		i++;
		k++;
	}
	
	while(j <= right){
		temp[k] = arr[j];
		j++;
		k++;
	}
	
	for(int iter = 0; iter < k; iter++){
		arr[left + iter] = temp[iter];
	}
	
}

//MergeSort to Sort an Array
void MergeSort(int arr[], int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergePivot(arr, left, right);
	}
}

void QuickSort(int arr[], int left, int right) {
	if(left < right) {
		int pivot = QuickSortPivot(arr, left, right);
		
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

//QuickSortPivot To Divide value in an Array into smaller and bigger
int QuickSortPivot(int arr[], int left, int right) {
	int pivot = arr[right];
	int i = left, j = right - 1;
	if(sortAsc){
		pivot = arr[left];
		i++;
		j++;
	}

	while(i < j){
		while(i <= right && (arr[i] <= pivot ^ !sortAsc)){
			i++;
		}
		
		while(j >= 0 && (arr[j] > pivot ^ !sortAsc)){
			j--;
		}
		
		if(i < j){
			swapVal(&arr[i], &arr[j]);
		}
	}
	
	if(sortAsc){
		swapVal(&arr[left], &arr[j]);
		return j;
	}
	else{
		swapVal(&arr[right], &arr[i]);
		return i;
	}
}

//swapVal Swapping Two Value (Passing By Reference)
void swapVal(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

//printArr Printout an Array value
void printArr(int arr[]){
	for(int i = 0; i < arrSize; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

