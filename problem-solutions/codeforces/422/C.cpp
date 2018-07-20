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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200005;
int n, x;
vector<ii> tam[N];
vi menor[N];

int main(void){
	scanf("%d%d", &n, &x);

	int l, r, c;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &l, &r, &c);
		tam[r-l+1].pb(ii(l, c));
	}

	for(int i = 1; i < N; i++){
		sort(tam[i].begin(), tam[i].end());
		
		int len = tam[i].size();
		menor[i].resize(len);

		if(len > 0) menor[i][len-1] = tam[i][len-1].se;
		for(int j = len-2; j >= 0; j--){
			menor[i][j] = min(menor[i][j+1], tam[i][j].se);
		}
	}

	// printf("\n");
	// for(int j = 0; j < menor[3].size(); j++){
	// 	printf("%d ", menor[3][j]);
	// }
	// printf("\n");

	int ans = INT_MAX;
	for(int i = 1; i < N; i++){
		int len = tam[i].size();
		for(int j = 0; j < len; j++){
			int comp = x-i;
			if(comp <= 0) continue;

			auto it = lower_bound(tam[comp].begin(), tam[comp].end(), ii(tam[i][j].fi+i, -1));
			if(it == tam[comp].end()) continue;

			int pos = it-tam[comp].begin();
			// printf("%d %d %d %d\n", i, j, comp, pos);
			ans = min(ans, tam[i][j].se + menor[comp][pos]);
		}
	}

	if(ans != INT_MAX){
		printf("%d\n", ans);
	}
	else{
		printf("-1\n");
	}

	return 0;
}