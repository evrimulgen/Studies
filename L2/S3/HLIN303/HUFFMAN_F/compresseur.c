#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------Global-Variables-------------------------*/

int * parent, *fg,*fd;
char** code;
char* Arbre;
char buffer[9];
int n=0;
int poschaine=0;
int Occ[256]={0};
char* Table;
int huffsize=0;

int ProbaCar(char* chemin,float* Proba) {

  FILE* fic=fopen(chemin,"r");
  if (fic==NULL) {
    fprintf(stderr,"impossible d'ouvrir le fichier \n");
    return -1;
  }

 
  
  int taille=0,c;
  
  while (EOF!=(c=fgetc(fic))) {
    Occ[c]++;
    taille++;
  }

  fclose(fic);

  if (taille!=0) {
  for (int i=0;i<256;i++)
    Proba[i]=(float) Occ[i]/taille;
  }

  return taille;
}


char* ctob(int k) {
  char* bin=(char*) malloc(9);
  for (int i=0; i<8 ;i++)
    bin[i]='0';
  bin[8]='\0';

  for (int i=7; i>=0;i--) {
    if(k%2==0)
      bin[i]='0';
    else
      bin[i]='1';
    k/=2;
  }
  return bin;
}


char* itob(int i) {
  int j=i;
  char* binaire=(char*)malloc(33);
  for (int k=31; k>=0; k--) {
    if(j%2==0)
      binaire[k]='0';
    else
      binaire[k]='1';
    j/=2;
  }
  binaire[32]='\0';
  return binaire; 
}

int btoc(char * bin) {
  int sumpow2=0,pow=1;
  if (bin[7]!='0')
    sumpow2=1;
  for (int i=6;i>=0;i--) {
    pow*=2;
    if (bin[i]!='0')
      sumpow2+=pow;
  }
  return sumpow2;
}

void calculCode(int noeud, char* buf) {
  if (fg[noeud]==-1)
    {
      code[noeud]=(char *)malloc(strlen(buf)+1);
      strcpy(code[noeud],buf);
    }
  else
    {
      char* newbuf=(char*)malloc(strlen(buf)+2);//+2=le nouveau car du code et le car terminal
      strcpy(newbuf,buf);
      strcat(newbuf,"0");
      calculCode(fg[noeud],newbuf);
      newbuf[strlen(newbuf)-1]='1'; //0 devient 1
      calculCode(fd[noeud],newbuf);
      free(newbuf);
    }
}

void Linear(int noeud, char* Arbre,char* chemin,int* Rconv) {
  
  if (fg[noeud]==-1) {
    strcat(Arbre,"01");
    char* bin=ctob(Rconv[noeud]);
    strcat(Arbre,bin);
    free(bin);
       
  }
  
  else {
    strcat(Arbre,"00");
    char* buf=(char*)malloc((strlen(chemin)+3)*sizeof(char));
    strcpy(buf,chemin);
    strcat(buf,"00");
    Linear(fg[noeud],Arbre,buf,Rconv);
    strcat(Arbre,buf);
    buf[strlen(buf)-1]='1';
    buf[strlen(buf)-2]='1';
    Arbre[strlen(Arbre)-1]='1';
    Arbre[strlen(Arbre)-2]='1';
    Linear(fd[noeud],Arbre,buf,Rconv);
    free(buf);
  }
}

void cryptOcc() {
  for (int i=0;i<256;i++) {
    if (Occ[i]!=0) {
      strcat(strcat(Table,ctob(i)),itob(Occ[i]));
    }
  }
}
      
	     
      
void cryptage(char* chaine,FILE* dest) {
   
  int k=strlen(chaine);
  int nbflush=(k-(8-n))/8+1;
  huffsize+=nbflush-1;
 
  int j=0;
  //printf("tampons %i \n",nbflush);
  // printf("%i \n",n);
  while (j<nbflush) {
    //la taille est supérieure à l'espace du buffer
    if (k-poschaine>=8-n) {
      //copier jusqu'a remplissage du buffer
      for (int i=n;i<8;i++) {
	buffer[i]=chaine[poschaine];
	poschaine++;
      }
      printf("%s \n",buffer);
      //vider le buffer dans le fichier
      fputc(btoc(buffer),dest);
      //nettoyer le buffer
      for (int i=0;i<8;i++)
	buffer[i]='0';
      n=0;
    }
    j++;
  }
 
  int len=k-poschaine;
  //printf("n:%i \n",n);
  int f=n;
  for (int i=f;i<f+len;i++) {
    buffer[i]=chaine[poschaine];
    poschaine++;
    n++;
  }
  poschaine=0;
  //  printf("buffer:%s \n",buffer);
  //n+=k%8;  
}


