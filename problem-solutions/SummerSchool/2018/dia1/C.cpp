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

string s, t;
const int N = 102;
int dp[N][N], opt[N][N];
vector<ii> ans;

int solve(int i, int j){
	if(i == s.size() or j == t.size())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	int ret = 0;
	if(s[i] == t[j]){
		ret = solve(i+1, j+1) + 1;
	}
	else{
		ret = solve(i+1, j);
		int aux = solve(i, j+1);
		if(aux > ret){
			ret = aux;
			opt[i][j] = 1;
		}
	}

	return dp[i][j] = ret;
}

void get_ans(int i, int j){
	if(i == s.size() or j == t.size())
		return;

	if(s[i] == t[j]){
		ans.pb(ii(i,j));
		get_ans(i+1, j+1);
	}
	else if(opt[i][j] == 0){
		get_ans(i+1, j);
	}
	else{
		get_ans(i, j+1);
	}
}

int main(void){
	fastcin;
	cin >> s >> t;

	memset(dp, -1, sizeof dp);
	int subseq = solve(0, 0);
	cout << subseq << endl;

	get_ans(0, 0);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].fi+1 << " ";
	}
	cout << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].se+1 << " ";
	}
	cout << endl;

	return 0;
}