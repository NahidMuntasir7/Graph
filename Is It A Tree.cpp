#include<bits/stdc++.h>
using namespace std;


const int N=1e7+10 ;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){

    vis[vertex]=true;
    for(int child : g[vertex]){

        if(vis[child]) continue;

        dfs(child);
    }

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,e;
    cin>>n>>e;

    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);

    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }

    if((n-1==e) && cnt==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}












