#include <bits/stdc++.h>
using namespace std;
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

int n, m, sz;
set<int> av;
set<ii> e;

void dfs(int u){
	sz++;
	av.erase(u);

	int v = -1;
	while(av.upper_bound(v) != av.end()){
		v = *av.upper_bound(v);
		if(!e.count(ii(u,v))){
			dfs(v);
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		av.insert(i);
	}

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		e.insert(ii(u,v));
		e.insert(ii(v,u));
	}

	vi ans;
	for(int u = 1; u <= n; u++){
		if(av.count(u)){
			sz = 0;
			dfs(u);
			ans.pb(sz);
		}
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}