#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 502;
char g[N][N];
int n, m;

int main(void){
	fastcin;
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> g[i][j];
			if(g[i][j] == '.'){
				g[i][j] = 'D';
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == 'S'){
				if(g[i+1][j] == 'W' or g[i][j+1] == 'W' or g[i-1][j] == 'W' or g[i][j-1] == 'W'){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}

	cout << "Yes" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << g[i][j];
		}
		cout << endl;
	}


	return 0;
}