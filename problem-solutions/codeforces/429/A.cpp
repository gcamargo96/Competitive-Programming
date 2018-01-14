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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;
int n, k;
int cnt[30];

int main(void){
	cin >> n >> k >> s;

	for(int i = 0; i < n; i++){
		cnt[s[i]-'a']++;
	}

	bool ans = 1;
	for(int i = 0; i < 26; i++){
		if(cnt[i] > k) ans = 0;
	}

	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}