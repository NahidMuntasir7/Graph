#include<bits/stdc++.h>
using namespace std;

const int n=1e7+10 ;


int N,M;
char graph[1001][1001];
bool vis [1001][1001];

bool isvalid(int x,int y){

    if(x<1 || x>N || y<1 || y>M) return false;
    if(vis[x][y]==true || graph[x][y]=='#') return false;

    return true;
}


void dfs(int x,int y){

    vis[x][y]=true;

    if(isvalid(x+1,y)) dfs(x+1,y);
    if(isvalid(x-1,y)) dfs(x-1,y);
    if(isvalid(x,y+1)) dfs(x,y+1);
    if(isvalid(x,y-1)) dfs(x,y-1);

}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin>>N>>M;

    for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){
         cin>>graph[i][j]  ;
      }
    }

    int cnt=0;

     for(int i=1;i<=N;i++){
      for(int j=1;j<=M;j++){

        if(graph[i][j]=='.' && vis[i][j]==false){
        dfs(i,j);
        cnt++;

        }
      }
    }

    cout<<cnt<<endl;
}









