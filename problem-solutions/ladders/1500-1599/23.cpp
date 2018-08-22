#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 1000002;
bool p[N];
vector<ll> res;
int n;
ll x;

void sieve(){
	for(ll i = 2; i < N; i++){
		if(p[i] == 0){
			res.pb(i*i);
			for(int j = i; j < N; j += i){
				p[j] = 1;
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);

	
	cin >> n;

	For(i,0,n){
		cin >> x;
		if(binary_search(res.begin(), res.end(), x)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
