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

int mod;
struct mat{
    int ar[2][2];
    mat() { mem(ar); }
    mat(int *ptr){
        fo(i, 2) fo(j, 2) ar[i][j] = *ptr , ptr++;
    }
    mat operator *(const mat &o){
        mat ans;
        ans.ar[0][0] = ((ar[0][0] * o.ar[0][0])%mod + (ar[0][1] * o.ar[1][0])%mod)%mod;
        ans.ar[1][0] = ((ar[1][0] * o.ar[0][0])%mod + (ar[1][1] * o.ar[1][0])%mod)%mod;
        ans.ar[0][1] = ((ar[0][0] * o.ar[0][1])%mod + (ar[0][1] * o.ar[1][1])%mod)%mod;
        ans.ar[1][1] = ((ar[1][0] * o.ar[0][1])%mod + (ar[1][1] * o.ar[1][1])%mod)%mod;
        return ans;
    }    
};

inline void prn(mat o){
    fo(i , 2) {
        fo(j , 2)
            cout << o.ar[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';
}

const int N = 1e5 + 100;
vector<mat> tree(N << 2);
vector<mat> ar(N);

void build(int l , int r , int t){
    if(l == r){
        tree[t] = ar[l];
        return;
    }
    int mid = (l + r)>>1;
    build(l , mid , t << 1);
    build(mid + 1 , r , t << 1 | 1);
    tree[t] = tree[t << 1] * tree[t << 1 | 1];
    return;
}
int id[4] = {1, 0, 0, 1};
mat qry(int l , int r , int t , int ql , int qr){
    if(l > qr || r < ql)
        return mat(id);
    if(l >= ql && r <= qr)
        return tree[t];
    int mid = (l + r)>>1;
    return qry(l, mid, t << 1, ql, qr) * qry(mid + 1, r, t << 1 | 1, ql, qr);
}

int n, q;

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);


    cin >> mod;
    cin >> n;
    cin >> q;
    fo(i , n) {
        int tmp[4];
        fo(j, 4) cin >> tmp[j];
        ar[i] = mat(tmp);
    }

    build(0, n - 1, 1);

    fo(i , q){
        int l , r;
        cin >> l >> r;
        l--;
        r--;
        prn(qry(0, n - 1, 1, l, r));
    }


    return 0;

}