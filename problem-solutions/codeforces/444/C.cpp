#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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
#define fastcin ios_base::sync_with_stdio(false)

int v[27];

bool test1(){
	if(!(v[1] == v[2] and v[1] == v[3] and v[1] == v[4])) return 0;
	if(!(v[9] == v[10] and v[9] == v[11] and v[9] == v[12])) return 0;

	bool ok = 0;
	if(v[13] == v[14] and v[13] == v[7] and v[13] == v[8]
		and v[5] == v[6] and v[5] == v[19] and v[5] == v[20]
		and v[17] == v[18] and v[17] == v[23] and v[17] == v[24]
		and v[21] == v[22] and v[21] == v[15] and v[21] == v[16])
		ok = 1;

	if(v[5] == v[6] and v[5] == v[15] and v[5] == v[16]
		and v[17] == v[18] and v[17] == v[7] and v[17] == v[8]
		and v[21] == v[22] and v[21] == v[19] and v[21] == v[20])
		ok = 1;

	return ok;
}

bool test2(){
	if(!(v[13] == v[14] and v[13] == v[15] and v[13] == v[16])) return 0;
	if(!(v[17] == v[18] and v[17] == v[19] and v[17] == v[20])) return 0;

	bool ok = 0;
	if(v[1] == v[3] and v[1] == v[6] and v[1] == v[8]
		and v[5] == v[7] and v[5] == v[10] and v[5] == v[12]
		and v[9] == v[11] and v[9] == v[21] and v[9] == v[23]
		and v[22] == v[24] and v[22] == v[2] and v[22] == v[4])
		ok = 1;

	if(v[2] == v[4] and v[2] == v[5] and v[2] == v[7]
		and v[6] == v[8] and v[6] == v[9] and v[6] == v[11]
		and v[10] == v[12] and v[10] == v[22] and v[10] == v[24]
		and v[21] == v[23] and v[21] == v[1] and v[21] == v[3])
		ok = 1;

	return ok;
}

bool test3(){
	if(!(v[5] == v[6] and v[5] == v[7] and v[5] == v[8])) return 0;
	if(!(v[21] == v[22] and v[21] == v[23] and v[21] == v[24])) return 0;

	bool ok = 0;
	if(v[1] == v[2] and v[1] == v[17] and v[1] == v[19]
		and v[18] == v[20] and v[18] == v[10] and v[18] == v[9]
		and v[12] == v[11] and v[12] == v[16] and v[12] == v[14]
		and v[15] == v[13] and v[15] == v[3] and v[15] == v[4])
		ok = 1;

	if(v[18] == v[20] and v[18] == v[3] and v[18] == v[4]
		and v[11] == v[12] and v[11] == v[17] and v[11] == v[19]
		and v[13] == v[15] and v[13] == v[9] and v[13] == v[10]
		and v[1] == v[2] and v[1] == v[14] and v[1] == v[16])
		ok = 1;

	return ok;
}

int main(void){
	// fastcin;
	for(int i = 1; i <= 24; i++){
		scanf("%d", &v[i]);
	}

	bool ok = test1();
	ok |= test2();
	ok |= test3();

	if(ok) printf("YES\n");
	else printf("NO\n");

	return 0;
}