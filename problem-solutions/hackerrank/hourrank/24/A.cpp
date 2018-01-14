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

int n;
string s;
string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> s;

	int num = 0, low = 0, up = 0, spec = 0;
	for(int i = 0; i < n; i++){
		if(numbers.find(s[i]) != string::npos) num = 1;
		if(lower_case.find(s[i]) != string::npos) low = 1;
		if(upper_case.find(s[i]) != string::npos) up = 1;
		if(special_characters.find(s[i]) != string::npos) spec = 1;
	}

	// cout << num << " " << low << " " << up << " " << spec << endl;

	int falta = 4 - num - low - up - spec;
	 n += falta;
	if(n < 6) falta += 6-n;

	cout << falta << endl;

	return 0;
}