#include <stdio.h>
int a[100], n;

void show() {
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int ch, v, p, t;
    printf("Size: "); scanf("%d", &n);
    printf("Elements: ");
    for(int i=0; i<n; i++) scanf("%d", &a[i]);

    while(1) {
        printf("\n1.Show 2.Insert 3.Delete 4.Search 5.Sort 0.Exit\nChoice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: show(); break;
            case 2:
                printf("Pos & Val: "); scanf("%d %d", &p, &v);
                for(int i=n; i>p; i--) a[i]=a[i-1];
                a[p]=v; n++; break;
            case 3:
                printf("Pos: "); scanf("%d", &p);
                for(int i=p; i<n-1; i++) a[i]=a[i+1];
                n--; break;
            case 4:
                printf("Val: "); scanf("%d", &v);
                for(int i=0; i<n; i++)
                    if(a[i]==v) printf("Found at %d\n", i);
                break;
            case 5:
                for(int i=0; i<n-1; i++)
                    for(int j=0; j<n-i-1; j++)
                        if(a[j]>a[j+1]) { t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
                printf("Sorted!\n"); break;
            case 0: return 0;
        }
    }
}