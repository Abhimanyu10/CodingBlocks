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
int tree[N << 2];
int ar[N];

void build(int l , int r , int t){
    if(l == r){
        tree[t] = ar[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l , mid , t << 1);
    build(mid + 1 , r , t << 1 | 1);
    tree[t] = max(tree[t << 1], tree[t << 1 | 1]);
    return;
}

int qry(int l , int r, int t, int ql , int qr){
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return tree[t];
    int mid = (l + r)>>1;
    return max(qry(l, mid, t << 1, ql, qr) , qry(mid + 1 , r , t << 1 | 1 , ql , qr));
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    fo(i , n) cin >> ar[i];
    build(0 , n -1 , 1);
    fo(i , n){
        int l = i;
        int h = n;
        while(l + 1 < h){
            int mid = (l + h) >> 1;
            int x = qry(0, n - 1, 1, i+1, mid);
            deb(x);
            if(x > ar[i])
                h = mid;
            else
                l = mid;    
        }
        cout << "l " << l << " ar[l] " << ar[l] << "\n";
    }


    return 0;

}