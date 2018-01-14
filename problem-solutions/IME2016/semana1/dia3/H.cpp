#include <bits/stdc++.h>
using namespace std;

const int N = 100002;
int n;
string s;
int v[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> s;

	for(int i = 0; i < n; i++){
		if(s[i] == 'H'){
			v[0]++;
			v[n-i-1]--;
		}
		if(s[i] == 'M'){	
			v[0]--;
			v[n-i-1]++;
		}
	}

	for(int i = 1; i < n-1; i++){
		v[i] += v[i-1];
	}

	for(int i = n-2; i > 0; i--){
		int aux = v[i]/2;
		v[i-1] += aux;
		v[i] -= 2*aux;
	}

	/*for(int i = 0; i < n-1; i++){
		cout << v[i] << " ";
	}
	cout << endl;*/

	int res = 0;
	for(int i = 0; i < n-1; i++){
		if(v[i] > 0){
			res = 1;
			break;
		}
		if(v[i] < 0){
			res = -1;
			break;
		}
	}

	if(res == 0) cout << "HM" << endl;
	if(res > 0) cout << "H" << endl;
	if(res < 0) cout << "M" << endl;

	return 0;
}
