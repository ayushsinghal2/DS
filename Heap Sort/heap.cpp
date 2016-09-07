//heap sort ....
#include <iostream>
using namespace std;
void topdownheap(int arr[],int i,int n)
{
	int largest = i; 
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
 
        // Recursively heapify the affected sub-tree
        topdownheap(arr,  largest,n);
    }
}
void heapsort(int arr[] , int n)
{
	for (int i = (n / 2)-1; i >= 0; i--)
        topdownheap(arr, i, n);
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
 		int temp = arr[0];
 		arr[0]=arr[i];
 		arr[i]=temp;
        // call max heapify on the reduced heap
        topdownheap(arr, 0, i);
    }
}
int main()
{
	int a[10]={17,7,2,34,19,15,64,54,73,35};
	heapsort(a,10);
	for (int i = 0; i < 10; ++i)
	{
		cout<<a[i]<<" , ";
	}
	cout<<endl;

}