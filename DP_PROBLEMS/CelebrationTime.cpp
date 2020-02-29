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
#define int ll
const ll MOD = 1e6 + 3;

const int N = 120;
int dp[N][N][2];
int n;

int fun(int i , int k , int prev){
    if(i == n)
        return k == 0;
    if(k < 0)
        return 0;
    auto &res = dp[i][k][prev];
    if(res != -1) return res;
    if(prev == 0)
        return res = (fun(i + 1, k, 0) % MOD + fun(i + 1, k, 1) % MOD) % MOD;
    else
        return res = (fun(i + 1, k - 1, 1) % MOD + fun(i + 1, k, 0) % MOD) % MOD;
}


signed main(){
    memset(dp, -1, sizeof(dp));
#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        memset(dp, -1, sizeof(dp));
        int k;
        cin >> n >> k;
        cout << fun(0, k , 0) % MOD  << "\n";
    }

    return 0;

}