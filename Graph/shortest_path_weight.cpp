#include <unordered_map>
#include <list>
#include <stack>

#include <utility>   // for pair<int,int>
#include <iostream>  // for cout, cin (if used)
using namespace std;


class Graph{
    public:
    unordered_map <int, list<pair<int,int>>> adj;
    
    void insert(int u,int v,int wt,bool dir){
        
        adj[u].push_back({v,wt});
        if(dir){
        adj[v].push_back({u,wt});

        }
    }
        
        void print(int src){
        for(auto i: adj){
            cout<<i.first<<"-{";
            for(auto j: i.second){
                int neg=j.first;
                int wgt=j.second;
                 cout<<neg<<", "<<wgt;
            }
            cout<<"}"<<endl;
          }    
        }
        
        void topo(int src, stack<int>& st,unordered_map<int ,bool> vis){
            vis[src]=true;
            
            for(auto neg :adj[src]){
                if(!vis[neg.first]){
                    topo(neg.first,st,vis);
                }
            }
            
            st.push(src);
            
            
            
        }
        
        void shortestpath( )
        
    
};
int main(){
    Graph g;
    g.insert(2,3,11,0);
        g.insert(3,5,31,0);

    g.insert(5,7,61,0);
    // g.print(2);
    stack<int> st;
    unordered_map<int ,bool> vis;
    g.topo(2,st,vis);
    
    while(!st.empty()){
        cout<<st.top()<<" ,";
        st.pop();
    }
    
    
    
    
    

}
