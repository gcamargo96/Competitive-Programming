#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

const int N = 52;
char g[N][N];
int n, m;
ii S, E;
vector<int> dir;
string moves;

bool check(){
	int x = S.fi, y = S.se;

	for(int i = 0; i < moves.size(); i++){
		int d = dir[moves[i] - '0'];

		if(x < 0 or y < 0 or x >= n or y >= m or g[x][y] == '#'){
			return 0;
		}

		if(g[x][y] == 'E'){
			return 1;
		}

		if(d == UP){
			x--;
		}
		if(d == DOWN){
			x++;
		}
		if(d == LEFT){
			y--;
		}
		if(d == RIGHT){
			y++;
		}
	}

	if(x < 0 or y < 0 or x >= n or y >= m or g[x][y] == '#' or g[x][y] == '.'){
		return 0;
	}

	if(g[x][y] == 'E'){
		return 1;
	}

	return 0;
}

int main(void){
	fastcin;
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
			if(g[i][j] == 'S'){
				S.fi = i;
				S.se = j;
			}	

			if(g[i][j] == 'E'){
				E.fi = i;
				E.se = j;
			}
		}
	}

	cin >> moves;

	for(int i = 0; i < 4; i++){
		dir.pb(i);
	}

	int ans = 0;
	do{
		bool ok = check();
		if(ok) ans++;
	}while(next_permutation(dir.begin(), dir.end()));

	cout << ans << endl;

	return 0;
}