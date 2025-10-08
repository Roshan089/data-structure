#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph{
    
public:

unordered_map<int ,list<int>> edgeList;

void edge(int u,int v,bool direction){
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

};




int main() {
    
    Graph g;
    
    g.edge(2,3,1);
        g.edge(3,4,1);

    g.edge(4,5,0);


    g.edge(5,8,1);
    // g.print();

return 0;    
}
