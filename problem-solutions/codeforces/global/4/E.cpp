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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;
int n;
string a, b;

int main(void){
	fastcin;
	cin >> s;
	n = s.size();

	int i = 0, j = n-1;
	while(i <= j){
		if(i == j){
			a += s[i];
			break;
		}

		if(s[i] == s[j]){
			a += s[i];
			b += s[j];
			i++;
			j--;
		}
		// nao deu match
		else if(j-1 > i and s[i] == s[j-1]){
			a += s[i];
			b += s[j-1];
			i++;
			j -= 2;
		}
		else{
			i++;
		}
	}

	reverse(b.begin(), b.end());
	for(int i = 0; i < b.size(); i++){
		a += b[i];
	}

	if(a.size() >= n/2){
		cout << a << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}