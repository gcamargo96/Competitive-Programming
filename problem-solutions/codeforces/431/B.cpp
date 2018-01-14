#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mk make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define EPS 1e-7
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll gcd (ll a, ll b) {
	if (!b)
		return a;
	else
		return gcd(b, a%b);
}

class Point {
public:
	double x, y;

	Point () { }

	Point (double x, double y) {
		this->x = x;
		this->y = y;
	}

	/**/
	bool operator == (const Point &b) const {
		return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
	}

	/**/
	bool operator < (const Point &b) const {
		return ((x < b.x) or ((x == b.x) and y < b.y));
	}

	//Produto vetorial
	double operator ^ (const Point &b) const {
		return (this->x * b.y) - (this->y * b.x); 
	}

	//Produto escalar
	double operator * (const Point &b) const {
		return (this->x * b.x) + (this->y * b.y);
	}

	/**/
	Point operator * (double k) {
		return Point (x*k, y*k);
	}

	Point operator / (double k) {
		if (k == 0.0) cout << "Class Point (operador /): divisao por zero" << endl;
		return Point (x/k, y/k);
	}
	
	/**/
	Point operator + (const Point &b) const {
		return Point (x + b.x, y + b.y);
	}

	/**/
	Point operator - (const Point &b) const {
		return Point (x - b.x, y - b.y);
	}

	/**/
	double len () {
		return sqrt (x*x + y*y);
	}

	/*Distancia ponto a ponto*/
	double dpp (const Point &b) {
		return ((*this)-b).len();
	}

	/*Projecao*/
	double proj (Point &b) {
		return ((*this)*b)/(b.len()*b.len());
	}

	Point norm () {
		return Point (x/this->len(), y/this->len());
	}

	/*Retorna o vetor perpendicular ao vetor (0,0) -> (Point)
	Sentido clockwise*/
	Point perp () {
		return Point (this->y, -1.0 * this->x);
	}

	// Distancia do ponto p ao segmento ab, tambem retorna por 
	// referencia o ponto (c) do segmento mais perto de p
	double distToLine (const Point a, const Point b, Point& c) {
		// formula: c = a + u * ab
		Point p = *this;
		if (a == b) return p.dpp(a);
		Point ap = Point(p - a), ab = Point(b - a);
		double u = ap.proj(ab);
		if (u < 0.0) u = 0.0;
		if (u > 1.0) u = 1.0;
		c = a + ab * u;
		return p.dpp(c);
	}

	/**/
	Point rotaciona (double ang) {
		double c = cos(ang), s = sin(ang);
		double X = x*c - y*s;
		double Y = x*s + y*c;
		return Point(X,Y);
	}

	/*area de um poligono concavo ou convexo
	dado vetor de vertices ordenados clockwise ou
	counter clockwise*/
	static double area (vector <Point> v) {
		double area = 0.0;
		for (int i = 0; i < (int)v.size(); i++) 
			area += v[i] ^ v[(i+1)%v.size()];
		return abs(area/2.0);
	}

	/**/
	static vector <Point> convex_hull (vector <Point> p) {
		if (p.size() <= 2) return p;

		int n = p.size(), k = 0;
		vector <Point> H(2*n);

		sort(p.begin(), p.end());

		for (int i = 0; i < n; i++) {
			while (k >= 2 and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
			H[k++] = p[i];
		}

		for (int i = n-2, t = k+1; i >= 0; i--) {
			while (k >= t and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
			H[k++] = p[i];
		}

		H.resize(k-1);

		return H;
	}
	
	/*Angulo em forma de fracao reduzida entre o vetor Op (p é o ponto)
	 e o eixo x, se paralelo ao eixo x retorna (1,0) ou (-1,0)
	 se paralelo ao eixo y retorna (0,1) ou (0,-1)
	 SÓ FUNCIONA PARA PONTOS INTEIROS*/ 
	static ii ang (Point p) {
		int a = p.x, b = p.y;
		if (a == 0) return mk(0, b/abs(b));
		else if (b == 0) return mk(a/abs(a), 0);
		return mk(a/gcd(a,b), b/gcd(a,b));
	}

	/*Interseccao de dois vetores somandos a pontos*/
	static double inter (Point p1, Point v1, Point p2, Point v2) {
		if (abs(v2 ^ v1) >= EPS) {
			Point c = p1 - p2;
			return (c ^ v2)/(v2 ^v1);
		} else {
			cout << "Class Point (funcao inter): retas paralelas" << endl;
			cout << "Talvez deva ajustar o EPS" << endl;
		}
		return 0.0;
	}

	/*Retorna o retangulo (pontos em anti clockwise) que tem a menor valor
	min(Xmax -Xmin, Ymax - Ymin)*/
	static vector <Point> minRetangulo (vector <Point> v) {
		vector <Point> at;
		at.pb(Point(-1e18, -1e18));
		at.pb(Point(1e18, -1e18));
		at.pb(Point(1e18, 1e18));
		at.pb(Point(-1e18, 1e18));
		v = convex_hull(v);
		int n = v.size();
		for (int i = 0; i < n; i++) {
			int j = (i+1)%n;
			Point vec = v[j] - v[i];
			double ang = atan2(vec.y, vec.x);
			vector <Point> ve;
			for (int j = 0; j < n; j++) {
				ve.pb(v[j].rotaciona(ang));
			}
			double minx = DBL_MAX, miny = DBL_MAX, maxx = -DBL_MAX, maxy = -DBL_MAX;
			for (int j = 0; j < n; j++) {
				if (ve[j].x < minx) minx = ve[j].x;
				if (ve[j].x > maxx) maxx = ve[j].x;
				if (ve[j].y < miny) miny = ve[j].y;
				if (ve[j].y > maxy) maxy = ve[j].y;
			}
			double mini = min(maxx - minx, maxy - miny);
			if (mini < min(at[2].x - at[0].x, at[2].y - at[0].y)) {
				at.clear();
				at.pb(Point(minx, miny));
				at.pb(Point(maxx, miny));
				at.pb(Point(maxx, maxy));
				at.pb(Point(minx, maxy));
			}
		}

		return at;
	}
};

const int N = 1002;
Point p[N];
map<ii, int> angs;
int n;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%lf", &p[i].y);
		p[i].x = (double)i+1;
	}

	for(int i = 1; i < n; i++){
		Point paux = p[i]-p[0];
		ii ang = Point::ang(paux);
		angs[ang]++;
	}

	for(int i = 1; i < n; i++){
		for(int j = i+1; j < n; i++){
			Point paux = p[i]-p[0];
			ii ang = Point::ang(paux);
			
		}
	}

	return 0;
}