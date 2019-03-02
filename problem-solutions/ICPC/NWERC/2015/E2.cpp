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

const int N = 2505;
int A[N], B[3*N];
int vis[N];
map<ll,int> who;
vector<pair<int, int> > v;
vi adj[N];
int n, cnt = 1;

int kuhn(int u){
	if (vis[u])
		return 0;
	vis[u] = 1;

	for (int v : adj[u]){
		if (B[v] == -1){
			A[u] = v;
			B[v] = u;
			return 1;
		}
	}
	for (int v : adj[u]){
		if (kuhn(B[v])){
			A[u] = v;
			B[v] = u;
			return 1;
		}
	}
	return 0;
}

int vertex(ll u){
	if(who.count(u))
		return who[u];
	return who[u] = cnt++;
}

int main(void){
	scanf("%d", &n);

	int a, b;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		
		v.eb(a, b);
		adj[i].pb(vertex(a+b));
		adj[i].pb(vertex(a-b));
		adj[i].pb(vertex(ll(a)*ll(b)));
	}

	memset(B, -1, sizeof B);

	int ans = 0;
	for(int i = 0; i < n; i++){
		memset(vis, 0, sizeof vis);
		ans += kuhn(i);
	}

	if(ans >= n){
		for(int i = 0; i < n; i++){
			a = v[i].fi, b = v[i].se;
			char op;
			ll ans;
			if(A[i] == vertex(a+b)){
				op = '+'; ans = a+b;
			}
			else if(A[i] == vertex(a-b)){
				op = '-'; ans = a-b;
			}
			else{
				op = '*'; ans = ll(a)*ll(b);
			}
			printf("%d %c %d = %lld\n", a, op, b, ans);
		}
	}
	else{
		printf("impossible\n");
	}

	return 0;
}