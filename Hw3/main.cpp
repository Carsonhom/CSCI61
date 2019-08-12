#include <queue>
#include <stack>
#include <iostream>
#include <string>

void InsertionSort(int arr[], int n) 
{ 
    if (n <= 1) 
        return; 
    else
    {
    	InsertionSort(arr, n - 1); 
    	int last = arr[n - 1]; 
    	int j = n - 2; 
    	while (j >= 0 && arr[j] > last) 
   		{ 
        	arr[j + 1] = arr[j]; 
        	j--; 
    	} 
    	arr[j+1] = last; 
	}
} 

std::string d2b(unsigned n)
{
	if(n <= 0)
	{
		return "";
	}
	else 
	{
		unsigned rem = n % 2;
		std::string r;
		if(rem == 0)
		{
			r = "0";
		}
		else 
		{
			r = "1";
		}
		return d2b(n / 2) += r;
	}
}

void Merg3(int arr[],int lo,int mid1,int mid2,int hi)
{
	int arr2[hi + 1];
	int posa = lo;
	int posb = mid1 + 1;
	for(int i = 0; i < mid2 + 1; ++i)
	{
		if(posa < mid1 +1 && posb < mid2 + 1)
		{
			if(arr[posa] < arr[posb])
			{
				arr2[i] = arr[posa];
				posa++;
			}
			else 
			{
				arr2[i] = arr[posb];
				posb++;
			}
		}
		else if(posa > mid1 && posb < mid2 + 1)
		{
			arr2[i] = arr[posa];
			posa++;
		}
		else if(posb > mid2 && posa < mid1 + 1)
		{
			arr2[i] = arr[posb];
			posb++;
		}
	}
		posa = lo;
		posb = mid2 + 1;
		for(int i = 0; i < hi + 1; ++i)
		{
			if(posa < mid2 +1 && posb < hi + 1)
			{
				if(arr[posa] < arr[posb])
				{
					arr2[i] = arr[posa];
					posa++;
				}
				else 
				{
					arr2[i] = arr[posb];
					posb++;
				}
			}
			else if(posa > mid2 && posb < hi + 1)
			{
				arr2[i] = arr[posa];
				posa++;
			}
			else if(posb > hi && posa < mid2 + 1)
			{
				arr2[i] = arr[posb];
				posb++;
			}
		}	

	

	for(int i = 0; i < hi + 1; ++i)
	{
		arr[i] = arr2[i];
	}
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void merge_sort_3(int A[], int lo, int hi)
{
	int sizes = hi / 3;
	int rem = hi % 3;
	int mid1 = sizes + rem;
	int mid2 = mid1 + sizes;
	quickSort(A, lo, mid1);
	quickSort(A, mid1 + 1, mid2);
	quickSort(A, mid2 + 1, hi);
	Merg3(A, lo, mid1, mid2, hi);
}

int main()
{
	int unsorted[6] = {3, 1, 5, 2, 4, 6};
	merge_sort_3(unsorted, 0, 5);
	for(int i = 0; i < 6; ++i)
	{
		std::cout << unsorted[i] << std::endl;
	}

	unsigned dec = 294;
	std::cout << d2b(dec) << std::endl;


	

	
	

	
	return 0;
}