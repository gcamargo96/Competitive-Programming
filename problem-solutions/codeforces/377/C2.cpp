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

ll a,b,c;
ll ans;
void A(){
	long long temp=0;
	if(a>b)temp+=a-1-b;
	if(a>c)temp+=a-1-c;
	ans=min(ans,temp);
}
void B(){
	long long temp=0;
	if(b>a)temp+=b-1-a;
	if(b>c)temp+=b-1-c;
	ans=min(ans,temp);
}
void C(){
	long long temp=0;
	if(c>a)temp+=c-1-a;
	if(c>b)temp+=c-1-b;
	ans=min(ans,temp);
}
int main(){
	cin>>a>>b>>c;
	long long maxx=max(a,b);
	maxx=max(maxx,c);
	ans=2*maxx;
	if(a==maxx)A();
	if(b==maxx)B();
	if(c==maxx)C();
	cout<<ans<<endl;
	return 0;
}
