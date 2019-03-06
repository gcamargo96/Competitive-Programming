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
	ll x, y;

	Point () { }

	Point (ll x, ll y) {
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
	ll operator ^ (const Point &b) const {
		return (this->x * b.y) - (this->y * b.x); 
	}

	//Produto escalar
	ll operator * (const Point &b) const {
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
};

const int N = 100005;
int n, p;
Point points[N];

bool check(int id1, int id2){
	// printf("id1 = %d, id2 = %d\n", id1, id2);
	Point u = points[id2]-points[id1];
	// printf("u = %d %d\n", u.x, u.y);

	int cnt = 2;
	for(int i = 0; i < n; i++){
		if(i == id1 or i == id2) continue;
		
		Point v = points[i] - points[id1];
		if((u^v) == 0){
			// printf("bateu com %d\n", i);
			// printf("v = %d %d\n", v.x, v.y);
			cnt++;
		}
	}

	// printf("percentage = %lf\n", double(cnt)/double(n));

	return cnt*100 >= n*p;
}

int main (void) {
	srand(time(NULL));
	scanf("%d%d", &n, &p);

	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &points[i].x, &points[i].y);
	}


	for(int i = 0; i < 250; i++){
		random_shuffle(points, points+n);
		int id1 = 0;
		int id2 = 1;
		// while(id2 == id1) id2 = rand()%n;

		if(check(id1, id2)){
			printf("possible\n");
			return 0;
		}
	}

	printf("impossible\n");

	return 0;
}