#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 27;
int t, r, c;
char g[N][N];
bool beg[N][N];
set<char> vis;

bool check(int baixo, int cima, int esq, int dir, char c){
	if(baixo < 0 or cima >= r or esq < 0 or dir >= c) return 0;
	for(int i = baixo; i <= cima; i++){
		for(int j = esq; j <= dir; j++){
			if(g[i][j] != '?' and g[i][j] != c) return 0;
		}
	}
	return 1;
}

void draw(int baixo, int cima, int esq, int dir, char c){
	for(int i = baixo; i <= cima; i++){
		for(int j = esq; j <= dir; j++){
			g[i][j] = c;
		}
	}
}

void fix(int& baixo, int& cima, int& esq, int& dir){
	if(baixo < 0) baixo++;
	if(esq < 0) esq++;
	if(cima == r) cima--;
	if(dir == c) dir--;
}

void expand(int i, int j, char c){
	int baixo = i, cima = i, esq = j, dir = j;

	while(check(baixo, cima+1, esq-1, dir, c)){ // esq cima
		cima++, esq--;
	}
	fix(baixo, cima, esq, dir);
	while(check(baixo, cima+1, esq, dir+1, c)){ // dir cima
		cima++, dir++;
	}
	fix(baixo, cima, esq, dir);
	while(check(baixo-1, cima, esq-1, dir, c)){ // esq baixo
		baixo--, esq--;
	}
	fix(baixo, cima, esq, dir);
	while(check(baixo-1, cima, esq, dir+1, c)){ // dir baixo
		baixo--, dir++;
	}
	fix(baixo, cima, esq, dir);

	while(check(baixo, cima+1, esq, dir, c)){ // cima
		cima++;
	}
	fix(baixo, cima, esq, dir);
	while(check(baixo-1, cima, esq, dir, c)){ // baixo
		baixo--;
	}
	fix(baixo, cima, esq, dir);
	while(check(baixo, cima, esq-1, dir, c)){ // esq
		esq--;
	}
	fix(baixo, cima, esq, dir);
	while(check(baixo, cima, esq, dir+1, c)){ // dir
		dir++;
	}
	fix(baixo, cima, esq, dir);
	draw(baixo, cima, esq, dir, c);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		vis.clear();
		memset(beg, 0, sizeof beg);
		cin >> r >> c;

		For(i,0,r){
			For(j,0,c){
				cin >> g[i][j];
				if(g[i][j] != '?') beg[i][j] = 1;
			}
		}
	
		For(i,0,r){
			For(j,0,c){
				if(g[i][j] != '?' /*and !vis.count(g[i][j])*/){
					expand(i, j, g[i][j]);
					vis.insert(g[i][j]);
				}
			}
		}

		cout << "Case #" << caso << ":" << endl;
		For(i,0,r){
			For(j,0,c){
				cout << g[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}

