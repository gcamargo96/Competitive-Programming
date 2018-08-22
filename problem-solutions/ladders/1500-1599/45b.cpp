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

string num;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> num;

	for(int i = 0; i < num.size(); i++){
		int x = num[i]-'0';
		if(x%8 == 0){
			cout << "YES" << endl;
			cout << x << endl;
			return 0;
		}
		for(int j = i+1; j < num.size(); j++){
			int x = 10*(num[i]-'0') + num[j]-'0';
			if(x%8 == 0){
				cout << "YES" << endl;
				cout << x << endl;
				return 0;
			}
			for(int k = j+1; k < num.size(); k++){
				int x = 100*(num[i]-'0') + 10*(num[j]-'0') + num[k]-'0';
				if(x%8 == 0){
					cout << "YES" << endl;
					cout << x << endl;
					return 0;
				}
			}
		}
	}

	printf("NO\n");

	return 0;
}

