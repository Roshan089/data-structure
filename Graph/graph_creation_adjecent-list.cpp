#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>


using namespace std;

template <typename T>

class Graph{
    
public:

unordered_map<T ,list<T>> edgeList;

void edge(T u,T v,bool direction){
    //direction---0-> unidirection
    //direction -- 1 --> directed;
    
    if (direction){
        edgeList[u].push_back(v);
        
    }
    else{
        edgeList[u].push_back(v);

        edgeList[v].push_back(u);

        
    }
    print();
 
}
    void print(){
        for(auto i :edgeList){
            cout<<i.first <<"-{";
            for(auto neg :i.second){
                cout<<neg<<" ";
            }
            cout<<"}";
              cout<<endl;
        }
        cout<<endl;
    }
    
    
    void bfs(T scr){
        unordered_map<T,bool> vis;
        
        queue <T> q; 
        q.push(scr);
        vis[scr]=true;
        
        while(!q.empty()){
            
            T frontNode =q.front();
            q.pop();
            cout<<frontNode<< " ";
            
            for(auto neg :edgeList[frontNode] ){
                T negData=neg;
                
                if(!vis[negData]){
                    q.push(negData);
                    vis[negData]=true;
                }
                
                
                
            }
        }
    
}

};







int main() {
    
    Graph<char> g;
    
    // g.edge(2,3,1);
    //     g.edge(3,4,1);

    // g.edge(4,5,0);


    // g.edge(5,8,1);
    
    
    
        g.edge('a','b',1);
        g.edge('b','f',1);

    g.edge('f','q',0);


    g.edge('q','l',1);
    g.bfs('a');
    // g.print();

return 0;    
}
