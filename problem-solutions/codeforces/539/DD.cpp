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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;

bool palindrome(int i, int j){
	for(int l = i, r = j; l < r; l++, r--){
		if(s[l] != s[r]) return 0;
	}
	return 1;
}

int solve(int l, int r){
	if(l == r) return 0;

	if(palindrome(l, l + (l+r-1)/2)){
		return solve(l, l + (l+r-1)/2);
	}
	return (r-l+1)%2 == 0 ? 1 : 2;
}

int main(void){
	fastcin;
	cin >> s;

	int ans = solve(0, s.size()-1);

	if(ans > 0){
		printf("%d\n", ans);
	}
	else{
		printf("Impossible\n");
	}

	return 0;
}