// k smallest number with median property
#include <iostream>
#include <cstdlib>
using namespace std;
int  partition(int a[], int low, int high )
{//partition
	int pivot = a[low];
	int left =low;
	int right = high;
	while(left<=right)
	{
		while(a[left]<=pivot)
			{left++;}
		while(a[right]>pivot)
			{right--;}
		if(left<right)
		{
			/////swapping
			int temp = a[left];
			a[left]=a[right];
			a[right]=temp;
		}
	}
	a[low]=a[right];
	a[right]=pivot;
	return right;
	
}
int rank (int a[] , int i , int j ,int r )
{
	int fo = i + (rand()%(j-i+1));
	int temp = a[i];
	a[i]=a[fo];
	a[fo]=temp;
	int k = partition(a,i,j);
	if (r==j-k+1)
		return a[k];
	else if (r<j-k+1)
		return rank(a,k+1,j,r);
	else
		return rank(a,i,k,r-j+k);
}
int main()
{
	int a[16]={17,7,2,34,19,0,64,10,73,35,5,1,8,88,4,6};
	int k = 4;
	int size=16;
	int* c;  
	c = (int *)calloc(2*k,sizeof(int));
	for (int i = 0; i < 2*k; ++i)
	{
		c[i]=a[i];
	}
	int median = rank(c,0,2*k-1,k);
	for (int i = 2*k; i < size; ++i)
	{
		for (int j = k; j <2*k ; ++j)
		{
			if(i<size)
			c[j] = a[i++];
		}
		i--;
		median = rank(c,0,2*k-1,k);
	}
	for (int i = 0; i < k; ++i)
	{
		cout<<c[i]<<endl;
	}
	free(c);
}