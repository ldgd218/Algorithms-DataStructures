#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0 && a[j]>temp;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
}
int main()
{
	int a[]={5,6,4,3,4,6,2,6};
	int n=sizeof(a)/sizeof(a[0]);
	InsertionSort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
}