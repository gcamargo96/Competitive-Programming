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

const int N = 200005;
int v[N];
int t, n, k;
ll acum[N];


int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &k);

		bool allNegative = 1;
		int maX = -1000000000;
		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
			
			if(v[i] >= 0){
				allNegative = 0;
			}
			maX = max(maX, v[i]);
		}

		if(allNegative){
			printf("%d\n", maX);
			continue;
		}

		for(int i = n+1; i <= min(2,k)*n; i++){
			v[i] = v[i-n];
		}

		memset(acum, 0, sizeof acum);
		for(int i = 1; i <= min(2,k)*n; i++){
			acum[i] = acum[i-1] + v[i];
		}

		ll ans1 = acum[n] * ll(k);

		// tratando as bordas
		pair<ll, int> best;
		best = mp(0,0);
		for(int i = 1; i <= n; i++){
			if(acum[i] < best.fi){
				best = mp(acum[i], i);
			}
		}
		ans1 -= best.fi;

		pair<ll, int> best2;
		best2 = mp(0LL,0);
		int lim = (k > 1 ? 1 : best.se+1);
		for(int i = n; i >= lim; i--){
			if(acum[n] - acum[i-1] < best2.fi){
				best2 = mp(acum[n] - acum[i-1], i);
			}
		}
		ans1 -= best2.fi;

		// printf("ans1 = %lld\n", ans1);

		ll ans2 = 0;
		set<pair<ll, int> > s;
		s.insert(mp(0LL, 0));
		for(int i = 1; i <= min(2,k)*n; i++){
			auto it = s.begin();

			ll sum = acum[i] - it->fi;
			ans2 = max(ans2, sum);
			s.insert(mp(acum[i], i));
		}

		ll ans = max(ans1, ans2);
		printf("%lld\n", ans);
	}

	return 0;
}