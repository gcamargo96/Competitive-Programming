#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 500002;
string s[N];
int n;
int lim[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n){
		cin >> s[i];
	}
	
	for(int i = n-1; i > 0; i--){
		int j;
		bool ok = 0;
		for(j = 0; j < min(s[i].size(),s[i-1].size()); j++){
			if(s[i][j] < s[i-1][j]){
				ok = 0;
				break;
			}
			if(s[i][j] > s[i-1][j]){
				ok = 1;
				break;
			}
		}
		if(j == 0) j++;
		if(ok == 0) s[i-1].erase(s[i-1].begin()+j, s[i-1].end());
	}

	For(i,0,n){
		cout << s[i] << endl;
	}

	return 0;
}

