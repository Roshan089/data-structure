#include <iostream>
#include <unordered_map>
#include <list>
#include <map>

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
 
};
int main(){
    Graph g;
    g.insert(1,3,0);
        g.insert(3,5,0);
    g.insert(3,2,1);

    g.insert(8,9,1);
    
    
     map<int ,bool> vis;
     stack<int> st;
     
     g.topoDfs(1,vis ,st);
     while(!st.empty()){
         cout<<st.top();
         st.pop();
     }
 //   g.print();

    
    
}
