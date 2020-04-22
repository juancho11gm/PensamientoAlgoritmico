#include <iostream>
#include<stdlib.h>
using namespace std;

//Información de los jugadores
struct Jugador{
	int id;
	string nombre;
	string apellido;
	string correo;
	int partidasG;//partidas ganadas
	int partidasP;//partidas perdidas
	int partidasJ;//partidas jugadas
};

//Funciones del prgrama. Especificadas más abajo
Jugador crearJugador(Jugador jugadores[],int cantJugadores);
int ingresarUsuarios(Jugador jugadores[],int cantJugadores);
void mostrarJugadores(Jugador jugadores[],int cantJugadores);
void iniciarTablero(char tablero1[10][10],char tablero2[10][10]);
void imprimirTablero(char tablero[10][10]);
void ponerBarcos(char tablero1[10][10],char tablero2[10][10],Jugador jugador1,Jugador jugador2);
void barco(char tablero1[10][10],char tablero2[10][10],Jugador jugador,int nPuntos);
void ordenar(int nPuntos,int arreglo[4]);
bool verificarPunto(int x,int y,int posX[4],int posY[4],int nPuntos);
bool verificarGanador(char tablero[10][10]);
bool disparar(Jugador jugador,char tablero[10][10],char ataque[10][10],char defensa2[10][10]);

int main(){
	system ("color 0A" );
	Jugador jugadores[20];//vector jugadores. máximo 20
	Jugador jugador1,jugador2;//los dos jugadores que estarán en el programa
	jugador1.id=-1;
	jugador2.id=-1;
	char matriz1 [10][10],matriz2 [10][10],ataque1[10][10],ataque2[10][10]; //cuatro tableros. 2 para cada jugador. 1 ataque y 1 defensa
	int cantJugadores=0,opcionInicio,aux;//cantidad de jugadores registrados. Opcion inicio (1,2,3,4)
	bool salirInicio=false,entraron=false,ganador=false;
	 while(salirInicio==false){//Se ejecuta hasta que el usuario desee salir
        do{
        	entraron=false;
        	system("cls");//Imprimir el menu
        	cout<<"*****************BATALLA NAVAL*****************"<<endl;
        	cout<<"1. Crear un usuario"<<endl;
            cout<<"2. Jugar partida"<<endl;
            cout<<"3. Desplegar informacion jugadores"<<endl;
            cout<<"4. Salir"<<endl;
            cin>>opcionInicio;
             if(opcionInicio<1||opcionInicio>4){
                cout<<"Ingrese una opcion valida por favor"<<endl;
                system("pause");//presione una tecla para continuar
                system("cls");//borra la consola
            }
            system("cls");
        }while(opcionInicio<1||opcionInicio>4);
		switch(opcionInicio){
			case 1: {//CREAR JUGADOR
				iniciarTablero(matriz1,matriz2);
				jugadores[cantJugadores]=crearJugador(jugadores,cantJugadores);//creacion de un jugador y se almacena en el vector de Jugadores
				cantJugadores++;
                system("PAUSE");
                break;
			}
			case 2:{//JUGAR
				cout<<"Identificacion jugador 1"<<endl;
				aux=ingresarUsuarios(jugadores,cantJugadores);
				if(aux!=-1){
					jugador1=jugadores[aux];
					cout<<"Ingreso satisfactorio"<<endl;
					system("PAUSE");
					system("cls");
					do{
						cout<<"Identificacion jugador 2"<<endl;
						aux=ingresarUsuarios(jugadores,cantJugadores);
						if(aux==jugador1.id-1){//mismo jugador ingresado
							cout<<"No puede jugar con el mismo jugador"<<endl;
							aux=-1;
						}
						if(aux!=-1){
							jugador2=jugadores[aux];
							entraron=true;
							cout<<"Ingreso satisfactorio"<<endl;
							system("PAUSE");
							system("cls");
						}
					}while(aux==jugador1.id-1);
				}
				if(entraron==true){
					ganador=false;
					iniciarTablero(matriz1,matriz2);
					iniciarTablero(ataque1,ataque2);
					imprimirTablero(matriz1);
					cout<<"TABLERO PROPIO "<<jugador1.nombre<<" DEFENSA"<<endl<<endl;
					ponerBarcos(matriz1,matriz2,jugador1,jugador2);
					do{
						disparar(jugador1,matriz1,ataque1,matriz2);
						if(verificarGanador(matriz2)){
							ganador=true;
							system("cls");
							imprimirTablero(matriz1);
							imprimirTablero(ataque1);
							cout<<"FELICITACIONES GANADOR "<<jugador1.nombre<<endl;
							system("PAUSE");
							jugadores[jugador1.id-1].partidasG++;
							jugadores[jugador1.id-1].partidasJ++;
							jugadores[jugador2.id-1].partidasP++;
							jugadores[jugador2.id-1].partidasJ++;
						}else{
							disparar(jugador2,matriz2,ataque2,matriz1);
							if(verificarGanador(matriz1)){
								ganador=true;
								system("cls");
								imprimirTablero(matriz2);
								imprimirTablero(ataque2);
								cout<<"FELICITACIONES GANADOR "<<jugador2.nombre<<endl;
								system("PAUSE");
								jugadores[jugador2.id-1].partidasG++;
								jugadores[jugador2.id-1].partidasJ++;
								jugadores[jugador1.id-1].partidasP++;
								jugadores[jugador1.id-1].partidasJ++;
							}
						}

					}while(ganador==false);
					ganador=false;
				}
				system("PAUSE");
				break;
			}
			case 3:{//MOSTRAR INFORMACIÓN DE LOS JUGADORES
				mostrarJugadores(jugadores,cantJugadores);
				system("PAUSE");
				break;
			}
			case 4:{
				//SALIR DEL JUEGO
				salirInicio=true;
				system("cls");
				cout<<"HASTA LUEGO"<<endl;
				break;
			}
		}
    }
}

