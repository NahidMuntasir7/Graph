#include<bits/stdc++.h>
using namespace std;


const int N=1e7+10 ;
vector<int> tree[N];


void dfs(int vertex,int par,vector<int>& ans){

    int subords=0;

    for(int child : tree[vertex]){

            if(child == par) continue;

            dfs(child,vertex,ans);
            subords+=(1+ans[child]);
        }

       ans[vertex]=subords;
}

int main(){
        int n;
        cin>>n;

        vector<int> ans(n+1);

        for(int i=2;i<=n;i++){
            int x;
            cin >> x;
            tree[x].push_back(i);
            tree[i].push_back(x);
        }

        dfs(1,0,ans);

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
   }
















