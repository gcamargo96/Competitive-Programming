#include <bits/stdc++.h>

using namespace std;

#define mk make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int, int> ii;
typedef long long ll;
const double EPS = 1e-9;
const double PI = acos(-1.0);

ll gcd (ll a, ll b) {
	if (!b)
		return a;
	else
		return gcd(b, a%b);
}

class Point {
public:
	int x, y;

	Point () { }

	Point (int x, int y) {
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
	int operator ^ (const Point &b) const {
		return (this->x * b.y) - (this->y * b.x); 
	}

	//Produto escalar
	int operator * (const Point &b) const {
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
	int len () {
		return sqrt (x*x + y*y);
	}

	/*Distancia ponto a ponto*/
	int dpp (const Point &b) {
		return ((*this)-b).len();
	}

	Point norm () {
		return Point (x/this->len(), y/this->len());
	}
};

const int N = 1005;
int W, P;
Point w[N], p[N];
vector<int> adj[N];
int s[N], color[N];

bool intersect(Point p1, Point q1, Point p2, Point q2){
	Point u = q1-p1;
	Point v = p2-q1;
	Point w = q2-q1;

	int cross1 = u^v;
	int cross2 = u^w;

	u = q2-p2;
	v = p1-q2;
	w = q1-q2;

	int cross3 = u^v;
	int cross4 = u^w;

	if(cross1 == 0 or cross2 == 0 or cross3 == 0 or cross4 == 0)
		return 0;

	cross1 /= abs(cross1);
	cross2 /= abs(cross2);
	cross3 /= abs(cross3);
	cross4 /= abs(cross4);

	if(cross1 != cross2 and cross3 != cross4){
		return 1;
	}

	return 0;
}

bool dfs(int u, int cor){
	color[u] = cor;

	bool ret = 1;
	for(int v : adj[u]){
		if(color[v] == color[u]) return 0;
		if(color[v] == 0) ret &= dfs(v, cor == 1 ? 2 : 1);
	}

	return 1;
}

int main (void) {
	scanf("%d%d", &W, &P);

	for(int i = 1; i <= W; i++){
		scanf("%d%d", &w[i].x, &w[i].y);
	}

	
	for(int i = 1; i <= P; i++){
		scanf("%d%d%d", &s[i], &p[i].x, &p[i].y);
	}

	for(int i = 1; i <= P; i++){
		for(int j = i+1; j <= P; j++){
			if(intersect(w[s[i]], p[i], w[s[j]], p[j])){
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
	}

	bool ok = 1;
	for(int i = 1; i <= P; i++){
		if(!color[i])
			ok &= dfs(i, 1);
	}

	if(ok)
		printf("possible\n");
	else
		printf("impossible\n");

	return 0;
}