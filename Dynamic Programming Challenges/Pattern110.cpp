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
int n;
vi ar;
int dp[64][2][2][2][2];
//     pos f  p1 p2 found

int fun(int i , int f , int p1 , int p2 , int found , string st=""){
    if(i == n){
        // deb(st);
        return found==1;
    }
    auto &res = dp[i][f][p1][p2][found];
    if(res!=-1) return res;
    int lim = f ? ar[i] : 1;
    int ans = 0;
    for (int j = 0;j <= lim; j++)
        ans += fun(i + 1, j == ar[i] ? f : 0, j, p1, found | ((p1 == 1) && (p2 == 1) && (j == 0)) , st+to_string(j));
    
    return res = ans;
}


int get(int x){
    ar.clear();
    while(x>0){
        ar.pb(x % 2);
        x /= 2;
    }
    n = ar.size();
    reverse(all(ar));
    memset(dp, -1, sizeof(dp));
    return fun(0 , 1 , 0 , 0 , 0);
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int l , r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << "\n";
    }

    return 0;

}