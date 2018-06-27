#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h> 
int f=0,k=0;
const double PI = 3.14159265;
double calc(const char* s){
    char*  p, c; 
	double n, sum = strtod(s, &p);
	char sinus[]="sin", cosinus[]="cos", tangens[]="tg", arctangens[]="arctg", arcsinus[]="arcsin", arccosinus[]="arccos";
	char *isin, *icos, *itg, *iarctg, *iarcsin, *iarccos;
    if(s == p)
        return 0.0;
    isin=strstr(s,sinus);
	if (isin != NULL) {sum=sin(sum); k=1;}
	icos=strstr(s,cosinus);
	if (icos != NULL) {sum=cos(sum);k=1;}
	itg=strstr(s,tangens);
	if (itg != NULL) {sum=tan(sum);k=1;}
	iarctg=strstr(s,arctangens);
	if (iarctg != NULL) {sum=atan(sum);k=1;}
	iarcsin=strstr(s,arcsinus);
	if (iarcsin != NULL) {sum=asin(sum);k=1;}
	iarccos=strstr(s,arccosinus);
	if (iarccos != NULL) {sum=acos(sum);k=1;}
    if (k==0) {
    sum = strtod(s, &p);
    for(s = p; *s; s = p){
        while(*s && isspace(*s))
            ++s;
        if(! *s)
            break;
        c = *s++;
        n = strtod(s, &p);
        if(s == p)
            break; 
        switch(c){
        case '+':
            sum += n;
            break;
        case '-':
            sum -= n;
            break;
        case '/':
        	if (n==0) f=1;
        	else {sum /=n;}
        	break;
        case '*':
        	sum *=n;
        	break;
        case '^':
            sum=pow (sum,n);
            break;
        default:
            return 0.0;
       }
    }
    }
    return sum;
}
 
int main(void){
    char s[128], pause[]="q";
    char *ipause;
    int w=1;
    while (w==1) {
      fgets(s, sizeof(s), stdin);
      ipause=strstr(s,pause);
      if (ipause != NULL) break;
      calc(s);
      if (f==1) {printf ("ERROR\n"); f=0;}
      else {printf("Result: %lg\n", calc(s)); }
      if (k==1) k=0;
    }
}

