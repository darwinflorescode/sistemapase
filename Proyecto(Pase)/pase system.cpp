#define CRT_NO_SECURE_WARNINGS//variable que no permite el truncamiento de las variables mediante las advertencias
//Cabezeras respectivas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include "box.h"
#include "txtcolor.h"
#include "validacion.h"
//Variables Gloables
//tamaño de estudiantes,usuario y madres definido como limite
#define F 400
//tamaño de productos definido como limite
#define p 400
//tamaño de menus definido como limite
#define ali 100
int caracter = 200;//variable auxiliar para la validacion de solo letras y numeros

//****************************************************************************************************************************************
//  VARIABLES Y PROTOTIPOS DE INICIO DE SESSION
//****************************************************************************************************************************************
char usuario[F], password[F];//Variables para almacenar user and pass para iniciar session
void encabezado();
void encabezadoinicio();
void cargando();
void lodbar();
void principal();
void login();
void copyright(int cond,int contar);


//***************************************************************************************************************************************
//												VARIABLES Y PROTOTIPOS DE MANTENIMIENTO USUARIO
//***************************************************************************************************************************************
char codigoU[F][200],user[F][200],pass[F][200];
int contU,contC;
void manttouser();
void iniciarU(); //Valores definidos del usuario
void funcionesUser(char opcion[20]);
char pase[25] = "SISTEMA PASE";
void logo();

//****************************************************************************************************************************************
//												MANTENIMIENTO COMITE DE MADRES
//****************************************************************************************************************************************
struct Cmadre
{
	char nombreM[200],apellidoM[200],duiM[11],telM[10];
	char dirM[300],comite[10],nombreCM[200];
}madre[F];
int contM;
void manttoMadre();
void insertM();
void mostrarM();
void eliminarM();
void modificarM();

//***************************************************************************************************************************************
//											VARIABLES Y PROTOTIPOS PARA LOS ESTUDIANTES
//***************************************************************************************************************************************

// variables globales para el mantenimeinto de los estudiante de cada grado   
char carnetU[F][100],nombre[F][100],apellidos[F][100];
char carnetU1[F][100],nombre1[F][100],apellidos1[F][100];
char carnetU2[F][100],nombre2[F][100],apellidos2[F][100];
char carnetU3[F][100],nombre3[F][100],apellidos3[F][100];
char carnetU4[F][100],nombre4[F][100],apellidos4[F][100];
char carnetU5[F][100],nombre5[F][100],apellidos5[F][100];
char carnetU6[F][100],nombre6[F][100],apellidos6[F][100];
char carnetU7[F][100],nombre7[F][100],apellidos7[F][100];
char carnetU8[F][100],nombre8[F][100],apellidos8[F][100];
int contN,contE,contN1,contE1,contN2,contE2,contN3,contE3,contN4,contE4,contN5,contE5;
int contN6,contE6,contN7,contE7,contN8,contE8;
//****************************************************************************************************************************************
//								PROTOTIPOS PARA REGISTROS, LLENADOS Y MOSTRAR SECCIONES
//****************************************************************************************************************************************
void menusecciones();
void menuestudiantes();
void menuestudiantes1();
void menuestudiantes2();
void menuestudiantes3();
void menuestudiantes4();
void menuestudiantes5();
void menuestudiantes6();
void menuestudiantes7();
void menuestudiantes8();
void llenado(); 
void llenado1(); 
void llenado2();
void llenado3(); 
void llenado4(); 
void llenado5(); 
void Estudiantes(char opcion[20]);
void Estudiantes1(char opcion[20]);
void Estudiantes2(char opcion[20]);
void Estudiantes3(char opcion[20]);
void Estudiantes4(char opcion[20]);
void Estudiantes5(char opcion[20]);
void Estudiantes6(char opcion[20]);
void Estudiantes7(char opcion[20]);
void Estudiantes8(char opcion[20]);

//***************************************************************************************************************************************
//												VARIABLES Y PROTOTIPOS PARA MENUS DE SEMANAS
//***************************************************************************************************************************************
float arroz=0.03,frijoles=0.03,leche=0.03,azucar=0.02,bebida=0.015, aceite=0.005 ;//Raciones
char val[200],opmenu;//para validar cantidad

struct lunes
{
	char alimento[200];
	char codigo[50];
}l[ali];
int contL,contL1,l1,l2,l3,l4,l5,l6,l7,l8,l9,totlunes1=0;//asistencia
float p1,p2,p3;//opcion 1 menu
float p4,p5,p6;//opcion 2 menu
float p7,p8;//opcion 3 menu

struct martes
{
	char alimento1[200];//capturar dia
	char codigo1[50];
}d[ali];
int contma, contma1,ma1,ma2,ma3,ma4,ma5,ma6,ma7,ma8,ma9,totmartes1=0;
float pd1,pd2,pd3;//opcion 1 menu
float pd4,pd5,pd6;//opcion 2 menu

struct miercoles
{
	char alimento2[200];//capturar dia
	char codigo2[50];
}ml[ali];
int contmi,contmi1,mi1,mi2,mi3,mi4,mi5,mi6,mi7,mi8,mi9,totmiercoles1=0;
float pm1,pm2,pm3,pm4,pm5,pm6;//opcion menu

struct jueves
{
	char alimentos3[200];
	char codigos3[50];
}jk[ali];
int contj,contj1,j1,j2,j3,j4,j5,j6,j7,j8,j9,totjueves1=0;
float pj1,pj2,pj3,pj4,pj5,pj6;//opcion menu

struct viernes
{
	char alimento4[200];//capturar dia
	char codigo4[50];
}v[ali];
int contV,contV1,v1,v2,v3,v4,v5,v6,v7,v8,v9,totviernes1=0;
float pv1,pv2,pv3,pv4,pv5,pv6,pv7;//opcion menu

void llenadodias();
void menusemana();
//Día lunes
void menulunes();
void ingresarlunes();
void eliminarlunes();
void asistencialunes();
void elejirmenu();
void opcion1();
void opcion2();
void opcion3();
//Día martes
void menumartes();
void ingresarmartes();
void eliminarmartes();
void asistenciamartes();
void elejirmenumartes();
void opcion12();
void opcion22();
//Día miercoles
void menumiercoles();
void ingresarmiercoles();
void eliminarmiercoles();
void asistenciamiercoles();
void elejirmenumiercoles();
void opcion13();
void opcion23();
//Día jueves
void menujueves();
void ingresarjueves();
void eliminarjueves();
void asistenciajueves();
void elejirmenujueves();
void opcion14();
void opcion24();
//Día viernes
void menuviernes();
void ingresarviernes();
void eliminarviernes();
void asistenciaviernes();
void elejirmenuviernes();
void opcion15();
void opcion25();

//***************************************************************************************************************************************
//												VARIABLES Y PROTOTIPOS PARA EL INVENTARIO
//***************************************************************************************************************************************
struct producto
{
	char nombre[140];
	char codigo[50];
	float dismi,tot,agg,cant;

}pro[p];
int m,c,k;
char cantidadC[200], precioC[200];
void iniciarproducto();
void menuproductos();
void ingresarproducto();
void eliminarproducto();
void sumcanproducto();
void rescanproducto();
void mostrarproducto();

//***************************************************************************************************************************************
//											VARIABLES Y PROTOTIPOS DE REPORTES
//**************************************************************************************************************************************
void menuReportes();
void reporteComiteMadre();
void reporteSecciones();
//Funciones que son llamadas al menu reporteSecciones
void reporteseccion();
void reporteseccion1();
void reporteseccion2();
void reporteseccion3();
void reporteseccion4();
void reporteseccion5();
//fin llamado
void reporteInventario();
void reporteMenu();

//**************************************************************************************************************************************
// funcion principal main()
//**************************************************************************************************************************************
void main()
{
	setlocale(LC_CTYPE, "Spanish");
	iniciarU();//registro lleno de usuarios
	llenado();//registros de estudiantes
	llenado1();//registros de estudiantes
	llenado2();//registros de estudiantes
	llenado3();//registros de estudiantes
	llenado4();//registros de estudiantes
	llenado5();//registros de estudiantes
	llenadodias();
	iniciarproducto();//registro de productos
	color(255,9);
	logo();
	login();//Llama función login
  
}//Fin main()

void logo()
{
	
	color(255,9);
	system("cls");
	
	int log;
	color(1,255);//color para el cuadro dibujado
	for(log=0;log<80;log++)
	{
		
		gotoxy(log,0);
		printf(" ");
		gotoxy(log,1);
		printf(" ");
		gotoxy(log,2);
		printf(" ");
	}//Fin for log
	//imagen del tenedor
	gotoxy(1,1);
	printf("   PROGRAMA DE ALIMENTACIÓN Y SALUD ESCOLAR (PASE),C/E ZARAGOZA, BIENVENIDOS   ");
	color(0,0);

	for(log=6;log<=18;log++)
	{
		gotoxy(26,log);
		printf("**  ***  **");
	}
	gotoxy(27,log);
	printf("*********");
	gotoxy(28,log+1);
	printf("*******");
	for(log=21;log<=35;log++)
	{
		gotoxy(29,log);
		printf("*****");
	}
	//primera linea
	for(log=6;log<=18;log++)
	{
		color(255,9);
		gotoxy(28,log);
		printf("  ");
	
	}
	//segunda linea
	for(log=6;log<=18;log++)
	{
		color(255,9);
		gotoxy(33,log);
		printf("  ");
		
	}
	//imagen del cuchillo
	color(0,0);
	gotoxy(50,6);
	printf("*");
	gotoxy(49,7);
	printf("**");
	gotoxy(48,8);
	printf("***");
	gotoxy(47,9);
	printf("****");
	gotoxy(46,10);
	printf("*****");
	gotoxy(45,11);
	printf("******");
	gotoxy(44,12);
	printf("*******");
	gotoxy(43,13);
	printf("********");
	log=14;
	gotoxy(42,log);
	printf("*********");
	gotoxy(42,log+1);
	printf("*********");
	gotoxy(42,log+2);
	printf("*********");
	gotoxy(42,log+3);
	printf("*********");
	gotoxy(42,log+4);
	printf("*********");
	gotoxy(42,log+5);
	printf("*********");
	gotoxy(42,log+6);
	printf("*********");
	gotoxy(42,log+7);
	printf("*********");
	gotoxy(42,log+8);
	printf("*********");

	//Inesertar manualmente
	gotoxy(43,23);
	printf("********");
	gotoxy(44,24);
	printf("*******");

	log = 25;
	gotoxy(46,log);
	printf("*****");
	gotoxy(46,log+1);
	printf("*****");
	gotoxy(46,log+2);
	printf("*****");
	gotoxy(46,log+3);
	printf("*****");
	gotoxy(46,log+4);
	printf("*****");
	gotoxy(46,log+5);
	printf("*****");
	gotoxy(46,log+6);
	printf("*****");
	gotoxy(46,log+7);
	printf("*****");
	gotoxy(46,log+8);
	printf("*****");
	gotoxy(46,log+9);
	printf("*****");
	gotoxy(46,log+10);
	printf("*****");
	gotoxy(0,36);
	color(5,255);
	printf("\n                                                                               ");
	printf("\t\t\tCOPYRIGHT: UNIVERSIDAD DE EL SALVADOR (UES) 2017\t");
	printf("\t\t\t\t\t\t\t\t\t\t\t\n\n");
	system("pause>null");
}//Fin logo

//****************************************************************************************************************************************
//													INICIO DE SESSION DEL USUARIO
//****************************************************************************************************************************************

void login()
{

	bool ingresar = false,valida=false,va=false; //variable booleana
	int i = 0,ca;	//Posicion del caracter leido
	char caracter; // Guarda el caracter mediante  getch 
	int long_a;
		//Inicio de un do while cuando se equivoca el usuario
		do {
			color(255,9);
			system("cls");
			encabezadoinicio(); //funcion que muestra en encabezado
			color(3,3);
			sysbox(8,0,28,79,3); // Dibuja recuadro principal
			gotoxy(1,8);	
			gotoxy(1,9);
			color(4,255);
			printf("\t\t\t\t\t\t\t\t\t       ");
			gotoxy(1,10);
			printf("\t\t\t       INICIO DE SESIÓN\t\t\t\t       ");
			gotoxy(1,11);
			printf("\t\t\t\t\t\t\t\t\t       ");			
			copyright(1,0); //Funcion que muestra los derechos reservados
			color(255,3);
			gotoxy(10,16);
			printf("     USUARIO: ");
			gotoxy(10,19);
			printf("  CONTRASEÑA: ");
				//Crear las cajitas donde escribe el usuario
				for(int k=24;k<50;k++)
				{
					gotoxy(k,16);
					color(7,0);
					printf(" ");
					gotoxy(k,19);
					printf(" ");
				}//Fin for k
				
				do
				{
					gotoxy(24,16);
					fflush(stdin);
					color(7,0);
					gets(usuario);
					if(strlen(usuario) ==0)
					{
						color(255,12);
						gotoxy(10,16);
						printf(" *   USUARIO: ");
						va = true;
											
					}
					else
					{
						color(255,2);
						gotoxy(10,16);
						printf("     USUARIO: ");
						va = false;
					}
				}while(va);//Fin validacion usuario
				
				
				//procedimiento para capturar la contraseña y mostrar un *
			 do
			 {
				i = 0;	//Posicion del caracter leido
				gotoxy(24,19);
				caracter = getch();

				while (i < F  && caracter != 13) //Tecle enter
				{		
					if (caracter != 8) 
					{ //espacio
						password[i] = caracter;
						i++;
						color(7,0);
						printf("*");
					} 
					else if(i>0)
					{
						long_a = strlen(password);
							if(long_a>0)
							{
							printf("\b \b");
							password[long_a] = '\0';
							i--;
							}//Fin if
					}//Fin if
					caracter = getch();
				}// fin while enter
					password[i] = '\0';
		
				if(strlen(password)==0)
				{
					gotoxy(10,19);
					color(255,12);
					printf("* CONTRASEÑA: ");
					color(255,10);
					gotoxy(24,18);	
					valida  = false;
				}
				else
				{
					gotoxy(10,19);
					color(255,2);
					printf("  CONTRASEÑA: ");
					valida = true;
				}//Fin if

			 }while(!valida);//Fin do while
			
				int ko = 0;
				//Recorrer con estructura while para ver si existe el usuario
				while(ko<contU)
				{
					//Comparar los datos
					if (strcmp(strupr(usuario), strupr(user[ko])) == 0 && strcmp(password, pass[ko]) == 0) {

						ingresar=true;
						break;
					} 
					else
					{			
						ingresar = false;
					
					}//Fin if
					ko++;

				}//Fin while ko

					if(!ingresar)
					{
						gotoxy(12,21);
						color(5,255);
						printf("     ¡Error!. Usuario y/o Contraseña Incorrecta        ");
						Sleep(2800);
					}//Fin if
		
 
	} while (!ingresar);//Fin do while

		if(ingresar)
		{
			
			cargando(); //llama funcion cargando
			//principal();
		
		}//Fin if
		printf("\n");

}//Fin login


void iniciarU()
{ 
	contU = 0;
	contC = 0;
	//Un usuario registrado
	//char *cadenau = "ADMON",*cadenap = "12345";
	strcpy(codigoU[contU],"U117");
	strcpy(user[contU],"darwin");
	strcpy(pass[contU],"12345");
	contU++;
	contC++;
	//char *cadenau1 = "DARWIN",*cadenap1="123";
	strcpy(codigoU[contU],"C217");
	strcpy(user[contU],"alfonso");
	strcpy(pass[contU],"2017");
	contU++;
	contC++;


	//contadores madres
	contM=0;
	//Para la primera Madre
	strcpy(madre[contM].nombreM,"MARIA ");
	strcpy(madre[contM].apellidoM,"HERNADEZ");
	strcpy(madre[contM].duiM,"01415689-0");
	strcpy(madre[contM].telM,"2023-1425");
	strcpy(madre[contM].dirM,"Colonia san julian");
	strcpy(madre[contM].comite,"NO");
	strcpy(madre[contM].nombreCM,strcat(madre[contM].nombreM,madre[contM].apellidoM));
	contM++;
	//*********************************
	strcpy(madre[contM].nombreM,"KARLA ");
	strcpy(madre[contM].apellidoM,"ORTIZ");
	strcpy(madre[contM].duiM,"01415689-4");
	strcpy(madre[contM].telM,"2023-2224");
	strcpy(madre[contM].dirM,"Canton las brisas");
	strcpy(madre[contM].comite,"NO");
	strcpy(madre[contM].nombreCM,strcat(madre[contM].nombreM,madre[contM].apellidoM));
	contM++;	
}



void copyright(int cond,int contar)
{
			int c,z;
			if(cond == 1)
			{
				c= 28;
			
			}//end if

			if(cond ==2)
			{
				c= 26;
			
			}//Fin if

			if(cond == 3)
			{
				if(contU>=5  || contM>=5)
				{
					c=contar;
				
				}
				else
				{
				c=26;
				}
			}//Fin cond 3

			color(1,255);
			gotoxy(1,c);
			printf(" Autores: ");
		/*	color(255,0);
			gotoxy(8,c+2);
			printf("%c Zuleyma Yamileth Aquino Rodriguez",1);
			gotoxy(8,c+3);
			printf("%c José Saul Hernandez Vasquez",2);
			gotoxy(8,c+4);
			printf("%c José Gerardo Zometa Díaz",1);
			gotoxy(8,c+5);
			printf("%c Kevin Alberto Lopez Escobar",2);
			gotoxy(8,c+6);*/
			printf("%c Darwin Alfonso Flores Colindres",1);
			gotoxy(0,c+7);
			color(5,255);
			printf("\n                                                                               ");
			printf("\t\t\t\t  Copyright: Darwin  2023 \t\t\t\t");
			printf("\t\t\t\t\t\t\t\t\t\t\t\n\n");


}//Fin copy


void encabezado()
{
	int i;
	
	gotoxy(0,0);
	color(0,0);
	printf("                                                                                "); 
	color(5,255);
	printf("\t\t\t                                           \t\t\t");
	printf("\t\t\t\t                        \t\t");
	printf("                                                                                ");
	color(0,0);
	printf("                                                                                ");
	gotoxy(30,5);
	color(255,1);
	gotoxy(0,2);
	color(5,255);
	printf("\t\t\t   CENTRO ESCOLAR ZARAGOZA");

	//Mostrar fecha y hora de manera local
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
	strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
	gotoxy(60,6);
	color(255,0);
    printf("%s\n",output);
	color(255,0);
	
}//Fin encabezado


void encabezadoinicio()
{
	int i;
	
	gotoxy(0,0);
	color(0,0);
	printf("                                                                                "); 
	color(5,255);
	printf("\t\t\t                                           \t\t\t");
	printf("\t\t\t\t                        \t\t");
	printf("                                                                                ");
	color(0,0);
	printf("                                                                                ");
	gotoxy(30,5);
	color(255,0);
	printf("\n\t\t\t\t SISTEMA PASE\n");
	gotoxy(26,2);
	color(5,255);
	printf(" CENTRO ESCOLAR ZARAGOZA");

	//Mostrar fecha y hora de manera local
	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
	strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
	gotoxy(60,6);
	color(255,0);
    printf("%s\n",output);
	color(255,9);
	
}//Fin encabezado


void cargando()
{
	system("ClS");
	color(3,3);
	gotoxy(1,2);
	printf("                                                                              ");
	gotoxy(1,3);
	printf("                                                                              ");
	gotoxy(1,4);
	printf("                                                                              ");
	color(0,10);
	
	int i;
	gotoxy(1,6);
	printf("      ********************************************************************    \n");
	gotoxy(1,7);
	printf("      |          ~       ^^          ~    ___________________            |    \n");
	gotoxy(1,8);
	printf("      |      ^     CENTRO ESCOLAR     ^   |                  |___________|    \n");
	gotoxy(1,9);				
	printf("      |     ^        %cZARAGOZA%c        ^|    AUTORES:      |COPYRIGHT: |    \n",34,34);
	gotoxy(1,10);
	printf("      |    ^   ************************ ^ |  DARWIN FLORES   |           |    \n");
	gotoxy(1,11);
	printf("      |    ^  PROGRAMA DE ALIMENTACION  ^ | DARWIN FLORES    |UNIVERSIDAD|    \n");
	gotoxy(1,12);
	printf("      |    ^   Y SALUD ESCOLAR  (PASE)  ^ | DARWIN FLORES    |     DE    |    \n");
	gotoxy(1,13);
	printf("      |    ^   ************************ ^ | DARWIN FLORES    |     EL    |    \n");
	gotoxy(1,14);
	printf("      |  _____________ DAR _______________| DARWIN FLORES    |  SALVADOR |    \n");
	gotoxy(1,15);
	printf("      |  |  _    _     2023  _    _    _  |__________________|___________|    \n");
	gotoxy(1,16);
	printf("      |  | | |  | |  _____  | |  | |  | | |       _____      |   |  _ |  |    \n");
	gotoxy(1,17);
	printf("      |  | | |  | |  |%c|%c|  | |  | |  | | |       |%c|%c|      |   |  | |  |    \n",1,1,1,1);
	gotoxy(1,18);
	printf("      ********************************************************************    \n");
	gotoxy(1,24);
	color(255,3);
	printf("______________________________________________________________________________");
	gotoxy(23,26);
	color(255,1);
	//gurdar en variables los codigos ascii
	//para crear las cajitas
	int x,m=1;
	char h=201;
	char j=186;
	char k=200;
	char l=196;
	char v=187;
	char b=188;
	color(3,3);

	 gotoxy (23,26);printf("%c",h);
	 gotoxy (1,27);printf("%c",j);
	 gotoxy (23,28);printf("%c",k);

	 for(x=0;x<77;x++){
	  gotoxy (m,26);printf("%c",l);
	  gotoxy (m,28);printf("%c",l);
	  m++;
	 }
	 gotoxy (m,26);printf("%c",v);
	 gotoxy (m,27);printf("%c",j);
	 gotoxy (m,28);printf("%c",j);
	 gotoxy (m,28);printf("%c",b);
	/////////////////////////////////////////////////////////////////
	 gotoxy (29,21);printf("%c",h);
	 gotoxy (29,22);printf("%c",j);
	 gotoxy (29,23);printf("%c",k);
	 m=30;
	 for(x=0;x<15;x++){
	  gotoxy (m,21);printf("%c",l);
	  gotoxy (m,23);printf("%c",l);
	  m++;
	 }
	 gotoxy (45,21);printf("%c",v);
	 gotoxy (45,22);printf("%c",j);
	 gotoxy (45,23);printf("%c",b);
	 lodbar();
	 principal();//Funcion principal menú


}//Fin cargando


void lodbar()
{
	int i, n=1,j,m;
	char z=178;
	double porcentaje={1.35};
	float sum=0;
	srand (time (NULL));
	m=rand()%2;
	color(255,3);
	gotoxy (31,22);
	printf("Cargando...");
    int con=9;
	 for(i=1;i<=76;i++,con+1){
	  n++;

			int h=0;
			while(h<12)
			{
				
			color(3,con-1);
			gotoxy(31+(h+1),3);
			printf("%c",pase[h]);
			h++;
			}

			if(con==13)
			{
				con=9;
			}
			con++;
  
	  color(2,2);
	  gotoxy (n,27); printf("%c",z);
	  Sleep(20);
	  color(255,3);
	  gotoxy (40,22);printf(".    ");
	  Sleep(25);
	  gotoxy (40,22);printf("..");
	  Sleep(25);
	  gotoxy (40,22);printf("...");
	  Sleep(25);
	  gotoxy (40,22);printf("....");
	  Sleep(25);
	  gotoxy (40,22);printf(".....");

	  if(i>42)
	  {
		 color(0,con-2);
	  }
	  else
	  {
	  color(255,0);
	  }

	gotoxy (35,27);printf("%.2f%%",sum);
 
	  if(i==40)
	  {
			if(m==0)
			{
				for(j=0;j<=10;j++)
				{
					 gotoxy (40,22);printf(".    ");
					 gotoxy (40,22);printf("..");
					 gotoxy (40,22);printf("...");
					 Sleep(25);
					 gotoxy (40,22);printf("...");
					 Sleep(25);
					 gotoxy (40,22);printf(".....");
				}
		    }
	  }
	sum+=float(porcentaje);
 }
	gotoxy (35,27);printf("100.00%%");
	gotoxy(26,30);
	color(255,3);
	printf("Excelente. Ingresaste");
	Sleep(2000);
}



void principal()
{
	char resp,op,dis;
	do
	{
		do
		{
		color(255,9);
		system("CLS");
		color(255,9);
		color(3,3);
		sysbox(8,0,40,79,2); // Dibuja recuadro principal

////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
		color(0,0);
		 ////marco verde limon////
		for(dis=1;dis<79;dis++)
		{
			gotoxy(dis,9);
			printf(" ");
			gotoxy(dis,10);
			printf(" ");
			gotoxy(dis,11);
			printf(" ");
			gotoxy(dis,12);
			printf(" ");
			gotoxy(dis,13);
			printf(" ");
			gotoxy(dis,14);
			printf(" ");
		}
		gotoxy(6,12);
		color(255,0);
		gotoxy(6,11);
		printf("                ");
		gotoxy(6,13);
		printf("                ");
		gotoxy(6,12);
		printf(" %cSISTEMA PASE%c ",124,124);
		////cuadrado uno////
		for(dis=50;dis<57;dis++)//inicio for dis
		{
			gotoxy(dis,10);
			color(3,0);
			printf(" ");
			gotoxy(dis,11);
			color(3,0);
			printf(" ");
			gotoxy(dis,12);
			color(3,0);
			printf(" ");
			gotoxy(dis,13);
			color(3,0);
			printf(" ");
		}//fin for dis
			////cuadrado 3////
		for(dis=67;dis<74;dis++)//inicio for dis
		{
			gotoxy(dis,12);
			color(3,0);
			printf(" ");
			gotoxy(dis,13);
			color(3,0);
			printf(" ");
		}//fin for dis

		//forma central/////
		for(dis=57;dis<74;dis++)//inicio for dis
		{
			gotoxy(dis,10);
			color(15,0);
			printf(" ");
			gotoxy(dis,11);
			color(15,0);
			printf(" ");
		}//fin for dis

		for(dis=57;dis<67;dis++)//inicio for dis
		{
			gotoxy(dis,12);
			color(15,0);
			printf(" ");
			gotoxy(dis,13);
			color(15,0);
			printf(" ");
		}//fin for dis
		//lineas centrales
		//texto
		color(5,255);
		for(dis=1;dis<26;dis++)//inicio for dis
		{
			gotoxy(dis,15);
			printf(" ");
			gotoxy(dis,16);
			printf(" ");
			gotoxy(dis,17);
			printf(" ");
		}//fin for dis
		gotoxy(7,16);
		printf("MENU PRINCIPAL");
		for(dis=26;dis<79;dis++)//inicio for dis
		{
			gotoxy(dis,15);
			color(3,0);
			printf(" ");
			gotoxy(dis,16);
			color(3,0);
			printf(" ");
			gotoxy(dis,17);
			color(3,0);
			printf(" ");
		}//fin for dis

		//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,43);
			printf(" ");
			gotoxy(dis,44);
			printf(" ");
			gotoxy(dis,45);
			printf(" ");
		}
		gotoxy(30,44);
		printf("Copyright Darwin 2023");
		encabezado();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		color(3,15);
		gotoxy(8,19);
		printf("                       ");
		gotoxy(8,20);
		printf(" %c 1. Usuarios         ",4);
		gotoxy(8,21);
		printf("                       ");
		gotoxy(8,23);
		printf("                       ");
		gotoxy(8,24);
		printf(" %c 2. Comite de Madres ",4);
		gotoxy(8,25);
		printf("                       ");
		gotoxy(8,27);
		printf("                       ");
		gotoxy(8,28);
		printf(" %c 3. Seciones         ",4);
		gotoxy(8,29);
		printf("                       ");
		gotoxy(49,19);
		printf("                      ");
		gotoxy(49,20);
		printf(" %c 4. Menus de comida ",4);
		gotoxy(49,21);
		printf("                      ");
		gotoxy(49,23);
		printf("                      ");
		gotoxy(49,24);
		printf(" %c 5. Inventario      ",4);
		gotoxy(49,25);
		printf("                      ");
		gotoxy(49,27); 
		printf("                      ");
		gotoxy(49,28);
		printf(" %c 6. Reportes        ",4);
		gotoxy(49,29);
		printf("                      ");
		gotoxy(8,34);
		color(3,15);
		printf("            ");
		gotoxy(8,35);
		printf(" %c 7. Salir ",11);
		gotoxy(8,36);
		printf("            ");
		color(255,3);
		gotoxy(30,34);
		printf("%c Elija una opcion: ",16);
		for(int l=30;l<48;l++)
		{
			gotoxy(l,36);
			color(7,0);
			printf(" ");
		}
		gotoxy(39,36);
		op=getch();
			switch(op)
			{
			case '1':
			
				manttouser();
				break;
					

			case '2':
				manttoMadre();

				break;
			case '3':
				menusecciones();
				break;
			case '4':
				 menusemana();
				break;
			case '5':
				menuproductos();
				break;
			case '6':
				menuReportes();
				break;
			case '7':

				break;
			default:
				color(255,4);
				gotoxy(39,35);
				printf("%c",25);
				gotoxy(37,36);
				printf("%c",26);
				gotoxy(41,36);
				printf("%c",27);
				gotoxy(39,37);
				printf("%c",24);
				gotoxy(30,38);			
				printf("%c Opcion incorrecta.",16);
				Sleep(500);
			}//Fin switch op
		}while(op !='7');//Fin do while op
				gotoxy(48,38);
				color(255,4);
				printf(" Esta seguro  de Salir? (S/N):");
				resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	login();//Llama la funcion login


}

//****************************************************************************************************************************************
//													MANTENIMIENTO USUARIO
//****************************************************************************************************************************************
void manttouser()
{
	char op,dis,resp;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(0,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,11);
			color(255,0);
			gotoxy(6,10);
			printf("                ");
			gotoxy(6,12);
			printf("                ");
			gotoxy(6,11);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
			
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(5,255);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				
				printf(" ");
			}//fin for dis
			color(5,255);
			gotoxy(4,16);
			printf("     USUARIOS");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("copyright: UES 2017");
			encabezado();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			color(10,9);
			gotoxy(10,22);
			color(255,3);
			printf("%c 1. Registrar Usuario",5);
			gotoxy(10,25);
			printf("%c 2. Modificar",5);
			gotoxy(40,22);
			printf("%c 3. Eliminar",5);
			gotoxy(40,25);
			printf("%c 4. Mostrar Registros",5);
			gotoxy(10,32);
			color(3,15);
			printf("             ");
			gotoxy(10,33);
			printf("%c 5. Regresar",27);
			gotoxy(10,34);
			printf("             ");
			color(255,3);
			gotoxy(30,32);
			printf("%cElija una opcion: ",16);
			for(dis=30;dis<48;dis++)
			{
				color(7,0);
				gotoxy(dis,34);
				printf(" ");
			}
			gotoxy(39,34);
			op=getch();//lee op

			switch(op)
			{
				case '1':
					funcionesUser("add");
				
					break;
				
				case '2':
						funcionesUser("update");
					break;
				case '3':
					funcionesUser("delete");

					break;

				case '4':
					funcionesUser("ver");

					break;
				case '5':
			

					break;
				default:
					color(255,4);
					gotoxy(39,33);
					printf("%c",25);
					gotoxy(37,34);
					printf("%c",26);
					gotoxy(41,34);
					printf("%c",27);
					gotoxy(39,35);
					printf("%c",24);
					gotoxy(30,36);			
					printf("%c Opcion incorrecta.",16);
					Sleep(500);
			}//Fin switch op
		}while(op !='5');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	principal(); //regresa al menu principal
	
}//Fin mantto users


