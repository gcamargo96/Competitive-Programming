#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

const int N = 2505;
int A[N], B[N];
int vis[N];
vi adj[N];

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