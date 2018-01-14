#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

struct block{
	ll tam;
   	int	l, r;

	block() {}

	block(int _tam, int _l, int _r){
		tam = _tam;
		l = _l;
		r = _r;
	}
};

const int N = 100002;
int t;
string s;
vector<block> blocks;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;
	
	while(t--){
		blocks.clear();
		cin >> s;

		int i, cnt = 0, l, r;
		bool comecou = 0, terminou = 0;
		for(i = 0; i < s.size(); i++){
			if(s[i] == '1'){
				if(!comecou){
					l = i;
					comecou = 1;
				}
				cnt++;
			}
			if(comecou and s[i] == '0'){
				r = i-1;
				blocks.pb(block(r-l+1,l,r));
				comecou = 0;
			}
		}
		if(comecou){
			r = s.size()-1;
			blocks.pb(block(r-l+1,l,r));
		}

		/*For(i,0,blocks.size()){
			cout << "tam/l/r = " << blocks[i].tam << " " << blocks[i].l << " " << blocks[i].r << endl;
		}*/

		ll res = 0;
		For(i,1,blocks.size()){
			res += blocks[i-1].tam + blocks[i-1].tam * (ll)(blocks[i].l - blocks[i-1].r-1);
			blocks[i].tam += blocks[i-1].tam;
		}
		int n = blocks.size();
		if(n > 0 and blocks[n-1].r < s.size()-1)
			res += blocks[n-1].tam * (s.size() - blocks[n-1].r);

		cout << res << endl;
	}

	return 0;
}
