#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define Rightl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200002;
set<ii> len, ini;
int v[N];
int n;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	int l, r;
	for(int i = 1; i <= n; i++){
		if(v[i] != v[i-1]){
			l = i;
		}
		if(v[i] != v[i+1]){
			r = i;
			len.insert(ii(-(r-l+1), l));
			ini.insert(ii(l, r-l+1));
		}
	}

	// for(ii x : len){
	// 	printf("%d %d\n", x.fi, x.se);
	// }
	// printf("\n");
	// for(ii x : ini){
	// 	printf("%d %d\n", x.fi, x.se);
	// }

	int ans = 0;
	while(!len.empty()){
		auto cur = len.begin();
		auto L = ini.lower_bound(ii(cur->se, -cur->fi));
		auto R = ini.lower_bound(ii(cur->se, -cur->fi));

		// printf("%d %d\n", cur->fi, cur->se);

		if(L != ini.begin() and R != ini.end()){
			L--, R++;
			if(R != ini.end() and v[L->fi] == v[R->fi]){
				len.insert(ii(-(L->se + R->se), L->fi));
				ini.insert(ii(L->fi, L->se + R->se));

				len.erase(ii(-L->se, L->fi));
				len.erase(ii(-R->se, R->fi));

				ini.erase(L);
				ini.erase(R);
			}
		}

		ini.erase(ii(cur->se, -cur->fi));	
		len.erase(cur);

		ans++;
	}

	printf("%d\n", ans);

	return 0;
}