//Fución encargada de crear un jugador solicitando la información básica.

Jugador crearJugador(Jugador jugadores[],int cantJugadores){
	Jugador x;
	string correo;
	bool registrado;
	do{
		system("cls");
		registrado=false;
		cout<<"Ingrese su correo por favor"<<endl;
		cin>>correo;
		for(int i=0;i<cantJugadores;i++){
			if(correo==jugadores[i].correo){//No se podrá usar el mismo correo en 2 jugadores
				cout<<"Lo siento, el correo ya esta registrado"<<endl;
				system("PAUSE");
				registrado=true;
			}
		}
	}while(registrado==true);
	x.correo=correo;
	//inicialización partidas
	x.partidasG=0;
	x.partidasP=0;
	x.partidasJ=0;
	x.id=cantJugadores+1;
	cout<<"Ingrese su nombre por favor (sin espacios)"<<endl;
	cin>>x.nombre;
	cout<<"Ingrese su apellido por favor (sin espacios)"<<endl;
	cin>>x.apellido;
	cout<<"Su cuenta ha sido creada exitosamente"<<endl;
	return x;//retorna el jugador creado
}
//Función encargada de mostrar la información de los jugadores recorriendo el vector Jugadores.
void mostrarJugadores(Jugador jugadores[],int cantJugadores){
	for(int i=0;i<cantJugadores;i++){
		cout<<"*****Usuarios******"<<endl;
		cout<<"ID jugador: "<<jugadores[i].id<<endl;
		cout<<"Nombre: "<<jugadores[i].nombre<<" "<<jugadores[i].apellido<<endl;
		cout<<"Correo: "<<jugadores[i].correo<<endl;
		cout<<"Partidas jugadas: "<<jugadores[i].partidasJ<<endl;
		cout<<"Partidas ganadas: "<<jugadores[i].partidasG<<endl;
		cout<<"Partidas perdidas: "<<jugadores[i].partidasP<<endl;
		cout<<endl;
	}
}
//Función encargada del ingreso de los usuarios solicitando el correo con el que se registraron
int ingresarUsuarios(Jugador jugadores[],int cantJugadores){
	string correoEntrar;
	bool encontro;
	cout<<"Ingrese correo del jugador por favor"<<endl;
    cin>>correoEntrar;
    encontro=false;
    for(int i=0;i<cantJugadores;i++){
       	if(jugadores[i].correo==correoEntrar){
       		encontro=true;
			return i;
		}
	}
	if(encontro==false){//nunca encontró el correo
		cout<<"No se encontro el correo"<<endl;
		return -1;
	}

}
//Inicializa el tablero para jugar una nueva partida
void iniciarTablero(char tablero1[10][10],char tablero2[10][10]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			tablero1[i][j]='-';
			tablero2[i][j]='-';
		}
	}
}
//Función encargada de solicitar las coordenadas de los barcos en los tableros para cada jugador
void ponerBarcos(char tablero1[10][10],char tablero2[10][10],Jugador jugador1,Jugador jugador2){
	int i;
	for(i=0;i<2;i++){
		cout<<"COLOCAR LANCHA ACUATICA "<<i+1<<endl;
		barco(tablero1,tablero2,jugador1,2);
	}
	system("cls");
	imprimirTablero(tablero1);
	cout<<"TABLERO PROPIO "<<jugador1.nombre<<" DEFENSA"<<endl<<endl;
	for(i=0;i<2;i++){
		cout<<"COLOCAR BUQUE BOMBARDERO "<<i+1<<endl;
		barco(tablero1,tablero2,jugador1,3);
	}
	system("cls");

	imprimirTablero(tablero1);
	cout<<"TABLERO PROPIO "<<jugador1.nombre<<" DEFENSA"<<endl<<endl;
	cout<<"COLOCAR BUQUE PORTA AVIONES "<<1<<endl;
	barco(tablero1,tablero2,jugador1,4);

	system("PAUSE");
	system("cls");

	imprimirTablero(tablero2);
	cout<<"TABLERO PROPIO "<<jugador2.nombre<<" DEFENSA"<<endl<<endl;
	for(i=0;i<2;i++){
		cout<<"COLOCAR LANCHA ACUATICA "<<i+1<<endl;
		barco(tablero2,tablero1,jugador2,2);
	}
	system("cls");
	imprimirTablero(tablero2);
	cout<<"TABLERO PROPIO "<<jugador2.nombre<<" DEFENSA"<<endl<<endl;
	for(i=0;i<2;i++){
		cout<<"COLOCAR BUQUE BOMBARDERO "<<i+1<<endl;
		barco(tablero2,tablero1,jugador2,3);
	}
	system("cls");
	imprimirTablero(tablero2);
	cout<<"TABLERO PROPIO "<<jugador2.nombre<<" DEFENSA"<<endl<<endl;
	cout<<"COLOCAR BUQUE PORTA AVIONES "<<1<<endl;
	barco(tablero2,tablero1,jugador1,4);

}

