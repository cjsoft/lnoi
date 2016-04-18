#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

/*
argv[1]: ��׼�����ļ�
argv[2]: ѡ������ļ�
argv[3]: ��׼����ļ�
argv[4]: �����Ե�����
argv[5]: ��������ļ������봴��������һ�У�����һ���Ǹ���������ʾ�÷֡�
argv[6]: ������Ϣ�ļ������Բ�������
*/

const int maxn=1010;

int n,m,col[maxn][maxn],tag[maxn][maxn],axis[maxn][4];

int main(int argc,char* argv[])
{
	freopen(argv[1],"r",stdin);
	scanf("%d%d",&n,&m);
	for (int a=1;a<=m;a++)
	{
		for (int b=0;b<4;b++)
			scanf("%d",&axis[a][b]);
		tag[axis[a][0]][axis[a][1]]=1;
		tag[axis[a][2]][axis[a][3]]=1;
	}
	freopen(argv[6],"w",stderr);

	freopen(argv[2],"r",stdin);
	bool able=true;
	int tot=0;
	for (int a=1;a<=m && able;a++)
	{
		int l;
		scanf("%d",&l);
		tot+=l;
		int lx=0,ly=0;
		for (;l-- && able;)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			col[x][y]=a;
			if ((lx==0 && ly==0) || (abs(x-lx)+abs(y-ly)==1))
			{
				if (!lx && !ly)
				{
					if (!tag[x][y]) 
					{
						able=false;
						fprintf(stderr,"1");
					}
				}
				lx=x;
				ly=y;
			}
			else 
			{
				able=false;
				fprintf(stderr,"2");
			}
		}
		if (!tag[lx][ly])
		{
			able=false;
			fprintf(stderr,"3");
		}
	}
	if (tot!=n*n) able=false;
	for (int a=1;a<=n;a++)
		for (int b=1;b<=n;b++)
			if (!col[a][b]) 
			{
				able=false;
				fprintf(stderr,"4");
			}
	for (int a=1;a<=m;a++)
		if (col[axis[a][0]][axis[a][1]]!=col[axis[a][2]][axis[a][3]])
		{
			able=false;
			fprintf(stderr,"5");
		}

	freopen(argv[5],"w",stdout);
	if (able) printf("%s\n",argv[4]);
	else printf("0\n");

	return 0;
}
