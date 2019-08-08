#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int t, p, q;
int XW[N], XE[N], YS[N], YN[N];

void init(){
	memset(XW, 0, sizeof XW);
	memset(XE, 0, sizeof XE);
	memset(YS, 0, sizeof YS);
	memset(YN, 0, sizeof YN);
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		init();
		cin >> p >> q;

		int x, y;
		char dir;
		for(int i = 0; i < p; i++){
			cin >> x >> y >> dir;

			if(dir == 'W'){
				XW[x-1]++;
			}
			if(dir == 'E'){
				XE[x+1]++;
			}
			if(dir == 'S'){
				YS[y-1]++;
			}
			if(dir == 'N'){
				YN[y+1]++;
			}
		}

		int mx = 0, my = 0;
		int X = 0, Y = 0;

		for(int i = 1; i <= q; i++){
			XE[i] += XE[i-1];
			YN[i] += YN[i-1];
		}
		for(int i = q-1; i >= 0; i--){
			XW[i] += XW[i+1];
			YS[i] += YS[i+1];
		}
		for(int i = 0; i <= q; i++){
			if(mx < XW[i]+XE[i]){
				mx = XW[i]+XE[i];
				X = i;
			}
			if(my < YS[i]+YN[i]){
				my = YS[i]+YN[i];
				Y = i;
			}
		}

/*		for(int i = 0; i <= q; i++){
			cout << XW[i] << " ";
		}
		cout << endl;
		for(int i = 0; i <= q; i++){
			cout << XE[i] << " ";
		}
		cout << endl;
		for(int i = 0; i <= q; i++){
			cout << YS[i] << " ";
		}
		cout << endl;
		for(int i = 0; i <= q; i++){
			cout << YN[i] << " ";
		}
		cout << endl;*/

		// cout << mx << " " << my << endl;

		cout << "Case #" << caso << ": " << X << " " << Y << endl;
	}

	return 0;
}