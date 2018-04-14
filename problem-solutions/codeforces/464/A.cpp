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

const int N = 5002;
int n;
int f[N];

int main(void){
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> f[i];
	}

	bool ans = 0;
	for(int i = 1; i <= n; i++){
		if(i == f[f[f[i]]]){
			ans = 1;
		}
	}

	if(ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}