#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
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
int f[3];

int main(void){
	cin >> s;

	int flag = 0;

	for(int i = 1; i < s.size(); i++){
		if(s[i] == 'c' and s[i-1] == 'a'){
			cout << "NO" << endl;
			return 0;
		}
		if(s[i] == 'a' and s[i-1] != 'a'){
			cout << "NO" << endl;
			return 0;			
		}
		if(s[i] == 'b' and s[i-1] == 'c'){
			cout << "NO" << endl;
			return 0;						
		}
	}

	for(int i = 0; i < s.size(); i++){
		f[s[i]-'a']++;
	}

	if(f[0] == 0 or f[1] == 0 or f[2] == 0){
		cout << "NO" << endl;
		return 0;
	}

	if(f[2] == f[0] or f[2] == f[1]){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}