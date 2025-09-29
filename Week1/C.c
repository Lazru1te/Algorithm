#include <stdio.h>
#include <string.h>     

int main() {
    int n;
    scanf("%d", &n);
    char words[101][21];
    int fre[101] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((strcmp(words[i], words[j]) == 0)) {
                fre[j]++;
                break;
            }
        }
        if (fre[i] == 0) {
            fre[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (fre[i] == 5) {
            printf("%s\n", words[i]);
        }
    }
    return 0;
}


