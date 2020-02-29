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
const int N = 1e5+10;
int bit[N];
void upd(int x , int val){
    while(x < N){
        bit[x] += val;
        x += (x & -x);
    }
    return;
}

int qry(int x){
    int ans = 0;
    while(x > 0){
        ans += bit[x];
        x -= (x & -x);
    }
    return ans;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    unordered_map<string,int> hm , st;
    hm.max_load_factor(.25);
    hm.reserve(1 << 11);
    fo(i , n){
        string ss;
        cin >> ss;
        int x;
        cin >> x;
        hm[ss] = x;
    }
    int q;
    cin >> q;
    while(q--){
        string ss;
        cin >> ss;
        if(ss == "+"){
            string str;
            cin >> str;
            st[str]++;
            upd(hm[str] , 1);
            continue;
        }
        if(ss == "-"){
            string str;
            cin >> str;
            if(st[str] == 0) 
            continue;
            st[str]--;
            upd(hm[str], -1);
            continue;
        }
        int x;
        cin >> x;
        cout << qry(N-1) - qry(x) << "\n";
    }




    return 0;

}