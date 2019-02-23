#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 0x3f3f3f3f
#define A 0
#define B 1
#define C 2

const int N = 1005;
int xa, ya, xb, yb, xc, yc;
set<ii> s;
ii ans;

void get_path(int label){
	int xf, yf;
	if(label == A) xf = xa, yf = ya;
	if(label == B) xf = xb, yf = yb;
	if(label == C) xf = xc, yf = yc;

	s.insert(ii(xf, yf));

	int x = ans.fi, y = ans.se;
	for(; x < xf; x++){
		s.insert(ii(x, ans.se));
	}
	for(; x > xf; x--){
		s.insert(ii(x, ans.se));
	}

	for(; y < yf; y++){
		s.insert(ii(x, y));
	}
	for(; y > yf; y--){
		s.insert(ii(x, y));
	}
}

int main(void){
	scanf("%d%d", &xa, &ya);
	scanf("%d%d", &xb, &yb);
	scanf("%d%d", &xc, &yc);

	int mn = INF;
	for(int x = 0; x < N; x++){
		for(int y = 0; y < N; y++){
			int dist = abs(x-xa) + abs(x-xb) + abs(x-xc) + abs(y-ya) + abs(y-yb) + abs(y-yc);
			if(dist < mn){
				ans.fi = x;
				ans.se = y;
				mn = dist;
			}
		}
	}

	get_path(A);
	get_path(B);
	get_path(C);

	printf("%d\n", int(s.size()));

	for(ii plot : s){
		printf("%d %d\n", plot.fi, plot.se);
	}

	return 0;
}