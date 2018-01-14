#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 502;
int v[N];
int n, k, x;
int dp[N][N];

int solve(int p, int x){
	if(p == n) return 0;
	//if(dp[p][x] != -1) return dp[p][x];
	
	int ret1, ret2 = 1000000000, melhor = 0;
	int ant = v[p]+v[p-1];
	int prox = v[p]+v[p+1];
	if(ant < k){
		ret1 = solve(p+1, k-ant) + k-ant;
	}
	else if(prox < k){
		for(int i = 1; i <= k-prox; i++){
			int aux = solve(p+1, i) + i;
			if(aux < ret2){
				ret2 = aux;
				melhor = i;
			}
		}
	}

	if(ret1 < ret2){
		printf("ret1: pos = %d / v[p] += %d\n", p, k-ant);
		v[p] += k-ant;
		return ret1;
	}
	else{
		printf("ret2: pos = %d / v[p] += %d\n", p, melhor);
		v[p] += melhor;
		return ret2;
	}
}

int main(void){
	scanf("%d%d", &n, &k);

	v[0] = k;
	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}
	v[n+1] = k;

	solve(1, 0);

	for(int i = 1; i <= n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}

