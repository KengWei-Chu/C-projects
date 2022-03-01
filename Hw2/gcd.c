#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *,int *);
int main(int argc, char *argv[]){
    int a,b,q,r,i,N;//a=bq+r,a>=b
    time_t t;
    unsigned int ans ; 
    N = 100;
    srand( time(NULL) );
    //手動輸入需要做運算的值
    /*
    printf("a: ");  
    scanf("%d",&a);
    printf("b: ");
    scanf("%d",&b); 
    */
    t = clock();
    for (i=0;i<N;i++){
        a = rand();
        b = rand(); 
        // 如果a<b，優先交換後再下去做
        if (a<b)
        {
            swap(&a,&b);
        }
        
        ans = gcd(a,b);
        printf("gcd(%d,%d)=%d\n",a,b,ans);
    }
    t = clock()-t;
    
   
    printf("total use time:%d ms",t);

    return 0;
}

int gcd(int a,int b){
    int r;
    r = a % b; 
    
    if (r==0) // 除到整除就對啦
        return b;
    else      // 沒整除就繼續除 b當新的被除數，r當新除數
        return gcd(b,r);

}
void swap(int *A,int *B){
    int C = *A;
    *A = *B;
    *B = C;
}