#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

vector<int> a3, b3, c;
int a, b;

ll POW(int b, int e){
	ll ret = 1;
	For(i, 0, e){
		ret *= b;
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> a >> b;

	int x;
	while(a > 0){
		x = a%3;
		a3.pb(x);
		a /= 3;
	}

	while(b > 0){
		x = b%3;
		b3.pb(x);
		b /= 3;
	}

	while(a3.size() > b3.size()){
		b3.pb(0);
	}
	while(b3.size() > a3.size()){
		a3.pb(0);
	}

	/*for(int i = a3.size(); i >= 0; i--){
		cout << a3[i] << " ";
	}
	cout << endl;
	for(int i = b3.size(); i >= 0; i--){
		cout << b3[i] << " ";
	}
	cout << endl;
	*/

	For(i, 0, a3.size()){
		x = 0;
		while((a3[i]+x)%3 != b3[i]) x++;
		c.pb(x);
	}

	for(int i = c.size()-1; i >= 0; i--){
		if(c[i] != 0) break;
		else{
			c.pop_back();
		}
	}

	/*for(int i = c.size()-1; i >= 0; i--){
		cout << c[i] << " ";
	}
	cout << endl;
	*/

	ll res = 0;
	for(int i = 0; i < c.size(); i++){
		res += c[i] * POW(3, i);
		//cout << c[i] << " * " << POW(3, i) << endl;
	}

	cout << res << endl;

	return 0;
}
