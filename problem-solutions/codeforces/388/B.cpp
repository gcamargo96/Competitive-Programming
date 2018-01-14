#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

struct point{
	int x, y;

	bool operator<(const point& b) const{
		if(x == b.x) return y < b.y;
		return x < b.x;
	}
};

point a, b, c;

int main(void){
	scanf("%d%d", &a.x, &a.y);
	scanf("%d%d", &b.x, &b.y);
	scanf("%d%d", &c.x, &c.y);

	point d;
	set<point> res;

	d.x = a.x + (b.x-a.x) + (c.x-a.x);
	d.y = a.y + (b.y-a.y) + (c.y-a.y);
	res.insert(d);

	d.x = b.x + (a.x-b.x) + (c.x-b.x);
	d.y = b.y + (a.y-b.y) + (c.y-b.y);
	res.insert(d);

	d.x = c.x + (a.x-c.x) + (b.x-c.x);
	d.y = c.y + (a.y-c.y) + (b.y-c.y);
	res.insert(d);

	printf("%d\n", res.size());
	for(auto it = res.begin(); it != res.end(); it++){
		printf("%d %d\n", it->x, it->y);
	}

	return 0;
}

