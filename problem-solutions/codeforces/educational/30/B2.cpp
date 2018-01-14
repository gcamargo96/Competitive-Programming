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

const int N = 100002;
int n;
string s;
// int sum[N];

int main(void){
	fastcin;
	cin >> n >> s;
	s = "#" + s;

	// for(int i = 1; i <= n; i++){
	// 	sum[i] = sum[i-1] + (s[i]-'0');
	// }

	int ans = 0, sum = 0;
	for(int i = 1; i <= n; i++){
		sum += s[i]-'0';
		ans = max(ans, 2*min(i-sum, i-(i-sum)));
	}

	cout << ans << endl;

	return 0;
}