#include<bits/stdc++.h>
using namespace std;
//#define ll = long long;

const int N = 2e3 +1;

int dp[N][N];
string s1 , s2;
int n , m;

inline int __MIN(int a , int b , int c) {return min(a  , min(b , c));}

int fun(int i , int j){
    if(i == n && j == m) return 0;
    if(i == n)
        return 1 + fun(i , j + 1);
    
    if(j == m)
        return 1 + fun(i + 1 , j);
    
    auto &res = dp[i][j];
    return __MIN(fun(i + 1 , j) + 1 , fun(i , j + 1) + 1 , (s1[i] != s2[j]) + fun(i + 1 , j + 1)); 
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp , -1 ,sizeof(dp));
    
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    cout << n << " " << m << " \n";
    cout << fun(0 , 0) << "\n";
    return 0;
}