//Función encargada de poner los 3 tipos de barco. Recibe los tableros y de acuerdo al numero de puntos se sabrá qué tipo de barco es.
void barco(char tablero1[10][10],char tablero2[10][10],Jugador jugador,int nPuntos){
	int x=0,y=0,contador=0;
	char posy;
	bool salir=false;
	int posX [4];
	int posY [4];
	do{
		do{
			cout<<"Ingrese posicion X (Numero)"<<endl;
			cin>>x;
			if(x>10||x<1){
				cout<<"Ingrese una coordenada valida"<<endl;
			}
		}while(x>10||x<1);
		do{
			cout<<"Ingrese posicion Y (Letra mayuscula)"<<endl;
			cin>>posy;
			y=int(posy)-64;
			if(y>10||y<1){
				cout<<"Ingrese una coordenada valida"<<endl;
			}
		}while((int(posy)-64>10||int(posy)-64<1));
				if(tablero1[y-1][x-1]!='B'&&tablero1[y-1][x-1]!='R'&&tablero1[y-1][x-1]!='P'){
					switch(contador){
						case 0:{//primera coordenada
							posX[contador]=x;
							posY[contador]=y;
							if(nPuntos==2){
								tablero1[y-1][x-1]='R';
							}
							if(nPuntos==3){
								tablero1[y-1][x-1]='B';
							}
							if(nPuntos==4){
									tablero1[y-1][x-1]='P';
							}
							contador++;
							break;
						}
						case 1:{//segunda coordenada
							if(verificarPunto(x,y,posX,posY,2)){
								posX[contador]=x;
								posY[contador]=y;
								if(nPuntos==2){
									tablero1[y-1][x-1]='R';
								}
								if(nPuntos==3){
									tablero1[y-1][x-1]='B';
								}
								if(nPuntos==4){
									tablero1[y-1][x-1]='P';
								}
								contador++;
							}else{
								cout<<"DEBE SER CONSIGUIENTE (VERTICAL/DIAGONAL) A PUNTOS INGRESADOS ANTERIORMENTE"<<endl;
							}
							break;
						}
						case 2:{//tercera coordenada
							if(verificarPunto(x,y,posX,posY,3)){
								posX[contador]=x;
								posY[contador]=y;
								if(nPuntos==3){
									tablero1[y-1][x-1]='B';
								}
								if(nPuntos==4){
									tablero1[y-1][x-1]='P';
								}
								contador++;
							}else{
								cout<<"DEBE SER CONSIGUIENTE (VERTICAL/DIAGONAL) A PUNTOS INGRESADOS ANTERIORMENTE"<<endl;
							}
							break;
						}
						case 3:{//cuarta coordenada
							if(verificarPunto(x,y,posX,posY,4)){
								posX[contador]=x;
								posY[contador]=y;
								if(nPuntos==4){
									tablero1[y-1][x-1]='P';
								}
								contador++;
							}else{
								cout<<"DEBE SER CONSIGUIENTE (VERTICAL/DIAGONAL) A PUNTOS INGRESADOS ANTERIORMENTE"<<endl;
							}
							break;
						}
					}
				}else{
					cout<<"POSICION YA INGRESADA"<<endl;
				}
			system("PAUSE");
			system("cls");
			imprimirTablero(tablero1);
			cout<<"TABLERO PROPIO "<<jugador.nombre<<" DEFENSA"<<endl<<endl;
			if(contador==nPuntos){
				salir=true;
			}
		}while(salir==false);
}
bool verificarPunto(int x,int y,int posX[4],int posY[4],int nPuntos){
	if(nPuntos==2){//verificar que dos puntos son consiguientes. (verticales/horizontales)
		if(y==posY[0]&&posX[0]==x-1){
		return true;
		}
		if(x==posX[0]&&y==posY[0]+1){
			return true;
		}
		if(y==posY[0]&&posX[0]==x+1){
			return true;
		}
		if(x==posX[0]&&y==posY[0]-1){
			return true;
		}
	}
	int i,j,aux,auxY[4],auxX[4];
		for (i=0;i<nPuntos-1;i++){
			auxX[i]=posX[i];
			auxY[i]=posY[i];
		}
		auxX[nPuntos-1]=x;
		auxY[nPuntos-1]=y;
	if(nPuntos==3){//verificar que tres puntos son consiguientes. (verticales/horizontales)
		if(posX[0]==posX[1]&&posX[0]==x){
			ordenar(nPuntos,auxY);
			if(auxY[0]+1==auxY[1]&&auxY[1]+1==auxY[2]){
				return true;
			}
		}
		if(posY[0]==posY[1]&&posY[0]==y){
			ordenar(nPuntos,auxX);
			if(auxX[0]+1==auxX[1]&&auxX[1]+1==auxX[2]){
				return true;
			}
		}
	}
	if(nPuntos==4){//verificar que cuatro puntos son consiguientes. (verticales/horizontales)
		if(posX[0]==posX[1]&&posX[1]==posX[2]&&posX[2]==x){
			ordenar(nPuntos,auxY);
			if(auxY[0]+1==auxY[1]&&auxY[1]+1==auxY[2]&&auxY[2]+1==auxY[3]){
				return true;
			}
		}
		if(posY[0]==posY[1]&&posY[0]==y){
			ordenar(nPuntos,auxX);
			if(auxX[0]+1==auxX[1]&&auxX[1]+1==auxX[2]&&auxX[2]+1==auxX[3]){
				return true;
			}
		}
	}

	return false;
}

