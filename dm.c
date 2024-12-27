#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

int w(int *G, int n, int s, int t) {
    return G[n*s+t];
}

int poids_cycle(int *G, int *c ,int n){
    assert(n>1);
    int res = 0;
    int b=c[0];
    int a=c[0];
    for(int i =1; i<n ; i++){
        res=res + w(G,n,a,c[i]);
        a=c[i];
    }
    res=res+w(G,n,a,b);
    return res;
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
    int c[5] = {0, 2, 4, 3, 1};
    int res= poids_cycle(G0,c,5);
    printf("%d\n",res);
    return 0;
}