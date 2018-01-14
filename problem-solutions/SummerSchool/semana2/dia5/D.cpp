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

ll A, B, C;

ll f(ll x){
	return (A*x + x%B)%C;
}

int main(void){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> A >> B >> C;

	ll tortoise = f(1), hare = f(f(1)), cnt = 0;
	while(tortoise != hare){
		if(cnt == 20000000){
			cout << -1 << endl;
			return 0;
		}
		tortoise = f(tortoise);
		hare = f(f(hare));
		cnt++;
	}

	int mu = 0; hare = 1; cnt = 0;
	while(tortoise != hare){
		if(cnt == 20000000){
			cout << -1 << endl;
			return 0;
		}
		tortoise = f(tortoise);
		hare = f(hare);
		mu++;
		cnt++;
	}

	int lambda = 1; hare = f(tortoise);
	while(tortoise != hare){
		if(cnt == 20000000){
			cout << -1 << endl;
			return 0;
		}
		hare = f(hare);
		lambda++;
		cnt++;
	}

	cout << mu+lambda << endl;
	
	//cout << -1 << endl;

	return 0;
}

