#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 100005;
vi adj[N];
int n;

int main(void){
	scanf("%d", &n);

	int u, v;
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if(n == 2){
		printf("Yes\n");
		printf("1\n");
		printf("1 2\n");
		return 0;
	}

	int maxdeg = 0, id = 0, cnt = 0;
	vi leafs;
	for(int u = 1; u <= n; u++){
		// maxdeg = max(maxdeg, int(adj[u].size()));
		if(adj[u].size() == 1){
			leafs.pb(u);
		}
		if(adj[u].size() > 2){
			cnt++;
		}
		if(adj[u].size() > maxdeg){
			maxdeg = adj[u].size();
			id = u;
		}
	}

	if(cnt < 2){
		printf("Yes\n");
		printf("%d\n", int(leafs.size()));
		for(int i = 0; i < leafs.size(); i++){
			printf("%d %d\n", id, leafs[i]);
		}
	}
	else{
		printf("No\n");
	}

	return 0;
}