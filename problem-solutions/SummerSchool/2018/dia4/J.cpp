#include <bits/stdc++.h>
using namespace std;
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

const int N = 26;
vector<string> s;
vi adj[N];
vector<pair<int, ii> > comps;
int cor[N], opt[N][N][N], dp[N][N][N], vis[N];
int n, cnt1, cnt2;
set<char> vogal, consoante;
map<char,char> m;

void init(){
	memset(dp, -1, sizeof dp);
	
	m[' '] = ' ';

	vogal.insert('A');
	vogal.insert('E');
	vogal.insert('I');
	vogal.insert('O');
	vogal.insert('U');

	for(char c = 'A'; c <= 'Z'; c++){
		if(!vogal.count(c))
			consoante.insert(c);
	}
}

bool dfs(int u, int c){
	cor[u] = c;

	if(c == 1)
		cnt1++;
	else
		cnt2++;

	bool ret = 1;
	for(int v : adj[u]){
		if(cor[v] == cor[u]){
			return 0;
		}
		if(cor[v] == 0){
			ret &= dfs(v, (c == 1 ? 2 : 1));
		}
	}

	return ret;
}

bool solve(int i, int v, int c){
	if(i == comps.size()){
		if(v <= 5 and c <= 21)
			return 1;
		return 0;
	}

	if(dp[i][v][c] != -1)
		return dp[i][v][c];

	bool ok1 = solve(i+1, v+comps[i].se.fi, c+comps[i].se.se);
	bool ok2 = solve(i+1, v+comps[i].se.se, c+comps[i].se.fi);

	if(ok1)
		opt[i][v][c] = 1;
	if(ok2)
		opt[i][v][c] = 2;

	return ok1 || ok2;
}

void assign(int u, int c){
	vis[u] = 1;

	char letra;;
	if(c == 1){
		letra = *(vogal.begin());
		vogal.erase(letra);
	}
	if(c == 2){
		letra = *(consoante.begin());
		consoante.erase(letra);
	}
	m[u+'A'] = letra;
	// cout << "m[" << char(u+'A') << "] = " << letra << endl;

	for(int v : adj[u]){
		if(!vis[v]){
			assign(v, (c == 1 ? 2 : 1));
		}
	}
}

void get_ans(int i, int v, int c){
	if(i == comps.size())
		return;

	if(opt[i][v][c] == 1){
		assign(comps[i].fi, 1);
		get_ans(i+1, v+comps[i].se.fi, c+comps[i].se.se);
	}
	if(opt[i][v][c] == 2){
		assign(comps[i].fi, 2);
		get_ans(i+1, v+comps[i].se.se, c+comps[i].se.fi);
	}
}

int main(void){
	freopen("javanese.in", "r", stdin);
	freopen("javanese.out", "w", stdout);

	fastcin;
	init();
	string aux;
	while(cin >> aux){
		s.pb(aux);
	}

	// for(int i = 0; i < s.size(); i++){
	// 	cout << s[i] << endl;
	// }

	bool ok = 1;
	for(int k = 0; k < s.size(); k++){
		int n = s[k].size();
		for(int i = 0; i < n-1; i++){
			// if(s[k][i] == ' ' || s[k][i+1] == ' ')
			// 	continue;

			int u = s[k][i]-'A', v = s[k][i+1]-'A';
			adj[u].pb(v);
			adj[v].pb(u);
		}

	}
	
	for(int k = 0; k < s.size(); k++){
		for(int i = 0; i < s[k].size(); i++){
			// if(s[k][i] == ' ')
			// 	continue;

			int u = s[k][i]-'A';
			if(cor[u] == 0){
				cnt1 = cnt2 = 0;
				ok &= dfs(u, 1);
				comps.pb(mp(u, ii(cnt1, cnt2)));
			}
		}
	}

	// for(int i = 0; i < comps.size(); i++){
	// 	cout << "comp " << char(comps[i].fi+'A') << " " << comps[i].se.fi << " " << comps[i].se.se << endl;
	// }

	if(!ok){
		cout << "impossible" << endl;
		return 0;
	}

	ok = solve(0, 0, 0);

	if(!ok){
		cout << "impossible" << endl;
		return 0;
	}

	get_ans(0,0,0);

	for(int k = 0; k < s.size(); k++){
		for(int i = 0; i < s[k].size(); i++){
			cout << m[s[k][i]];
		}
		cout << endl;
	}

	return 0;
}