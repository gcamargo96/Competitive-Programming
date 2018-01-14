#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1000002;
#define B 10
string s;
ll mod[2] = {1000000000000037LL, 1000000000100011LL};
ll h[2][N], hr[2][N];
ll pot[2][N], potr[2][N];
int lens;

ll russianPeasant(ll a, ll b, int k)
{
    ll res = 0;  // initialize result
 
    // While second number doesn't become 1
    while (b > 0)
    {
         // If second number becomes odd, add the first number to result
         if (b & 1)
             res = (res + a) % mod[k];
 
         // Double the first number and halve the second number
         a = (a << 1) % mod[k];
         b = b >> 1;
     }
     return res;
}

void precalc(string& s){
    for(int k = 0; k < 1; k++){
        h[k][0] = s[0] - '0';
        pot[k][0] = 1;

        for(int i = 1; i < lens; i++){
            h[k][i] = ((h[k][i-1]*B)%mod[k] + (s[i] - '0'))%mod[k];
            pot[k][i] = (pot[k][i-1]*B)%mod[k];
        }
    }
}

void precalcrev(string& s){
    int n = s.size();
    for(int k = 0; k < 1; k++){
        hr[k][n-1] = s[n-1] - '0';

        for(int i = n-2; i >= 0; i--){
            hr[k][i] = (((s[i] - '0')*pot[k][(n-1)-i])%mod[k] + hr[k][i+1])%mod[k];
        	// cout << hr[k][i] << " ";
        }
        // cout << endl;
    }
}


ll calcHash(int i, int j, int k){
    if(i == 0) return h[k][j];
    return (h[k][j] - /*h[k][i-1]*pot[k][j-i+1])%mod[k]*/ russianPeasant(h[k][i-1], pot[k][j-i+1], k) + mod[k])%mod[k];
}

ll calcHashRev(int i, int j, int k){
	return hr[k][i];
}

bool check(int lena, int lenb, int lenc){
	if(lena <= 0 || lenb <= 0 || lenc <= 0)
		return 0;

	if(lena + lenb + lenc != lens)
		return 0;

	if((s[0] == '0' && lena > 1) || (s[lena] == '0' && lenb > 1) || (s[lena+lenb] == '0' && lenc > 1))
		return 0;

	ll ha0 = calcHash(0, lena-1, 0);
	// ll ha1 = calcHash(0, lena-1, 1);

	ll hb0 = calcHash(lena, lena+lenb-1, 0);
	// ll hb1 = calcHash(lena, lena+lenb-1, 1);

	ll hc0 = calcHashRev(lena+lenb, lens-1, 0);
	// ll hc1 = calcHashRev(lena+lenb, lens-1, 1);

	if((ha0 + hb0) % mod[0] == hc0 /*&& (ha1 + hb1) % mod[1] == hc1*/){
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
	precalcrev(s);

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