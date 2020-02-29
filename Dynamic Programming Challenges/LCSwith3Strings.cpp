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

int n , m , l;
string s1 , s2 , s3;
int dp[202][202][202];
int fun(int i , int j , int k){
    if(i >= n || j >= m || k >= l)
        return 0;

    auto &res = dp[i][j][k];
    if(res!=-1)
        return res;
    int ans = 0;
    if(s1[i] == s2[j] && s2[j] == s3[k])
        ans = max(ans , 1 + fun(i + 1, j + 1, k + 1));
    
    ans =  max({ans,fun(i + 1, j, k) , fun(i , j + 1 , k) , fun(i , j , k + 1)});
    return res = ans;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> s1 >> s2 >> s3;
    n = s1.size();
    m = s2.size();
    l = s3.size();
    cout << fun(0, 0, 0);

    return 0;

}