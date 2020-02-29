#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 10;
int ar[N];
int n;
bool fun(int i , int x){
	if(i == n){
		if(x == 0) return 1;
		return 0;
	}
	return fun(i + 1 , x + ar[i]) | fun(i + 1 , x);
}	

void solve(){
	scanf("%d",&n);
	for(int i=0 ;i < n;i++) scanf("%d" , &ar[i]);
	if (fun(0 , 0)) printf("Yes\n");
	else		printf("No\n");
	return ;
}

int main(){
	int tc;
	scanf("%d" , &tc);
	while(tc--) solve();
	return 0;
}
