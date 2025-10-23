#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <queue>
#include <stack>
using namespace std;
class Graph{
    public:
 unordered_map<int ,list<int>> adjlist;
 
 void insert(int u,int v,bool type){
     
     if(type){
         adjlist[v].push_back(u);
     }
      adjlist[u].push_back(v);
 }
 
 void print(){
     for(auto neg :adjlist){
         cout<<neg.first<<"-{ ";
         for(auto i: neg.second){
             cout<<i<<" ,";
         }
         cout<<"}"<<endl;
     }
 }
 void topoDfs(int src, map<int ,bool>& vis, stack<int>& st){
     vis[src]=true;
     
     for(auto i: adjlist[src]){
         if(!vis[i]){
             topoDfs(i,vis,st);
         }
     }
     st.push(src);
 } 
 void topoBfs(int  n){
     map<int ,int> inorder;
     queue<int> q;
     
     for(auto i:adjlist){
         for(auto neg:i.second){
             inorder[neg]++;
         }
     }     
     for(int i=0;i<=n;i++){
         if(inorder[i]==0){
             q.push(i);
         }
     }
     while(!q.empty()){
         
         int front=q.front();
         cout<<front<<", ";
         q.pop();
         for(auto cli: adjlist[front]){
             inorder[cli]--;
         
             if(inorder[cli]==0)
             q.push(cli);        
         }  
     }
 }
 //-------------------------------------------shortest path----------------------------
 void sortPath(int src ,int des){
     queue<int> q;
     unordered_map <int,int> parent;
          unordered_map <int,bool> vis;      
          vis[src]=true;
          q.push(src);
          parent[src]=-1;
          while(!q.empty()){
              int front=q.front();
              q.pop();
              
              for(auto neg:adjlist[front]){
                  if(!vis[neg]){
                  vis[neg]=true;
                  q.push(neg);
                  parent[neg]=front;
                  }
              }         
          }          
          vector<int> ans;
          while(des!=-1){
              ans.push_back(des);
              des=parent[des];
          }
          
          for(auto i:ans){
              cout<<i<<",";
          }  
 } 
};
int main(){
    Graph g;
g.insert(0, 5, 0);
g.insert(5, 4, 1);
g.insert(4, 3, 1);
g.insert(0, 6, 1);
g.insert(6, 3, 1);
g.insert(0, 1, 1);
g.insert(1, 2, 1);
g.insert(2, 3, 1);    
    map<int ,bool> vis;
     stack<int> st;
     
    //  g.topoBfs(5);
     g.sortPath(1,5);
     
    //  g.topoDfs(1,vis ,st);
    //  while(!st.empty()){
    //      cout<<st.top();
    //      st.pop();
    //  }
 //   g.print();    
}
