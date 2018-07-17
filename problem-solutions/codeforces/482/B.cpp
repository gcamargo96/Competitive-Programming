#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
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

const int N = 100005;
int n;
string a, b, c;
int ma[N], mb[N], mc[N];
int fa = 0, fb = 0, fc = 0;
int ansa, ansb, ansc;

int main(void){
	fastcin;
	cin >> n;
	cin >> a >> b >> c;
	int len = a.size();

	for(int i = 0; i < len; i++){
		fa = max(fa, ++ma[a[i]]);
	}
	for(int i = 0; i < len; i++){
		fb = max(fb, ++mb[b[i]]);
	}
	for(int i = 0; i < len; i++){
		fc = max(fc, ++mc[c[i]]);
	}

	ansa = min(len, fa + n);
	ansb = min(len, fb + n);
	ansc = min(len, fc + n);

	if(n == 1 and fa == len) ansa--;
	if(n == 1 and fb == len) ansb--;
	if(n == 1 and fc == len) ansc--;

	if(ansa > ansb and ansa > ansc){
		cout << "Kuro" << endl;
	}
	else if(ansb > ansa and ansb > ansc){
		cout << "Shiro" << endl;
	}
	else if(ansc > ansa and ansc > ansb){
		cout << "Katie" << endl;
	}
	else{
		cout << "Draw" << endl;
	}

	return 0;
}