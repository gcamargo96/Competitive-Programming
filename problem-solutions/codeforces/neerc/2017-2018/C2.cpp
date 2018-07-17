#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define LOWER 1
#define UPPER 2

struct Edge{
	int u, v, w;

	Edge () {}

	Edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}

	bool operator<(const Edge& b) const{
		return w > b.w;
	}
};

const int N = 30;
vector<Edge> e;
vector<int> vcons;
set<char> cons;
int peso[N][N], label[N], ans[N];
string s;
int best = 0;

void init(){
	for(char c = 'a'; c <= 'z'; c++){
		if(c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u' and c != 'w' and c != 'y'){
			cons.insert(c);
		}
	}

	for(int i = 0; i < 26; i++){
		label[i] = LOWER;
	}

	for(char c : cons){
		vcons.pb(c-'a');
	}
}

int check(){
	int aux = 0;
	for(int i = 0; i < 26; i++){
		for(int j = i+1; j < 26; j++){
			if(label[i] != label[j]){
				// cout << "aux += " << peso[i][j] << endl;
				aux += peso[i][j];
			}
		}
	}
	// cout << "aux = " << endl;
	return aux;
}

void solve(int i){
	if(i == vcons.size()){
		int aux = check();
		if(aux > best){
			best = aux;
			for(int j = 0; j < 26; j++){
				ans[j] = label[j];
			}
		}
		return;
	}

	label[vcons[i]] = LOWER;
	solve(i+1);
	label[vcons[i]] = UPPER;
	solve(i+1);
	// label[vcons[i]] = LOWER;
}

int main(void){
	freopen("consonant.in", "r", stdin);
	freopen("consonant.out", "w", stdout);

	fastcin;
	init();
	cin >> s;

	for(int i = 0; i < int(s.size())-1; i++){
		if(cons.count(s[i]) and cons.count(s[i+1])){
			int u = s[i]-'a', v = s[i+1]-'a';
			peso[u][v]++;
			peso[v][u]++;
		}
	}

	solve(0);
	// cout << "best = " << best << endl;

	for(int i = 0; i < s.size(); i++){
		if(ans[s[i]-'a'] == LOWER) cout << s[i]; // printf("%c", s[i]);
		else cout << char(s[i]-'a'+'A'); // printf("%c", s[i]-'a'+'A');		
	}
	cout << endl; // printf("\n");

	return 0;
}