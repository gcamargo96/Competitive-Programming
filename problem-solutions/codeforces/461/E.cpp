#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1002, M = 10002;
int n, m;
ll W, B, X;
ll b[N], c[N];
ll dp[N][M];

int main(void){
	scanf("%d%lld%lld%lld", &n, &W, &B, &X);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &b[i]);
		m += b[i];
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", &c[i]);
	}

	memset(dp, -1, sizeof dp);
	dp[0][0] = W;
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k <= min(ll(j), b[i]); k++){
				if(dp[i-1][j-k] == -1){
					continue;
				}
				dp[i][j] = max(dp[i][j], min(dp[i-1][j-k]+X, W+ll(j-k)*B) - c[i]*ll(k));
			}
			if(dp[i][j] >= 0){
				ans = max(ans, j);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}