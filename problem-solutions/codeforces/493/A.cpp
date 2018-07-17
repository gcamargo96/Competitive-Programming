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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 12;
int v[N];
int n;

int main(void){
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	if(n == 1){
		cout << -1 << endl;
		return 0;
	}

	for(int i = 0; i < n; i++){
		int a = v[i], b = 0;
		for(int j = 0; j < n; j++){
			if(i != j){
				b += v[j];
			}
		}
		// cout << a << " " << b << endl;
		if(a != b){
			cout << 1 << endl;
			cout << i+1 << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}