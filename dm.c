#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

int w(int *G, int n, int s, int t) {
    return G[n*s+t];
}

int main(){
    int G0[25] =
    {0, 1, 3, 5, 4,
    1, 0, 6, 12, 7,
    3, 6, 0, 2, 10,
    5, 12, 2, 0, 9,
    4, 7, 10, 9, 0};
    int w51 = w(G0,5,3,4);
    printf("%d\n",w51);
    return 0;
}