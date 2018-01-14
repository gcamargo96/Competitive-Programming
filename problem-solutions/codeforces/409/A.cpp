#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

string s;

int main(void){
	cin >> s;

	if(s.size() == 1){
		cout << 0 << endl;
		return 0;
	}
	if(s.size() == 2){
		if(s == "KV") cout << 0 << endl;
		else cout << 1 << endl;
		return 0;
	}

	int cnt = 0;
	bool foi = 0;

	if(s[0] == 'V' and s[1] == 'V'){
		s[1] = 'K';
		foi = 1;
	}
	if(s[0] == 'K' and s[1] == 'K'){
		s[0] = 'V';
		foi = 1;
	}
	if(s[s.size()-2] == 'V' and s[s.size()-1] == 'V'){
		s[s.size()-1] = 'K';
		foi = 1;
	}
	if(s[s.size()-2] == 'K' and s[s.size()-1] == 'K'){
		s[s.size()-2] = 'V';
		foi = 1;
	}
	if(!foi){
		For(i,1,s.size()-2){
			if(s[i] == 'V' and s[i+1] == 'V' and s[i+2] == 'V'){
				s[i+1] = 'K';
				foi = 1;
				break;
			}
		}
	}

	if(!foi){	
		For(i,1,s.size()-2){
			if(s[i] == 'K' and s[i+1] == 'K' and s[i+2] == 'K'){
				s[i+1] = 'V';
				foi = 1;
				break;
			}
		}
	}


	For(i,0,s.size()-1){
		if(s[i] == 'V' and s[i+1] == 'K'){
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}

