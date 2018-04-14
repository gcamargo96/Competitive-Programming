#include <bits/stdc++.h>
using namespace std;
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

const int N = 52;
string s[N];
int n;

int main(void){
	fastcin;
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}

	set<int> ans;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			string aux;
			aux = s[i] + s[j];
			for(int k = 1; k <= n; k++){
				if(aux == s[k]){
					ans.insert(k);
				}
			}
		}
	}

	for(int x : ans){
		cout << x << " ";
	}
	cout << endl;

	return 0;
}