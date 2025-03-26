#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
// duyet sau phai pop ra moi danh dau da tham 
// duyet rong push vao phai danh dau da tham luon de khong co dinh trung    
class Graph{
    private : 
    int V; // so dinh cua do thi 
    vector<vector<pair<int,int>>>adj;
    public : 
    Graph(int v){
        V=v;
        adj.resize(v);   // khoi tao vector rong 
    };
    // them canh vao do thi 
    void addEdge(int u,int v,int weight){
        adj[u].push_back({v,weight});   // them v,trong so vao danh sach cua u 
        adj[v].push_back({u,weight});   // them u , trong so vao danh sach cua v 
    }
    void printGraph(){
        for(int i=0;i<V;i++){
            cout<<"DINH " << i << "ke :" ;
            for(auto x : adj[i] ){
                  cout << x.first <<" trong so " << x.second <<" ; ";
            }
            cout<<endl;
        }
    }
    void BFS(int start){
        vector<bool> visited(V,false);  // khoi tao cac dinh ban dau la false , chua tham 
        queue<int> q;
        q.push(start);    // push phan tu dau tien vao queue
        visited[start]=true ;  // danh dau dinh thu start la da tham 
        cout<<"BFS: " ;
        while(!q.empty()){
            int u =q.front();
            q.pop();
            cout<< u << " ";
            //tim cac dinh ke voi u 
            for(auto x : adj[u]){
                if(visited[x.first]==false){
                    visited[x.first]=true;      // danh dau da tham 
                    q.push(x.first); // push cac dinh ke vao queue
                }
            }

        }
        cout << endl;
    }
    void DFS(int start){
        stack<int> s;
        vector<bool> visited(V,false);
        s.push(start);
        cout<<"DFS: ";
        while(!s.empty()){
            int u=s.top();
            s.pop();
            if(!visited[u]){
                cout<<u<<" ";
                visited[u]=true;
            }
            // duyet cac dinh ke cua dinh bat dau
            for(auto x : adj[u]){
                if(visited[x.first]==false){
                    s.push(x.first);
                }
            }
        }
        cout<<endl;

    }


};
int main(){
    Graph G(7);
    G.addEdge(1,4,2);
    G.addEdge(1,5,6);
    G.addEdge(1,6,2);
    G.addEdge(2,4,1);
    G.addEdge(2,5,1);
    G.addEdge(2,6,1);
    G.addEdge(3,4,1);
    G.addEdge(3,5,1);
    G.addEdge(3,6,1);
    G.printGraph();
    G.BFS(1);
    G.DFS(1);
}