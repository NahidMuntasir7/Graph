#include<bits/stdc++.h>
using namespace std;


const int N=1e7+10 ;

vector<int> g[N];
bool vis[N];
int color[N];

bool dfs(int vertex ,int c){

    vis[vertex]=true;
    color[vertex]=c;

    for(int child : g[vertex]){

       if(vis[child]==false){

        bool res=dfs(child,c^1);
        if(res==false) return false;

       }
       else {

        if(color[vertex]==color[child]) return false;
       }
    }
    return true;

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

    bool flag=true;

    for(int i=1;i<=n;i++){
        if(vis[i]==false){

            flag=dfs(i,0);

            if(flag == false) break;

        }
    }

    if(!flag) cout<<"IMPOSSIBLE"<<endl;

    else{
        for(int i=1;i<=n;i++){

            cout<<color[i]+1<<" ";
        }

        cout<<endl;
    }
}










