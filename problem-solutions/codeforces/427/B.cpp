#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int k;
string s;

int calc(){
	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		sum += s[i]-'0';
	}
	return sum;
}

int main(void){
	cin >> k >> s;

	sort(s.begin(), s.end());
	int sum = calc();

	int ans = 0;
	for(int i = 0; i < s.size() and sum < k; i++){
		sum -= s[i]-'0';
		sum += 9;
		ans++;
	}

	cout << ans << endl;

	return 0;
}