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

int main(void){
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);

	fastcin;
	cin >> s;

	for(int i = 0; i < s.size(); ){
		if(s[i] >= '0' and s[i] <= '9'){
			string num;
			int j = i;
			for(j = i; j < s.size() and s[j] >= '0' and s[j] <= '9'; j++){
				num += s[j];
			}

			cout << num;
			i = j;
		}
		else{
			char op = s[i];
			cout << op;
			i++;

			if(op == '-'){
				string num;
				num += s[i]; // primeiro digito positivo
				i++;

				for(; i < s.size() and s[i] == '0'; i++){ // enquanto tiverem zeros
					num += s[i];
				}

				if(num.size() > 1){
					cout << num[0];
					for(int i = 1; i < num.size(); i++){
						cout << "+0";
					}
				}
				else{
					cout << num;
				}

				if(i < s.size() and s[i] >= '1' and s[i] <= '9'){
					cout << "+";
				}
			}
		}
	}
	cout << endl;

	return 0;
}