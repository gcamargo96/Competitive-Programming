#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 605;
int l[N], r[N];
int n;
int dp[N][N];
int choice[N][N];
char s[2*N];

bool solve(int i, int j){
	if(i > j) return 1;
	if(i == j){
		if(l[i] == 1) return 1;
		return 0;
	}
	if(dp[i][j] != -1) return dp[i][j];

	bool ret = 0;
	for(int k = 0; k < j-i+1; k++){
		int d = 2*k+1;

		if(l[i] <= d and d <= r[i]){
			ret |= (solve(i+1, i+k) && solve(i+k+1, j));
		}
		if(ret){
			choice[i][j] = k;
			break;
		}
	}

	return dp[i][j] = ret;
}

void build(int i, int j, int p){
	if(i > j) return;
	if(i == j){
		s[p] = '(';
		s[p+1] = ')';
		return;
	}

	// printf("%d %d %d %d\n", i, j, choice[i][j], p);

	int k = choice[i][j];
	int d = 2*k+1;
	s[p] = '(';
	s[p+d] = ')';

	build(i+1, i+k, p+1);
	build(i+k+1, j, p+d+1);
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d%d", &l[i], &r[i]);
	}

	memset(dp, -1, sizeof dp);
	bool ans = solve(0, n-1);

	if(ans){
		build(0, n-1, 0);
		for(int i = 0; i < 2*n; i++){
			printf("%c", s[i]);
		}
		printf("\n");
	}
	else{
		printf("IMPOSSIBLE\n");
	}

	return 0;
}