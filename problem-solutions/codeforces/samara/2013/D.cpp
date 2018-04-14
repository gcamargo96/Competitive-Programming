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

int n;
string a, b, c, ans;

int main(void){
	fastcin;
	cin >> n >> a >> b >> c;

	for(int i = 0; i < n; i++){
		map<char,int> cnt;
		cnt[a[i]]++;
		cnt[b[i]]++;
		cnt[c[i]]++;
		
		int maior = 0;
		char c;
		for(auto it : cnt){
			if(it.se > maior){
				maior = it.se;
				c = it.fi;
			}
		}

		ans += c;
	}

	cout << ans << endl;

	return 0;
}