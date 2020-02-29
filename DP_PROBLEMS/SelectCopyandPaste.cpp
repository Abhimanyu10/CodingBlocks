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

const int N = 51;
int ar[N];
int dp[N][N*40][N*40];
int n;

int fun(int i , int placed , int buf){
    if(i == n)
        return 0;
    auto &res = dp[i][placed][buf];
    // if(res!=-1)
    //     return res;
    int ans = 0;
    if(i + 3 < n)
        ans = max(ans, 2*placed + fun(i + 3, placed * 3, 2 * placed));
    // if(i + 1 < n){
        ans = max(ans, 1 + fun(i + 1, placed + 1, buf));
        ans = max(ans, buf + fun(i + 1, placed + buf, buf));
    // }
    return res = ans;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    // cin >> n;
    for(int i = 10;i>=1;i--) {
        n = i;
        cout << fun(0, 0, 0) << "\n";
    }
    return 0;

}