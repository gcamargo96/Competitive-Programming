#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
vi adj[N];
int c[N], diff[N];
int n, root = 1;

int main(void){
	scanf("%d", &n);

	int u, v;
	For(i,0,n-1){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	For(i,0,n){
		scanf("%d", &c[i+1]);
	}

	int cnt1 = 0, cnt2 = 0;
	bool rooted = 0;
	for(int u = 1; u <= n; u++){
		//set<int> colors;
		int cnt = 0;
		For(i,0,adj[u].size()){
			v = adj[u][i];
			//colors.insert(c[v]);
			if(c[u] != c[v]) cnt++;
		}
		//if(colors.count(c[u])) colors.erase(c[u]);
		if(cnt == 1){
			cnt1++;
			if(!rooted) root = u;
		}
		if(cnt > 1){
			cnt2++;
			root = u;
			rooted = 1;
		}
		diff[u] = cnt;
	}

	if(!cnt1 and !cnt2){
		printf("YES\n");
		printf("1\n");
	}
	else if(cnt2 > 1){
		printf("NO\n");
	}
	else{
		int cnt = 0;
		For(i,0,adj[root].size()){
			v = adj[root][i];
			if(c[root] != c[v]){
				cnt++;
			}
		}

		if((cnt2 == 1 and cnt == cnt1) or (cnt2 == 0 and cnt == cnt1-1)){
			printf("YES\n");
			printf("%d\n", root);
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}

