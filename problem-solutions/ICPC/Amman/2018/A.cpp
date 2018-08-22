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

struct seg{
	int l, r, v;

	seg() {}

	seg(int _l, int _r, int _v){
		l = _l;
		r = _r;
		v = _v;
	}

	bool operator<(const seg& b) const{
		return l < b.l;
	}
};

int t;
int m, k;
vector<seg> v;

int main(void){
	scanf("%d", &t);

	while(t--){
		v.clear();
		scanf("%d%d", &m, &k);

		int l, r, val;
		v.eb(0,0,0);
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &l, &r, &val);
			v.eb(l,r,val);
		}

		sort(v.begin(), v.end());

		int j = 1;
		ll cur = 0, ans = 0;
		for(int i = 1; i <= m; i++){
			j = max(i, j);

			int rr = v[i].l;
			while(j <= m and (j == i or v[j-1].r+1 == v[j].l) and v[i].l+k-1 >= v[j].l){ //v[j].r - v[i].l + 1 <= k){
				// cur += ll(v[j].r-v[j].l+1)*ll(v[j].v);
				rr = min(v[i].l+k-1, v[j].r);
				cur += ll(rr-v[j].l+1) * ll(v[j].v);
				ans = max(ans, cur);
				j++;
			}

			// printf("%d %d %lld\n", v[i].l, rr, cur);

			cur -= ll(min(v[i].r, rr) - v[i].l + 1) * ll(v[i].v);
		}

		j = m, cur = 0;
		for(int i = m; i >= 1; i--){
			j = min(i, j);

			int le = v[i].r;
			while(j >= 1 and (j == i or v[j+1].l-1 == v[j].r) and v[i].r-k+1 <= v[j].r){ //v[j].r - v[i].l + 1 <= k){
				// cur += ll(v[j].r-v[j].l+1)*ll(v[j].v);
				le = max(v[i].r-k+1, v[j].l);
				cur += ll(v[j].r-le+1) * ll(v[j].v);
				ans = max(ans, cur);
				j--;
			}

			// printf("%d %d %lld\n", le, v[i].r, cur);

			cur -= ll(v[i].r - max(v[i].l, le) + 1) * ll(v[i].v);
		}


		printf("%lld\n", ans);
	}

	return 0;
}