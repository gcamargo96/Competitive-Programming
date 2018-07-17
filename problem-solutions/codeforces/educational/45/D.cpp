#include <bits/stdc++.h>
using namespace std;
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

const int N = 1002;
int n, a, b;
int g[N][N];

int main(void){
	scanf("%d%d%d", &n, &a, &b);

	if(a == 1 and b == 1 and (n == 1 or n > 3)){
		int comps = n;
		for(int i = 1; i < n and comps > a; i++){
			g[i][i+1] = 1;
			g[i+1][i] = 1;
			comps--;
		}

		printf("YES\n");
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				printf("%d", g[i][j]);
			}
			printf("\n");
		}
	}
	else if(a > 1 and b == 1){
		int comps = n;
		for(int i = 1; i < n and comps > a; i++){
			g[i][i+1] = 1;
			g[i+1][i] = 1;
			comps--;
		}

		printf("YES\n");
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				printf("%d", g[i][j]);
			}
			printf("\n");
		}
	}
	else if(a == 1 and b > 1){
		int comps = n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i != j) g[i][j] = 1;
			}
		}

		for(int i = 1; i < n and comps > b; i++){
			g[i][i+1] = 0;
			g[i+1][i] = 0;
			comps--;
		}

		printf("YES\n");
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				printf("%d", g[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("NO\n");
	}

	return 0;
}