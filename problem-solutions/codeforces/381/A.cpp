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

ll n, k, a, b, c;

int main(void){
	//scanf("%d%d%d%d", &n, &a, &b, &c);
	cin >> n >> a >> b >> c;

	if(n%4 == 0){
		printf("0\n");
		return 0;
	}
	
	ll res = 1000000000000000;
	if(4 - n%4 == 1){
		res = min(res, a);
		res = min(res, b+c);
		res = min(res, 3*c);
	}
	else if(4 - n%4 == 2){
		res = min(res, 2*a);
		res = min(res, b);
		res = min(res, 2*c);
	}
	else if(4 - n%4 == 3){
		res = min(res, 3*a);
		res = min(res, a+b);
		res = min(res, c);
	}

	cout << res << endl;
	
	/*b = min(b, 2*a);
	c = min(c, 3*a);
	c = min(c, a+b);
	*/


	return 0;
}

