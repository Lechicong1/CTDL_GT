
#include<bits/stdc++.h>
using namespace std;
struct canh{
    int u,v,w;

};
int n,m;
vector<pair<int,int>> adj[100];
bool used[100];
int parent[100],d[100];
void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w; 
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});

    }
        memset(used,false,sizeof(used));
}
void prim(int u){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    vector<canh> MST;
    int res=0;
    Q.push({0,u});
    while(!Q.empty()){
        // lay dinh dau queue( dinh co trong so nho nhat ) ra va them vao cay MST
        pair<int,int> top=Q.top();
        Q.pop();
        int dinh=top.second;
        int trongso=top.first;
        if(used[dinh]){
            continue;
        }
        res+=trongso;
        used[dinh]=true;
        if(u!=dinh){
            MST.push_back({dinh,parent[dinh],trongso});
        }
        // duyet tat ca cac dinh ke va them vào queue 
        for(auto x:adj[dinh]){
            int y=x.first ;
            int w=x.second;
            if(!used[y]){
                Q.push({w,y});
                d[y]=w;
                parent[y]=dinh;
            }
        }
    }
}
