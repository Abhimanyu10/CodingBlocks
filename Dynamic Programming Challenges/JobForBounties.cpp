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
int ar[N];
signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    string ss;
    cin >> ss;
    stack<pair<char , int>> st;
    int n = ss.size();
    for(int i =0 ;i < n;i++){
        if(st.empty() || ss[i] == '(') st.push({ss[i],i});
        if(ss[i] == ')'){
            if(st.top().f == '('){
                ar[i] = ar[st.top().s] = 1;
                st.pop();
            }
        }
    }       

    fo(i , n) cout << ar[i] << " ";
    cout << '\n';

    fo(i , n){
        if(ar[i] == 1)
            ar[i] = (i - 1 >= 0)?ar[i - 1] + 1 : 1; 
    }

    cout << *max_element(ar, ar + n) << "\n";

    return 0;
}