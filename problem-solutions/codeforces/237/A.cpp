#include <bits/stdc++.h>
using namespace std;
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

const int N = 302;
char d, nd;
char g[N][N];
int n;

int main(void){
	fastcin;
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> g[i][j];
		}
	}

	d = g[0][0];
	nd = g[0][1];

	if(d == nd){
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++){
		if(g[i][i] != d or g[i][n-i-1] != d){
			cout << "NO" << endl;
			return 0;
		}
		for(int j = 0; j < n; j++){
			if(i == j or j == n-i-1){
				continue;
			}
			else{
				if(g[i][j] != nd){
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}