#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const ull M = 1000000000000037LL, B = 10;
const int N = 1000002;
ull h[N], pot[N];
string s;
int lens;

ull mul(ull a, ull b){
	ull q = ull((long double)a*b/M);
	ull r = a*b - M*q;
	while(r < M) r += M;
	while(r >= M) r -= M;
	return r;
}

void precalc(string& s){
    h[0] = s[0] - '0';
    pot[0] = 1;

    for(int i = 1; i < lens; i++){
        h[i] = (mul(h[i-1], B) + (s[i] - '0'))%M;
        pot[i] = mul(pot[i-1], B);
    }
}

ll calcHash(int i, int j){
    if(i == 0) return h[j];
    return (h[j] - /*h[k][i-1]*pot[k][j-i+1])%mod[k]*/ mul(h[i-1], pot[j-i+1]) + M)%M;
}

bool check(int lena, int lenb, int lenc){
	if(lena <= 0 || lenb <= 0 || lenc <= 0)
		return 0;

	if(lena + lenb + lenc != lens)
		return 0;

	if((s[0] == '0' && lena > 1) || (s[lena] == '0' && lenb > 1) || (s[lena+lenb] == '0' && lenc > 1))
		return 0;

	ll ha = calcHash(0, lena-1);
	ll hb = calcHash(lena, lena+lenb-1);
	ll hc = calcHash(lena+lenb, lens-1);

	if((ha + hb) % M == hc){
		cout << s.substr(0, lena) << "+" << s.substr(lena, lenb) << "=" << s.substr(lena+lenb, lenc) << endl;
		return 1;
	}
	return 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;
	lens = s.size();

	precalc(s);

	int lena, lenb; 
	for(int lenc = 1; lenc <= lens-2; lenc++){
		lena = lenc;
		lenb = lens - lena - lenc;
		if(check(lena, lenb, lenc))
			break;

		lena = lenc-1;
		lenb = lens - lena - lenc;
		if(check(lena, lenb, lenc))
			break;

		lenb = lenc;
		lena = lens - lenb - lenc;
		if(check(lena, lenb, lenc))
			break;

		lenb = lenc-1;
		lena = lens - lenb - lenc;
		if(check(lena, lenb, lenc))
			break;
	}

	return 0;
}