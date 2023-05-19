
// -----------------------------------------------------------------------------------------------------
// Declaración de funciones definidas por el usuario (FDU), Métodos o Procedimientos
// -----------------------------------------------------------------------------------------------------
void gotoxy(int x,int y);
void sysbox(int f1,int c1,int f2,int c2, int tr);

// -----------------------------------------------------------------------------------------------------
//  Método      : gotoxy
//  Utilidad    : Controlan las coordenadas de salida de datos en donde
//                (x,y):  x es para la posición en horizontal o columnas
//                        y es para la posición en vertical o filas
//  Parametros  : f1 = Fila1
//	              f2 = Fila2
//          	  c1 = Columna1
//	              c2 = Columna2
//	              tr = Tipo de raya
// -----------------------------------------------------------------------------------------------------


// -----------------------------------------------------------------------------------------------------
//
//  Método      : sysbox
//  Utilidad    : Dibuja una ventana (Windows)
//  Parametros  : f1 = Fila1
//	              f2 = Fila2
//          	  c1 = Columna1
//	              c2 = Columna2
//	              tr = Tipo de raya
//
// -----------------------------------------------------------------------------------------------------
int x,y;                      // x=Filas y y=Columnas
char eis,rah,eds,rav,eii,edi; // caracteres ASCII

void sysbox(int f1,int c1,int f2,int c2, int tr)
{
  if ((f1>=0)&&(f1<300)&&(f2>0)&&(f2<=300)&&(c1>=0)&&(c1<300)&&(c2>0&&(c2<300)&&(f2>f1)&&(c2>c1)))
  {
     switch (tr)                   // Evalua el tipo de raya
     {
       case 1: eis=218;rah=196;eds=191;rav=179;eii=192;edi=217;break; // Raya simple
       case 2: eis=201;rah=205;eds=187;rav=186;eii=200;edi=188;break; // Raya Doble
       case 3: eis=219;rah=219;eds=219;rav=219;eii=219;edi=219;break; // Raya Reverso
     }
     gotoxy(c1,f1);printf("%c",eis);  // Raya de esquina  izquierda superior
     gotoxy(c2,f1);printf("%c",eds);  // Raya de esquina  derecha superior
     for (y=c1+1;y<=c2-1;y++)
     {
       gotoxy(y,f1);printf("%c",rah); // Raya horizontal arriba
       gotoxy(y,f2);printf("%c",rah); // Raya horizontal abajo
     }
     for (x=f1+1;x<=f2-1;x++)
     {
       gotoxy(c1,x);printf("%c",rav); // Raya vertical izquierda
       gotoxy(c2,x);printf("%c",rav); // Raya vertical derecha
     }
     gotoxy(c1,f2);printf("%c",eii);  // Raya de esquina izquierda inferior
     gotoxy(c2,f2);printf("%c",edi);  // Raya de esquina derecha inferior
  }
}


