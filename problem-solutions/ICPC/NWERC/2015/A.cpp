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

#define BEG 1
#define END 0

struct event{
	int t, tipo;

	event() {}

	event(int _t, int _tipo){
		t = _t;
		tipo = _tipo;
	}

	bool operator<(const event& b) const{
		if(t == b.t) return tipo < b.tipo;
		return t < b.t;
	}
};

const int N = 300005;
int n, m;
vector<event> e;
map<int,int> active;

int main(void){
	scanf("%d%d", &n, &m);

	int l, k;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &l, &k);
		e.eb(l, BEG);
		e.eb(l+k, END);
	}

	sort(e.begin(), e.end());

	int ans = 0;
	for(int i = 0; i < e.size(); i++){
		if(e[i].tipo == END){
			active[e[i].t + m]++;
		}
		else{ // BEG
			bool ok = 0;
			auto it = active.begin();
			while(it != active.end()){
				if(it->fi >= e[i].t){ // da pra encaixar
					ok = 1;

					// printf("encaixou %d em %d\n", e[i].t, it->fi);

					it->se--;
					if(it->se == 0){
						active.erase(it);
					}

					break;
				}
				else{
					it = active.erase(it);
				}
			}

			if(!ok){
				// printf("novo em %d\n", e[i].t);
				ans++;
			}
		}
	}

	printf("%d\n", n-ans);

	return 0;
}