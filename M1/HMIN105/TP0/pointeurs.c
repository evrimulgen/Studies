#include<stdlib.h>
#include<stdio.h>

void affiche(int*T,int n){
  printf("array display : \t");
  for(int i=0;i<n;i++)
    printf("%d \t",T[i]);

  printf("\n");
}

void extract(int* T,int n,int a,int b){
  int* res=NULL;
  int taille=0;
  for(int i=0;i<n;i++)
    if(T[i]>=a && T[i]<=b)
      taille++;
    
  res=(int*)malloc(taille*sizeof(int));
  int j=0;
  
  for(int i=0;i<n;i++)
    if(T[i]>=a && T[i]<=b){
       res[j]=T[i];
       j++;
    }
  
  
  affiche(res,taille);
    
}

void saisirTableau(int* T,int n){
  
  for(int i=0;i<n;i++){
    printf("T(%d)=",i); 
    scanf("%d",&(T[i]));
  }
}

int somme(int* T,int n){
  if(n==0) return 0;
  return (T[n-1]+somme(T,(n-1)));
}

int main(int agrc,char** argv){
  int a=10;
  int b=25;
  int *p=&b;
  int *pp=&a;
  int T[5]={1,3,5,7,9};

  /* *(&(*(*(&p))))
     *(p-1)
     *(*(&p)-1)
     *(*(&pp)+1)
     *(&(*(*(&p))) - 1)
   */
  printf("\n");

  printf("  *(&(*(*(&p))) - 1)  : %d \n",  *(&(*(*(&p))) - 1) );
  printf("la valeur de a : %d  \n",a);
  printf("la valeur de b : %d  \n",b);
  printf("l adresse de a : %p  \n",&a);
  printf("l adresse de b : %p  \n",&b);
  printf("la valeur de p : %i  \n",*p);
  printf("la valeur de pp :%i  \n",*pp);

  affiche(T,5);
  extract(T,5,2,5);

  int size;
  //int* array;
  printf("saississez la taille du tableau et ses éléments \n");
  printf("taille : ");
  scanf("%d",&size);
  //array =malloc(size*sizeof(int));
  int array[size];
  printf("\n");
  printf("array : ");
  saisirTableau(array,size);
  affiche(array,size);
  printf("somme du tableau %d \n",somme(array,size));
  
  return EXIT_SUCCESS;
}
