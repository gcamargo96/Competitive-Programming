#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

string s;
int len;

bool is_palindrome(int l, int r){
	for(int i = l, j = r; i < j; i++, j--){
		if(s[i] != s[j]){
			return 0;
		}
	}
	return 1;
}

int main(void){
	fastcin;
	cin >> s;
	len = s.size();

	int ans = 0;
	for(int i = 0; i < len; i++){
		for(int j = i; j < len; j++){
			if(!is_palindrome(i, j)){
				ans = max(ans, j-i+1);
			}
		}
	}

	cout << ans << endl;

	return 0;
}