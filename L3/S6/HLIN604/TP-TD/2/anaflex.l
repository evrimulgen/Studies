%{
union {  int i;float f; char* s;} yylval;
#define IF 300
#define THEN 301
#define ELSE 302
#define ID 303
#define LITENT 400
#define LITID 401
#define LITFLOAT 402
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%} 
%option noyywrap

%%
if {return IF;}
then {return THEN;}
else {return ELSE;}
[1-9][0-9]*            {yylval.i = atoi(yytext); return LITENT ;}
0[0-7]+               {yylval.i= strtol(yytext,NULL,8);   return LITENT; }    
0[xX][0-9A-Fa-f]+     {yylval.i= strtol(yytext,NULL,16 ) ;return LITENT; }
[A-Za-z][A-Za-z0-9]*   {yylval.s= strdup(yytext); return LITID; }
([0-9]+\.[0-9]*|\.[0-9]+).([eEdD][+-]?[0-9]+)   {yylval.f=strtof(yytext,NULL);return LITFLOAT;}
"/*"([^*]|"*"+[/])*"/*"+'/'   {}
%%

int main(){
int j;
char* invite="Saisissez un(des)mot(s) matchant une express. regu. ; finissez par EOF (CTRL-D) SVP : ";
 printf("%s",invite);
 while((j=yylex()) != 0)  
{
switch(j)
{
case IF : printf("%d \n",IF);break;
case ELSE :  printf("%d \n", ELSE);break;
case THEN :  printf("%d \n", THEN);break;
case ID :  printf("%s \n", yylval.s);break;
case LITID : printf("%s \n", yylval.s);break;
case LITENT : printf("%d \n", yylval.i);break;
case LITFLOAT : printf("%f \n", yylval.f);break;
}
}
 return 0;
}

