#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

string s;

int main(void){
	cin >> s;

	int ans = 0;
	for(char c : s){
		if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
			ans++;
		if(c == '1' or c == '3' or c == '5' or c == '7' or c == '9')
			ans++;
	}

	cout << ans << endl;

	return 0;
}