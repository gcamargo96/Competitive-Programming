#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string num;
int cnt = 0;

int main(void){
	cin >> num;

	For(i,0,num.size()){
		if(num[i] != '0') cnt++;
	}

	if(num[0] == '9'){
		string novo;
		novo += '1';
		For(i,0,num.size()){
			novo += '0';
		}

		int maior = stoi(novo);
		int cur = stoi(num);
		cout << (maior-cur) << endl;
	}
	else{
		string novo = num;
		novo[0]++;
		For(i,1,num.size()){
			novo[i] = '0';
		}
		int maior = stoi(novo);
		int cur = stoi(num);
		cout << (maior-cur) << endl;
	}

	return 0;
}

