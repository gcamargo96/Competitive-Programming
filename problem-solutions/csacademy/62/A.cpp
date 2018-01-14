#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 12;
set<int> s;
int v[N];
int n;

int main(void){
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			s.insert(v[i]+v[j]);
		}
	}

	cout << s.size() << endl;

	return 0;
}