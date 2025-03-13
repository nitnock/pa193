#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<climits>
void bO(){char b[10];strcpy(b,"Too long!");}
void fS(char* u){printf(u);}
void sC(){int a[5];a[10]=42;}
void hC(){int* p=new int[5];p[10]=42;delete[] p;}
void hO(){char* h=(char*)malloc(10);strcpy(h,"HeapFlow!");free(h);}
void uA(){int* d=new int[5];delete[] d;d[0]=42;}
void dF(){int* d=new int[5];delete[] d;delete[] d;}
void nP(){int* p=nullptr;*p=42;}
void iO(){int s=INT_MAX;s+=10;}
void uV(){int v;std::cout<<v;}
void oR(){int a[5]={1,2,3,4,5};std::cout<<a[10];}
void uM(){int* d=(int*)malloc(5*sizeof(int));d[10]=42;free(d);}
void sCnv(){int i=-1,a[5]={1,2,3,4,5};std::cout<<a[(unsigned)i];}
void cI(){char c[256];std::cin>>c;system(c);}
int main(){
    FILE* f=fopen("msg.txt","r");
    char in[256]={};
    if(f){fread(in,1,255,f);fclose(f);}
    if(in[0]){
        bO();fS(in);sC();hC();hO();uA();dF();nP();
        iO();uV();oR();uM();sCnv();cI();
    }
    return 0;
}
