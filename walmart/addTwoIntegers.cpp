#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        
     long long p=dividend,q=divisor,m=1,a,ans=0;
     int f=0;
     
     if(p<0^q<0) f=1;        if(p<0) p=-p;          if(q<0) q=-q;
     if(p==q) if(f==1) return -1; else return 1;
     a=q;
     
    while(a<=p) {a=a<<1;m=m<<1;}  a=a>>1;m=m>>1;

    while(p>=q && p>0)
    {
      if(p>=a)
        { 
            p=p-a;
            ans=ans+m;   
        }      
        a=a>>1;m=m>>1;
    }

    if(f==1) {return -ans;} 
    
    else{if(ans==1+long(INT_MAX)) return INT_MAX; else return ans;}
    }
};