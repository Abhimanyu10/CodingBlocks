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

const ll MOD = 1000000007;

const int N = 1e5 + 100;
int ar[N][3];
int dp[N][3];
void solve(){
    int n ;
    cin >> n;

    fo(i, n) fo(j, 3) cin >> ar[i][j];  
    fo(i, 3) dp[0][i] = ar[0][i];

    Fo(i, 1, n) fo(j, 3) {
        dp[i][j] = oo;
        fo(k, 3)
            if (j != k)
            dp[i][j] = min(dp[i-1][k], dp[i][j]);
        dp[i][j] += ar[i][j];
    }


    int ans = oo;
    fo(i, 3) ans = min(ans, dp[n - 1][i]);
    cout << ans << '\n';
    return;
}


signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--) solve();


    return 0;

}
