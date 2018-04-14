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

struct Point{
	double x, y;

	Point() {} 

	Point(double _x, double _y){
		x = _x;
		y = _y;
	}

	double operator^(const Point& b) const{
		return x*b.y - y*b.x;
	}

};

int n;
vector<Point> p;

double area(vector<Point>& v){
	double a = 0;
	for(int i = 0; i < v.size(); i++){
		a += v[i] ^ v[(i+1)%v.size()];
	}
	return abs(a/2.0);
}

int main(void){
	scanf("%d", &n);

	double x, y;
	for(int i = 0; i < n; i++){
		scanf("%lf%lf", &x, &y);
		p.emplace_back(x,y);
	}

	double ans = area(p);
	printf("%lf\n", ans);

	return 0;
}