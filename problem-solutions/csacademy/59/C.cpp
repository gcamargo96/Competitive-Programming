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
string s[N], ans;
bool adj[N][30][30];

void dfs(int row, int c){
	// cout << "dfs" << endl;
	ans += c+'a';
	if(row == n)
		return;

	for(int i = 0; i < 26; i++){
		if(adj[row][c][i] == 1){
			dfs(row+1, i);
			break;
		}
	}
}

int main(void){
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = "#" + s[i];
	}

	for(int i = 1; i < n; i++){
		for(int j = 1; j <= i; j++){
			// cout << "a";
			// cout << s[i][j] << "->" << s[i+1][j] << " e " << s[i+1][j+1] << endl;
			adj[i][s[i][j]-'a'][s[i+1][j]-'a'] = 1;
			adj[i][s[i][j]-'a'][s[i+1][j+1]-'a'] = 1;
		}
		// cout << endl;
	}

	dfs(1, s[1][1]-'a');

	cout << ans << endl;

	return 0;
}