#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int u,v,w;
    Edge(int x,int y,int z){
        u=x;
        v=y;
        w=z;
    }
};
int parent[1000];
int size[1000];
int n,m;  // n la so dinh , m la so canh
void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        size[i]=1;
    }

}
int find(int v){
    if(v==parent[v])
    return v;
    return parent[v]=find(parent[v]);
}
bool Union(int u,int v){
    int root1=find(u);
    int root2=find(v);
    if(root1==root2) 
    return false;
    if(size[root1]<size[root2]){
        parent[root1]=root2;
        size[root2]+=size[root1];
        return true;
    }
    else{
        parent[root2]=root1;
        size[root1]+=size[root2];
        return true;
    }
}
vector<Edge> canh;
void input(){
        cout<<" nhap so dinh " ; cin>>n;
        cout<<"nhap so canh " ; cin>>m;
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            Edge e=Edge(x,y,w);
            canh.push_back(e);
        }
}
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
void kruskal(){
    // tao cay khung cuc tieu rong 
    vector<Edge> MST ;
    int d=0;
    sort(canh.begin(),canh.end(),cmp); // sap xep cay khung theo trong so tang dan 
    for(int i=0;i<m;i++){
        if(MST.size()==n-1) return ;
        Edge e=canh[i];
        if(Union(e.u,e.v)){    // kiem tra 2 dinh cua 1 canh co cung tap hop hay k
            MST.push_back(e);
            d+=e.w;
        }
    }
}

