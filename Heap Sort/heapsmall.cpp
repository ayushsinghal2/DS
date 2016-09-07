// k smallest number with heap only
#include <iostream>
using namespace std;
void maxheapify(int a[], int i,int size)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest=i;
	if(l < size && a[l]>a[i])
	{
		largest=l;
	}
	else if(r < size && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		int temp = a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheapify(a,largest,size);
	}	
}
void buildheap(int a[],int n)
{
	for (int i = n/2; i >= 0; --i)
	{
		maxheapify(a,i,n);
	}
}
int main()
{
	int a[10]={17,7,2,34,19,15,64,54,73,35};
	int k = 4;
	int c[4]={17,7,2,34};//change generic
	buildheap(c,4);
	//cout<<c[0]<<"   "<<c[1]<<"   "<<c[2]<<"   "<<c[3]<<endl;
	for (int i = 4; i < 10; ++i)
	{
		if(a[i]<c[0])
		{
			c[0]=a[i];
			buildheap(c,4);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		cout<<c[i]<<endl;
	}
}