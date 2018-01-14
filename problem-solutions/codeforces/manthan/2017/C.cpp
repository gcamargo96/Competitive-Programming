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
#define fast_cin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define LESS 0
#define EQUALS 1
#define GREATER 2
#define M 1000000007

const int N = 100002;
int n, m, k, x;
vector<int> adj[N];
ll dp[N][3][10];

void init(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 10; k++){
				dp[i][j][k] = -1LL;
			}
		}
	}
}

ll mul(ll a, ll b){
	return (a*b)%M;
}

ll solve(int u, int label, int cnt, int last){
	if(cnt > x) return 0;
	if(dp[u][label][cnt] != -1) return dp[u][label][cnt];

	ll ret;
	if(label == LESS) ret = k-1;
	if(label == EQUALS) ret = 1;
	if(label == GREATER) ret = n-k;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(v != last){
			if(label == LESS){
				ret = mul(ret, solve(v, LESS, cnt, u));
				ret = mul(ret, solve(v, EQUALS, cnt+1, u));
				ret = mul(ret, solve(v, GREATER, cnt, u));
			}
			else if(label == EQUALS){
				ret = mul(ret, solve(v, LESS, cnt, u));
			}
			else if(label == GREATER){
				ret = mul(ret, solve(v, LESS, cnt, u));
				ret = mul(ret, solve(v, GREATER, cnt, u));
			}
		}
	}

	return dp[u][label][cnt] = ret;
}

int main(void){
	init();
	scanf("%d%d", &n, &m);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	scanf("%d%d", &k, &x);

	ll ans = 0;
	ans += solve(1, LESS, 0, 0);
	ans += solve(1, EQUALS, 1, 0);
	ans += solve(1, GREATER, 0, 0);

	printf("%lld\n", ans);

	return 0;
}