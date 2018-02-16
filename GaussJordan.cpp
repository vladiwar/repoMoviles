#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <stdio.h>


using namespace std;

int cadena(char *op)
{
    
int c;
c=0;

if(op[15] != ' ')
{
cout<<"\n Captura demaciado gde, intentelo nuevamente con un NUMERO que tenga como maximo 14 caracteres ";
c=0;
cin.get();
}
else
{
c=1;
}

cin.get();
return c;
}


char inicia (char *op)
{
int c;
	for(c=0 ; c<50; c++)
	{
	op[c]=' ';
	}
return *op;
}

int csymletras(char *op)
{
int o,c,r;
o=0;
	for(c=0; c<10; c++)
	{

		if(op[c] != '1' && op[c] != '2' && op[c] != '3' && op[c] != '4'  && op[c] != '5'  &&  op[c] != '6' && op[c]!='7' && op[c] != '8' && op[c]!='9' && op[c]!='0' && op[c]!= ' ')
			{
			r=1  ;

			}
			else
			{
			r=0;
			}
		o=o+r;
	}

return o;
}

int letras(char *op)
{
int o,c,r;
o=0;
	for(c=0; c<10; c++)
	{

		if(op[c] != '-' && op[c] != '.' && op[c] != '1' && op[c] != '2' && op[c] != '3' && op[c] != '4'  && op[c] != '5'  &&  op[c] != '6' && op[c]!='7' && op[c] != '8' && op[c]!='9' && op[c]!='0' && op[c]!= ' ')
			{
			r=1  ;

			}
			else
			{
			r=0;
			}
		o=o+r;
	}
if(o>1)
{
cout<<"\n No es un numero , x favor de teclear un numero ";
cin.get();
}
return o;
}


int sletras(char *op)
{
int o,c,r;
o=0;
	for(c=0; c<10; c++)
	{

		if(op[c] != '1' && op[c] != '2' && op[c] != '3' && op[c] != '4'  && op[c] != '5'  &&  op[c] != '6' && op[c]!='7' && op[c] != '8' && op[c]!='9' && op[c]!='0' && op[c]!= ' ')
			{
			r=1  ;

			}
			else
			{
			r=0;
			}
		o=o+r;
	}
if(o>1)
{
cout<<"\n No es un numero entero , x favor de teclear un numero entero";
cin.get();
}
return o;
}



int punto(char *op)
{
int a,b,c;
c=0;
for (a=0 ; a<10 ; a++)
{
	if (op[a]=='.' )
	{
	b=1;
	}
	else
	{
	b=0;
	}
	c=c+b;
}
return c;
}


int guion(char *op)
{
int a,b,c;
c=0;

for (a=0 ; a<10 ; a++)
{
	if (op[a]=='-' )
	{
	b=a+1;
	}
	else
	{
	b=0;
	}
	c=c+b;
}
return c;
}


int mcvalidacion(char *op)
{
int a,b,v;
char *o;
o=op;
a=cadena(o);
b=sletras(o);
if(a<1 ||b>1)
{
v=0;
}
else
{
v=1;
}
return v;
}


int validacion(char *op)
{
int a,b,c,d,v;
char *o;
o=op;
a=cadena(o);
b=letras(o);
c=guion(o);
d=punto(o);
if(a<1 || b>1 || c>1 || d>1)
{
v=0;
}
else
{
v=1;
}
return v;
}



void captura(double a[50][50],int n)
{
int c,f,v;
char A[5000];
for(c=0;c<n;c++)
{
                for(f=0;f<n+1;f++)
                { 
                                  if(f<n)
                                  {
                                  do{system("cls");
                                  inicia(A);
                                  cout<<"\n\n\n\n  Captura de la matriz :";
                                  cout<<"\n\n X"<<c+1<<","<<f+1<<" :  ";
                                  cin>>A;
                                  v=validacion(A);
                                  }while (v<1);
                                  a[c][f]=atof(A);
                                  }
                                  else
                                  {
                                      system("cls");
                                  cout<<"\n\n\n\n  Captura de la matriz :";
                                  cout<<"\n\n Constante = ";
                                  cin>>a[c][f];
                                  }                               
                                
                }

}
}



