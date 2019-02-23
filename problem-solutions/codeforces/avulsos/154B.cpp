#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int n, m;
char op;
int v[N], vis[N];

int conflict(int x){
	if(vis[x] > 0) return vis[x];

	for(int i = 2; i*i <= x; i++){
		if(x%i == 0){
			int j = x/i;
			if(vis[i] > 0){
				return vis[i];
			}
			if(vis[j] > 0){
				return vis[j];
			}
		}
	}

	return 0;
}

void mark(int x){
	for(int i = 2; i*i <= x; i++){
		if(x%i == 0){
			int j = x/i;
			vis[i] = x;
			vis[j] = x;
		}
	}
	vis[x] = x;
	v[x] = 1;
}

void unmark(int x){
	for(int i = 2; i*i <= x; i++){
		if(x%i == 0){
			int j = x/i;
			vis[i] = 0;
			vis[j] = 0;
		}
	}
	vis[x] = 0;
	v[x] = 0;
}

int main(void){
	fastcin;
	cin >> n >> m;

	int x;
	for(int i = 0; i < m; i++){
		cin >> op >> x;
		
		if(op == '+'){
			int conf = conflict(x);
			if(v[x]){
				cout << "Already on" << endl;
			}
			else if(conf){
				cout << "Conflict with " << conf << endl;
			}
			else{
				mark(x);
				cout << "Success" << endl;
			}
		}
		else{ // op == '-'
			if(v[x] == 1){
				unmark(x);
				cout << "Success" << endl;
			}
			else{
				cout << "Already off" << endl;
			}
		}
	}

	return 0;
}