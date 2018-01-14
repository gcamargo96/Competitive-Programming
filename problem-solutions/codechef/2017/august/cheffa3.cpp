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
ll dp[N][52][102][52];

void imprime(){
	for(int i = 0; i < 6; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}

ll solve(int i){
	// if(i == N-2) return 1;
	// imprime();
	

	int x1 = min(v[i], v[i+1]), x2 = v[i+1], x3 = v[i+2];
	// int p = v1 > v2 ? 1 : 0;

	if(dp[i][x1][x2][x3] != -1){
		// printf("retornou %lld dos estados %d %d %d\n", dp[i][x1][x2], i, x1, x2);
		return dp[i][x1][x2][x3];
	}

	ll ans = 0;
	for(int j = i; j < N-2; j++){
		if(v[j] > 0 and v[j+1] > 0){
			v[j]--, v[j+1]--, v[j+2]++;
			ans = (ans + solve(j))%M;
			v[j]++, v[j+1]++, v[j+2]--;
		}
	}

	return dp[i][x1][x2][x3] = (ans+1)%M;//(ans+1)%M;
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