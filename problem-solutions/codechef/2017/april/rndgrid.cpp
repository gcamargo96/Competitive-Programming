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

const int N = 1002;
char g[N][N];
int t, l, n;
string s;

void init(){
	for(int i = 0; i <= n+1; i++){
		g[i][0] = g[i][n+1] = '#';
		g[0][i] = g[n+1][i] = '#';
	}
}

int move(int x, int y){
	int ret = 0;
	For(i,0,s.size()){
		if(s[i] == 'L'){
			if(g[x][y-1] == '.'){
				y--;
				ret++;
			}
			else{
				return ret;
			}
		}
		if(s[i] == 'R'){
			if(g[x][y+1] == '.'){
				y++;
				ret++;
			}
			else{
				return ret;
			}
		}
		if(s[i] == 'D'){
			if(g[x+1][y] == '.'){
				x++;
				ret++;
			}
			else{
				return ret;
			}
		}
		if(s[i] == 'U'){
			if(g[x-1][y] == '.'){
				x--;
				ret++;
			}
			else{
				return ret;
			}
		}
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		cin >> l >> n;
		cin >> s;

		init();

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> g[i][j];
			}
		}

		int res = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(g[i][j] == '.') res ^= move(i, j);
			}
		}

		cout << res << endl;
	}
	
	return 0;
}

