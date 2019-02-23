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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int t, n, k;
ii v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &k);
	
		for(int i = 0; i < n; i++){
			scanf("%d%d", &v[i].fi, &v[i].se);
		}

		if(k == 1){
			int ans = 0;
			for(int i = 0; i < n; i++){
				ans = max(ans, v[i].se-v[i].fi);
			}
			printf("%d\n", ans);
			continue;
		}

		sort(v, v+n);

		int l = 1;
		multiset<int> s;
		for(int i = 0; i < k-1; i++){
			l = v[i].fi;
			s.insert(v[i].se);
		}

		int ans = 0;
		for(int i = k-1; i < n; i++){
			l = v[i].fi;

			// auto it = s.end();
			// it--;
			auto it = s.begin();
			int r = min(*it, v[i].se);
			ans = max(ans, r-l);

			// printf("l = %d, r = %d\n", l, r);

			if(v[i].se > *s.begin()){
				s.erase(s.begin());
				s.insert(v[i].se);
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}