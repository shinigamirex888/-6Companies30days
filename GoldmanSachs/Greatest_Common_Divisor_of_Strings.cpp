#include <bits/stdc++.h>
using namespace std;


class Solution {
    int gcd(int a, int b)     
{                                     
    if (b > a)                        
    {                                 
        return gcd(b, a); 
    }
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
public:
    string gcdOfStrings(string str1, string str2) {
        if (str2.size() > str1.size()) swap(str1, str2);
        int j = 0;
        for (int i = 0; i < str1.size(); i++, j++) {
            if (j == str2.size()) j = 0;
            if (str1[i] != str2[j]) return "";
        }
        if (j < str2.size()) {
            int i = 0;
            while (j < str2.size()) 
                if (str2[i++] != str2[j++]) return "";
        }
        
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};