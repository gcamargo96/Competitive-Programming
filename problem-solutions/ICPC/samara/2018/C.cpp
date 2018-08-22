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

#define BEG 0
#define END 1

struct event{
	int pos, tipo, id;

	event() {}

	event(int _pos, int _tipo, int _id){
		pos = _pos;
		tipo = _tipo;
		id = _id;
	}

	bool operator<(const event& b) const{
		if(pos == b.pos){
			return tipo < b.tipo;
		}
		return pos < b.pos;
	}
};

const int N = 200005;
int n;
vector<event> e;
bool used[N];

int main(void){
	scanf("%d", &n);

	int l, r;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &l, &r);
		e.eb(l, BEG, i);
		e.eb(r, END, i);
	}

	sort(e.begin(), e.end());

	set<int> s;
	vi ans;
	for(int i = 0; i < e.size(); i++){
		if(e[i].tipo == BEG){
			s.insert(e[i].id);
			// printf("insert %d\n", e[i].id);
		}
		else if(s.count(e[i].id)){
			// printf("buy %d\n", e[i].id);
			ans.pb(e[i].pos);
			s.clear();
		}
	}

	printf("%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}