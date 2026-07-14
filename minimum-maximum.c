#include <stdio.h>

int main() {
    int a, b, c, d, e;
    int* p;
    
    printf("Input 5 Values: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int min = a;
    int max = a;
    
    p = &a;
    for (int i = 0; i < 5; i++) {
        if (*p > max) {
            max = *p;
        }
        if (*p < min) {
            min = *p;
        }
        p++;
    }
    
    printf("minimum: %d \nmaximum: %d", min, max);
    
    return 0;
}
