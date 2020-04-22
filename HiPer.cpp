
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct sDatos{
int valor;
char *nombre=new char[10];
char *ecuacion=new char[20];
};

bool diferente(char* n){
for(int i=0;i<strlen(n);i++){
    if(*(n+i)=='\n'){
        return false;
    }
}
return true;
}
void imprimir_matriz(sDatos** dato,int filas, int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<(*(*(dato+i)+j)).valor<<" ";
        }
        cout<<endl;
    }
}

void iniciar_ceros(sDatos** dato){
for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
        (*(*(dato+i)+j)).valor=0;
    }
}
}

void pegar_nombre(sDatos** dato){
char *letra=new char[10];
char *numero=new char[10];
for(int i=0;i<20;i++){
    for(int j=0;j<20;j++){
         *(letra+0)=char(j+65);
         itoa(i+1,numero,10);
         strcpy((*(*(dato+i)+j)).nombre,letra);
         strcat((*(*(dato+i)+j)).nombre,numero);
         strcpy((*(*(dato+i)+j)).ecuacion,(*(*(dato+i)+j)).nombre);
    }
}
}


bool verificar_n(char* n){
    for(int i=0;i<strlen(n);i++){
        if(*(n+i)=='='){
            return true;
        }
    }
    return false;
}

char* quitar_igual(char*pal){
for(int i=0;i<strlen(pal)+1;i++){
        *(pal+i)=*(pal+i+1);
}
return pal;
}

void sumar(sDatos**&dato,int filas,int columnas,int columna,int fila,char*n){
    int cont_suma=0;
    char* aux=n;
    for(int i=0;i<strlen(n);i++){
         if(*(n+i)=='+'){
            cont_suma++;
        }
    }
    aux=quitar_igual(aux);
    int h=0;
    char*aux1=new char[10];
    strtok(aux,"+");
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(strcmp((*(*(dato+i)+j)).nombre,aux)==0){
                (*(*(dato+fila)+columna)).valor+=(*(*(dato+i)+j)).valor;
                }
            }
        }
        while(h<cont_suma){
        if(h==cont_suma-1){
        aux=strtok(NULL,"\n");
        }
        else{
            aux=strtok(NULL,"+");
        }
        bool b=false;
        for(int i=0;i<filas&&b==false;i++){
            for(int j=0;j<columnas&&b==false;j++){
                if(strcmp((*(*(dato+i)+j)).nombre,aux)==0){
                    (*(*(dato+fila)+columna)).valor+=(*(*(dato+i)+j)).valor;
                    b=true;
                }
            }
        }
         h++;
    }
}


void calcular(sDatos**&dato,int filas,int columnas){
for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
    }
}

for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
        if(!verificar_n((*(*(dato+i)+j)).ecuacion)){
            (*(*(dato+i)+j)).valor=atoi((*(*(dato+i)+j)).ecuacion);
        }
    }
}


for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
        if(verificar_n((*(*(dato+i)+j)).ecuacion)){
           sumar(dato,filas,columnas,j,i,(*(*(dato+i)+j)).ecuacion);
        }
    }
}
}

void pegar_plantilla(char* nombre_plantilla,char* nombre, char* apellido,sDatos**dato,int filas,int columnas){
ifstream plantilla(nombre_plantilla,ios::in);
char*nombre_completo=new char[40];
char*ciudad="BOGOTA";
strcpy(nombre_completo,nombre);
strcat(nombre_completo,apellido);
strcat(nombre_completo,".txt");
ofstream salida(nombre_completo,ios::out);
char*n=new char[200];
bool b=true;
char*pal=new char[30];
cout<<"FILAS "<<filas<<" "<<"columnas "<<columnas<<endl;
while(!plantilla.eof()&&b==true){
    plantilla.getline(n,200,'<');
    salida<<n;
    plantilla.getline(n,200,'\n');
    salida<<nombre<<" "<<apellido<<'\n'<<ciudad<<'\n';
    plantilla.getline(n,200,'\n');
    plantilla.getline(n,200,'<');
    salida<<n<<" ";
    itoa((*(*(dato+0)+columnas-1)).valor,pal,10);
    salida<<pal;
    plantilla.getline(n,200,'>');
    plantilla.getline(n,200,'<');
    salida<<n<<" ";
    itoa((*(*(dato+filas-1)+columnas-1)).valor,pal,10);
    salida<<pal;
    plantilla.getline(n,200,'<');
    plantilla.getline(n,200,'>');
    plantilla.getline(n,200,'<');
    salida<<n<<" ";
    plantilla.getline(n,200,'>');
    itoa((*(*(dato+filas-1)+0)).valor,pal,10);
    salida<<pal;
    plantilla.getline(n,200,'<');
    salida<<n<" ";
    cout<<filas/2<<" "<<columnas/2<<endl;
    itoa(filas/2,pal,10);
    salida<<"("<<pal<<",";
    itoa(columnas/2,pal,10);
    salida<<pal<<")";
    plantilla.getline(n,200,'>');
    plantilla.getline(n,200,'\0');
    salida<<n;

    b=false;

}
plantilla.close();
salida.close();
}

leer_datos(sDatos** &dato,char* nombre,int &filas, int &columnas){
ifstream entrada(nombre,ios::in);
ifstream nombres("nombres.txt",ios::in);
char*n=new char[30];
char c;
int cont=0,i=0,j=0;
char* veces=new char[10];
bool b=false;
char*nombre_persona=new char[30];
char*apellido=new char[30];
char*nombre_plantilla="plantilla.txt";
if(!nombres){
    cout<<"Error: no abrio";
}
bool cond=true;
while(!nombres.eof()&&cond){
    nombres.getline(nombre_persona,30,' ');
    nombres.getline(apellido,30,'\n');
    cout<<nombre_persona<<" "<<apellido<<endl;
    cond=false;
    system("pause");
}
char*numer;
while(!entrada.eof()&&b==false){
        if(cont==0){
            entrada.getline(veces,10,'\n');
            cont++;
        }
        else{
            for(int m=0;m<atoi(veces);m++){
                itoa(m+1,numer,10);
                strcat(apellido,numer);
                entrada.getline(n,30,' ');
                columnas=atoi(n);
                entrada.getline(n,30,'\n');
                filas=atoi(n);
                cout<<veces<<endl;
                cout<<columnas<<" "<<filas<<endl;
                int contador;
                for(int j=0;j<filas;j++){
                    contador=0;
                    for(int i=0;i<columnas;i++){
                        contador++;
                        if(contador==columnas){
                            entrada.getline(n,30,'\n');
                        }
                        else{
                            entrada.getline(n,30,' ');
                        }
                        strcpy((*(*(dato+j)+i)).ecuacion,n);

                }
                }
                   b=true;
                   calcular(dato,filas,columnas);
                    pegar_plantilla(nombre_plantilla,nombre_persona,apellido,dato,filas,columnas);
                   imprimir_matriz(dato,filas,columnas);
                   iniciar_ceros(dato);
            }
}
}
}




int main(){
    int filas,columnas;
    sDatos **dato=new sDatos*[20];
    for(int i=0;i<20;i++){
        *(dato+i)=new sDatos[20];
    }
    char*nombre=new char[30];
    cout<<"Nombre del archivo?"<<endl;
    cin>>nombre;
    iniciar_ceros(dato);
    pegar_nombre(dato);
    leer_datos(dato,nombre,filas,columnas);
}


