#include <bits/stdc++.h>
using namespace std;

#define ll long long
const double PI = acos(-1.0);


struct Point{
	ll x, y;

	Point() {}

	Point(ll a, ll b){
		x = a;
		y = b;
	}

	bool operator<(const Point &b) const{
		return x < b.x or (x == b.x and y < b.y);
	}

	ll operator^(const Point &b) const{
		return x*b.y - y*b.x;
	}

	ll norm(){
		return ((x*x)+(y*y));
	}

	Point operator-(const Point &b) const{
		return Point(x-b.x, y-b.y);
	}
};

ll cross(const Point &o, const Point &a, const Point &b){
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

vector <Point> convex_hull(vector<Point> &v){
	int n = v.size();
	int k = 0;
	vector<Point> hull(2*n);

	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++){
		while(k >= 2 and cross(hull[k-2], hull[k-1], v[i]) <= 0) k--;
		hull[k++] = v[i];
	}

	for(int i = n-2, t = k+1; i >= 0; i--){
		while(k >= t and cross(hull[k-2], hull[k-1], v[i]) <= 0) k--;
		hull[k++] = v[i];
	}

	hull.resize(k-1);
	return hull;
}

ll calipers(vector <Point> &hull){
	int p1 = 0, p2 = 1;
	ll maxdist = 0;

	do{
		int p1nxt = (p1-1+hull.size())%hull.size();
		Point v1 = hull[p1nxt]-hull[p1];
		int p2nxt = (p2-1+hull.size())%hull.size();
		Point v2 = hull[p2nxt]-hull[p2];
		while((v1^v2) < 0){
			p2 = (p2-1+hull.size())%hull.size();
			p2nxt = (p2-1+hull.size())%hull.size();
			v2 = hull[p2nxt]-hull[p2];
		}
		maxdist = max(maxdist, (hull[p1]-hull[p2]).norm());
		maxdist = max(maxdist, (hull[p1]-hull[p2nxt]).norm());
		maxdist = max(maxdist, (hull[p1nxt]-hull[p2]).norm());
		maxdist = max(maxdist, (hull[p1nxt]-hull[p2nxt]).norm());
		p1 = (p1-1+hull.size())%hull.size();
	}while(p1);

	return maxdist;
}

int t, n;

int main(void){
	scanf("%d", &t);

	for(int c = 1; c <= t; c++){
		scanf("%d", &n);
		vector <Point> all;
		ll x, y;
		Point p;
		for(int i = 0; i < n; i++){
			ll x, y;
			scanf("%lld%lld", &x, &y);
			p.x = x, p.y = y;
			all.push_back(p);
		}
	
		if(n <= 1){
			printf("0\n");
			continue;
		}

		vector <Point> hull = convex_hull(all);
		ll res = calipers(hull);
		printf("%lld\n", res);
	}

	return 0;
}
