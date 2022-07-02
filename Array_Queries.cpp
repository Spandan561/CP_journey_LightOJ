/**THE FUTURE IS UNPREDICTABLE. SO, BE REMEMBERED THROUGH THE LOVE YOU GIVE & GET. NOT FORGOTTEN FOR HATE OR JUDGEMENT**/
/**Man can do everything,if he is determined. Cause man is not made for defeat, man can be destroyed but not defeated**/

/****************************************
**     Solution by Baspannissu         **
****************************************/

#include<bits/stdc++.h>
#include<stdio.h>
#include <algorithm>
#include <string.h>

#define  ll         long long
#define  llu        unsigned long long

#define  pi         ((2.0)*acos(0.0))
#define  pb         push_back
#define  pf         push_front
#define  eb         emplace_back
#define  mp         make_pair
#define  all(x)     (x).begin(),(x).end()
#define  X          first
#define  Y          second

/*loop*/
#define  spa(i,p,n,m)   for(ll i=n;i<m;i+=p)
#define  den(i,n,m)     for(int i=n;i>=m;i--)
#define  bas(i,p,n,m)   for(ll i=n;i<=m;i+=p)

/*output shortcuts*/
#define  nl         "\n"
#define  Yes        cout<<"Yes\n"
#define  yes        cout<<"yes\n"
#define  YES        cout<<"YES\n"
#define  No         cout<<"No\n"
#define  no         cout<<"no\n"
#define  NO         cout<<"NO\n"
#define take(n)     scanf("%d",&n)
#define give(n)     printf("%d\n",n)
#define mx 10001

#define  fastio     ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


using namespace std;



ll fib[50];
void fibo_make()
{

    ll x=0;ll y=1;
    fib[0]=x;fib[1]=y;
    for(ll i=2;i<50;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
}

ll mod(ll b,ll p, ll m)
{
    if(p==0)
    {
        return 1;
    }
    else if(p%2==0)
    {
        ll x = (mod(b,p/2,m)%m);
        return (x*x)%m;
    }
    else if(p%2==1)
    {
        ll x = b;
        ll y = (mod(b,p-1,m)%m);
        return (x*y)%m;
    }
}



void body()
{

}
int tree[400005];
int ar[100005];
int seg_tree(int l, int u, int node)
{
    if(l==u)
    {
        tree[node] = ar[l];
        return tree[node];
    }
    int left = 2*node;
    int right = left+1;
    int mid = (l+u)/2;
    int x = seg_tree(l,mid,left);
    int y = seg_tree(mid+1,u,right);

    tree[node] = min(x,y);
    return tree[node];
}

int query(int l, int u, int b, int e, int node)
{
    if(b>u || e<l)
    {
        return INT_MAX;
    }
    if(l>=b && e>=u)
    {
        return tree[node];
    }
    int left = 2*node;
    int right = left+1;
    int mid = (l+u)/2;
    int x = query(l,mid,b,e,left);
    int y = query(mid+1,u,b,e,right);

    return min(x,y);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;scanf("%d",&t);
    //printf("\n");




    for(int i=0;i<t;i++)
    {
        int n,q; scanf("%d%d",&n,&q);


        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ar[i]);
        }
        //body();
        seg_tree(1,n,1);
        //body(a,q,n);
        printf("Case %d:\n",i+1);



        while(q--)
        {
            int i,j;
            scanf("%d%d",&i,&j);

             int d = query(1,n,i,j,1);
             printf("%d\n",d);

             //update()




        }
        //update()
    }

    return 0;



}


