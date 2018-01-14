#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n;
ll x, y, xi, yi;
char p;
bool res = 1;


bool check_diag(){
	ll d1, d2;
	d1 = abs(x-xi);
	d2 = abs(y-yi);
	return d1 == d2;
}

bool check_hor(){
	return x == xi;
}

bool check_vert(){
	return y == yi;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	//scanf("%d", &n);

	cin >> x >> y;
	//scanf("%lld%lld", &x, &y);

	For(i,0,n){
		cin >> p >> xi >> yi;
		
		bool aux;
		if(p == 'B'){
			aux = check_diag();
			if(aux) res = 0;
		}
		if(p == 'R'){
			aux = check_hor() or check_vert();
			if(aux) res = 0;
		}
		if(p == 'Q'){
			aux = check_diag() or check_hor() or check_vert();
			if(aux) res = 0;
		}
	}

	if(res) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}

