#include <iostream>

#define SIZE 100
#define INFINITY 10000

using namespace std;

int v[10]={0};//1..n
int p[10]={0};//1..n
int d[10]={0};//1..n
//0..n-1
//int linjie[6][6]={INFINITY,2,5,1,INFINITY,INFINITY, 2,INFINITY,3,2,INFINITY,INFINITY, 5,3,INFINITY,3,1,5, 1,2,3,INFINITY,1,INFINITY, INFINITY,INFINITY,1,1,INFINITY,2, INFINITY,INFINITY,5,INFINITY,2,INFINITY};
int linjie[6][6]={INFINITY,1,INFINITY,1,INFINITY,INFINITY,1,INFINITY,2,1,INFINITY,INFINITY,INFINITY,2,INFINITY,1,1,1,1,1,1,INFINITY,2,15,INFINITY,INFINITY,1,2,INFINITY,1, INFINITY,INFINITY,1,15,1,INFINITY};

void dijsktra(int n)
{
	int s[10]={0};
	int pos=0,min, count=0;

	v[1]=1;
	s[count++]=1;
	for(int i=0;i<n;i++)
	{
		if(linjie[0][i]<INFINITY)
		{
			d[i+1]=linjie[0][i];
		}
		else
		{
			d[i+1]=INFINITY;
		}
	}

	for(i=1;i<n+1;i++)
		cout<<d[i]<<' ';
	cout<<endl;

	d[1]=0;
	int dd=1;
	for(int j=0;j<n;j++)
	{
		while(v[dd]!=0) dd++;
	//	cout<<dd<<"dasd ";
		min=d[dd];pos=dd;
		for(i=1;i<n;i++)
		{
			//not in
			if(min>d[i+1]&&v[i+1]==0)
			{
				pos=i+1;
				min=d[i];
			}
		}
		v[pos]=1;
	//	cout<<pos<<' '<<min<<endl;
		if(count<6)
			s[count++]=pos;
	//	cout<<pos<<endl;
		for(i=0;i<n;i++)
		{
			
			if(linjie[pos-1][i]<INFINITY&&i!=pos-1&&v[i+1]==0)
			{
			//	cout<<"linjie[pos-1]["<<i<<"]:"<<linjie[pos-1][i]<<endl;
	//			cout<<"i="<<i+1<<","<<linjie[i][pos-1]<<' ';
				if(d[i+1]==INFINITY)
					d[i+1]=d[pos]+linjie[i][pos-1];
				else
				{
					if(d[i+1]>d[pos]+linjie[i][pos-1])
					{
						d[i+1]=d[pos]+linjie[i][pos-1];
	//					cout<<"d[pos]"<<d[pos]<<endl;
					}
				}

	//			for(int k=1;k<n+1;k++)
	//				cout<<d[k]<<' ';
	//			cout<<endl;
			}
		}
	}

	for(i=0;i<count;i++)
		cout<<s[i]<<' ';
	cout<<endl;
}



int main()
{ 
	
//	int n;

//	cout<<"Please input n:";
//	cin>>n;
	dijsktra(6);


	return 0;
}