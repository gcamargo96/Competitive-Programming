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

struct Point {
	ll x, y;
	int id;

	Point() {}

	Point(ll X, ll Y, int ID){
		x = X;
		y = Y;
		id = ID;
	}

	Point operator-(const Point& b) const{
		return Point(x-b.x, y-b.y, b.id);
	}

	ll operator^(const Point& b) const{
		return x*b.y - b.x*y;
	}

	bool operator <(const Point &p) const {
		if(x == p.x) return y < p.y;
		return x < p.x;
	}
};

ll cross(const Point &O, const Point &A, const Point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

const int N = 100005;
vector<Point> seg[4*N];
Point p[N];
int t, n;
int a, b;
Point p1, p2;

vector<Point> convex_hull(vector<Point> P){
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	sort(P.begin(), P.end());

	// Upper hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) > 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}

vector<Point> subvec(int l, int r){
	vector<Point> v;
	for(int i = l; i <= r; i++){
		v.pb(p[i]);
	}
	return v;
}

void build(int R, int l, int r){
	if(l == r){
		seg[r].pb(p[l]);
		return;
	}
	
	int mid = (l+r)/2;
	build(2*R, l, mid);
	build(2*R+1, mid+1, r);

	seg[r].clear();
	seg[r] = convex_hull(subvec(l, r));

	// printf("l = %d, r = %d:\n", l, r);
	// for(int i = 0; i < seg[r].size(); i++){
	// 	printf("(%lld,%lld,%lld) ", seg[r][i].x, seg[r][i].y, seg[r][i].id);
	// }
	// printf("\n");
}

int bin_search(vector<Point>& h){
	int lo = 1, hi = h.size()-1, id = 0;
	Point u = p2-p1;

	while(lo <= hi){
		int mid = (lo+hi)/2;
		Point v = h[mid] - h[mid-1];

		if((u^v) > 0){
			id = mid;
			lo = mid+1;
		}
		else{
			hi = mid-1;
		}
	}

	return ((p2-p1)^(h[id]-p1)) > 0;
}

int search_on_tree(int R, int l, int r){
	if(l > b or r < a){
		return 0;
	}

	if(!bin_search(seg[r])){
		return 0;
	}

	if(l == r){
		if(((p2-p1)^(p[l]-p1)) > 0)
			return l-1;
		return 0;
	}
	
	int mid = (l+r)/2;
	int L = search_on_tree(2*R, l, mid);
	
	if(L != 0) return L;
	return search_on_tree(2*R+1, mid+1, r);
}

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 1; i <= n; i++){
			scanf("%lld%lld", &p[i].x, &p[i].y);
			p[i].id = i;
		}

		build(1, 1, n);

		for(int i = 2; i < n; i++){
			p2 = p[i], p1 = p[i-1];
			
			a = i+1, b = n;
			int ans = search_on_tree(1, 1, n);
		
			printf("%d ", ans);
		}
		printf("0\n");
	}

	return 0;
}