void funcionesUser(char opcion[20])
{
	bool ingresar = false,va=false,repe=false,searchv=false,valida=false; //variables booleanas
	int i = 0;	//Posicion del caracter leido
	char caracter,contra[F],search[200]; // Guarda el caracter mediante  getch 
	int long_a,aumentar;
	char nombreU[200];
	char res,dis;
	int cont;
	//para asignar la fecha(año) al codigo generado del usuario
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);
	//opcione de agregar datos
	if(opcion =="add")
	{
		do
		{
		color(255,3);
		system("CLS");
		color(255,3);
		color(3,3);
		sysbox(8,0,26,79,2); // Dibuja recuadro principal
		//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,29);
			printf(" ");
			gotoxy(dis,30);
			printf(" ");
			gotoxy(dis,31);
			printf(" ");
		}
		gotoxy(30,30);
		printf("Copyright UES 2017");
		encabezado();
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("    REGISTRO DATOS DE USUARIO    ");
		color(255,3);
		gotoxy(10,13);
		printf("     USUARIO: ");
		gotoxy(10,16);
		printf("  CONTRASEÑA: ");
			//Dibuja las cajitas donde digita el usuario
		for(int k=24;k<60;k++)
		{
			gotoxy(k,13);
			color(7,0);
			printf(" ");
			gotoxy(k,16);
			printf(" ");
		}//Fin for k
				do
				{
					gotoxy(24,13);
					fflush(stdin);
					color(7,0);
					gets(nombreU);

					if(strlen(nombreU)<3)
					{
						color(255,12);
						gotoxy(10,13);
						printf(" *   USUARIO: ");
						gotoxy(24,13);
						color(7,0);
						printf("                         ");
						va = false;
					
					}else
					{
						color(255,2);
						gotoxy(10,13);
						printf("     USUARIO: ");
						va=true;
					
					}//Fin if

				}while(!va);//Fin do while va

			

				strupr(nombreU);//convierte a mayuscula

					//Generar  Coidgo Usuario
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contC+1,anio);//concatena variables

				do
				{
					i = 0;	//Posicion del caracter leido
					gotoxy(24,16);
					caracter = getch();
					while (i < F  && caracter != 13)
					{
				
						if (caracter != 8) //Espacio
						{
							contra[i] = caracter;
							i++;
							color(7,0);
							printf("*");
						}
						else if(i>0) 
						{
							long_a = strlen(contra);
								if(long_a>0)
								{
								printf("\b \b");
								i--;
								}//Fin if long
						}//Fin if caracter

						caracter = getch();
					}//Fin while enter
			
					contra[i]='\0';
					
					if(strlen(contra)<3)
					{
						gotoxy(10,16);
						color(255,12);
						printf("* CONTRASEÑA: ");
						gotoxy(24,16);
						color(7,0);
						printf("                         ");	
						valida  = false;
				
					}
					else
					{
						 valida = true;
					}//Fin if

				}while(!valida);//Fin do while
				
				int ko;
				//Verifica si ya existe un usuario
				for(ko=0;ko<contU;ko++)
				{
					if (strcmp(strupr(nombreU),strupr(user[ko])) == 0)
					{
						repe=false;
						
						break;
			
					} 
					else 
					{
						repe = true;
					}//Fin if coomparacion
				
				}//Fin for ko
					color(255,2);
					gotoxy(10,16);
					printf("  CONTRASEÑA: ");
					//Muestra el mensaje respectivo
				if(repe)
				{
					
					if(strlen(contra)<3)
					{
						strcpy(codigoU[contU],codigo);
						strcpy(user[contU],nombreU);
						strcpy(pass[contU],"pase");
					
					}
					else
					{
						strcpy(codigoU[contU],codigo);
						strcpy(user[contU],nombreU);
						strcpy(pass[contU],contra);
					}



					gotoxy(15,18);
					color(3,255);
					printf("\t\t\t\t\t\t\t");
					gotoxy(15,19);
					printf("\t\tUsuario agregado satisfactoriamente  \t");
					gotoxy(15,20);
					printf("\t\t\t\t\t\t\t");
					contU++;
					contC++;
				
				}else
				{

					gotoxy(15,18);
					color(5,255);
					printf("\t\t\t\t\t\t\t");
					gotoxy(15,19);
					printf("\t\t¡Error!.Usuario ya existe agregado.  \t");
					gotoxy(15,20);
					printf("\t\t\t\t\t\t\t");
				
					
				}//Fin if
				color(255,4);
				gotoxy(30,24);
			printf("Deseas registrar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
		
	}//Fin if opcion add.


	//Condicion ver usuarios
	if(opcion == "ver")
	{
		do
		{
		color(255,9);
		system("CLS");
		color(255,9);
		color(4,255);
		gotoxy(1,9);
		printf("                                                                              \n");
		gotoxy(1,10);
		printf("%5s%10s\t%-30s%-25s", "N°","CODIGO", "USUARIO", "CONTRASEÑA");
		gotoxy(1,11);
		printf("                                                                              \n");
		color(255,1);
	

		for (i = 0,cont=12;i < contU; i++,cont=cont+2) 
		{
			
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d%9s\t\t%-30s%-25s\n",i+1,codigoU[i],user[i],pass[i]);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
	
		gotoxy(1,cont);
		color(3,3);
		printf("------------------------------------------------------------------------------\n");

		if(i>=5)
		{
			aumentar=cont+5;
		}else
		{
			aumentar = 27;
		}
		color(3,3);
		sysbox(8,0,aumentar,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar+4);
			printf(" ");
			gotoxy(dis,aumentar+5);
			printf(" ");
			gotoxy(dis,aumentar+6);
			printf(" ");
		}
		gotoxy(30,aumentar+5);
		printf("Copyright UES 2017");
		//fin barra horizontal
		encabezado();
		gotoxy(14,8);
		color(10,0);
		printf("      LISTADO DE USUARIOS REGISTRADOS     ");
		color(255,4);
		//barra horizontal de color negro enla parte inferior
		gotoxy(60,cont+2);
		printf("%cRegresar (S/N): ",27);
		res = getch();
		}while(toupper(res)!='S');
	
	
	}//Fin if condicion ver
	//creando opcion de modificar

	if(opcion == "update")
	{
		do
		{
		color(255,9);
		system("CLS");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,28,79,2); // Dibuja recuadro principal
		//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
			gotoxy(dis,33);
			printf(" ");
		}
		gotoxy(30,32);
		printf("Copyright UES 2017");
		//Fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("    MODIFICAR DATOS USUARIO    ");
		for(int k=38;k<70;k++)
		{
			gotoxy(k,11);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,11);
		printf("     Codigo usuario a Modificar: ");
		do{               
		gotoxy(39,11);
		color(7,0);
		fflush(stdin);
		gets(search);

			if(strlen(search)<1)
			{
				color(255,12);
				gotoxy(6,11);
				printf("  *  Codigo usuario a Modificar: ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("     Codigo usuario a Modificar: ");
				searchv=true;
				
			}//Fin if search longitud
		}while(!searchv);
		bool existe=false;
		int b,posicion;
				//Verifica si ya existe un usuario
				
				for(b=1;b<contU;b++)
				{
					if ((strcmp(strupr(search),strupr(codigoU[b])) == 0))
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{

					color(3,255);
					gotoxy(24,13);
					printf("    Usuario Encontrado. Modifique   ");
					color(255,3);
					gotoxy(10,15);
					printf("  N. USUARIO: ");
					gotoxy(7,18);
					printf("  N. CONTRASEÑA: ");
					//Dibuja las cajitas donde digita el usuario
					for(int k=24;k<60;k++)
					{
						gotoxy(k,15);
						color(7,0);
						printf(" ");
						gotoxy(k,18);
						printf(" ");
					}//Fin for k

						do
						{
							gotoxy(24,15);
							fflush(stdin);
							color(7,0);
							gets(nombreU);

							if(strlen(nombreU)<3)
							{
								color(255,12);
								gotoxy(10,15);
								printf("* N. USUARIO: ");
								va = false;
							}else
							{
								color(255,2);
								gotoxy(10,15);
								printf("  N. USUARIO: ");
								va=true;
							}//Fin if
						}while(!va);//Fin do while va

						strupr(nombreU);//convierte a mayuscula
						int j=0;
						char nom,codigo[50];
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
								}
						j++;				
						}
						sprintf(codigo,"%c%d%s",nom,posicion+1,anio);//concatena variables

						do
						{
							i = 0;	//Posicion del caracter leido
							gotoxy(24,18);
							caracter = getch();

						while (i < F  && caracter != 13)
						{
				
							if (caracter != 8) //Espacio
							{
								contra[i] = caracter;
								i++;
								color(7,0);
								printf("*");
							}
							else if(i>0) 
							{
								long_a = strlen(contra);
									if(long_a>0)
									{
									printf("\b \b");
									contra[long_a] = '\0';
									i--;
									}//Fin if long
							}//Fin if caracter

							caracter = getch();
					}//Fin while enter
					
					contra[i]='\0';
					if(strlen(contra)==0)
					{
						gotoxy(7,18);
						color(255,12);
						printf("* N. CONTRASEÑA: ");
						valida  = false;
				
					}
					else
					{
						 valida = true;
					}//Fin if

				}while(!valida);//Fin do while
				
				int ko;
				//Verifica si ya existe un usuario
				for(ko=0;ko<contU;ko++)
				{
					if(ko==posicion)
					{
						
					}else{
					if (strcmp(strupr(nombreU),strupr(user[ko])) == 0)
					{
						repe=false;
						
						break;
			
					} 
					else 
					{
						repe = true;
					}//Fin if coomparacion
					}//End if comparar datos repetidos en comparacion
				
				}//Fin for ko
					color(255,2);
					gotoxy(7,18);
					printf("  N. CONTRASEÑA: ");
					//Muestra el mensaje respectivo
				if(repe)
				{
					if(strlen(contra)==0)
					{
						strcpy(user[posicion],nombreU);
						strcpy(pass[posicion],pass[posicion]);
					}
					else
					{
						strcpy(user[posicion],nombreU);
						strcpy(pass[posicion],contra);
						strcpy(codigoU[posicion],codigo);
					}//Fin if contra
					
					color(4,255);
					gotoxy(14,21);
					printf("     ¡Excelente!.Usuario Modificado con exito     ");
				
				}
				else
				{

					color(5,255);
					gotoxy(14,21);
					printf("        ¡Error!.Ya existe otro Usuario.           ");	
				}//Fin if repe

					
				}
				else
				{
					gotoxy(16,13);
					color(5,255);
					printf("                                           ");
					gotoxy(16,14);
					printf("     ¡Error!.Usuario no encontrado.        ");
					gotoxy(16,15);                                      
					printf("                                           ");
				}//End if existe

			color(255,4);
			gotoxy(30,25);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//END OPCION UPDATE



	if(opcion == "delete")
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,28,79,2); // Dibuja recuadro principal
			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,31);
				printf(" ");
				gotoxy(dis,32);
				printf(" ");
				gotoxy(dis,33);
				printf(" ");
			}
			gotoxy(30,32);
			printf("Copyright UES 2017");
			//Fin barra horizontal
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE USUARIO    ");
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(2,11);
			printf("     Codigo del usuario a Eliminar: ");
			do{               
				gotoxy(38,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<1)
				{
					color(255,12);
					gotoxy(2,11);
					printf("  *  Codigo del usuario a Eliminar: ");
				
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(2,11);
					printf("     Codigo del usuario a Eliminar: ");
					searchv=true;
				
				}//Fin if search longitud
			}while(!searchv);
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un usuario
				
			for(b=1;b<contU;b++)
			{
				if ((strcmp(strupr(search),strupr(codigoU[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
			
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(255,2);
				gotoxy(14,15);
				printf("       Desea eliminar este usuario? (S/N):  ");
				color(255,4);
				char r;
				r= getch();
				if(toupper(r)=='S')
				{
					for(int f = posicion;f<contU;f++)
					{
						strcpy(codigoU[f],codigoU[f+1]);
						strcpy(user[f],user[f+1]);
						strcpy(pass[f],pass[f+1]);
							
					}//Fin for F
					contU--;
					color(3,255);
					gotoxy(14,17);
					printf("     ¡Excelente!.Usuario Eliminado con Exito     ");
				}
				else
				{
					color(5,255);
					gotoxy(14,21);
					printf("     ¡Error!.Usuario no eliminado            ");
					
				}//Fin respuesta
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Usuario no encontrado.        ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//Fin if search
			color(255,4);
			gotoxy(30,25);
			printf("Deseas eliminar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//End opcion delete
	manttouser();//llamado de la funcion
}//En funcionesuser

//****************************************************************************************************************************************
//												MANTENIMIENTO COMITE DE MADRES
//****************************************************************************************************************************************
void manttoMadre()
{

	char op,resp,dis;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,36,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				color(15,0);
				printf(" ");
			}//fin for dis
	
			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(4,16);
			printf("COMITE DE MADRES");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,39);
				printf(" ");
				gotoxy(dis,40);
				printf(" ");
				gotoxy(dis,41);
				printf(" ");
			}
			gotoxy(30,40);
			printf("Copyright UES 2017");
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			gotoxy(10,21);
			color(255,3);
			printf("%c 1. Registrar Madres",4);
			gotoxy(10,24);
			printf("%c 2. Modificar",4);
			gotoxy(44,21);
			printf("%c 3. Eliminar",4);
			gotoxy(44,24);
			printf("%c 4. Mostrar Registros",4);
			gotoxy(10,30);
			color(3,15);
			printf("               ");
			gotoxy(10,31);
			printf(" %c 5. Regresar ",27);
			gotoxy(10,32);
			printf("               ");
			color(255,3);
			gotoxy(30,30);
			printf("%c Elija una opcion: ",16);
			for(int l=30;l<48;l++)
			{
				gotoxy(l,32);
				color(7,0);
				printf(" ");
			}
			gotoxy(39,32);
			op=getch();//leer op

			switch(op)
			{
				case '1':
					insertM();
					break;
				
				case '2':
					modificarM();
					break;
				case '3':
					eliminarM();
					break;

				case '4':
					mostrarM();
					break;
				case '5':
					break;
				default:
				color(255,4);
				gotoxy(39,31);
				printf("%c",25);
				gotoxy(37,32);
				printf("%c",26);
				gotoxy(41,32);
				printf("%c",27);
				gotoxy(39,32);
				printf("%c",24);
				gotoxy(30,34);			
				printf("%c Opcion incorrecta.",16);
				Sleep(500);
			}//Fin switch  op
		}while(op!='5');//Fin do while op
		gotoxy(58,34);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	principal(); //regresa al menu principal
	
}//Fin manttoMadre


void insertM()
{
	bool va=false,existe=false;//validar
	char res,dis;
	//Declraracion de variables para almacenar cada una de las partes del dui y 
	//Teléfono
	char dui1[100],dui2[100],tel1[100],tel2[100];	 
	//do de desea volver a intentar de nuevo
	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,28,79,2); // Dibuja recuadro principal
			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,32);
				printf(" ");
				gotoxy(dis,33);
				printf(" ");
				gotoxy(dis,34);
				printf(" ");
			}
			gotoxy(30,33);
			printf("Copyright UES 2017");
			//Fin barra horizontal
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRAR DATOS DE MADRE    ");

			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRE: ");
			gotoxy(10,13);
			printf("   APELLIDO: ");
			gotoxy(10,15);
			printf("        DUI: ");
			gotoxy(10,17);
			printf("   TELEFONO: ");
			gotoxy(10,19);
			printf("  DIRECCION: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,13);
				printf(" ");
				gotoxy(k,19);
				printf(" ");
				gotoxy(k,20);
				printf(" ");
			}//Fin for k

			//Cajita de DUI*******************

			gotoxy(24,15);
			printf("        ");
			gotoxy(32,15);
			color(255,9);
			printf("-");
			color(7,0);
			gotoxy(33,15);
			printf("  ");
			color(255,4);
			gotoxy(38,15);
			printf("Formato: 00000000-0");
			//************************
			//Cajita de telefono
			color(7,0);
			gotoxy(24,17);
			printf("    ");
			gotoxy(28,17);
			color(255,9);
			printf("-");
			color(7,0);
			gotoxy(29,17);
			printf("    ");
			color(255,4);
			gotoxy(38,17);
			printf("Formato: 0000-0000");
			//**********************************

			//validando nombre
			do
			{
				color(7,0);
				gotoxy(24,11);
				letras(madre[contM].nombreM,caracter);

				strupr(madre[contM].nombreM);
	
				  if(strlen(madre[contM].nombreM)<3)
				{
						va = true;
						color(255,12);
						gotoxy(10,11);
						printf("*    NOMBRE: ");
						gotoxy(24,11);
						color(7,0);
						printf("                        ");
				
				 }
				 else
				{
						va = false;
						color(255,2);
						gotoxy(10,11);
						printf("     NOMBRE: ");
				  }	
			}while(va);
			//validando Apellido
			do
			{
				color(7,0);
				gotoxy(24,13);
				letras(madre[contM].apellidoM,caracter);

				strupr(madre[contM].apellidoM);
				//Verifciar que sea solo letras
			
				   if(strlen(madre[contM].apellidoM)<5)
					{
						va = true;
						color(255,12);
						gotoxy(10,13);
						printf("*  APELLIDO: ");
						gotoxy(24,13);
						color(7,0);
						printf("                        ");
					}
				   else
				   {
						va = false;
						color(255,2);
						gotoxy(10,13);
						printf("   APELLIDO: ");
				   }
		
			}while(va);

			//Validando DUI
			do
			{
				color(7,0);
				gotoxy(24,15);
				numeros(dui1,caracter);
				if(strlen(dui1)<8 || strlen(dui1) > 8)
				{
					color(255,12);			
					gotoxy(10,15);
					printf("    *   DUI: ");
					color(7,0);
					gotoxy(24,15);
					printf("        ");
					gotoxy(32,15);
					color(255,9);
					printf("-");
					va = true;
				}else
				{
					color(255,2);			
					gotoxy(10,15);
					printf("        DUI: ");
					va = false;
					
					strcpy(madre[contM].duiM,dui1);
					strcat(madre[contM].duiM,"-");			
				}

			}while(va);
	
			do
			{
				color(7,0);
				gotoxy(33,15);
				numeros(dui2,caracter);
				if(strlen(dui2)<1 || strlen(dui2) > 1)
				{
					color(255,12);			
					gotoxy(10,15);
					printf("    *   DUI: ");
					gotoxy(32,15);
					color(255,9);
					printf("-");
					color(7,0);
					gotoxy(33,15);
					printf("  ");
					va = true;
				}else
				{
					color(255,2);			
					gotoxy(10,15);
					printf("        DUI: ");
					va = false;
					strcat(madre[contM].duiM,dui2);	
				}
		}while(va);
		
		//Validando Teléfono
		do
		{
			color(7,0);
			gotoxy(24,17);
			numeros(tel1,caracter);
			if(strlen(tel1)<4 || strlen(tel1) > 4)
			{
				color(255,12);			
				gotoxy(10,17);
				printf("*  TELEFONO: ");
				color(7,0);
				gotoxy(24,17);
				printf("    ");
				gotoxy(28,17);
				color(255,9);
				printf("-");
				va = true;
			}else
			{
				color(255,2);			
				gotoxy(10,17);
				printf("   TELEFONO: ");
				va = false;
				strcpy(madre[contM].telM,tel1);
				strcat(madre[contM].telM,"-");
			
			}
		}while(va);
		
		do
		{
			color(7,0);
			gotoxy(29,17);
			numeros(tel2,caracter);
			if(strlen(tel2)<4 || strlen(tel2) > 4)
			{
				color(255,12);			
				gotoxy(10,17);
				printf("*  TELEFONO: ");
				color(7,0);
				gotoxy(29,17);
				printf("    ");
				gotoxy(28,17);
				color(255,9);
				printf("-");
				va = true;
			}else
			{
				color(255,2);			
				gotoxy(10,17);
				printf("   TELEFONO: ");
				va = false;
				strcat(madre[contM].telM,tel2);
			}

		}while(va);
		//Validando direccion
		do
		{
			color(7,0);
			gotoxy(24,19);
			gets(madre[contM].dirM);
			if(strlen(madre[contM].dirM)<1 )
			{
				color(255,12);			
				gotoxy(10,19);
				printf("* DIRECCION: ");
			
				va = true;
			}else
			{
				color(255,2);			
				gotoxy(10,19);
				printf("  DIRECCION: ");
				va = false;
			}
		}while(va);

		char co;
		gotoxy(13,22);
		printf(" Desea agregar esta madre al comite? (S/N): ");
		co = getch();

		if(toupper(co)=='S')
		{
			strcpy(madre[contM].comite,"SI");
		
		}
		else
		{
			strcpy(madre[contM].comite,"NO");
		
		}

		int j;

		for(j=0;j<contM;j++)
		{
			if(strcmp(madre[contM].duiM,madre[j].duiM)==0)
			{
				existe=true;
				break;
			
			}
			else
			{
				existe = false;
			}
		
		}
		if(existe)
		{
			gotoxy(14,24);
			color(5,255);
			printf("¡Error!. Dui de madre ya existe.");
		
		}
		else
		{
			gotoxy(15,24);
			color(3,255);
			printf("¡Excelente!.Datos de Madre Agregados");
			strcpy(madre[contM].nombreCM,strcat(strcat(madre[contM].nombreM," "),madre[contM].apellidoM));
			contM++;
		}		
		color(255,4);
		gotoxy(30,26);
		printf(" Desea registrar  o intentar otra vez? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin fo while respuesta
}//Fin InsertM


void mostrarM()
{
	int aumentar,cont,i=0,conte=0;
	char res,dis;
	do
		{
		color(255,9);
		system("CLS");
		color(255,9);
		encabezado();
		color(4,255);
		gotoxy(1,9);
		printf("                                                                              \n");
		gotoxy(1,10);
		printf("%2s %s\t%-5s%14s%12s \t%14s\t", "N°","NOMBRE COMPLETO", "DUI", "TELEFONO","DIRECCION","COMITE");
		gotoxy(1,11);
		printf("                                                                              \n");
		color(255,1);
		cont=12;

		if(contM>0)
		{
			for (i = 0,cont=12;i < contM; i++,cont=cont+2) 
			{
				
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				if(strcmp(madre[i].comite,"SI")==0)
				{
				gotoxy(1,cont);
				color(255,2);
				conte++;
				printf("%2d %-20s%s%10s  %-29s%s  \n",i+1,madre[i].nombreCM,madre[i].duiM,madre[i].telM,madre[i].dirM,madre[i].comite);
				}else
				{
				
				gotoxy(1,cont);
				color(255,1);
				printf("%2d %-20s%s%10s  %-29s%s  \n",i+1,madre[i].nombreCM,madre[i].duiM,madre[i].telM,madre[i].dirM,madre[i].comite);
				}


				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
	
		}
		else
		{
			gotoxy(25,12);
			color(5,255);
			printf("NO hay datos Ingresados");
		
		}
		gotoxy(1,cont);
		color(3,3);
		printf("------------------------------------------------------------------------------\n");

		if(i>=5)
		{
			aumentar=cont+4;
		}else
		{
			aumentar = 26;
		}
		color(3,3);
		sysbox(8,0,aumentar,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar+4);
			printf(" ");
			gotoxy(dis,aumentar+5);
			printf(" ");
			gotoxy(dis,aumentar+6);
			printf(" ");
		}
		gotoxy(30,aumentar+5);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(14,8);
		color(10,9);
		printf("         LISTADO DE MADRES REGISTRADAS        ");
		color(255,2);
		gotoxy(2,cont+2);
		printf("%c Comité de madres lo forman: %d de %d Madres Registradas.",12,conte,contM);
		color(255,4);
		gotoxy(60,cont+2);
		printf("%cRegresar (S/N): ",27);
		res = getch();
		}while(toupper(res)!='S');
		manttoMadre();//llamado de la funcion
}//Fin mostrarM


void eliminarM()
{
	bool searchv=false;
	char res,dis,search[200];

	do
	{
		color(255,9);
		system("CLS");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,28,79,2); // Dibuja recuadro principal
		//incio barra horizontal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
			gotoxy(dis,33);
			printf(" ");
		}
		gotoxy(30,32);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("    ELIMINAR DATOS DE MADRE    ");
		for(int k=38;k<70;k++)
		{
			gotoxy(k,11);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,11);
		printf("          Dui Madre a Eliminar: ");
		do{               

			gotoxy(38,11);
			color(7,0);
			fflush(stdin);
			numerosdui(search,caracter);
			if(strlen(search)<8)
			{
				color(255,12);
				gotoxy(6,11);
				printf("   *      Dui Madre a Eliminar: ");
				gotoxy(38,11);
				color(7,0);
				printf("          ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("          Dui Madre a Eliminar: ");
				searchv=true;
				
			}//Fin if search longitud
		}while(!searchv);
		bool existe=false;
		int b,posicion;
			//Verifica si ya existe un usuario
				
			for(b=0;b<contM;b++)
			{
				if ((strcmp(strupr(search),strupr(madre[b].duiM)) == 0))
				{
					existe=true;
					posicion = b;
					break;
			
				} 
				else 
				{
						existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{

				color(255,2);
				gotoxy(14,14);
				printf(" Desea eliminar los Datos de esta Madre? (S/N):  ");
				color(255,4);
				char r;
				r= getch();
				if(toupper(r)=='S')
				{
					for(int f = posicion;f<contM;f++)
					{
						strcpy(madre[f].nombreM,madre[f+1].nombreM);
						strcpy(madre[f].apellidoM,madre[f+1].apellidoM);
						strcpy(madre[f].duiM,madre[f+1].duiM);
						strcpy(madre[f].telM,madre[f+1].telM);
						strcpy(madre[f].dirM,madre[f+1].dirM);
						strcpy(madre[f].comite,madre[f+1].comite);
						strcpy(madre[f].nombreCM,madre[f+1].nombreCM);
							
					}//Fin for F
					contM--;
					
					color(3,255);
					gotoxy(14,21);
					printf("  ¡Excelente!.Datos de Madre Eliminado con exito     ");
				}
				else
				{
					color(5,255);
					gotoxy(14,21);
					printf("   ¡Error!.Datos de Madre no eliminado.              ");
					
				}//Fin respuesta eliminar
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                                   ");
				gotoxy(16,14);
				printf("     ¡Error!.Dui de Madre no encontrado.           ");
				gotoxy(16,15);                                      
				printf("                                                   ");
			}//Fin if search

		color(255,4);
		gotoxy(30,25);
		printf(" Desea eliminar  o intentar otra vez? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin do while respuesta

}//Fin eliminarM

void modificarM()
{
	bool searchv=false;
	char res,dis,search[200];

	do
	{
		color(255,9);
		system("CLS");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,28,79,2); // Dibuja recuadro principal
		//incio barra horizontal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
			gotoxy(dis,33);
			printf(" ");
		}
		gotoxy(30,32);
		printf("Copyright UES 2017");
		//fin barra horizontal
			gotoxy(22,8);
			color(10,0);
			printf("    MODIFICAR DATOS DE MADRE    ");
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
		color(255,3);
		gotoxy(6,11);
		printf("         Dui Madre a Modificar: ");
		do{               

			gotoxy(38,11);
			color(7,0);
			fflush(stdin);
			numerosdui(search,caracter);
			if(strlen(search)<8)
			{
				color(255,12);
				gotoxy(6,11);
				printf("   *     Dui Madre a Modificar: ");
				gotoxy(38,11);
				color(7,0);
				printf("      ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
					printf("         Dui Madre a Modificar: ");
				searchv=true;
				
			}//Fin if search longitud
		}while(!searchv);
		bool existe=false;
		int b,posicion;
				//Verifica si ya existe un usuario
				
				for(b=0;b<contM;b++)
				{
					if ((strcmp(strupr(search),strupr(madre[b].duiM)) == 0))
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{

					char r,nom[200],apell[200],dui1[200],dui2[200],tel1[200],tel2[200];
					int k;
					bool valida=false;
					color(255,2);
					gotoxy(14,13);
					printf("Datos Encontrados de:  %s",madre[posicion].nombreCM);
					gotoxy(14,15);
					color(255,12);
					printf(" Desea modificar su nombre? (S/N):  ");
				
					r= getch();
					if(toupper(r)=='S')
					{
						
						color(255,3);
						gotoxy(10,17);
						printf("     NOMBRE: ");
						//Dibuja las cajitas donde digita el nombre
						for(k=23;k<60;k++)
						{
							gotoxy(k,17);
							color(7,0);
							printf(" ");
						
						}//Fin for k

						do
						{
							gotoxy(23,17);
							letras(nom,caracter);
							strupr(nom);
							if(strlen(nom)<3)
							{
								
								gotoxy(10,17);
								color(255,12);
								printf("  *  NOMBRE: ");
								gotoxy(23,17);
								color(7,0);
								printf("   ");
								valida=true;							
							
							}else
							{
								color(255,2);
								gotoxy(10,17);
								printf("    NOMBRE: ");
								valida=false;
							
							}
						
						}while(valida);

						
						strcpy(madre[posicion].nombreM,nom);
						strcat(strcpy(madre[posicion].nombreCM,""),(strcat(strcat(nom," "),madre[posicion].apellidoM)));
						gotoxy(20,19);
						color(3,255);
						printf("  Nombre Modificado.  ");

					
					}
					else
					{
						gotoxy(20,17);
						color(5,255);
						printf("  Nombre no fue Modificado.  ");
					}//Fin if respuesta nombre

					//----------------------------------------------------------------

					
					gotoxy(14,20);
					color(255,12);
					printf(" Desea modificar su apellido? (S/N):  ");
				
					r= getch();
					if(toupper(r)=='S')
					{
						
						color(255,3);
						gotoxy(10,22);
						printf("   APELLIDO: ");
						//Dibuja las cajitas donde digita el nombre
						for(k=23;k<60;k++)
						{
							gotoxy(k,22);
							color(7,0);
							printf(" ");
						
						}//Fin for k

						do
						{
							gotoxy(23,22);
							letras(apell,caracter);
							strupr(apell);
							if(strlen(apell)<3)
							{
								
								gotoxy(10,22);
								color(255,12);
								printf("*  APELLIDO: ");
								gotoxy(23,22);
								color(7,0);
								printf("   ");
								valida=true;							
							
							}else
							{
								color(255,2);
								gotoxy(10,22);
								printf("   APELLIDO: ");
								valida=false;
							
							}
						
						}while(valida);

						
						strcpy(madre[posicion].apellidoM,apell);
						strcat(madre[posicion].nombreM," ");
						strcpy(madre[posicion].nombreCM,strcat(madre[posicion].nombreM,madre[posicion].apellidoM));
						gotoxy(20,24);
						color(3,255);
						printf("  Apellido Modificado.  ");
						system("pause>null");
					
					}
					else
					{
						gotoxy(20,22);
						color(5,255);
						printf("  Apellido no fue Modificado.  ");
						system("pause>null");
					}//Fin if respuesta apellido
					//----------------------------------------------------------------------------
					for(k=10;k<27;k++)
					{
						for(int l = 10;l<76;l++)
						{
							color(255,0);
							gotoxy(l,k);
							printf(" ");
						
						}
					
					}//limpiar
					gotoxy(14,10);
					color(255,12);
					printf(" Desea modificar su DUI? (S/N):  ");
				
					r= getch();
					if(toupper(r)=='S')
					{
						
						color(255,3);
						gotoxy(10,12);
						printf("        DUI: ");
						//Cajita de DUI*******************
						color(7,0);
						gotoxy(24,12);
						printf("        ");
						gotoxy(32,12);
						color(255,9);
						printf("-");
						color(7,0);
						gotoxy(33,12);
						printf("  ");
						color(255,4);
						gotoxy(38,12);
						printf("Formato: 00000000-0");

				
					//Validando DUI
					do
					{
						color(7,0);
						gotoxy(24,12);
						numeros(dui1,caracter);
						if(strlen(dui1)<8 || strlen(dui1) > 8)
						{
							color(255,12);			
							gotoxy(10,12);
							printf("    *   DUI: ");
							color(7,0);
							gotoxy(24,12);
							printf("        ");
							gotoxy(32,12);
							color(255,9);
							printf("-");
							valida = true;
						}else
						{
							color(255,2);			
							gotoxy(10,12);
							printf("        DUI: ");
							valida = false;
						
						}


					}while(valida);
				
					do
					{
						color(7,0);
						gotoxy(33,12);
						numeros(dui2,caracter);
						if(strlen(dui2)<1 || strlen(dui2) > 1)
						{
							color(255,12);			
							gotoxy(10,12);
							printf("    *   DUI: ");
							gotoxy(32,12);
							color(255,9);
							printf("-");
							color(7,0);
							gotoxy(33,12);
							printf("  ");
							valida = true;
						}else
						{
							color(255,2);			
							gotoxy(10,12);
							printf("        DUI: ");
							valida = false;
								
						}

					}while(valida);

				bool repe = false;
				char duicompleto[200];
				strcpy(duicompleto,dui1);
				strcat(duicompleto,"-");
				strcat(duicompleto,dui2);
				//Verifica si ya existe un dui
				for(k=0;k<contM;k++)
				{
					if(k==posicion)
					{
						
					}
					else
					{
					if (strcmp(strupr(duicompleto),strupr(madre[k].duiM)) == 0)
					{
						repe=false;
						
						break;
			
					} 
					else 
					{
						repe = true;
					}//Fin if coomparacion
					}//End if comparar datos repetidos en comparacion
				
				}//Fin for ko

				if(!repe)
				{
					gotoxy(20,13);
					color(5,255);
					printf("  DUI no Modificado. Se repite.  ");
				}
				else
				{
					strcpy(madre[posicion].duiM,"");			
					strcpy(madre[posicion].duiM,dui1);
					strcat(madre[posicion].duiM,"-");
					strcat(madre[posicion].duiM,dui2);
					gotoxy(20,13);
					color(3,255);
					printf("  DUI Modificado.  ");					
				}					
					}
					else
					{
						gotoxy(20,13);
						color(5,255);
						printf("  DUI no fue Modificado.  ");
					}//Fin if respuesta 
					

					gotoxy(14,15);
					color(255,12);
					printf(" Desea modificar su Telefono? (S/N):  ");
						r= getch();
				
				
					if(toupper(r)=='S')
					{
					//Cajita de telefono
					gotoxy(10,17);
					color(255,3);
					printf("   TELEFONO: ");
					color(7,0);
					gotoxy(24,17);
					printf("    ");
					gotoxy(28,17);
					color(255,9);
					printf("-");
					color(7,0);
					gotoxy(29,17);
					printf("    ");
					color(255,4);
					gotoxy(38,17);
					printf("Formato: 0000-0000");
	


					//Validando Teléfono
						do
						{
							color(7,0);
							gotoxy(24,17);
							numeros(tel1,caracter);
							if(strlen(tel1)<4 || strlen(tel1) > 4)
							{
								color(255,12);			
								gotoxy(10,17);
								printf("*  TELEFONO: ");
								color(7,0);
								gotoxy(24,17);
								printf("    ");
								gotoxy(28,17);
								color(255,9);
								printf("-");
								valida = true;
							}else
							{
								color(255,2);			
								gotoxy(10,17);
								printf("   TELEFONO: ");
								valida = false;
								
							
							}


						}while(valida);
							
						
						do
						{
							color(7,0);
							gotoxy(29,17);
							numeros(tel2,caracter);
							if(strlen(tel2)<4 || strlen(tel2) > 4)
							{
								color(255,12);			
								gotoxy(10,17);
								printf("*  TELEFONO: ");
								color(7,0);
								gotoxy(29,17);
								printf("    ");
								gotoxy(28,17);
								color(255,9);
								printf("-");
								valida = true;
							}else
							{
								color(255,2);			
								gotoxy(10,17);
								printf("   TELEFONO: ");
								valida = false;
								
							
							}


						}while(valida);

						strcpy(madre[posicion].telM,"");
						strcpy(madre[posicion].telM,tel1);
						strcat(madre[posicion].telM,"-");
						strcat(madre[posicion].telM,tel2);
						color(3,255);			
						gotoxy(20,19);
						printf("  Telefono Modificado   ");

					}
					else
					{
						color(5,255);			
						gotoxy(20,18);
						printf("  Telefono no Modificado   ");
					
					}//Fin respuesta telefono modificar
		
					gotoxy(10,21);
					color(255,1);
					printf(" Desea agregar al comite a esta Madre? (S=Agregar/N =Quitar): ");
					r=getch();
					if(toupper(r)=='S')
					{
					gotoxy(20,23);
					color(3,255);
					printf(" Madre agregada al comite ");
					strcpy(madre[posicion].comite,"SI");
					}
					else if(toupper(r)=='N')
					{
					gotoxy(20,23);
					color(5,255);
					printf(" Madre quitada del comite ");
					strcpy(madre[posicion].comite,"NO");
					
					}
				}
				else
				{
					gotoxy(16,13);
					color(5,255);
					printf("                                                   ");
					gotoxy(16,14);
					printf("     ¡Error!.Dui de Madre no encontrado.           ");
					gotoxy(16,15);                                      
					printf("                                                   ");
				}//Fin if search

			color(255,4);
			gotoxy(30,25);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin do while respuesta

}//Fin eliminarM

//****************************************************************************************************************************************
//					INICIO DE SECCIONES, REGISTROS, MODIFICAR,INSERTAR Y ELIMINAR DATOS DE LOS ESTUDIANTES
//****************************************************************************************************************************************

void llenado()//Inicio llenado de datos
{ 

	//Estudiantes ya registrados o agregados
	char *cadenau = "MOISES ANDRES",*cadenap = "VENTURA VENTURA",*can="M117";
	strcpy(nombre[contN],cadenau);//Copia del dato que posee la variable cadenau a la variable nombre
	strcpy(apellidos[contN],cadenap);//Copia del dato que posee la variable cadenap a la variable apellidos
	strcpy(carnetU[contN],can);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//Incremento del contador

	char *cadenau1 = "RUTT NOHEMY",*cadenap1="MOLINA HERNADEZ",*can1="R217";
	strcpy(nombre[contN],cadenau1);//Copia del dato que posee la variable cadenau1 a la variable nombre
	strcpy(apellidos[contN],cadenap1);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU[contN],can1);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//Incremento del contador

	char *cadenau2 = "NANCY IRENE",*cadenap2="BELTRAN HERNADEZ",*can2="N317";
	strcpy(nombre[contN],cadenau2);//Copia del dato que posee la variable cadenau2 a la variable nombre
	strcpy(apellidos[contN],cadenap2);//Copia del dato que posee la variable cadenap2 a la variable apellidos
	strcpy(carnetU[contN],can2);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau3 = "JENNY MARICELA",*cadenap3="SANCHEZ VENTURA",*can3="J417";
	strcpy(nombre[contN],cadenau3);//Copia del dato que posee la variable cadenau3 a la variable nombre
	strcpy(apellidos[contN],cadenap3);//Copia del dato que posee la variable cadenap3 a la variable apellidos
	strcpy(carnetU[contN],can3);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau4 = "EVELYN DEL CARMEN",*cadenap4="HERNANDEZ GARCIA",*can4="E517";
	strcpy(nombre[contN],cadenau4);//Copia del dato que posee la variable cadenau4 a la variable nombre
	strcpy(apellidos[contN],cadenap4);//Copia del dato que posee la variable cadenap4 a la variable apellidos
	strcpy(carnetU[contN],can4);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau5 = "JOSE GERARDO",*cadenap5="ZOMETA DIAZ",*can5="J617";
	strcpy(nombre[contN],cadenau5);//Copia del dato que posee la variable cadenau5 a la variable nombre
	strcpy(apellidos[contN],cadenap5);//Copia del dato que posee la variable cadenap5 a la variable apellidos
	strcpy(carnetU[contN],can5);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau6 = "ESTEPHANY LARITHZA",*cadenap6="AQUINO BELTRAN",*can6="E717";
	strcpy(nombre[contN],cadenau6);//Copia del dato que posee la variable cadenau6 a la variable nombre
	strcpy(apellidos[contN],cadenap6);//Copia del dato que posee la variable cadenap6 a la variable apellidos
	strcpy(carnetU[contN],can6);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau7= "LUCIA MARGOT",*cadenap7="TORRES VENTURA",*can7="L817";
	strcpy(nombre[contN],cadenau7);//Copia del dato que posee la variable cadenau7 a la variable nombre
	strcpy(apellidos[contN],cadenap7);//Copia del dato que posee la variable cadenap7 a la variable apellidos
	strcpy(carnetU[contN],can7);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau8= "HELEN IRANI",*cadenap8="PALACIOS BELTRAN",*can8="H917";
	strcpy(nombre[contN],cadenau8);//Copia del dato que posee la variable cadenau8 a la variable nombre
	strcpy(apellidos[contN],cadenap8);//Copia del dato que posee la variable cadenap8 a la variable apellidos
	strcpy(carnetU[contN],can8);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau9= "JORGE ALBERTO",*cadenap9="GARCIA HERNANDEZ",*can9="J1017";
	strcpy(nombre[contN],cadenau9);//Copia del dato que posee la variable cadenau9 a la variable nombre
	strcpy(apellidos[contN],cadenap9);//Copia del dato que posee la variable cadenap9 a la variable apellidos
	strcpy(carnetU[contN],can9);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau10= "JOSE MIGUEL",*cadenap10="LOPEZ SANCHEZ",*can10="J1117";
	strcpy(nombre[contN],cadenau10);//Copia del dato que posee la variable cadenau10 a la variable nombre
	strcpy(apellidos[contN],cadenap10);//Copia del dato que posee la variable cadenap10 a la variable apellidos
	strcpy(carnetU[contN],can10);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau11= "ZULEYMA YAMILETH",*cadenap11="AQUINO RODRIGUEZ",*can11="Z1217";
	strcpy(nombre[contN],cadenau11);//Copia del dato que posee la variable cadenau11 a la variable nombre
	strcpy(apellidos[contN],cadenap11);//Copia del dato que posee la variable cadenap11 a la variable apellidos
	strcpy(carnetU[contN],can11);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau12 = "KEVIN ALBERTO",*cadenap12="LOPEZ CASTANEDA",*can12="K1317";
	strcpy(nombre[contN],cadenau12);//Copia del dato que posee la variable cadenau12 a la variable nombre
	strcpy(apellidos[contN],cadenap12);//Copia del dato que posee la variable cadenap12 a la variable apellidos
	strcpy(carnetU[contN],can12);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau13= "DARWIN ALFONZO",*cadenap13="FLORES COLINDRES",*can13="D1417";
	strcpy(nombre[contN],cadenau13);//Copia del dato que posee la variable cadenau13 a la variable nombre
	strcpy(apellidos[contN],cadenap13);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU[contN],can13);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

	char *cadenau14= "JOSE SAUL",*cadenap14="HERNANDEZ VASQUEZ",*can14="J1517";
	strcpy(nombre[contN],cadenau14);//Copia del dato que posee la variable cadenau14 a la variable nombre
	strcpy(apellidos[contN],cadenap14);//Copia del dato que posee la variable cadenap14 a la variable apellidos
	strcpy(carnetU[contN],can14);//Copia el dato constante para la generacion del carnet
	contN++;//incremento del contador
	contE++;//incremento del contador

}//Fin llenado de datos inicio

void llenado1()//Inicio llenado de datos
{ 

	//Estudiantes ya registrados o agregados
	char *cadenau = "ANA CAROLINA",*cadenap = "HERNANDEZ GARCIA",*can="A117";
	strcpy(nombre1[contN1],cadenau);//Copia del dato que posee la variable cadenau a la variable nombre
	strcpy(apellidos1[contN1],cadenap);//Copia del dato que posee la variable cadenap a la variable apellidos
	strcpy(carnetU1[contN1],can);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//Incremento del contador

	char *cadenau1 = "RUTT NOHEMY",*cadenap1="MOLINA HERNADEZ",*can1="R217";
	strcpy(nombre1[contN1],cadenau1);//Copia del dato que posee la variable cadenau1 a la variable nombre
	strcpy(apellidos1[contN1],cadenap1);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU1[contN1],can1);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//Incremento del contador

	char *cadenau2 = "NANCY IRENE",*cadenap2="BELTRAN HERNADEZ",*can2="N317";
	strcpy(nombre1[contN1],cadenau2);//Copia del dato que posee la variable cadenau2 a la variable nombre
	strcpy(apellidos1[contN1],cadenap2);//Copia del dato que posee la variable cadenap2 a la variable apellidos
	strcpy(carnetU1[contN1],can2);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau3 = "JENNY MARICELA",*cadenap3="SANCHEZ VENTURA",*can3="J417";
	strcpy(nombre1[contN1],cadenau3);//Copia del dato que posee la variable cadenau3 a la variable nombre
	strcpy(apellidos1[contN1],cadenap3);//Copia del dato que posee la variable cadenap3 a la variable apellidos
	strcpy(carnetU1[contN1],can3);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau4 = "EVELYN DEL CARMEN",*cadenap4="HERNANDEZ GARCIA",*can4="E517";
	strcpy(nombre1[contN1],cadenau4);//Copia del dato que posee la variable cadenau4 a la variable nombre
	strcpy(apellidos1[contN1],cadenap4);//Copia del dato que posee la variable cadenap4 a la variable apellidos
	strcpy(carnetU1[contN1],can4);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau5 = "JOSE GERARDO",*cadenap5="ZOMETA DIAZ",*can5="J617";
	strcpy(nombre1[contN1],cadenau5);//Copia del dato que posee la variable cadenau5 a la variable nombre
	strcpy(apellidos1[contN1],cadenap5);//Copia del dato que posee la variable cadenap5 a la variable apellidos
	strcpy(carnetU1[contN1],can5);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau6 = "ESTEPHANY LARITHZA",*cadenap6="AQUINO BELTRAN",*can6="E717";
	strcpy(nombre1[contN1],cadenau6);//Copia del dato que posee la variable cadenau6 a la variable nombre
	strcpy(apellidos1[contN1],cadenap6);//Copia del dato que posee la variable cadenap6 a la variable apellidos
	strcpy(carnetU1[contN1],can6);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau7= "LUCIA MARGOT",*cadenap7="TORRES VENTURA",*can7="L817";
	strcpy(nombre1[contN1],cadenau7);//Copia del dato que posee la variable cadenau7 a la variable nombre
	strcpy(apellidos1[contN1],cadenap7);//Copia del dato que posee la variable cadenap7 a la variable apellidos
	strcpy(carnetU1[contN1],can7);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau8= "HELEN IRANI",*cadenap8="PALACIOS BELTRAN",*can8="H917";
	strcpy(nombre1[contN1],cadenau8);//Copia del dato que posee la variable cadenau8 a la variable nombre
	strcpy(apellidos1[contN1],cadenap8);//Copia del dato que posee la variable cadenap8 a la variable apellidos
	strcpy(carnetU1[contN1],can8);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau9= "JORGE ALBERTO",*cadenap9="GARCIA HERNANDEZ",*can9="J1017";
	strcpy(nombre1[contN1],cadenau9);//Copia del dato que posee la variable cadenau9 a la variable nombre
	strcpy(apellidos1[contN1],cadenap9);//Copia del dato que posee la variable cadenap9 a la variable apellidos
	strcpy(carnetU1[contN1],can9);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau10= "JOSE MIGUEL",*cadenap10="LOPEZ SANCHEZ",*can10="J1117";
	strcpy(nombre1[contN1],cadenau10);//Copia del dato que posee la variable cadenau10 a la variable nombre
	strcpy(apellidos1[contN1],cadenap10);//Copia del dato que posee la variable cadenap10 a la variable apellidos
	strcpy(carnetU1[contN1],can10);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau11= "ZULEYMA YAMILETH",*cadenap11="AQUINO RODRIGUEZ",*can11="Z1217";
	strcpy(nombre1[contN1],cadenau11);//Copia del dato que posee la variable cadenau11 a la variable nombre
	strcpy(apellidos1[contN1],cadenap11);//Copia del dato que posee la variable cadenap11 a la variable apellidos
	strcpy(carnetU1[contN1],can11);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau12 = "KEVIN ALBERTO",*cadenap12="LOPEZ CASTANEDA",*can12="K1317";
	strcpy(nombre1[contN1],cadenau12);//Copia del dato que posee la variable cadenau12 a la variable nombre
	strcpy(apellidos1[contN1],cadenap12);//Copia del dato que posee la variable cadenap12 a la variable apellidos
	strcpy(carnetU1[contN1],can12);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau13= "DARWIN ALFONZO",*cadenap13="FLORES COLINDRES",*can13="D1417";
	strcpy(nombre1[contN1],cadenau13);//Copia del dato que posee la variable cadenau13 a la variable nombre
	strcpy(apellidos1[contN1],cadenap13);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU1[contN1],can13);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

	char *cadenau14= "JOSE SAUL",*cadenap14="HERNANDEZ VASQUEZ",*can14="J1517";
	strcpy(nombre1[contN1],cadenau14);//Copia del dato que posee la variable cadenau14 a la variable nombre
	strcpy(apellidos1[contN1],cadenap14);//Copia del dato que posee la variable cadenap14 a la variable apellidos
	strcpy(carnetU1[contN1],can14);//Copia el dato constante para la generacion del carnet
	contN1++;//incremento del contador
	contE1++;//incremento del contador

}//Fin llenado de datos 1