void ordenar(int nPuntos,int arreglo[4]){//ordena las coordenadas de menor a mayor para saber si los puntos son consiguientes. (verticales/horizontales)
	int i,j,aux;
	for(i=0;i<nPuntos;i++){
				for(j=0;j<nPuntos;j++){
					if(arreglo[i]<arreglo[j]){
						aux=arreglo[i];
						arreglo[i]=arreglo[j];
						arreglo[j]=aux;
				}
			}
		}
}
//Función encargada de imprimir los tableros de los jugadores
void imprimirTablero(char tablero[10][10]){
	for(int k=0;k<10;k++){
		cout<<" "<<k+1<<" ";
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(j==0){
				cout<<char(65+i)<<" "<<tablero[i][j]<<" ";
			}else{
				cout<<" "<<tablero[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}

bool verificarGanador(char tablero[10][10]){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(tablero[i][j]=='B'||tablero[i][j]=='R'||tablero[i][j]=='P'){
				return false;
			}
		}
	}
	return true;
}
bool disparar(Jugador jugador,char tablero[10][10],char ataque[10][10],char defensa2[10][10]){
	int x,y;
	char posy;
	do{
		system("cls");
		cout<<"**************ATAQUE-DISPARAR***************"<<endl;
		imprimirTablero(tablero);
		cout<<"TABLERO PROPIO "<<jugador.nombre<<" DEFENSA"<<endl<<endl;
		imprimirTablero(ataque);
		cout<<"TABLERO ENEMIGO "<<jugador.nombre<<" ATAQUE"<<endl<<endl;
		do{
			cout<<"Ingrese posicion X (Numero)"<<endl;
			cin>>x;
			if(x>10||x<1){
				cout<<"Ingrese una coordenada valida"<<endl;

			}
		}while(x>10||x<1);
		do{
			cout<<"Ingrese posicion Y (Letra mayuscula)"<<endl;
			cin>>posy;
			y=int(posy)-64;
			if(y>10||y<1){
				cout<<"Ingrese una coordenada valida"<<endl;
			}
		}while((int(posy)-64>10||int(posy)-64<1));
		if(ataque[y-1][x-1]=='X'||ataque[y-1][x-1]=='O'){
			cout<<"Coordenada ya atacada"<<endl;
			system("PAUSE");
		}
	}while(ataque[y-1][x-1]=='X'||ataque[y-1][x-1]=='O');
	if(defensa2[y-1][x-1]=='B'||defensa2[y-1][x-1]=='R'||defensa2[y-1][x-1]=='P'){
		ataque[y-1][x-1]='X';
		defensa2[y-1][x-1]='X';
		cout<<"OBJETIVO ATACADO"<<endl;
		system("PAUSE");
	}else{
			ataque[y-1][x-1]='O';
			cout<<"OBJETIVO FALLIDO"<<endl;
			system("PAUSE");
	}
	system("cls");
	cout<<"**************ATAQUE-DISPARAR***************"<<endl;
	imprimirTablero(tablero);
	cout<<"TABLERO PROPIO "<<jugador.nombre<<" DEFENSA"<<endl<<endl;
	imprimirTablero(ataque);
	cout<<"TABLERO ENEMIGO "<<jugador.nombre<<" ATAQUE"<<endl<<endl;
	system("PAUSE");
	return verificarGanador(defensa2);
}


