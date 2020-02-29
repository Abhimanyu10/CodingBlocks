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

const int N = 1000 + 10;
int ps[N][26] , c[26];
int dp[N][26];

int n;
string ss;

int fun(int i, int prev, string s ="")
{
    //have the choice to break it here or leave it as it is 
    if(i == n-1){
        if(prev == 0)
            return 0;
        bool ok = true;
        fo(j , 26){
            if(prev != 0){
                if(ps[i][j] - ps[prev - 1][j] > c[j] ){
                    ok = false;
                    break;
                }
            }else{
                if(ps[i][j] > c[j]){
                    ok = false;
                    break;
                }
            }
        }
        
        if(ok){
            deb((s + to_string(prev)));
            return 1;
        }
        return 0;
    }
    
    auto &res = dp[i][prev];
    // if(res != -1)
    //     return res;

    int ans = fun(i + 1 , prev , s);
    bool ok = true;
    fo(j , 26){
        if(prev != 0){
            if(ps[i][j] - ps[prev - 1][j] > c[j] ){
                ok = false;
                break;
            }
        }else{
            if(ps[i][j] > c[j]){
                ok = false;
                break;
            }
        }
    }
    if(ok){
        // cout << "breaked @ " << i << "\n";
        ans += fun(i + 1, i + 1 , s + to_string(prev));
    }
    return res = ans;
}

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    mem(ps);
    mem(c);

    cin >> n;
    cin >> ss;
    fo(i , 26) cin >> c[i];
    
    fo(i, n) 
        if(i == 0)
            ps[i][ss[i] - 'a']++;
        else
            fo(j, 26)
                ps[i][j] += (ps[i - 1][j] + (ss[i] - 'a' == j));

    fo(i , n) {
        fo(j , 26) cout << ps[i][j] << " ";
        cout << '\n';
    }

    cout << fun(0, 0);

    return 0;
}