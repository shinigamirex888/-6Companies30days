#include <bits/stdc++.h>
using namespace std;

class Solution
{
   public:
   //Function to find the largest number after k swaps.
   void klp(string str,int k,string &maxm,int ctr){
       if(k==0){
           return ;
       }
       int n=str.size();
       char maxi=str[ctr];
       for(int i=ctr+1;i<n;i++){
           if(str[i]>maxi){
               maxi=str[i];
           }
       }
       if(maxi!=str[ctr]){
           k--;
       }
       for (int j=n-1;j>=ctr;j--){
           if(str[j]==maxi){
               swap(str[ctr],str[j]);
               if(str.compare(maxm)>0){
                   maxm=str;
               }
               klp(str,k,maxm,ctr+1);
               swap(str[ctr],str[j]);
           }
       }
   }
   string findMaximumNum(string str, int k)
   {
      string maxm="";
      klp(str,k,maxm,0);
      return maxm;
   }
};