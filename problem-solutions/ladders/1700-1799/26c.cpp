#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 5002;
int n, m;
int dp[N];
int v[N];

int main(void){
	scanf("%d%d", &n, &m);

	double aux;
	for(int i = 0; i < n; i++){
		scanf("%d%lf", &v[i], &aux);
	}

	dp[v[0]] = 1;
	int ans = 1;
	for(int i = 1; i < n; i++){
		int j = v[i];
		int mx = 0;
		for(int k = 1; k <= j; k++){
			mx = max(mx, dp[k] + 1);
		}
		dp[j] = mx;
		ans = max(ans, dp[j]);
	}

	// for(int i = 1; i <= m; i++){
	// 	printf("%d ", dp[i]);
	// }
	// printf("\n");

	printf("%d\n", n-ans);

	return 0;
}