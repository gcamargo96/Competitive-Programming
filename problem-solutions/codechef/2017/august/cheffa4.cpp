
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
ll dp[60][102][102][60]; // pos, x1, x2
 
void imprime(){
	for(int i = 0; i < v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}
 
ll solve(int i){
	/*printf("v.size() = %d / ", (int)v.size());*/
	//imprime();
	
	int x1 = v[i-1], x2 = v[i];
	int x3 = (i == v.size()-1 ? 0 : v[i+1]);	
	if(dp[i][x1][x2][x3] != -1){
		// imprime();
		// printf("retornou dp[%d][%d][%d] = %lld em ", i, x1, x2, dp[i][x1][x2]);
		// imprime();
		return dp[i][x1][x2][x3];
	}
 
	ll ans = 0;
	// printf("i = %d / v.size() = %d\n", i, (int)v.size());
	for(int j = i; j < int(v.size())-1; j++){
		// printf("entrou\n");
		// printf("v.size() = %d\n", (int)v.size());
		if(v[j-1] > 0 and v[j] > 0){
			v[j-1]--, v[j]--, v[j+1]++;
			// printf("chamou para "); imprime();
			ans = (ans + solve(j))%M;
			v[j-1]++, v[j]++, v[j+1]--;
		}
	}
	int len = v.size();
	if(len >= 2 and v[len-2] > 0 and v[len-1] > 0){
		v[len-2]--, v[len-1]--, v.pb(1);
		ans = (ans + solve(len-1))%M;
		v.pop_back(), v[len-1]++, v[len-2]++;
	}
 
	//if(i == len-1) ans = (ans+1)%M;
 
	// printf("salvou dp[%d][%d][%d] = %lld em ", i, x1, x2, ans);
	// imprime();
	// printf("v.size() = %d / ", (int)v.size()); imprime();
	return dp[i][x1][x2][x3] = (ans+1)%M;
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
 
		ll ans = solve(1)%M;
		printf("%lld\n", ans);
	}
 
	return 0;
}