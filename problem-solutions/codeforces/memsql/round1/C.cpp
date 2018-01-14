#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

#define BOB 0
#define ALICE 1

int dp[52][2];
int n;
int v[52];

int solve(int i, int turn){
	if(i == n-1){
		if(turn == BOB) return v[i];
		else return 0;
	}

	if(dp[i][turn] != -1) return dp[i][turn];

	int a, b;
	if(turn == BOB){
		a = solve(i+1, ALICE) + v[i];
		b = solve(i+1, BOB);
		return dp[i][turn] = max(a, b);
	}
	else{
		a = solve(i+1, BOB);
		b = solve(i+1, ALICE) + v[i];
		return dp[i][turn] = min(a,b);
	}
}

int main(void){
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += v[i];
	}

	int ans = solve(0, BOB);

	printf("%d %d\n", sum-ans, ans);

	return 0;
}