void llenado2()//Inicio llenado de datos
{ 

	//Estudiantes ya registrados o agregados
	char *cadenau = "WENDY NOHEMY",*cadenap = "VENTURA VASQUEZ",*can="W117";
	strcpy(nombre2[contN2],cadenau);//Copia del dato que posee la variable cadenau a la variable nombre
	strcpy(apellidos2[contN2],cadenap);//Copia del dato que posee la variable cadenap a la variable apellidos
	strcpy(carnetU2[contN2],can);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//Incremento del contador

	char *cadenau1 = "RUTT NOHEMY",*cadenap1="MOLINA HERNADEZ",*can1="R217";
	strcpy(nombre2[contN2],cadenau1);//Copia del dato que posee la variable cadenau1 a la variable nombre
	strcpy(apellidos2[contN2],cadenap1);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU2[contN2],can1);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//Incremento del contador

	char *cadenau2 = "NANCY IRENE",*cadenap2="BELTRAN HERNADEZ",*can2="N317";
	strcpy(nombre2[contN2],cadenau2);//Copia del dato que posee la variable cadenau2 a la variable nombre
	strcpy(apellidos2[contN2],cadenap2);//Copia del dato que posee la variable cadenap2 a la variable apellidos
	strcpy(carnetU2[contN2],can2);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau3 = "JENNY MARICELA",*cadenap3="SANCHEZ VENTURA",*can3="J417";
	strcpy(nombre2[contN2],cadenau3);//Copia del dato que posee la variable cadenau3 a la variable nombre
	strcpy(apellidos2[contN2],cadenap3);//Copia del dato que posee la variable cadenap3 a la variable apellidos
	strcpy(carnetU2[contN2],can3);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau4 = "EVELYN DEL CARMEN",*cadenap4="HERNANDEZ GARCIA",*can4="E517";
	strcpy(nombre2[contN2],cadenau4);//Copia del dato que posee la variable cadenau4 a la variable nombre
	strcpy(apellidos2[contN2],cadenap4);//Copia del dato que posee la variable cadenap4 a la variable apellidos
	strcpy(carnetU2[contN2],can4);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau5 = "JOSE GERARDO",*cadenap5="ZOMETA DIAZ",*can5="J617";
	strcpy(nombre2[contN2],cadenau5);//Copia del dato que posee la variable cadenau5 a la variable nombre
	strcpy(apellidos2[contN2],cadenap5);//Copia del dato que posee la variable cadenap5 a la variable apellidos
	strcpy(carnetU2[contN2],can5);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau6 = "ESTEPHANY LARITHZA",*cadenap6="AQUINO BELTRAN",*can6="E717";
	strcpy(nombre2[contN2],cadenau6);//Copia del dato que posee la variable cadenau6 a la variable nombre
	strcpy(apellidos2[contN2],cadenap6);//Copia del dato que posee la variable cadenap6 a la variable apellidos
	strcpy(carnetU2[contN2],can6);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau7= "LUCIA MARGOT",*cadenap7="TORRES VENTURA",*can7="L817";
	strcpy(nombre2[contN2],cadenau7);//Copia del dato que posee la variable cadenau7 a la variable nombre
	strcpy(apellidos2[contN2],cadenap7);//Copia del dato que posee la variable cadenap7 a la variable apellidos
	strcpy(carnetU2[contN2],can7);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau8= "HELEN IRANI",*cadenap8="PALACIOS BELTRAN",*can8="H917";
	strcpy(nombre2[contN2],cadenau8);//Copia del dato que posee la variable cadenau8 a la variable nombre
	strcpy(apellidos2[contN2],cadenap8);//Copia del dato que posee la variable cadenap8 a la variable apellidos
	strcpy(carnetU2[contN2],can8);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau9= "JORGE ALBERTO",*cadenap9="GARCIA HERNANDEZ",*can9="J1017";
	strcpy(nombre2[contN2],cadenau9);//Copia del dato que posee la variable cadenau9 a la variable nombre
	strcpy(apellidos2[contN2],cadenap9);//Copia del dato que posee la variable cadenap9 a la variable apellidos
	strcpy(carnetU2[contN2],can9);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau10= "JOSE MIGUEL",*cadenap10="LOPEZ SANCHEZ",*can10="J1117";
	strcpy(nombre2[contN2],cadenau10);//Copia del dato que posee la variable cadenau10 a la variable nombre
	strcpy(apellidos2[contN2],cadenap10);//Copia del dato que posee la variable cadenap10 a la variable apellidos
	strcpy(carnetU2[contN2],can10);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau11= "ZULEYMA YAMILETH",*cadenap11="AQUINO RODRIGUEZ",*can11="Z1217";
	strcpy(nombre2[contN2],cadenau11);//Copia del dato que posee la variable cadenau11 a la variable nombre
	strcpy(apellidos2[contN2],cadenap11);//Copia del dato que posee la variable cadenap11 a la variable apellidos
	strcpy(carnetU2[contN2],can11);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau12 = "KEVIN ALBERTO",*cadenap12="LOPEZ CASTANEDA",*can12="K1317";
	strcpy(nombre2[contN2],cadenau12);//Copia del dato que posee la variable cadenau12 a la variable nombre
	strcpy(apellidos2[contN2],cadenap12);//Copia del dato que posee la variable cadenap12 a la variable apellidos
	strcpy(carnetU2[contN2],can12);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau13= "DARWIN ALFONZO",*cadenap13="FLORES COLINDRES",*can13="D1417";
	strcpy(nombre2[contN2],cadenau13);//Copia del dato que posee la variable cadenau13 a la variable nombre
	strcpy(apellidos2[contN2],cadenap13);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU2[contN2],can13);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

	char *cadenau14= "JOSE SAUL",*cadenap14="HERNANDEZ VASQUEZ",*can14="J1517";
	strcpy(nombre2[contN2],cadenau14);//Copia del dato que posee la variable cadenau14 a la variable nombre
	strcpy(apellidos2[contN2],cadenap14);//Copia del dato que posee la variable cadenap14 a la variable apellidos
	strcpy(carnetU2[contN2],can14);//Copia el dato constante para la generacion del carnet
	contN2++;//incremento del contador
	contE2++;//incremento del contador

}//Fin llenado de datos 2

void llenado3()//Inicio llenado de datos
{ 

	//Estudiantes ya registrados o agregados
	char *cadenau = "MARIA DANIELA",*cadenap = "ROCHES PEREZ",*can="M117";
	strcpy(nombre3[contN3],cadenau);//Copia del dato que posee la variable cadenau a la variable nombre
	strcpy(apellidos3[contN3],cadenap);//Copia del dato que posee la variable cadenap a la variable apellidos
	strcpy(carnetU3[contN3],can);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//Incremento del contador

	char *cadenau1 = "RUTT NOHEMY",*cadenap1="MOLINA HERNADEZ",*can1="R217";
	strcpy(nombre3[contN3],cadenau1);//Copia del dato que posee la variable cadenau1 a la variable nombre
	strcpy(apellidos3[contN3],cadenap1);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU3[contN3],can1);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//Incremento del contador

	char *cadenau2 = "NANCY IRENE",*cadenap2="BELTRAN HERNADEZ",*can2="N317";
	strcpy(nombre3[contN3],cadenau2);//Copia del dato que posee la variable cadenau2 a la variable nombre
	strcpy(apellidos3[contN3],cadenap2);//Copia del dato que posee la variable cadenap2 a la variable apellidos
	strcpy(carnetU3[contN3],can2);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau3 = "JENNY MARICELA",*cadenap3="SANCHEZ VENTURA",*can3="J417";
	strcpy(nombre3[contN3],cadenau3);//Copia del dato que posee la variable cadenau3 a la variable nombre
	strcpy(apellidos3[contN3],cadenap3);//Copia del dato que posee la variable cadenap3 a la variable apellidos
	strcpy(carnetU3[contN3],can3);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau4 = "EVELYN DEL CARMEN",*cadenap4="HERNANDEZ GARCIA",*can4="E517";
	strcpy(nombre3[contN3],cadenau4);//Copia del dato que posee la variable cadenau4 a la variable nombre
	strcpy(apellidos3[contN3],cadenap4);//Copia del dato que posee la variable cadenap4 a la variable apellidos
	strcpy(carnetU3[contN3],can4);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau5 = "JOSE GERARDO",*cadenap5="ZOMETA DIAZ",*can5="J617";
	strcpy(nombre3[contN3],cadenau5);//Copia del dato que posee la variable cadenau5 a la variable nombre
	strcpy(apellidos3[contN3],cadenap5);//Copia del dato que posee la variable cadenap5 a la variable apellidos
	strcpy(carnetU3[contN3],can5);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau6 = "ESTEPHANY LARITHZA",*cadenap6="AQUINO BELTRAN",*can6="E717";
	strcpy(nombre3[contN3],cadenau6);//Copia del dato que posee la variable cadenau6 a la variable nombre
	strcpy(apellidos3[contN3],cadenap6);//Copia del dato que posee la variable cadenap6 a la variable apellidos
	strcpy(carnetU3[contN3],can6);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau7= "LUCIA MARGOT",*cadenap7="TORRES VENTURA",*can7="L817";
	strcpy(nombre3[contN3],cadenau7);//Copia del dato que posee la variable cadenau7 a la variable nombre
	strcpy(apellidos3[contN3],cadenap7);//Copia del dato que posee la variable cadenap7 a la variable apellidos
	strcpy(carnetU3[contN3],can7);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau8= "HELEN IRANI",*cadenap8="PALACIOS BELTRAN",*can8="H917";
	strcpy(nombre3[contN3],cadenau8);//Copia del dato que posee la variable cadenau8 a la variable nombre
	strcpy(apellidos3[contN3],cadenap8);//Copia del dato que posee la variable cadenap8 a la variable apellidos
	strcpy(carnetU3[contN3],can8);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau9= "JORGE ALBERTO",*cadenap9="GARCIA HERNANDEZ",*can9="J1017";
	strcpy(nombre3[contN3],cadenau9);//Copia del dato que posee la variable cadenau9 a la variable nombre
	strcpy(apellidos3[contN3],cadenap9);//Copia del dato que posee la variable cadenap9 a la variable apellidos
	strcpy(carnetU3[contN3],can9);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau10= "JOSE MIGUEL",*cadenap10="LOPEZ SANCHEZ",*can10="J1117";
	strcpy(nombre3[contN3],cadenau10);//Copia del dato que posee la variable cadenau10 a la variable nombre
	strcpy(apellidos3[contN3],cadenap10);//Copia del dato que posee la variable cadenap10 a la variable apellidos
	strcpy(carnetU3[contN3],can10);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau11= "ZULEYMA YAMILETH",*cadenap11="AQUINO RODRIGUEZ",*can11="Z1217";
	strcpy(nombre3[contN3],cadenau11);//Copia del dato que posee la variable cadenau11 a la variable nombre
	strcpy(apellidos3[contN3],cadenap11);//Copia del dato que posee la variable cadenap11 a la variable apellidos
	strcpy(carnetU3[contN3],can11);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau12 = "KEVIN ALBERTO",*cadenap12="LOPEZ CASTANEDA",*can12="K1317";
	strcpy(nombre3[contN3],cadenau12);//Copia del dato que posee la variable cadenau12 a la variable nombre
	strcpy(apellidos3[contN3],cadenap12);//Copia del dato que posee la variable cadenap12 a la variable apellidos
	strcpy(carnetU3[contN3],can12);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau13= "DARWIN ALFONZO",*cadenap13="FLORES COLINDRES",*can13="D1417";
	strcpy(nombre3[contN3],cadenau13);//Copia del dato que posee la variable cadenau13 a la variable nombre
	strcpy(apellidos3[contN3],cadenap13);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU3[contN3],can13);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

	char *cadenau14= "JOSE SAUL",*cadenap14="HERNANDEZ VASQUEZ",*can14="J1517";
	strcpy(nombre3[contN3],cadenau14);//Copia del dato que posee la variable cadenau14 a la variable nombre
	strcpy(apellidos3[contN3],cadenap14);//Copia del dato que posee la variable cadenap14 a la variable apellidos
	strcpy(carnetU3[contN3],can14);//Copia el dato constante para la generacion del carnet
	contN3++;//incremento del contador
	contE3++;//incremento del contador

}//Fin llenado de datos 3
void llenado4()//Inicio llenado de datos
{ 

	//Estudiantes ya registrados o agregados
	char *cadenau = "JOSE ANDRES",*cadenap = "BELTRAN VENTURA",*can="J117";
	strcpy(nombre4[contN4],cadenau);//Copia del dato que posee la variable cadenau a la variable nombre
	strcpy(apellidos4[contN4],cadenap);//Copia del dato que posee la variable cadenap a la variable apellidos
	strcpy(carnetU4[contN4],can);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//Incremento del contador

	char *cadenau1 = "RUTT NOHEMY",*cadenap1="MOLINA HERNADEZ",*can1="R217";
	strcpy(nombre4[contN4],cadenau1);//Copia del dato que posee la variable cadenau1 a la variable nombre
	strcpy(apellidos4[contN4],cadenap1);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU4[contN4],can1);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//Incremento del contador

	char *cadenau2 = "NANCY IRENE",*cadenap2="BELTRAN HERNADEZ",*can2="N317";
	strcpy(nombre4[contN4],cadenau2);//Copia del dato que posee la variable cadenau2 a la variable nombre
	strcpy(apellidos4[contN4],cadenap2);//Copia del dato que posee la variable cadenap2 a la variable apellidos
	strcpy(carnetU4[contN4],can2);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau3 = "JENNY MARICELA",*cadenap3="SANCHEZ VENTURA",*can3="J417";
	strcpy(nombre4[contN4],cadenau3);//Copia del dato que posee la variable cadenau3 a la variable nombre
	strcpy(apellidos4[contN4],cadenap3);//Copia del dato que posee la variable cadenap3 a la variable apellidos
	strcpy(carnetU4[contN4],can3);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau4 = "EVELYN DEL CARMEN",*cadenap4="HERNANDEZ GARCIA",*can4="E517";
	strcpy(nombre4[contN4],cadenau4);//Copia del dato que posee la variable cadenau4 a la variable nombre
	strcpy(apellidos4[contN4],cadenap4);//Copia del dato que posee la variable cadenap4 a la variable apellidos
	strcpy(carnetU4[contN4],can4);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau5 = "JOSE GERARDO",*cadenap5="ZOMETA DIAZ",*can5="J617";
	strcpy(nombre4[contN4],cadenau5);//Copia del dato que posee la variable cadenau5 a la variable nombre
	strcpy(apellidos4[contN4],cadenap5);//Copia del dato que posee la variable cadenap5 a la variable apellidos
	strcpy(carnetU4[contN4],can5);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau6 = "ESTEPHANY LARITHZA",*cadenap6="AQUINO BELTRAN",*can6="E717";
	strcpy(nombre4[contN4],cadenau6);//Copia del dato que posee la variable cadenau6 a la variable nombre
	strcpy(apellidos4[contN4],cadenap6);//Copia del dato que posee la variable cadenap6 a la variable apellidos
	strcpy(carnetU4[contN4],can6);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau7= "LUCIA MARGOT",*cadenap7="TORRES VENTURA",*can7="L817";
	strcpy(nombre4[contN4],cadenau7);//Copia del dato que posee la variable cadenau7 a la variable nombre
	strcpy(apellidos4[contN4],cadenap7);//Copia del dato que posee la variable cadenap7 a la variable apellidos
	strcpy(carnetU4[contN4],can7);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau8= "HELEN IRANI",*cadenap8="PALACIOS BELTRAN",*can8="H917";
	strcpy(nombre4[contN4],cadenau8);//Copia del dato que posee la variable cadenau8 a la variable nombre
	strcpy(apellidos4[contN4],cadenap8);//Copia del dato que posee la variable cadenap8 a la variable apellidos
	strcpy(carnetU4[contN4],can8);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau9= "JORGE ALBERTO",*cadenap9="GARCIA HERNANDEZ",*can9="J1017";
	strcpy(nombre4[contN4],cadenau9);//Copia del dato que posee la variable cadenau9 a la variable nombre
	strcpy(apellidos4[contN4],cadenap9);//Copia del dato que posee la variable cadenap9 a la variable apellidos
	strcpy(carnetU4[contN4],can9);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau10= "JOSE MIGUEL",*cadenap10="LOPEZ SANCHEZ",*can10="J1117";
	strcpy(nombre4[contN4],cadenau10);//Copia del dato que posee la variable cadenau10 a la variable nombre
	strcpy(apellidos4[contN4],cadenap10);//Copia del dato que posee la variable cadenap10 a la variable apellidos
	strcpy(carnetU4[contN4],can10);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau11= "ZULEYMA YAMILETH",*cadenap11="AQUINO RODRIGUEZ",*can11="Z1217";
	strcpy(nombre4[contN4],cadenau11);//Copia del dato que posee la variable cadenau11 a la variable nombre
	strcpy(apellidos4[contN4],cadenap11);//Copia del dato que posee la variable cadenap11 a la variable apellidos
	strcpy(carnetU4[contN4],can11);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau12 = "KEVIN ALBERTO",*cadenap12="LOPEZ CASTANEDA",*can12="K1317";
	strcpy(nombre4[contN4],cadenau12);//Copia del dato que posee la variable cadenau12 a la variable nombre
	strcpy(apellidos4[contN4],cadenap12);//Copia del dato que posee la variable cadenap12 a la variable apellidos
	strcpy(carnetU4[contN4],can12);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau13= "DARWIN ALFONZO",*cadenap13="FLORES COLINDRES",*can13="D1417";
	strcpy(nombre4[contN4],cadenau13);//Copia del dato que posee la variable cadenau13 a la variable nombre
	strcpy(apellidos4[contN4],cadenap13);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU4[contN4],can13);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

	char *cadenau14= "JOSE SAUL",*cadenap14="HERNANDEZ VASQUEZ",*can14="J1517";
	strcpy(nombre4[contN4],cadenau14);//Copia del dato que posee la variable cadenau14 a la variable nombre
	strcpy(apellidos4[contN4],cadenap14);//Copia del dato que posee la variable cadenap14 a la variable apellidos
	strcpy(carnetU4[contN4],can14);//Copia el dato constante para la generacion del carnet
	contN4++;//incremento del contador
	contE4++;//incremento del contador

}//Fin llenado de datos 4

void llenado5()//Inicio llenado de datos
{ 

	//Estudiantes ya registrados o agregados
	char *cadenau = "JOSE ANGEL",*cadenap = "HERNANDEZ VENTURA",*can="J117";
	strcpy(nombre5[contN5],cadenau);//Copia del dato que posee la variable cadenau a la variable nombre
	strcpy(apellidos5[contN5],cadenap);//Copia del dato que posee la variable cadenap a la variable apellidos
	strcpy(carnetU5[contN5],can);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//Incremento del contador

	char *cadenau1 = "RUTT NOHEMY",*cadenap1="MOLINA HERNADEZ",*can1="R217";
	strcpy(nombre5[contN5],cadenau1);//Copia del dato que posee la variable cadenau1 a la variable nombre
	strcpy(apellidos5[contN5],cadenap1);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU5[contN5],can1);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//Incremento del contador

	char *cadenau2 = "NANCY IRENE",*cadenap2="BELTRAN HERNADEZ",*can2="N317";
	strcpy(nombre5[contN5],cadenau2);//Copia del dato que posee la variable cadenau2 a la variable nombre
	strcpy(apellidos5[contN5],cadenap2);//Copia del dato que posee la variable cadenap2 a la variable apellidos
	strcpy(carnetU5[contN5],can2);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau3 = "JENNY MARICELA",*cadenap3="SANCHEZ VENTURA",*can3="J417";
	strcpy(nombre5[contN5],cadenau3);//Copia del dato que posee la variable cadenau3 a la variable nombre
	strcpy(apellidos5[contN5],cadenap3);//Copia del dato que posee la variable cadenap3 a la variable apellidos
	strcpy(carnetU5[contN5],can3);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau4 = "EVELYN DEL CARMEN",*cadenap4="HERNANDEZ GARCIA",*can4="E517";
	strcpy(nombre5[contN5],cadenau4);//Copia del dato que posee la variable cadenau4 a la variable nombre
	strcpy(apellidos5[contN5],cadenap4);//Copia del dato que posee la variable cadenap4 a la variable apellidos
	strcpy(carnetU5[contN5],can4);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau5 = "JOSE GERARDO",*cadenap5="ZOMETA DIAZ",*can5="J617";
	strcpy(nombre5[contN5],cadenau5);//Copia del dato que posee la variable cadenau5 a la variable nombre
	strcpy(apellidos5[contN5],cadenap5);//Copia del dato que posee la variable cadenap5 a la variable apellidos
	strcpy(carnetU5[contN5],can5);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau6 = "ESTEPHANY LARITHZA",*cadenap6="AQUINO BELTRAN",*can6="E717";
	strcpy(nombre5[contN5],cadenau6);//Copia del dato que posee la variable cadenau6 a la variable nombre
	strcpy(apellidos5[contN5],cadenap6);//Copia del dato que posee la variable cadenap6 a la variable apellidos
	strcpy(carnetU5[contN5],can6);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau7= "LUCIA MARGOT",*cadenap7="TORRES VENTURA",*can7="L817";
	strcpy(nombre5[contN5],cadenau7);//Copia del dato que posee la variable cadenau7 a la variable nombre
	strcpy(apellidos5[contN5],cadenap7);//Copia del dato que posee la variable cadenap7 a la variable apellidos
	strcpy(carnetU5[contN5],can7);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau8= "HELEN IRANI",*cadenap8="PALACIOS BELTRAN",*can8="H917";
	strcpy(nombre5[contN5],cadenau8);//Copia del dato que posee la variable cadenau8 a la variable nombre
	strcpy(apellidos5[contN5],cadenap8);//Copia del dato que posee la variable cadenap8 a la variable apellidos
	strcpy(carnetU5[contN5],can8);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau9= "JORGE ALBERTO",*cadenap9="GARCIA HERNANDEZ",*can9="J1017";
	strcpy(nombre5[contN5],cadenau9);//Copia del dato que posee la variable cadenau9 a la variable nombre
	strcpy(apellidos5[contN5],cadenap9);//Copia del dato que posee la variable cadenap9 a la variable apellidos
	strcpy(carnetU5[contN5],can9);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau10= "JOSE MIGUEL",*cadenap10="LOPEZ SANCHEZ",*can10="J1117";
	strcpy(nombre5[contN5],cadenau10);//Copia del dato que posee la variable cadenau10 a la variable nombre
	strcpy(apellidos5[contN5],cadenap10);//Copia del dato que posee la variable cadenap10 a la variable apellidos
	strcpy(carnetU5[contN5],can10);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau11= "ZULEYMA YAMILETH",*cadenap11="AQUINO RODRIGUEZ",*can11="Z1217";
	strcpy(nombre5[contN5],cadenau11);//Copia del dato que posee la variable cadenau11 a la variable nombre
	strcpy(apellidos5[contN5],cadenap11);//Copia del dato que posee la variable cadenap11 a la variable apellidos
	strcpy(carnetU5[contN5],can11);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau12 = "KEVIN ALBERTO",*cadenap12="LOPEZ CASTANEDA",*can12="K1317";
	strcpy(nombre5[contN5],cadenau12);//Copia del dato que posee la variable cadenau12 a la variable nombre
	strcpy(apellidos5[contN5],cadenap12);//Copia del dato que posee la variable cadenap12 a la variable apellidos
	strcpy(carnetU5[contN5],can12);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau13= "DARWIN ALFONZO",*cadenap13="FLORES COLINDRES",*can13="D1417";
	strcpy(nombre5[contN5],cadenau13);//Copia del dato que posee la variable cadenau13 a la variable nombre
	strcpy(apellidos5[contN5],cadenap13);//Copia del dato que posee la variable cadenap1 a la variable apellidos
	strcpy(carnetU5[contN5],can13);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

	char *cadenau14= "JOSE SAUL",*cadenap14="HERNANDEZ VASQUEZ",*can14="J1517";
	strcpy(nombre5[contN5],cadenau14);//Copia del dato que posee la variable cadenau14 a la variable nombre
	strcpy(apellidos5[contN5],cadenap14);//Copia del dato que posee la variable cadenap14 a la variable apellidos
	strcpy(carnetU5[contN5],can14);//Copia el dato constante para la generacion del carnet
	contN5++;//incremento del contador
	contE5++;//incremento del contador

}//Fin llenado de datos 5

//****************************************************************************************************************************************
//													SECCIONES DE LA INSTITUCION
//****************************************************************************************************************************************

void menusecciones()//Inicio  menusecciones
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,46,79,2); // Dibuja recuadro principal

////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);
			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");

			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(7,16);
			printf("  SECCIONES  ");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			
			//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,49);
			printf(" ");
			gotoxy(dis,50);
			printf(" ");
			gotoxy(dis,51);
			printf(" ");
		}
		gotoxy(30,50);
		printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			color(3,15);
			gotoxy(5,21);
			printf("               ");
			gotoxy(5,22);
			printf(" %c A. 1° Grado ",4);
			gotoxy(5,23);
			printf("               ");
			gotoxy(5,26);
			printf("               ");
			gotoxy(5,27);
			printf(" %c B. 2° Grado ",4);
			gotoxy(5,28);
			printf("               ");
			gotoxy(5,31);
			printf("               ");
			gotoxy(5,32);
			printf(" %c C. 3° Grado ",4);
			gotoxy(5,33);
			printf("               ");
			gotoxy(32,21);
			printf("               ");
			gotoxy(32,22);
			printf(" %c D. 4° Grado ",4);
			gotoxy(32,23);
			printf("               ");
			gotoxy(32,26);
			printf("               ");
			gotoxy(32,27);
			printf(" %c E. 5° Grado ",4);
			gotoxy(32,28);
			printf("               ");
			gotoxy(32,31);
			printf("               ");
			gotoxy(32,32);
			printf(" %c F. 6° Grado ",4);
			gotoxy(32,33);
			printf("               ");
			gotoxy(60,21);
			printf("               ");
			gotoxy(60,22);
			printf(" %c G. 7° Grado ",4);
			gotoxy(60,23);
			printf("               ");
			gotoxy(60,26);
			printf("               ");
			gotoxy(60,27);
			printf(" %c H. 8° Grado ",4);
			gotoxy(60,28);
			printf("               ");
			gotoxy(60,31);
			printf("               ");
			gotoxy(60,32);
			printf(" %c I. 9° Grado ",4);
			gotoxy(60,33);
			printf("               ");
			color(3,255);
			gotoxy(5,39);
			printf("               ");
			gotoxy(5,40);
			printf(" %c 5. Regresar ",27);
			gotoxy(5,41);
			printf("               ");
			color(255,3);
			gotoxy(30,39);
			printf(" %c Elija una opcion: ",16);
			gotoxy(50,16);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,41);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(40,41);
			color(7,0);
			op = getch(); //leer opcion
			switch(toupper(op))
			{
			case 'A':
				menuestudiantes();
				
				break;

			case 'B':
				menuestudiantes1();
				
				break;
			case 'C':
				menuestudiantes2();
				
				break;
			case 'D':
				menuestudiantes3();
				
				break;
			case 'E':
				menuestudiantes4();
				
				break;
			case 'F':
				
				menuestudiantes5();
		
				break;
			case 'G':
				menuestudiantes6();//SOLO SE MOSTRARAN, TABLAS VACIAS SIN REGISTRO DE ESTUDIANTES, CREACION DE ESTAS SECCIONES SERA OPCIONAL
				
				break;
			case 'H':
				menuestudiantes7();//SOLO SE MOSTRARAN, TABLAS VACIAS SIN REGISTRO DE ESTUDIANTES, CREACION DE ESTAS SECCIONES SERA OPCIONAL
				break;
			case 'I':
				menuestudiantes8();//SOLO SE MOSTRARAN, TABLAS VACIAS SIN REGISTRO DE ESTUDIANTES, CREACION DE ESTAS SECCIONES SERA OPCIONAL
				break;
			case '5':
				break;
			default:
				color(255,4);
				gotoxy(40,40);
				printf("%c",25);
				gotoxy(37,41);
				printf("%c",26);
				gotoxy(43,41);
				printf("%c",27);
				gotoxy(40,42);
				printf("%c",24);
				gotoxy(29,43);			
				printf("  Opcion incorrecta.");
				Sleep(500);
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,44);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	principal();//regresa ala funcion principal
}//Fin menusecciones

//****************************************************************************************************************************************
//							MENU DE LAS OPCIONES DEL REGISTRO, ELIMINAR Y MODIFICAR DATOS DEL ESTUDIANTE
//****************************************************************************************************************************************
void menuestudiantes()//Inicio menuestudiantes
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("1 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,41);
			printf(" ");
			gotoxy(dis,42);
			printf(" ");
			gotoxy(dis,43);
			printf(" ");
		}
		gotoxy(30,42);
		printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes("agregar");
				
				break;

			case '2':
				Estudiantes("modificar");

				break;
			case '3':
				Estudiantes("eliminar");
	
				break;

			case '4':
				Estudiantes("mostrar");
				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menusecciones();
}//Fin menuestudiantes

void menuestudiantes1()//Inicio menuestudiantes
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("2 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,41);
			printf(" ");
			gotoxy(dis,42);
			printf(" ");
			gotoxy(dis,43);
			printf(" ");
		}
		gotoxy(30,42);
		printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes1("agregar1");
				
				break;

			case '2':
				Estudiantes1("modificar1");

				break;
			case '3':
				Estudiantes1("eliminar1");
	
				break;

			case '4':
				Estudiantes1("mostrar1");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menusecciones();
	
}//Fin menuestudiantes1

void menuestudiantes2()//Inicio menuestudiantes
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("3 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,41);
			printf(" ");
			gotoxy(dis,42);
			printf(" ");
			gotoxy(dis,43);
			printf(" ");
		}
		gotoxy(30,42);
		printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes2("agregar2");
				
				break;

			case '2':
				Estudiantes2("modificar2");

				break;
			case '3':
				Estudiantes2("eliminar2");
	
				break;

			case '4':
				Estudiantes2("mostrar2");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	menusecciones();
	
}//Fin menuestudiantes2

void menuestudiantes3()//Inicio menuestudiantes
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);
			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("4 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,41);
			printf(" ");
			gotoxy(dis,42);
			printf(" ");
			gotoxy(dis,43);
			printf(" ");
		}
		gotoxy(30,42);
		printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes3("agregar3");
				
				break;

			case '2':
				Estudiantes3("modificar3");

				break;
			case '3':
				Estudiantes3("eliminar3");
	
				break;

			case '4':
				Estudiantes3("mostrar3");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	menusecciones();
	
}//Fin menuestudiantes3

