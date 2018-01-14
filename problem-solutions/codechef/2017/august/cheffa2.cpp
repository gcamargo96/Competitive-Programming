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
int v[N];
ll dp[N][102][102][N];

ll solve(int i){
	if(i == N-2) return 1;
	/*for(int i = 0; i < 5; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	*/

	int x1 = v[i], x2 = v[i+1], x3 = v[i+2];
	// if(x1 == 0 or x2 == 0) return 1;
	if(dp[i][x1][x2][x3] != -1) return dp[i][x1][x2][x3];

	ll ans = solve(i+1)%M;

	if(v[i] > 0 and v[i+1] > 0){
		v[i]--, v[i+1]--, v[i+2]++;
		ans = (ans + solve(i))%M;
		v[i]++, v[i+1]++, v[i+2]--;
	}

	/*if(v[i+1] > 0 and v[i+2] > 0){
		v[i+1]--, v[i+2]--, v[i+3]++;
		ans = (ans + solve(i+1))%M;
		v[i+1]++, v[i+2]++, v[i+3]--;
	}*/

	// ans = (ans + solve(i+1))%M;


	return dp[i][x1][x2][x3] = ans;//(ans+1)%M;
}

int main(void){
	scanf("%d", &t);

	while(t--){
		memset(v, 0, sizeof v);
		memset(dp, -1, sizeof dp);
		/*for(int i = 0; i < N; i++){
			for(int j = 0; j < 102; j++){
				for(int k = 0; k < 102; k++){
					dp[i][j][k] = -1;
				}
			}
		}*/

		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		ll ans = solve(0)%M;
		printf("%lld\n", ans);
	}

	return 0;
}