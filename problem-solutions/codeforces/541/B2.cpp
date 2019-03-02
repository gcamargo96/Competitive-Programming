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

int n;
ii last, cur;
unordered_set<int> s;

int main(void){
	scanf("%d", &n);

	last = ii(0,0);
	int ans = 1;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &cur.fi, &cur.se);

		int l = max(last.fi, last.se);
		int r = min(cur.fi, cur.se);

		if(r-l+1 > 0){
			ans += r-l+1;
			ans -= s.count(l);
		}

		if(cur.fi == cur.se) s.insert(cur.fi);
		last = cur;
	}

	printf("%d\n", ans);

	return 0;
}