void menuestudiantes4()//Inicio menuestudiantes
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("5 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,41);
			printf(" ");
			gotoxy(dis,42);
			printf(" ");
			gotoxy(dis,43);
			printf(" ");
		}
		gotoxy(30,42);
		printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes4("agregar4");
				
				break;

			case '2':
				Estudiantes4("modificar4");

				break;
			case '3':
				Estudiantes4("eliminar4");
	
				break;

			case '4':
				Estudiantes4("mostrar4");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	menusecciones();
	
}//Fin menuestudiantes4

void menuestudiantes5()//Inicio menuestudiantes
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("6 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes5("agregar5");
				
				break;

			case '2':
				Estudiantes5("modificar5");

				break;
			case '3':
				Estudiantes5("eliminar5");
	
				break;

			case '4':
				Estudiantes5("mostrar5");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	menusecciones();
	
}//Fin menuestudiantes5

void menuestudiantes6()//inicio menuestudiantes6
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("7 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes6("agregar6");
				
				break;

			case '2':
				Estudiantes6("modificar6");

				break;
			case '3':
				Estudiantes6("eliminar6");
	
				break;

			case '4':
				Estudiantes6("mostrar6");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	menusecciones();

}//fin menuestudiantes6

void menuestudiantes7()//inicio menuestudiantes7
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("8 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes7("agregar7");
				
				break;

			case '2':
				Estudiantes7("modificar7");

				break;
			case '3':
				Estudiantes7("eliminar7");
	
				break;

			case '4':
				Estudiantes7("mostrar7");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	menusecciones();

}//fin menuestudiantes7

void menuestudiantes8()
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(10,16);
			printf("9 GRADO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(2,21);
			color(255,3);
			printf("%c 1. Registrar Estudiante",5);
			gotoxy(2,24);
			printf("%c 2. Modificar datos del Estudiante ",5);
			gotoxy(39,21);
			printf(" %c 3. Eliminar Estudiantes registrados",5);
			gotoxy(39,24);
			printf(" %c 4. Mostrar  datos de los Estudiantes",5);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 5. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				Estudiantes8("agregar8");
				
				break;

			case '2':
				Estudiantes8("modificar8");

				break;
			case '3':
				Estudiantes8("eliminar8");
	
				break;

			case '4':
				Estudiantes8("mostrar8");

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,35);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res

	menusecciones();

}//fin menuestudiantes8
void Estudiantes(char opcion[20])//Inicio Estudiantes
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");

			//copyright(2,0);
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre[contN],nombreU);
			strcpy(apellidos[contN],apellidoU);
			strcpy(carnetU[contN],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN++;//Incremento del contador para estudiantes agregados
			contE++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,0);
			int cont,b=0; 
			for (i = 0,cont=12;i < contN; i++,cont=cont+2) //Inicio for de estudiantes
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos[i],nombre[i],carnetU[i]);//Impresion de los estudiantes registrados y agregados
				b++;
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}//Fin for de estudiantes
			color(3,3);
			gotoxy(1,cont);
			printf("------------------------------------------------------------------------------\n");
			color(255,3);
			printf("\n");
			printf("  Total                                                             %d",b);

			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			color(255,4);
			gotoxy(58	,cont+4);
			printf(" %c Regresar (S/N): ",27);
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,31);
				printf(" ");
				gotoxy(dis,32);
				printf(" ");
				gotoxy(dis,33);
				printf(" ");
			}

			gotoxy(30,32);
			printf("Copyright UES 2017");
			//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE      ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                         ");
				
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("      Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN;f++)
						{
							 strcpy(carnetU[f],carnetU[f+1]);//elimina carnet
							 strcpy(nombre[f],nombre[f+1]);//elimina nombre
							 strcpy(apellidos[f],apellidos[f+1]);//elimina apellidos
							
						}//Fin for F
						contN--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar
}//Fin Estudiantes

void Estudiantes1(char opcion[20])//Inicio Estudiantes
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar1")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");

			//copyright(2,0);
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE1+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre1[contN1],nombreU);
			strcpy(apellidos1[contN1],apellidoU);
			strcpy(carnetU1[contN1],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN1++;//Incremento del contador para estudiantes agregados
			contE1++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar1")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			//encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,g=0; 
			for (i = 0,cont=12;i < contN1; i++,cont=cont+2) //Inicio for de estudiantes
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos1[i],nombre1[i],carnetU1[i]);//Impresion de los estudiantes registrados y agregados
				g++;
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");		
			}//Fin for de estudiantes
			color(3,3);
			gotoxy(1,cont);
			printf("------------------------------------------------------------------------------\n");
			color(255,3);
			printf("\n");
			printf("  Total                                                             %d",g);
			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			color(255,4);
			gotoxy(58	,cont+4);
			printf(" %c Regresar (S/N): ",27);
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar1")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN1;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU1[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre1[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}
				gotoxy(30,32);
				printf("Copyright UES 2017");
			//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN1;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre1[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre1[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU1[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos1[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Deseas modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar1")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                            ");
				
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
				// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN1;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU1[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN1;f++)
						{
							 strcpy(carnetU1[f],carnetU1[f+1]);//elimina carnet
							 strcpy(nombre1[f],nombre1[f+1]);//elimina nombre
							 strcpy(apellidos1[f],apellidos1[f+1]);//elimina apellidos
							
						}//Fin for F
						contN1--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar
}//Fin Estudiantes1

void Estudiantes2(char opcion[20])//Inicio Estudiantes
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar2")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");

			//copyright(2,0);
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE2+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre2[contN2],nombreU);
			strcpy(apellidos2[contN2],apellidoU);
			strcpy(carnetU2[contN2],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN2++;//Incremento del contador para estudiantes agregados
			contE2++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar2")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			//encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,h=0; 
			for (i = 0,cont=12;i < contN2; i++,cont=cont+2) //Inicio for de estudiantes
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos2[i],nombre2[i],carnetU2[i]);//Impresion de los estudiantes registrados y agregados
				h++;
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");

			}//Fin for de estudiantes
			color(3,3);
			gotoxy(1,cont);
			printf("------------------------------------------------------------------------------\n");
			color(255,3);
			printf("\n");
			printf("  Total                                                             %d",h);
			
			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,7);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS    ");
			color(255,4);
			gotoxy(58	,cont+4);
			printf(" %c Regresar (S/N): ",27);
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar2")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN2;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU2[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre2[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}

				gotoxy(30,32);
				printf("Copyright UES 2017");
				//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN2;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre2[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre2[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU2[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos2[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar2")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

				gotoxy(42,11);
				color(7,0);
				fflush(stdin);
				gets(search);//captura carnet ingresado

				if(strlen(search)<4)//if que pide que los datos no sean vacios
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Eliminar: ");
					gotoxy(42,11);
					color(7,0);
					printf("                            ");
				
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Eliminar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);
			bool existe=false;
			int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN2;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU2[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN2;f++)
						{
							 strcpy(carnetU2[f],carnetU2[f+1]);//elimina carnet
							 strcpy(nombre2[f],nombre2[f+1]);//elimina nombre
							 strcpy(apellidos2[f],apellidos2[f+1]);//elimina apellidos
							
						}//Fin for F
						contN2--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar
}//Fin Estudiantes2

void Estudiantes3(char opcion[20])//Inicio Estudiantes
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar3")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");

			//copyright(2,0);
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE3+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre3[contN3],nombreU);
			strcpy(apellidos3[contN3],apellidoU);
			strcpy(carnetU3[contN3],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN3++;//Incremento del contador para estudiantes agregados
			contE3++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar3")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,s=0; 
			for (i = 0,cont=12;i < contN3; i++,cont=cont+2) //Inicio for de estudiantes
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos3[i],nombre3[i],carnetU3[i]);//Impresion de los estudiantes registrados y agregados
				s++;
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");

			}//Fin for de estudiantes
			color(3,3);
			gotoxy(1,cont);
			printf("------------------------------------------------------------------------------\n");
			color(255,3);
			printf("\n");
			printf("  Total                                                             %d",s);

			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			color(255,4);
			gotoxy(58	,cont+4);
			printf(" %c Regresar (S/N): ",27);
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar3")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN3;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU3[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre3[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}
				gotoxy(30,32);
				printf("Copyright UES 2017");
				//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN3;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre3[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre3[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU3[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos3[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Deseas modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar3")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                         ");
				
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN3;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU3[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN3;f++)
						{
							 strcpy(carnetU3[f],carnetU3[f+1]);//elimina carnet
							 strcpy(nombre3[f],nombre3[f+1]);//elimina nombre
							 strcpy(apellidos3[f],apellidos3[f+1]);//elimina apellidos
							
						}//Fin for F
						contN3--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar
}//Fin Estudiantes3

void Estudiantes4(char opcion[20])//Inicio Estudiantes
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar4")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE4+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre4[contN4],nombreU);
			strcpy(apellidos4[contN4],apellidoU);
			strcpy(carnetU4[contN4],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN4++;//Incremento del contador para estudiantes agregados
			contE4++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar4")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,q=0; 
			for (i = 0,cont=12;i < contN4; i++,cont=cont+2) //Inicio for de estudiantes
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos4[i],nombre4[i],carnetU4[i]);//Impresion de los estudiantes registrados y agregados
				q++;
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}//Fin for de estudiantes
			color(3,3);
			gotoxy(1,cont);
			printf("------------------------------------------------------------------------------\n");
			color(255,3);
			printf("\n");
			printf("  Total                                                             %d",q);

			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			color(255,4);
			gotoxy(58	,cont+4);
			printf(" %c Regresar (S/N): ",27);
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar4")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN4;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU4[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre4[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}
				gotoxy(30,32);
				printf("Copyright UES 2017");
				//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN4;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre4[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre4[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU4[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos4[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar4")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                          ");
				
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN4;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU4[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN4;f++)
						{
							 strcpy(carnetU4[f],carnetU4[f+1]);//elimina carnet
							 strcpy(nombre4[f],nombre4[f+1]);//elimina nombre
							 strcpy(apellidos4[f],apellidos4[f+1]);//elimina apellidos
							
						}//Fin for F
						contN4--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar
}//Fin Estudiantes4

void Estudiantes5(char opcion[20])//Inicio Estudiantes
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar5")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE5+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre5[contN5],nombreU);
			strcpy(apellidos5[contN5],apellidoU);
			strcpy(carnetU5[contN5],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN5++;//Incremento del contador para estudiantes agregados
			contE5++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta

		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar5")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,z=0; 
			for (i = 0,cont=12;i < contN5; i++,cont=cont+2) //Inicio for de estudiantes
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos5[i],nombre5[i],carnetU5[i]);//Impresion de los estudiantes registrados y agregados
				z++;
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}//Fin for de estudiantes
			color(3,3);
			gotoxy(1,cont);
			printf("------------------------------------------------------------------------------\n");
			color(255,3);
			printf("\n");
			printf("  Total                                                             %d",z);

			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			color(255,4);
			gotoxy(58	,cont+4);
			printf(" %c Regresar (S/N): ",27);
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar5")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN5;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU5[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre5[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}

				gotoxy(30,32);
				printf("Copyright UES 2017");
				//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN5;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre5[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre5[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU5[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos5[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar5")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                            ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN5;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU5[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN5;f++)
						{
							 strcpy(carnetU5[f],carnetU5[f+1]);//elimina carnet
							 strcpy(nombre5[f],nombre5[f+1]);//elimina nombre
							 strcpy(apellidos5[f],apellidos5[f+1]);//elimina apellidos
							
						}//Fin for F
						contN5--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar
}//Fin Estudiantes5


void Estudiantes6(char opcion[20])//inicio estudiantes6
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar6")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE6+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre6[contN6],nombreU);
			strcpy(apellidos6[contN6],apellidoU);
			strcpy(carnetU6[contN6],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN6++;//Incremento del contador para estudiantes agregados
			contE6++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta

		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar6")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,z=0; 
			if(contN6>0)
			{
				for (i = 0,cont=12;i < contN6; i++,cont=cont+2) //Inicio for de estudiantes
				{
					gotoxy(1,cont-1);
					color(8,255);
					printf("                                                                              \n");
					gotoxy(1,cont);
					color(255,1);
					printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos6[i],nombre6[i],carnetU6[i]);//Impresion de los estudiantes registrados y agregados
					z++;
					gotoxy(1,cont+1);
					color(8,255);
					printf("                                                                              \n");
				}//Fin for de estudiantes
				color(3,3);
				gotoxy(1,cont-1);
				printf("\n-------------------------------------------------------------------------------\n");
				color(255,3);
				printf("\n");
				printf("  Total                                                             %d",z);
				color(255,4);
				gotoxy(58	,cont+4);
				printf(" %c Regresar (S/N): ",27);
			}
			else
			{
				color(3,3);
				gotoxy(1,cont);
				printf("-------------------------------------------------------------------------------");
				color(255,3);
				printf("\n\n");
				printf("  Total                                                             %d",z);
				color(255,4);
				printf("                                     No hay Estudiantes registrados\n");
				color(255,4);
				printf("                                                           %c Regresar (S/N): ",27);
			}

			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar6")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN6;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU6[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre6[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}

				gotoxy(30,32);
				printf("Copyright UES 2017");
				//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN6;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre6[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre6[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU6[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos6[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar6")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                            ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN6;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU6[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN6;f++)
						{
							 strcpy(carnetU6[f],carnetU6[f+1]);//elimina carnet
							 strcpy(nombre6[f],nombre6[f+1]);//elimina nombre
							 strcpy(apellidos6[f],apellidos6[f+1]);//elimina apellidos
							
						}//Fin for F
						contN6--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar

}//fin estudiantes6
void Estudiantes7(char opcion[20])//inicio estudiantes7
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar7")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE7+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre7[contN7],nombreU);
			strcpy(apellidos7[contN7],apellidoU);
			strcpy(carnetU7[contN7],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN7++;//Incremento del contador para estudiantes agregados
			contE7++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta

		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar7")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,z=0; 
			if(contN7>0)
			{
				for (i = 0,cont=12;i < contN7; i++,cont=cont+2) //Inicio for de estudiantes
				{
					gotoxy(1,cont-1);
					color(8,255);
					printf("                                                                              \n");
					gotoxy(1,cont);
					color(255,1);
					printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos7[i],nombre7[i],carnetU7[i]);//Impresion de los estudiantes registrados y agregados
					z++;
					gotoxy(1,cont+1);
					color(8,255);
					printf("                                                                              \n");
				}//Fin for de estudiantes
				color(3,3);
				gotoxy(1,cont-1);
				printf("\n-------------------------------------------------------------------------------\n");
				color(255,3);
				printf("\n");
				printf("  Total                                                             %d",z);
				color(255,4);
				gotoxy(58	,cont+4);
				printf(" %c Regresar (S/N): ",27);
			}
			else
			{
				color(3,3);
				gotoxy(1,cont);
				printf("-------------------------------------------------------------------------------");
				color(255,3);
				printf("\n\n");
				printf("  Total                                                             %d",z);
				color(255,4);
				printf("                                     No hay Estudiantes registrados\n");
				color(255,4);
				printf("                                                           %c Regresar (S/N): ",27);
			}
			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar7")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN7;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU7[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre7[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}

				gotoxy(30,32);
				printf("Copyright UES 2017");
				//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN7;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre7[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre7[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU7[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos7[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar7")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                            ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN7;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU7[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN7;f++)
						{
							 strcpy(carnetU7[f],carnetU7[f+1]);//elimina carnet
							 strcpy(nombre7[f],nombre7[f+1]);//elimina nombre
							 strcpy(apellidos7[f],apellidos7[f+1]);//elimina apellidos
							
						}//Fin for F
						contN7--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar

}//fin estudiantes7
void Estudiantes8(char opcion[20])//inicio estudiantes8
{
	//variables locales
	bool va=false,repe=false,searchv=false,valida=false; //variable booleana
	int i = 0,j=0;	//variables para los for´s
	int aumentar;//aumenta el tamaño del marco
	char nombreU[150],apellidoU[150],search[200];//guarda nombre y apellidos para el registro de los estudiantes
	char res,v,dis;//guarda si el usuario desea seguir con el proceso de registro

	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

///////////////////////////////////////////AGREGAR ESTUDIANTES///////////////////////////////////////////////////////////////////////////////
	//codicion agregar nuevos estudiantes
	if(opcion =="agregar8")//inicio if agregar estudiantes
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			gotoxy(22,8);
			color(10,0);
			printf("    REGISTRO DE ESTUDIANTE    ");
			color(255,3);
			gotoxy(10,11);
			printf("     NOMBRES: ");
			gotoxy(10,15);
			printf("  APELLIDOS: ");
			//Dibuja las cajitas donde digita el usuario
			for(int k=24;k<60;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
				gotoxy(k,15);
				printf(" ");
			}//Fin for k
			
			do//inicio do while para la ingresacion del nombre
			{
				gotoxy(24,11);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(nombreU,caracter);
				if(strlen(nombreU)<3)
				{
					color(255,12);
					gotoxy(10,11);
					printf(" *   NOMBRES: ");
					gotoxy(24,11);
					color(7,0);
					printf("                     ");
					va = false;
				}
					
				else
				{
					color(255,2);
					gotoxy(10,11);
					printf("     NOMBRES: ");
					va=true;
					}//Fin if

			}while(!va);//Fin do while va
			strupr(nombreU);//convierte a mayuscula el nombre
				
			do
			{
				gotoxy(24,15);
				fflush(stdin);//limpia el buffer
				color(7,0);
				letras(apellidoU,caracter);

				if(strlen(apellidoU)<5)
				{
					color(255,12);
					gotoxy(10,15);
					printf(" * APELLIDOS: ");
					gotoxy(24,15);
					color(7,0);
					printf("                     ");
					va = false;
					}
					
				else
				{
					color(255,2);
					gotoxy(10,15);
					printf("   APELLIDOS: ");
					va=true;
				}//Fin if
			}while(!va);//Fin do while va

			strupr(apellidoU);//convierte a mayuscula el apellido
			color(255,2);
			gotoxy(10,15);
			printf("   APELLIDOS: ");

			//Generar  carnet del estudiante
				int j=0;
				char codigo[50],nom;
			
				while(j<strlen(nombreU))
				{
					if(nombreU[j]!=32)
					{
						nom = nombreU[j];
						break;
					}
					else
					{
						nom = 'K';
					}
					j++;				
				}
				
				sprintf(codigo,"%c%d%s",nom,contE8+1,anio);//concatena variables

				//Muestra el mensaje para el nuevo estudiante agregado
			strcpy(nombre8[contN8],nombreU);
			strcpy(apellidos8[contN8],apellidoU);
			strcpy(carnetU8[contN8],codigo);
			gotoxy(15,17);
			color(4,255);
			printf("\t\t\t\t\t\t");
			gotoxy(15,18);
			printf("\tEstudiante agregado satisfactoriamente \t");
			gotoxy(15,19);
			printf("\t\t\t\t\t\t");
			contN8++;//Incremento del contador para estudiantes agregados
			contE8++;//Incremento del contador para CARNET de los Estudiantes

			//Mensaje para agregar nuevo estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea registrar  un nuevo Estudiante? (S/N):");
			res=getch(); //Leer la respuesta

		}while(toupper(res)=='S');//Fin fo while respuesta


	}//Fin if opcion agregar

////////////////////////////////////////////////////MOSTRAR DATOS DEL ESTUDIANTE//////////////////////////////////////////////////////////////////
	//Condicion ver datos de los estudiantes registrados
	if(opcion == "mostrar8")
	{
		do
		{
			color(255,13);
			system("CLS");
			color(255,13);
			encabezado();
			color(3,3);
			gotoxy(1,9);
			printf("------------------------------------------------------------------------------");
			gotoxy(1,10);
			color(3,15);
			printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
			gotoxy(1,11);
			color(3,3);
			printf("------------------------------------------------------------------------------\n");
			color(255,1);
			int cont,z=0;
			if(contN8>0)
			{
				for (i = 0,cont=12;i < contN8; i++,cont=cont+2) //Inicio for de estudiantes
				{
					gotoxy(1,cont-1);
					color(8,255);
					printf("                                                                              \n");
					gotoxy(1,cont);
					color(255,1);
					printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos8[i],nombre8[i],carnetU8[i]);//Impresion de los estudiantes registrados y agregados
					z++;
					gotoxy(1,cont+1);
					color(8,255);
					printf("                                                                              \n");
				}//Fin for de estudiantes
				color(3,3);
				gotoxy(1,cont-1);
				printf("\n-------------------------------------------------------------------------------\n");
				color(255,3);
				printf("\n");
				printf("  Total                                                             %d",z);
				color(255,4);
				gotoxy(58	,cont+4);
				printf(" %c Regresar (S/N): ",27);
			}
			else
			{
				color(3,3);
				gotoxy(1,cont);
				printf("-------------------------------------------------------------------------------");
				color(255,3);
				printf("\n\n");
				printf("  Total                                                             %d",z);
				color(255,4);
				printf("                                     No hay Estudiantes registrados\n");
				color(255,4);
				printf("                                                           %c Regresar (S/N): ",27);
			}

			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar+2,79,1); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar+5);
				printf(" ");
				gotoxy(dis,aumentar+6);
				printf(" ");
				gotoxy(dis,aumentar+7);
				printf(" ");
			}

			gotoxy(30,aumentar+6);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(14,8);
			color(10,0);
			printf("        LISTADO DE ESTUDIANTES REGISTRADOS       ");
			res = getch();
		}while(toupper(res)!='S');//Fin do while y regresa al menu 
	}//Fin if condicion mostrar

////////////////////////////////////////////MODIFICAR DATOS DEL ESTUDIANTE////////////////////////////////////////
	//Cpndicion modificar datos del estudiante
	if(opcion=="modificar8")
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(16,8);
			color(10,0);
			printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
			//copyright(2,0);
			for(int k=38;k<70;k++)
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k
			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Modificar: ");
			do{ //inicioo buscar carnet              
				gotoxy(45,11);
				color(7,0);
				fflush(stdin);
				gets(search);

				if(strlen(search)<4)
				{
					color(255,12);
					gotoxy(6,11);
					printf("* Carnet del Estudiante a Modificar: ");
					gotoxy(45,11);
					color(7,0);
					printf("                    ");
					searchv=false;
			
				}else
				{
					color(255,2);
					gotoxy(6,11);
					printf("  Carnet del Estudiante a Modificar: ");
					searchv=true;
				
				}//Fin if search 
			}while(!searchv);//fin buscar carnet
			bool existe=false;
			int b,posicion;
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contN8;b++)
			{
				if ((strcmp(strupr(search),strupr(carnetU8[b])) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for ko
			if(existe)
			{
				color(3,255);
				gotoxy(8,13);
				printf("    Estudiante Encontrado. Modifique los datos de %s   ",nombre8[posicion]);
				color(255,9);
				system("pause>nul");
				color(255,9);
				system("cls");
				color(255,9);
				encabezado();
				color(3,3);
				sysbox(8,0,28,79,2); // Dibuja recuadro principal
				//inicio copyright
				for(dis=0;dis<80;dis++)
				{
					color(5,255);
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
				}

				gotoxy(30,32);
				printf("Copyright UES 2017");
				//fin copyright
				gotoxy(16,8);
				color(10,0);
				printf("       MODIFICAR DATOS DEL ESTUDIANTE       ");
				gotoxy(14,12);
				color(255,12);
				printf("Desea modificar el nombre? (S/N):  ");
				v= getch();
//////////////////INICIO MODIFICAR NOMBRE DEL ESTUDIANTE/////////////////////////////////////////////////////////////
				if(toupper(v)=='S')
				{
					color(255,3);
					gotoxy(10,14);
					printf("  N. NOMBRES: "); //Dibuja las cajitas donde digitan los nombres del estudiante
					for(int k=24;k<60;k++)
					{
						gotoxy(k,14);
						color(7,0);
						printf(" ");
					}//Fin for k

					//incio captura del nombre del estudiante
					do
					{
						gotoxy(25,14);
						fflush(stdin);
						color(7,0);
						//validacion del nombre del estudiante
						letras(nombreU,caracter);
						if(strlen(nombreU)<3)
						{
							color(255,12);
							gotoxy(10,14);
							printf("* N. NOMBRES:");
							gotoxy(24,14);
							color(7,0);
							printf("                    ");
							valida= true;
						}
						else
						{
							color(255,2);
							gotoxy(10,14);
							printf("  N. NOMBRES:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(nombreU);//convierte a mayuscula
					//Verifica si ya existe un estudiante
					int ko;
					for(ko=0;ko<contN8;ko++)
					{
						if(ko==posicion)
						{
						
						}
						else
						{
							if (strcmp(strupr(nombreU),strupr(nombre8[ko])) == 0)//busca datos existentes
							{
								repe=false;
								break;
							} 
							else 
							{
								repe = true;
							}//Fin if coomparacion
						}//Fin if comparar datos repetidos en comparacion
				
					}//Fin for ko	

					if(!repe)
					{
						gotoxy(20,16);
						color(5,255);
						printf("  Nombre no modificado  ");
					}
					else
					{
						//Generar  carnet del estudiante
						int j=0;
						char codig[50],nom;
						while(j<strlen(nombreU))
						{
							if(nombreU[j]!=32)
							{
								nom = nombreU[j];
								break;
							}
							else
							{
								nom = 'K';
							}
							j++;				
						}
						sprintf(codig,"%c%d%s",nom,posicion+1,anio);//concatena variables
						strcpy(nombre8[posicion],nombreU);//copia el nombre ingresado a guardarlo en la variable original
						strcpy(carnetU8[posicion],codig);//guarda carnet
						gotoxy(20,16);
						color(3,255);
						printf("  Nombre Modificado.  ");
					}//fin else modificar nombre del estudiante
				}
				else
				{
					gotoxy(20,15);	
					color(5,255);
					printf("  Nombre no fue Modificado.  ");
				}//fin else modificar nombre
//////////////////////////////////////////FIN NOMBRES////////////////////////////////////////////////////////////////////

//////////////////////////////////INICIO MIDIFICAR APELLIDOS/////////////////////////////////////////////////////////
				//inicio captura de apellidos
				gotoxy(14,18);
				color(255,12);
				printf("Desea modificar el apellido? (S/N):  ");	
				v= getch();
				if(toupper(v)=='S')
				{
					gotoxy(7,20);
					color(255,3);
					printf("   N. APELLIDOS: ");
					for(int l=24;l<60;l++)
					{
						gotoxy(l,20);
						color(7,0);
						printf(" ");
					}//Fin for k
					do
					{
						gotoxy(25,20);
						fflush(stdin);
						color(7,0);
						//validacion de solo letras
						letras(apellidoU,caracter);
						if(strlen(apellidoU)<5)
						{
							color(255,12);
							gotoxy(6,20);
							printf("  * N. APELLIDOS:");
							gotoxy(24,20);
							color(7,0);
							printf("                        ");
							valida=true;				
						}
						else
						{
							color(255,2);
							gotoxy(7,20);
							printf("   N. APELLIDOS:");
							valida=false;
						}//Fin if

					}while(valida);//Fin do while va
					strupr(apellidoU);
					strcpy(apellidos8[posicion],apellidoU);//copia apellido ingresado y lo guarda en la variable original
					color(255,2);
					gotoxy(7,20);
					printf("   N. APELLIDOS:");
					gotoxy(20,22);
					color(3,255);
					printf("  Apellido Modificado.  ");
				}//fin if modificar apellidos
				else
				{
					gotoxy(20,21);
					color(5,255);
					printf("  Apellido no fue Modificado.  ");
				}//fin else modificar apellidos
////////////////////////////FIN MODIFICAR APELLIDOS//////////////////////////////////////////	
			}
			else
			{
				gotoxy(16,13);
				color(5,255);
				printf("                                           ");
				gotoxy(16,14);
				printf("     ¡Error!.Estudiante no encontrado.     ");
				gotoxy(16,15);                                      
				printf("                                           ");
			}//End if existe
			color(255,4);
			gotoxy(30,24);
			printf(" Desea modificar  o intentar otra vez? (S/N):");
			res=getch(); //Leer la respuesta
		}while(toupper(res)=='S');//Fin fo while respuesta
	}//fin modificar

/////////////////////////////////////////ELIMINAR DATOS DEL ESTUDIANTE/////////////////////////////////////////////
	//condicion eliminar datos del estudiante
	if(opcion=="eliminar8")
	{	
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,26,79,2); // Dibuja recuadro principal
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
			}

			gotoxy(30,30);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(22,8);
			color(10,0);
			printf("    ELIMINAR DATOS DE ESTUDIANTES    ");
			//copyright(2,0);
			for(int k=38;k<70;k++)//inicio for k que imprime cajitas 
			{
				gotoxy(k,11);
				color(7,0);
				printf(" ");
			}//Fin for k

			color(255,3);
			gotoxy(6,11);
			printf("  Carnet del Estudiante a Eliminar: ");
			do{               

			gotoxy(42,11);
			color(7,0);
			fflush(stdin);
			gets(search);//captura carnet ingresado

			if(strlen(search)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,11);
				printf("* Carnet del Estudiante a Eliminar: ");
				gotoxy(42,11);
				color(7,0);
				printf("                            ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(6,11);
				printf("  Carnet del Estudiante a Eliminar: ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);
		bool existe=false;
		int b,posicion;//variables que serviran´para identificar en que posicion esta el estudiante, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
				//Verifica si ya existe un usuario
				for(b=0;b<contN8;b++)
				{
					if ((strcmp(strupr(search),strupr(carnetU8[b])) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
					{
						existe=true;
						posicion = b;
						break;
			
					} 
					else 
					{
						existe = false;
					}//Fin if coomparacion
				
				}//Fin for ko
				if(existe)
				{
					color(255,2);
					gotoxy(2,14);
					printf("       Desea eliminar los Datos de el Estudiante? (S/N):  ");
					color(255,4);
					char r;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
					r= getch();
					if(toupper(r)=='S')
					{
						for(int f = posicion;f<contN8;f++)
						{
							 strcpy(carnetU8[f],carnetU8[f+1]);//elimina carnet
							 strcpy(nombre8[f],nombre8[f+1]);//elimina nombre
							 strcpy(apellidos8[f],apellidos8[f+1]);//elimina apellidos
							
						}//Fin for F
						contN8--;
					
					color(3,255);
					gotoxy(14,20);
					printf("     ¡Excelente!.Estudiante Eliminado con exito     ");
					}
					else
					{
						color(5,255);
						gotoxy(14,20);
						printf("     ¡Error!.Estudiante no eliminado            ");
					
					}//Fin respuesta y copiar los datos
				}
				else
				{
					gotoxy(14,13);
					color(5,255);
					printf("                                           ");
					gotoxy(14,14);
					printf("     ¡Error!.Estudiante no encontrado.     ");
					gotoxy(14,15);                                      
					printf("                                           ");
				}//Fin if buscar estudiante
			color(255,4);
			gotoxy(30,24);
			printf(" Desea eliminar  o intentar otra vez? (S/N):");
			res=getch(); //captura respuesta
		}while(toupper(res)=='S');//Fin do while respuesta
	}//fin eliminar
}//fin estudiantes8

//****************************************************************************************************************************************
//														MENU DE SEMANAS
//****************************************************************************************************************************************
void llenadodias()//inicio llenadodias
{
	//lunes
	strcpy(l[contL].alimento,"Arroz en leche");
	strcpy(l[contL].codigo,"A117");
	contL++;
	contL1++;
	strcpy(l[contL].alimento,"Poleada");
	strcpy(l[contL].codigo,"P217");
	contL++;
	contL1++;
	strcpy(l[contL].alimento,"Pupusas con Frijoles");
	strcpy(l[contL].codigo,"P317");
	contL++;
	contL1++;

	//martes
	strcpy(d[contma].alimento1,"Arroz con leche");
	strcpy(d[contma].codigo1,"A117");
	contma++;
	contma1++;
	strcpy(d[contma].alimento1,"Poleada");
	strcpy(d[contma].codigo1,"P217");
	contma++;
	contma1++;
	//miercoles
	strcpy(ml[contmi].alimento2,"Arroz con vegetales y bebida fortificada");
	strcpy(ml[contmi].codigo2,"A117");
	contmi++;
	contmi1++;
	strcpy(ml[contmi].alimento2,"Empanadas de harina de arroz y frijoles ");
	strcpy(ml[contmi].codigo2,"E217");
	contmi++;
	contmi1++;
	//jueves
	strcpy(jk[contj].alimentos3,"Sopa de Frijoles y bebida fortificada");
	strcpy(jk[contj].codigos3,"S117");
	contj++;
	contj1++;
	strcpy(jk[contj].alimentos3,"Sopa de arroz y bebida fortificada");
	strcpy(jk[contj].codigos3,"S217");
	contj++;
	contj1++;
	//viernes
	strcpy(v[contV].alimento4,"Arroz frito y bebida fortificada");
	strcpy(v[contV].codigo4,"A117");
	contV++;
	contV1++;
	strcpy(v[contV].alimento4,"Pasteles de arina de arroz");
	strcpy(v[contV].codigo4,"P217");
	contV++;
	contV1++;
}//fin llenadodias
void menusemana()//inicio menusemana
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,49,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(7,16);
			printf("MENU SEMANA");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,53);
			printf(" ");
			gotoxy(dis,54);
			printf(" ");
			gotoxy(dis,55);
			printf(" ");
		}
		gotoxy(30,54);
		printf("Copyright UES 2017");

//***************************************************************************************************************************************
//											 TABLA DE LOS DIAS DE LA SEMANA
//***************************************************************************************************************************************
		////marco verde días////
			color(3,15);
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,19);
				printf(" ");
				gotoxy(dis,20);
				printf(" ");
			}	
			color(3,15);
			gotoxy(0,18);
			printf("                                                                                ");
			gotoxy(0,37);
			printf("                                                                                ");
			color(3,15);
			gotoxy(4,19);
			printf("1. Lunes");
			gotoxy(20,19);
			printf("2. Martes");
			gotoxy(34,19);
			printf("3. Miercoles");
			gotoxy(52,19);
			printf("4. Jueves");
			gotoxy(67,19);
			printf("5. Viernes\n");
			color(255,0);
			////marco gris////
			color(7,15);
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,21);
				printf(" ");
				gotoxy(dis,22);
				printf(" ");
				gotoxy(dis,23);
				printf(" ");
				gotoxy(dis,24);
				printf(" ");
				gotoxy(dis,25);
				printf(" ");
				gotoxy(dis,26);
				printf(" ");
				gotoxy(dis,27);
				printf(" ");
				gotoxy(dis,28);
				printf(" ");
				gotoxy(dis,29);
				printf(" ");
				gotoxy(dis,30);
				printf(" ");
				gotoxy(dis,31);
				printf(" ");
				gotoxy(dis,32);
				printf(" ");
				gotoxy(dis,33);
				printf(" ");
				gotoxy(dis,34);
				printf(" ");
				gotoxy(dis,35);
				printf(" ");
				gotoxy(dis,36);
				printf(" ");
			}
			//lineas verticales
			for(int u=0;u<=20;u++)
			{
				color(3,3);
				gotoxy(16,19);
				printf("-\n");
				gotoxy(16,20);
				printf("-\n");
				gotoxy(16,21);
				printf("-\n");
				gotoxy(16,22);
				printf("-\n");
				gotoxy(16,23);
				printf("-\n");
				gotoxy(16,24);
				printf("-\n");
				gotoxy(16,25);
				printf("-\n");
				gotoxy(16,26);
				printf("-\n");
				gotoxy(16,27);
				printf("-\n");
				gotoxy(16,28);
				printf("-\n");
				gotoxy(16,29);
				printf("-\n");
				gotoxy(16,30);
				printf("-\n");
				gotoxy(16,31);
				printf("-\n");
				gotoxy(16,32);
				printf("-\n");
				gotoxy(16,33);
				printf("-\n");
				gotoxy(16,34);
				printf("-");
				gotoxy(16,35);
				printf("-");
				gotoxy(16,36);
				printf("-");


				gotoxy(32,19);
				printf("-\n");
				gotoxy(32,20);
				printf("-\n");
				gotoxy(32,21);
				printf("-\n");
				gotoxy(32,22);
				printf("-\n");
				gotoxy(32,23);
				printf("-\n");
				gotoxy(32,24);
				printf("-\n");
				gotoxy(32,25);
				printf("-\n");
				gotoxy(32,26);
				printf("-\n");
				gotoxy(32,27);
				printf("-\n");
				gotoxy(32,28);
				printf("-\n");
				gotoxy(32,29);
				printf("-\n");
				gotoxy(32,30);
				printf("-\n");
				gotoxy(32,31);
				printf("-\n");
				gotoxy(32,32);
				printf("-\n");
				gotoxy(32,33);
				printf("-\n");
				gotoxy(32,34);
				printf("-");
				gotoxy(32,35);
				printf("-");
				gotoxy(32,36);
				printf("-");

				gotoxy(48,19);
				printf("-\n");
				gotoxy(48,20);
				printf("-\n");
				gotoxy(48,21);
				printf("-\n");
				gotoxy(48,22);
				printf("-\n");
				gotoxy(48,23);
				printf("-\n");
				gotoxy(48,24);
				printf("-\n");
				gotoxy(48,25);
				printf("-\n");
				gotoxy(48,26);
				printf("-\n");
				gotoxy(48,27);
				printf("-\n");
				gotoxy(48,28);
				printf("-\n");
				gotoxy(48,29);
				printf("-\n");
				gotoxy(48,30);
				printf("-\n");
				gotoxy(48,31);
				printf("-\n");
				gotoxy(48,32);
				printf("-\n");
				gotoxy(48,33);
				printf("-\n");
				gotoxy(48,34);
				printf("-");
				gotoxy(48,35);
				printf("-");
				gotoxy(48,36);
				printf("-");

				gotoxy(64,19);
				printf("-\n");
				gotoxy(64,20);
				printf("-\n");
				gotoxy(64,21);
				printf("-\n");
				gotoxy(64,22);
				printf("-\n");
				gotoxy(64,23);
				printf("-\n");
				gotoxy(64,24);
				printf("-\n");
				gotoxy(64,25);
				printf("-\n");
				gotoxy(64,26);
				printf("-\n");
				gotoxy(64,27);
				printf("-\n");
				gotoxy(64,28);
				printf("-\n");
				gotoxy(64,29);
				printf("-\n");
				gotoxy(64,30);
				printf("-\n");
				gotoxy(64,31);
				printf("-\n");
				gotoxy(64,32);
				printf("-\n");
				gotoxy(64,33);
				printf("-\n");
				gotoxy(64,34);
				printf("-");
				gotoxy(64,35);
				printf("-");
				gotoxy(64,36);
				printf("-");
			}
			//lunes
			color(7,0);
			gotoxy(1,23);
			printf(" 1. Arroz con");
			gotoxy(1,24);
			printf("    leche");

			gotoxy(1,29);
			printf(" 2. Poleada");

			gotoxy(1,31);
			printf(" 3. Pupusas de");
			gotoxy(1,32);
			printf("    Arroz con");
			gotoxy(1,33);
			printf("    Frijoles");
			//martes
			gotoxy(17,23);
			printf(" 1. Arroz con");
			gotoxy(17,24);
			printf("    leche");

			gotoxy(17,29);
			printf(" 2. Poleada");
			//miercoles
			gotoxy(33,23);
			printf(" 1. Arroz con");
			gotoxy(33,24);
			printf("    vegetales");
			gotoxy(33,25);
			printf("    y bebida");
			gotoxy(33,26);
			printf("   fortificada");

			gotoxy(33,29);
			printf(" 2. Empanadas");
			gotoxy(33,30);
			printf("    de harina");
			gotoxy(33,31);
			printf("    de arroz ");
			gotoxy(33,32);
			printf("    y frijoles");
			//jueves
			gotoxy(49,23);
			printf(" 1. Sopa de");
			gotoxy(49,24);
			printf("    frijoles");
			gotoxy(49,25);
			printf("    y bebida");
			gotoxy(49,26);
			printf("   fortificada");

			gotoxy(49,29);
			printf(" 2. Sopa de");
			gotoxy(49,30);
			printf("    arroz");
			gotoxy(49,31);
			printf("    y bebida");
			gotoxy(49,32);
			printf("   fortificada");


			//viernes
			gotoxy(65,23);
			printf(" 1. Arroz");
			gotoxy(65,24);
			printf("    frito");
			gotoxy(65,25);
			printf("    y bebida");
			gotoxy(65,26);
			printf("  fortificada");

			gotoxy(65,29);
			printf(" 2. Pasteles");
			gotoxy(65,30);
			printf("    de arina");
			gotoxy(65,31);
			printf("    de arroz");
			gotoxy(65,32);
			printf("    rellenos");
			gotoxy(65,33);
			printf("    de frijo-");
			gotoxy(65,34);
			printf("   les fritos");
