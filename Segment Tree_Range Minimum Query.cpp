//here index is 0 based
#include <bits/stdc++.h>
#define MAX_VALUE 100000
using namespace std;
int input[10005]={0};
int SegTree[30005]={0};
int lazy[30005]={0};
void constructTree(int low,int high,int pos)
{
	if(low==high)
	{
		SegTree[pos]=input[low];
		return;
	}
	int mid=(low+high)/2;
	constructTree(low,mid,2*pos+1);
	constructTree(mid+1,high,2*pos+2);
	SegTree[pos]=min(SegTree[2*pos+1],SegTree[2*pos+2]);
}
int rangeMinQuery(int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low && qhigh>=high)  //total overlap
		return SegTree[pos];
	if(qlow>high || qhigh<low)   //no overlap
		return MAX_VALUE;
	int mid=(low+high)/2;      //partial overlap
	return min(rangeMinQuery(qlow,qhigh,low,mid,2*pos+1),rangeMinQuery(qlow,qhigh,mid+1,high,2*pos+2));
}
int rangeMinQueryLazy(int qlow,int qhigh,int low,int high,int pos)
{
	if(low>high)return MAX_VALUE;
	if(lazy[pos]!=0)
	{
		SegTree[pos]+=lazy[pos];
		if(low!=high)//not a leaf node
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}
	if(qlow<=low && qhigh>=high)  //total overlap
		return SegTree[pos];
	if(qlow>high || qhigh<low)   //no overlap
		return MAX_VALUE;
	int mid=(low+high)/2;      //partial overlap
	return min(rangeMinQueryLazy(qlow,qhigh,low,mid,2*pos+1),rangeMinQueryLazy(qlow,qhigh,mid+1,high,2*pos+2));
}
