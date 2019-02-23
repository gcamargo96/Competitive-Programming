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

const int N = 200005, M = 1000000007;
int n, l, r;
ll dp[N][5];
int cnt[5], x;

ll add(ll a, ll b){
	return (a+b)%M;
}

ll mul(ll a, ll b){
	return (a*b)%M;
}

ll solve(int i, int k){
	if(i == n){
		if(k == 0) return 1;
		return 0;
	}

	if(dp[i][k] != -1) return dp[i][k];

	ll ret = mul(solve(i+1, k), cnt[0]);
	ret = add(ret, mul(solve(i+1, (k+1)%3), cnt[1]));
	ret = add(ret, mul(solve(i+1, (k+2)%3), cnt[2]));

	return dp[i][k] = ret;
}

int main(void){
	scanf("%d%d%d", &n, &l, &r);

	int i = l;
	for(i = l; i <= r and i%3 != 0; i++){
		cnt[i%3]++;
	}

	int j = r;
	for(j = r; j >= i and j%3 != 2; j--){
		cnt[j%3]++;
	}

	// printf("i = %d, j = %d\n", i, j);

	if(j > i){
		x = (j-i+1)/3;
	}
	cnt[0] += x;
	cnt[1] += x;
	cnt[2] += x;

	// printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], x);

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 0);

	printf("%lld\n", ans);

	return 0;
}