//***************************************************************************************************************************************
//																FIN TABLA
//***************************************************************************************************************************************

			color(3,15);
			gotoxy(12,43);
			printf("               ");
			gotoxy(12,44);
			printf(" %c 6. Regresar ",27);
			gotoxy(12,45);
			printf("               ");
			color(255,3);
			gotoxy(30,43);
			printf(" %c Seleccione un dia: ",16);
			gotoxy(20,33);

			for(int k=31;k<51;k++)
			{
				gotoxy(k,45);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,45);
			color(7,0);
			op=getch();
			switch(op)
			{
			case '1':
				 menulunes();
				
				break;

			case '2':
				 menumartes();

				break;
			case '3':
				 menumiercoles();
	
				break;

			case '4':
				 menujueves();

				break;
			case '5':
				menuviernes();
				break;
			case '6':
				break;

			default:
				color(255,4);
				gotoxy(39,44);
				printf("%c",25);
				gotoxy(37,45);
				printf("%c",26);
				gotoxy(41,45);
				printf("%c",27);
				gotoxy(39,46);
				printf("%c",24);
				gotoxy(30,47);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='6');//Fin do while op
		gotoxy(58,47);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	principal();//llamado de la funcion principal
}//fin menu semana

void menulunes()//Inicio menulunes
{
	char resp,op,dis;
	int aumentar, cont;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(7,16);
			printf("MENU DIA LUNES");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis
			//Muestra menu en pantalla pricipal del dia lunes
			color(3,3);
			gotoxy(0,18);
			printf("--------------------------------------------------------------------------------");
			color(3,15);
			gotoxy(0,19);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(0,20);
			color(3,3);
			printf("---------------------------------------------------------------------------------\n");
			color(255,1);
			for(k=0,cont=22;k<contL;k++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%3d\t%-50s%-14s\n",k+1,l[k].alimento,l[k].codigo);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------\n");
			if(k>=0)
			{
				aumentar=cont+24;
			}
			else
			{
				aumentar = 26;
			}
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar);
				printf(" ");
				gotoxy(dis,aumentar+1);
				printf(" ");
				gotoxy(dis,aumentar+2);
				printf(" ");
			}
			gotoxy(30,aumentar+1);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			color(255,3);
			gotoxy(10,cont+4);
			printf(" %c 1. Agregar Menu   ",5);
			gotoxy(10,cont+7);
			printf(" %c 2. Eliminar Menu  ",5);
			gotoxy(46,cont+4);
			printf(" %c 3. Asistencia     ",5);
			gotoxy(46,cont+7);
			printf(" %c 4. Elija Menu     ",5);
			color(3,15);
			gotoxy(10,cont+14);
			printf("               ");
			gotoxy(10,cont+15);
			printf(" %c 5. Regresar ",27);
			gotoxy(10,cont+16);
			printf("               ");
			color(255,3);
			gotoxy(30,cont+14);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,cont+16);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,cont+16);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				if(contL<3)
				{
					ingresarlunes();
				}
				else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf("  Elimine un Menu para  ");
					gotoxy(54,cont+16);
					printf("   agregar uno nuevo    ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}
				break;

			case '2':
				eliminarlunes();

				break;
			case '3':
				if(totlunes1<=0)
				{
					asistencialunes();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Ya se paso asistencias ");
					gotoxy(54,cont+16);
					printf("      Elija un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;

			case '4':
				if(totlunes1>0)
				{
					elejirmenu();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Pasar asistencias para ");
					gotoxy(54,cont+16);
					printf("     Elejir un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,cont+15);
				printf("%c",25);
				gotoxy(37,cont+16);
				printf("%c",26);
				gotoxy(41,cont+16);
				printf("%c",27);
				gotoxy(39,cont+17);
				printf("%c",24);
				gotoxy(30,cont+18);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,cont+18);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menusemana();

}//Inicio menulunes
void menumartes()//Inicio menumartes
{
	char resp,op,dis;
	int aumentar, cont;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(7,16);
			printf("MENU DIA LUNES");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis
			//Muestra menu en pantalla pricipal del dia lunes
			color(3,3);
			gotoxy(0,18);
			printf("--------------------------------------------------------------------------------");
			color(3,15);
			gotoxy(0,19);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(0,20);
			color(3,3);
			printf("---------------------------------------------------------------------------------\n");
			color(255,1);
			for(k=0,cont=22;k<contma;k++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%3d\t%-50s%-14s\n",k+1,d[k].alimento1,d[k].codigo1);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------\n");
			if(k>=0)
			{
				aumentar=cont+24;
			}
			else
			{
				aumentar = 26;
			}
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar);
				printf(" ");
				gotoxy(dis,aumentar+1);
				printf(" ");
				gotoxy(dis,aumentar+2);
				printf(" ");
			}
			gotoxy(30,aumentar+1);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			color(255,3);
			gotoxy(10,cont+4);
			printf(" %c 1. Agregar Menu   ",5);
			gotoxy(10,cont+7);
			printf(" %c 2. Eliminar Menu  ",5);
			gotoxy(46,cont+4);
			printf(" %c 3. Asistencia     ",5);
			gotoxy(46,cont+7);
			printf(" %c 4. Elija Menu     ",5);
			color(3,15);
			gotoxy(10,cont+14);
			printf("               ");
			gotoxy(10,cont+15);
			printf(" %c 5. Regresar ",27);
			gotoxy(10,cont+16);
			printf("               ");
			color(255,3);
			gotoxy(30,cont+14);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,cont+16);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,cont+16);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				if(contma<2)
				{
					ingresarmartes();
				}
				else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf("  Elimine un Menu para  ");
					gotoxy(54,cont+16);
					printf("   agregar uno nuevo    ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}
				break;

			case '2':
				eliminarmartes();

				break;
			case '3':
				if(totmartes1<=0)
				{
					asistenciamartes();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Ya se paso asistencias ");
					gotoxy(54,cont+16);
					printf("      Elija un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;

			case '4':
				if(totmartes1>0)
				{
					elejirmenumartes();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Pasar asistencias para ");
					gotoxy(54,cont+16);
					printf("     Elejir un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,cont+15);
				printf("%c",25);
				gotoxy(37,cont+16);
				printf("%c",26);
				gotoxy(41,cont+16);
				printf("%c",27);
				gotoxy(39,cont+17);
				printf("%c",24);
				gotoxy(30,cont+18);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,cont+18);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menusemana();
}//Fin menumartes
void menumiercoles()//Inicio menumiercoles
{
	char resp,op,dis;
	int aumentar, cont;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(7,16);
			printf("MENU DIA LUNES");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis
			//Muestra menu en pantalla pricipal del dia lunes
			color(3,3);
			gotoxy(0,18);
			printf("--------------------------------------------------------------------------------");
			color(3,15);
			gotoxy(0,19);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(0,20);
			color(3,3);
			printf("---------------------------------------------------------------------------------\n");
			color(255,1);
			for(k=0,cont=22;k<contmi;k++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%3d\t%-50s%-14s\n",k+1,ml[k].alimento2,ml[k].codigo2);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------\n");
			if(k>=0)
			{
				aumentar=cont+24;
			}
			else
			{
				aumentar = 26;
			}
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar);
				printf(" ");
				gotoxy(dis,aumentar+1);
				printf(" ");
				gotoxy(dis,aumentar+2);
				printf(" ");
			}
			gotoxy(30,aumentar+1);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			color(255,3);
			gotoxy(10,cont+4);
			printf(" %c 1. Agregar Menu   ",5);
			gotoxy(10,cont+7);
			printf(" %c 2. Eliminar Menu  ",5);
			gotoxy(46,cont+4);
			printf(" %c 3. Asistencia     ",5);
			gotoxy(46,cont+7);
			printf(" %c 4. Elija Menu     ",5);
			color(3,15);
			gotoxy(10,cont+14);
			printf("               ");
			gotoxy(10,cont+15);
			printf(" %c 5. Regresar ",27);
			gotoxy(10,cont+16);
			printf("               ");
			color(255,3);
			gotoxy(30,cont+14);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,cont+16);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,cont+16);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				if(contmi<2)
				{
					ingresarmiercoles();
				}
				else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf("  Elimine un Menu para  ");
					gotoxy(54,cont+16);
					printf("   agregar uno nuevo    ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}
				break;

			case '2':
				eliminarmiercoles();

				break;
			case '3':
				if(totmiercoles1<=0)
				{
					asistenciamiercoles();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Ya se paso asistencias ");
					gotoxy(54,cont+16);
					printf("      Elija un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;

			case '4':
				if(totmiercoles1>0)
				{
					elejirmenumiercoles();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Pasar asistencias para ");
					gotoxy(54,cont+16);
					printf("     Elejir un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,cont+15);
				printf("%c",25);
				gotoxy(37,cont+16);
				printf("%c",26);
				gotoxy(41,cont+16);
				printf("%c",27);
				gotoxy(39,cont+17);
				printf("%c",24);
				gotoxy(30,cont+18);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,cont+18);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menusemana();
}//Fin menumiercoles
void menujueves()//Inicio menujueves
{
	char resp,op,dis;
	int aumentar, cont;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(7,16);
			printf("MENU DIA LUNES");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis
			//Muestra menu en pantalla pricipal del dia lunes
			color(3,3);
			gotoxy(0,18);
			printf("--------------------------------------------------------------------------------");
			color(3,15);
			gotoxy(0,19);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(0,20);
			color(3,3);
			printf("---------------------------------------------------------------------------------\n");
			color(255,1);
			for(k=0,cont=22;k<contj;k++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%3d\t%-50s%-14s\n",k+1,jk[k].alimentos3,jk[k].codigos3);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------\n");
			if(k>=0)
			{
				aumentar=cont+24;
			}
			else
			{
				aumentar = 26;
			}
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar);
				printf(" ");
				gotoxy(dis,aumentar+1);
				printf(" ");
				gotoxy(dis,aumentar+2);
				printf(" ");
			}
			gotoxy(30,aumentar+1);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			color(255,3);
			gotoxy(10,cont+4);
			printf(" %c 1. Agregar Menu   ",5);
			gotoxy(10,cont+7);
			printf(" %c 2. Eliminar Menu  ",5);
			gotoxy(46,cont+4);
			printf(" %c 3. Asistencia     ",5);
			gotoxy(46,cont+7);
			printf(" %c 4. Elija Menu     ",5);
			color(3,15);
			gotoxy(10,cont+14);
			printf("               ");
			gotoxy(10,cont+15);
			printf(" %c 5. Regresar ",27);
			gotoxy(10,cont+16);
			printf("               ");
			color(255,3);
			gotoxy(30,cont+14);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,cont+16);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,cont+16);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				if(contj<3)
				{
					ingresarjueves();
				}
				else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf("  Elimine un Menu para  ");
					gotoxy(54,cont+16);
					printf("   agregar uno nuevo    ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}
				break;

			case '2':
				eliminarjueves();

				break;
			case '3':
				if(totjueves1<=0)
				{
					asistenciajueves();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Ya se paso asistencias ");
					gotoxy(54,cont+16);
					printf("      Elija un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;

			case '4':
				if(totjueves1>0)
				{
					elejirmenujueves();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Pasar asistencias para ");
					gotoxy(54,cont+16);
					printf("     Elejir un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,cont+15);
				printf("%c",25);
				gotoxy(37,cont+16);
				printf("%c",26);
				gotoxy(41,cont+16);
				printf("%c",27);
				gotoxy(39,cont+17);
				printf("%c",24);
				gotoxy(30,cont+18);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,cont+18);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menusemana();
}//Fin menujueves

void menuviernes()//Inicio menuviernes
{
	char resp,op,dis;
	int aumentar, cont;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(7,16);
			printf("MENU DIA LUNES");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis
			//Muestra menu en pantalla pricipal del dia lunes
			color(3,3);
			gotoxy(0,18);
			printf("--------------------------------------------------------------------------------");
			color(3,15);
			gotoxy(0,19);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(0,20);
			color(3,3);
			printf("---------------------------------------------------------------------------------\n");
			color(255,1);
			for(k=0,cont=22;k<contV;k++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%3d\t%-50s%-14s\n",k+1,v[k].alimento4,v[k].codigo4);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------\n");
			if(k>=0)
			{
				aumentar=cont+24;
			}
			else
			{
				aumentar = 26;
			}
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,aumentar);
				printf(" ");
				gotoxy(dis,aumentar+1);
				printf(" ");
				gotoxy(dis,aumentar+2);
				printf(" ");
			}
			gotoxy(30,aumentar+1);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			color(255,3);
			gotoxy(10,cont+4);
			printf(" %c 1. Agregar Menu   ",5);
			gotoxy(10,cont+7);
			printf(" %c 2. Eliminar Menu  ",5);
			gotoxy(46,cont+4);
			printf(" %c 3. Asistencia     ",5);
			gotoxy(46,cont+7);
			printf(" %c 4. Elija Menu     ",5);
			color(3,15);
			gotoxy(10,cont+14);
			printf("               ");
			gotoxy(10,cont+15);
			printf(" %c 5. Regresar ",27);
			gotoxy(10,cont+16);
			printf("               ");
			color(255,3);
			gotoxy(30,cont+14);
			printf(" %c Elija una opcion: ",16);
			gotoxy(20,33);

			for(int k=31;k<50;k++)
			{
				gotoxy(k,cont+16);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,cont+16);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				if(contV<2)
				{
					ingresarviernes();
				}
				else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf("  Elimine un Menu para  ");
					gotoxy(54,cont+16);
					printf("   agregar uno nuevo    ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}
				break;

			case '2':
				eliminarviernes();

				break;
			case '3':
				if(totviernes1<=0)
				{
					asistenciaviernes();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Ya se paso asistencias ");
					gotoxy(54,cont+16);
					printf("      Elija un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;

			case '4':
				if(totviernes1>0)
				{
					elejirmenuviernes();
				}else
				{
					color(5,255);
					gotoxy(54,cont+14);
					printf("                        ");
					gotoxy(54,cont+15);
					printf(" Pasar asistencias para ");
					gotoxy(54,cont+16);
					printf("     Elejir un Menu     ");
					gotoxy(54,cont+17);
					printf("                        ");
					system("pause>null");
				}	

				break;
			case '5':
		
				break;

			default:
				color(255,4);
				gotoxy(39,cont+15);
				printf("%c",25);
				gotoxy(37,cont+16);
				printf("%c",26);
				gotoxy(41,cont+16);
				printf("%c",27);
				gotoxy(39,cont+17);
				printf("%c",24);
				gotoxy(30,cont+18);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='5');//Fin do while op
		gotoxy(58,cont+18);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menusemana();
}//Fin menuviernes


//****************************************************************************************************************************************
//												FUNCIONES PARA LE MeNU DEL DIA LUNES
//****************************************************************************************************************************************
void ingresarlunes()//inicio ingresarproducto
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);

	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,26,79,2); // Dibuja recuadro principal
		sysbox(8,0,26,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,30);
			printf(" ");
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
		}
		gotoxy(30,31);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       AGREGAR MENU       ");
		color(255,3);
		gotoxy(13,13);
		printf("  N. MENU: ");
		gotoxy(9,16);
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=24;k<60;k++)
		{
			gotoxy(k,13);
			color(7,0);
			printf(" ");
		}//Fin for k

		//incio captura del MENU NUEVO
		do
		{
			gotoxy(24,13);
			fflush(stdin);
			color(7,0);
			//validacion del nombre del producto
			letras(menu,caracter);
	
			if(strlen(menu)<5)
			{
				color(255,12);
				gotoxy(13,13);
				printf("* N. MENU:");
				gotoxy(24,13);
				color(7,0);
				printf("                   ");
				va = false;
			}
			else
			{
				color(255,2);
				gotoxy(13,13);
				printf("  N. MENU:");
				va=true;
			}//Fin if

		}while(!va);//Fin do while va
		strupr(menu);//convierte a mayuscula
		
		//Verifica si ya existe un menu en existencia
		int ko;
		for(ko=0;ko<contL;ko++)
		{
			if (strcmp(strupr(menu),strupr(l[ko].alimento)) == 0)
			{
				repe=false;
				break;
			
			} 
			else 
			{
				repe = true;
			}//Fin if coomparacion
				
		}//Fin for ko
		//Generar  codigo del producto
		int j=0;
		char codig[50],nom;
		while(j<strlen(menu))
		{
			if(menu[j]!=32)
			{
				nom = menu[j];
				break;
			}
			else
			{
				nom = 'K';
			}
			j++;				
		}
		sprintf(codig,"%c%d%s",nom,contL1+1,anio);//concatena variables
		//Muestra el mensaje respectivo
		if(repe)
		{			
			strcpy(l[contL].alimento,menu);
			strcpy(l[contL].codigo,codig);
			contL++;
			contL1++;
			//mensaje
			color(4,255);
			gotoxy(14,15);
			printf("     ¡Excelente!.Menu Ingresado con éxito     ");
		}
		else
		{
				color(5,255);
				gotoxy(11,m+11);
				printf("        ¡Error!.Ya existe otro Menu.           ");	
		}//Fin if repe

		color(255,4);
		gotoxy(41,24);
		printf("   Registrar nuevo menu? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin fo while respuesta
	menulunes();
}//fin ingresarproducto

