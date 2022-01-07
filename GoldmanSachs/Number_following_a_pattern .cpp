#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int> st;
        string ans ="";
        int num=1;
        for(int i=0;i<S.size();i++){
            char c=S[i];
            if(c=='D'){
                st.push(num++);
                
            }
            else {
                st.push(num++);
                while(!st.empty()){
                    char c1= '0'+st.top();
                    ans.push_back(c1);
                    st.pop();
                    
                }
            }
        }
        st.push(num++);
        while(!st.empty()){
            
            char c1= '0'+st.top();
            ans.push_back(c1);
            st.pop();
                    
                }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends