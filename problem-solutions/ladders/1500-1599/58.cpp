#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 102;
int n, m;
char g[N][N];
bool tirei[N];

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,n){
		For(j,0,m){
			scanf(" %c", &g[i][j]);
		}
	}

	For(i,0,n-1){
		bool ok = 0;
		while(!ok){
			ok = 1;
			For(j,0,m){
				if(!tirei[j] and g[i][j] < g[i+1][j]){
					ok = 1;
					break;
				}
				if(!tirei[j] and g[i][j] > g[i+1][j]){
					tirei[j] = 1;
					ok = 0;
					i = -1;
					break;
				}
			}
		}
	}

	int res = 0;
	For(i,0,m){
		if(tirei[i]) res++;
	}

	printf("%d\n", res);
	
	return 0;
}

