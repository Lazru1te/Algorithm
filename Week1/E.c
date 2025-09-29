#include <stdio.h>

typedef struct node {
    int num;  // 系数
    int mi;   // 指数
} node;

node a[100001];
node b[100001];
node c[200001];

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 1; i <= t; i++) {
        int n, m;
        
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j].num);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j].mi);
        }
        a[n].mi = -1;
        
        scanf("%d", &m);
        for (int k = 0; k < m; k++) {
            scanf("%d", &b[k].num);
        }
        for (int k = 0; k < m; k++) {
            scanf("%d", &b[k].mi);
        }
        b[m].mi = -1;
        
        int j = 0, k = 0, cnt = 0;
        while (a[j].mi != -1 && b[k].mi != -1) {
            if (a[j].mi < b[k].mi) {
                c[cnt++] = a[j];
                j++;
            } else if (a[j].mi > b[k].mi) {
                c[cnt++] = b[k];
                k++;
            } else {
                if (a[j].num + b[k].num != 0) {
                    c[cnt].mi = a[j].mi;
                    c[cnt].num = a[j].num + b[k].num;
                    cnt++;
                }
                j++;
                k++;
            }
        }
        
        while (a[j].mi != -1) {
            c[cnt++] = a[j];
            j++;
        }
        while (b[k].mi != -1) {
            c[cnt++] = b[k];
            k++;
        }
        
        printf("%d\n", cnt);
        for (int p = 0; p < cnt; p++) {
            printf("%d ", c[p].num);
        }
        printf("\n");
        for (int p = 0; p < cnt; p++) {
            printf("%d ", c[p].mi);
        }
        printf("\n");
    }
    return 0;
}