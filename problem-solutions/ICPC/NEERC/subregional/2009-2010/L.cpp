#include <bits/stdc++.h>

using namespace std;

#define mk make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

typedef pair<int, int> ii;
typedef long long ll;
const double EPS = 1e-9;
const double PI = acos(-1.0);

class Point {
public:
	int x, y;

	Point () { }

	Point (int x, int y) {
		this->x = x;
		this->y = y;
	}

	Point operator - (const Point& b) const{
		return Point(this->x - b.x, this->y - b.y);
	}

	int operator * (const Point& b) const {
		return (this->x * b.x) + (this->y * b.y);
	}

	bool operator == (const Point& b) const{
		return x == b.x and y == b.y;
	}

};

const int N = 5005;
int n;
vector<Point> p;

int main (void) {
	freopen("lshape.in", "r", stdin);
	freopen("lshape.out", "w", stdout);
	
	scanf("%d", &n);

	int X1, Y1, X2, Y2;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
		p.eb(X1, Y1);
		p.eb(X2, Y2);
	}

	int ans = 0;
	for(int i = 0; i < 2*n; i += 2){
		for(int j = i+2; j < 2*n; j += 2){
			if(p[i] == p[j] or p[i+1] == p[j] or p[i] == p[j+1] or p[i+1] == p[j+1]){
				Point u = p[i+1] - p[i];
				Point v = p[j+1] - p[j];

				if((u*v) == 0){
					ans++;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}