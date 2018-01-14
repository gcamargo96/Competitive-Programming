#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define M 1000000007
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

const int N = 3002;
int n;
string s[N];
bool flag[N][N];

int main(void){
	fastcin;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> s[i];
	}

	string ans;
	ans += s[0][0];
	flag[1][0] = flag[1][1] = 1;
	for(int i = 1; i < n; i++){
		char menor = 'z';
		
		for(int j = 0; j <= i; j++){
			if(flag[i][j]){
				// cout << s[i][j] << " ";
				menor = min(menor, s[i][j]);
			}
		}

		// cout << endl;

		ans += menor;

		for(int j = 0; j <= i; j++){
			if(flag[i][j] and menor == s[i][j]){
				flag[i+1][j] = flag[i+1][j+1] = 1;
			}
		}
	}

	cout << ans << endl;

	return 0;
}