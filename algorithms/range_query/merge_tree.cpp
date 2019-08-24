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

const int N = 500005;

ll acc[N];
vector<ll> seg[4 * N];
int a, b;
ll x, y;

void build_seg(int p, int l, int r) {
	if(l == r) {
		seg[p].pb(acc[l]);
	} else {
		int mid = (l + r)/2;
		build_seg(2 * p, l, mid);
		build_seg(2 * p + 1, mid+1, r);
 
		seg[p].resize(r - l + 1);
		merge(seg[2 * p].begin(), seg[2 * p].end(), seg[2 * p + 1].begin(), seg[2 * p + 1].end(), seg[p].begin());
	}
 
}
 
int query(int p, int l, int r) {
	if(l > b or r < a) return 0;
	if(l >= a and r <= b) {
		int i = upper_bound(seg[p].begin(), seg[p].end(), y) - seg[p].begin();
		int j = lower_bound(seg[p].begin(), seg[p].end(), x) - seg[p].begin();
		return max(0, i - j);
	}

	int mid = (l + r)/2;
	return query(2 * p, l, mid) + query(2 * p + 1, mid+1, r);
}