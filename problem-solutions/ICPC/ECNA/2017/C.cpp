#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;

int main(void){
	cin >> s;
	int len = s.size();

	vi v1, v2;
	for(int i = 0; i < len/2; i++){
		v1.pb(s[i]-'A');
		v2.pb(s[len/2+i]-'A');
	}

	int sum = 0;
	for(int i = 0; i < len/2; i++){
		sum += v1[i];
	}
	for(int i = 0; i < len/2; i++){
		v1[i] += sum;
		v1[i] %= 26;
	}

	sum = 0;
	for(int i = 0; i < len/2; i++){
		sum += v2[i];
	}
	for(int i = 0; i < len/2; i++){
		v2[i] += sum;
		v2[i] %= 26;
	}

	for(int i = 0; i < len/2; i++){
		v1[i] += v2[i];
		v1[i] %= 26;
		cout << char(v1[i]+'A');
	}
	cout << endl;

	return 0;
}