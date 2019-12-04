/**
 * @file afd.h     
 * @author Michel Meynard
 * @brief Définition d'un AFD
 */

/*
//etats automate de MM
#define EINIT 0
#define EA 1
#define EAB 2
#define EABC 3
#define EB 4
#define EBD 5
#define NBETAT 6
*/
//etats automate du TD (union des automates vu en TD)
#define EINIT 0
#define EI 1
#define EIF 2
#define EID 3
#define EENT 4
#define EFLOAT 5
#define EP 6
#define ES 7 
#define ESS 8
#define ECOM1 9
#define ESE 10 
#define ESEE 11
#define ECOM 12
#define ESEP 13
#define NBETAT1 14


//int TRANS[NBETAT][256];		/* table de transition : état suivant */
//int JETON[NBETAT];		/* jeton à retourner */


int TRANS[NBETAT1][256];		/* table de transition : état suivant */
int JETON[NBETAT1];		/* jeton à retourner */

/*

int creerAfd(){		       
  int i;int j;		       
  for (i=0;i<NBETAT;i++){
    for(j=0;j<256;j++) TRANS[i][j]=-1; 
    JETON[i]=0;			
  }
  
  TRANS[EINIT]['a']=EA;TRANS[EA]['b']=EAB;TRANS[EAB]['b']=EAB;
  TRANS[EAB]['c']=EABC;TRANS[EINIT]['b']=EB;TRANS[EB]['d']=EBD; 
  JETON[EA]=JETON[EABC]=1;
  JETON[EBD]=-1;
}
*/

void classe(int ed, int cd, int cf, int ef)
{
  for(int i=cd;cd<=cf;i++)
    TRANS[ed][cd]=ef;
}


int creerAfd_TD(){			/* Construction de l'AFD */
  int i;int j;			/* variables locales */
  for (i=0;i<NBETAT1;i++){
    for(j=0;j<256;j++) TRANS[i][j]=-1; /* init vide */
    JETON[i]=0;			/* init tous états non finaux */
  }
  /* Transitions de l'AFD */
  //EINIT
  TRANS[EINIT]['i']=EI;classe(EINIT,0,9,EENT);classe(EINIT,'a','z',EID);classe(EINIT,'A','Z',EID);TRANS[EINIT]['.']=EP;TRANS[EINIT]['/']=ES;TRANS[EINIT]['\t']=ESEP;TRANS[EINIT][' ']=ESEP;TRANS[EINIT]['\n']=ESEP;
  //ESEP
  TRANS[ESEP]['\t']=ESEP;TRANS[ESEP]['\n']=ESEP;TRANS[ESEP][' ']=ESEP;
  //EI
  TRANS[EI]['f']=EIF;classe(EI,0,9,EID);classe(EI,'a','z',EID);classe(EI,'A','Z',EID);
  //EIF
  classe(EIF,0,9,EID);classe(EIF,'a','z',EID);classe(EIF,'A','Z',EID);
  //EID
  classe(EID,0,9,EID);classe(EID,'a','z',EID);classe(EID,'A','Z',EID);
  //EENT
  classe(EENT,0,9,EENT);TRANS[EENT]['.']=EFLOAT;
  //EFLOAT
  classe(EFLOAT,0,9,EFLOAT);
  //EP
  classe(EP,0,9,EFLOAT);
  //ES
  TRANS[ES]['/']=ESS;TRANS[ES]['*']=ESE;
  //ESS
  TRANS[ESS]['\n']=ECOM1;classe(ESS,0,26,ESS);classe(ESS,28,255,ESS);
  //ESE
  TRANS[ESE]['*']=ESEE;classe(ESE,0,41,ESE);classe(ESE,43,255,ESE);
  //ESEE
  TRANS[ESEE]['/']=ECOM;TRANS[ESEE]['*']=ESEE;classe(ESEE,0,41,ESE);classe(ESEE,48,255,ESE);
  JETON[EI]=EI;
  JETON[EIF]=EIF;
  JETON[EID]=EID;
  JETON[EENT]=EENT;
  JETON[EFLOAT]=EFLOAT;
  JETON[ECOM1]=ECOM1;
  JETON[ECOM]=ECOM;
  JETON[ESEP]=ESEP;
    /* états finaux */
}
