#include<iostream>
using namespace std;

int main()
{
	int array[10];
	for(int i=0;i<10;i++)
		array[i]=i+1;
	int p,m=0;
	cin>>p;
	int sort[10];
	for(int i=p+1;i<10;i++)
		sort[m++]=array[i];
	for(int i=0;i<=p;i++)
		sort[m++]=array[i];
	for(int i=0;i<10;i++)
		cout<<sort[i]<<" ";
	return 0;
} 
