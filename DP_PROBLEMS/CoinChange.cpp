#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 1000;
int dp[N][N];
int ar[N];
int n , m;

int fun(int i , int x){
    if(i == m)
        return x == 0;

    auto &res = dp[i][x];
    if(res != -1) return res;

    if(ar[i] <= x)
        return res = fun(i , x - ar[i]) + fun(i + 1 , x);
    return res = fun(i + 1 , x);
}



int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp , - 1, sizeof(dp));
    cin >> n >> m;
    for(int i =0 ;i < m;i++)
        cin >> ar[i];
    cout << fun(0 , n) << "\n";

    return 0;
}
