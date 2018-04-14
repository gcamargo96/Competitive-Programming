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
int t, r, c, h, v;
char g[N][N];

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d%d%d", &r, &c, &h, &v);

		int tot = 0;
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				scanf(" %c", &g[i][j]);
				
				if(g[i][j] == '@'){
					tot++;
				}
			}
		}

		if(tot == 0){
			printf("Case #%d: POSSIBLE\n", caso);
			continue;			
		}

		if(tot%(h+1) != 0 or tot%(v+1) != 0 or tot%((h+1)*(v+1)) != 0){
			printf("Case #%d: IMPOSSIBLE\n", caso);
			continue;
		}

		int hsum = 0, vsum = 0, hcut = 0, vcut = 0;
		vector<int> vh, vv;
		vh.pb(0), vv.pb(0); // onde termina o anterior

		// cortes horizontais
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				if(g[i][j] == '@'){
					hsum++;
				}
			}
			if(hsum == tot/(h+1)){
				vh.pb(i);
				hsum = 0;
				hcut++;
			}
		}

		// cortes verticais
		for(int j = 1; j <= c; j++){
			for(int i = 1; i <= r; i++){
				if(g[i][j] == '@'){
					vsum++;
				}
			}
			if(vsum == tot/(v+1)){
				vv.pb(j);
				vsum = 0;
				vcut++;
			}
		}

		// vh.pb(r+1), vv.pb(c+1);

		if(!(hcut == h+1 and hsum == 0 and vcut == v+1 and vsum == 0)){
			printf("Case #%d: IMPOSSIBLE\n", caso);
			continue;
		}

		// for(int i = 1; i < vh.size(); i++){
		// 	printf("%d ", vh[i]);
		// }
		// printf("\n");

		// for(int i = 1; i < vv.size(); i++){
		// 	printf("%d ", vv[i]);
		// }
		// printf("\n");


		bool ok = 1;
		for(int i = 1; i <= h+1; i++){
			for(int j = 1; j <= v+1; j++){
				int subsum = 0;
				for(int k = vh[i-1]+1; k <= vh[i]; k++){ // onde termina o ultimo + 1
					for(int l = vv[j-1]+1; l <= vv[j]; l++){ // mesma coisa para as colunas
						if(g[k][l] == '@'){
							subsum++;
						}
					}
				}
				// printf("subsum = %d\n", subsum);
				if(subsum != tot/((h+1)*(v+1))){
					ok = 0;
				}
			}
		}

		if(ok){
			printf("Case #%d: POSSIBLE\n", caso);			
		}
		else{
			printf("Case #%d: IMPOSSIBLE\n", caso);
		}
	}

	return 0;
}