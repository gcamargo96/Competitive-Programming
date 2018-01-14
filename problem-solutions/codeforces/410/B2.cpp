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

const int N = 52;
int n;
string s[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n){
		cin >> s[i];
	}

	For(i,0,n){
		For(j,0,s[i].size()){
			string aux;
			For(k,0,s[i].size()){
				aux += s[(j+k)%s[i].size()];
			}
			
			for(int l = 1; l < n; l++){
				For(k,0,s[l].size()){
					
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}

