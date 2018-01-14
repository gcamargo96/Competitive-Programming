#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

int a1, a2, a3, b1, b2, b3, n;

int main(void){
	scanf("%d%d%d", &a1, &a2, &a3);
	scanf("%d%d%d", &b1, &b2, &b3);
	scanf("%d", &n);

	int usado = 0;
	usado += (a1+a2+a3)/5;
	if((a1+a2+a3)%5) usado++;

	//cout << usado << endl;

	usado += (b1+b2+b3)/10;
	if((b1+b2+b3)%10) usado++;;

	//cout << usado << endl;

	if(usado <= n) printf("YES\n");
	else printf("NO\n");

	return 0;
}
