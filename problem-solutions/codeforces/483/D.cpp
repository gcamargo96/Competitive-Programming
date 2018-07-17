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

const int N = 5002;
ll v[N];
ll f[N][N], dp[N][N];
int n, q;


int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		f[i][i] = dp[i][i] = v[i];
	}

	for(int tam = 2; tam <= n; tam++){
		for(int l = 0; l < n; l++){
			int r = l+tam-1;
			f[l][r] = f[l][r-1] ^ f[l+1][r];
		}
	}

	for(int tam = 2; tam <= n; tam++){
		for(int l = 0; l < n-tam+1; l++){
			int r = l+tam-1;
			dp[l][r] = max(f[l][r], max(dp[l][r-1], dp[l+1][r]));
		}
	}

	scanf("%d", &q);

	int l, r;
	while(q--){
		scanf("%d%d", &l, &r);
		l--, r--;
		printf("%lld\n", dp[l][r]);
	}

	return 0;
}