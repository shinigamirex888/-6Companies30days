#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &v, int mid, int days)
    {
        int d = 1;
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            if (sum > mid)
            {
                d++;
                sum = v[i];
            }
        }
        return d <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int maxi = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int lo = maxi;
        int hi = sum;
        if (n == days)
            return maxi;
        int ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (possible(weights, mid, days))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};