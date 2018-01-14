#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

string num;
int n, t;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> t;
	
	cin >> num;

	int pos = -1;
	For(i,1,n){
		if(num[i]-'0' >= 5){
			pos = i;
			break;
		}
	}

	pos--;
	t--;
	int carry = 0;

	while(pos > 0 and t > 0){
		if(num[pos] == '.'){
			pos--;
			continue;
		}

		int x = num[pos]-'0';
		
		if(carry) x++;
		if(x == 10){
			pos--;
			carry = 1;
			continue;
		}

		x++;	
		if(x == 10){
			pos--;
			carry = 1;
			t--;
			continue;
		}
	
		if(x >= 5){
			pos--;
			t--;
			carry = 0;
			continue;
		}
		else{
			break;
		}
	}

	if(num[pos] == '.') pos--;

	if(pos < 0){
		cout << num << endl;
		return 0;
	}

	int x = num[pos]-'0';
	if(pos == 0){
		if(carry) x++;
		cout << x+1 << endl;
		return 0;
	}

	For(i,0,pos){
		cout << num[i];
	}
	if(carry) x++;
	cout << x+1 << endl;

	return 0;
}

