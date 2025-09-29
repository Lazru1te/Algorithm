#include <stdio.h>
#include <stdlib.h>
long long a[10000000];
int main(){
    long long n,x,m;

    long long sum = 0;
    long long temp;
    int xm=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        sum = 0;
        scanf("%lld%lld",&x,&m);
        xm = 1;
        for(int j=0;j<m;j++){
            scanf("%lld",&a[j]);
            temp = a[j];
            if(j != 0){
                xm = xm*x%10007;
            }
            sum = (sum + (temp%10007)*(xm%10007))%10007;
        }
        printf("%lld\n",sum);
    }
}

