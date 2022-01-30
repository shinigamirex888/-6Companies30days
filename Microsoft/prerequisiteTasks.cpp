#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &defvis, int node){
vis[node]=1;
defvis[node]=1;
for(auto it: adj[node]){
if(! vis[it]){
if(dfs(adj,vis,defvis,it)){
return true;
}
}
else{
if(defvis[it]){
return true;
}
}
}
defvis[node]=0;
return false;
}

bool isPossible(int N,vector<pair<int,int>> &p){
vector<int> vis(N,0);
vector<int> defvis(N,0);
vector<int> adj[N];
int i;
for(i=0;i<p.size();i++){
adj[p[i].second].push_back(p[i].first);
}
for(i=0;i<N;i++){
if(!vis[i]){
if(dfs(adj,vis,defvis,i)){
return false;
}
}
}
return true;
}


};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends