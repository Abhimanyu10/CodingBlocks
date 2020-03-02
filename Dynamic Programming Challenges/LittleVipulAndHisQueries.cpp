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

const int N = 101;

int ca[N], cb[N];
int dp[N][N][N];

int n;

int fun(int i , int x , int y){
    if(i == n)
        return 0;

    auto &res = dp[i][x][y];
    if(res!=-1) return res;
    int ans = 0;
    if(ca[i] <= x && cb[i] <= y){
        ans = max(ans, 1 + fun(i + 1, x - ca[i], y - cb[i]));
    }
    ans = max(ans, fun(i + 1, x, y));
    return res = ans;
}


signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    fo(i , n){
        string ss;
        cin >> ss;
        for(const auto &j : ss) 
            if(j == 'R')
                ca[i]++;
            else
                cb[i]++;
    }

    int q;
    cin >> q;
    fun(0, 100, 100);
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << fun(0, x, y) << "\n";
    }

    return 0;

}