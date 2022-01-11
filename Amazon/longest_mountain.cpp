#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
int ans=0;
//from 1 to n-2
for(int i=1;i<=n-2;){
if(arr[i]>arr[i+1] and arr[i]>arr[i-1]){
int cnt=1;
int j=i;
while(j>0 and arr[j] > arr[j-1]){
j--;
cnt++;
}
while(i<n-1 and arr[i] > arr[i+1]){
i++;
cnt++;
}
ans=max(cnt,ans);
}
else{
i++;
}
}
return ans;
    }
};