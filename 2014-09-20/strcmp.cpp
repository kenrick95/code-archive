#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <ctime>

using namespace std;

struct Point {
    int32_t len;
    char str[64];
} points[65536];

bool cmpPoints(const Point &a,const Point &b)
{
    return strcmp(a.str,b.str)<0;
}

static int32_t upbound(int32_t pos, int32_t left, int32_t right)
{
    int32_t mid,ans=0;
    while(left <= right)
    {
        // mid=(left+right)>>1;
        mid=(left+right)/2;
        if(points[pos].len > points[mid].len)
        {
            right=mid-1;
            continue;
        }
        if(strncmp(points[pos].str,points[mid].str,points[pos].len) == 0)
        {
            left=mid+1;
            ans=max(mid,ans);
        }
        else right=mid-1;
    }
    return ans;
}
int main()
{
    // clock_t begin = clock();

    int32_t tests, n, now;
    scanf("%d",&tests);
    while(tests--)
    {
        scanf("%d",&n);
        int64_t ans=0;
        for(int32_t i=0; i<n; i++)
        {
            scanf("%s",points[i].str);
            points[i].len=strlen(points[i].str);
        }
        sort(points,points+n,cmpPoints);

        for(int32_t i=0;i<n;i++)
        {
            now=upbound(i,i,n-1);
            ans+=(now-i);
        }
        if(ans > 11519)
            ans%=11519;

        printf("%I64d\n",ans);
    }
     
    // fprintf(stderr, "Time elapsed: %.4f ms\n", double(clock() - begin)/CLOCKS_PER_SEC);
    return 0;
}
