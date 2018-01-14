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

map<string, int> cnt;
int n, m;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	int k;
	string s;
	For(i,0,n){
		cin >> k;
		For(j,0,k){
			cin >> s;
			cnt[s]++;
		}
	}

	cin >> m;

	For(i,0,m){
		cin >> k;
		int res = INF;
		For(j,0,k){
			cin >> s;
			res = min(res, cnt[s]);
		}
		cout << res << endl;
	}

	return 0;
}

