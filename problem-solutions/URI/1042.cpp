#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

vi v1, v2;

int main(void){
	int x;
	for(int i = 0; i < 3; i++){
		cin >> x;
		v1.pb(x);
	}
	v2 = v1;

	sort(v2.begin(), v2.end());

	for(int i = 0; i < 3; i++){
		cout << v2[i] << endl;
	}

	cout << endl;

	for(int i = 0; i < 3; i++){
		cout << v1[i] << endl;
	}

	return 0;
}