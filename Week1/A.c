#include <stdio.h>
#include <stdlib.h>
int a[10000000];
int main(){
    int n,x,m,temp;

    int sum = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        sum = 0;
        scanf("%d%d",&x,&m);
        for(int j=0;j<m;j++){
            scanf("%d",&a[j]);
            int temp = a[j];
            for(int k=0;k<j;k++){
                temp = ((temp%10007)*(x%10007))%10007;
            }
            sum = (sum%10007 + temp%10007)%10007;
        }
        printf("%d\n",sum);
    }
}