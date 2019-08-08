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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f

const int N = 300005;
int n;
int op[N];
vi adj[N];

int countLeaves(int u){
	if(adj[u].size() == 0) return 1;

	int ret = 0;
	for(int v : adj[u]){
		ret += countLeaves(v);
	}

	return ret;
}

int countMinLeaves(int u){
	if(adj[u].size() == 0) return 1;

	int ret = op[u] == 0 ? 0 : INF;
	for(int v : adj[u]){
		if(op[u] == 0){
			ret += countMinLeaves(v);
		}
		else{
			ret = min(ret, countMinLeaves(v));
		}
	}

	return ret;
}

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &op[i]);
	}

	int p;
	for(int i = 2; i <= n; i++){
		scanf("%d", &p);
		adj[p].pb(i);
	}

	int leaves = countLeaves(1);
	int minLeaves = op[1] == 0 ? 0 : INF;

	for(int v : adj[1]){
		if(op[1] == 0){
			minLeaves += countMinLeaves(v);
		}
		else{
			minLeaves = min(minLeaves, countMinLeaves(v));
		}
	}

	int ans = leaves-minLeaves+1;

	printf("%d\n", ans);

	return 0;
}