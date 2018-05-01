#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000LL
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

const int N = 2005;
int p, q, c, m;
set<ii> s;
ll dp[N][N];

ll solve(int g, int b){
	if(g > p or b > q or s.count(ii(g,b)))
		return 0;
	if(g == p and b == q)
		return 1;
	if(dp[g][b] != -1)
		return dp[g][b];

	ll ret = solve(g+1, b);
	if(g-b > c)
		ret += solve(g, b+1);
	ret %= M;

	return dp[g][b] = ret;
}

int main(void){
	scanf("%d%d%d%d", &p, &q, &c, &m);

	int g, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &g, &b);
		s.insert(ii(g,b));
	}

	memset(dp, -1, sizeof dp);
	ll ans = solve(0, 0);
	printf("%lld\n", ans);

	return 0;
}