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
const int N = 1e5 + 100;
ll ar[N+1],dp[N+1];

signed main(){
    mem(ar);
    memset(dp, -1, sizeof(dp));
#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n ;
    cin >> n;
    fo(i , n){
        int x;
        cin >> x;
        ar[x]++;
    }
    dp[0] = 0;
    dp[1] = 1 * ar[1];
    for(int i = 2 ; i < N ;i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + ar[i] * i);
    

    cout << *max_element(dp, dp + N);
    return 0;

}