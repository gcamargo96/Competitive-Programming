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
	double x, y, ang;
};

const int N = 100002;
int n;
point p[N];

bool cmp(point a, point b){
	return a.ang < b.ang;
}

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%lf%lf", &p[i].x, &p[i].y);
		p[i].ang = atan2(p[i].y, p[i].x);
	}

	sort(p, p+n, cmp);

	double res = INF, dif, comp;
	For(i,0,n-1){
		dif = p[i+1].ang - p[i].ang;
		comp = 2*acos(-1) - dif;
		res = min(res, comp);
	}
	dif = 2*acos(-1) - abs(p[0].ang - p[n-1].ang);
	comp = 2*acos(-1) - dif;
	res = min(res, comp);

	if(n == 2) res = min(dif, comp);

	printf("%lf\n", (res)*(180/acos(-1)));

	return 0;
}

