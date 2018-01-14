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
int pai[N], size[N], op[N];
int n, m, q; 
map<string,int> mapa;

int init() {
    for(int i=0;i <= n;i++) {
        pai[i] = i;
        op[i] = 1e5+i+1;
		pai[op[i]] = op[i];
		size[i] = 0;
    }
}
 
int find (int u) {
	if (pai[u] == u)
		return u;
	else
		return pai[u] = find(pai[u]);
}

bool join (int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;

	if (size[a] < size[b])
		swap(a, b);

	pai[b] = a;
	size[a] += size[b];
	size[b] = 0;

	return true;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	init();

	string s, t;
	int cnt = 0;
	For(i,0,n){
		cin >> s;
		mapa[s] = cnt++;
	}

	int x;
	For(i,0,m){
		cin >> x >> s >> t;
		
		int a = mapa[s], b = mapa[t];
		a = find(a);
		b = find(b);

		op[a] = find(op[a]);
		op[b] = find(op[b]);

		op[op[a]] = a;
		op[op[b]] = b;
		
		if(x == 1){
			if(a == op[b]){
				cout << "NO" << endl;
				continue;
			}
			cout << "YES" << endl;
			join(a, b);
			join(op[a], op[b]);
		}
		else{
			if(a == b){
				cout << "NO" << endl;
				continue;
			}
			cout << "YES" << endl;
			join(a, op[b]);
			join(op[a], b);
		}
	}

	For(i,0,q){
		cin >> s >> t;
		int a = mapa[s], b = mapa[t];
		a = find(a);
		b = find(b);

		if(a == b){
			cout << 1 << endl;
		}
		else if(a == op[b]){
			cout << 2 << endl;
		}
		else{
			cout << 3 << endl;
		}
	}

	return 0;
}
