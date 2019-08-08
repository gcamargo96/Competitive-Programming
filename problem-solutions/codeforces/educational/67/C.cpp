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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct Seg{
	int t, l, r;

	Seg() {}

	Seg(int _t, int _l, int _r){
		t = _t;
		l = _l;
		r = _r;
	}
};

struct Event{
	int pos, t, tipo;

	Event() {}

	Event(int _pos, int _t, int _tipo){
		pos = _pos;
		t = _t;
		tipo = _t;
	}

	bool operator<(const Event& b) const{
		if(pos == b.pos){
			return tipo > b.tipo;
		}
		return pos < b.pos;
	}
};

#define BEG 0
#define END 1

const int MX = 1000000;
const int N = 1005;
int ans[N], cnt1, cnt0;
int n, m;
Seg seg[N];
int acc1[N], acc0[N];
vector<Event> e;


int main(void){
	scanf("%d%d", &n, &m);

	int t, l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &seg[i].t, &seg[i].l, &seg[i].r);
		e.eb(seg[i].l, seg[i].t, BEG);
		e.eb(seg[i].r, seg[i].t, END);
	}

	bool ok = 1;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if(seg[j].t == 1 or i == j) continue;
			
			if(seg[j].l >= seg[i].l and seg[j].r <= seg[i].r){
				ok = 0;
			}
		}
	}

	if(!ok){
		printf("NO\n");
		return 0;
	}

	sort(e.begin(), e.end());

	int cur = MX, j = 0;
	for(int i = 1; i <= n; i++){
		while(j < e.size() and e[j].pos < i){
			if(e[i].tipo == BEG){
				if(e[i].t == 0) cnt0++;
				else cnt1++;
			}
			else{ // END
				if(e[i].t == 0) cnt0--;
				else cnt1--;
			}
		}

		while(j < e.size() and e[j].pos == i and e[j].t == 1){
			
		}
	}

	// for(int i = 0; i < m; i++){
	// 	int l = seg[i].l, r = seg[i].r;

	// 	if(seg[i].t == 0){
	// 		acc0[l]++;
	// 		acc0[r+1]--;
	// 	}
	// 	else{
	// 		acc1[l]++;
	// 		acc1[r+1]--;
	// 	}
	// }

	// for(int i = 1; i <= n; i++){
	// 	acc0[i] += acc0[i-1];
	// 	acc1[i] += acc1[i-1];
	// }

	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", acc0[i]);
	// }
	// printf("\n");
	
	// for(int i = 1; i <= n; i++){
	// 	printf("%d ", acc1[i]);
	// }
	// printf("\n");


	return 0;
}