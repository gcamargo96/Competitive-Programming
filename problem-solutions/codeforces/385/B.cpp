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

const int N = 502;
char g[N][N];
int n, m, cntx, cntres;

int main(void){
	//ios_base::sync_with_stdio(false);
	//cin >> n >> m;
	scanf("%d%d", &n, &m);

	For(i,0,n){
		/*For(j,0,m){
			cin >> g[i][j];
			if(g[i][j] == 'X') cntx++;
		}*/
		scanf("%s", g[i]);
	}

	For(i,0,n){
		For(j,0,m){
			if(g[i][j] == 'X') cntx++;
		}
	}

	bool foi = 0, ok = 1;
	int tamh = 0, tamv = 0, k, l;
	For(i,0,n){
		For(j,0,m){
			//cout << "loop" << endl;
			if(g[i][j] == 'X'){
				k = i, l = j;
				while(k < n and g[k][j] == 'X'){
					k++;
				}
				while(l < m and g[i][l] == 'X'){
					l++;
				}
				tamv = k, tamh = l;
				//cout << "tamv = " << tamv << " tamh = " << tamh << endl;
				for(k = i; k < tamv; k++){
					for(l = j; l < tamh; l++){
						if(g[k][l] == 'X') cntres++;
						else{
							ok = 0;
						}
					}
				}
				foi = 1;
				break;
			}
		}
		if(foi) break;
	}

	if(cntres == cntx and ok) printf("YES\n");
	else printf("NO\n");

	return 0;
}

