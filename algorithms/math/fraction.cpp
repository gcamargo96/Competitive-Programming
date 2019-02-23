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


bool operator < (frac a, frac b){
    if((a.den < 0) ^ (b.den < 0)) return a.num * b.den > b.num * a.den;
    return a.num * b.den < b.num * a.den;
}

std::ostream& operator<<(std::ostream& o, const frac f){
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


int main(void){
	frac a(1,2);
	frac b(3,4);
	frac c = a*b;
	frac d(1,8);
	// c -= frac(1,8);
	c -= d;

	cout << c << endl;

	return 0;
}