int imprimir (double a[50][50],int n)
{
int c,f,r,m;
r=0;
double e,d;
e = a[0][0];

m=n*n;
for(c=0;c<n;c++)
{
 for(f=0;f<n;f++)
 {
  d =a[c][f];
  if ( d != e)
  {
  
   r=r+0; 
  }
  else
  {
      r=r+1;
  }
 }
}


if(r!=m)
  {
  cout<<"Matriz Con solucion :";
  cout<<"\n\n\n Matriz de "<<n<<" x "<<n<<"\n\n\n  ";
for(c=0;c<n;c++)
{
                for(f=0;f<n+1;f++)
                {
                                if(f<n)
                                {
                                    cout<<"  "<<a[c][f];
                                }
                                else
                                {
                                    cout<<" = "<<a[c][f];
                                }                                    
                }
                cout<<"\n  ";
}
  }
else
{
  
  cout<<"\n\n\n\n   Esta matriz no tiene SOLUCION :\n\n ";
for(c=0;c<n;c++)
{
                for(f=0;f<n+1;f++)
                {
                                if(f<n)
                                {
                                    cout<<"  "<<a[c][f];
                                }
                                else
                                {
                                    cout<<" = "<<a[c][f];
                                }                                    
                }
                cout<<"\n  ";
}
}
}


void metodogaussjordan (double a[50][50], int n)
{
int e,ee,c,f,cc,ff,h;
double r[50][50],d,g,b,s;
e = 0;

for(c=0;c<n;c++)
{
b=a[c][c]; 
           if(b != 0 )
           {
                      for(f=0;f<n+1;f++)
                      {
                            
                      a[c][f]=(a[c][f])/b;
                      r[c][f]=a[c][f];                    
                      }
           
           cout<<"\n R"<<c+1<<" = R"<<c+1<<"/"<<b;
           cout<<"\n\n";
           for(ee=0;ee<n;ee++)
           {
                           for(ff=0;ff<n+1;ff++)
                           {
                           
                           cout<<"   "<<a[ee][ff]; 
                                    
                           }
                           cout<<"\n";
           }
           
          cout<<"\n\n Suma de renglones multiplicados por pibote\n\n";
           for(cc=e;cc<n;cc++)
           {
           d=a[cc+1][c];
           
                           
                           
                           for(ff=0;ff<n+1;ff++)
                           {
                           r[cc+1][ff]=((-1*d)*(a[c][ff]))+(a[cc+1][ff]);
                           
                                
                           
                           a[cc][ff]=r[cc][ff];         
                           }
                           
                            
                           
           }
          e=e+1;
          
          if(c>0 )
          {
          for(cc=0;cc<c;cc++)
              {
                    g=r[cc][c];
                    for(ff=0;ff<n+1;ff++)
                    {
                           r[cc][ff]=((-1*g)*(a[c][ff]))+(a[cc][ff]);
                         a[cc][ff]=r[cc][ff];
                    }
                    
            
               }
          }
          
          if(c<n)
          {
                 for(cc=0;cc<n;cc++)
                 {
           
           
                           for(ff=0;ff<n+1;ff++)
                           {
                                                
                           cout<<"   "<<r[cc][ff]; 
                                  
                           }
                            
                           cout<<"\n";
                  }
           }
           cout<<"\n";
           }  
           
           
           else
            {
                         
                   for(cc=c;cc<n;cc++)
                   {
                          s=a[cc][c];
                          if(s != 0)
                          {
                               h=cc;
                          }
                   
                   }
                   cout<<"\n Sumamos R"<<h+1<<" a R"<<c+1<<"\n";                
                   for(f=c;f<n+1;f++)
                        {
                        a[c][f]=a[c][f]+a[h][f];
                        }
                   imprimir(a,n);
           b=a[c][c];
           for(f=0;f<n+1;f++)
           {
                            
                             a[c][f]=(a[c][f])/b;
                             r[c][f]=a[c][f];                    
           }
           
           cout<<"\n R"<<c+1<<" = R"<<c+1<<"/"<<b;
           cout<<"\n\n";
           for(ee=0;ee<n;ee++)
           {
                           for(ff=0;ff<n+1;ff++)
                           {
                           
                           cout<<"   "<<a[ee][ff]; 
                                    
                           }
                           cout<<"\n";
           }
           
          cout<<"\n\n Suma de renglones multiplicados por pibote\n\n";
           for(cc=e;cc<n;cc++)
           {
           d=a[cc+1][c];
           
                           
                           
                           for(ff=0;ff<n+1;ff++)
                           {
                           r[cc+1][ff]=((-1*d)*(a[c][ff]))+(a[cc+1][ff]);
                           
                                
                           
                           a[cc][ff]=r[cc][ff];         
                           }
                           
                            
                           
           }
          e=e+1;
          
          if(c>0 )
          {
          for(cc=0;cc<c;cc++)
          {
          g=r[cc][c];
                    for(ff=0;ff<n+1;ff++)
                    {
                           r[cc][ff]=((-1*g)*(a[c][ff]))+(a[cc][ff]);
                         a[cc][ff]=r[cc][ff];
                    }
                    
            
          }
          }
          
          if(c<n)
          {
          for(cc=0;cc<n;cc++)
           {
           
           
                           for(ff=0;ff<n+1;ff++)
                           {
                                                
                           cout<<"   "<<r[cc][ff]; 
                                  
                           }
                            
                           cout<<"\n";
           }}
           cout<<"\n"; 
                                           
            }   
}
}
     




