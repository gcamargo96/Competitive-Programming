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

const int N = 11;
char g[N][N];
int x, y;

bool full(int qx, int qy){
	for(int i = 3*qx; i < 3*qx+3; i++){
		for(int j = 3*qy; j < 3*qy+3; j++){
			if(g[i][j] == '.')
				return 0;
		}
	}
	return 1;
}

int main(void){
	fastcin;

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> g[i][j];
		}
	}

	cin >> x >> y;
	x--, y--;

	int qx = x/3, qy = y/3;
	int rx = x%3, ry = y%3;

	if(!full(rx, ry)){
		for(int i = 3*rx; i < 3*rx+3; i++){
			for(int j = 3*ry; j < 3*ry+3; j++){
				if(g[i][j] == '.')
					g[i][j] = '!';
			}
		}
	}
	else{
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(g[i][j] == '.')
					g[i][j] = '!';
			}
		}
	}

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(j == 3 or j == 6){
				cout << " ";
			}

			cout << g[i][j];	

			if((i == 2 or i == 5) and j == 8){
				cout << endl;
			}
		}
		cout << endl;
	}

	return 0;
}