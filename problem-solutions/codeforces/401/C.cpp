#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
int n, m, k;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<int>> b(n, vector<int>(m));
	vector<int> best(n);

	For(i,0,n){
		For(j,0,m){
			cin >> a[i][j];
		}
	}

	For(j,0,m){
		b[0][j] = 1;
	}
	best[0] = 1;
	For(i,1,n){
		For(j,0,m){
			if(a[i][j] >= a[i-1][j]){
				b[i][j] = b[i-1][j] + 1;
			}
			else{
				b[i][j] = 1;
			}
			best[i] = max(best[i], b[i][j]);
		}
	}
	
	/*cout << endl;

	For(i,0,n){
		For(j,0,m){
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

	cout << "best" << endl;
	For(i,0,n){
		cout << best[i] << " ";
	}
	cout << endl;
	*/

	cin >> k;

	int l, r;
	For(i,0,k){
		cin >> l >> r;
		l--, r--;

		if(r-l <= best[r]-1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}

