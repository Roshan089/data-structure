#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <climits> // 👈 Add this line




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
        
        void topo(int src, stack<int>& st,unordered_map<int ,bool>& vis){
            vis[src]=true;

            for(auto neg :adj[src]){
                if(!vis[neg.first]){
                    topo(neg.first,st,vis);
                }
            }
            
            st.push(src);
            
            
            
        }
        
        void shortestpath(stack<int> st,int n ){
            vector<int> ans(n,INT_MAX);
        int src = st.top();
                    ans[src]=0;

        st.pop();
            for(auto neg: adj[src]){
              int wt=neg.second;
              int negNode=neg.first;
                   if(ans[src]+wt<ans[negNode])
                   ans[negNode]=ans[src]+wt;
                
            }
        while(!st.empty()){
     
        src=st.top();
        st.pop();
        
          for(auto neg: adj[src]){
              int wt=neg.second;
              int negNode=neg.first;
                   if(ans[src]+wt<ans[negNode])
                   ans[negNode]=ans[src]+wt;
                
            }
        
          }
          for(auto i:ans){
            cout<<i<<",";
          }
        
    }
};
int main(){
    Graph g;
    g.insert(0,1,1,0);
        g.insert(0,2,3,0);
  g.insert(1,3,6,0);
    g.insert(2,1,11,0);
    // g.print(2);
    stack<int> st;
    unordered_map<int ,bool> vis;
     g.topo(0,st,vis);
    
    // while(!st.empty()){
    //     cout<<st.top()<<" ,";
    //     st.pop();
    // }
    g.shortestpath(st,4);
    

    
    
    
    
    
    

}
