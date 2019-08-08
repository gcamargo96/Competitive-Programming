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

const int N = 1000005, M = 10000005;
int n;
int v[N], pai[N];
int vis[M], L[M], R[M], nxt[M], last[M];

void precalc(){
	for(int i = 1; i < M; i++){
		vis[i] = i;
	}

	for(int i = 2; i < M; i++){
		if(vis[i] == i){
			for(int j = i+i; j < M; j += i){
				if(i < vis[j]) vis[j] = i;
			}
		}
	}

	// for(int i = 1; i <= 12; i++){
	// 	printf("%d ", vis[i]);
	// }
	// printf("\n");
}

bool check(int l, int r, int i){
	return L[i] < l and R[i] > r;
}

bool solve(int l, int r, int p){
	for(int k = 0; k < r-l+1; k++){
		int i = l+k;
		if(check(l, r, i)){
			// printf("root %d\n", i);
			pai[i] = p;
			return solve(l, i-1, i) and solve(i+1, r, i);
		}
		i = r-k;
		if(check(l, r, i)){
			// printf("root %d\n", i);
			pai[i] = p;
			return solve(l, i-1, i) and solve(i+1, r, i);
		}
	}
	// for(int i = l; i <= r; i++){
	// 	if(check(l, r, i)){
	// 		// printf("root %d\n", i);
	// 		pai[i] = p;
	// 		return solve(l, i-1, i) and solve(i+1, r, i);
	// 	}
	// }

	return l >= r;
}

int main(void){
	precalc();
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	// for(int i = 1; i <= n; i++){
	// 	if(v[i] == 1){
	// 		printf("impossible\n");
	// 		return 0;
	// 	}
	// }

	for(int i = 0; i < M; i++){
		nxt[i] = n+1;
		last[i] = 0;
		L[i] = 0;
		R[i] = n+1;
	}

	for(int i = n; i >= 1; i--){
		int x = v[i];
		while(vis[x] > 1){
			if(nxt[vis[x]] > i) R[i] = min(R[i], nxt[vis[x]]);
			nxt[vis[x]] = i;
			x = x/vis[x];
		}
	}
	for(int i = 1; i <= n; i++){
		int x = v[i];
		while(vis[x] > 1){
			if(last[vis[x]] < i) L[i] = max(L[i], last[vis[x]]);
			last[vis[x]] = i;
			x = x/vis[x];
		}
	}

	// for(int i = 1; i <= n; i++){
	// 	printf("%d %d\n", L[i], R[i]);
	// }

	bool ok = solve(1, n, 0);	

	if(ok){
		for(int i = 1; i <= n; i++){
			printf("%d ", pai[i]);
		}
		printf("\n");
	}
	else{
		printf("impossible\n");
	}

	return 0;
}