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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int n;
string s;
vi pos[2*N];

int main(void){
	fastcin;
	cin >> n >> s;
	s = "#" + s;

	int sum = 0;
	pos[N].pb(0);
	for(int i = 1; i <= n; i++){
		if(s[i] == '0') sum--;
		if(s[i] == '1') sum++;
		pos[sum+N].pb(i);
	}

	int ans = 0;
	for(int i = 0; i < 2*N; i++){
		if(pos[i].size() > 1){
			ans = max(ans, pos[i][pos[i].size()-1] - pos[i][0]);
		}
	}

	cout << ans << endl;

	return 0;
}