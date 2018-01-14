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

const int N = 200002;
string s, t;
vi l[27];
int v[N], rev[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;

	For(i,1,(int)s.size()+1){
		cin >> v[i];
		rev[v[i]] = i;
	}

	For(i,0,s.size()){
		l[s[i]-'a'].pb(rev[i+1]);
	}

	int limit = INF;
	for(int i = t.size()-1; i >= 0; i--){
		int id = t[i]-'a';
		limit = min(limit, l[id][l[id].size()-1]);
		l[id].pop_back();
	}

	int i = 0;
	for(i = 1; i <= (int)s.size(); i++){
		if(v[i] == limit) break;
	}

	cout << i-1 << endl;

	return 0;
}

