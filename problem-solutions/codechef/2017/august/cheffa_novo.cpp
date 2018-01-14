
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back
#define eb emplace_back
#define ii pair<int,int>
#define fi first
#define se second
#define M 1000000007
 
using namespace std;
 
const int N = 60;
int t, n;
vector<int> v;
ll dp[60][102][102]; // pos, qto pos i ganhou, qto pos i+1 ganhou
 
void imprime(){
	for(int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}
 
ll solve(int i){
	if(i == v.size()){
		// imprime();
		return 1;
	}
	
	// NAO MEXER
	// int a = (i-1 >= 0 ? min(v[i-1], v[i]) : 0);
	// int b = max(0, v[i]-a);	

	int a = (i-2 >= 0 ? min(v[i-2], v[i-1]) : 0);
	int b = (i+1 < v.size() ? min(v[i], v[i+1]) : 0);

	// printf("a = %d / b = %d\n", a, b);
	if(dp[i][a][b] != -1){
		// imprime();
		// printf("retornou dp[%d][%d][%d] = %lld em ", i, add, sub, dp[i][add][sub]);
		// imprime();
		// return dp[i][a][b];
	}
 
	ll ans = 0;
	int len = v.size();
	int aux = (i-1 >= 0 ? min(v[i-1], v[i]) : 0);
	if(i < len-1){
		for(int j = 0; j <= aux; j++){
			v[i-1] -= j, v[i] -= j, v[i+1] += j;
			ans = (ans + solve(i+1))%M;
			v[i-1] += j, v[i] += j, v[i+1] -= j;
		}
	}
	else{
		for(int j = 1; j <= aux; j++){
			v[len-2] -= j, v[len-1] -= j, v.pb(j);
			ans = (ans + solve(i+1))%M;
			v.pop_back(), v[len-2] += j, v[len-1] += j;
		}
		ans = (ans + solve(i+1)%M);
	}
 
	//if(i == len-1) ans = (ans+1)%M;
 
	// printf("salvou dp[%d][%d][%d] = %lld em ", i, x1, x2, ans);
	// imprime();
	// printf("v.size() = %d / ", (int)v.size()); imprime();
	return dp[i][a][b] = ans;
}
 
int main(void){
	scanf("%d", &t);
 
	while(t--){
		v.clear();
		memset(dp, -1, sizeof dp);

		scanf("%d", &n);
 
		int x;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			v.pb(x);
		}
 
		ll ans = solve(0)%M;
		printf("%lld\n", ans);
	}
 
	return 0;
}