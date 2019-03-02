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

#define L 0
#define R 1

const int N = 105;
int n;
int v[N];
int dp[N][N][N], opt[N][N][N];
vi s;

int solve(int l, int r, int i){
	if(i == n) return abs(v[r]-v[l]);
	if(dp[l][r][i] != -1) return dp[l][r][i];

	int a = max(solve(i, r, i+1), max(abs(v[i]-v[l]), 0));
	int b = max(solve(l, i, i+1), max(abs(v[i]-v[r]), 0));

	int ret = a;
	if(a < b){
		ret = a;
		opt[l][r][i] = L;
	}
	else{
		ret = b;
		opt[l][r][i] = R;
	}

	return dp[l][r][i] = ret;
}

void build(int l, int r, int i){
	if(i == n) return;

	if(opt[l][r][i] == L){
		s.insert(s.begin(), v[i]);
		build(i, r, i+1);
	}
	else{
		s.pb(v[i]);
		build(l, i, i+1);
	}
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	sort(v, v+n);

	memset(dp, -1, sizeof dp);
	int ans = max(abs(v[0]-v[1]), solve(0, 1, 2));

	s.pb(v[0]);
	s.pb(v[1]);
	// printf("%d\n", ans);
	build(0, 1, 2);

	for(int i = 0; i < n; i++){
		printf("%d ", s[i]);
	}
	printf("\n");

	return 0;
}