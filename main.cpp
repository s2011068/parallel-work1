#include <iostream>
#include <cstdlib>
#include<sys/time.h>
#include<unistd.h>
using namespace std;
const int N=4096;
const int count=5000;
int a[N];
int sum;
void rand_init(int n)
{
    sum=0;
    for(int i=0;i<n;i++)
    {
        a[i]=i;
    }
}
void liner(int n,int sum,int a[N])
{
    struct  timeval   tv_begin,tv_end;
    unsigned  long liner_time;
    gettimeofday(&tv_begin,NULL);
    for(int k=0;k<count;k++)
    {
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }
    }
    gettimeofday(&tv_end,NULL);
   liner_time=1000000 * (tv_end.tv_sec-tv_begin.tv_sec)+ tv_end.tv_usec-tv_begin.tv_usec;
   cout<<"liner_time:"<<liner_time<<endl;
}

int main()
{
    rand_init(N);
    liner(N,sum,a);
}
