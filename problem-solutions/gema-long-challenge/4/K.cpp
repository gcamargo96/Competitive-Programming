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

const int N = 1005;
int n, a;
int adj[N][N];
vi ans;

void dfs(int u){

	for(int v = 1; v <= a; v++){
		if(adj[u][v] > 0){
			adj[u][v]--;
			adj[v][u]--;
			dfs(v);
			// break;
		}
	}

	ans.pb(u);
}

void init(){
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= a; j++){
			if(i != j) adj[i][j] = 1;
		}
	}

	if(a%2 == 0){
		for(int i = 1; i < a; i += 2){
			adj[i][i+1]++;
			adj[i+1][i]++;
		}
	}

	// for(int i = 1; i <= a; i++){
	// 	for(int j = 1; j <= a; j++){
	// 		printf("%d ", adj[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
}

int main(void){
	freopen("achromatic.in", "r", stdin);
	freopen("achromatic.out", "w", stdout);	

	scanf("%d", &n);

	int e = 0;
	for(int i = 2; i < N; i++){
		if(i%2 == 1){
			int edges = (i*(i-1))/2;
			if(edges <= n and edges+1 != n){
				a = i;
				e = edges;
			}
		}
		else{
			int edges = (i*i)/2;
			if(edges <= n){
				a = i;
				e = edges;				
			}
		}

		// int aux = (i*(i-1))/2;
		// if(i%2 == 0){
		// 	aux += i/2;;
		// }

		// if(aux > n or n == aux+1) break;
		// a = i;
		// e = aux;
	}

	init();

	printf("%d\n", a);

	dfs(1);
	ans.pop_back();

	// for(int u : ans){
	// 	printf("%d ", u);
	// }

	n -= e;

	if(n == 1){
		int u = ans.back();
		if(u-1 > 1) ans.pb(u-1);
		else ans.pb(u+1);
		n--;
	}

	if(n%2 == 1){
			ans.pb(1);
			ans.pb(2);
			ans.pb(3);		
			n -= 3;
	}

	while(n > 0){
		ans.pb(1);
		ans.pb(2);		
		n -= 2;
	}

	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}