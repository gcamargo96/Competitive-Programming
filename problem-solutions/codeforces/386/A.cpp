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

int a, b, c;

int main(void){
	cin >> a >> b >> c;

	int res = 0;
	for(int i = 0; i <= a; i++){
		if(b >= 2*i and c >= 4*i){
			res = max(res, i + 2*i + 4*i);
		}
	}

	cout << res << endl;

	return 0;
}

