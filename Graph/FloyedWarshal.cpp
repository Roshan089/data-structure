#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <vector>
#include <climits>


class  Graph{
    public:
    unordered_map<char,list<pair<char,int>>> adj;
    void insert(char u,char v,int wt,bool dir){
        
        if(!dir){
            adj[v].push_back({u,wt});
        }
        adj[u].push_back({v,wt});
    }
    
    void print(){
        for(auto i: adj){
            cout<<i.first<<"- {";
            for(auto j: i.second){
                cout<<j.first<<" ,"<<j.second;
            }
            
              cout<<"}"<<endl;
              
        }
    }
  
  
 
  
  void floyesWarshal(int n){
      vector<vector<int>> dist(n, vector<int> (n,1e9));
      
      for(int i=0;i<n;i++){
          dist[i][i]=0;
          
      }
      for(auto i: adj){
          for(auto j:i.second){
              int u=i.first;
              int v=j.first;
              int wt=j.second;
        dist[u][v]=wt;        
              
          }
      }
      
      for (int help=0;help<n;help++){
          for(int scr=0;scr<n;scr++){
              for(int des=0;des<n;des++){
                  dist[scr][des]=min(dist[scr][des],dist[scr][help]+dist[help][des]);
              }
          }
          
      }
      
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              cout<< dist[i][j]<<" ";
              
          }
          cout<<endl;    
      }
      
  }
       
};


int main(){
    Graph g;
     vector<int> dist(6,INT_MAX);
     
       
     g.insert(0, 1, 3, 1);
g.insert(1, 0, 2, 1);
g.insert(0, 3, 5, 1);
g.insert(1, 3, 4, 1);
g.insert(3, 2, 2, 1);
g.insert(2, 1, 1, 1);
g.floyesWarshal(4);

// g.insert('a', 'b', -1, 1);
// g.insert('b', 'e', 2, 1);
// g.insert('e', 'd', -3, 1);
// g.insert('d', 'c', 5, 1);
// g.insert('a', 'c', 4, 1);
// g.insert('b', 'c', 3, 1);
// g.insert('b', 'd', 2, 1);
// g.insert('d', 'b', 1, 1);

    // g.print();
    // g.bellmenford(6,'a',dist);
    // for(auto i: dist){
    //     cout<<i<< " ";
    // }
}
