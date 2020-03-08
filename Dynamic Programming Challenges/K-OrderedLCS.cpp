//@author :: Abhimanyu Chauhan

#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>


#define oo			INT_MAX/2
#define f			first
#define sz(a)  ((int)(a).size())
#define s			second
#define present(c,x) ((c).find(x)!=(c).end())
#define all(v)		v.begin(),v.end()
#define pii 			pair<int,int>
#define pil 		pair<int,long long>
#define pll 		pair<long long , long long>
#define vpii 		vector<pii>
#define vpil 		vector<pil>
#define vpll 		vector<pll>
#define eb			emplace_back
#define mem(x) 			memset(x , 0 , sizeof(x))
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>
#define vll			vector<ll>
#define deb(x)		cout << #x << " " << x << endl

using namespace std;
using ll  = long long;
using lld = long double;
using l64 = int64_t;

const ll MOD =1000000007;

const int N = 2e3 + 10;
int ar[N], br[N] , dp[N][N][7];
int n, m;

int _max(int a=0, int b=0, int c=0 , int d=0){
    return max(max(a, b), max(c, d));
}

int fun(int i , int j, int k){
  
    if(i == n)
        return 0;
    
    if(j == m)
        return 0;
    
    auto &res = dp[i][j][k];
    if(res != -1) return res;
    int ans = 0;
    if(ar[i] == br[j])
        ans = max(ans, fun(i + 1, j + 1, k) + 1);
    if(k > 0) //i have the option to change this or leave it as it is
        ans = max(ans, 1 + fun(i + 1, j + 1, k - 1));
    ans = _max(ans, fun(i, j + 1, k), fun(i + 1, j, k));
    return res = ans;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int k;
    cin >> n >> m >> k;
    fo(i, n) cin >> ar[i];
    fo(i, m) cin >> br[i];
    cout << fun(0, 0, k);
    return 0;

}