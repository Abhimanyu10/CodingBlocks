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
#define mem(x) 			memset(x , -1 , sizeof(x))
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
const ll MOD =1000000007;
int n;
const int N = 1e5 + 10;
int dp[N][4][4];

int fun(int i , int p1 , int p2){
    if(i == n) return 1;
    auto &res = dp[i][p1][p2];
    if(res != -1) return res;
    int ans = 0;
    (ans += fun(i + 1, 1, p1))%=MOD;
    if(p1!=2) (ans += fun(i + 1 , 2 , p1)) %= MOD;
    if(p1!=3 && p2!=3)
        (ans += fun(i + 1, 3, p1))%=MOD;
    return res = ans%MOD;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif
    mem(dp);
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    cout << fun(0,0,0) << "\n";

    return 0;

}