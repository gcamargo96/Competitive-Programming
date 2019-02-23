#include <bits/stdc++.h>
using namespace std;
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

struct point{
	int x, y;

	point() {}

	point(int _x, int _y){
		x = _x;
		y = _y;
	}

	bool operator<(const point& b) const{
		if(x == b.x)
			return y < b.y;
		return x < b.x;
	}
};

struct frac{
    long long num, den;
    frac() : num(0), den(1) { };
    frac(long long num, long long den) { set_val(num, den); }
    frac(long long num) : num(num), den(1) { };

    void set_val(long long _num, long long _den){
        num = _num/__gcd(_num, _den);
        den = _den/__gcd(_num, _den);
        if(den < 0) { num *= -1; den *= -1; }
    }



    void operator*=(frac f) { set_val(num * f.num, den * f.den); }
    void operator+=(frac f) { set_val(num * f.den + f.num * den, den * f.den); }
    void operator-=(frac f) { set_val(num * f.den - f.num * den, den * f.den); }
    void operator/=(frac f) { set_val(num * f.den, den * f.num); }
};


bool operator < (frac a, frac b)
{
    if((a.den < 0) ^ (b.den < 0)) return a.num * b.den > b.num * a.den;
    return a.num * b.den < b.num * a.den;
}

std::ostream& operator<<(std::ostream& o, const frac f)
{
    o << f.num << "/" << f.den;
    return o;
}

bool operator == (frac a, frac b) { return a.num * b.den == b.num * a.den; }
bool operator != (frac a, frac b) { return !(a == b); }
bool operator <= (frac a, frac b) { return (a == b) || (a < b); }
bool operator >= (frac a, frac b) { return !(a < b); }
bool operator > (frac a, frac b) { return !(a <= b); }
frac operator / (frac a, frac b) { frac ret = a; ret /= b; return ret; }
frac operator * (frac a, frac b) { frac ret = a; ret *= b; return ret; }
frac operator + (frac a, frac b) { frac ret = a; ret += b; return ret; }
frac operator - (frac a, frac b) { frac ret = a; return ret; }

ll dist(point a, point b){
	return ll(a.x-b.x)*ll(a.x-b.x) + ll(a.y-b.y)*ll(a.y-b.y);
}

const int N = 10005;
int n, m;
point p[N], r[N];

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
	}

	sort(p, p+m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d%d", &r[j].x, &r[j].y);
		}

		if(m == 1){
			printf("YES\n");
			continue;
		}

		sort(r, r+m);

		frac zoom(dist(p[0], p[1]), dist(r[0], r[1]));

		bool ok = 1;
		for(int j = 1; j < m; j++){
			frac xy1(p[j].y - p[j-1].y, p[j].x - p[j-1].x);
			frac xy2(r[j].y - r[j-1].y, r[j].x - r[j-1].x);
			frac zoom2(dist(p[0], p[j]), dist(r[0], r[j]));

			if(xy1 != xy2){
				// printf("xyz diferente em %d\n", j);
				// cout << xy1 << " " << xy2 << endl;
				ok = 0;
				break;
			}
			if(zoom != zoom2){
				// printf("zoom diferentes em %d\n", j);
				// cout << zoom << " " << zoom2 << endl;
				ok = 0;
				break;
			}
		}

		if(ok){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}

	return 0;
}