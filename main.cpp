#include <iostream>
#include <cstdlib>
#include<sys/time.h>
#include<unistd.h>
using namespace std;
const int N=4096;
const int count=5000;
int a[N];
int sum1,sum2,sum;
void rand_init(int n)
{
    sum=0;
    sum1=0;sum2=0;
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
}
void sum_n(int n,int sum,int a[N])
{
    struct  timeval   tv_begin,tv_end;
    unsigned  long two_way_time;
    gettimeofday(&tv_begin,NULL);
    for(int k=0;k<count;k++)
    {
        for (int i = 0; i < n; i += 2)
        {
            sum1 += a[i];
            sum2 += a[i+1];
        }
    }
    sum=sum1+sum2;
    gettimeofday(&tv_end,NULL);
    two_way_time=1000000 * (tv_end.tv_sec-tv_begin.tv_sec)+ tv_end.tv_usec-tv_begin.tv_usec;
    cout<<"two_way_time:"<<two_way_time<<endl;
}
int main()
{
    rand_init(N);
    sum_n(N,sum,a);
}

