#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define NADA 0
#define BUC 1
#define BAR 2
#define INV 3

const int N = 1024002;
int seg[4*N], lazy[4*N];
string pira;
int T, m, n, q, t;
int a, b;

void build(int r, int i, int j){
	if(i == j){
		seg[r] = pira[i-1] - '0';
		return;
	}
	int mid = (i+j)/2;
	build(2*r, i, mid);
	build(2*r+1, mid+1, j);
	seg[r] = seg[2*r] + seg[2*r+1];
}

void prop(int r, int action, int i, int j){
	if(action == NADA){
		if(lazy[r] == BAR) seg[r] = 0;
		if(lazy[r] == BUC) seg[r] = j-i+1;
		if(lazy[r] == INV) seg[r] = j-i+1 - seg[r];
		if(i != j){
			lazy[2*r] = lazy[r];
			lazy[2*r+1] = lazy[r];
		}
	}
	else if(action == BAR){
		seg[r] = 0;
		if(i != j){
			lazy[2*r] = BAR;
			lazy[2*r+1] = BAR;
		}
	}
	else if(action == BUC){
		seg[r] = j-i+1;
		if(i != j){
			lazy[2*r] = BUC;
			lazy[2*r+1] = BUC;
		}
	}
	else if(action == INV){
		if(lazy[r] == BAR){
			seg[r] = j-i+1;
			if(i != j){
				lazy[2*r] = BUC;
				lazy[2*r+1] = BUC;
			}
		}
		if(lazy[r] == BUC){
			seg[r] = 0;
			if(i != j){
				lazy[2*r] = BAR;
				lazy[2*r+1] = BAR;
			}
		}
		if(lazy[r] == NADA){
			seg[r] = j-i+1 - seg[r];
			if(i != j){
				lazy[2*r] = INV;
				lazy[2*r+1] = INV;
			}
		}
	}
	lazy[r] = NADA;
}

void update(int r, int action, int i, int j){
	if(!(a <= i and j <= b)) prop(r, NADA, i, j);
	if(i > b or j < a) return;
	//prop(r, action, i, j);
	if(a <= i and j <= b){
		prop(r, action, i, j);
		return;
	}
	int mid = (i+j)/2;
	update(2*r, action, i, mid);
	update(2*r+1, action, mid+1, j);
	seg[r] = seg[2*r] + seg[2*r+1];
}

int query(int r, int i, int j){
	prop(r, NADA, i, j);
	if(i > b or j < a) return 0;
	if(a <= i and j <= b) return seg[r];
	int mid = (i+j)/2;
	int L = query(2*r, i, mid);
	int R = query(2*r+1, mid+1, j);
	return L+R;
}

void init(){
	n = 0;
	pira.clear();
	For(i,0,N){
		seg[i] = 0;
		lazy[i] = 0;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> T;

	For(caso,1,T+1){
		init();
		cin >> m;

		string s;
		For(i,0,m){
			cin >> t;
			cin >> s;

			n += t*s.size();

			For(j,0,t){
				pira += s;
			}
		}

		build(1,1,n);

		cin >> q;

		char c;
		int cnt = 1;
		cout << "Case " << caso << ":" << endl;
		For(i,0,q){
			cin >> c >> a >> b;
			a++, b++;
			if(c == 'F'){ // BUC
				update(1, BUC, 1, n);
			}
			if(c == 'E'){
				update(1, BAR, 1, n);
			}
			if(c == 'I'){
				update(1, INV, 1, n);
			}
			if(c == 'S'){
				int res = query(1, 1, n);
				cout << "Q" << cnt++ << ": " << res << endl;
			}
		}
	}

	return 0;
}
