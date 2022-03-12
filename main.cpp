#include <iostream>
#include<sys/time.h>
#include<unistd.h>
#include <cstdlib>
using namespace std;
const int N=10000;
int b[N][N];
int a[N];
int sum[N];
void rand_init(int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100+1;
        for(int j=0;j<n;j++)
        {
            b[i][j]=rand()%100+1;
        }
    }

}
void col_major(int n,int sum[N],int b[N][N],int a[N])
{
    struct  timeval   tv_begin,tv_end;
    unsigned  long col_time;
    gettimeofday(&tv_begin,NULL);
    for(int i = 0; i < n; i++)
    {
        sum[i] = 0;
        for(int j = 0; j < n; j++)
        {
            sum[i]+=b[j][i]*a[j];
        }
   }
   gettimeofday(&tv_end,NULL);
   col_time=1000000 * (tv_end.tv_sec-tv_begin.tv_sec)+ tv_end.tv_usec-tv_begin.tv_usec;
   cout<<"col_time:"<<col_time<<endl;
}
void row_major(int n,int sum[N],int b[N][N],int a[N])
{
    struct  timeval   tv_begin,tv_end;
    unsigned  long row_time;
    gettimeofday(&tv_begin,NULL);
    for(int i = 0; i < n; i++)
    {
        sum[i] = 0;
    }
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            sum[i] += b[j][i] * a[j ];
        }
    }
    gettimeofday(&tv_end,NULL);
    row_time=1000000 * (tv_end.tv_sec-tv_begin.tv_sec)+ tv_end.tv_usec-tv_begin.tv_usec;
    cout<<"row_time:"<<row_time<<endl;
}

int main()
{
    rand_init(N);
    col_major(N,sum,b,a);
    row_major(N,sum,b,a);
}
