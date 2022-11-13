#include<bits/stdc++.h>
using namespace std;


const int N=1e7+10 ;

vector<int> g[N];
bool vis[N];
vector<int> point;

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

    int cc=0;

    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(i);
        point.push_back(i);
        cc++;
    }

    cout<<cc-1<<endl;

    if(cc>1){

     int first=point[0],second;

     for(int i=1;i<cc;i++){

        second=point[i];
        cout<<first<<" "<<second<<endl;
        first=second;

     }

    }
}








