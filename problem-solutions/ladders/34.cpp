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
string s;
int m, l, r;
int cnt[N];

int main(void){
	ios_base::sync_with_stdio(false);
	
	string aux;
	s += ' ';
	cin >> aux;
	s += aux;

	for(int i = 1; i < s.size()-1; i++){
		cnt[i] = cnt[i-1];
		if(s[i] == s[i+1]) cnt[i]++;
	}

	cin >> m;

	For(i,0,m){
		cin >> l >> r;
		cout << cnt[r-1]-cnt[l-1] << endl;
	}

	return 0;
}

