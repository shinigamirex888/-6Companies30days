#include<bits/stdc++.h>
using namespace std;
bool loc(vector<int> v[],int &row,int &col)
{
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(v[row][col]==0)
            return true;
        }
    }
    return false;
}
bool inrow(vector<int> v[],int row,int num)
{
    for(int i=0;i<9;i++)
    {
        if(v[row][i]==num)
        return true;
    }
    return false;
}
bool incol(vector<int> v[],int col,int num)
{
    for(int i=0;i<9;i++)
    {
        if(v[i][col]==num)
        return true;
    }
    return false;
}
bool inbox(vector<int> v[],int row,int col,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(v[i+row][j+col]==num)
            return true;
        }
    }
    return false;
}
bool issafe(vector<int> v[],int row,int col,int i)
{
    return (!inrow(v,row,i)&&!incol(v,col,i)&&!inbox(v,row-row%3,col-col%3,i)&&v[row][col]==0);
}
bool solvesudoku(vector<int> v[])
{
    int row,col;
    if(!loc(v,row,col))
        return true;
    
    for(int i=1;i<=9;i++)
    {
        if(issafe(v,row,col,i))
        {
            v[row][col]=i;
            if(solvesudoku(v))
                return true;
            v[row][col]=0;
        }
    }
    return false;
}
int main()
{
    int t;
	cin>>t;
	while(t--)
	{
	    vector<int> v[9];
	    int n=9;
	    for(int i=0;i<n;i++)
	    {
	        vector<int> tmp(9);
	        v[i]=tmp;
	        for(int j=0;j<n;j++)
	            cin>>v[i][j];
	    }
	    if(solvesudoku(v))
    	    cout<<1<<endl;
    	else
    	    cout<<0<<endl;
    }
     return 0;
}
