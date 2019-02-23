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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int t, n;
set<int> s;

int main(void){
	s.insert(2010);
	s.insert(2015);
	s.insert(2016);
	s.insert(2017);
	s.insert(2019);

	cin >> t;

	while(t--){
		cin >> n;
		if(s.count(n)){
			cout << "HOSTED" << endl;
		}
		else{
			cout << "NOT HOSTED" << endl;
		}
	}

	return 0;
}