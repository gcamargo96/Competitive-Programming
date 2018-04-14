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
int g[N][N];
int q1[N][N], q2[N][N], q3[N][N], q4[N][N];
int n, m;

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &g[i][j]);
		}
	}

	// q1
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= 1; j--){
			q1[i][j] = max(q1[i][j+1], g[i][j]);
		}
		for(int j = m; j >= 1; j--){
			q1[i][j] = max(q1[i][j], q1[i-1][j]);
		}
	}
	
	// q2
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			q2[i][j] = max(q2[i][j-1], g[i][j]);
		}
		for(int j = 1; j <= m; j++){
			q2[i][j] = max(q2[i][j], q2[i-1][j]);
		}
	}

	// q3
	for(int i = n; i >= 1; i--){
		for(int j = 1; j <= m; j++){
			q3[i][j] = max(q3[i][j-1], g[i][j]);
		}
		for(int j = 1; j <= m; j++){
			q3[i][j] = max(q3[i][j], q3[i+1][j]);
		}
	}

	// q4
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			q4[i][j] = max(q4[i][j+1], g[i][j]);
		}
		for(int j = m; j >= 1; j--){
			q4[i][j] = max(q4[i][j], q4[i+1][j]);
		}		
	}

	// pegando a resposta
	int pior = INF;
	ii ans(1,1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			ll max1 = q1[i-1][j+1];
			ll max2 = q2[i-1][j-1];
			ll max3 = q3[i+1][j-1];
			ll max4 = q4[i+1][j+1];
			
			ll mx = max(max(max1, max2), max(max3, max4));
			if(mx < pior){
				pior = mx;
				ans.fi = i;
				ans.se = j;
			}
		}
	}

	printf("%d %d\n", ans.fi, ans.se);

	return 0;
}