#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */




//variabes globales
int tipoProducto = 0, stockActualCamisas = 300, stockActualPantalones = 300, stockActualMedias = 300, ingresosNuevos = 0, cantidadVendidas = 0;
double precioProducto;

HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);


//prototipos de funciones y procedimientos
void menu();
void gotoxy(int x ,int y);
void cuadro(int x1, int y1, int x2, int y2);
void ingresar_existencias();
void mostrarStock();

void estadisticas();


//procedimientos
void gotoxy(int x ,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

void cuadro(int x1, int y1, int x2, int y2){
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}


void mostrarStock(){
	
	system ("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(10,7,70,17);
	cuadro(18,3,38,5);
	
	gotoxy(19,4); printf("***Stock Actual***"); 
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(19,9); printf("Cantidad de Camisetas: %i\n", stockActualCamisas);
	gotoxy(19,11); printf("Cantidad de Pantalones: %i\n", stockActualPantalones);;
	gotoxy(19,13); printf("Cantidad de Medias: %i\n", stockActualMedias);
	
	gotoxy(27,19); printf("<Pulse tecla para Abandonar>");
	getch();
	
}

void ingresar_existencias(){
	char sigue;

	do{
		system("cls");
		
		cuadro(10,7,70,17);
		cuadro(18,3,38,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(20,04); printf("INGRESANDO DATOS");

		SetConsoleTextAttribute (hConsoleHandle, 6);
		gotoxy(12,8); printf("Ingrese el tipo de producto: ");
		scanf("%i", &tipoProducto);
		gotoxy(12,10); printf("Ingrese la cantidad de producto: ");
		scanf("%i", &ingresosNuevos);
		
	
	//	asignarProducto(tipoProducto);
		
		switch(tipoProducto){
			case 1: stockActualCamisas += ingresosNuevos; break;
			case 2: stockActualPantalones += ingresosNuevos; break;
			case 3: stockActualMedias += ingresosNuevos; break;
		}

		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,18);printf("Desea Continuar S/N");
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	}while (tolower(sigue)=='s');
	//tolower convierte a minuscula
	//toupper convierte a mayuscula
	
}

void datosDeVentas(){
	char sigue;

	do{
		system("cls");
		
		cuadro(10,7,70,17);
		cuadro(18,3,38,5);
		SetConsoleTextAttribute (hConsoleHandle, 10);
		gotoxy(20,04); printf("INGRESANDO DATOS");

		SetConsoleTextAttribute (hConsoleHandle, 6);
		gotoxy(12,8); printf("Ingrese el tipo de producto: ");
		scanf("%i", &tipoProducto);
		gotoxy(12,10); printf("Ingrese la cantidad vendida: ");
		scanf("%i", &cantidadVendidas);
		
		//asignarProducto(tipoProducto);
		
		switch(tipoProducto){
			case 1: stockActualCamisas -= cantidadVendidas; break;
			case 2: stockActualPantalones -= cantidadVendidas; break;
			case 3: stockActualMedias -= cantidadVendidas; break;
		}

		do{
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,18);printf("Desea Continuar S/N");
			sigue=getch();

		}while (toupper(sigue)!='S' && toupper(sigue)!='N');
		
	}while (tolower(sigue)=='s');
	//tolower convierte a minuscula
	//toupper convierte a mayuscula
}

void menu(){
	char opc,conti;
//HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
	
	do{
		
		system("cls");
		cuadro(16,2,65,6); //primer cuadro de arriba hacia abajo
		cuadro(8,8,72,22);//grande
		cuadro(8,23,72,25); //cuadro de abajo opcion es
		cuadro(56,19,68,21); //cuadro pequeño salir

		SetConsoleTextAttribute (hConsoleHandle, 10);
	    gotoxy(22,4);printf("***** MENU PRINCIPAL DEL PROGRAMA *****");
        SetConsoleTextAttribute (hConsoleHandle, 15);
        gotoxy(15,10);printf("[1]  MOSTRAR STOCK ACTUAL");
	    gotoxy(15,12);printf("[2]  INGRESAR NUEVAS EXISTENCIAS");
		gotoxy(15,14);printf("[3]  INGRESAR DATOS DE VENTAS");
		gotoxy(15,16);printf("[4]  MOSTRAR STOCK ACTUALIZADO");
		gotoxy(57,20);printf("<[5] SALIR>");
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,24);printf("Su opcion es: ");
		opc=getch();

		switch(opc)
		{
		case '1': mostrarStock();break;
		case '2': ingresar_existencias(); break;
		case '3': datosDeVentas(); break;
		case '4': mostrarStock();break;
		case '5': 
				
			system("cls");
			gotoxy(20,10);printf("Estas seguro Que Deseas Salir del Sistema");
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,15);printf("Desea Continuar S/N");
			conti=getch();

			if (conti=='N' || conti=='n')
				menu();
			else if (conti=='S' || conti=='s')

		
				break; 
		
		}
			

		}while(opc!='5');

}

int main(int argc, char** argv) {
	menu();
	return 0;
}
