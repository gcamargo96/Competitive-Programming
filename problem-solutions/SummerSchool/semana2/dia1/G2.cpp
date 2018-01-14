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

map<vector<string>, int> cnt;
int n, m;
vector<string> aux;

void go(vector<string>& v, int i){
	if(i == v.size()){
		if(aux.size() > 0) cnt[aux]++;
		return;
	}

	aux.pb(v[i]);
	go(v, i+1);
	aux.pop_back();
	go(v, i+1);
}

int main(void){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;

	
	int k;
	string s;
	For(i,0,n){
		cin >> k;
		vector<string> v;
		For(j,0,k){
			cin >> s;
			v.pb(s);
		}
		sort(v.begin(), v.end());
		go(v,0);
	}

	cin >> m;

	For(i,0,m){
		cin >> k;
		vector<string> v;
		For(j,0,k){
			cin >> s;
			v.pb(s);
		}
		sort(v.begin(), v.end());
		cout << cnt[v] << endl;
	}

	return 0;
}

