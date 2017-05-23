#include <stdio.h>
#include <stdlib.h>
#define MAXN 2000
typedef struct{
    int id;
    int c;
    int m;
    int e;
    int a;
}STU;
STU sc[MAXN];
STU sm[MAXN];
STU se[MAXN];
STU sa[MAXN];
int id[MAXN];
int cmpc(const STU* a,const STU* b){
    return (b->c - a->c);
}
int cmpm(const STU* a,const STU* b){
    return (b->m - a->m);
}
int cmpe(const STU* a,const STU* b){
    return (b->e - a->e);
}
int cmpa(const STU* _a,const STU* b){
    return (b->a - _a->a);
}
int find(STU* p,int n,int id,int c){
    int i;
    switch(c){
        case 0:
        for(i = 0;i < n;i++){
            if(p[i].id == id)
            break;
        }
        if(i != n){
            while(i>=1 && p[i].a == p[i-1].a) i--;
        } 
        return i+1;
        case 1:
        for(i = 0;i < n;i++){
            if(p[i].id == id)
            break;
        }
        if(i != n){
            while(i>=1 && p[i].c == p[i-1].c) i--;
        }
        return i+1;
        case 2:
        for(i = 0;i < n;i++){
            if(p[i].id == id)
            break;
        }
        if(i != n){
            while(i>=1 && p[i].m == p[i-1].m) i--;
        }
        return i+1;
        case 3:
        for(i = 0;i < n;i++){
            if(p[i].id == id)
            break;
        }
        if(i != n){
            while(i>=1 && p[i].e == p[i-1].e) i--;
        }
        return i+1;
    }
}
int m_min(int c,int m,int e,int a,char *fg){
    int min = a;
    *fg = 'A';
    if(min > c) {min = c;*fg = 'C';}
    if(min > m) {min = m;*fg = 'M';}
    if(min > e) {min = e;*fg = 'E';}
    return min;
}
int main(){
    int N,M,i;
    int rc,rm,re,ra,r;
    char c[] = {'A','C','M','E'};
    char flag;
    scanf("%d%d",&N,&M);
    for(i = 0;i < N;i++){
        scanf("%d%d%d%d",&sc[i].id,&sc[i].c,&sc[i].m,&sc[i].e);
        sc[i].a = ((float)(sc[i].c + sc[i].m + sc[i].e) / 3) * 1000;
        sm[i] = se[i] = sa[i] = sc[i];
    }
    qsort(sc,N,sizeof(STU),cmpc);
    qsort(sm,N,sizeof(STU),cmpm);
    qsort(se,N,sizeof(STU),cmpe);
    qsort(sa,N,sizeof(STU),cmpa);
    for(i = 0;i < M;i++){
        scanf("%d",&id[i]);
    }
    for(i = 0;i < M;i++){
        rc = find(sc,N,id[i],1);
        rm = find(sm,N,id[i],2);
        re = find(se,N,id[i],3);
        ra = find(sa,N,id[i],0);
        r = m_min(rc,rm,re,ra,&flag);
        if(r > N)
        printf("N/A\n");
        else
        printf("%d %c\n",r,flag);
    }
    return 0;
}
