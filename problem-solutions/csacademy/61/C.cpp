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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define BEG 0
#define END 1

struct event{
	int p, tipo;

	event() {}

	event(int _p, int _tipo){
		p = _p;
		tipo = _tipo;
	}

	bool operator<(const event& b) const{
		if(p == b.p){
			return tipo < b.tipo;
		}
		return p < b.p;
	}
};

const int N = 200002;
int bit[N];
vector<event> v;
ii q[N];
int n, m;

void update(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}

int main(void){
	scanf("%d%d", &n, &m);

	int l, r;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &l, &r);
		v.pb(event(l, BEG));
		v.pb(event(r, END));
	
		q[i].fi = l;
		q[i].se = r;
	}

	sort(v.begin(), v.end());

	int open = 0, pos = 0, cnt0 = 0;
	int i;
	for(i = 1; i <= n /*and pos < v.size()*/; i++){
		while(pos < v.size() and v[pos].p == i and v[pos].tipo == BEG){
			open++;
			pos++;
		}

		if(open == 0)
			cnt0++;

		if(open == 1){
			update(i, 1);
		}

		while(pos < v.size() and v[pos].p == i and v[pos].tipo == END){
			open--;
			pos++;
		}

	}

	// cnt0 += n-i+1;

	// for(int i = 1; i <= n; i++){
	// 	int x = query(i) - query(i-1);
	// 	printf("%d ", x);
	// }
	// printf("\n\n");

	for(int i = 0; i < m; i++){
		int ans = query(q[i].se) - query(q[i].fi-1);
		printf("%d\n", cnt0 + ans);
	}

	return 0;
}