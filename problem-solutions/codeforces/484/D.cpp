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

const int N = 100005;
int n;
ii v[N];
set<ii> seg;
set<int> sizes;
int cnt[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i].fi);
		v[i].se = i;
	}

	sort(v, v+n, greater<ii>());

	int ans = v[0].fi+1;

	seg.insert(ii(0, n-1));
	cnt[n] = 1;
	int best_size = 0;

	for(int i = 0; i < n; i++){
		auto it = seg.upper_bound(ii(v[i].se, v[i].se));

		// if(it == seg.begin()){
		// 	printf("vai dar pau\n");
		// }

		if(it == seg.end() or it->fi > v[i].se){
			it--;
		}


		ii cur = *it;
		seg.erase(it);
		int sz = cur.se-cur.fi+1;
		cnt[sz]--;
		if(cnt[sz] == 0) sizes.erase(sz);

		if(v[i].se == cur.fi){
			if(sz-1 > 0){
				seg.insert(ii(cur.fi+1, cur.se));
				cnt[sz-1]++;
				sizes.insert(sz-1);
			}
		}
		else if(v[i].se == cur.se){
			if(sz-1 > 0){
				seg.insert(ii(cur.fi, cur.se-1));
				cnt[sz-1]++;
				sizes.insert(sz-1);
			}
		}
		else{
			int sz1 = v[i].se-1 - cur.fi + 1;
			int sz2 = cur.se - (v[i].se+1) + 1;

			if(sz1 > 0){
				seg.insert(ii(cur.fi, v[i].se-1));
				cnt[sz1]++;
				sizes.insert(sz1);
			}
			if(sz2 > 0){
				seg.insert(ii(v[i].se+1, cur.se));
				cnt[sz2]++;
				sizes.insert(sz2);
			}
		}

		if(sizes.size() == 1 and cnt[*sizes.begin()] >= best_size and i < n-1){
			ans = v[i+1].fi+1;
			// printf("size = %d\n", *sizes.begin());
			best_size = cnt[*sizes.begin()];
			// printf("best size = %d\n", best_size);
		}
	}


	printf("%d\n", ans);

	return 0;
}