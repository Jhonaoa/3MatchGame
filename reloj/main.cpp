#include<stdio.h>
#include<conio.h>
#include<windows.h>
using namespace std;

void salir()
{
    if ( kbhit() )
        exit(0);

}

void reloj () {
     int h=23, m=59, s=55;
     while(true) {
           system("cls");//gotoxy (36,12);
           printf ("%2d:%2d:%2d",
                   h=((s==0 && m==0)?((h>22)?0:h+1):h),
                   m=((s==0)?((m>58)?0:m+1):m),
                   s=((s>58)?0:s+1));
           salir();
           Sleep (1000);
     }
}

main () {
     reloj ();
}
