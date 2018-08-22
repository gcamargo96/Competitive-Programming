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

const int N = 3002;
int n;
ll dp[N][5];
int a[N], b[N], c[N];

ll solve(int i, int op){
	if(i == n-1){
		if(op == 0) return a[i];
		else if(op == 2) return b[i];
		else return 0;
	}
	if(dp[i][op] != -1) return dp[i][op];

	ll ret = 0;
	if(op == 0){
		ret = max(solve(i+1, 2), solve(i+1, 3)) + a[i];
	}
	else if(op == 1){
		ret = max(solve(i+1, 0), solve(i+1, 1)) + b[i];
	}
	else if(op == 2){
		ret = max(solve(i+1, 2), solve(i+1, 3)) + b[i];
	}
	else{
		ret = max(solve(i+1, 0), solve(i+1, 1)) + c[i];
	}

	return dp[i][op] = ret;
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}

	ll ans = max(solve(1, 0) + a[0], solve(1, 1) + b[0]);
	printf("%lld\n", ans);

	return 0;
}