#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<algorithm>

using namespace std;

const int BUF_SIZE = 30;
char buf[BUF_SIZE], *buf_s = buf, *buf_t = buf + 1;
  
#define PTR_NEXT() \
    { \
        buf_s ++; \
        if (buf_s == buf_t) \
        { \
            buf_s = buf; \
            buf_t = buf + fread(buf, 1, BUF_SIZE, stdin); \
        } \
    }
   
#define readint(_n_) \
    { \
        while (*buf_s != '-' && !isdigit(*buf_s)) \
            PTR_NEXT(); \
        bool register _nega_ = false; \
        if (*buf_s == '-') \
        { \
            _nega_ = true; \
            PTR_NEXT(); \
        } \
        int register _x_ = 0; \
        while (isdigit(*buf_s)) \
        { \
            _x_ = _x_ * 10 + *buf_s - '0'; \
            PTR_NEXT(); \
        } \
        if (_nega_) \
            _x_ = -_x_; \
        (_n_) = (_x_); \
    }

const int maxn=1000010;

int n,m,t,cnt,en,dfn[maxn],low[maxn],sta1[maxn],sta2[maxn],belong[maxn],res[maxn];

bool instack[maxn];

char s[maxn*7];

int l;

void print(int x)
{
	int c=0,v=0;
	for (;x;)
	{
		v=v*10+x%10;
		c++;
		x/=10;
	}
	for (;c--;)
	{
		s[l++]=v%10+'0';
		v/=10;
	}
	s[l++]='\n';
}

struct edge
{
	int e;
	edge *next;
}*v[maxn],ed[maxn<<1],*fe[maxn];

void add_edge(int s,int e)
{
	en++;
	ed[en].next=v[s];v[s]=ed+en;v[s]->e=e;
}

void dfs(int now)
{
	int size1=0,size2=0;
	sta1[++size1]=now;
	while (size1)
	{
		int now=sta1[size1];
		if (fe[now])
		{
			if (!dfn[now])
			{
				t++;
				dfn[now]=low[now]=t;
				instack[now]=true;
				sta2[++size2]=now;
			}
			else low[now]=min(low[now],low[fe[now]->e]);
			for (;fe[now];fe[now]=fe[now]->next)
				if (!dfn[fe[now]->e])
				{
					sta1[++size1]=fe[now]->e;
					break;
				}
				else
				{
					if (instack[fe[now]->e]) low[now]=min(low[now],dfn[fe[now]->e]);
				}
		}
		else
		{
			if (!dfn[now])
			{
				t++;
				dfn[now]=low[now]=t;
				instack[now]=true;
				sta2[++size2]=now;
			}
			size1--;
			if (low[now]==dfn[now])
			{
				cnt++;
				while (sta2[size2]!=now)
				{
					res[cnt]++;
					instack[sta2[size2]]=false;
					belong[sta2[size2]]=cnt;
					size2--;
				}
				size2--;
				res[cnt]++;
				instack[now]=false;
				belong[now]=cnt;
			}
		}
	}
}

int main()
{
	readint(n);
	readint(m);
	for (int a=1;a<=m;a++)
	{
		int s,e;
		readint(s);
		readint(e);
		add_edge(s,e);
	}
	for (int a=1;a<=n;a++)
		fe[a]=v[a];
	for (int a=1;a<=n;a++)
		if (!dfn[a]) dfs(a);
	for (int a=1;a<=n;a++)
		print(res[belong[a]]);
	printf("%s",s);

	return 0;
}
