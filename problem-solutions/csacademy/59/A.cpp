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

int n;
string s;
map<char,int> cnt;

int main(void){
	cin >> n >> s;

	for(int i = 0; i < s.size(); i++){
		cnt[s[i]]++;
	}

	for(int i = 0; i < s.size(); i++){
		if(cnt[s[i]] == 1){
			cout << s[i] << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}