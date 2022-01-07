#include <bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];

        cout << countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends



int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
     int end=0,start=0;
    long long ans=0, temp=1;
    while(end<n)
    {
         temp*=a[end];
        while(start<end && temp>k)
        {
            temp/=a[start];
            start++;
        }
        if(temp<k)
        {
            ans+=end-start+1;
        }
       
        end++;
    }
    
    return ans;
    
}