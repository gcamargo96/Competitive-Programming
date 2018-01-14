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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n, cnt = 0;
int v[N];
ii aux[N];
vector<int> ans[N];
bool vis[N];

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	ans[cnt].pb(u);
	dfs(v[u]);
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
		aux[i].fi = v[i];
		aux[i].se = i;
	}

	sort(aux+1, aux+n+1);

	for(int i = 1; i <= n; i++){
		v[aux[i].se] = i;
	}

	/*for(int i = 1; i <= n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	*/

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cnt++;
			dfs(i);
		}
	}

	printf("%d\n", cnt);
	for(int i = 1; i <= cnt; i++){
		printf("%d ", (int)ans[i].size());
		for(int j = 0; j < ans[i].size(); j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}