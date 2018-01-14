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

const int N = 102;
int t, n, m;
char g[N][N];

struct add{
	char model;
	int x, y;

	add() {}

	add(char _model, int _x, int _y){
		model = _model;
		x = _x;
		y = _y;
	}
};

void init(){
	For(i,0,N){
		For(j,0,N){
			g[i][j] = '.';
		}
	}
}

bool check_diag(int r){
	int j = 2;
	for(int i = r-1; i >= 1; i--){
		if(g[i][j] == 'x') return 1;
		j++;
	}
	return 0;
}

bool check_linha(int i){
	for(int j = 1; j <= n; j++){
		if(g[i][j] != '+' and g[i][j] != '.'){
			return 1;
		}
	}
	return 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		init();
		cin >> n >> m;

		char c;
	   	int	x, y;
		For(i,0,m){
			cin >> c >> x >> y;
			g[x][y] = c;
			cout << "colocou" << endl;
		}

		cout << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << g[i][j];
			}
			cout << endl;
		}

		bool tem = 0;
		char qual;
		for(int j = 1; j <= n; j++){
			if(g[1][j] != '.' and g[1][j] != '+'){
				tem = 1;
				qual = g[1][j];
			}
		}

		vector<add> res;
		bool foi = 0;
		if(!tem){
			for(int j = 1; j <= n; j++){
				if(g[1][j] == '.'){
					g[1][j] = 'o';
					foi = 1;
					res.pb(add('o',1,j));
					break;
				}
			}
		}

		if(!foi){
			for(int j = 1; j <= n; j++){
				if(g[1][j] == '+'){
					g[1][j] = 'o';
					res.pb(add('o',1,1));
				}
			}
		}

		for(int j = 1; j <= n; j++){
			if(g[1][j] == '.'){
				g[1][j] = '+';
				res.pb(add('+',1,j));
			}
		}
		
		for(int i = 2; i <= n; i++){
			if(check_diag(i)){
				g[i][1] = 'o';	
				res.pb(add('o',i,1));
			}
			else{
				g[i][1] = 'x';
				res.pb(add('x',i,1));
			}
		}
		
		for(int i = 2; i <= n; i++){
			for(int j = 2; j <= n-i+1; j++){
				g[i][j] = '+';
				res.pb(add('+',i,j));
			}
		}

		for(int j = 1; j <= n; j++){
			if(g[1][j] == 'x'){
				int i = 1;
				while(j < n){
					j++;
					i++;
					if(!check_linha(i)){
						g[i][j] = 'o';
						res.pb(add('o',i,j));
					}
					else{
						g[i][j] = '+';
						res.pb(add('+',i,j));
					}
				}
			}
		}

		int style = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(g[i][j] == 'o') style += 2;
				if(g[i][j] == '+' or g[i][j] == 'o') style++;
			}
		}


		cout << "Case #" << caso << ": ";
		cout << style << " " << res.size() << endl;

		For(i,0,res.size()){
			cout << res[i].model << " " << res[i].x << " " << res[i].y << endl;
		}

		cout << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << g[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
