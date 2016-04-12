#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n,m,ans,p[40];

void dfs(int nowp,int nown,int nowv)
{
	if (nown&1) ans-=n/nowv;
	else ans+=n/nowv;
	for (int a=nowp;a<=m;a++)
		if (n/p[a]>=nowv) dfs(a+1,nown+1,nowv*p[a]);
		else break;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int a=1;a<=m;a++)
		scanf("%d",&p[a]);
	sort(p+1,p+m+1);
	m=unique(p+1,p+m+1)-p-1;
	dfs(1,0,1);
	printf("%d\n",n-ans);

	return 0;
}
