#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 1000005;
int t, n;
string s;
int acum[N];

int main(void){
	fastcin;
	cin >> t;

	while(t--){
		cin >> s >> n;
		
		int x = min(int(s.size()), n);
		ll sum = 0, ans = 0, cnt = 0;
		for(int i = 0; i < x; i++){
			cnt = 0;
			for(int j = 0; j < s.size(); j++){
				if(s[j] == 'a'){
					sum++;
				}
				else{
					sum--;
				}
				if(sum > 0){
					cnt++;
					ans++;
				}
			}
		}

		if(n > x and cnt > 0){
			ans += ll(n-x)*cnt;
		}

		cout << ans << endl;
	}

	return 0;
}