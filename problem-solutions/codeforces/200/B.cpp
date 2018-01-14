#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int a, b, c;
int x, y, z;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> a >> b >> c;

	int res = 0;
	for(x = 0; x < N; x++){
		y = b-x;
		z = a-x;
		if(y >= 0 and z >= 0 and a == x+z and b == x+y and c == y+z){
			cout << x << " " << y << " " << z << endl;
			return 0;
		}
	}

	cout << "Impossible" << endl;

	return 0;
}
