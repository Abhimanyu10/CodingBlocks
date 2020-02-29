#include<bits/stdc++.h>
using namespace std;
//using ll = long long;
const int N = 2000;
int dp[N];
int ar[N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    for(int i =1 ;i <= n ;i++) cin >> ar[i];

    dp[n] = 1;
    for(int i = n - 1; i >= 1 ;i--){
        if(ar[i] == 0){
        for(int j = min(n , i + k) ; j > i ;j--)
            dp[i] += dp[j];
        }
    }
  //  for(int i = 1 ;i<=n;i++) cout << dp[i] << " ";
//    cout << "\n";
    cout << dp[1] << "\n";

    return 0;
}
