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

const int N = 105;
char g[N][N];
int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &g[i][j]);
		}
	}

	bool ok = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int cnt = 0;
			for(int k = i-1; k <= i+1; k++){
				for(int l = j-1; l <= j+1; l++){
					if(!(k == i and l == j)){
						if(g[k][l] == '*'){
							cnt++;
						}
					}
				}
			}
			if(g[i][j] >= '1' and g[i][j] <= '8' and cnt != g[i][j]-'0'){
				ok = 0;
			}
			if(g[i][j] == '.' and cnt > 0){
				ok = 0;
			}
		}
	}

	if(ok){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}