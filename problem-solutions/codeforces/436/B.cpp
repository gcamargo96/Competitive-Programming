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

int n;
string s;
int cnt[202];


int main(void){
	fastcin;
	cin >> n >> s;

	int ans = 0;
	for(int i = 0; i < n; i++){
		int sum = 0;
		memset(cnt, 0, sizeof cnt);
		for(int j = i; j < n; j++){
			if(s[j] >= 'A' and s[j] <= 'Z') break;
			if(cnt[s[j]] == 0) sum++;
			cnt[s[j]]++;
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;

	return 0;
}