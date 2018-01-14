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

map<ii, set<ii> > interests;
vector<tuple<int, int, int, int, int, int, int> > ans;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		int a,b,c,d;
		scanf("%d%d%d%d", &a, &b, &c, &d);

		interests[mp(a,b)].insert(mp(c,d));
	}

	for (int i = 0; i < m; i++) {
		int a,b,c,d,e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		auto it = interests[mp(a,b)].lower_bound(mp(d, 0));
		if (it == interests[mp(a,b)].begin()) continue;
		it--;
		int time = (*it).first;
		
		if (d > time) {
			ans.push_back(make_tuple((*it).second, a,b,time,c, d, e));
		}
	}

	sort (ans.begin(), ans.end());

	printf("%d\n",ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d %d %d %d %d %d\n", get<1>(ans[i]), get<2>(ans[i]), get<3>(ans[i]), get<0>(ans[i]),
				get<4>(ans[i]), get<5>(ans[i]), get<6>(ans[i]));
	}

	return 0;
}
