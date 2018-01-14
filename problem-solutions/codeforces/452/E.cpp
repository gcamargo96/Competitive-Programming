#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define Rightl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct segment{
	int l, r, v;

	segment() {}

	segment(int _l, int _r, int _v){
		l = _l;
		r = _r;
		v = _v;
	}

	bool operator<(const segment& b) const{
		if(r == b.r)
			return l > b.l;
		return r < b.r;
	}
};

struct segment2{
	int l, r, v;

	segment2() {}

	segment2(int _l, int _r, int _v){
		l = _l;
		r = _r;
		v = _v;
	}

	bool operator<(const segment2& b) const{
		return l > b.l;
	}
};

struct segment3{
	int l, r, v;

	segment3() {}

	segment3(int _l, int _r, int _v){
		l = _l;
		r = _r;
		v = _v;
	}

	bool operator<(const segment3& b) const{
		return l < b.l;
	}
};

const int N = 200002;
int n;
int v[N];
set<segment> tam;
set<segment2> Left;
set<segment3> Right;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}

	int l, r;
	for(int i = 1; i <= n; i++){
		if(v[i] != v[i-1]){
			l = i;
		}
		if(v[i] != v[i+1]){
			r = i;
			tam.insert(segment(l, r-l+1, v[i]));
			Left.insert(segment2(l, r-l+1, v[i]));
			Right.insert(segment3(l, r-l+1, v[i]));			
		}
	}

	// for(segment x : tam){
	// 	printf("%d %d %d\n", x.l, x.r, x.v);
	// }
	
	// printf("\n\n");

	// for(segment2 x : Left){
	// 	printf("%d %d %d\n", x.l, x.r, x.v);
	// }

	// printf("\n\n");

	// for(segment3 x : Right){
	// 	printf("%d %d %d\n", x.l, x.r, x.v);
	// }

	// printf("\n\n");

	int ans = 0;
	while(!tam.empty()){
		auto x = tam.end();
		x--;

		// printf("%d %d %d\n", x->l, x->r, x->v);

		auto L = Left.upper_bound(segment2(x->l, x->r, x->v));
		auto R = Right.upper_bound(segment3(x->l, x->r, x->v));

		if(L != Left.end() and R != Right.end() and L->v == R->v){
			tam.insert(segment(L->l, L->r + R->r, L->v));
			Left.insert(segment2(L->l, L->r + R->r, L->v));
			Right.insert(segment3(L->l, L->r + R->r, L->v));
			
			tam.erase(segment(L->l, L->r, L->v));
			tam.erase(segment(R->l, R->r, R->v));

			Left.erase(segment2(L->l, L->r, L->v));
			Left.erase(segment2(R->l, R->r, R->v));

			Right.erase(segment3(L->l, L->r, L->v));
			Right.erase(segment3(R->l, R->r, R->v));
		}

		tam.erase(x);
		Left.erase(segment2(x->l, x->r, x->v));
		Right.erase(segment3(x->l, x->r, x->v));

		ans++;
	}

	printf("%d\n", ans);

	return 0;
}