void eliminarlunes()//inicio eliminarproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char r,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int f,a;//para guardar los nuevos datos del producto encontrado y f para recorrer el for
	float sum=0;//para guardar los nuevos datos del producto encontrado
	bool va=false,repe=false,searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

	//INICIO DO WHILE
	do
	{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		//copyright(2,0);
////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(33,8);
		color(255,3);
		printf("MENUS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
		gotoxy(1,11);
		color(3,3);
		printf("--------------------------------------------------------------------------------\n");
		color(255,1);
		int aumentar,cont;
		for(a=0,cont=12;a<contL;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-50s%-14s\n",a+1,l[a].alimento,l[a].codigo);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+18;
		}
		else
		{
			aumentar = 26;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar);
			printf(" ");
			gotoxy(dis,aumentar+1);
			printf(" ");
			gotoxy(dis,aumentar+2);
			printf(" ");
		}
		gotoxy(30,aumentar+1);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(27,8);
		color(10,0);
		printf("    ELIMINAR MENU   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////

		for(int k=36;k<68;k++)//inicio for k que imprime cajitas 
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,cont+4);
		printf("  Codigo del Menu a Eliminar: ");
		do{               
			gotoxy(36,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);//captura carnet ingresado
			if(strlen(digit)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,cont+4);
				printf("* Codigo del Menu a Eliminar: ");
				gotoxy(36,cont+4);
				color(7,0);
				printf("          ");
				searchv=false;
			}
			else
			{
				color(255,2);
				gotoxy(6,cont+4);
				printf("  Codigo del Menu a Eliminar: ");
				searchv=true;
			}//Fin if search 
		}while(!searchv);
		int b,posicion;//variables que serviran para identificar en que posicion esta el producto, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
		//Verifica si ya existe un producto
		for(b=1;b<contL;b++)
		{
			if ((strcmp(strupr(digit),strupr(l[b].codigo)) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
			{
				existe=true;
				posicion = b;
				break;
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion	
		}//Fin for ko
		if(existe)
		{
			color(255,2);
			gotoxy(10,cont+6);
			printf("      Desea eliminar el Menu? (S/N):  ");
			color(255,4);
			r= getch();
			if(toupper(r)=='S')
			{
				for(f = posicion;f<contL;f++)
				{
					strcpy(l[f].alimento,l[f+1].alimento);
					strcpy(l[f].codigo,l[f+1].codigo);
							
				}//Fin for F
				contL--;//dejar inexistente la posicion eliminada pero no vacia
				color(3,255);
				gotoxy(14,cont+8);
				printf("     ¡Excelente!.Menu Eliminado con exito     ");
			}
			else
			{
				color(5,255);
				gotoxy(14,cont+7);
				printf("     ¡Error!.Menu no eliminado            ");
					
			}//Fin respuesta y copiar los datos
		}
		else
		{
			gotoxy(14,cont+6);
			color(5,255);
			printf("                                       ");
			gotoxy(14,cont+7);
			printf("      ¡Error!.Menu no encontrado.      ");
			gotoxy(14,cont+8);                                      
			printf("                                       ");
		}//Fin if buscar estudiante
		color(255,4);
		gotoxy(30,cont+12);
		printf("Desea eliminar  o intentar otra vez? (S/N):");
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta
	menulunes();
}//fin eliminarmenu


void asistencialunes()
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	int totlunes=0;
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);
	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,35,79,2); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,39);
			printf(" ");
			gotoxy(dis,40);
			printf(" ");
			gotoxy(dis,41);
			printf(" ");
		}
		gotoxy(30,40);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       ASISTENCIA DIA LUNES      ");
		color(3,15);
		gotoxy(1,9);
		printf("                                                                                ");
		gotoxy(1,10);
		printf("                        ASISTENCIA POR CADA SECCION                             ");
		gotoxy(1,11);
		printf("                                                                                ");
		color(255,3);
		gotoxy(5,15);
		printf("  1° GRADO: ");
		gotoxy(5,17);
		printf("  2° GRADO: ");
		gotoxy(5,19);
		printf("  3° GRADO: ");
		gotoxy(5,21);
		printf("  4° GRADO: ");
		gotoxy(5,23);
		printf("  5° GRADO: ");
		gotoxy(5,25);
		printf("  6° GRADO: ");
		gotoxy(5,27);
		printf("  7° GRADO: ");
		gotoxy(5,29);
		printf("  8° GRADO: ");
		gotoxy(5,31);
		printf("  9° GRADO: ");
		color(3,15);
		gotoxy(45,19);
		printf("                 ");
		gotoxy(45,20);
		printf("  TOTAL ALUMNOS: ");
		gotoxy(45,21);
		printf("                 ");
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=17;k<25;k++)
		{
			color(7,0);
			gotoxy(k,15);
			printf(" ");
			gotoxy(k,17);
			printf(" ");
			gotoxy(k,19);
			printf(" ");
			gotoxy(k,21);
			printf(" ");
			gotoxy(k,23);
			printf(" ");
			gotoxy(k,25);
			printf(" ");
			gotoxy(k,27);
			printf(" ");
			gotoxy(k,29);
			printf(" ");
			gotoxy(k,31);
			printf(" ");
		}//Fin for k
		gotoxy(45,23);
		color(7,0);
		printf("                 ");

		//incio captura del MENU NUEVO
		totlunes=0;
		do
		{
			do
			{
				gotoxy(20,15);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l1);//variable que captura la cantidad
	
				if(l1<0 || l1>contN)
				{
					color(255,12);
					gotoxy(5,15);
					printf("* 1° GRADO: ");
					gotoxy(17,15);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,15);
					printf("  1° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l1<0 || l1>contN && contN<0);
		gotoxy(53,23);
		color(7,0);
		totlunes+=l1;
		printf("%d",totlunes);

		do
		{
			do
			{
				gotoxy(20,17);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l2);//variable que captura la cantidad
	
				if(l2<0 || l2>contN1)
				{
					color(255,12);
					gotoxy(5,17);
					printf("* 2° GRADO: ");
					gotoxy(17,17);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,17);
					printf("  2° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l2<0 || l2>contN1 && contN1<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l2;
		printf("%d",totlunes);

		do
		{
			do
			{
				gotoxy(20,19);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l3);//variable que captura la cantidad
	
				if(l3<0 || l3>contN2)
				{
					color(255,12);
					gotoxy(5,19);
					printf("* 3° GRADO: ");
					gotoxy(17,19);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,19);
					printf("  3° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l3<0 || l3>contN2 && contN2<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l3;
		printf("%d",totlunes);

		do
		{
			do
			{
				gotoxy(20,21);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l4);//variable que captura la cantidad
	
				if(l4<0 || l4>contN3)
				{
					color(255,12);
					gotoxy(5,21);
					printf("* 4° GRADO: ");
					gotoxy(17,21);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,21);
					printf("  4° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l4<0 || l4>contN3 && contN3<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l4;
		printf("%d",totlunes);

		do
		{
			do
			{
				gotoxy(20,23);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l5);//variable que captura la cantidad
	
				if(l5<0 || l5>contN4)
				{
					color(255,12);
					gotoxy(5,23);
					printf("* 5° GRADO: ");
					gotoxy(17,23);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,23);
					printf("  5° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l5<0 || l5>contN4 && contN4<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l5;
		printf("%d",totlunes);

		do
		{
			do
			{
				gotoxy(20,25);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l6);//variable que captura la cantidad
	
				if(l6<0 || l6>contN5)
				{
					color(255,12);
					gotoxy(5,25);
					printf("* 6° GRADO: ");
					gotoxy(17,25);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,25);
					printf("  6° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l6<0 || l6>contN5 && contN5<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l6;
		printf("%d",totlunes);

		do
		{
			do
			{
				gotoxy(20,27);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l7);//variable que captura la cantidad
	
				if(l7<0 || l7>contN6)
				{
					color(255,12);
					gotoxy(5,27);
					printf("* 7° GRADO: ");
					gotoxy(17,27);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,27);
					printf("  7° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l7<0 || l7>contN6 && contN6<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l7;
		printf("%d",totlunes);

		do
		{
			do
			{
				gotoxy(20,29);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l8);//variable que captura la cantidad
	
				if(l8<0 || l8>contN7)
				{
					color(255,12);
					gotoxy(5,29);
					printf("* 8° GRADO: ");
					gotoxy(17,29);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,29);
					printf("  8° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l8<0 || l8>contN7 && contN7<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l8;
		printf("%d",totlunes);
		do
		{
			do
			{
				gotoxy(20,31);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&l9);//variable que captura la cantidad
	
				if(l9<0 || l9>contN8)
				{
					color(255,12);
					gotoxy(5,31);
					printf("* 9° GRADO: ");
					gotoxy(17,31);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,31);
					printf("  9° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(l9<0 || l9>contN8 && contN8<0);
		//calculo del total de alumnos
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totlunes+=l9;
		totlunes1=totlunes;
		printf("%d",totlunes1);
		color(255,4);
		gotoxy(58,32);
		printf("   Regresar? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	menulunes();
}
void elejirmenu()//inicio elejirmenu
{
	char dis,resp;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(0,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			color(5,255);
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis
			gotoxy(8,16);
			printf("ELEJIR MENU");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");
			encabezado();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			color(3,15);
			gotoxy(10,21);
			printf("               ",5);
			gotoxy(10,22);
			printf(" %c 1. Opción 1 ",5);
			gotoxy(10,23);
			printf("               ",5);
			gotoxy(32,21);
			printf("               ",5);
			gotoxy(32,22);
			printf(" %c 2. Opción 2 ",5);
			gotoxy(32,23);
			printf("               ",5);
			gotoxy(53,21);
			printf("               ",5);
			gotoxy(53,22);
			printf(" %c 3. Opción 3 ",5);
			gotoxy(53,23);
			printf("               ",5);
			gotoxy(10,32);
			color(3,15);
			printf("             ");
			gotoxy(10,33);
			printf("%c 5. Regresar",27);
			gotoxy(10,34);
			printf("             ");
			color(255,3);
			gotoxy(30,32);
			printf("%cElija una opción: ",16);
			for(dis=30;dis<48;dis++)
			{
				color(7,0);
				gotoxy(dis,34);
				printf(" ");
			}
			gotoxy(39,34);
			opmenu=getch();//lee op
			switch(opmenu)
			{
				case '1':
					if(opmenu!='1')
					{
						totlunes1=0;
						opcion1();
						opcion2();
						opcion3();
					}else
					{
						if(opmenu!='1')
						{
							totlunes1=0;
							opcion1();
						}
						else
						{
							opcion1();
						}
						
					}
					
					break;
				
				case '2':
					if(opmenu!='2')
					{
						totlunes1=0;
						opcion1();
						opcion2();
						opcion3();
					}else
					{
						if(opmenu!='2')
						{
							totlunes1=0;
						}
						opcion2();
					}

					break;
				case '3':
					if(opmenu!='3')
					{
						totlunes1=0;
						opcion1();
						opcion2();
						opcion3();
					}else
					{
						if(opmenu!='3')
						{
							totlunes1=0;
						}
						opcion3();
					}

					break;

				case '4':

					break;
				case '5':

					break;
				default:
					color(255,4);
					gotoxy(39,33);
					printf("%c",25);
					gotoxy(37,34);
					printf("%c",26);
					gotoxy(41,34);
					printf("%c",27);
					gotoxy(39,35);
					printf("%c",24);
					gotoxy(30,36);			
					printf("%c Opción incorrecta.",16);
					Sleep(500);
			}//Fin switch op
		}while(opmenu !='5');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menulunes();//regresa al menu anterior

}//fin elejirmenu
void opcion1()//inicio opcion1
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total=totlunes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="LECHE", bus2[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			p1=0;
			p2=0;
			p3=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0,cont=12;a<contL-2;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,l[a].alimento,l[a].codigo);
				strcpy(search,l[a].codigo);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contL;b++)
			{
				if ((strcmp(strupr(search),strupr(l[b].codigo)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total);
				//calculo de raciones por el total de alumnos
				p1=total*arroz;
				p2=total*leche;
				p3=total*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",p1);
				gotoxy(19,20);
				printf("%.2f",p2);
				gotoxy(19,22);
				printf("%.2f",p3);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(10,20);
				printf("LECHE: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=p1;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-p1;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=p2;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-p2;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=p3;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-p3;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior
}//fin opcion1
void opcion2()//inicio opcion2
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total2=totlunes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="LECHE", bus2[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			p1=0;
			p2=0;
			p3=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0+1,cont=12;a<contL-1;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,l[a].alimento,l[a].codigo);
				strcpy(search,l[a].codigo);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contL;b++)
			{
				if ((strcmp(strupr(search),strupr(l[b].codigo)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total2);
				//calculo de raciones por el total de alumnos
				p4=total2*arroz;
				p5=total2*leche;
				p6=total2*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",p4);
				gotoxy(19,20);
				printf("%.2f",p5);
				gotoxy(19,22);
				printf("%.2f",p6);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(10,20);
				printf("LECHE: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=p4;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-p4;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=p5;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-p5;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=p6;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-p6;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior

}//fin opcion2
void opcion3()//inicio opcion3
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total3=totlunes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="FRIJOLES";//variables para buscar y disminuir cantidad al inventario
	do
		{
			p1=0;
			p2=0;
			p3=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0+1,cont=12;a<contL-1;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,l[a].alimento,l[a].codigo);
				strcpy(search,l[a].codigo);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contL;b++)
			{
				if ((strcmp(strupr(search),strupr(l[b].codigo)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total3);
				//calculo de raciones por el total de alumnos
				p7=total3*arroz;
				p8=total3*frijoles;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",p7);
				gotoxy(19,20);
				printf("%.2f",p8);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(7,20);
				printf("FRIJOLES: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=p7;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-p7;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=p8;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-p8;
					pro[o].cant=pro[o].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior

}//fin opcion3








//
void ingresarmartes()//inicio ingresarproducto
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);

	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,26,79,2); // Dibuja recuadro principal
		sysbox(8,0,26,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,30);
			printf(" ");
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
		}
		gotoxy(30,31);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       AGREGAR MENU       ");
		color(255,3);
		gotoxy(13,13);
		printf("  N. MENU: ");
		gotoxy(9,16);
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=24;k<60;k++)
		{
			gotoxy(k,13);
			color(7,0);
			printf(" ");
		}//Fin for k

		//incio captura del MENU NUEVO
		do
		{
			gotoxy(24,13);
			fflush(stdin);
			color(7,0);
			//validacion del nombre del producto
			letras(menu,caracter);
	
			if(strlen(menu)<5)
			{
				color(255,12);
				gotoxy(13,13);
				printf("* N. MENU:");
				gotoxy(24,13);
				color(7,0);
				printf("                   ");
				va = false;
			}
			else
			{
				color(255,2);
				gotoxy(13,13);
				printf("  N. MENU:");
				va=true;
			}//Fin if

		}while(!va);//Fin do while va
		strupr(menu);//convierte a mayuscula
		
		//Verifica si ya existe un menu en existencia
		int ko;
		for(ko=0;ko<contma;ko++)
		{
			if (strcmp(strupr(menu),strupr(d[ko].alimento1)) == 0)
			{
				repe=false;
				break;
			
			} 
			else 
			{
				repe = true;
			}//Fin if coomparacion
				
		}//Fin for ko
		//Generar  codigo del producto
		int j=0;
		char codig[50],nom;
		while(j<strlen(menu))
		{
			if(menu[j]!=32)
			{
				nom = menu[j];
				break;
			}
			else
			{
				nom = 'K';
			}
			j++;				
		}
		sprintf(codig,"%c%d%s",nom,contma1+1,anio);//concatena variables
		//Muestra el mensaje respectivo
		if(repe)
		{			
			strcpy(d[contma].alimento1,menu);
			strcpy(d[contma].codigo1,codig);
			contma++;
			contma1++;
			//mensaje
			color(4,255);
			gotoxy(14,15);
			printf("     ¡Excelente!.Menu Ingresado con éxito     ");
		}
		else
		{
				color(5,255);
				gotoxy(11,m+11);
				printf("        ¡Error!.Ya existe otro Menu.           ");	
		}//Fin if repe

		color(255,4);
		gotoxy(41,24);
		printf("   Registrar nuevo menu? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin fo while respuesta
	menulunes();
}//fin ingresarproducto

void eliminarmartes()//inicio eliminarproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char r,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int f,a;//para guardar los nuevos datos del producto encontrado y f para recorrer el for
	float sum=0;//para guardar los nuevos datos del producto encontrado
	bool va=false,repe=false,searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

	//INICIO DO WHILE
	do
	{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		//copyright(2,0);
////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(33,8);
		color(255,3);
		printf("MENUS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
		gotoxy(1,11);
		color(3,3);
		printf("--------------------------------------------------------------------------------\n");
		color(255,1);
		int aumentar,cont;
		for(a=0,cont=12;a<contma;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-50s%-14s\n",a+1,d[a].alimento1,d[a].codigo1);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+18;
		}
		else
		{
			aumentar = 26;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar);
			printf(" ");
			gotoxy(dis,aumentar+1);
			printf(" ");
			gotoxy(dis,aumentar+2);
			printf(" ");
		}
		gotoxy(30,aumentar+1);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(27,8);
		color(10,0);
		printf("    ELIMINAR MENU   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////

		for(int k=36;k<68;k++)//inicio for k que imprime cajitas 
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,cont+4);
		printf("  Codigo del Menu a Eliminar: ");
		do{               
			gotoxy(36,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);//captura carnet ingresado
			if(strlen(digit)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,cont+4);
				printf("* Codigo del Menu a Eliminar: ");
				gotoxy(36,cont+4);
				color(7,0);
				printf("          ");
				searchv=false;
			}
			else
			{
				color(255,2);
				gotoxy(6,cont+4);
				printf("  Codigo del Menu a Eliminar: ");
				searchv=true;
			}//Fin if search 
		}while(!searchv);
		int b,posicion;//variables que serviran para identificar en que posicion esta el producto, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
		//Verifica si ya existe un producto
		for(b=1;b<contma;b++)
		{
			if ((strcmp(strupr(digit),strupr(d[b].codigo1)) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
			{
				existe=true;
				posicion = b;
				break;
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion	
		}//Fin for ko
		if(existe)
		{
			color(255,2);
			gotoxy(10,cont+6);
			printf("      Desea eliminar el Menu? (S/N):  ");
			color(255,4);
			r= getch();
			if(toupper(r)=='S')
			{
				for(f = posicion;f<contma;f++)
				{
					strcpy(d[f].alimento1,d[f+1].alimento1);
					strcpy(d[f].codigo1,d[f+1].codigo1);
							
				}//Fin for F
				contma--;//dejar inexistente la posicion eliminada pero no vacia
				color(3,255);
				gotoxy(14,cont+8);
				printf("     ¡Excelente!.Menu Eliminado con exito     ");
			}
			else
			{
				color(5,255);
				gotoxy(14,cont+7);
				printf("     ¡Error!.Menu no eliminado            ");
					
			}//Fin respuesta y copiar los datos
		}
		else
		{
			gotoxy(14,cont+6);
			color(5,255);
			printf("                                       ");
			gotoxy(14,cont+7);
			printf("      ¡Error!.Menu no encontrado.      ");
			gotoxy(14,cont+8);                                      
			printf("                                       ");
		}//Fin if buscar estudiante
		color(255,4);
		gotoxy(30,cont+12);
		printf("Desea eliminar  o intentar otra vez? (S/N):");
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta
	menulunes();
}//fin eliminarmenu


void asistenciamartes()
{
	char res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	int totmartes=0;
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);
	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,35,79,2); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,39);
			printf(" ");
			gotoxy(dis,40);
			printf(" ");
			gotoxy(dis,41);
			printf(" ");
		}
		gotoxy(30,40);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       ASISTENCIA DIA LUNES      ");
		color(3,15);
		gotoxy(1,9);
		printf("                                                                                ");
		gotoxy(1,10);
		printf("                        ASISTENCIA POR CADA SECCION                             ");
		gotoxy(1,11);
		printf("                                                                                ");
		color(255,3);
		gotoxy(5,15);
		printf("  1° GRADO: ");
		gotoxy(5,17);
		printf("  2° GRADO: ");
		gotoxy(5,19);
		printf("  3° GRADO: ");
		gotoxy(5,21);
		printf("  4° GRADO: ");
		gotoxy(5,23);
		printf("  5° GRADO: ");
		gotoxy(5,25);
		printf("  6° GRADO: ");
		gotoxy(5,27);
		printf("  7° GRADO: ");
		gotoxy(5,29);
		printf("  8° GRADO: ");
		gotoxy(5,31);
		printf("  9° GRADO: ");
		color(3,15);
		gotoxy(45,19);
		printf("                 ");
		gotoxy(45,20);
		printf("  TOTAL ALUMNOS: ");
		gotoxy(45,21);
		printf("                 ");
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=17;k<25;k++)
		{
			color(7,0);
			gotoxy(k,15);
			printf(" ");
			gotoxy(k,17);
			printf(" ");
			gotoxy(k,19);
			printf(" ");
			gotoxy(k,21);
			printf(" ");
			gotoxy(k,23);
			printf(" ");
			gotoxy(k,25);
			printf(" ");
			gotoxy(k,27);
			printf(" ");
			gotoxy(k,29);
			printf(" ");
			gotoxy(k,31);
			printf(" ");
		}//Fin for k
		gotoxy(45,23);
		color(7,0);
		printf("                 ");

		//incio captura del MENU NUEVO
		totmartes=0;
		do
		{
			do
			{
				gotoxy(20,15);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma1);//variable que captura la cantidad
	
				if(ma1<0 || ma1>contN)
				{
					color(255,12);
					gotoxy(5,15);
					printf("* 1° GRADO: ");
					gotoxy(17,15);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,15);
					printf("  1° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma1<0 || ma1>contN && contN<0);
		gotoxy(53,23);
		color(7,0);
		totmartes+=l1;
		printf("%d",totmartes);

		do
		{
			do
			{
				gotoxy(20,17);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma2);//variable que captura la cantidad
	
				if(ma2<0 || ma2>contN1)
				{
					color(255,12);
					gotoxy(5,17);
					printf("* 2° GRADO: ");
					gotoxy(17,17);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,17);
					printf("  2° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma2<0 || ma2>contN1 && contN1<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=ma2;
		printf("%d",totmartes);

		do
		{
			do
			{
				gotoxy(20,19);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma3);//variable que captura la cantidad
	
				if(ma3<0 || ma3>contN2)
				{
					color(255,12);
					gotoxy(5,19);
					printf("* 3° GRADO: ");
					gotoxy(17,19);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,19);
					printf("  3° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma3<0 || ma3>contN2 && contN2<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=l3;
		printf("%d",totmartes);

		do
		{
			do
			{
				gotoxy(20,21);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma4);//variable que captura la cantidad
	
				if(ma4<0 || ma4>contN3)
				{
					color(255,12);
					gotoxy(5,21);
					printf("* 4° GRADO: ");
					gotoxy(17,21);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,21);
					printf("  4° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma4<0 || ma4>contN3 && contN3<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=ma4;
		printf("%d",totmartes);

		do
		{
			do
			{
				gotoxy(20,23);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma5);//variable que captura la cantidad
	
				if(ma5<0 || ma5>contN4)
				{
					color(255,12);
					gotoxy(5,23);
					printf("* 5° GRADO: ");
					gotoxy(17,23);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,23);
					printf("  5° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma5<0 || ma5>contN4 && contN4<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=ma5;
		printf("%d",totmartes);

		do
		{
			do
			{
				gotoxy(20,25);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma6);//variable que captura la cantidad
	
				if(ma6<0 || ma6>contN5)
				{
					color(255,12);
					gotoxy(5,25);
					printf("* 6° GRADO: ");
					gotoxy(17,25);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,25);
					printf("  6° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma6<0 || ma6>contN5 && contN5<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=ma6;
		printf("%d",totmartes);

		do
		{
			do
			{
				gotoxy(20,27);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma7);//variable que captura la cantidad
	
				if(ma7<0 || ma7>contN6)
				{
					color(255,12);
					gotoxy(5,27);
					printf("* 7° GRADO: ");
					gotoxy(17,27);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,27);
					printf("  7° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma7<0 || ma7>contN6 && contN6<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=ma7;
		printf("%d",totmartes);

		do
		{
			do
			{
				gotoxy(20,29);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma8);//variable que captura la cantidad
	
				if(ma8<0 || ma8>contN7)
				{
					color(255,12);
					gotoxy(5,29);
					printf("* 8° GRADO: ");
					gotoxy(17,29);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,29);
					printf("  8° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma8<0 || ma8>contN7 && contN7<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=ma8;
		printf("%d",totmartes);
		do
		{
			do
			{
				gotoxy(20,31);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&ma9);//variable que captura la cantidad
	
				if(ma9<0 || ma9>contN8)
				{
					color(255,12);
					gotoxy(5,31);
					printf("* 9° GRADO: ");
					gotoxy(17,31);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,31);
					printf("  9° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(ma9<0 || ma9>contN8 && contN8<0);
		//calculo del total de alumnos
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmartes+=ma9;
		totmartes1=totmartes;
		printf("%d",totmartes1);
		color(255,4);
		gotoxy(58,32);
		printf("   Regresar? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	menulunes();
}
void elejirmenumartes()//inicio elejirmenu
{
	char dis,resp,op;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(0,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			color(5,255);
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis
			gotoxy(8,16);
			printf("ELEJIR MENU");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");
			encabezado();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			color(3,15);
			gotoxy(10,21);
			printf("               ",5);
			gotoxy(10,22);
			printf(" %c 1. Opción 1 ",5);
			gotoxy(10,23);
			printf("               ",5);
			gotoxy(32,21);
			printf("               ",5);
			gotoxy(32,22);
			printf(" %c 2. Opción 2 ",5);
			gotoxy(32,23);
			printf("               ",5);
			gotoxy(10,32);
			color(3,15);
			printf("             ");
			gotoxy(10,33);
			printf("%c 5. Regresar",27);
			gotoxy(10,34);
			printf("             ");
			color(255,3);
			gotoxy(30,32);
			printf("%cElija una opción: ",16);
			for(dis=30;dis<48;dis++)
			{
				color(7,0);
				gotoxy(dis,34);
				printf(" ");
			}
			gotoxy(39,34);
			op=getch();//lee op
			switch(opmenu)
			{
				case '1':
					if(op!='1')
					{
						totmartes1=0;
						opcion12();
						opcion22();
					}else
					{
						if(op!='1')
						{
							totmartes1=0;
							opcion12();
						}
						else
						{
							opcion12();
						}
						
					}
					
					break;
				
				case '2':
					if(op!='2')
					{
						totmartes1=0;
						opcion12();
						opcion22();
					}else
					{
						if(op!='2')
						{
							totmartes1=0;
						}
						opcion22();
					}

					break;
				case '3':

					break;

				case '4':

					break;
				case '5':

					break;
				default:
					color(255,4);
					gotoxy(39,33);
					printf("%c",25);
					gotoxy(37,34);
					printf("%c",26);
					gotoxy(41,34);
					printf("%c",27);
					gotoxy(39,35);
					printf("%c",24);
					gotoxy(30,36);			
					printf("%c Opción incorrecta.",16);
					Sleep(500);
			}//Fin switch op
		}while(opmenu !='5');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menulunes();//regresa al menu anterior

}//fin elejirmenu
void opcion12()//inicio opcion1
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total=totmartes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="LECHE", bus2[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pd1=0;
			pd2=0;
			pd3=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0,cont=12;a<contma-2;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,d[a].alimento1,d[a].codigo1);
				strcpy(search,d[a].codigo1);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contma;b++)
			{
				if ((strcmp(strupr(search),strupr(d[b].codigo1)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total);
				//calculo de raciones por el total de alumnos
				pd1=total*arroz;
				pd2=total*leche;
				pd3=total*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pd1);
				gotoxy(19,20);
				printf("%.2f",pd2);
				gotoxy(19,22);
				printf("%.2f",pd3);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(10,20);
				printf("LECHE: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pd1;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pd1;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pd2;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pd2;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pd3;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pd3;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior
}//fin opcion1
void opcion22()//inicio opcion2
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total2=totmartes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="LECHE", bus2[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pd4=0;
			pd5=0;
			pd6=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0+1,cont=12;a<contma-1;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,d[a].alimento1,d[a].codigo1);
				strcpy(search,d[a].codigo1);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contma;b++)
			{
				if ((strcmp(strupr(search),strupr(d[b].codigo1)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total2);
				//calculo de raciones por el total de alumnos
				pd4=total2*arroz;
				pd5=total2*leche;
				pd6=total2*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pd4);
				gotoxy(19,20);
				printf("%.2f",pd5);
				gotoxy(19,22);
				printf("%.2f",pd6);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(10,20);
				printf("LECHE: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pd4;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pd4;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pd5;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pd5;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pd6;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pd6;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior

}//fin opcion2




//
void ingresarmiercoles()//inicio ingresarproducto
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);

	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,26,79,2); // Dibuja recuadro principal
		sysbox(8,0,26,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,30);
			printf(" ");
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
		}
		gotoxy(30,31);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       AGREGAR MENU       ");
		color(255,3);
		gotoxy(13,13);
		printf("  N. MENU: ");
		gotoxy(9,16);
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=24;k<60;k++)
		{
			gotoxy(k,13);
			color(7,0);
			printf(" ");
		}//Fin for k

		//incio captura del MENU NUEVO
		do
		{
			gotoxy(24,13);
			fflush(stdin);
			color(7,0);
			//validacion del nombre del producto
			letras(menu,caracter);
	
			if(strlen(menu)<5)
			{
				color(255,12);
				gotoxy(13,13);
				printf("* N. MENU:");
				gotoxy(24,13);
				color(7,0);
				printf("                   ");
				va = false;
			}
			else
			{
				color(255,2);
				gotoxy(13,13);
				printf("  N. MENU:");
				va=true;
			}//Fin if

		}while(!va);//Fin do while va
		strupr(menu);//convierte a mayuscula
		
		//Verifica si ya existe un menu en existencia
		int ko;
		for(ko=0;ko<contmi;ko++)
		{
			if (strcmp(strupr(menu),strupr(ml[ko].alimento2)) == 0)
			{
				repe=false;
				break;
			
			} 
			else 
			{
				repe = true;
			}//Fin if coomparacion
				
		}//Fin for ko
		//Generar  codigo del producto
		int j=0;
		char codig[50],nom;
		while(j<strlen(menu))
		{
			if(menu[j]!=32)
			{
				nom = menu[j];
				break;
			}
			else
			{
				nom = 'K';
			}
			j++;				
		}
		sprintf(codig,"%c%d%s",nom,contmi1+1,anio);//concatena variables
		//Muestra el mensaje respectivo
		if(repe)
		{			
			strcpy(ml[contmi].alimento2,menu);
			strcpy(ml[contmi].codigo2,codig);
			contmi++;
			contmi1++;
			//mensaje
			color(4,255);
			gotoxy(14,15);
			printf("     ¡Excelente!.Menu Ingresado con éxito     ");
		}
		else
		{
				color(5,255);
				gotoxy(11,m+11);
				printf("        ¡Error!.Ya existe otro Menu.           ");	
		}//Fin if repe

		color(255,4);
		gotoxy(41,24);
		printf("   Registrar nuevo menu? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin fo while respuesta
	menulunes();
}//fin ingresarproducto

void eliminarmiercoles()//inicio eliminarproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char r,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int f,a;//para guardar los nuevos datos del producto encontrado y f para recorrer el for
	float sum=0;//para guardar los nuevos datos del producto encontrado
	bool va=false,repe=false,searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

	//INICIO DO WHILE
	do
	{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		//copyright(2,0);
////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(33,8);
		color(255,3);
		printf("MENUS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
		gotoxy(1,11);
		color(3,3);
		printf("--------------------------------------------------------------------------------\n");
		color(255,1);
		int aumentar,cont;
		for(a=0,cont=12;a<contmi;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-50s%-14s\n",a+1,ml[a].alimento2,ml[a].codigo2);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+18;
		}
		else
		{
			aumentar = 26;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar);
			printf(" ");
			gotoxy(dis,aumentar+1);
			printf(" ");
			gotoxy(dis,aumentar+2);
			printf(" ");
		}
		gotoxy(30,aumentar+1);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(27,8);
		color(10,0);
		printf("    ELIMINAR MENU   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////

		for(int k=36;k<68;k++)//inicio for k que imprime cajitas 
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,cont+4);
		printf("  Codigo del Menu a Eliminar: ");
		do{               
			gotoxy(36,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);//captura carnet ingresado
			if(strlen(digit)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,cont+4);
				printf("* Codigo del Menu a Eliminar: ");
				gotoxy(36,cont+4);
				color(7,0);
				printf("          ");
				searchv=false;
			}
			else
			{
				color(255,2);
				gotoxy(6,cont+4);
				printf("  Codigo del Menu a Eliminar: ");
				searchv=true;
			}//Fin if search 
		}while(!searchv);
		int b,posicion;//variables que serviran para identificar en que posicion esta el producto, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
		//Verifica si ya existe un producto
		for(b=1;b<contmi;b++)
		{
			if ((strcmp(strupr(digit),strupr(ml[b].alimento2)) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
			{
				existe=true;
				posicion = b;
				break;
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion	
		}//Fin for ko
		if(existe)
		{
			color(255,2);
			gotoxy(10,cont+6);
			printf("      Desea eliminar el Menu? (S/N):  ");
			color(255,4);
			r= getch();
			if(toupper(r)=='S')
			{
				for(f = posicion;f<contmi;f++)
				{
					strcpy(ml[f].alimento2,ml[f+1].alimento2);
					strcpy(ml[f].codigo2,ml[f+1].codigo2);
							
				}//Fin for F
				contmi--;//dejar inexistente la posicion eliminada pero no vacia
				color(3,255);
				gotoxy(14,cont+8);
				printf("     ¡Excelente!.Menu Eliminado con exito     ");
			}
			else
			{
				color(5,255);
				gotoxy(14,cont+7);
				printf("     ¡Error!.Menu no eliminado            ");
					
			}//Fin respuesta y copiar los datos
		}
		else
		{
			gotoxy(14,cont+6);
			color(5,255);
			printf("                                       ");
			gotoxy(14,cont+7);
			printf("      ¡Error!.Menu no encontrado.      ");
			gotoxy(14,cont+8);                                      
			printf("                                       ");
		}//Fin if buscar estudiante
		color(255,4);
		gotoxy(30,cont+12);
		printf("Desea eliminar  o intentar otra vez? (S/N):");
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta
	menulunes();
}//fin eliminarmenu


void asistenciamiercoles()
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	int totmiercoles=0;
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);
	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,35,79,2); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,39);
			printf(" ");
			gotoxy(dis,40);
			printf(" ");
			gotoxy(dis,41);
			printf(" ");
		}
		gotoxy(30,40);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       ASISTENCIA DIA LUNES      ");
		color(3,15);
		gotoxy(1,9);
		printf("                                                                                ");
		gotoxy(1,10);
		printf("                        ASISTENCIA POR CADA SECCION                             ");
		gotoxy(1,11);
		printf("                                                                                ");
		color(255,3);
		gotoxy(5,15);
		printf("  1° GRADO: ");
		gotoxy(5,17);
		printf("  2° GRADO: ");
		gotoxy(5,19);
		printf("  3° GRADO: ");
		gotoxy(5,21);
		printf("  4° GRADO: ");
		gotoxy(5,23);
		printf("  5° GRADO: ");
		gotoxy(5,25);
		printf("  6° GRADO: ");
		gotoxy(5,27);
		printf("  7° GRADO: ");
		gotoxy(5,29);
		printf("  8° GRADO: ");
		gotoxy(5,31);
		printf("  9° GRADO: ");
		color(3,15);
		gotoxy(45,19);
		printf("                 ");
		gotoxy(45,20);
		printf("  TOTAL ALUMNOS: ");
		gotoxy(45,21);
		printf("                 ");
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=17;k<25;k++)
		{
			color(7,0);
			gotoxy(k,15);
			printf(" ");
			gotoxy(k,17);
			printf(" ");
			gotoxy(k,19);
			printf(" ");
			gotoxy(k,21);
			printf(" ");
			gotoxy(k,23);
			printf(" ");
			gotoxy(k,25);
			printf(" ");
			gotoxy(k,27);
			printf(" ");
			gotoxy(k,29);
			printf(" ");
			gotoxy(k,31);
			printf(" ");
		}//Fin for k
		gotoxy(45,23);
		color(7,0);
		printf("                 ");

		//incio captura del MENU NUEVO
		totmiercoles=0;
		do
		{
			do
			{
				gotoxy(20,15);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi1);//variable que captura la cantidad
	
				if(mi1<0 || mi1>contN)
				{
					color(255,12);
					gotoxy(5,15);
					printf("* 1° GRADO: ");
					gotoxy(17,15);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,15);
					printf("  1° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi1<0 || mi1>contN && contN<0);
		gotoxy(53,23);
		color(7,0);
		totmiercoles+=mi1;
		printf("%d",totmiercoles);

		do
		{
			do
			{
				gotoxy(20,17);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi2);//variable que captura la cantidad
	
				if(mi2<0 || mi2>contN1)
				{
					color(255,12);
					gotoxy(5,17);
					printf("* 2° GRADO: ");
					gotoxy(17,17);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,17);
					printf("  2° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi2<0 || mi2>contN1 && contN1<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi2;
		printf("%d",totmiercoles);

		do
		{
			do
			{
				gotoxy(20,19);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi3);//variable que captura la cantidad
	
				if(mi3<0 || mi3>contN2)
				{
					color(255,12);
					gotoxy(5,19);
					printf("* 3° GRADO: ");
					gotoxy(17,19);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,19);
					printf("  3° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi3<0 || mi3>contN2 && contN2<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi3;
		printf("%d",totmiercoles);

		do
		{
			do
			{
				gotoxy(20,21);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi4);//variable que captura la cantidad
	
				if(mi4<0 || mi4>contN3)
				{
					color(255,12);
					gotoxy(5,21);
					printf("* 4° GRADO: ");
					gotoxy(17,21);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,21);
					printf("  4° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi4<0 || mi4>contN3 && contN3<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi4;
		printf("%d",totmiercoles);

		do
		{
			do
			{
				gotoxy(20,23);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi5);//variable que captura la cantidad
	
				if(mi5<0 || mi5>contN4)
				{
					color(255,12);
					gotoxy(5,23);
					printf("* 5° GRADO: ");
					gotoxy(17,23);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,23);
					printf("  5° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi5<0 || mi5>contN4 && contN4<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi5;
		printf("%d",totmiercoles);

		do
		{
			do
			{
				gotoxy(20,25);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi6);//variable que captura la cantidad
	
				if(mi6<0 || l6>contN5)
				{
					color(255,12);
					gotoxy(5,25);
					printf("* 6° GRADO: ");
					gotoxy(17,25);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,25);
					printf("  6° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi6<0 || mi6>contN5 && contN5<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi6;
		printf("%d",totmiercoles);

		do
		{
			do
			{
				gotoxy(20,27);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi7);//variable que captura la cantidad
	
				if(mi7<0 || mi7>contN6)
				{
					color(255,12);
					gotoxy(5,27);
					printf("* 7° GRADO: ");
					gotoxy(17,27);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,27);
					printf("  7° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi7<0 || mi7>contN6 && contN6<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi7;
		printf("%d",totmiercoles);

		do
		{
			do
			{
				gotoxy(20,29);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi8);//variable que captura la cantidad
	
				if(mi8<0 || mi8>contN7)
				{
					color(255,12);
					gotoxy(5,29);
					printf("* 8° GRADO: ");
					gotoxy(17,29);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,29);
					printf("  8° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi8<0 || mi8>contN7 && contN7<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi8;
		printf("%d",totmiercoles);
		do
		{
			do
			{
				gotoxy(20,31);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&mi9);//variable que captura la cantidad
	
				if(mi9<0 || mi9>contN8)
				{
					color(255,12);
					gotoxy(5,31);
					printf("* 9° GRADO: ");
					gotoxy(17,31);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,31);
					printf("  9° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(mi9<0 || mi9>contN8 && contN8<0);
		//calculo del total de alumnos
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totmiercoles+=mi9;
		totmiercoles1=totmiercoles;
		printf("%d",totmiercoles1);
		color(255,4);
		gotoxy(58,32);
		printf("   Regresar? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	menulunes();
}
void elejirmenumiercoles()//inicio elejirmenu
{
	char dis,resp,op;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(0,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			color(5,255);
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis
			gotoxy(8,16);
			printf("ELEJIR MENU");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");
			encabezado();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			color(3,15);
			gotoxy(10,21);
			printf("               ",5);
			gotoxy(10,22);
			printf(" %c 1. Opción 1 ",5);
			gotoxy(10,23);
			printf("               ",5);
			gotoxy(32,21);
			printf("               ",5);
			gotoxy(32,22);
			printf(" %c 2. Opción 2 ",5);
			gotoxy(32,23);
			printf("               ",5);
			gotoxy(10,32);
			color(3,15);
			printf("             ");
			gotoxy(10,33);
			printf("%c 5. Regresar",27);
			gotoxy(10,34);
			printf("             ");
			color(255,3);
			gotoxy(30,32);
			printf("%cElija una opción: ",16);
			for(dis=30;dis<48;dis++)
			{
				color(7,0);
				gotoxy(dis,34);
				printf(" ");
			}
			gotoxy(39,34);
			op=getch();//lee op
			switch(opmenu)
			{
				case '1':
					if(op!='1')
					{
						totmiercoles1=0;
						opcion13();
						opcion23();
					}else
					{
						if(op!='1')
						{
							totmiercoles1=0;
							opcion13();
						}
						else
						{
							opcion13();
						}
						
					}
					
					break;
				
				case '2':
					if(op!='2')
					{
						totmiercoles1=0;
						opcion13();
						opcion23();
					}else
					{
						if(op!='2')
						{
							totmiercoles1=0;
						}
						opcion23();
					}

					break;
				case '3':

					break;

				case '4':

					break;
				case '5':

					break;
				default:
					color(255,4);
					gotoxy(39,33);
					printf("%c",25);
					gotoxy(37,34);
					printf("%c",26);
					gotoxy(41,34);
					printf("%c",27);
					gotoxy(39,35);
					printf("%c",24);
					gotoxy(30,36);			
					printf("%c Opción incorrecta.",16);
					Sleep(500);
			}//Fin switch op
		}while(opmenu !='5');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menulunes();//regresa al menu anterior

}//fin elejirmenu
void opcion13()//inicio opcion1
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total=totmiercoles1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="BEBIDA F", bus2[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pm1=0;
			pm2=0;
			pm3=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0,cont=12;a<contmi-2;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,ml[a].alimento2,ml[a].codigo2);
				strcpy(search,ml[a].codigo2);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contmi;b++)
			{
				if ((strcmp(strupr(search),strupr(ml[b].codigo2)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total);
				//calculo de raciones por el total de alumnos
				pm1=total*arroz;
				pm2=total*bebida;
				pm3=total*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pm1);
				gotoxy(19,20);
				printf("%.2f",pm2);
				gotoxy(19,22);
				printf("%.2f",pm3);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(9,20);
				printf("BEBIDA: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pm1;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pm1;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pm2;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pm2;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pm3;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pm3;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior
}//fin opcion1

void opcion23()//inicio opcion2
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total2=totlunes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="ACEITE", bus2[50]="FRIJOLES";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pm4=0;
			pm5=0;
			pm6=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0+1,cont=12;a<contmi-1;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,ml[a].alimento2,ml[a].codigo2);
				strcpy(search,ml[a].codigo2);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contmi;b++)
			{
				if ((strcmp(strupr(search),strupr(ml[b].codigo2)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total2);
				//calculo de raciones por el total de alumnos
				pm4=total2*arroz;
				pm5=total2*aceite;
				pm6=total2*frijoles;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pm4);
				gotoxy(19,20);
				printf("%.2f",pm5);
				gotoxy(19,22);
				printf("%.2f",pm6);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(9,20);
				printf("ACEITE: ");
				gotoxy(7,22);
				printf("FRIJOLES: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pm4;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pm4;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pm5;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pm5;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pm6;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pm6;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior

}//fin opcion2



//
void ingresarjueves()//inicio ingresarproducto
{
	char menu[200],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);

	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,26,79,2); // Dibuja recuadro principal
		sysbox(8,0,26,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,30);
			printf(" ");
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
		}
		gotoxy(30,31);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       AGREGAR MENU       ");
		color(255,3);
		gotoxy(13,13);
		printf("  N. MENU: ");
		gotoxy(9,16);
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=24;k<60;k++)
		{
			gotoxy(k,13);
			color(7,0);
			printf(" ");
		}//Fin for k

		//incio captura del MENU NUEVO
		do
		{
			gotoxy(24,13);
			fflush(stdin);
			color(7,0);
			//validacion del nombre del producto
			letras(menu,caracter);
	
			if(strlen(menu)<5)
			{
				color(255,12);
				gotoxy(13,13);
				printf("* N. MENU:");
				gotoxy(24,13);
				color(7,0);
				printf("                   ");
				va = false;
			}
			else
			{
				color(255,2);
				gotoxy(13,13);
				printf("  N. MENU:");
				va=true;
			}//Fin if

		}while(!va);//Fin do while va
		strupr(menu);//convierte a mayuscula
		
		//Verifica si ya existe un menu en existencia
		int ko;
		for(ko=0;ko<contj;ko++)
		{
			if (strcmp(strupr(menu),strupr(jk[ko].alimentos3)) == 0)
			{
				repe=false;
				break;
			
			} 
			else 
			{
				repe = true;
			}//Fin if coomparacion
				
		}//Fin for ko
		//Generar  codigo del producto
		int j=0;
		char codig[50],nom;
		while(j<strlen(menu))
		{
			if(menu[j]!=32)
			{
				nom = menu[j];
				break;
			}
			else
			{
				nom = 'K';
			}
			j++;				
		}
		sprintf(codig,"%c%d%s",nom,contj1+1,anio);//concatena variables
		//Muestra el mensaje respectivo
		if(repe)
		{			
			strcpy(jk[contj].alimentos3,menu);
			strcpy(jk[contj].codigos3,codig);
			contj++;
			contj1++;
			//mensaje
			color(4,255);
			gotoxy(14,15);
			printf("     ¡Excelente!.Menu Ingresado con éxito     ");
		}
		else
		{
				color(5,255);
				gotoxy(11,m+11);
				printf("        ¡Error!.Ya existe otro Menu.           ");	
		}//Fin if repe

		color(255,4);
		gotoxy(41,24);
		printf("   Registrar nuevo menu? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin fo while respuesta
	menulunes();
}//fin ingresarproducto

void eliminarjueves()//inicio eliminarproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char r,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int f,a;//para guardar los nuevos datos del producto encontrado y f para recorrer el for
	float sum=0;//para guardar los nuevos datos del producto encontrado
	bool va=false,repe=false,searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

	//INICIO DO WHILE
	do
	{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		//copyright(2,0);
////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(33,8);
		color(255,3);
		printf("MENUS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
		gotoxy(1,11);
		color(3,3);
		printf("--------------------------------------------------------------------------------\n");
		color(255,1);
		int aumentar,cont;
		for(a=0,cont=12;a<contj;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-50s%-14s\n",a+1,jk[a].alimentos3,jk[a].codigos3);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+18;
		}
		else
		{
			aumentar = 26;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar);
			printf(" ");
			gotoxy(dis,aumentar+1);
			printf(" ");
			gotoxy(dis,aumentar+2);
			printf(" ");
		}
		gotoxy(30,aumentar+1);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(27,8);
		color(10,0);
		printf("    ELIMINAR MENU   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////

		for(int k=36;k<68;k++)//inicio for k que imprime cajitas 
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,cont+4);
		printf("  Codigo del Menu a Eliminar: ");
		do{               
			gotoxy(36,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);//captura carnet ingresado
			if(strlen(digit)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,cont+4);
				printf("* Codigo del Menu a Eliminar: ");
				gotoxy(36,cont+4);
				color(7,0);
				printf("          ");
				searchv=false;
			}
			else
			{
				color(255,2);
				gotoxy(6,cont+4);
				printf("  Codigo del Menu a Eliminar: ");
				searchv=true;
			}//Fin if search 
		}while(!searchv);
		int b,posicion;//variables que serviran para identificar en que posicion esta el producto, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
		//Verifica si ya existe un producto
		for(b=1;b<contj;b++)
		{
			if ((strcmp(strupr(digit),strupr(jk[b].codigos3)) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
			{
				existe=true;
				posicion = b;
				break;
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion	
		}//Fin for ko
		if(existe)
		{
			color(255,2);
			gotoxy(10,cont+6);
			printf("      Desea eliminar el Menu? (S/N):  ");
			color(255,4);
			r= getch();
			if(toupper(r)=='S')
			{
				for(f = posicion;f<contj;f++)
				{
					strcpy(jk[f].alimentos3,jk[f+1].alimentos3);
					strcpy(jk[f].codigos3,jk[f+1].codigos3);
							
				}//Fin for F
				contj--;//dejar inexistente la posicion eliminada pero no vacia
				color(3,255);
				gotoxy(14,cont+8);
				printf("     ¡Excelente!.Menu Eliminado con exito     ");
			}
			else
			{
				color(5,255);
				gotoxy(14,cont+7);
				printf("     ¡Error!.Menu no eliminado            ");
					
			}//Fin respuesta y copiar los datos
		}
		else
		{
			gotoxy(14,cont+6);
			color(5,255);
			printf("                                       ");
			gotoxy(14,cont+7);
			printf("      ¡Error!.Menu no encontrado.      ");
			gotoxy(14,cont+8);                                      
			printf("                                       ");
		}//Fin if buscar estudiante
		color(255,4);
		gotoxy(30,cont+12);
		printf("Desea eliminar  o intentar otra vez? (S/N):");
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta
	menulunes();
}//fin eliminarmenu


void asistenciajueves()
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	int totjueves=0;
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);
	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,35,79,2); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,39);
			printf(" ");
			gotoxy(dis,40);
			printf(" ");
			gotoxy(dis,41);
			printf(" ");
		}
		gotoxy(30,40);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       ASISTENCIA DIA LUNES      ");
		color(3,15);
		gotoxy(1,9);
		printf("                                                                                ");
		gotoxy(1,10);
		printf("                        ASISTENCIA POR CADA SECCION                             ");
		gotoxy(1,11);
		printf("                                                                                ");
		color(255,3);
		gotoxy(5,15);
		printf("  1° GRADO: ");
		gotoxy(5,17);
		printf("  2° GRADO: ");
		gotoxy(5,19);
		printf("  3° GRADO: ");
		gotoxy(5,21);
		printf("  4° GRADO: ");
		gotoxy(5,23);
		printf("  5° GRADO: ");
		gotoxy(5,25);
		printf("  6° GRADO: ");
		gotoxy(5,27);
		printf("  7° GRADO: ");
		gotoxy(5,29);
		printf("  8° GRADO: ");
		gotoxy(5,31);
		printf("  9° GRADO: ");
		color(3,15);
		gotoxy(45,19);
		printf("                 ");
		gotoxy(45,20);
		printf("  TOTAL ALUMNOS: ");
		gotoxy(45,21);
		printf("                 ");
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=17;k<25;k++)
		{
			color(7,0);
			gotoxy(k,15);
			printf(" ");
			gotoxy(k,17);
			printf(" ");
			gotoxy(k,19);
			printf(" ");
			gotoxy(k,21);
			printf(" ");
			gotoxy(k,23);
			printf(" ");
			gotoxy(k,25);
			printf(" ");
			gotoxy(k,27);
			printf(" ");
			gotoxy(k,29);
			printf(" ");
			gotoxy(k,31);
			printf(" ");
		}//Fin for k
		gotoxy(45,23);
		color(7,0);
		printf("                 ");

		//incio captura del MENU NUEVO
		totjueves=0;
		do
		{
			do
			{
				gotoxy(20,15);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j1);//variable que captura la cantidad
	
				if(j1<0 || j1>contN)
				{
					color(255,12);
					gotoxy(5,15);
					printf("* 1° GRADO: ");
					gotoxy(17,15);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,15);
					printf("  1° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j1<0 || j1>contN && contN<0);
		gotoxy(53,23);
		color(7,0);
		totjueves+=j1;
		printf("%d",totjueves);

		do
		{
			do
			{
				gotoxy(20,17);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j2);//variable que captura la cantidad
	
				if(j2<0 || j2>contN1)
				{
					color(255,12);
					gotoxy(5,17);
					printf("* 2° GRADO: ");
					gotoxy(17,17);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,17);
					printf("  2° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j2<0 || j2>contN1 && contN1<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j2;
		printf("%d",totjueves);

		do
		{
			do
			{
				gotoxy(20,19);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j3);//variable que captura la cantidad
	
				if(j3<0 || j3>contN2)
				{
					color(255,12);
					gotoxy(5,19);
					printf("* 3° GRADO: ");
					gotoxy(17,19);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,19);
					printf("  3° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j3<0 || j3>contN2 && contN2<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j3;
		printf("%d",totjueves);

		do
		{
			do
			{
				gotoxy(20,21);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j4);//variable que captura la cantidad
	
				if(j4<0 || j4>contN3)
				{
					color(255,12);
					gotoxy(5,21);
					printf("* 4° GRADO: ");
					gotoxy(17,21);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,21);
					printf("  4° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j4<0 || j4>contN3 && contN3<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j4;
		printf("%d",totjueves);

		do
		{
			do
			{
				gotoxy(20,23);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j5);//variable que captura la cantidad
	
				if(j5<0 || j5>contN4)
				{
					color(255,12);
					gotoxy(5,23);
					printf("* 5° GRADO: ");
					gotoxy(17,23);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,23);
					printf("  5° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j5<0 || j5>contN4 && contN4<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j5;
		printf("%d",totjueves);

		do
		{
			do
			{
				gotoxy(20,25);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j6);//variable que captura la cantidad
	
				if(j6<0 || j6>contN5)
				{
					color(255,12);
					gotoxy(5,25);
					printf("* 6° GRADO: ");
					gotoxy(17,25);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,25);
					printf("  6° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j6<0 || j6>contN5 && contN5<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j6;
		printf("%d",totjueves);

		do
		{
			do
			{
				gotoxy(20,27);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j7);//variable que captura la cantidad
	
				if(j7<0 || j7>contN6)
				{
					color(255,12);
					gotoxy(5,27);
					printf("* 7° GRADO: ");
					gotoxy(17,27);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,27);
					printf("  7° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j7<0 || j7>contN6 && contN6<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j7;
		printf("%d",totjueves);

		do
		{
			do
			{
				gotoxy(20,29);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j8);//variable que captura la cantidad
	
				if(j8<0 || j8>contN7)
				{
					color(255,12);
					gotoxy(5,29);
					printf("* 8° GRADO: ");
					gotoxy(17,29);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,29);
					printf("  8° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j8<0 || j8>contN7 && contN7<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j8;
		printf("%d",totjueves);
		do
		{
			do
			{
				gotoxy(20,31);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&j9);//variable que captura la cantidad
	
				if(j9<0 || j9>contN8)
				{
					color(255,12);
					gotoxy(5,31);
					printf("* 9° GRADO: ");
					gotoxy(17,31);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,31);
					printf("  9° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(j9<0 || j9>contN8 && contN8<0);
		//calculo del total de alumnos
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totjueves+=j9;
		totjueves1=totjueves;
		printf("%d",totjueves1);
		color(255,4);
		gotoxy(58,32);
		printf("   Regresar? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	menulunes();
}
void elejirmenujueves()//inicio elejirmenu
{
	char dis,resp,op;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(0,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			color(5,255);
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis
			gotoxy(8,16);
			printf("ELEJIR MENU");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");
			encabezado();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			color(3,15);
			gotoxy(10,21);
			printf("               ",5);
			gotoxy(10,22);
			printf(" %c 1. Opción 1 ",5);
			gotoxy(10,23);
			printf("               ",5);
			gotoxy(32,21);
			printf("               ",5);
			gotoxy(32,22);
			printf(" %c 2. Opción 2 ",5);
			gotoxy(32,23);
			printf("               ",5);
			gotoxy(10,32);
			color(3,15);
			printf("             ");
			gotoxy(10,33);
			printf("%c 5. Regresar",27);
			gotoxy(10,34);
			printf("             ");
			color(255,3);
			gotoxy(30,32);
			printf("%cElija una opción: ",16);
			for(dis=30;dis<48;dis++)
			{
				color(7,0);
				gotoxy(dis,34);
				printf(" ");
			}
			gotoxy(39,34);
			op=getch();//lee op
			switch(opmenu)
			{
				case '1':
					if(op!='1')
					{
						totjueves1=0;
						opcion14();
						opcion24();
					}else
					{
						if(op!='1')
						{
							totjueves1=0;
							opcion14();
						}
						else
						{
							opcion14();
						}
						
					}
					
					break;
				
				case '2':
					if(op!='2')
					{
						totjueves1=0;
						opcion14();
						opcion24();
					}else
					{
						if(op!='2')
						{
							totjueves1=0;
						}
						opcion24();
					}

					break;
				case '3':
	
					break;

				case '4':

					break;
				case '5':

					break;
				default:
					color(255,4);
					gotoxy(39,33);
					printf("%c",25);
					gotoxy(37,34);
					printf("%c",26);
					gotoxy(41,34);
					printf("%c",27);
					gotoxy(39,35);
					printf("%c",24);
					gotoxy(30,36);			
					printf("%c Opción incorrecta.",16);
					Sleep(500);
			}//Fin switch op
		}while(opmenu !='5');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menulunes();//regresa al menu anterior

}//fin elejirmenu
void opcion14()//inicio opcion1
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total=totjueves1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="FRIJOLES", bus1[50]="BEBIDA F", bus2[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pj1=0;
			pj2=0;
			pj3=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0,cont=12;a<contj-2;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,jk[a].alimentos3,jk[a].codigos3);
				strcpy(search,jk[a].codigos3);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contj;b++)
			{
				if ((strcmp(strupr(search),strupr(jk[b].codigos3)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total);
				//calculo de raciones por el total de alumnos
				pj1=total*arroz;
				pj2=total*bebida;
				pj3=total*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pj1);
				gotoxy(19,20);
				printf("%.2f",pj2);
				gotoxy(19,22);
				printf("%.2f",pj3);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(9,20);
				printf("BEBIDA: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pj1;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pj1;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pj2;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pj2;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pj3;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pj3;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior
}//fin opcion1
void opcion24()//inicio opcion2
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total2=totjueves1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="BEBIDA F", bus2[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pj3=0;
			pj4=0;
			pj5=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0+1,cont=12;a<contj-1;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,jk[a].alimentos3,jk[a].codigos3);
				strcpy(search,jk[a].codigos3);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contj;b++)
			{
				if ((strcmp(strupr(search),strupr(jk[b].codigos3)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total2);
				//calculo de raciones por el total de alumnos
				pj4=total2*arroz;
				pj5=total2*bebida;
				pj6=total2*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pj4);
				gotoxy(19,20);
				printf("%.2f",pj5);
				gotoxy(19,22);
				printf("%.2f",pj6);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(9,20);
				printf("BEBIDA: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pj4;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pj4;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pj5;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pj5;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pj6;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pj6;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior

}//fin opcion2
//
void ingresarviernes()//inicio ingresarproducto
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);

	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,26,79,2); // Dibuja recuadro principal
		sysbox(8,0,26,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,30);
			printf(" ");
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
		}
		gotoxy(30,31);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       AGREGAR MENU       ");
		color(255,3);
		gotoxy(13,13);
		printf("  N. MENU: ");
		gotoxy(9,16);
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=24;k<60;k++)
		{
			gotoxy(k,13);
			color(7,0);
			printf(" ");
		}//Fin for k

		//incio captura del MENU NUEVO
		do
		{
			gotoxy(24,13);
			fflush(stdin);
			color(7,0);
			//validacion del nombre del producto
			letras(menu,caracter);
	
			if(strlen(menu)<5)
			{
				color(255,12);
				gotoxy(13,13);
				printf("* N. MENU:");
				gotoxy(24,13);
				color(7,0);
				printf("                   ");
				va = false;
			}
			else
			{
				color(255,2);
				gotoxy(13,13);
				printf("  N. MENU:");
				va=true;
			}//Fin if

		}while(!va);//Fin do while va
		strupr(menu);//convierte a mayuscula
		
		//Verifica si ya existe un menu en existencia
		int ko;
		for(ko=0;ko<contV;ko++)
		{
			if (strcmp(strupr(menu),strupr(v[ko].alimento4)) == 0)
			{
				repe=false;
				break;
			
			} 
			else 
			{
				repe = true;
			}//Fin if coomparacion
				
		}//Fin for ko
		//Generar  codigo del producto
		int j=0;
		char codig[50],nom;
		while(j<strlen(menu))
		{
			if(menu[j]!=32)
			{
				nom = menu[j];
				break;
			}
			else
			{
				nom = 'K';
			}
			j++;				
		}
		sprintf(codig,"%c%d%s",nom,contV1+1,anio);//concatena variables
		//Muestra el mensaje respectivo
		if(repe)
		{			
			strcpy(v[contV].alimento4,menu);
			strcpy(v[contV].codigo4,codig);
			contV++;
			contV1++;
			//mensaje
			color(4,255);
			gotoxy(14,15);
			printf("     ¡Excelente!.Menu Ingresado con éxito     ");
		}
		else
		{
				color(5,255);
				gotoxy(11,m+11);
				printf("        ¡Error!.Ya existe otro Menu.           ");	
		}//Fin if repe

		color(255,4);
		gotoxy(41,24);
		printf("   Registrar nuevo menu? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin fo while respuesta
	menulunes();
}//fin ingresarproducto

void eliminarviernes()//inicio eliminarproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char r,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int f,a;//para guardar los nuevos datos del producto encontrado y f para recorrer el for
	float sum=0;//para guardar los nuevos datos del producto encontrado
	bool va=false,repe=false,searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

	//INICIO DO WHILE
	do
	{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		//copyright(2,0);
////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(33,8);
		color(255,3);
		printf("MENUS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
		gotoxy(1,11);
		color(3,3);
		printf("--------------------------------------------------------------------------------\n");
		color(255,1);
		int aumentar,cont;
		for(a=0,cont=12;a<contV;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-50s%-14s\n",a+1,v[a].alimento4,v[a].codigo4);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+18;
		}
		else
		{
			aumentar = 26;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar);
			printf(" ");
			gotoxy(dis,aumentar+1);
			printf(" ");
			gotoxy(dis,aumentar+2);
			printf(" ");
		}
		gotoxy(30,aumentar+1);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(27,8);
		color(10,0);
		printf("    ELIMINAR MENU   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////

		for(int k=36;k<68;k++)//inicio for k que imprime cajitas 
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,cont+4);
		printf("  Codigo del Menu a Eliminar: ");
		do{               
			gotoxy(36,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);//captura carnet ingresado
			if(strlen(digit)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,cont+4);
				printf("* Codigo del Menu a Eliminar: ");
				gotoxy(36,cont+4);
				color(7,0);
				printf("          ");
				searchv=false;
			}
			else
			{
				color(255,2);
				gotoxy(6,cont+4);
				printf("  Codigo del Menu a Eliminar: ");
				searchv=true;
			}//Fin if search 
		}while(!searchv);
		int b,posicion;//variables que serviran para identificar en que posicion esta el producto, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
		//Verifica si ya existe un producto
		for(b=1;b<contV;b++)
		{
			if ((strcmp(strupr(digit),strupr(v[b].codigo4)) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
			{
				existe=true;
				posicion = b;
				break;
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion	
		}//Fin for ko
		if(existe)
		{
			color(255,2);
			gotoxy(10,cont+6);
			printf("      Desea eliminar el Menu? (S/N):  ");
			color(255,4);
			r= getch();
			if(toupper(r)=='S')
			{
				for(f = posicion;f<contV;f++)
				{
					strcpy(v[f].alimento4,v[f+1].alimento4);
					strcpy(v[f].codigo4,v[f+1].codigo4);
							
				}//Fin for F
				contV--;//dejar inexistente la posicion eliminada pero no vacia
				color(3,255);
				gotoxy(14,cont+8);
				printf("     ¡Excelente!.Menu Eliminado con exito     ");
			}
			else
			{
				color(5,255);
				gotoxy(14,cont+7);
				printf("     ¡Error!.Menu no eliminado            ");
					
			}//Fin respuesta y copiar los datos
		}
		else
		{
			gotoxy(14,cont+6);
			color(5,255);
			printf("                                       ");
			gotoxy(14,cont+7);
			printf("      ¡Error!.Menu no encontrado.      ");
			gotoxy(14,cont+8);                                      
			printf("                                       ");
		}//Fin if buscar estudiante
		color(255,4);
		gotoxy(30,cont+12);
		printf("Desea eliminar  o intentar otra vez? (S/N):");
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta
	menulunes();
}//fin eliminarmenu


void asistenciaviernes()
{
	char menu[100],res,dis;//produc guarda el nombre del menu y res captura la respusta por si se desea seguir registrando productos
	int totviernes=0;
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);
	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,35,79,2); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,39);
			printf(" ");
			gotoxy(dis,40);
			printf(" ");
			gotoxy(dis,41);
			printf(" ");
		}
		gotoxy(30,40);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       ASISTENCIA DIA LUNES      ");
		color(3,15);
		gotoxy(1,9);
		printf("                                                                                ");
		gotoxy(1,10);
		printf("                        ASISTENCIA POR CADA SECCION                             ");
		gotoxy(1,11);
		printf("                                                                                ");
		color(255,3);
		gotoxy(5,15);
		printf("  1° GRADO: ");
		gotoxy(5,17);
		printf("  2° GRADO: ");
		gotoxy(5,19);
		printf("  3° GRADO: ");
		gotoxy(5,21);
		printf("  4° GRADO: ");
		gotoxy(5,23);
		printf("  5° GRADO: ");
		gotoxy(5,25);
		printf("  6° GRADO: ");
		gotoxy(5,27);
		printf("  7° GRADO: ");
		gotoxy(5,29);
		printf("  8° GRADO: ");
		gotoxy(5,31);
		printf("  9° GRADO: ");
		color(3,15);
		gotoxy(45,19);
		printf("                 ");
		gotoxy(45,20);
		printf("  TOTAL ALUMNOS: ");
		gotoxy(45,21);
		printf("                 ");
		//Dibuja las cajitas donde digitan los datos del MENU
		for(int k=17;k<25;k++)
		{
			color(7,0);
			gotoxy(k,15);
			printf(" ");
			gotoxy(k,17);
			printf(" ");
			gotoxy(k,19);
			printf(" ");
			gotoxy(k,21);
			printf(" ");
			gotoxy(k,23);
			printf(" ");
			gotoxy(k,25);
			printf(" ");
			gotoxy(k,27);
			printf(" ");
			gotoxy(k,29);
			printf(" ");
			gotoxy(k,31);
			printf(" ");
		}//Fin for k
		gotoxy(45,23);
		color(7,0);
		printf("                 ");

		//incio captura del MENU NUEVO
		totviernes=0;
		do
		{
			do
			{
				gotoxy(20,15);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v1);//variable que captura la cantidad
	
				if(v1<0 || v1>contN)
				{
					color(255,12);
					gotoxy(5,15);
					printf("* 1° GRADO: ");
					gotoxy(17,15);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,15);
					printf("  1° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v1<0 || v1>contN && contN<0);
		gotoxy(53,23);
		color(7,0);
		totviernes+=v1;
		printf("%d",totviernes);

		do
		{
			do
			{
				gotoxy(20,17);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v2);//variable que captura la cantidad
	
				if(v2<0 || v2>contN1)
				{
					color(255,12);
					gotoxy(5,17);
					printf("* 2° GRADO: ");
					gotoxy(17,17);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,17);
					printf("  2° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v2<0 || v2>contN1 && contN1<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v2;
		printf("%d",totviernes);

		do
		{
			do
			{
				gotoxy(20,19);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v3);//variable que captura la cantidad
	
				if(v3<0 || v3>contN2)
				{
					color(255,12);
					gotoxy(5,19);
					printf("* 3° GRADO: ");
					gotoxy(17,19);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,19);
					printf("  3° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v3<0 || v3>contN2 && contN2<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v3;
		printf("%d",totviernes);

		do
		{
			do
			{
				gotoxy(20,21);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v4);//variable que captura la cantidad
	
				if(v4<0 || v4>contN3)
				{
					color(255,12);
					gotoxy(5,21);
					printf("* 4° GRADO: ");
					gotoxy(17,21);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,21);
					printf("  4° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v4<0 || v4>contN3 && contN3<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v4;
		printf("%d",totviernes);

		do
		{
			do
			{
				gotoxy(20,23);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v5);//variable que captura la cantidad
	
				if(v5<0 || v5>contN4)
				{
					color(255,12);
					gotoxy(5,23);
					printf("* 5° GRADO: ");
					gotoxy(17,23);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,23);
					printf("  5° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v5<0 || v5>contN4 && contN4<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v5;
		printf("%d",totviernes);

		do
		{
			do
			{
				gotoxy(20,25);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v6);//variable que captura la cantidad
	
				if(v6<0 || v6>contN5)
				{
					color(255,12);
					gotoxy(5,25);
					printf("* 6° GRADO: ");
					gotoxy(17,25);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,25);
					printf("  6° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v6<0 || v6>contN5 && contN5<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v6;
		printf("%d",totviernes);

		do
		{
			do
			{
				gotoxy(20,27);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v7);//variable que captura la cantidad
	
				if(v7<0 || v7>contN6)
				{
					color(255,12);
					gotoxy(5,27);
					printf("* 7° GRADO: ");
					gotoxy(17,27);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,27);
					printf("  7° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v7<0 || v7>contN6 && contN6<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v7;
		printf("%d",totviernes);

		do
		{
			do
			{
				gotoxy(20,29);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v8);//variable que captura la cantidad
	
				if(v8<0 || v8>contN7)
				{
					color(255,12);
					gotoxy(5,29);
					printf("* 8° GRADO: ");
					gotoxy(17,29);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,29);
					printf("  8° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v8<0 || v8>contN7 && contN7<0);
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v8;
		printf("%d",totviernes);
		do
		{
			do
			{
				gotoxy(20,31);
				color(7,0);
				//validacion del nombre del producto
				numeros(val,200);
				sscanf(val,"%d",&v9);//variable que captura la cantidad
	
				if(v9<0 || v9>contN8)
				{
					color(255,12);
					gotoxy(5,31);
					printf("* 9° GRADO: ");
					gotoxy(17,31);
					color(7,0);
					printf("        ");
					va = false;
				}
				else
				{
					color(255,2);
					gotoxy(5,31);
					printf("  9° GRADO: ");
					va=true;
				}//Fin if

			}while(!va);//Fin do while va
		}while(v9<0 || v9>contN8 && contN8<0);
		//calculo del total de alumnos
		color(7,0);
		gotoxy(45,23);
		printf("          ");
		gotoxy(53,23);
		totviernes+=v9;
		totviernes1=totviernes;
		printf("%d",totviernes1);
		color(255,4);
		gotoxy(58,32);
		printf("   Regresar? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	menulunes();
}
void elejirmenuviernes()//inicio elejirmenu
{
	char dis,resp,op;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(0,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			color(5,255);
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis
			gotoxy(8,16);
			printf("ELEJIR MENU");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(3,0);
				printf(" ");
				gotoxy(dis,16);
				color(3,0);
				printf(" ");
				gotoxy(dis,17);
				color(3,0);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");
			encabezado();
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			color(3,15);
			gotoxy(10,21);
			printf("               ",5);
			gotoxy(10,22);
			printf(" %c 1. Opción 1 ",5);
			gotoxy(10,23);
			printf("               ",5);
			gotoxy(32,21);
			printf("               ",5);
			gotoxy(32,22);
			printf(" %c 2. Opción 2 ",5);
			gotoxy(32,23);
			printf("               ",5);
			gotoxy(10,32);
			color(3,15);
			printf("             ");
			gotoxy(10,33);
			printf("%c 5. Regresar",27);
			gotoxy(10,34);
			printf("             ");
			color(255,3);
			gotoxy(30,32);
			printf("%cElija una opción: ",16);
			for(dis=30;dis<48;dis++)
			{
				color(7,0);
				gotoxy(dis,34);
				printf(" ");
			}
			gotoxy(39,34);
			op=getch();//lee op
			switch(op)
			{
				case '1':
					if(op!='1')
					{
						totviernes1=0;
						opcion15();
						opcion25();
					}else
					{
						if(op!='1')
						{
							totviernes1=0;
							opcion15();
						}
						else
						{
							opcion15();
						}
						
					}
					
					break;
				
				case '2':
					if(op!='2')
					{
						totviernes1=0;
						opcion15();
						opcion25();
					}else
					{
						if(op!='2')
						{
							totviernes1=0;
						}
						opcion25();
					}

					break;
				case '3':

					break;

				case '4':

					break;
				case '5':

					break;
				default:
					color(255,4);
					gotoxy(39,33);
					printf("%c",25);
					gotoxy(37,34);
					printf("%c",26);
					gotoxy(41,34);
					printf("%c",27);
					gotoxy(39,35);
					printf("%c",24);
					gotoxy(30,36);			
					printf("%c Opción incorrecta.",16);
					Sleep(500);
			}//Fin switch op
		}while(opmenu !='5');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menulunes();//regresa al menu anterior

}//fin elejirmenu
void opcion15()//inicio opcion1
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total=totviernes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="ACEITE", bus2[50]="BEBIDA F",bus3[50]="AZUCAR";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pv1=0;
			pv2=0;
			pv3=0;
			pv4=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0,cont=12;a<contV-2;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,v[a].alimento4,v[a].codigo4);
				strcpy(search,v[a].codigo4);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contV;b++)
			{
				if ((strcmp(strupr(search),strupr(v[b].codigo4)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total);
				//calculo de raciones por el total de alumnos
				pv1=total*arroz;
				pv2=total*aceite;
				pv3=total*bebida;
				pv4=total*azucar;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pv1);
				gotoxy(19,20);
				printf("%.2f",pv2);
				gotoxy(19,22);
				printf("%.2f",pv3);
				gotoxy(19,24);
				printf("%.2f",pv4);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(9,20);
				printf("ACEITE: ");
				gotoxy(9,22);
				printf("BEBIDA: ");
				gotoxy(9,22);
				printf("AZUCAR: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pv1;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pv1;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pv2;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pv2;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pv3;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pv3;
					pro[j].cant=pro[j].tot;
				}
					for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus3),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pv4;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pv4;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior
}//fin opcion1
void opcion25()//inicio opcion2
{
	//variables locales
	bool searchv=false,existe=false,buscar=false; //variable booleana
	int a,cont,b,i,j,n,o,k,posicion,total2=totviernes1;
	char res,dis,search[50];//variables que capturan diseño y busqueda del menu
	char bus[50]="ARROZ", bus1[50]="ACEITE", bus2[50]="FRIJOLES";//variables para buscar y disminuir cantidad al inventario
	do
		{
			pv5=0;
			pv6=0;
			pv7=0;
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal para digitar los datos
			//inicio copyright
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}

			gotoxy(30,42);
			printf("Copyright UES 2017");
			//fin copyright
			gotoxy(25,8);
			color(10,0);
			printf("       MENU DEL DIA       ");
			gotoxy(1,9);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(3,15);
			gotoxy(1,10);
			printf(" %4s%20s\t\t%23s\t\t\t","No","MENU","CODIGO");
			gotoxy(1,11);
			color(3,3);
			printf("--------------------------------------------------------------------------------\n");
			color(255,1);
			for(a=0+1,cont=12;a<contV-1;a++,cont+=2)
			{
				gotoxy(1,cont-1);
				color(8,255);
				printf("                                                                              \n");
				gotoxy(1,cont);
				color(255,1);
				printf("%4d\t%-50s%-14s\n",a+1,v[a].alimento4,v[a].codigo4);
				strcpy(search,v[a].codigo4);
				gotoxy(1,cont+1);
				color(8,255);
				printf("                                                                              \n");
			}
			color(3,3);
			gotoxy(1,cont-1);
			printf("\n--------------------------------------------------------------------------------");
			//Verifica si ya existe un carnet de estudiante	
			for(b=0;b<contV;b++)
			{
				if ((strcmp(strupr(search),strupr(v[b].codigo4)) == 0))
				{
					existe=true;
					posicion = b;
					break;
				} 
				else 
				{
					existe = false;
				}//Fin if coomparacion
				
			}//Fin for b
			if(existe)
			{
				//Diseño
				for(dis=17;dis<=25;dis++)
				{
					color(7,0);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
				}
				for(dis=30;dis<=45;dis++)
				{
					gotoxy(dis,18);
					printf(" ");
				}
				//impresion del total de estudiantes de las secciones
				gotoxy(37,18);
				printf("%d",total2);
				//calculo de raciones por el total de alumnos
				pv5=total2*arroz;
				pv6=total2*aceite;
				pv7=total2*frijoles;
				//impresion de resultados
				gotoxy(19,18);
				printf("%.2f",pv5);
				gotoxy(19,20);
				printf("%.2f",pv6);
				gotoxy(19,22);
				printf("%.2f",pv7);
				//impresion de caracteres
				color(255,3);
				gotoxy(30,16);
				printf("TOTAL ESTUDIANTES");
				gotoxy(12,16);
				printf("INGREDIENTES");
				gotoxy(10,18);
				printf("ARROZ: ");
				gotoxy(9,20);
				printf("ACEITE: ");
				gotoxy(7,22);
				printf("FRIJOLES: ");
				gotoxy(51,17);
				color(3,15);
				printf(" RACIONES POR ALUMNO EN KG ");
				gotoxy(51,16);
				printf("                           ");
				gotoxy(51,18);
				printf("                           ");
				
				color(3,15);
				gotoxy(51,18);
				printf("                  ");
				gotoxy(51,19);
				printf(" ARROZ           : 0.03");
				gotoxy(51,20);
				printf("                  ");
				gotoxy(51,21);
				printf(" FRIJOL          : 0.03");
				gotoxy(51,22);
				printf("                  ");
				gotoxy(51,23);
				printf(" LECHE           : 0.03");
				gotoxy(51,24);
				printf("                  ");
				gotoxy(51,25);
				printf(" AZUCAR          : 0.02");
				gotoxy(51,26);
				printf("                  ");
				gotoxy(51,27);
				printf(" BEBIDA           ");
				gotoxy(51,28);
				printf(" FORTIFICADA     : 0.015");
				gotoxy(51,29);
				printf("                  ");
				gotoxy(51,30);
				printf(" ACEITE          : 0.005");
				gotoxy(51,31);
				printf("                  ");
				gotoxy(51,32);
				printf(" CEREAL           ");
				gotoxy(51,33);
				printf(" SOLO PARVULARIA :");
				gotoxy(51,34);
				printf("                  ");
				//dibuja cuadros grises y numero
				color(7,0);
				gotoxy(69,25);
				printf(" 0.02   ");
				gotoxy(69,27);
				printf("        ");
				gotoxy(69,28);
				printf(" 0.015  ");
				gotoxy(69,23);
				printf(" 0.03   ");
				gotoxy(69,21);
				printf(" 0.03   ");
				gotoxy(69,19);
				printf(" 0.03   ");
				gotoxy(69,30);
				printf(" 0.005  ");
				gotoxy(69,32);
				printf("        ");
				gotoxy(69,33);
				printf(" 0.0352 ");
				//dibuja cuadros verde
				color(3,3);
				gotoxy(69,18);
				printf("        ");
				gotoxy(69,20);
				printf("        ");
				gotoxy(69,22);
				printf("        ");
				gotoxy(69,24);
				printf("        ");
				gotoxy(69,26);
				printf("        ");
				gotoxy(69,29);
				printf("        ");
				gotoxy(69,31);
				printf("        ");
				gotoxy(69,34);
				printf("        ");
				//for de diseño
				for(dis=77;dis<=77;dis++)
				{
					color(3,3);
					gotoxy(dis,18);
					printf(" ");
					gotoxy(dis,19);
					printf(" ");
					gotoxy(dis,20);
					printf(" ");
					gotoxy(dis,21);
					printf(" ");
					gotoxy(dis,22);
					printf(" ");
					gotoxy(dis,23);
					printf(" ");
					gotoxy(dis,24);
					printf(" ");
					gotoxy(dis,25);
					printf(" ");
					gotoxy(dis,26);
					printf(" ");
					gotoxy(dis,27);
					printf(" ");
					gotoxy(dis,28);
					printf(" ");
					gotoxy(dis,29);
					printf(" ");
					gotoxy(dis,30);
					printf(" ");
					gotoxy(dis,31);
					printf(" ");
					gotoxy(dis,32);
					printf(" ");
					gotoxy(dis,33);
					printf(" ");
					gotoxy(dis,34);
					printf(" ");
				}//fin for dis
				//busqueda 1 de los datos para disminuir las cantidades de las raciones al inventario
				for(i=0;i<m;i++)
				{
					if ((strcmp(strupr(bus),strupr(pro[i].nombre)) == 0))
					{
						searchv=true;
						j= i;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pv5;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pv5;
					pro[j].cant=pro[j].tot;
				}
				
				//busqueda 2 de los datos para disminuir las cantidades de las raciones al inventario
				for(n=0;n<m;n++)
				{
					if ((strcmp(strupr(bus1),strupr(pro[n].nombre)) == 0))
					{
						buscar=true;
						o= n;
						break;
					} 
					else 
					{
						buscar= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(buscar)
				{	
					pro[o].dismi=0;
					pro[o].dismi=pv6;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[o].tot=pro[o].cant-pv6;
					pro[o].cant=pro[o].tot;
				}
				//busqueda 3 de los datos para disminuir las cantidades de las raciones al inventario
				for(k=0;k<m;k++)
				{
					if ((strcmp(strupr(bus2),strupr(pro[k].nombre)) == 0))
					{
						searchv=true;
						j= k;
						break;
					} 
					else 
					{
						searchv= false;
					}//Fin if coomparacion
				
				}//Fin for b
				if(searchv)
				{	
					pro[j].dismi=0;
					pro[j].dismi=pv7;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
					pro[j].tot=pro[j].cant-pv7;
					pro[j].cant=pro[j].tot;
				}
			}
			color(255,4);
			gotoxy(58,36);
			printf(" Regresar? (S/N):");
			res=getch(); //Leer la respuesta
	}while(toupper(res)!='S');//Fin fo while respuesta
	elejirmenu();//llama al menu anterior

}//fin opcion2

//****************************************************************************************************************************************
//					INICIO DEL INVENTARIO, MODIFICAR,ELIMINAR,INSERTAR, EXISTENCIAS,AUMENTAR,DISMINUIR
//****************************************************************************************************************************************

void iniciarproducto()// inicio iniciarproducto
{
	int cantidad=4;
	strcpy(pro[m].nombre,"ARROZ");
	strcpy(pro[m].codigo,"A117");
	pro[m].cant=cantidad;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad1=2;
	strcpy(pro[m].nombre,"MAIZ");
	strcpy(pro[m].codigo,"M217");
	pro[m].cant=cantidad1;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad2=16;
	strcpy(pro[m].nombre,"FRIJOLES");
	strcpy(pro[m].codigo,"F317");
	pro[m].cant=cantidad2;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad3=5;
	strcpy(pro[m].nombre,"LECHE");
	strcpy(pro[m].codigo,"L417");
	pro[m].cant=cantidad3;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad4=8;
	strcpy(pro[m].nombre,"AZUCAR");
	strcpy(pro[m].codigo,"A517");
	pro[m].cant=cantidad4;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad5=16;
	strcpy(pro[m].nombre,"QUESILLO");
	strcpy(pro[m].codigo,"Q617");
	pro[m].cant=cantidad5;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad6=16;
	strcpy(pro[m].nombre,"INCAPARINA");
	strcpy(pro[m].codigo,"I717");
	pro[m].cant=cantidad6;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad7=10;
	strcpy(pro[m].nombre,"SAL");
	strcpy(pro[m].codigo,"S817");
	pro[m].cant=cantidad7;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad8=25;
	strcpy(pro[m].nombre,"MASECA");
	strcpy(pro[m].codigo,"M917");
	pro[m].cant=cantidad8;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad9=15;
	strcpy(pro[m].nombre,"CEBOLLA");
	strcpy(pro[m].codigo,"C1017");
	pro[m].cant=cantidad9;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad10=15;
	strcpy(pro[m].nombre,"BEBIDA F");
	strcpy(pro[m].codigo,"B1117");
	pro[m].cant=cantidad10;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;

	int cantidad11=15;
	strcpy(pro[m].nombre,"ACEITE");
	strcpy(pro[m].codigo,"A1217");
	pro[m].cant=cantidad11;
	pro[m].tot=pro[m].cant;
	pro[m].dismi;
	pro[m].agg;
	m++;
	c++;
}//fin iniciarproducto

void menuproductos()//inicio menuproductos
{
	char op,resp;//variables que capturan opcion elegida y si desea repetir la ejecucion
	int dis;//variable para diseño del sistema
	do//incio do res
	{
		do//inicio do op
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
////////////////////////////////////ESTETICA DEL SYSBOX////////////////////////////////////////////////////////////////////////////////////
			color(282,0);
			////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");

			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				//color(125,236);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis

			//lineas centrales

			//texto
		
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				color(7,0);
				printf(" ");
				gotoxy(dis,16);
				color(7,0);
				printf(" ");
				gotoxy(dis,17);
				color(7,0);
				printf(" ");
			}//fin for dis
			color(7,0);
			gotoxy(8,16);
			printf("INVENTARIO");
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				color(3,0);
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis
			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");
/////////////////////////////////////////FIN ESTETICA DEL SISBOX////////////////////////////////////////////////////////////////////////////////
			gotoxy(8,20);
			color(255,3);
			printf(" %c 1. Ingresar Producto",6);
			gotoxy(8,23);
			printf(" %c 2. Eliminar Producto",6);
			gotoxy(8,26);
			printf(" %c 3. Agregar Cantidad ",6);
			gotoxy(45,20);
			printf(" %c 4. Disminuir cantidad ",6);
			gotoxy(45,23);
			printf(" %c 5. Existencias ",6);
			color(3,15);
			gotoxy(8,32);
			printf("               ");
			gotoxy(8,33);
			printf(" %c 6. Regresar ",27);
			gotoxy(8,34);
			printf("               ");
			color(255,3);
			gotoxy(30,32);
			printf(" %c Elija una opcion: ",16);
			for(int k=31;k<50;k++)
			{
				gotoxy(k,34);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,34);
			color(7,0);
			op = getch(); //leer opcion
			switch(op)
			{
			case '1':
				system("cls");
				ingresarproducto();
				break;

			case '2':
				system("cls");
				eliminarproducto();
				break;

			case '3':
				sumcanproducto();
				break;
			case '4':
				rescanproducto();
				break;
			case '5':
				system("cls");
				mostrarproducto();
				break;
			case '6':
		
				break;

			case '0':

				break;
			default:
				color(255,4);
				gotoxy(39,33);
				printf("%c",25);
				gotoxy(37,34);
				printf("%c",26);
				gotoxy(41,34);
				printf("%c",27);
				gotoxy(39,35);
				printf("%c",24);
				gotoxy(30,36);			
				printf("  %cOpcion incorrecta",16);
				Sleep(500);
			}//Fin switch  op
		}while(op!='6');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf("%c Regresar ? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
}

void ingresarproducto()//inicio ingresarproducto
{
	char produc[100],res,dis;//produc guarda el nombr del producto y res captura la respusta por si se desea seguir registrando productos
	int canti;//guarda la cantidad de productos de uno solo
	float preci;//guarda el precio del producto por unidad
	bool va=false,repe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
	struct tm *tlocall = localtime(&tiempos);
	char anio[128];
	strftime(anio,128,"%y",tlocall);

	do{
		//inicio de la ingresacion de los datos
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		sysbox(8,0,26,79,2); // Dibuja recuadro principal
		sysbox(8,0,26,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,30);
			printf(" ");
			gotoxy(dis,31);
			printf(" ");
			gotoxy(dis,32);
			printf(" ");
		}
		gotoxy(30,31);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("       REGISTRAR PRODUCTO       ");
		color(255,3);
		gotoxy(10,13);
		printf("  N. PRODUCTO: ");
		gotoxy(9,16);
		printf("   N. CANTIDAD: ");
		//Dibuja las cajitas donde digitan los datos del producto
		for(int k=25;k<60;k++)
		{
			gotoxy(k,13);
			color(7,0);
			printf(" ");
			gotoxy(k,16);
			printf(" ");
		}//Fin for k

		//incio captura del nombre del producto
		do
		{
			gotoxy(25,13);
			fflush(stdin);
			color(7,0);
			//validacion del nombre del producto
			letras(produc,caracter);
	
			if(strlen(produc)<3)
			{
				color(255,12);
				gotoxy(10,13);
				printf("* N. PRODUCTO:");
				gotoxy(25,13);
				color(7,0);
				printf("                   ");
				va = false;
			}
			else
			{
				color(255,2);
				gotoxy(10,13);
				printf("  N. PRODUCTO:");
				va=true;
			}//Fin if

		}while(!va);//Fin do while va
		strupr(produc);//convierte a mayuscula

		//inicio captura de cantidad
		do{
			do{
					gotoxy(25,16);
					fflush(stdin);
					color(7,0);
					numeros(cantidadC,200);
					sscanf(cantidadC,"%d",&canti);//variable que captura la cantidad
			
					if(canti<1)
					{
						color(255,12);
						gotoxy(8,16);
						printf("  * N. CANTIDAD:");
						gotoxy(25,16);
						color(7,0);
						printf("                     ");
						va = false;	
					}
					else
					{
						color(255,2);
						gotoxy(9,16);
						printf("   N. CANTIDAD:");
						va=true;
					}//Fin if
				}while(!va);//Fin do while va
			}while(canti<1);
		
		//Verifica si ya existe un usuario
		int ko;
		for(ko=0;ko<m;ko++)
		{
			if (strcmp(strupr(produc),strupr(pro[ko].nombre)) == 0)
			{
				repe=false;
				break;
			
			} 
			else 
			{
				repe = true;
			}//Fin if coomparacion
				
		}//Fin for ko
		color(255,2);
		gotoxy(9,16);
		printf("   N. CANTIDAD:");
		//Generar  codigo del producto
		int j=0;
		char codig[50],nom;
		while(j<strlen(produc))
		{
			if(produc[j]!=32)
			{
				nom = produc[j];
				break;
			}
			else
			{
				nom = 'K';
			}
			j++;				
		}
		sprintf(codig,"%c%d%s",nom,c+1,anio);//concatena variables
		//Muestra el mensaje respectivo
		if(repe)
		{			
			strcpy(pro[m].nombre,produc);
			strcpy(pro[m].codigo,codig);
			pro[m].cant=canti;
			pro[m].tot=pro[m].cant;
			m++;
			c++;
			//mensaje
			color(4,255);
			gotoxy(14,22);
			printf("     ¡Excelente!.Producto Ingresado con éxito     ");
		}
		else
		{
				color(5,255);
				gotoxy(11,m+11);
				printf("        ¡Error!.Ya existe otro Producto.           ");	
		}//Fin if repe

		color(255,4);
		gotoxy(41,24);
		printf("   Registrar nuevo producto? (S/N):");
		res=getch(); //Leer la respuesta
	}while(toupper(res)=='S');//Fin fo while respuesta
}//fin ingresarproducto

void eliminarproducto()//inicio eliminarproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char r,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int f,a;//para guardar los nuevos datos del producto encontrado y f para recorrer el for
	float sum=0;//para guardar los nuevos datos del producto encontrado
	bool va=false,repe=false,searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al carnet del estudiante
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);

	//INICIO DO WHILE
	do
	{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		//copyright(2,0);
////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(29,8);
		color(255,3);
		printf("PRODUCTOS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf(" %4s%10s  %11s\t%2s%10s%13s%8s\t\t\n","No","NOMBRE","CODIGO"," CANTIDAD LB","AGREGADO","DISMINUIDO","TOTAL");
		gotoxy(1,11);
		color(3,3);
		printf("---------------------------------------------------------------------------------\n");
		color(1,255);
		int aumentar,cont;
		for(a=0,cont=12;a<m;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-12s\t%-5s\t    %.2f\t%.2f\t%7.2f%12.2f     \n",a+1,pro[a].nombre,pro[a].codigo,pro[a].cant,pro[a].agg, pro[a].dismi,pro[a].tot);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+18;
		}
		else
		{
			aumentar = 26;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-4,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar);
			printf(" ");
			gotoxy(dis,aumentar+1);
			printf(" ");
			gotoxy(dis,aumentar+2);
			printf(" ");
		}
		gotoxy(30,aumentar+1);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(22,8);
		color(10,0);
		printf("    ELIMINAR DATOS DEl PRODUCTO   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////

		for(int k=40;k<70;k++)//inicio for k que imprime cajitas 
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(6,cont+4);
		printf("  Codigo del Producto a Eliminar: ");
		do{               
			gotoxy(40,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);//captura carnet ingresado
			if(strlen(digit)<4)//if que pide que los datos no sean vacios
			{
				color(255,12);
				gotoxy(6,cont+4);
				printf("* Codigo del Producto a Eliminar: ");
				gotoxy(40,cont+4);
				color(7,0);
				printf("             ");
				searchv=false;
			}
			else
			{
				color(255,2);
				gotoxy(6,cont+4);
				printf("  Codigo del Producto a Eliminar: ");
				searchv=true;
			}//Fin if search 
		}while(!searchv);
		int b,posicion;//variables que serviran para identificar en que posicion esta el producto, b para el for
						// y posicion para el estudiante y para guardar la posicion misma del carnet sumandole 1
		//Verifica si ya existe un producto
		for(b=0;b<m;b++)
		{
			if ((strcmp(strupr(digit),strupr(pro[b].codigo)) == 0))//comparacion de la busqueda del carnet si hay uno igual con el ingresado
			{
				existe=true;
				posicion = b;
				break;
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion	
		}//Fin for ko
		if(existe)
		{
			color(255,2);
			gotoxy(10,cont+7);
			printf("      Desea eliminar los Datos de el Producto? (S/N):  ");
			color(255,4);
			r= getch();
			if(toupper(r)=='S')
			{
				for(f = posicion;f<m;f++)
				{
					strcpy(pro[f].nombre,pro[f+1].nombre);
					strcpy(pro[f].codigo,pro[f+1].codigo);
					pro[f].cant=pro[f+1].cant;
					pro[f].agg=pro[f+1].agg;
					pro[f].dismi=pro[f+1].dismi;
					pro[f].tot=pro[f+1].tot;
							
				}//Fin for F
				m--;//dejar inexistente la posicion eliminada pero no vacia
				color(3,255);
				gotoxy(14,cont+9);
				printf("     ¡Excelente!.Producto Eliminado con exito     ");
			}
			else
			{
				color(5,255);
				gotoxy(14,cont+9);
				printf("     ¡Error!.Producto no eliminado            ");
					
			}//Fin respuesta y copiar los datos
		}
		else
		{
			gotoxy(14,cont+7);
			color(5,255);
			printf("                                           ");
			gotoxy(14,cont+8);
			printf("      ¡Error!.Producto no encontrado.      ");
			gotoxy(14,cont+9);                                      
			printf("                                           ");
		}//Fin if buscar estudiante
		color(255,4);
		gotoxy(30,cont+12);
		printf("Desea eliminar  o intentar otra vez? (S/N):");
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta
}//fin eliminarproducto

void sumcanproducto()//incio sumcanproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char v,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int canti,a;//para guardar los nuevos datos del producto encontrado
	float sum=0;//para guardar los nuevos datos del producto encontrado
	bool searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al código delproducto
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);
	do{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		gotoxy(22,7);
		//copyright(2,0);
		////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(29,8);
		color(255,3);
		printf("PRODUCTOS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf("%4s%10s\t  %11s\t%11s\t%10s\t%9s\t\t\n","No","NOMBRE","CODIGO"," CANTIDAD LB","AGREGAR LB","TOTAL LB");
		gotoxy(1,11);
		color(3,3);
		printf("---------------------------------------------------------------------------------\n");
		int aumentar,cont;
		for(a=0,cont=12;a<m;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-12s\t%-5s\t    %.2f\t$%8.2f\t$%8.2f      \n",a+1,pro[a].nombre,pro[a].codigo,pro[a].cant,pro[a].agg, pro[a].tot);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+16;
		}
		else
		{
			aumentar = 26;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-1,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar+3);
			printf(" ");
			gotoxy(dis,aumentar+4);
			printf(" ");
			gotoxy(dis,aumentar+5);
			printf(" ");
		}
		gotoxy(30,aumentar+4);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(16,8);
		color(10,0);
		printf("   AGREGAR CANTIDAD A PRODUCTOS EN EXISTENCIA   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////
		for(int k=32;k<64;k++)
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k

		
		color(255,3);
		gotoxy(9,cont+4);
		printf("  Codigo del Producto : ");
		do
		{               
			gotoxy(34,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);

			if(strlen(digit)<4)
			{
				color(255,12);
				gotoxy(9,cont+4);
				printf("* Codigo del Producto : ");
				color(7,0);
				gotoxy(32,cont+4);
				printf("                      ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(9,cont+4);
				printf("  Codigo del Producto : ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);

		int b,posicion;
		for(b=0;b<m;b++)
		{
			if ((strcmp(strupr(digit),strupr(pro[b].codigo)) == 0))
			{
				existe=true;
				posicion = b;
				break;	
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion
		}//Fin for b
		if(existe)
		{
			color(3,255);
			gotoxy(14,cont+6);
			printf("  Producto Encontrado. Agregue cantidad a %s ",pro[posicion].nombre);
			color(255,9);
			color(255,9);
			system("pause>null");
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(6,0,30,79,1); // Dibuja recuadro principal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,33);
				printf(" ");
				gotoxy(dis,34);
				printf(" ");
				gotoxy(dis,35);
				printf(" ");
			}
			gotoxy(30,34);
			printf("Copyright UES 2017");
			//fin barra horizontal
			gotoxy(22,6);
			color(10,0);
			printf("    AGREGAR CANTIDAD A PRODUCTO EN EXISTENCIAS   ");
			gotoxy(14,12);
			color(255,12);
			printf("Agregar cantidad al Producto seleccionado? (S/N):");
			v= getch();
//////////////////INICIO AGREGAR CANTIDAD/////////////////////////////////////////////////////////////
			if(toupper(v)=='S')
			{
				color(255,3);
				gotoxy(10,14);
				printf("  N. CANTIDAD: "); //Dibuja las cajitas donde digitan los datos del producto
				for(int k=25;k<60;k++)
				{
					gotoxy(k,14);
					color(7,0);
					printf(" ");
				}//Fin for k

				//incio captura del nombre del producto
				do
				{
					gotoxy(25,14);
					fflush(stdin);
					color(7,0);
					//validacion de la cantidad del producto
					numeros(cantidadC,200);
					sscanf(cantidadC, "%d", &canti);
					if(canti<0)
					{
						color(255,12);
						gotoxy(10,14);
						printf("* N. CANTIDAD:");
						gotoxy(25,14);
						color(7,0);
						printf("                    ");
						valida= true;
					}
					else
					{
						color(255,2);
						gotoxy(10,14);
						printf("  N. CANTIDAD:");
						valida=false;
					}//Fin if

				}while(valida);//Fin do while va
				pro[posicion].agg=pro[posicion].agg+canti;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
				pro[posicion].tot=pro[posicion].cant+canti;//guarda nuevo total
				pro[posicion].cant=pro[posicion].tot;
				posicion++;//incremento de posiciion para guardar el dato ingresado cada vez que se ejecute
				gotoxy(20,16);
				color(3,255);
				printf("  Cantidad agregada exitosamente.  ");
			}
			else
			{
				color(5,255);			
				gotoxy(20,16);
				printf("   Error!. Cantidad no agregada   ");
			}
		}
		else
		{
			gotoxy(16,cont+6);
			color(5,255);
			printf("                                           ");
			gotoxy(16,cont+7);
			printf("     Error!.Producto no encontrado.        ");
			gotoxy(16,cont+8);                                      
			printf("                                           ");
		}//fin else si no existe el codigo del producto a buscar
		if(existe)
		{
			color(255,4);
			gotoxy(15,28);
			printf("Desea agregar  mas cantidad a productos en existencias? (S/N):");
		}
		else
		{
			color(255,4);
			gotoxy(15,cont+12);
			printf("Desea agregar  mas cantidad a productos en existencias? (S/N):");
		}
		
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta
}//fin suncanproducto

void rescanproducto()//inicio rescanproducto
{
	char digit[100],res;//para buscar el producto a modificar datos
	char v,dis;//variable de tipo caracter que lee la respuesta para eliminar los datos del estudiante
	int a;//para guardar los nuevos datos del producto encontrado
	float sum=0,canti;//para guardar los nuevos datos del producto encontrado
	bool searchv=false,valida=false,existe=false; //variable booleana
	//para asignar AÑ0 al código del producto
	time_t tiempos = time(0);
    struct tm *tlocall = localtime(&tiempos);
    char anio[128];
	strftime(anio,128,"%y",tlocall);
	do{
		color(255,9);
		system("cls");
		color(255,9);
		encabezado();
		color(3,3);
		gotoxy(22,7);
		////////////////////////MUESTRA LA TABLA DE LOS PRODUCTOS///////////////////////////////////////
		gotoxy(29,8);
		color(255,3);
		printf("PRODUCTOS REGISTRADOS");
		color(3,3);
		gotoxy(1,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(1,10);
		printf("%4s%10s\t  %11s\t%11s\t%10s\t%9s\t\t\n","No","NOMBRE","CODIGO"," CANTIDAD LB","DISMINUIR LB","TOTAL");
		gotoxy(1,11);
		color(3,3);
		printf("---------------------------------------------------------------------------------\n");
		color(1,255);
		int aumentar,cont;
		for(a=0,cont=12;a<m;a++,cont+=2)
		{
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-12s\t%-5s\t    %.2f\t$%8.2f\t$%8.2f      \n",a+1,pro[a].nombre,pro[a].codigo,pro[a].cant,pro[a].dismi, pro[a].tot);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------");
		if(a>=0)
		{
			aumentar=cont+16;
		}
		else
		{
			aumentar = 45;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar-1,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar+3);
			printf(" ");
			gotoxy(dis,aumentar+4);
			printf(" ");
			gotoxy(dis,aumentar+5);
			printf(" ");
		}
		gotoxy(30,aumentar+4);
		printf("Copyright UES 2017");
		//fin barra horizontal
		gotoxy(10,8);
		color(10,0);
		printf("   DISMINUIR CANTIDAD A PRODUCTOS EN EXISTENCIA UTILIZADOS   ");
///////////////////////FIN MOSTRAR TABLA/////////////////////
		for(int k=32;k<64;k++)
		{
			gotoxy(k,cont+4);
			color(7,0);
			printf(" ");
		}//Fin for k
		color(255,3);
		gotoxy(9,cont+4);
		printf("  Codigo del Producto : ");
		do
		{               
			gotoxy(34,cont+4);
			color(7,0);
			fflush(stdin);
			gets(digit);

			if(strlen(digit)<4)
			{
				color(255,12);
				gotoxy(9,cont+4);
				printf("* Codigo del Producto : ");
				color(7,0);
				gotoxy(33,cont+4);
				printf("                      ");
				searchv=false;
			
			}else
			{
				color(255,2);
				gotoxy(9,cont+4);
				printf("  Codigo del Producto : ");
				searchv=true;
				
			}//Fin if search 
		}while(!searchv);

		int b,posicion;
		for(b=0;b<m;b++)
		{
			if ((strcmp(strupr(digit),strupr(pro[b].codigo)) == 0))
			{
				existe=true;
				posicion = b;
				break;	
			} 
			else 
			{
				existe = false;
			}//Fin if coomparacion
		}//Fin for b
		if(existe)
		{
			color(3,255);
			gotoxy(14,cont+6);
			printf("  Producto Encontrado. Disminuir cantidad a %s ",pro[posicion].nombre);
			color(255,9);
			color(255,9);
			system("pause>null");
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(6,0,30,79,1); // Dibuja recuadro principal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,33);
				printf(" ");
				gotoxy(dis,34);
				printf(" ");
				gotoxy(dis,35);
				printf(" ");
			}
			gotoxy(30,34);
			printf("Copyright UES 2017");
			//fin barra horizontal
			gotoxy(22,6);
			color(10,0);
			printf("    DISMINUIR CANTIDAD A PRODUCTO EN EXISTENCIAS   ");
			gotoxy(14,12);
			color(255,12);
			printf("Disminuir cantidad al Producto seleccionado? (S/N):");
			v= getch();
//////////////////INICIO AGREGAR CANTIDAD/////////////////////////////////////////////////////////////
			if(toupper(v)=='S')
			{
				color(255,3);
				gotoxy(10,14);
				printf("     CANTIDAD: "); //Dibuja las cajitas donde digitan los datos del producto
				for(int h=25;h<60;h++)
				{
					gotoxy(h,14);
					color(7,0);
					printf(" ");
				}//Fin for k

				//incio captura del nombre del producto
				do
				{
					gotoxy(25,14);
					fflush(stdin);
					color(7,0);
					//validacion de la cantidad del productos
					reales(cantidadC,200);
					sscanf(cantidadC, "%f", &canti);

					if(pro[posicion].cant<=canti)
					{
						color(255,12);
						gotoxy(10,14);
						printf("*    CANTIDAD:");
						gotoxy(25,14);
						color(7,0);
						printf("                    ");
						valida= true;
					}
					else
					{
						color(255,2);
						gotoxy(10,14);
						printf("     CANTIDAD:");
						valida=false;
					}//Fin if

				}while(valida);//Fin do while va
				pro[posicion].dismi=pro[posicion].dismi+canti;//suma cantidad a cantidades existentes guardandola en la posicion buscada mas la cantidad ingresada
				pro[posicion].tot=pro[posicion].cant-canti;
				pro[posicion].cant=pro[posicion].tot;
				posicion++;//incremento de posiciion para guardar el dato ingresado cada vez que se ejecute
				gotoxy(20,16);
				color(3,255);
				printf("  Cantidad disminuida exitosamente.  ");
			}
			else
			{
				color(5,255);			
				gotoxy(20,16);
				printf("   Error!. Cantidad no disminuida   ");
			}
		}
		else
		{
			gotoxy(16,cont+6);
			color(5,255);
			printf("                                           ");
			gotoxy(16,cont+7);
			printf("     Error!.Producto no encontrado.        ");
			gotoxy(16,cont+8);                                      
			printf("                                           ");
		}//fin else si no existe el codigo del producto a buscar
		if(existe)
		{
			color(255,4);
			gotoxy(17,28);
			printf("Desea disminuir  mas cantidad a productos utilizados? (S/N):");
		}
		else
		{
			color(255,4);
			gotoxy(17,cont+12);
			printf("Desea disminuir  mas cantidad a productos utilizados? (S/N):");
		}
		res=getch(); //captura respuesta
	}while(toupper(res)=='S');//Fin do while respuesta

}//fin rescanproducto


void mostrarproducto()//inicio mostrarproducto
{
	float sum=0,sum1=0,sum2=0;
	int aumentar, cont;
	char res,dis;
	do
	{
		color(255,3);
		system("cls");
		color(255,3);
		color(3,3);
		gotoxy(0,9);
		printf("--------------------------------------------------------------------------------");
		color(3,15);
		gotoxy(0,10);
		printf(" %4s%10s\t  %11s\t%2s%10s%13s%8s\t\t\n","No","NOMBRE","CODIGO"," CANTIDAD LB","AGREGADO","DISMINUIDO","TOTAL");
		gotoxy(0,11);
		color(3,3);
		printf("---------------------------------------------------------------------------------\n");
		color(255,1);
		for(k=0,cont=12;k<m;k++,cont+=2)
		{
			sum+=pro[k].tot;
			sum1+=pro[k].agg;
			sum2+=pro[k].dismi;
			gotoxy(1,cont-1);
			color(8,255);
			printf("                                                                              \n");
			gotoxy(1,cont);
			color(255,1);
			printf("%4d\t%-12s\t%-5s\t    %.2f\t%.2f\t%7.2f%12.2f     \n",k+1,pro[k].nombre,pro[k].codigo,pro[k].cant,pro[k].agg, pro[k].dismi,pro[k].tot);
			gotoxy(1,cont+1);
			color(8,255);
			printf("                                                                              \n");
		}
		color(3,3);
		gotoxy(1,cont-1);
		printf("\n--------------------------------------------------------------------------------\n");
		color(255,3);
		printf("  TOTAL :\t\t\t\t\t%.2f\t   %.2f\t   %8.2f",sum1,sum2,sum);
		
		if(k>=0)
		{
			aumentar=cont+10;
		}
		else
		{
			aumentar = 35;
		}
		color(3,3);//color para el cuadro dibujado
		sysbox(8,0,aumentar,79,1); // Dibuja recuadro principal
		for(dis=0;dis<80;dis++)
		{
			color(5,255);
			gotoxy(dis,aumentar+4);
			printf(" ");
			gotoxy(dis,aumentar+5);
			printf(" ");
			gotoxy(dis,aumentar+6);
			printf(" ");
		}
		gotoxy(30,aumentar+5);
		printf("Copyright UES 2017");
		//fin barra horizontal
		encabezado();
		gotoxy(27,8);
		color(10,0);
		printf("       INVENTARIO      ");
		color(255,4);
		gotoxy(58	,cont+7);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu 
}//fin mostrar producto

//****************************************************************************************************************************************
//										REPORTES DE INVENTARIO,SECCIONES,MENU,COMITE DE MADRES
//****************************************************************************************************************************************
void menuReportes()
{

	char op,dis,resp;

	do
	{
		do
		{
			color(255,9);
			system("CLS");
			color(255,9);
			encabezado();
			color(3,3);
			sysbox(8,0,38,79,2); // Dibuja recuadro principal
			////////////////////////////////////ESTETICA DE LA VENTANA////////////////////////////////////////////////////////////////////////////////////
			color(0,0);
			 ////marco verde limon////
			for(dis=1;dis<79;dis++)
			{
				gotoxy(dis,9);
				printf(" ");
				gotoxy(dis,10);
				printf(" ");
				gotoxy(dis,11);
				printf(" ");
				gotoxy(dis,12);
				printf(" ");
				gotoxy(dis,13);
				printf(" ");
				gotoxy(dis,14);
				printf(" ");
			}
			gotoxy(6,12);
			color(255,0);
			gotoxy(6,11);
			printf("                ");
			gotoxy(6,13);
			printf("                ");
			gotoxy(6,12);
			printf(" %cSISTEMA PASE%c ",124,124);

			////cuadrado uno////
			for(dis=50;dis<57;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(3,0);
				printf(" ");
				gotoxy(dis,11);
				color(3,0);
				printf(" ");
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis
			////cuadrado 3////
			for(dis=67;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(3,0);
				printf(" ");
				gotoxy(dis,13);
				color(3,0);
				printf(" ");
			}//fin for dis

			//forma central/////
			for(dis=57;dis<74;dis++)//inicio for dis
			{
				gotoxy(dis,10);
				color(15,0);
				printf(" ");
				gotoxy(dis,11);
				color(15,0);
				printf(" ");
			}//fin for dis

			for(dis=57;dis<67;dis++)//inicio for dis
			{
				gotoxy(dis,12);
				color(15,0);
				printf(" ");
				gotoxy(dis,13);
				color(15,0);
				printf(" ");
			}//fin for dis
			//lineas centrales
			//texto
			color(5,255);
			for(dis=1;dis<26;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis
	
			gotoxy(7,16);
			printf("  REPORTES");
			color(3,0);
			for(dis=26;dis<79;dis++)//inicio for dis
			{
				gotoxy(dis,15);
				printf(" ");
				gotoxy(dis,16);
				printf(" ");
				gotoxy(dis,17);
				printf(" ");
			}//fin for dis

			//barra horizontal de color negro enla parte inferior
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,41);
				printf(" ");
				gotoxy(dis,42);
				printf(" ");
				gotoxy(dis,43);
				printf(" ");
			}
			gotoxy(30,42);
			printf("Copyright UES 2017");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(10,21);
			color(255,3);
			printf("%c 1. Reporte comite de Madres",6);
			gotoxy(10,24);
			printf("%c 2. Reporte de Estudiantes",6);
			gotoxy(49,21);
			printf("%c 3. Reporte de Inventario",6);
			gotoxy(49,24);
			printf("%c 4. Reporte de Menu",6);
			gotoxy(10,32);
			color(3,15);
			printf("            ");
			gotoxy(10,33);
			printf(" %c 5. Atras ",27);
			gotoxy(10,34);
			printf("            ");
			color(255,3);
			gotoxy(30,32);
			printf("%c Elija una opcion: ",16);
			for(int l=30;l<48;l++)
			{
				gotoxy(l,34);
				color(7,0);
				printf(" ");
			}
			gotoxy(39,34);
			op=getch();//lee op

			switch(op)
			{
				case '1':
					reporteComiteMadre();
					break;
				
				case '2':
					reporteSecciones();
					break;
				case '3':
					reporteInventario();
					break;

				case '4':		
					reporteMenu();
					break;
				case '5':
				
				break;
				default:
					color(255,4);
					gotoxy(39,33);
					printf("%c",25);
					gotoxy(37,34);
					printf("%c",26);
					gotoxy(41,34);
					printf("%c",27);
					gotoxy(39,35);
					printf("%c",24);
					gotoxy(30,36);			
					printf("%c Opcion incorrecta.",16);
					Sleep(500);
			}//Fin switch op
		}while(op !='5');//Fin do while op
		gotoxy(58,36);
		color(255,4);
		printf(" Regresar? (S/N):");
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	principal(); //regresa al menu principal
}

void reporteComiteMadre()
{

	int aumentar,cont,i=0,conte=0;
	bool existe=false;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("COMITE DE MADRES");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);

		color(7,0);
		gotoxy(1,8);
		printf("                                                                              \n");
		gotoxy(1,9);
		printf("%2s %s\t%-5s%14s%12s \t%14s\t", "N°","NOMBRE COMPLETO", "DUI", "TELEFONO","DIRECCION","COMITE");
		gotoxy(1,10);
		printf("                                                                              \n");
		color(255,1);
		cont=12;

		if(contM>0)
		{
			for (i = 0;i < contM; i++) 
			{
				

				if(strcmp(madre[i].comite,"SI")==0)
				{
				
				gotoxy(1,cont);
				color(255,0);
				conte++;
				
				existe=true;
				printf("%2d %-20s%s%10s  %-29s%s  \n",conte,madre[i].nombreCM,madre[i].duiM,madre[i].telM,madre[i].dirM,madre[i].comite);
				gotoxy(1,cont+1);
				printf("                                                                               \n");
				cont = cont+2;
				}

			}

			if(!existe)
			{
				gotoxy(18,12);
				color(5,255);
				printf("NO hay madres registradas en el comite");

			}
	
		}
		else
		{
			
				gotoxy(24,12);
				color(5,255);
				printf("NO hay madres registradas");
		}
		if(i>=5)
		{
			aumentar=cont+4;
		}else
		{
			aumentar = 26;
		}
		color(7,7);
		sysbox(7,0,aumentar,79,1); // Dibuja recuadro principal
	

		color(255,2);
		gotoxy(2,cont+2);
		printf("%c Comite de madres lo forman: %d de %d Madres Registradas.",12,conte,contM);
		color(255,4);
		gotoxy(60,aumentar+2);
		printf("%cAtras (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');
	menuReportes();
}//Fin reporte comite de madres

void reporteSecciones()//inicio reportesecciones
{
	char resp,op,dis;
	do
	{
		do
		{
			color(255,9);
			system("cls");
			color(255,9);
			encabezado();
			//incio barra horizontal
			for(dis=0;dis<80;dis++)
			{
				color(5,255);
				gotoxy(dis,31);
				printf(" ");
				gotoxy(dis,32);
				printf(" ");
				gotoxy(dis,33);
				printf(" ");
			}
			gotoxy(30,32);
			printf("Copyright UES 2017");
			//fin barra horizontal
			color(3,3);//color para el cuadro dibujado
			sysbox(8,0,28,79,2); // Dibuja recuadro principal
			color(10,0);
			gotoxy(20,8);
			printf(" REPORTES DE ESTUDIANTES POR SECCIONES ");
			gotoxy(8,13);
			color(255,3);
			printf("%c A. 1° Grado",5);
			gotoxy(8,15);
			printf("%c B. 2° Grado",5);
			gotoxy(29,13);
			printf(" %c C. 3° Grado",5);
			gotoxy(29,15);
			printf(" %c D. 4° Grado",5);
			gotoxy(52,13);
			printf(" %c E. 5° Grado",5);
			gotoxy(52,15);
			printf(" %c F. 6° Grado",5);
			color(3,15);
			gotoxy(8,22);
			printf("               ");
			gotoxy(8,23);
			printf(" %c 7. Regresar ",27);
			gotoxy(8,24);
			printf("               ");
			color(255,3);
			gotoxy(30,22);
			printf(" %c Elija una opcion: ",16);
			for(int k=31;k<50;k++)
			{
				gotoxy(k,24);
				color(7,0);
				printf(" ");
			}//Fin for k
			gotoxy(39,24);
			color(7,0);
			op = getch(); //leer opcion
			switch(toupper(op))
			{
			case 'A':
				reporteseccion();
				
				break;

			case 'B':
				reporteseccion1();

				break;
			case 'C':
				reporteseccion2();
	
				break;

			case 'D':
				reporteseccion3();

				break;
			case 'E':
				reporteseccion4();
				break;

			case 'F':
				reporteseccion5();
				break;

				case '7':
				break;

			default:
				color(255,4);
				gotoxy(39,23);
				printf("%c",25);
				gotoxy(37,24);
				printf("%c",26);
				gotoxy(41,24);
				printf("%c",27);
				gotoxy(39,25);
				printf("%c",24);
				gotoxy(30,26);			
				printf(" %cOpcion incorrecta",16);
				Sleep(500);
				break;
			}//Fin switch  op
	
		}while(op!='7');//Fin do while op
		gotoxy(58,26);
		color(255,4);
		printf("%c Regresar? (S/N): ",27);
		resp=getche(); //Leer op
	}while(toupper(resp)!='S');//Fin do while res
	menuReportes();
}//fin reportesecciones

void reporteseccion()//inicio reporteseccion
{
	int i,aumentar;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("   1° GRADO");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);
		color(7,0);
		gotoxy(1,9);
		printf("                                                                               ");
		gotoxy(1,9);
		printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
		gotoxy(1,10);
		printf("                                                                               ");
		color(255,1);
		int cont; 
		for (i = 0,cont=12;i < contN; i++,cont=cont+2) //Inicio for de estudiantes
		{
			gotoxy(1,cont+1);
			color(255,0);
			printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos[i],nombre[i],carnetU[i]);//Impresion de los estudiantes registrados y agregados
		}//Fin for de estudiantes
		if(i>=5)
		{
			aumentar=cont+4;
		}
		else
		{
			aumentar = 26;
		}
		color(7,7);//color para el cuadro dibujado
		sysbox(8,0,aumentar-3,79,1); // Dibuja recuadro principal
		color(255,4);
		gotoxy(58	,cont+4);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu
	reporteSecciones();

}//fin reporteseccion

void reporteseccion1()//inicio reporteseccion1
{
	int i,aumentar;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("   2° GRADO");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);
		color(7,0);
		gotoxy(1,9);
		printf("                                                                               ");
		gotoxy(1,9);
		printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
		gotoxy(1,10);
		printf("                                                                               ");
		color(255,1);
		int cont; 
		for (i = 0,cont=12;i < contN1; i++,cont=cont+2) //Inicio for de estudiantes
		{
			gotoxy(1,cont+1);
			color(255,0);
			printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos1[i],nombre1[i],carnetU1[i]);//Impresion de los estudiantes registrados y agregados
		}//Fin for de estudiantes
		if(i>=5)
		{
			aumentar=cont+4;
		}
		else
		{
			aumentar = 26;
		}
		color(7,7);//color para el cuadro dibujado
		sysbox(8,0,aumentar-3,79,1); // Dibuja recuadro principal
		color(255,4);
		gotoxy(58	,cont+4);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu
	reporteSecciones();

}//fin reporteseccion1

void reporteseccion2()//inicio reporteseccion2
{
	int i,aumentar;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("   3° GRADO");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);
		color(7,0);
		gotoxy(1,9);
		printf("                                                                               ");
		gotoxy(1,9);
		printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
		gotoxy(1,10);
		printf("                                                                               ");
		color(255,1);
		int cont; 
		for (i = 0,cont=12;i < contN2; i++,cont=cont+2) //Inicio for de estudiantes
		{
			gotoxy(1,cont+1);
			color(255,0);
			printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos2[i],nombre2[i],carnetU2[i]);//Impresion de los estudiantes registrados y agregados			
		}//Fin for de estudiantes
		if(i>=5)
		{
			aumentar=cont+4;
		}
		else
		{
			aumentar = 26;
		}
		color(7,7);//color para el cuadro dibujado
		sysbox(8,0,aumentar-3,79,1); // Dibuja recuadro principal
		color(255,4);
		gotoxy(58	,cont+4);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu
	reporteSecciones();

}//fin reporteseccion2

void reporteseccion3()//inicio reporteseccion3
{
	int i,aumentar;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("   4° GRADO");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);
		color(7,0);
		gotoxy(1,9);
		printf("                                                                               ");
		gotoxy(1,9);
		printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
		gotoxy(1,10);
		printf("                                                                               ");
		color(255,1);
		int cont; 
		for (i = 0,cont=12;i < contN3; i++,cont=cont+2) //Inicio for de estudiantes
		{
			gotoxy(1,cont+1);
			color(255,0);
			printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos3[i],nombre3[i],carnetU3[i]);//Impresion de los estudiantes registrados y agregados			
			}//Fin for de estudiantes
			if(i>=5)
			{
				aumentar=cont+4;
			}
			else
			{
				aumentar = 26;
			}

			color(7,7);//color para el cuadro dibujado
			sysbox(8,0,aumentar-3,79,1); // Dibuja recuadro principal
			color(255,4);
			gotoxy(58	,cont+4);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu
	reporteSecciones();

}//fin reporteseccion3

void reporteseccion4()//inicio reporteseccion4
{
	int i,aumentar;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("   5° GRADO");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);
		color(7,0);
		gotoxy(1,9);
		printf("                                                                               ");
		gotoxy(1,9);
		printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
		gotoxy(1,10);
		printf("                                                                               ");
		color(255,1);
		int cont; 
		for (i = 0,cont=12;i < contN4; i++,cont=cont+2) //Inicio for de estudiantes
		{
			gotoxy(1,cont+1);
			color(255,0);
			printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos4[i],nombre4[i],carnetU4[i]);//Impresion de los estudiantes registrados y agregados	
		}//Fin for de estudiantes
		if(i>=5)
		{
			aumentar=cont+4;
		}
		else
		{
			aumentar = 26;
		}

		color(7,7);//color para el cuadro dibujado
		sysbox(8,0,aumentar-3,79,1); // Dibuja recuadro principal
		color(255,4);
		gotoxy(58	,cont+4);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu
	reporteSecciones();

}//fin reporteseccion4

void reporteseccion5()//inicio reporteseccion5
{
	int i,aumentar;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("   6° GRADO");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);
		color(7,0);
		gotoxy(1,9);
		printf("                                                                               ");
		gotoxy(1,9);
		printf("%6s\t\t%12s\t\%17s%24s\t\t", "N°", "APELLIDOS", "NOMBRES","CARNET");
		gotoxy(1,10);
		printf("                                                                               ");
		color(255,1);
		int cont; 
		for (i = 0,cont=12;i < contN5; i++,cont=cont+2) //Inicio for de estudiantes
		{
			gotoxy(1,cont+1);
			color(255,0);
			printf("%5d\t\t%-23s%-17s\t%8s\n",i+1,apellidos5[i],nombre5[i],carnetU5[i]);//Impresion de los estudiantes registrados y agregados	
		}//Fin for de estudiantes
		if(i>=5)
		{
			aumentar=cont+4;
		}
		else
		{
			aumentar = 26;
		}
		color(7,7);//color para el cuadro dibujado
		sysbox(8,0,aumentar-3,79,1); // Dibuja recuadro principal
		color(255,4);
		gotoxy(58	,cont+4);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu
	reporteSecciones();

}//fin reporteseccion5
void reporteInventario()//inicio reporteinventario
{
	float sum=0,sum1=0,sum2=0;
	int aumentar, cont;
	char res;
	do
	{
		color(255,9);
		system("CLS");
		color(5,255);
		gotoxy(0,0);
		printf("                                                                                \n");
		gotoxy(28,0);
		printf("Centro Escolar %cAnita Alvarado%c",34,34);
		gotoxy(30,3);
		color(255,9);
		printf("\n\t\t\t\t PASE SYSTEM\n");
		gotoxy(1,3);
		printf("REPORTE GENERAL DE");
		gotoxy(1,5);
		printf("   INVENTARIO");
		//Mostrar fecha y hora de manera local
		time_t tiempo = time(0);
		struct tm *tlocal = localtime(&tiempo);
		char output[128];
		strftime(output,128," %d/%m/%y %H:%M:%S",tlocal);
		gotoxy(62,2);
		printf("Fecha y Hora");
		gotoxy(60,3);
		printf("  de Impresion");
		gotoxy(60,5);
		color(255,0);
		printf("%s\n",output);
		color(7,0);
		gotoxy(1,9);
		printf("                                                                                ");
		gotoxy(0,10);
		printf(" %4s%10s\t  %11s\t%2s%10s%13s%8s\t\t\n","No","NOMBRE","CODIGO"," CANTIDAD LB","AGREGADO","DISMINUIDO","TOTAL");
		gotoxy(0,11);
		color(7,0);
		printf("                                                                                \n");
		color(255,1);
		for(k=0,cont=20;k<m;k++,cont++)
		{
			color(255,0);
			sum+=pro[k].tot;
			sum1+=pro[k].agg;
			sum2+=pro[k].dismi;
			printf("%4d\t%-12s\t%-5s\t    %.2f\t%.2f\t%7.2f%12.2f     \n",k+1,pro[k].nombre,pro[k].codigo,pro[k].cant,pro[k].agg, pro[k].dismi,pro[k].tot);
		}
		color(7,0);
		printf("\n                                                                                \n");
		color(255,0);
		printf("  TOTAL :\t\t\t\t\t%.2f\t   %.2f\t   %8.2f",sum1,sum2,sum);

		if(k>=0)
		{
			aumentar=cont+4;
		}
		else
		{
			aumentar = 26;
		}
		color(7,7);//color para el cuadro dibujado
		sysbox(8,0,aumentar+5,79,1); // Dibuja recuadro principal
		color(255,4);
		gotoxy(58	,cont+11);
		printf(" %c Regresar (S/N): ",27);
		res = getch();
	}while(toupper(res)!='S');//Fin do while y regresa al menu 
	menuReportes();

}//fin reporteinventario

void reporteMenu()//inicio reportemenu
{

}//fin reportemenu

//ya solo falta meter el menu con su estetica y su reporte y amarrar los contadores para mostrar los menus