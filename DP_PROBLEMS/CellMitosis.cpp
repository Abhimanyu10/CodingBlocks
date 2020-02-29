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

int x , y , z;
int n;
int cost[N << 2];

signed main(){

#ifndef ONLINE_JUDGE 
    freopen("in.txt","r",stdin);
#endif

    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    cin >> x >> z >> y;

    auto cmp = [](pii a, pii b) {
        return a.s > b.s;
    };

    priority_queue<pii , vpii , decltype(cmp)> pq(cmp);
    
    pq.push({1 , 0});
    fill(cost, cost + N, oo);
    cost[1] = 0;
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        if(t.f > 2*n)
            continue;
        if(cost[2*t.f] > cost[t.f] + x){
            cost[2*t.f] = x + cost[t.f];
            pq.push({2 * t.f, cost[2*t.f]});
        }
        if(t.f > 2 && cost[t.f - 1] > cost[t.f] + y){
            cost[t.f - 1] = y + cost[t.f];
            pq.push({t.f - 1, cost[t.f - 1]});
        }
        if(cost[t.f + 1] > cost[t.f] + z) {
            cost[t.f + 1] = z + cost[t.f];
            pq.push({t.f + 1, cost[t.f + 1]});
        }   
    }

    cout << cost[n] << "\n";

    return 0;

}