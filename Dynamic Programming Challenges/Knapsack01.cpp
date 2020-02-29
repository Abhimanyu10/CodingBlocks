#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1000+11;
int n , m;
int dp[N][N];
int wt[N] , val[N];
int fun(int i , int w){
    if(i == n)
        return 0;
    
    auto &res = dp[i][w];
    if(res!=-1) return res;
    if(wt[i] <= w)
        return max(val[i] + fun(i + 1 , w - wt[i]) , fun(i + 1 , w));
    
    return res = fun(i + 1 , w);
}


int main(){
	memset(dp , -1 , sizeof(dp));
    scanf("%d%d" , &n , &m);
    for(int i =0 ;i < n;i++) scanf("%d" , &wt[i]);
    for(int i=0 ;i < n;i ++) scanf("%d" , &val[i]);
	printf("%d\n" , fun(0 , m));
    return 0;
}
