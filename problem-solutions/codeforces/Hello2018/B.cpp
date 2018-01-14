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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1002;
vi adj[N];
int n;
bool ans = 1;

void dfs(int u){
	if(adj[u].size() == 0)
		return;

	int cntleaf = 0;
	for(int v : adj[u]){
		dfs(v);
		if(adj[v].size() == 0){
			cntleaf++;
		}
	}

	if(cntleaf < 3)
		ans = 0;
}

int main(void){
	scanf("%d", &n);

	int p;
	for(int i = 2; i <= n; i++){
		scanf("%d", &p);
		adj[p].pb(i);
	}

	dfs(1);

	if(ans){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}