int main(int argc, char* argv[]) {
  /*-----------------------securite--------------------------*/
  if (argc!=3) {
    fprintf(stderr,"Usage: %s <source> <destination>",argv[0]);
    return 1;
  }

  /*------------------------ProbaCar--------------------------*/
  float Proba[256]={0.0};
  
  int Taille=ProbaCar(argv[1],Proba);
  if (0>Taille) {
    fprintf(stderr,"calcul des proba impossible \n");
    return 2;
  }
  int nbcar=0;  
  for (int i=0; i<256; i++) {
    if (Proba[i]!=0.0) {
      nbcar++;
    }
  }
  /*------------------------Compactage--------------------------*/
  int Conv[256]={-1};
  float Prob[nbcar];
  int Rconv[nbcar];
  int j=0;
  for(int k=0;k<256;k++) {
    if(Proba[k]!=0.0) {
      Prob[j]=Proba[k];
      Conv[k]=j;
      Rconv[j]=k;
      j++;
    }
  }

  for(int i=0;i<nbcar;i++)
    printf("%c:%f \n",Rconv[i],Prob[i]);

  /*-------------------------Arbre------------------------------*/

  int nbnoeud=2*nbcar-1;
  parent=(int*)malloc(nbnoeud*sizeof(int));
  fg=(int*)malloc(nbnoeud*sizeof(int));
  fd=(int*)malloc(nbnoeud*sizeof(int));

  for (int i=0; i<nbnoeud; i++) {
    parent[i]=fg[i]=fd[i]=-1;
  }

  int i;
  for (int nn=nbcar; nn<nbnoeud;nn++) {
    i=j=-1; 
    
    for (int k=0; k<nn; k++) {
      if (parent[k]==-1) {
	if (i==-1)
	  i=k;
	else if (j==-1)
	  j=k;
	else if (Prob[k]<Prob[i]) {
	  j=i;
	  i=k;
	}
	else if (Prob[k]<Prob[j]) 
	  j=k;
      }
    }
    parent[i]=parent[j]=nn;
    fg[nn]=i;
    fd[nn]=j;
    Prob[nn]=Prob[i]+Prob[j];
    
    printf ("%d: fg=%d fd=%d prob=%f \n", nn,fg[nn],fd[nn], Prob[nn]);
  }

  /*--------------------------------codes---------------------------------*/

  code=(char**)malloc(nbcar*sizeof(char*));
  calculCode(nbnoeud-1,"");
  int somcode=0;
  for (int i=0; i<nbcar; i++)
    {
      somcode+=strlen(code[i]);
          printf("%c : %s \n",Rconv[i],code[i]);
    }

  
  /*--------------------------------arbre-lineaire--------------------------------*/


  /*
  Arbre=(char*) malloc((2*somcode)+(10*nbcar));
  Linear(nbnoeud-1,Arbre,"",Rconv);
  printf("linear:%s  size=%i \n",Arbre,strlen(Arbre));
  */
  /*---------------------------caractère-nbrOcc--------------------------------------*/
  
  Table=(char*)malloc(5*nbcar*sizeof(char)+1);
  Table[5*nbcar]='\0';
  cryptOcc();
 
  /*-----------------------------------renommage-ouputfile-----------------------------------------*/

  char* nnom;
  char *nom=(char*)malloc((strlen(argv[2])*sizeof(char)));
  strcpy(nom,argv[2]);
  int t=strlen(nom)-1;
  while (t!=-1 && nom[t]!='.') 
    t--;
  if (t == -1) {  
    nnom=(char *)malloc((strlen(nom)+6)*sizeof(char));
    strcpy(nnom,nom);
    strcat(nnom,".huff\0");
  }
  else {
    nnom=(char *)malloc((strlen(nom)-t+6)*sizeof(char));
    strncpy(nnom,nom,strlen(nom)-t);
    strcat(nnom,".huff\0");
  }
  FILE* f=fopen(nnom,"w+");
  free(nom);
  free(nnom);

  /*------------------------cryptage--------------------------*/
  FILE* file=fopen(argv[1],"r");
  
  for (int i=0;i<8;i++)
    buffer[i]='0';
  buffer[8]='\0';
  
  printf("taille:%i \n",Taille);
  cryptage(itob(Taille),f);
  printf("nbrcar:%i \n",nbcar);
  cryptage(ctob(nbcar),f);
  printf("Table \n");
  cryptage(Table,f);
  printf("texte \n");
   int c;
  while (EOF!=(c=fgetc(file))) {
    // printf("car:%c code:%s \n",c,code[Conv[c]]);
    cryptage(code[Conv[c]],f);
  }
  
  for (int i=n;i<8;i++){
    buffer[i]='1';
  }
  printf("dernier buffer:%s \n",buffer);
  fputc(btoc(buffer),f);

  fclose(file);
  fclose(f);

  /*-----------------------------gain--------------------------------*/

  printf("taille:%i \n nbcar:%i \n",Taille,nbcar); 
  printf("taux de compression :%f \n", huffsize/(float)Taille);
  printf("taille moyenne d'un code:%f \n",somcode/(float)nbcar);
  /*-------------------------------free-memory----------------------------*/

  free(parent);
  free(fg);
  free(fd);
  for (int i=0;i<nbcar;i++) {
    code[i]=NULL;
  }
  free(code);
  Table=NULL;
  free(Table);
    
  return 0;
}


  
  
    