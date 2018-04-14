#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
// typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define ldb long double

const ldb EPS = 1e-6;

struct Point{
	ldb x, y;

	Point () { }

	Point (ldb x, ldb y) {
		this->x = x;
		this->y = y;
	}

	bool operator == (const Point &b) const {
		return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
	}

	Point operator * (ldb k) {
		return Point (x*k, y*k);
	}

	Point operator + (const Point &b) const {
		return Point (x + b.x, y + b.y);
	}

	Point operator - (const Point &b) const {
		return Point (x - b.x, y - b.y);
	}

	Point operator / (ldb k) {
		// if (k == 0.0) cout << "Class Point (operador /): divisao por zero" << endl;
		return Point (x/k, y/k);
	}

	ldb len () {
		return sqrt (x*x + y*y);
	}

	ldb dpp (const Point &b) {
		return ((*this)-b).len();
	}

	Point norm () {
		return Point (x/this->len(), y/this->len());
	}
};

int R;
Point p1, p2, pap;
ldb Rap;

int main(void){
	int x1, y1, x2, y2;
	scanf("%d%d%d%d%d", &R, &x1, &y1, &x2, &y2);
	p1 = Point(x1, y1);
	p2 = Point(x2, y2);

	if(p1.dpp(p2) > (ldb)R){
		printf("%.10Lf %.10Lf %d\n", p1.x, p1.y, R);
		return 0;
	}

	if(x1 == x2 and y1 == y2){
		Rap = (ldb)(R)/2.0;
		pap.x = p1.x + Rap;
		pap.y = p1.y;
		printf("%.10Lf %.10Lf %.10Lf\n", pap.x, pap.y, Rap);
		return 0;
	}

	Rap = (p1.dpp(p2) + (ldb)(R))/2.0;
	Point pnorm = (p1-p2).norm();
	pap = p2 + (pnorm * Rap);

	printf("%.10Lf %.10Lf %.10Lf\n", pap.x, pap.y, Rap);

	return 0;
}