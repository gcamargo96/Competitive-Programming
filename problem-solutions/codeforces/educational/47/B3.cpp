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

string s, ans;
int n;

int main(void){
	fastcin;
	cin >> s;
	n = s.size();

	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			ans += '1';
		}
	}

	for(int i = 0; i < n; i++){
		if(s[i] != '1'){
			ans += s[i];
		}
	}

	for(int i = 0; i < n;){
		if(ans[i] == '2'){
			i++;
			continue;
		}

		int j = i;
		while(j < n and (ans[j] == '0' or ans[j] == '1')){
			j++;
		}
		sort(ans.begin()+i, ans.begin()+j);
		i = j;
	}

	cout << ans << endl;

	return 0;
}