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

struct node{
	int p, t;

	node() {}

	node(int _p, int _t){
		p = _p;
		t = _t;
	}

	bool operator<(const node& b) const{
		if(p == b.p) return t < b.t;
		return p > b.p;
	}
};

int n, k, p, t;
map<node, int> m;

int main(void){
	scanf("%d%d", &n, &k);

	For(i,0,n){
		scanf("%d%d", &p, &t);
		m[node(p,t)]++;
	}

	int cnt = 1;
	for(auto it = m.begin(); it != m.end() and cnt <= k; it++){
		if(cnt <= k and cnt+it->se > k){
			printf("%d\n", it->se);
			break;
		}
		cnt += it->se;
	}
	
	return 0;
}

