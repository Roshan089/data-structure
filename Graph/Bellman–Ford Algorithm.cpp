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
  
  
  void bellmenford(int n,char src , vector<int>& dist){

      dist[src-'a']=0;
      
      cout<<dist[0]<<endl;
      for(int k=1;k<n;k++){
          
          for(auto i: adj){
              for(auto j: i.second){
                  int u=i.first;
                  int v=j.first;
                  int wtv=j.second;
                  if(dist[u-'a']!=INT_MAX&&dist[u-'a']+wtv<dist[v-'a'])
                  dist[v-'a']=dist[u-'a']+wtv;
              }
              
          }
        
      }
        bool anyUpdate=false;
              for(auto i: adj){
              for(auto j: i.second){
                  int u=i.first;
                  int v=j.first;
                  int wtv=j.second;
                  if(dist[u-'a']!=INT_MAX && dist[u-'a'] + wtv<dist[v-'a']){
                  anyUpdate=true;
                  break;
                 
                  }
              }
               if (anyUpdate) break;
              
          }
          if(anyUpdate){
              cout<<"cycle present";
          }
          else
          cout<<"no cycle";
  }  
       
};


int main(){
    Graph g;
     vector<int> dist(6,INT_MAX);
g.insert('a', 'b', -1, 1);
g.insert('b', 'e', 2, 1);
g.insert('e', 'd', -3, 1);
g.insert('d', 'c', 5, 1);
g.insert('a', 'c', 4, 1);
g.insert('b', 'c', 3, 1);
g.insert('b', 'd', 2, 1);
g.insert('d', 'b', 1, 1);

    // g.print();
    g.bellmenford(6,'a',dist);
    for(auto i: dist){
        cout<<i<< " ";
    }
}
