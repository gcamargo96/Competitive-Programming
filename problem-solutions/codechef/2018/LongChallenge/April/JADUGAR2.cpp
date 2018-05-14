#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 5005;
int n, q, l, r;
ll k, a, b;
ll dp[N], acum[N];

int main(void){
	scanf("%d%lld%lld%lld", &n, &k, &a, &b);

	dp[1] = k;
	for(int i = 2; i <= n; i++){
		dp[i] = a*dp[i-1];
		dp[i] %= M;
		
		ll aux = 0;
		for(int j = 1; j <= i-1; j++){
			aux += dp[j] * dp[i-j];
			aux %= M;
		}

		dp[i] += b*aux;
		dp[i] %= M;
	}

	for(int i = 1; i <= n; i++){
		acum[i] = acum[i-1];
		acum[i] += (dp[i]*dp[i])%M;
		acum[i] %= M;
	}

	scanf("%d", &q);

	while(q--){
		scanf("%d%d", &l, &r);
		ll ans = acum[r] - acum[l-1];
		ans += M;
		ans %= M;
		printf("%lld\n", ans);
	}

	return 0;
}