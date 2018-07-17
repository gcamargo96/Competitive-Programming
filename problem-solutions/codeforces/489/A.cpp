#include <bits/stdc++.h>
using namespace std;
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

const int N = 100005;
int n;
// int v[N];
set<int> s;

int main(void){
	fastcin;
	cin >> n;

	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x != 0) s.insert(x);
	}

	cout << s.size() << endl;
	return 0;
}