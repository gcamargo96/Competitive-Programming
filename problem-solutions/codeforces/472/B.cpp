#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 52;
int n, m;
char g[N][N];

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &g[i][j]);
		}
	}

	bool ans = 1;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int dif = 0, eq = 0;
			for(int k = 0; k < m; k++){
				if(g[i][k] == '#' or g[j][k] == '#'){
					if(g[i][k] == g[j][k])
						eq++;
					else
						dif++;
				}
			}
			if(dif > 0 and eq > 0){
				// printf("i = %d, j = %d\n", i, j);
				// printf("eq = %d, dif = %d\n", eq, dif);
				ans = 0;
			}
		}
	}

	if(ans)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}