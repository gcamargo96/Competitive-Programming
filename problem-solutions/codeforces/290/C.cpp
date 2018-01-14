#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 102;
string s[N], r[N];
int n;
char res[28];

void init(){
	For(i,0,26){
		res[i] = 'a'+i;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	init();
	cin >> n;

	For(i,0,n){
		cin >> s[i];
		r[i] = s[i];
		sort(r[i].begin(), r[i].end());
	}

	For(i,1,n){
		while(r[i-1] > r[i]){
			next_permutation(r[i].begin(), r[i].end());
		}
	}

	For(i,0,n){
		cout << r[i] << endl;
	}

	/*For(i,0,n){
		For(j,0,s[i].size()){
			//res[s[i][j]-'a'] = r[i][j];
			swap(s[i], s[r[i][j]-'a']);
		}
	}*/

	/*For(i,0,26){
		cout << res[i];
	}
	cout << endl;
	*/
	return 0;
}
