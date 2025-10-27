#include <iostream>
#include <unordered_map>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Graph{
    
    public:
    unordered_map<int, list<pair<int,int>>> adj;
    
    void insert(int u ,int v,int wt,bool dir){
        adj[u].push_back({wt,v}) ;
        if(dir)
        adj[v].push_back({wt,u});
    }
    
  void  print (){
        for(auto i:adj){
            cout<< "node"<<i.first << "- ";
           for(auto j:i.second){
               cout<<j.first <<" "<< j.second<<" ";
           }
           cout<<endl;
        }
    
      
  }
  
  void disktra(int src,int n){
      set<pair<int,int>> st;
vector<int> dist(n + 1, INT_MAX);
      
      st.insert({0,src});
      dist[src]=0;
      
      while(!st.empty()){
          auto topElement=st.begin();
          pair<int,int>topPair=*topElement;
          int topNode=topPair.second;
          int topdis=topPair. first;
          
         st.erase(st.begin());
          
          for(pair<int,int> it :adj[topNode]){
          int nagNode=it.second;
          int negdis=it. first;
          if (topdis + negdis < dist[nagNode]){
auto preEntry = st.find({dist[nagNode], nagNode});
              if(preEntry!=st.end()){
                  st.erase(preEntry);
              }
              dist[nagNode]=topdis+negdis;
st.insert({dist[nagNode], nagNode});

              
          }
              
          }        
      }      
     for(auto i:dist){
          cout<<i<<" ";
      }     
  } 
};

int main(){
    Graph g;  
    g.insert(1,6,14,0);
g.insert(1,3,9,0);
g.insert(1,2,7,0);
g.insert(2,3,10,0);
g.insert(2,4,15,0);
g.insert(3,4,11,0);
g.insert(6,3,2,0);
g.insert(6,5,9,0);
g.insert(5,4,6,0);    
    // g.print();
g.disktra(1,6);
}
