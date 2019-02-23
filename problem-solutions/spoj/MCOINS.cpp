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

const int N = 1000005;
int k, l, m, n;
int dp[N];

bool solve(int n){
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];

	bool nxt = 1;

	nxt &= solve(n-1);
	if(n-k >= 0) nxt &= solve(n-k);
	if(n-l >= 0) nxt &= solve(n-l);

	return dp[n] = !nxt;
}

int main(void){
	scanf("%d%d%d", &k, &l, &m);

	memset(dp, -1, sizeof dp);

	for(int i = 0; i < m; i++){
		scanf("%d", &n);
		bool ans = solve(n);
		
		printf("%c", ans == 1 ? 'A' : 'B');
	}
	printf("\n");

	return 0;
}