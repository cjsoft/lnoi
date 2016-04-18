#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>

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

const int maxn=100010;
const int maxp=maxn*40;

int n,m,num,depth[2][maxn],f[2][maxn],l[maxn],r[maxn],en,wmt,root[maxn];

struct edge
{
	int e;
	edge *nextnext;
}*v[maxn],ed[maxn];

void add_edge(int s,int e)
{
	en++;
	ed[en].nextnext=v[s];v[s]=ed+en;v[s]->e=e;
}

void dfs(int o,int p)
{
	num++;
	if (o) l[p]=num;
	for (edge *e=v[p];e;e=e->nextnext)
	{
		depth[o][e->e]=depth[o][p]+1;
		dfs(o,e->e);
	}
	if (o) r[p]=num;
}

struct node
{
	int l,r,col;
	node()
	{
		l=r=col=0;
	}
}z[maxp];

int newnode(int p)
{
	wmt++;
	z[wmt].l=z[p].l;
	z[wmt].r=z[p].r;
	z[wmt].col=z[p].col;
	return wmt;
}

int modify(int p,int l,int r,int nowl,int nowr,int c)
{
	int pp=newnode(p);
	if (nowl<=l && r<=nowr)
	{
		z[pp].col=c;
		return pp;
	}
	int m=(l+r)>>1;
	if (nowl<=m) z[pp].l=modify(z[p].l,l,m,nowl,nowr,c);
	if (m<nowr) z[pp].r=modify(z[p].r,m+1,r,nowl,nowr,c);
	return pp;
}

int query(int p,int l,int r,int xp)
{
	if (!p) return 0;
	int m=(l+r)>>1;
	int ans=z[p].col;
	int res;
	if (xp<=m) res=query(z[p].l,l,m,xp);
	else res=query(z[p].r,m+1,r,xp);
	if (ans>res) return ans;
	else return res;
}

int main()
{
	readint(n);
	readint(m);
	for (int a=2;a<=n;a++)
	{
		readint(f[0][a]);
	}
	for (int a=2;a<=n;a++)
	{
		readint(f[1][a]);
		add_edge(f[1][a],a);
	}
	depth[1][1]=1;
	num=0;
	dfs(1,1);
	en=0;
	memset(v,0,sizeof(v));
	for (int a=2;a<=n;a++)
		add_edge(f[0][a],a);
	depth[0][1]=1;
	dfs(0,1);
	wmt=0;
	for (int a=1;a<=n;a++)
		root[a]=modify(root[f[0][a]],1,n,l[a],r[a],a);
	for (int a=1,ans=0;a<=m;a++)
	{
		int p1,p2;
		readint(p1);
		readint(p2);
		p1=(p1+ans)%n+1;
		p2=(p2+ans)%n+1;
		ans=query(root[p1],1,n,l[p2]);
		printf("%d %d %d\n",ans,depth[0][p1]-depth[0][ans]+1,depth[1][p2]-depth[1][ans]+1);
	}

	return 0;
}
