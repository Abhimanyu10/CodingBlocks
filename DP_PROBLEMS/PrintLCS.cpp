#include<bits/stdc++.h>
using namespace std;
//using ll = long long;

const int N = 1000 + 1;
int dp[N][N];
int par[N][N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s1 , s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	
	for(int i = 0 ;i < n ;i++) if(s1[i] == s2[0]) dp[i][0] = 1; else dp[i][0] = (i > 0)?dp[i - 1][0]:0;
	for(int i = 0 ;i < m ;i++) if(s2[i] == s1[0]) dp[0][i] = 1; else dp[0][i] = (i > 0)?dp[0][i - 1]:0;
		
	for(int i =1 ;i < n ;i++){
		for(int j =1 ;j < m ;j++){
			if(s1[i] == s2[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]);
		}
	}
	
	
//	for(int i =0 ;i < n ;i++) {
//		for(int j =0 ; j < m ;j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	//building solution::
	int x = n-1 , y = m - 1;
	string ans = "";
	while(true){
		if(s1[x] == s2[y]){
			ans.push_back(s1[x]);
			x = x - 1;
			y = y - 1;
		}else{
			if(dp[x][y] == dp[x - 1][y]) x --;
			else y--;
		}
		if(x < 0 || y < 0) break;
	} 
	reverse(ans.begin() , ans.end());
	
	cout << ans << '\n';
	
	
	return 0;
}
