#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

char s[1000010];

int main()
{
	scanf("%s",s);
	int l=strlen(s+1),ans=0;
	for (int a=0;a<l;)
	{
		int b=a;
		while (b<l && s[b]==s[a])
			b++;
		if (b-a>ans) ans=b-a;
		a=b;
	}
	printf("%d\n",ans);

	return 0;
}
