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

const int N = 52;
int n, m;
string s[N];
int dn[N], ds[N], dl[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	For(i,0,n){
		cin >> s[i];
	}

	//memset(dn, 1000, sizeof dn);
	//memset(ds, 1000, sizeof ds);
	//memset(dl, 1000, sizeof dl);

	For(i,0,N){
		dn[i] = 1000;
		dl[i] = 1000;
		ds[i] = 1000;
	}

	For(i,0,n){
		for(int j = 0; j <= m/2; j++){
			if(s[i][j] >= 'a' and s[i][j] <= 'z'){
				dl[i] = min(dl[i], j);
			}
			if(s[i][j] >= '0' and s[i][j] <= '9'){
				dn[i] = min(dn[i], j);
			}
			if(s[i][j] == '#' or s[i][j] == '*' or s[i][j] == '&'){
				ds[i] = min(ds[i], j);
			}
		}
	
		for(int j = m-1; j > m/2; j--){
			if(s[i][j] >= 'a' and s[i][j] <= 'z'){
				dl[i] = min(dl[i], m-j);
			}
			if(s[i][j] >= '0' and s[i][j] <= '9'){
				dn[i] = min(dn[i], m-j);
			}
			if(s[i][j] == '#' or s[i][j] == '*' or s[i][j] == '&'){
				ds[i] = min(ds[i], m-j);
			}	
		}
	}

	int res = INF;
	For(i,0,n){
		For(j,0,n){
			For(k,0,n){
				if(i != j and i != k and j != k){
					res = min(res, dl[i] + dn[j] + ds[k]);
				}
			}
		}
	}

	printf("%d\n", res);

	return 0;
}

