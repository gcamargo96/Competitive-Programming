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

const int N = 100002;
int n, a, b;
string s;

int main(void){
	cin >> n >> a >> b;
	cin >> s;
	
	a--, b--;
	if(s[a] == s[b]){
		cout << 0 << endl;
		return 0;
	}

	int res = INF;
	for(int i = a; i > 0; i--){
		if(s[i-1] == s[b]){
			res = min(res, 1);
		}
	}
	for(int i = a; i < n-1; i++){
		if(s[i+1] == s[b]){
			res = min(res, 1);
		}
	}

	if(res == INF)
		cout << abs(b-a) << endl;
	else
		cout << res << endl;

	return 0;
}

