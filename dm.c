#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*question 2*/
int w(int *G, int n, int s, int t) {
    return G[n*s+t];
}
/*question 3*/
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
/*question 4*/

/*
bool permut_suivante(int *p,int n)
    j=-1;
    pour tout i qui appartient à [|0,n-2|]
        si p[i]<p[i+1]:
            j=i
    si j=-1 : (p est un cycle parcourue par tout les sommets dans l'ordre décroissant donc dernière permutation)
        return false
    k=-1
    pour tout i qui appartient à [|j+1,n-1|]
        si p[j]<p[i]:
            k=i
    swap p[j] et p[k]
    b= n-1
    tant que que j<b:
        echanger p[j] et p[b]
        j=j+1
        b=b-1
    return true

*/
#include <stdbool.h>

bool permut_suivante(int *p, int n) {
    int j = -1;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] < p[i + 1]) {
            j = i;
        }
    }
    if (j == -1) return false;
    int k = -1;
    for (int i = j + 1; i < n; i++) {
        if (p[j] < p[i]) {
            k = i;
        }
    }
    int tmp = p[j];
    p[j] = p[k];
    p[k] = tmp;
    for (int a = j + 1, b = n - 1; a < b; a++, b--) {
        tmp = p[a];
        p[a] = p[b];
        p[b] = tmp;
    }

    return true;
}
/*question 5*/
int *PVC_naif(int *G, int n) {
    int *p=malloc(n*sizeof(int));
    int *res = malloc(n * sizeof(int));
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    for (int i = 0; i < n; i++) {
        res[i] = p[i];
    }
    int pres=poids_cycle(G,p,n);
    int a;
    while(permut_suivante(p,n)){
        a=poids_cycle(G,p,n);
        if(a<pres){
            for (int i = 0; i < n; i++) {
                res[i] = p[i];
            }   
        }
    }
    free(p);
    return res;
}

/*question 6*/
/*
On réalise l'ensemble des permutations des sommets donc n! passage dans la boucle auxquelles on ajoute l'étude du cycle que l'on étudie donc n et on rechange dans 
le pire des cas à chaque fois res donc en O(n) le changement
ainsi on est en O(n* (n!))


*/

/*question 11*/
int plus_proche(int *G, bool *vus, int n, int s){
    int pmin=1000000;
    int min=-1;
    for(int i=0;i<n;i++){
        if(!vus[i] && G[n*s+i]<pmin) {
            pmin=G[n*s+i];
            min=i;
        }   
    }
    return min;
}

/*question 12 */

int *PVC_glouton(int *G,int n){
    bool *vus=malloc(n*sizeof(bool));
    int *p=malloc(n*sizeof(int));
    for(int i=1;i<n;i++){
        vus[i]=false;
    }
    vus[0]=true;
    p[0]=0;
    int i,j;
    i=1;
    while(i<n){
        j=plus_proche(G,vus,n,p[i-1]);
        vus[j]=true;
        p[i]=j;
        i++;
    }
    free(vus);
    return p;
}
/*question 13*/
/*On a plus_proche qui est en O(|S|) soit O(n)
l'initialisation des tableaux et en O(n)
et dans la boucle while on réalise n fois l'opération plus_proche et de mettre a jour 3 informations O(n²)
ainsi on O(5n+n²)=O(n²)
*/

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
    int res=poids_cycle(G0,c,5);
    printf("%d\n",res);
    int *p=PVC_naif(G0,5);
    res=poids_cycle(G0,p,5);
    printf("%d\n",res);
    bool vus[5] = {true, false, true, true, false};
    int pu= plus_proche(G0, vus, 5, 2);
    printf("%d\n",pu);
    int *pg=PVC_glouton(G0,5);
    for(int i=0;i<5;i++){
        printf("%d ->",pg[i]);
    }   
    printf("\n");
    return 0;
}