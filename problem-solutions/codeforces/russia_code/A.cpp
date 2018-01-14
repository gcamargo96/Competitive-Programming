#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define pii pair<int,int>

int t, a, b, c, d;
string res;

void solve(list<char> s, int a, int b, int c, int d, int n){
	//list<int> aux = s;
	if(s.size() == n){
		auto it = s.begin();
		while(it != s.end()){
			res += *it;
			it++;
			return;
	}

	bool flag = 0;
	if(s.size() > 0){
		if(a > 0){
			if(s.back() != 0){
				s.pb(0);
				flag = 1;
			}
			s.pb(0);
			solve(s, a-1, b, c, d, n);
			if(flag) s.pop_back();
			s.pop_back();
			if(s.front() != 0)s.pf(0);
			s.pf(0);
			solve(s, a-1, b, c, d, n);
			s.pop_front();
			s.pop_front();
			flag = 0;
		}
		if(b > 0){
			if(s.back != 0){
				s.pb(0);
				flag = 1;
			}
			s.pb(0);
			solve(s, a-1, b, c, d, n);
			if(!flag) s.pop_back();
			s.pop_back();
			s.pf(0);
			s.pf(0);
			solve(s, a-1, b, c, d, n);
			s.pb(
			flag = 0;
		}
		if(c > 0){
			s.pb(0);
			s.pb(0);
			solve(s, a-1, b, c, d, n);
			s.pop_back();
			s.pop_back();
			s.pf(0);
			s.pf(0);
			solve(s, a-1, b, c, d, n);
		}
	}
	else{
		
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		cin >> a >> b >> c >> d;
		list<int> s;
		solve(s, a, b, c, d, a+b+c+d+1);
	}

	return 0;
}
