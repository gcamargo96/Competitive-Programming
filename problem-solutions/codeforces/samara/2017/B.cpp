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
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 200202;
int p[N];
string s, t;

void prefix_function(string& s){
	int n = s.size();
	for(int i = 2; i <= n; i++){
		p[i] = p[i-1];
		while(p[i] > 0 and s[p[i]] != s[i-1])
			p[i] = p[p[i]];
		if(s[p[i]] == s[i-1])
			p[i]++;
	}
}

int main(void){
	fastcin;
	cin >> t;
	string s("happiness#");
	s += t;

	prefix_function(s);
	// cout << s << endl;
	// cout << "s.size() = " << s.size() << endl;

	int cnt = 0, r1 = 0, r2 = 0;
	for(int i = 1; i <= s.size(); i++){
		if(p[i] == 9){
			// cout << i << endl;
			if(cnt == 0){
				r1 = i-10;
			}
			else if(cnt == 1){
				r2 = i-10;
			}
			cnt++;
		}
	}

	if(cnt > 2){
		cout << "NO" << endl;
	}
	else if(cnt == 2){
		cout << "YES" << endl;
		cout << r1 << " " << r2-2 << endl;
	}
	else if(cnt == 1){
		cout << "YES" << endl;
		cout << r1 << " " << r1-2 << endl;
	}
	else{
		cout << "YES" << endl;
		if(t.size() < 9){
			cout << 1 << " " << 2 << endl;
		}
		else{
			for(int i = 1; i < t.size(); i++){
				swap(t[0], t[i]);
				s = "happiness#" + t;
				prefix_function(s);
				bool ok = 1;
				for(int j = 1; j <= s.size(); j++){
					if(p[j] == 9){
						ok = 0;
						break;
					}
				}
				if(ok){
					cout << "1 " << i+1 << endl;
					break;
				}
				swap(t[0], t[i]);
			}
		}
	}

	return 0;
}