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

const int N = 1002;
string fir[N], sec[N];
map<string, int> cnt, id;
set<string> used;
int res[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	string a, b;
	For(i,0,n){
		cin >> a >> b;
		fir[i] = a.substr(0,3);
		sec[i] = a.substr(0,2) + b.substr(0,1);
	
		cnt[fir[i]]++;
	}

	For(i,0,n){
		if(cnt[fir[i]] > 1){
			if(!used.count(sec[i])){
				res[i] = 2;
				id[sec[i]] = i;
				used.insert(sec[i]);
			}
			else{
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	For(i,0,n){
		if(res[i] == 0){
			if(!used.count(fir[i])){
				res[i] = 1;
			}
			else if()
		}
	}

	return 0;
}

