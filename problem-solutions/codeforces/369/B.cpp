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
ll g[N][N];
int pi = -1, pj = -1;
int n;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		For(j,0,n){
			scanf("%lld", &g[i][j]);
			if(g[i][j] == 0){
				pi = i;
				pj = j;
			}
		}
	}

	if(n == 1){
		printf("1\n");
		return 0;
	}

	ll sum = 0;
	if(pi > 0){
		For(i,0,n){
			sum += g[0][i];
		}
	}
	else{
		For(i,0,n){
			sum += g[n-1][i];
		}
	}

	ll x = sum;
	For(i,0,n){
		x -= g[pi][i];
	}

	if(x < 1){
		printf("-1\n");
		return 0;
	}
	else{
		g[pi][pj] = x;
	}

	bool ok = 1;

	For(i,0,n){
		ll aux = 0;
		For(j,0,n){
			aux += g[i][j];
		}
		if(aux != sum){
			ok = 0;
			break;
		}
	}

	For(j,0,n){
		ll aux = 0;
		For(i,0,n){
			aux += g[i][j];
		}
		if(aux != sum){
			ok = 0;
			break;
		}
	}

	ll aux = 0;
	For(i,0,n){
		aux += g[i][i];
	}
	if(aux != sum) ok = 0;

	aux = 0;
	For(i,0,n){
		aux += g[i][n-i-1];
	}
	if(aux != sum) ok = 0;

	if(ok) printf("%lld\n", x);
		else printf("-1\n");

	return 0;
}
