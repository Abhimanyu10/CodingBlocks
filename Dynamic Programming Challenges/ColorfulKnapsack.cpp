//@author :: Abhimanyu Chauhan

#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>

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
#define int ll
const ll oo = 1e10;
const ll MOD =1000000007;
const int N = 100+2;
const int maxw = 10000 + 2;
vll ar[N];
int dp[N][maxw];
int w[N];
int n, m, W;
int fun(int i , int WW){
    if(i == m){
        return 0;
    }
    auto &res = dp[i][WW];
    if(res!=-1) return res;
    int ans = -oo;
    for(int j : ar[i]){
        if(j<=WW)
            ans = max(ans, j + fun(i + 1, WW - j));
    }
    return res = ans;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> W;
    fo(i , n)
        cin >> w[i];
    

    fo(i , n){
        int x;
        cin >> x;
        ar[x-1].pb(w[i]);
    }
    
    cout << (fun(0 , W)<0?-1:W-fun(0,W)) << "\n"; 

    return 0;
}