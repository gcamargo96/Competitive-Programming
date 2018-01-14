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

ll b, d, s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> b >> d >> s;

	ll res = 0;
	if(b >= d and b >= s){
		if(b == 1) res = 0;
		else{
			if(d > 0) res += b-d-1;
			else res += b-d;
			if(s > 0) res += b-s-1;
			else res += b-s;
		}
	}
	else if(d >= b and d >= s){
		if(d == 1) res = 0;
		else{
			if(b > 0) res += d-b-1;
			else res += d-b;
			if(s > 0) res += d-s-1;
			else res += d-s;
		}
	}
	else if(s >= b and s >= d){
		if(s == 1) res = 0;
		else{
			if(b > 0) res += s-b-1;
			else res += s-b;
			if(d > 0) res += s-d-1;
			else res += s-d;
		}
	}

	cout << res << endl;

	return 0;
}

