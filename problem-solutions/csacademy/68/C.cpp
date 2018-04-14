#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct Point{
  long long x, y;
  int id;

  Point() {}

  Point(long long _x, long long _y){
    x = _x;
    y = _y;
  }

  Point(long long _x, long long _y, int _id){
    x = _x;
    y = _y;
    id = _id;
  }


  Point operator-(const Point& b) const{
    return Point(b.x-x, b.y-y);
  }

  Point operator+(const Point& b) const{
    return Point(x + b.x, y + b.y);
  }

  long long operator*(const Point& b) const{
    return x*b.x + y*b.y;
  }

  long long operator^(const Point& b) const{
    return x*b.y - b.x*y;
  }

  long double len(){
    return hypot((long double) x,(long double) y);//sqrt(x*x + y*y);
  }

  bool operator<(const Point& b) const{
    if(x == b.x)
      return y < b.y;
    return x < b.x;
  }
};

const int N = 100002;
Point p0(0,0);
int n;
vector<Point> p;
int bit[N], ans[N];

bool ccw(Point a, Point b){
  long long cross = (a-p0)^(b-p0);
  if(cross == 0)
    return a.x < b.x;
  return cross > 0;
}

long long cross(Point o, Point a, Point b){
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void update(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}


int main(void){
	scanf("%d", &n);

	int x, y;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &x, &y);
		p.emplace_back(x, y, i);
	}

	sort(p.begin(), p.end(), ccw);

	for(int i = 0; i < p.size(); i++){
		ans[p[i].id] = query(p[i].x);
		update(p[i].x, 1);
	}

	for(int i = 0; i < n; i++){
		printf("%d\n", ans[i]);
	}

	return 0;
}