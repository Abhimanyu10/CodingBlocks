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
#define int ll
using namespace std;
using ll  = long long;
using lld = long double;
using l64 = int64_t;

const ll MOD =1000000007;

const int N = 1e5 + 10;
int ar[N];
int ps[N];

inline int fun(int l , int r){

    if(l >= r)
        return 0;
    // cout << l << " " << r << "\n";
    int sum = ps[r] - (l > 0 ? ps[l - 1]:0);
    if(sum % 2 == 1)
        return 0;
    int rs = 0;
    int i = l;
    if(sum == 0)
        return r - l;
    while(rs < sum/2){
        rs += ar[i];
        i++;
    }
    if(rs!=sum/2)
        return 0;
    return 1 + max(fun(l, i - 1) , fun(i , r));
}

inline void solve(){
    int n;
    cin >> n;
    fo(i, n) {
		cin >> ar[i];
		if(i == 0) ps[0] = ar[0];
		else ps[i] = ar[i] + ps[i - 1];
	}
    cout << fun(0, n - 1)<<"\n";
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }

    return 0;

}