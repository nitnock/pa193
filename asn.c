#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void bO(){char a[8];strcpy(a,"ov!");} // Buffer Overflow
void fS(){char i[32];gets(i);printf(i);} // Format String
void hO(){char*p=malloc(4);strcpy(p,"ov!");free(p);} // Heap Overflow
void uA(){int*x=malloc(8);free(x);*x=42;} // Use-After-Free
void oRw(){char b[4]="hi";b[5]='X';} // Out-of-Bounds Write
void iO(){int x=INT_MAX;x+=10;printf("%d",x);} // Integer Overflow
void nP(){int*p=NULL;*p=42;} // Null Pointer Dereference
void uV(){int x;printf("%d",x);} // Uninitialized Variable
void cI(){char b[64];gets(b);system(b);} // Command Injection
void bC(){int a[5],i;for(i=0;i<10;i++)a[i]=i;} // Buffer Corruption
void mL(){while(1)malloc(512);} // Memory Leak
void uS(){char a[5];memset(a,'A',10);printf("%s",a);} // Stack Overflow (Write)

int main(){
    int x;void(*fx[])()={bO,fS,hO,uA,oRw,iO,nP,uV,cI,bC,mL,uS};
    printf("Enter(0-%lu):",sizeof(fx)/sizeof(*fx)-1);
    scanf("%d",&x);if(x>=0&&x<12)fx[x]();
}
