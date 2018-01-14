#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int n, m;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	ll x, sum = 0;
	For(i,0,n){
		cin >> x;
		sum += (x-1);
		if(sum%2 == 0){
			cout << "2" << endl;
		}
		else cout << "1" << endl;
	}

	return 0;
}
