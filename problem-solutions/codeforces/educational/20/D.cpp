#include <bits/stdc++.h>
using namespace std;
#define INF 2000002
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100002;
int n, ans = INF;
vector<int> v;

bool check(int x){
	// if(n == 1 and x < v[0]-1) return 0;
	// if(n > 1 and x < v[0]) return 0;

	// if(x == 7) cout << "testou o 7" << endl;

	int cnt = 1, sum = 0, best = INF;
	for(int i = 0; i < v.size(); i++){
		if(v[i] > x) return 0;
		if(sum + v[i] > x){
			// best = min(sum, best);
			sum = v[i];
			cnt++;
		}
		else{
			sum += v[i];
		}
	}


	// cout << "testou 7, cnt = " << cnt << endl;

	if(cnt <= n){
		// cout << "deu bom em " << x << " cnt = " << cnt << endl; 
		// ans = best;
		return 1;
	}
	// cout << "deu ruim em << " << x << " cnt = " << cnt << endl;
	return 0;
}

int bin_search(){
	int l = 0, r = 1000002;

	int last = r;
	while(l <= r){
		// cout << "l = " << l << " r = " << r << endl;
		int m = (l+r)/2;
		if(check(m)){
			last = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	return last;
}

int main(void){
	ios_base::sync_with_stdio(false);
	// memset(dp, -1, sizeof dp);
	cin >> n;
	cin.get();

	string s;
	getline(cin, s);
	// cout << s << endl;
	int tam = 0;
	for(int i = 0; i < s.size(); i++){
		tam++;
		if(s[i] == ' ' or s[i] == '-'){
			v.pb(tam);
			tam = 0;
		}
	}
	v.pb(tam);

	/*cout << "sz = " << v.size() << endl;

	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	*/

	ans = bin_search();

	cout << ans << endl;

	return 0;
}