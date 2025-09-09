#include <iostream>
using namespace std;
#include<vector>


int kn(int coins[],int profit[],int in, int w,int p, int &maxp){
    if(in>2){
        return max(p,maxp);
    }
    
    if(w>=coins[in]){
        
        int inc=kn(coins,profit,in+1,w-coins[in],p+profit[in],maxp);
                int exc=0+kn(coins,profit,in+1,w,p,maxp);
                
                  maxp= max(inc,exc);



                  return maxp;

    }
    else{
        return  kn(coins, profit, in + 1, w, p, maxp);
    }
    return 0;
}


int knMemo(int coins[],int profit[],int in, int w,int p, int &maxp,vector<vector<int>> &dp){
    if(in>2){
        return dp[w][in]= max(p,maxp);
    }
    
    if(dp[w][in]!=-1) return dp[w][in];
    
    if(w>=coins[in]){
        
        int inc=knMemo(coins,profit,in+1,w-coins[in],p+profit[in],maxp,dp);
                int exc=0+knMemo(coins,profit,in+1,w,p,maxp,dp);
                
                  maxp= max(inc,exc);
                dp[w][in]=maxp;
                  return dp[w][in];

    }
    else{
        return  knMemo(coins, profit, in + 1, w, p, maxp,dp);
    }
    return 0;
}


int main(){
    int coins[3]={10,20,30};
    int in=0;
    int profit[3]={60,100,120};
    int w=50;
    
vector<vector<int>> dp(w + 1, vector<int>(3+1,-1));
    
    int p=0;
    int maxp=0;
    
    int ans= knMemo(coins,profit,in,w,p,maxp,dp);
    
    
    cout<<"max profit is:"<<ans;
    
    
    int knMemo(int coins[], int profit[], int in, int w, int n, vector<vector<int>> &dp) {
    if (in >= n) return 0;

    if (dp[w][in] != -1) return dp[w][in];

    int res;
    if (w >= coins[in]) {
        int inc = profit[in]+knMemo(coins, profit, in + 1, w - coins[in] , n, dp);
        int exc = knMemo(coins, profit, in + 1, w,  n, dp);
        res = max(inc, exc);
    } else {
        res = knMemo(coins, profit, in + 1, w,  n, dp);
    }

    dp[w][in] = res;
    return res;
}


  
  
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));

    // now call your memo function
    int p = 0;
    int maxp = 0;
    return knMemo(wt.data(), val.data(), 0, W, n, dp);
}
    
    
    
}
