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

const int N = 50005;
int at;
vector <int> s[N];
int n, T;

struct No {
	int L, R, p, suff, id;
	map <int, int> f;
	No() {}
	No(int l, int r, int P, int k) : L(l), R(r), p(P), id(k) {}
	inline int len () {
		return R-L+1;
	}
	inline int operator[] (int i) {
		return s[id][L + i];
	}
} t[2*N];

int novo (int L, int R, int p, int id) {
	t[at] = No (L, R, p, id);
	at++;
	return at-1;
}

void build_suffix_tree (vector <int> &s, int id) {	
	int i = 0, cn = 0, cd = 0, ns = 0;
	int n = s.size();
	for (int j = 0; j < s.size(); j++) {
		for (; i <= j; i++) {
			if (t[cn].len() == cd ? t[cn].f.count(s[j]) : t[cn][cd] == s[j]) {//CASO 1
				if (t[cn].len() == cd) {
					cd = 0;
					cn = t[cn].f[s[j]];
				}
				cd++;
				break;
			} else if (t[cn].len() == cd) {//CASO 2
				t[cn].f[s[j]] = novo(j, n-1, cn, id);
				if (cn) {
					cn = t[cn].suff;
					cd = t[cn].len();
				}
			} else {//CASO 3 (precisa criar o suffix link)
				//quebrar a aresta
				int mid = novo (t[cn].L, t[cn].L + cd - 1, t[cn].p, t[cn].id);
				t[t[mid].p].f[t[mid][0]] = mid;
				t[mid].f[s[j]] = novo (j, n-1, mid, id);
				t[mid].f[t[cn][cd]] = cn;
				t[cn].p = mid;
				t[cn].L += cd;
				if (ns) t[ns].suff = mid;
				//achar o suffix link de mid
				cn = t[mid].p;
				int g;
				if (cn) {
					cn = t[cn].suff;
					g = j - cd;
				} else g = i+1;
				while (g < j && g + t[t[cn].f[s[g]]].len() <= j) {
					cn = t[cn].f[s[g]];
					g += t[cn].len();
				}
				if (g == j) {
					t[mid].suff = cn;
					cd = t[cn].len();
					ns = 0;
				} else { // g < j
					ns = mid;
					cn = t[cn].f[s[g]];
					cd = j - g;
				}
			}
		}
	}
}

ll ans;
ll qtd[2*N];
int c[N];

ll dfs (int cn) {
	for(int i = 0; i < t[cn].len(); i++){
		cout << char(t[cn][i]);
	}
	cout << endl;
	cout << t[cn].id;

	if (t[cn].R + 1 == (int) s[t[cn].id].size()) return qtd[cn] = t[cn].len();

	for (map<int, int>::iterator it = t[cn].f.begin(); it != t[cn].f.end(); it++) {
		qtd[cn] += dfs (it->se);
	}
	return qtd[cn];
}

int main(void){
	fastcin;
	cin >> T;

	for(int i = 0; i < T; i++){
		// s.clear();

		string x; cin >> x;
		for(int j = 0; j < x.size(); j++){
			s[i].pb(x[j]);
		}

		build_suffix_tree(s[i], i);
		ll ans = dfs(0);
		cout << ans << endl;
	}

	return 0;
}