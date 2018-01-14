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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;
int choice[4][100];

bool solve(int i, int sum){
	if(i == 4){
		if(sum == 7) return 1;
		return 0;
	}
	bool a = solve(i+1, sum + (s[i]-'0'));
	bool b = solve(i+1, sum - (s[i]-'0'));

	if(a) choice[i][sum] = 0;
	else choice[i][sum] = 1;

	return a or b;
}

void printans(int i, int sum){
	if(i == 4){
		// cout << s[i] << "=7" <<  endl;
		cout << "=7" << endl;
		return;
	}

	if(choice[i][sum] == 0){
		cout << "+" << s[i];
		printans(i+1, sum+(s[i]-'0'));
	}
	else{
		cout << "-" << s[i];
		printans(i+1, sum-(s[i]-'0'));
	}
}

int main(void){
	cin >> s;

	solve(1, s[0]-'0');

	cout << s[0];
	printans(1, s[0]-'0');

	return 0;
}