void portada ()
{
cout<<"\n\n                    INSTITUTO POLITECNICO NACIONAL ";
cout<<"\n\n           Escuela Siperior de Ingenieria Mecanica y electrica";
cout<<"\n\n                            ESIME Zacatenco";
cout<<"\n\n              Ingenieria en Comunicaciones y Electronica";
cout<<"\n\n                       Academia de Computacion";
cout<<"\n\n                       Sistemas de Ecuaciones";
cout<<"\n\n                           GAUSS JORDAN";
cout<<"\n\n                   M. en C. Enrique Ugalde Miranda";
cout<<"\n\n                             Gpo : 4CV7";
cout<<"\n\n   Elaboracion : Tovar Salamanca Edgar          Bol. 2010302159";
cout<<"\n\n                 Vela Crisostomo Fernando D.    Bol. 20  ";
getch ();     
}


int determinante (double a[50][50], int n)
{
int e,ee,c,f,cc,ff,h,R,re;
double r[50][50],d,g,b,ed,s;
e = 0;

for(c=0;c<1;c++)
{
b=a[c][c]; 
           if(b != 0 )
           {
                      for(f=0;f<n;f++)
           {
                            
                             a[c][f]=(a[c][f])/b;
                             r[c][f]=a[c][f];                    
           }
           
           
           for(ee=0;ee<n;ee++)
           {
                           for(ff=0;ff<n;ff++)
                           {
                           
                           
                                    
                           }
                           
           }
           
           for(cc=e;cc<n;cc++)
           {
           d=a[cc+1][c];
           
                           
                           
                           for(ff=0;ff<n;ff++)
                           {
                           r[cc+1][ff]=((-1*d)*(a[c][ff]))+(a[cc+1][ff]);
                           
                                
                           
                           a[cc][ff]=r[cc][ff];         
                           }
                           
                            
                           
           }
          e=e+1;
          
          if(c>0 )
          {
          for(cc=0;cc<c;cc++)
          {
          g=r[cc][c];
                    for(ff=0;ff<n;ff++)
                    {
                           r[cc][ff]=((-1*g)*(a[c][ff]))+(a[cc][ff]);
                         a[cc][ff]=r[cc][ff];
                    }
                    
            
          }
          }
          
          if(c<n)
          {
          for(cc=0;cc<n;cc++)
           {
           
           
                           for(ff=0;ff<n;ff++)
                           {
                                                
                            
                                  
                           }
                            
                           
           }}
           
           }  
           else
            {
                         
                   for(cc=c;cc<n;cc++)
                   {
                          s=a[cc][c];
                          if(s != 0)
                          {
                               h=cc;
                          }
                   
                   }
                   cout<<"\n Sumamos R"<<h+1<<" a R"<<c+1<<"\n";                
                   for(f=c;f<n;f++)
                        {
                        a[c][f]=a[c][f]+a[h][f];
                        }
                  
           b=a[c][c];
           for(f=0;f<n;f++)
           {
                            
                             a[c][f]=(a[c][f])/b;
                             r[c][f]=a[c][f];                    
           }
           
           
           for(ee=0;ee<n;ee++)
           {
                           for(ff=0;ff<n;ff++)
                           {
                           
                           
                                    
                           }
                           
           }
           
          cout<<"\n\n \n\n";
           for(cc=e;cc<n;cc++)
           {
           d=a[cc+1][c];
           
                           
                           
                           for(ff=0;ff<n;ff++)
                           {
                           r[cc+1][ff]=((-1*d)*(a[c][ff]))+(a[cc+1][ff]);
                           
                                
                           
                           a[cc][ff]=r[cc][ff];         
                           }
                           
                            
                           
           }
          e=e+1;
          
          if(c>0 )
          {
          for(cc=0;cc<c;cc++)
          {
          g=r[cc][c];
                    for(ff=0;ff<n;ff++)
                    {
                           r[cc][ff]=((-1*g)*(a[c][ff]))+(a[cc][ff]);
                         a[cc][ff]=r[cc][ff];
                    }
                    
            
          }
          }
          
          if(c<n)
          {
          for(cc=0;cc<n;cc++)
           {
           
           
                           for(ff=0;ff<n;ff++)
                           {
                                                
                            
                                  
                           }
                            
                           
           }}
                                                     
            }   
}

R=0;

for(c=0;c<n;c++)
{
 for(f=0;f<n;f++)
 {
  d =a[c][f];
  if ( d != 0)
  {
  
   R=R+0; 
  }
  else
  {
      R=R+1;
  }
 }
}

re=n*(n-1);

if(re>R)
{
re=0;
cout<<"\n\n Matriz Con solucion.";
}
else
{
re=1;
cout<<"\n\n Matriz sin solucion . Determinante igual a 0 , por lo tanto la matriz no tendra solucion como se muestra a continuacion.";
}
getch();
return re;
}

