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

#define MAX_NIMBER 305

const int N = 1005;
int m;
int dp[N][N];

int solve(int l, int c){
	if(l == 0 or c == 0 or l == c) return MAX_NIMBER;
	
	int& ans = dp[l][c];
	if(ans != -1) return ans;

	bitset<MAX_NIMBER+1> reacheable;

	for(int u = 1; u <= min(l, c); u++){
		reacheable.set(solve(l-u, c-u));
	}
	for(int u = 1; u <= l; u++){
		reacheable.set(solve(l-u, c));
	}
	for(int u = 1; u <= c; u++){
		reacheable.set(solve(l, c-u));
	}
	for(int i = 0; i <= MAX_NIMBER; i++){
		if(!reacheable.test(i)) return ans = i;
	}
}

int main(void){
	scanf("%d", &m);

	memset(dp, -1, sizeof dp);

	int l, c;
	int ans = 0;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &l, &c);
		ans ^= solve(l, c);
	}

	if(ans){
		printf("Y\n");
	}
	else{
		printf("N\n");
	}

	return 0;
}