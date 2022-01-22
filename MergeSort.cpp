#include<iostream>
using namespace std;


void Merge(int a[], int l, int m, int r)
{
	int *a1 = new int[m - l + 1];
	int *a2 = new int[r - m];

	int size1 = m - l + 1;
	int size2 = r - m;
	int temp = l;
	for (int i = 0; i < size1 ; i++)
	{
		a1[i] = a[l++];
	}	
	
	for (int i =0; i < size2; i++)
	{
		a2[i] = a[l++];
	}
	
	int i  =0, j = 0;
	while(i < size1 && j < size2)
	{
		if(a1[i] < a2[j])
		{
			a[temp++] = a1[i];
			i++;
		} else 
		{
			a[temp++] = a2[j];
			j++;
		}
	}
	
	while(i < size1)
	{
		a[temp++] = a1[i];i++;
	}
	
	while(j < size2)
	{
		a[temp++] = a2[j]; j++;
	}
}


void MergeSort(int a[], int l, int r)
{
	if(l >= r)
		return;
	int m = (l + r) / 2;
	MergeSort(a, l, m);
	MergeSort(a, m + 1, r);
	Merge(a, l, m, r);
}

int main()
{
	int a[] = {1,3,2,4,612,321,512,321,56,7,8,5};
	int n = sizeof(a)/ sizeof(a[0]);
	MergeSort(a, 0 , n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}