double copiar(double a[50][50],int n,double b[50][50])
{
int c,f,i;

for(c=0;c<n;c++)
{
for(f=0;f<n+1;f++)
{
b[c][f]=a[c][f];
}
}       
return 0;
}

int main ()
{
portada();
char N[50000],SN[50000],S[50000],C[50000],F[50000];
int s,n,c,sn,v,f,d;
double a[50][50],b[50][50];
do{do{system("cls");
inicia(N);
inicia(SN);
cout<<"\n\n\n\n\n         BIENVENID@";
cout<<"\n Elinacion de GAUSS JORDAN de una Matriz n x n \n\n\n";
cout<<"\n Por favor teclee el tamaño de la matriz menor a 50: ";
cin>>N;
v=mcvalidacion(N);
}while(v<1);
n=atoi(N);
if(n>1)
{
captura(a,n);
do{do{do{system("cls");
inicia(S);
imprimir(a,n);
cout<<"\n\n Deseas Corregir algun dato ?\n";
cout<<"  1.-Si.\n  2.-No (coninuar).\n\n OPC. :   ";
cin>>S;
v=mcvalidacion(S);
}while(v<1);
s=atoi(S);
if(s<2)
{
do{system("cls");
inicia(C);
cout<<"\n\n Teclee numero de columna :  ";
cin>>C;
v=mcvalidacion(C);
}while(v<1);
c=atoi(C);
do{system("cls");
inicia(F);
cout<<"\n\n Teclee numero de fila :  ";
cin>>F;
v=mcvalidacion(F);
}while(v<1);
f=atoi(F);
do{system("cls");
inicia(SN);
cout<<"\n\n Teclee el valor correcto :  ";
cin>>SN;
v=validacion(SN);
}while(v<1);
a[f-1][c-1]=atof(SN);
}
else 
{
cout<<"\n\n  Generando preceso ....";

}
}while(s<1 || s>2);
}while(s<2);
cout<<"\n\n\n\n";
copiar(a,n,b);
d=determinante(b,n);
metodogaussjordan(a,n);


cout<<"\n\n";
cout.precision(20);
for(c=0;c<n; c++)
{
cout<<"\n\n  X"<<c+1<<" = "<<a[c][n];
}
getch();
}
else 
{
cout<<"\n\n No es una matriz , eso es solo una igualdad , el valor de tu incognita es el siguiente :";
getch();
captura(a,n);
imprimir(a,n);

cout<<"\n\n\n\n";
metodogaussjordan(a,n);


cout<<"\n\n";
cout.precision(20);
for(c=0;c<n; c++)
{
cout<<"\n\n  X"<<c+1<<" = "<<a[c][n];
}
getch();
}
do{do{system("cls");
inicia(SN);
cout<<"\n\n\n   ¿ DESEA RESOLVER OTRO SISTEMA DE ECUACIONES ?\n\n\n\n  1.- Si \n\n  2.- NO(salir)\n\n OPC. : ";
cin>>SN;
v=mcvalidacion(SN);

}while(v<1);
sn=atoi(SN);
}while(sn<1 || sn>2);
}while(sn<2);
return 0;
}
