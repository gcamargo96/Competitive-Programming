#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 52;
int n;
int g[N][N];

int main(void){
	fastcin;
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> g[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(g[i][j] == 1) continue;

			bool ok = 0;
			for(int s = 0; s < n; s++){
				for(int t = 0; t < n; t++){
					if(g[i][s] + g[t][j] == g[i][j]){
						ok = 1;
					}
				}
			}

			if(!ok){
				// cout << i << " " << j << endl;
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;

	return 0;
}