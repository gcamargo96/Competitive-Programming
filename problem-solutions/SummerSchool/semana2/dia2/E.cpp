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

const int N = 1000002;
string s, t, cat, catr;
vi z(2*N), zr(2*N);
int k;

void Z(string& s, vector<int>& z){
	int l = 0, r = 0, n = s.size();
	for(int i = 1; i < n; i++){
		if(i <= r)
			z[i] = min(z[i-l], r-i+1);
		while(z[i]+i < n and s[z[i]+i] == s[z[i]])
			z[i]++;
		if(r < i+z[i]-1)
			l = i, r = i + z[i] - 1;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t >> s >> k;

	string revs = s, revt = t;
	reverse(revs.begin(), revs.end());
	reverse(revt.begin(), revt.end());

	cat = s + '#' + t;
	catr = revs + '#' + revt;

	Z(cat, z);
	Z(catr, zr);

	reverse(zr.begin() + s.size() + 1, zr.begin() + catr.size());

	/*For(i,0,cat.size())
		cout << z[i] << " ";
	cout << endl;

	For(i,0,cat.size())
		cout << zr[i] << " ";
	cout << endl;
	

	cout << s << " " << t << endl;
	*/

	vi ans;
	int l = s.size(), r = cat.size();
	for(int i = l+1; i <= r - l; i++){
		//cout << "i = " << i << " / z = " << z[i] << " + " << z[i+s.size()-1] << " -> " << s.size()-z[i]-z[i+s.size()-1] << endl;
		//cout << "s.size() = " << s.size() << " / k = " << k << endl;
		if(z[i] + zr[i+l-1] >= l - k){
			ans.pb(i - s.size());
		}
	}

	cout << ans.size() << endl;
	For(i,0,ans.size()){
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}

