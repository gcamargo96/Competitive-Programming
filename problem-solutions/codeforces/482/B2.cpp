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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef complex<double> base;

int n;
string a, b, c;
map<char,int> ma, mb, mc;
vector<pair<int,char> > va, vb, vc;
int len;

void segments(vector<pair<int,char> >& v, string& s, map<char,int>& m){
	int cnt = 0;
	for(int i = 0; i < len; i++){
		m[s[i]]++;
		cnt++;
		if(s[i] != s[i+1]){
			v.pb(mp(cnt, s[i]));
			cnt = 0;
		}
	}	
}

int calc_ans(vector<pair<int,char> >& v, map<char,int>& m){
	int ans = 0;
	for(auto it = m.begin(); it != m.end(); it++){
		int aux = it->se, turns = 0;
		for(int i = 0; i < v.size() and turns < n; i++){
			if(v[i].se != it->fi){
				aux += v[i].fi;
				turns++;
			}
		}
		if(turns < n){
			int last = n-turns;
			// if(last%2 == 1){
			// 	aux--;
			// }
			bool ok = 0;
			for(int i = int(v.size()-1); i >= 0; i--){
				if(v[i].fi >= 2){
					ok = 1;
				}
			}
			if(!ok){
				aux--;
			}
		}

		ans = max(ans, aux);
	}
	return ans;
}

int main(void){
	fastcin;
	cin >> n;
	cin >> a >> b >> c;
	len = a.size();
	a += '#';
	b += '#';
	c += '#';

	segments(va, a, ma);
	segments(vb, b, mb);
	segments(vc, c, mc);

	sort(va.begin(), va.end(), greater<pair<int,char> >());
	sort(vb.begin(), vb.end(), greater<pair<int,char> >());
	sort(vc.begin(), vc.end(), greater<pair<int,char> >());

	// for(int i = 0; i < va.size(); i++){
	// 	cout << va[i].fi << " " << va[i].se;
	// }

	int ansa = calc_ans(va, ma);
	int ansb = calc_ans(vb, mb);
	int ansc = calc_ans(vc, mc);

	// printf("%d %d %d\n", ansa, ansb, ansc);

	if(ansa > ansb and ansa > ansc){
		cout << "Kuro" << endl;
	}
	else if(ansb > ansa and ansb > ansc){
		cout << "Shiro" << endl;
	}
	else if(ansc > ansa and ansc > ansb){
		cout << "Katie" << endl;
	}
	else{
		cout << "Draw" << endl;
	}

	return 0;
}