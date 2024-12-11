
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool check(int r,int c,int inext,int jnext,vector<vector<bool>> &visited,int mat[][4]){
    if((inext<r)&&(jnext<c)&& (mat[inext][jnext]==1) &&(visited[inext][jnext]==false))
    return true;
    else
    return false;
}

void ansrec(int mat[][4] ,int i,int j,int r,int c,string output,vector<vector<bool>> &visited){
   if(i==r-1&&j==c-1){
       cout<<output<<endl;
       return;
   }
   //up
   int inext=i-1;
   int jnext=j;
   
   if(check(r,c,inext,jnext,visited,mat)){
       visited[inext][jnext]=true;
       output.push_back('U');
       ansrec(mat,inext,jnext,r,c,output,visited);
       output.pop_back();
        visited[inext][jnext]=false;
   }
   //down
   inext=i+1;
    jnext=j;
   
     if(check(r,c,inext,jnext,visited,mat)){
       visited[inext][jnext]=true;
        output.push_back('D');
       ansrec(mat,inext,jnext,r,c,output,visited);
       output.pop_back();
        visited[inext][jnext]=false;
   }
   
   inext=i;
    jnext=j+1;
   
   
     if(check(r,c,inext,jnext,visited,mat)){
       visited[inext][jnext]=true;
       output.push_back('R');
       ansrec(mat,inext,jnext,r,c,output,visited);
       output.pop_back();
        visited[inext][jnext]=false;
   }
   
   inext=i;
    jnext=j-1;
   
     if(check(r,c,inext,jnext,visited,mat)){
       visited[inext][jnext]=true;
        output.push_back('L');
       ansrec(mat,inext,jnext,r,c,output,visited);
       output.pop_back();
        visited[inext][jnext]=false;
   }
   
    
}


int main() {
    
 int mat[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int row=4;
    int col=4;
int ans=0;
string output;
vector<vector<bool>> visited(row,vector<bool> (col,false));

ansrec(mat,0,0,row,col,output,visited);

 
    return 0;
}