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

#define INF 0x3f3f3f3f
#define U 0
#define D 1
#define P 2

const int N = 1000005;
int t, n;
int v[N];

int main(void){
	freopen("dales.in", "r", stdin);
	freopen("dales.out", "w", stdout);

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}

		vector<ii> hills;
		for(int i = 0; i < n-1; ){
			int lenU = 0, lenD = 0, lenP = 0;

			while(i < n-1 and v[i] == v[i+1]){
				lenP++;
				i++;
			}
			if(lenP > 0){
				hills.eb(lenP, P);
			}

			while(i < n-1 and v[i] < v[i+1]){
				lenU++;
				i++;
			}

			if(lenU > 0){
				hills.eb(lenU, U);
			}

			while(i < n-1 and v[i] > v[i+1]){
				lenD++;
				i++;
			}

			if(lenD > 0){
				hills.eb(lenD, D);
			}
		}

		// for(int i = 0; i < int(hills.size()); i++){
		// 	printf("seq %d %d\n", hills[i].fi, hills[i].se);
		// }

		int hill = 0, dale = 0;
		for(int i = 0; i < int(hills.size())-1; i++){
			// printf("%d %d\n", hills[i].fi, hills[i+1].fi);
			if(hills[i].se == U and hills[i+1].se == D){
				hill = max(hill, min(hills[i].fi, hills[i+1].fi));
			}
			if(hills[i].se == D and hills[i+1].se == U){
				dale = max(dale, min(hills[i].fi, hills[i+1].fi));
			}
		}

		printf("%d %d\n", hill, dale);
	}

	return 0;
}