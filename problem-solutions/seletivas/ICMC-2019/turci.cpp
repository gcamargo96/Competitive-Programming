#include <bits/stdc++.h>
 
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
 
const int N = 1000007, inf = 0x3f3f3f3f;
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
struct no {
	int l, r, par, suf;
	vector<int> * s;
	map<int, int> f;
	int len() {return r - l + 1;}
	int operator[](int i) {return (*s)[l+i];}
};
 
no t[N + N];
 
int new_node(int l, int r, int par, vector<int> * str) {
	static int ptr = 0;
	ptr++;
	t[ptr].l = l;
	t[ptr].r = r;
	t[ptr].par = par;
	t[ptr].s = str;
	return ptr;
}
 
 
void print_node(int u) {
	printf("Vert = %d\t", u);
	for(int i = 0; i < t[u].len(); ++i) printf("%d ", t[u][i]);
	printf("\tpar = %d\n", t[u].par);
}
 
 
void build(vector<int> & s, int n) {
	int i, j, cn, cd, ns = 0;
	i = j = cn = cd = 0;
 
	t[0].r = -1;
 
	// invariante (cn, cd-1) representa a string S[i .. j-1]
	for(j = 0; j < n; ++j) {
		for(; i <= j; ++i) {
			if((cd == t[cn].len() and t[cn].f.count(s[j])) or (cd != t[cn].len() and t[cn][cd] == s[j])) { // se eh o caso 1
				// atualiza a invariante e vai pra proxima iteracao
				if(cd == t[cn].len()) {
					cn = t[cn].f[s[j]];
					cd = 0;
				} 
				cd++;
				break;
			} else if(cd == t[cn].len()) {
				t[cn].f[s[j]] = new_node(j, n-1, cn, &s); // como esse novo noh eh uma folha, seu r eh n-1 automaticamente
				if(cn) { // voce nao esta na raiz
					cn = t[cn].suf;
					cd = t[cn].len();
				}
			} else if(cd < t[cn].len()) { // caso = 3
				// Divide a aresta no meio, criando um novo noh interno e um novo noh folha
				int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].par, &s);
				t[t[mid].par].f[t[mid][0]] = mid;
 
				t[mid].f[s[j]] = new_node(j, n-1, mid, &s);
				t[mid].f[t[cn][cd]] = cn;
				t[cn].l += cd;
				t[cn].par = mid;
				if(ns) t[ns].suf = mid;
				
 
				// Parte 2
				cn = t[mid].par;
				int g; // g indica que o cn representa o cara s[i+1, g-1]. Quero atualizar cn ateh que g seja igual a j
				if(cn) {
					cn = t[cn].suf;
					g = j - cd;
				} else g = i+1;
 
				while(g < j and g + t[t[cn].f[s[g]]].len() <= j) {
					cn = t[cn].f[s[g]];
					g += t[cn].len();
				}
				if(g == j) {
					t[mid].suf = cn;
					cd = t[cn].len();
					ns = 0;
				} else {
					ns = mid;
					cn = t[cn].f[s[g]];
					cd = j - g;
				}
			}
		}
	}
}
 
ll L, R;
ll acc[N];
 
vector<ll> seg[15 * N];
 
void build_seg(int p, int l, int r) {
	if(l == r) {
		seg[p].pb(acc[l]);
	} else {
		int mid = (l + r)/2;
		build_seg(2 * p, l, mid);
		build_seg(2 * p + 1, mid+1, r);
 
		seg[p].resize(r - l + 1);
		merge(seg[2 * p].begin(), seg[2 * p].end(), seg[2 * p + 1].begin(), seg[2 * p + 1].end(), seg[p].begin());
	}
 
}
 
int query(int p, int l, int r, int a, int b, ll x, ll y) {
	if(l > b or r < a) return 0;
	if(l >= a and r <= b) {
		int i = upper_bound(seg[p].begin(), seg[p].end(), y) - seg[p].begin();
		int j = lower_bound(seg[p].begin(), seg[p].end(), x) - seg[p].begin();
		return max(0, i - j);
	} else {
		int mid = (l + r)/2;
		return query(2 * p, l, mid, a, b, x, y) + query(2 * p + 1, mid+1, r, a, b, x, y);
	}
}
 
int n;
 
ll dfs(int u, ll cur = 0) {

	for(int i = 0; i < t[u].len(); i++){
		cout << t[u][i] << " ";
	}
	cout << endl;
 
	// print_node(u);
	int l = t[u].l;
	int r = t[u].r;
	
	// cout << l << ' ' << r << endl;
	
	ll x = r == -1? 0 : acc[r] - (l? acc[l - 1] : 0);
 
	// cout << i << ' ' << j << ' '  << l << ' ' << r << endl;
	ll tot = r < l? 0 : query(1, 0, n-1, l, r, L - cur + (l? acc[l - 1] : 0), R - cur + (l? acc[l - 1] : 0));
	for(pair<int, int> g : t[u].f) {
		tot += dfs(g.second, cur + x);
	}
	return tot;
}
 
 
 
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> L >> R;
 
	vector<int> s(n);
	for(int & x : s) cin >> x;
	
	acc[0] = s[0];
	for(int i = 1; i < n; ++i) {
		acc[i] = acc[i - 1] + s[i];
	}
 
	build_seg(1, 0, n-1);
	build(s, s.size());
 
	cout << dfs(0) << endl;
}