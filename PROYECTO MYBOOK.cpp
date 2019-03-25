#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 50

//recuerden por favor marcar todas las partes que hayan sido modificadas recientemente


struct cumpleanios 
{
	int di;
	int me;
	int an;
};

struct trik
{
	int ganado;
	int perdido;
	int jugado;
	int empatado;
};

struct usuario
{
    string uss;
    bool activo;
    string name[2];
    string cont;
    int edad;
    bool mostedad;
	bool admin;
	cumpleanios cumple;
	int cantamis;
	bool mostamigos;
	string amigos[MAX][2];
	bool mostco;
	string correo;
	bool mostgen;
	string genero;
	bool mostcumple;
	int cantpelifav;
	string pelifav[MAX*2];
	int cantsolic;
	string solicitudes[MAX][2];
	trik partri;
};

struct peli
{
    string nompeli;
    string generopeli;
    string resumen;
};

bool existe (string uss,string cont,usuario base[], int maxus);//busca existencia de usuario y contrasena
bool buscuss (string uss,usuario base[],int maxus);//busca existencia de usuario
bool existecorr (string noma,string contras,usuario base[],int maxus);
int idbusc (usuario base[],int maxus,string uss);//busca id de usuario
usuario registro (usuario base[], int tam);//pedir datos personales
void impus(usuario base,int maxus);//imprimir info usuarios
void publicoopersonal(bool a);//imprimir si es publico o personal
bool cambiopublicoopersonal(bool a);//cambia de publico a personal, o viceversa
void impmat (char cells[][MAX],int tamx,int tamy);//juego e la vida imprimir
void lavida (char cells[][MAX],int tamx,int tamy);//juego e la vida
void juegovida();//juego de la vida
int triqui();
int verificar(char matriz[][3]);//triqui
int idbuscor (usuario base[],int maxus,string noma);



main()
{
system("color 7C");
	bool rep=false;
    usuario base[MAX];
    peli pelicula[MAX*2];
	char all;
	bool salir=false,sesion=false;
	int maxus=2,tampeli=3;
	string uss, cont;
	int id,elimpeli, aceptarsolicitud;
	
	pelicula[0].nompeli="uno";
	pelicula[0].generopeli="comedia";
	pelicula[0].resumen="buahaha";
	
	pelicula[1].nompeli="dos";
	pelicula[1].generopeli="accion";
	pelicula[1].resumen="piu piu";
	
	pelicula[2].nompeli="tres";
	pelicula[2].generopeli="horror";
	pelicula[2].resumen="buuuu";
	
	base[0].uss="admindd";
	base[0].cont="wasd";
	base[0].admin=true;
	base[0].activo=true;
	base[0].correo="no";
	base[0].name[0]="dan";
	
	base[1].uss="prueba";
	base[1].cont="hola";
	base[1].admin=false;
	base[1].activo=true;
	base[1].correo="danh@hotmail.com";
	base[1].name[0]="daniel";
	base[1].name[1]="hamilton";
	base[1].cumple.an=1998;
	base[1].cumple.me=8;
	base[1].cumple.di=28;
	base[1].genero="hombre";
	base[1].mostamigos=true;
	base[1].mostco=true;
	base[1].mostcumple=true;
	base[1].mostedad=true;
	base[1].mostgen=true;
	base[1].edad=17;

	while (salir==false)
	{
		cout<<"1.registrarse \n2.ingreso\n3.salir"<<endl;
		cin>>all;
		system("cls");
		sesion=true;

		switch (all)
		{

			case '1'://registro//funciona
				{

					cout<<"usuario : ";
					cin>>uss;
					cout<<"contrasena : ";
					cin>>cont;

					sesion=buscuss(uss,base,maxus);
	
					if (sesion==false)
					{
						
						base[maxus]=registro(base,maxus);//pide datos personales
						base[maxus].uss=uss;
						base[maxus].cont=cont;
						maxus+=1;
						
					}
					else
					{
						cout<<"usuario existente"<<endl;
					}
					
					
					
					

				}break;

			case '2'://ingreso//funciona
				{
					cout<<"usuario : ";
					cin>>uss;
					cout<<"contrasena : ";
					cin>>cont;

					sesion=existe(uss,cont,base,maxus);

					if (sesion==true)
					{
						cout<<"usuario o contrasena equivocados"<<endl;
					}
					else 
					{
						id=idbusc(base,maxus,uss);
					}
					while (sesion==false)//inicio de sesion exitoso
					{
					    if (base[id].admin==true)
                        {
                            cout<<"m.administracion"<<endl;
                        }
                        rep=false;
							
						cout<<"1.perfil\n2.amigos\n3.peliculas\n4.juegos\n5.cerrar sesion"<<endl;
						cin>>all;

                        if(all=='m'&&base[id].admin==false)
                        {
                            all=0;
                        }
						switch (all)
						{
							case'm'://administracion//hamilton//funciona
								{
									while(rep==false)
									{
									system("cls");
									cout<<"1.asignar administradores\n2.ver usuarios\n3.peliculas\nv.volver"<<endl;
									cin>>all;

									switch (all)
										{
										case'1'://asignar administradores//funciona
											{

												cout<<"1.buscar usuario\n2.asignar administrador\n3.remover administrador "<<endl;
												cin>>all;

												switch (all)
												{
													
													
													case'1'://buscar usuarios//funciona
														{
															int usss,u;
															cout<<"usuario a buscar : ";
															cin>>uss;
															
															u=idbusc(base,maxus,uss);
													
															if (u!=0)
															{
																cout<<"id : "<<u<<endl;
																cout<<"usuario : "<<base[u].uss<<endl;
																cout<<"nombre y apellido : "<<base[u].name[0]<<" "<<base[u].name[1]<<endl;
																cout<<"genero : "<<base[u].genero<<endl;
																cout<<"edad : "<<base[u].edad<<endl;
																cout<<"cumple : ("<<base[u].cumple.an<<"/"<<base[u].cumple.me<<"/"<<base[u].cumple.di<<")"<<endl;
																cout<<"correo : "<<base[u].correo<<endl;
																
																if (base[u].activo)
																{
																	cout<<"activo"<<endl;
																}
																else
																{
																	cout<<"inactivo"<<endl;
																}
																
																if (base[u].admin)
																{
																	cout<<"admin";
																}  
															
															}
															else
															{
																cout<<"usuario no encontrado"<<endl;
															}	
															system("pause");
														}break;

													case'2'://asignar administrador//funciona
														{
                                                            
															cout<<"usuario : ";
															cin>>uss;
															bool u;
															u=buscuss(uss,base,maxus);
															
															if (u==true)
															{
																for (int a =0;a<maxus;a++)
																{
																	if (base[a].uss==uss)
																	{
																		base[a].admin=true;
																	}
																}
															}																
															
															
														}break;
													case'3'://remover administrador//funciona
														{
															int u,c=0;
															cout<<"administradores :"<<endl;
															for (int a=0;a<maxus;a++)
															{
																if (base[a].admin==true&&a!=id)
																{
																	cout<<base[a].uss<<" id : "<<a<<endl;
																	c++;
																}
															}
															
															if (c!=0)
															{
																cout<<endl<<"insertar id de admin a eliminar : ";
																cin>>u;
																
																if (u>0&&u<50&&base[u].admin==true)
																{
																	base[u].admin=false;
																}
																else
																{
																	cout<<"el usuario no es administrador"<<endl;
																}	
															}
															else
															{
																cout<<"no hay mas administradores"<<endl;
															}
															system("pause");
															
														}break;

													default:
														{
															cout<<"opcion no valida"<<endl;
														}break;
										}
											}break;
										case'2'://ver usuarios//funciona
											{
													for (int a=0;a<maxus;a++)
                                                            {
                                                            	impus(base[a],maxus);
																
															}system ("pause");
											}break;
										case'3'://peliculas//sebastian//funciona
											{
												char respeli;
												system("cls");
												
												cout<<"1.crear pelicula\n2.modificar pelicula\n3.eliminar pelicula"<<endl;
												cin>>all;
												
												switch (all)
												{
												case'1': //crear pelicula//funciona
														{ 
															cout<<"introducir palabras sin espacios, o con _ "<<endl;
														    do{
                                                                    cout<<"Nombre"<<endl;
                                                                    cin>>pelicula[tampeli].nompeli;
                                                                    
                                                                    cout<<"Genero"<<endl;
                                                                    cin>>pelicula[tampeli].generopeli;
                                                                    
                                                                    
                                                                    cout<<"resena"<<endl;
                                                                    cin>>pelicula[tampeli].resumen;//---------------------------------------------------------------------- probar "getline(cin,pelicula[tampeli].resumen)
                                                                
                                                                    
                                                                    cout<<"Alguna otra pelicula? (s/n)"<<endl;
                                                                    cin>>respeli;
                                                                    
                                                                    tampeli++;
														    }while(respeli=='S'||respeli=='s');
														}break;
														
													case'2'://moficiar pelicula//funciona
														{ int modificarpeli;
														
														    for(int i=0;i<tampeli;i++){
                                                                cout<<"Pelicula "<<i+1<<" "<<pelicula[i].nompeli<<endl<<endl;
														    }
                                                                do{
                                                                cout<<"Cual pelicula desea modificar? (#))"<<endl;
                                                                cin>>modificarpeli;
                                                                
                                                                modificarpeli--;
                                                                
                                                                cout<<"Nuevo nombre de la pelicula?"<<endl;
                                                                cin>>pelicula[modificarpeli].nompeli;
                                                                
                                                                cout<<"Genero de la pelicula"<<endl;
                                                                cin>>pelicula[modificarpeli].generopeli;
                                                                
                                                                cout<<"resena"<<endl;
                                                                cin>>pelicula[modificarpeli].resumen;
                                                                
                                                                cout<<"Alguna otra pelicula? (s/n)"<<endl;
                                                                cin>>respeli;
                                                                
														    }while(respeli=='S'||respeli=='s');
														}break;
														
													case'3'://eliminar pelicula//funciona
														{
														    
														    do{
														    	for(int i=0;i<tampeli;i++){
                                                                cout<<"Pelicula :"<<i+1<<" "<<pelicula[i].nompeli<<endl;
														    }
														    	
														  	  cout<<"# Pelicula que quiere eliminar?";
														  	  cin>>elimpeli;
														  	  elimpeli--;
														  	  if (tampeli==0)
														  	  {
														  	  		cout<<" no hay peliculas para eliminar"<<endl;
																}
														  	  else
														  	  {
														  	  	if(elimpeli>=0&&elimpeli<tampeli)
														  	  {
														  	  	 for(int i=elimpeli;i<tampeli;i++){
                                                         				    pelicula[i]=pelicula[i+1];
														 			   }
																 	   tampeli--;
																 	   
																    
															    
																}
																else
																{
																	
																}
																}
														  	
															cout<<"Eliminar alguna otra pelicula? (s/n)"<<endl;
                                                        	cin>>respeli;
															}while(respeli=='S'||respeli=='s');
														   

														}break;

													default:
														{
																cout<<"opcion no disponible"<<endl;
														}break;
												}
											}break;
										case'v'://volver
											{
												rep=true;
											}break;
										}
									}

								}break;
							case'1'://perfil//hamilton//funciona
								{
									while(rep==false)
									{
									system("cls");
									cout<<"1.mostrar informacion personal\n2.modificar perfil\n3.inactivar perfil\nv.volver";
									if (base[id].activo==false)
									{
										cout<<endl<<"4.eliminar perfil";
									}
									cout<<endl;
									cin>>all;
									   
									if(all=='4'&&base[id].activo==true)
                  					{
                						all=0;

              					    }

									switch (all)
									{
										case'1'://mostrar info perfil//funciona
											{
												impus(base[id],maxus);
											}break;
										case'2'://modificar perfil//falta probar//funciona
											{
												cout<<"que desea modificar?\n1.nombre\n2.contrasena\n3.correo\n4.edad\n5.cumpleanos\n6.genero\n7.informacion que desea mostrar al publico"<<endl;
												cin>>all;
												
												switch (all)
												{
													cout<<"ingrese ";
													case'1'://nombre//funciona
														{
															cout<<"nombre: ";
															cin>>base[id].name[0];
															
															cout<<"apellido: ";
															cin>>base[id].name[1];
														}break;
													case'2'://contrasena//funciona
														{
															cout<<"nueva contrasena: "<<endl;
															cin>>base[id].cont;
														}break;
													case'3'://coreo//funciona
														{
															cout<<"correo: "<<endl;
															cin>>base[id].correo;
														}break;	
													case'4'://edad//funciona
														{
															cout<<"edad: ";
															cin>>base[id].edad;
														}	break;
													case'5'://cumpleanios//funciona
														{
															cout<<"anio: ";
															cin>>base[id].cumple.an;
															
															cout<<"mes: ";
															cin>>base[id].cumple.me;
															
															cout<<"dia: ";
															cin>>base[id].cumple.di;
															
														}	break;
													case'6'://genero//funciona
														{
															char gene;
															cout<<"ingrese genero\n 1.hombre \n 2.mujer \n 3.otro ";
															cin>>gene;
					
															switch (gene)
															{
															case'1':
																{
																	base[id].genero="hombre";
																}break;
															case'2':
																{
																	base[id].genero="mujer";
																}break;
															default:
																{
																	base[id].genero="otro";
																}break;
															}
														}	break;
													case'7'://info publica//funciona
														{
															char cam;
															
															cout<<"1. amigos: ";
															publicoopersonal(base[id].mostamigos);
															
															cout<<"2. correo: ";
															publicoopersonal(base[id].mostco);
															
															cout<<"3. cumpleanios: ";
															publicoopersonal(base[id].mostcumple);
															
															cout<<"4. edad: ";
															publicoopersonal(base[id].mostedad);
															
															cout<<"5. genero: ";
															publicoopersonal(base[id].mostgen);
															
															cout<<"cambiar(s/n)";
															cin>>cam;
															
															if (cam=='s')
															{
																char ca;
																cout<<"cambiar: ";
																cin>>ca;
																
																switch(ca)
																	{
																		case'1':
																			{
																				base[id].mostamigos=!base[id].mostamigos;
																			}break;
																		case'2':
																			{
																				base[id].mostco=!base[id].mostco;
																			}break;
																		case'3':
																			{
																				base[id].mostcumple=!base[id].mostcumple;
																			}
																		case'4':
																			{
																				base[id].mostedad=!base[id].mostedad;
																			}
																		case'5':
																			{
																				base[id].mostgen=!base[id].mostgen;
																			}	
																	}
																	
															
															}
														}	
												}

											}break;
										case'3'://desactivar perfil//funciona
											{
												char des;
												cout<<"seguro que quiere desactivar su perfil? (s/n)";
												cin>>des;
												
												if (des=='s'||des=='S')
												{
													base[id].activo=false;
													
												}

											}break;
										case'4'://eliminar informacion del perfil//funciona
											{
												char des;
												cout<<"seguro que quiere eliminar la informacion de su usuario? (s/n)"<<endl;
												cin>>des;
												
												if (des=='s'||des=='S')
												{
													for (int a=id;a<maxus;a++)
													{
														base[a]=base[a+1];
													}
													maxus--;
													sesion=true;
												}
												else
												{
													cout<<"gracias por mantenerse con nosotros"<<endl;
												}
												system("pause");
												
											}break;
										case'v'://volver
											{
												rep=true;
											}break;
									}
									}

								}break;
							case'2'://amigos//Randy y Sebastian// funciona
								{
									while (rep==false)
									{
									system("cls");
									string nombuscar,correosolicitud;
									cout<<"1.buscar amigos\n2.mandar solicitud de amistad\n3.solicitudes pendientes\n4.aceptar solicitudes\n5.amigos\n6.informacion de amigo\n7.peliculas en comun\n8.eliminar amigo"<<endl;
									cin>>all;
									switch (all)
												{
													case'1'://buscar amigos//funciona
														{
															int ddd=0;
															cout<<"Nombre de la persona a buscar?"<<endl;
															cin>>nombuscar;
															for(int i=0;i<maxus;i++)
															{
                                                    	        if(base[i].name[0]==nombuscar||base[i].name[1]==nombuscar){
                                                    	            cout<<i<<" "<<base[i].name[0]<<" "<<base[i].name[1]<<endl;
                                                    	           
																    if(base[i].mostco==true){
                                                    	            	cout<<"correo: "<<base[i].correo<<endl;
																	}
																	if(base[i].mostcumple==true){
                                                    	            	cout<<"cumpeanios: "<<base[i].cumple.an<<"/";
                                                    	            	cout<<base[i].cumple.me<<"/";
                                                    	            	cout<<base[i].cumple.di<<endl;
																	}
																	if(base[i].mostedad==true){
                                                    	            	cout<<"edad: "<<base[i].edad<<endl;
																	}
																	if(base[i].mostgen==true){
                                                    	            	cout<<"genero: "<<base[i].genero<<endl;
																	}
																	ddd=1;
																	
                                                    	        }
                                                    	        
															}
															if(ddd==0)
															{
																cout<<"no se encontro el usuario"<<endl;
															}
															system("pause");
														}break;

													case'2'://mandar solicitud//funciona
														{
														    cout<<"A cual usuario desea enviarle la solicitud? (correo)"<<endl;
														    cin>>correosolicitud;
														    bool p=false;
														    if (correosolicitud!=base[id].correo)
														    {
														    	for(int i=0;i<maxus;i++)
																{
                                                          	    	if(correosolicitud==base[i].correo)
																	{
                                                          	        	base[i].solicitudes[base[i].cantsolic][0]=base[id].name[0];
																		base[i].solicitudes[base[i].cantsolic][1]=base[id].name[1]; 
																		base[i].cantsolic++;
																		p=true;
															   		}
														    	}
															}
															if(p==false){
																cout<<" correo invalido "<<endl;
															}	
									
														    
														    system("pause");

														}break;

													case'3'://solicitudes pendientes//funciona
														{
															cout<<"Usted tiene "<<base[id].cantsolic<< "Solicitudes de amistad pendientes"<<endl;
															
														    for(int i=0; i<base[id].cantsolic;i++)
															{
																cout<<base[id].solicitudes[i][0]<<" "<<base[id].solicitudes[i][1]<<endl;
																
														    }
															system("pause");
														}break;

													case'4'://aceptar solicitudes//funciona
														{
														     
															char  decid,chf;
															int aceptar;
														    if(base[id].cantsolic>0)
															{
															 do {
																for(int i=0; i<base[id].cantsolic;i++)
																{
																	cout<<"solicitud # "<<i+1<<" "<<base[id].solicitudes[i][0]<<" "<<base[id].solicitudes[i][1]<<endl;
	
															    }
																 //Si tiene alguna solicitud que las muestre y pregunte cual aceptar. al aceptarla guarda el nombre en amigos.//funciona
																cout<<"Cual solicitud desea aceptar?"<<endl;
															    cin>>aceptar;
															    
															    cout<<"aceptar o eliminar solicitud? (a/e)"<<endl;
															    cin>>decid;
															    int d=0;
															    switch (decid)
															    	{
															    		case'a':
															    			{
															    				base[id].amigos[base[id].cantamis][0]=base[id].solicitudes[aceptar-1][0];
															   					base[id].amigos[base[id].cantamis][1]=base[id].solicitudes[aceptar-1][1];
																				base[id].cantamis++;
															   					d=1;
															   					for(int i=aceptar-1;i<base[id].cantsolic;i++){
															   						base[id].solicitudes[i][0]=base[id].solicitudes[i+1][0];
															   						base[id].solicitudes[i][1]=base[id].solicitudes[i+1][1];
																				   }
																				   base[id].cantsolic--;
																				   if(base[id].cantsolic<0){
																				   	base[id].cantsolic=0;
																				   }
																				  //este ciclo es para que al aceptar la solicitud ambos queden como amigos
																				   for(int i=0;i<maxus;i++){
																				   	if(base[id].amigos[base[id].cantamis-1][0]==base[i].name[0]&&base[id].amigos[base[id].cantamis-1][1]==base[i].name[1]){
																				   		base[i].amigos[base[i].cantamis][0]=base[id].name[0];
																				   		base[i].amigos[base[i].cantamis][1]=base[id].name[1];
																				   		base[i].cantamis++;
																					   }
																				   }
																			}break;
																		case'e':
																			{
																				d=1;
																			}break;
																		default:
																			{
																				cout<<"no se ha hecho ningun cambio"<<endl;
																				
																			}break;
																			
																	}
															    
															    
															    if (d==1)
															    {
															    		for (int a=aceptar;a<base[id].cantsolic;a++)
															   			{
															   		 		base[id].solicitudes[a][0]=base[id].solicitudes[a+1][0];
															   		 		base[id].solicitudes[a][1]=base[id].solicitudes[a+1][1];
																		}
																		
															    		base[id].cantsolic--;
															    		if(base[id].cantsolic<0){
																		base[id].cantsolic=0;
																		}
																}
															   
															    

															    cout<<"Aceptar otra solicitud?(s/n)";
															    cin>>chf;
															    
														    }while(chf=='S'||chf=='s');
															}
															
															system("pause");
														}break;

													case'5'://amigos//funciona
														{
														    for(int i=0;i<base[id].cantamis;i++){
                                                                
																cout<<base[id].amigos[i][0]<<" "<<base[id].amigos[i][1]<<endl;
																
                                                                for(int j=0;j<maxus;j++){
																  
																	if(base[id].amigos[i][0]==base[j].name[0]&&base[id].amigos[i][1]==base[j].name[1]){
																	
																	cout<<"fecha de cumpleanos: "<<base[j].cumple.di<<"/"<<base[j].cumple.me<<"/"<<base[j].cumple.an<<endl;
																	cout<<"correo: "<<base[j].correo;
																
																	cout<<endl<<endl;
																	}
																}
														    }
														    system("pause");

														}break;
														
													case'6'://info de amigo//funciona
														{
															int d=0;
															string buscor;
															cout<<" ingrese correo del amigo a buscar \n";
															cin>>buscor;
															
															for(int i=0;i<maxus;i++)
															{
																if(buscor==base[i].correo)
																{
																	if (base[i].activo==true)
																	{
																		cout<<" nombre: "<<base[i].name[0]<<" apellido: "<<base[i].name[1]<<endl;
																		cout<<" usuario: "<<base[i].uss<<endl;
																		cout<<" cumpleanos: "<<base[i].cumple.di<<"/"<<base[i].cumple.me<<"/"<<base[i].cumple.an<<endl;
																		cout<<" genero: "<<base[i].genero<<endl;
																		cout<<" correo: "<<base[i].correo<<endl;
																		cout<<" peliculas favoritas: "<<endl;
																		d=1;
																	
																		for(int k=0;k<base[i].cantpelifav;k++)
																		{
																			cout<<k<<". "<<base[i].pelifav[k]<<endl;
																		}
																		
																	}
																	else
																	{
																		cout<<"usuario desactivado"<<endl;
																	}												
																					
																}
																
															}
															if (d==0)
															{
																cout<<"usuario no encontrado"<<endl;
															}
															
															system("pause");
														}break;

													case'7'://peliculas en comun
														{
															string nom1,nom2;
															bool p=false;
															int y;
															cout<<" ingrese el nombre del amigo con quien quiere comparar sus peliculas "<<endl;
															cin>>nom1;
															cout<<" ingrese el apellido del amigo con quien quiere comparar sus peliculas "<<endl;
															cin>>nom2;
															for(int i=0;i<base[id].cantamis;i++){
																if(nom1==base[id].amigos[i][0]&&nom2==base[id].amigos[i][1]){
																	p=true;
																}
															}
															if(p==true){
																for(int i=0;i<maxus;i++){
																	if(nom1==base[i].name[0]&&nom2==base[i].name[1]){
																		y=i;
																		cout<<"      | peliculas de su amigo |   "<<endl;
																		for(int k=0;k<base[i].cantpelifav;k++){
																			cout<<"|"<<k+1<<" "<<base[i].pelifav[k]<<" |"<<endl;
																		}
																	}
																}
																cout<<"      | sus peliculas |   "<<endl;
																for(int i=0;i<base[id].cantpelifav;i++){
																	cout<<" | "<<i+1<<" "<<base[id].pelifav[i]<<" |"<<endl;
																}
																cout<<"|  peliculas en comun  | \n";
																for(int i=0;i<base[id].cantpelifav;i++){
																	for(int l=0;l<base[y].cantpelifav;l++){
																		if(base[id].pelifav[i]==base[y].pelifav[l]){
																			cout<<"|"<<i+1<<base[id].pelifav[i]<<"|"<<endl;
																		}
																	}
																}
															}else{ cout<<" nombre invalido"<<endl;
															}
															system("pause");

														}break;
												
													case'8'://eliminar amigo
														{
																string correlim;
																int c,r,g;
																string nam1,nam2;
																cout<<" ingrese el correo del amigo que desea eliminar "<<endl;
																cin>>correlim;
																
																for (int i=0;i<maxus;i++){
																	if(correlim==base[i].correo){
																		nam1=base[i].name[0];
																		nam2=base[i].name[1];
																		r=i;
																	}
																}
																for(int i=0;i<base[id].cantamis;i++){
																	if(nam1==base[id].amigos[i][0]&&nam2==base[id].amigos[i][1]){
																		c=i;
																		
																	}
																}
																for(int i=0;i<base[r].cantamis;i++){
																	if(base[r].amigos[i][0]==base[id].name[0]&&base[r].amigos[i][1]==base[id].name[1]){
																		g=i;
																		
																	}
																}
																for(int k=g;k<base[id].cantamis;k++)
																{
																	base[r].amigos[k][0]=base[r].amigos[k+1][0];
																	base[r].amigos[k][1]=base[r].amigos[k+1][1];
																}										
																		
																		for(int k=c;k<base[id].cantamis;k++)
																			{
																				base[id].amigos[k][0]=base[id].amigos[k+1][0];
																				base[id].amigos[k][1]=base[id].amigos[k+1][1];
																			}
																		base[id].cantamis--;
																		base[r].cantamis--;
																		cout<<" amigo eliminado satisfactoriamente ";
																
																system("pause");

														}break;

													case'v':
														{
															rep=true;
														}break;
												}
											}
								}break;
							case'3'://peliculas//hamilton//funciona
								{
									while(rep==false)
									{
									system("cls");
									cout<<"1.favoritas\n2.ya no me gusta\n3.mostrar todas las peliculas\n4.aniadir a favoritos\nv.volver"<<endl;
									cin>>all;
									
									switch (all)
												{
													case'1'://mostrar favoritas//funciona
														{
															
															if(base[id].cantpelifav==0)
															{
																
																cout<<"no hay favoritos"<<endl;
															}
															else
															{
																for (int a=0;a<base[id].cantpelifav;a++)
																{
																	cout<<a+1<<". "<<base[id].pelifav[a]<<endl;
																}
															}
															system("pause");

														}break;
														
													case'2'://ya no me gusta//funciona
														{
															if (tampeli>0)
															{
																string u;
																int d=0;
																cout<<"ingrese pelicula que ya no le gusta: ";
																cin>>u;
																
																for (int aa=0;aa<base[id].cantpelifav&&d==0;aa++)
																{
																	if (u==base[id].pelifav[aa])
																	{
																		for (int a=aa;a<base[id].cantpelifav;a++)
																		{	
																			base[id].pelifav[a]=base[id].pelifav[a+1];
																		}
																		base[id].cantpelifav--;
																		d=1;
																	}
																	
																	
																	
																}													
																
															
															}
															

														}break;
													case'3'://mostrar peliculas	//funciona
														{
															
															if (tampeli==0)
															{
																cout<<"no hay peliculas"<<endl;
															}
															else
															{
																for (int a=0;a<tampeli;a++)
																{
																	cout<<a+1<<". nombre: " <<pelicula[a].nompeli<<endl;
																	cout<<"genero: "<<pelicula[a].generopeli<<endl;
																	cout<<"resenia: "<<pelicula[a].resumen<<endl<<endl;
																}
															}
															system("pause");
														}break;
														
													case'4'://aniadir a favoritos//funciona
														{
															string u;
															int ddd=0;
															cout<<"pelicula a aniadir a favoritos: ";
															cin>>u;
															
															for (int aba=0;aba<tampeli;aba++)
															{
																if (u==pelicula[aba].nompeli)
																{
																	base[id].pelifav[base[id].cantpelifav]=pelicula[aba].nompeli;
																	base[id].cantpelifav++;
																	ddd=1;
																}
															}
												
															if (ddd==0)
															{
																cout<<"la pelicula no fue encontrada"<<endl;
															}
																
															system ("pause");
														}
													case'v'://volver
														{
															rep=true;
														}break;
												}
									}
								}break;
							case'4'://juegos//meter los que hemos hecho en clase
								{
									while(rep==false)
									{
									system("cls");
									cout<<"1.jugar triqui\n2.juego de la vida\nv.volver"<<endl;
									cin>>all;
									switch (all)
												{
													case'1'://triqui
														{
															cout<<"1.jugar\n2.ver estadisticas"<<endl;
															cin>>all;
															
															switch (all)
															{
																case'1'://jugar triqui
																	{
																		int trk;
																		int hol;
																		string noma;
																		string contras;
																		bool jue;
																		cout<<"ingrese correo del amigo con el que desea jugar "<<endl;
																		cin>>noma;
																		cout<<" ingrese contrasena "<<endl;
																		cin>>contras;
																		jue=existecorr(noma,contras,base,maxus);

																		if (jue==true)
																		{
																		cout<<"usuario o contrasena equivocados"<<endl;
																		}
																		else 
																		{
																			hol=idbuscor(base,maxus,noma);
																		
																			trk=triqui();
																		
																			base[id].partri.jugado++;
																			base[hol].partri.jugado++;
																		
																			if(trk==1)
																			{
																				base[id].partri.ganado++;
																				base[hol].partri.perdido++;
																			}
																			else
																			{
																				if (trk==2)
																				{
																					base[hol].partri.ganado++;
																					base[id].partri.perdido++;
																				}
																			}
																		}
																		
																		
																		
																	}break;
																case'2'://estadisticas amigos
																	{
																		cout<<"mis estadisticas :"<<endl;
																		cout<<"partidas jugadas : "<<base[id].partri.jugado<<endl;
																		cout<<"partidas ganadas : "<<base[id].partri.ganado<<endl;
																		cout<<"partidas perdidas: "<<base[id].partri.perdido<<endl;
																		cout<<"partidas empatadas : "<<base[id].partri.empatado<<endl;
																		
																		system("pause");
																		
																		if (base[id].cantamis>0)
																		{
																			for (int b=0;b<maxus;b++)
																			{
																				for (int a=0;a<base[id].cantamis;a++)
																				{
																					if(base[id].amigos[a][0]==base[b].name[0]&&base[id].amigos[a][1]==base[b].name[1])
																					{
																						cout<<base[id].amigos[a][0]<<" "<<base[id].amigos[a][1]<<endl;
																						cout<<"partidas jugadas : "<<base[b].partri.jugado<<endl;
																						cout<<"partidas ganadas : "<<base[b].partri.ganado<<endl;
																						cout<<"partidas perdidas: "<<base[b].partri.perdido<<endl;
																						cout<<"partidas empatadas : "<<base[b].partri.empatado<<endl;
																						system("pause");
																					}
																				}
																			}
																				
																		}
																		
																		
																	}break;
																default:
																	{
																		
																	}break;
															}
															
														}break;
													case'2'://juego de la vida
														{
															juegovida();
														}break;

													case'v'://volver
														{
															rep=true;
														}break;
												}
									}

								}break;
							case'5'	://cerrar sesion//funciona
								{
									sesion=true;
								}break;
							default:
								{
									
								}break;
						}
						system("cls");
					}
					sesion=false;
				}break;
			case '3':
				{
					salir=true;
					cout<<"cerrando"<<endl;
				}
		}


	}

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//funciones//
void publicoopersonal(bool a)//imprime si el tipo de info es publico o personal
{
	if (a)
	{
		cout<<"publico"<<endl;
	}
	else
	{
		cout<<"privado"<<endl;
	}
}
	
void impus(usuario base,int maxus)//imprime al usuario enviado
{
	cout<<endl<<"usuario: "<<base.uss<<endl<<"nombre: "<<base.name[0]<<endl<<"apellido: "<<base.name[1]<<endl;
	cout<<"genero : "<<base.genero<<endl;
	cout<<"cumpleanios : ("<<base.cumple.an<<"/"<<base.cumple.me<<"/"<<base.cumple.di<<")"<<endl;
	cout<<"correo: "<<base.correo<<endl<<"estado: ";
	if(base.activo==true)
	{
		cout<<"activo"<<endl;
	}
	else
	{
		cout<<"inactivo"<<endl;
	}
	
	if (base.admin==true)
	{
		cout<<"admin";
	}
	
	cout<<endl<<endl;
	system("pause");
}

usuario registro (usuario base[], int maxus)//ingresa los datos del usuario
{
	usuario x;
	char siono;
	bool p=true;

	cout<<" ingrese nombre\n ";
	cin>>x.name[0];
	
	cout<<" ingrese apellido\n ";
	cin>>x.name[1];
	
	x.admin=false;
	x.activo=true;
	x.cantpelifav=0;
	x.cantsolic=0;
	x.cantamis=0;
	x.partri.ganado=0;
	x.partri.jugado=0;
	x.partri.perdido=0;
	x.partri.empatado=0;
	while(p==true){
	cout<<"ingrese su correo electronico\n ";
	cin>>x.correo;
	
	for(int i=0;i<maxus;i++)
		{
		if(base[i].correo==x.correo&&i!=maxus-1){
			cout<<" correo ya utilizado\n";
			p=true;
		}	
		else 
		{
			p=false;
		}
		}
		
	}
	cout<<" quiere que este dato sea publico? s/n";
	cin>>siono;
	if(siono=='s'||siono=='S'){
		x.mostco=true;
	}
	else{
		x.mostco=false;
	}

	system("cls");
	char gene;
	cout<<"ingrese genero\n 1.hombre \n 2.mujer \n 3.otro ";
	cin>>gene;
	
	switch (gene)
	{
		case'1':
			{
				x.genero="hombre";
			}break;
		case'2':
			{
				x.genero="mujer";
			}break;
		default:
			{
				x.genero="otro";
			}break;
	}
	
	cout<<" quiere que este dato sea publico? s/n";
	cin>>siono;
	if(siono=='s'||siono=='S'){
		x.mostgen=true;
	}
	else{
		x.mostgen=false;
	}
	
	system("cls");
	
int d=0;
do{

	if (d==1)
	{
		cout<<"por favor ingrese una fecha valida, recuerde que tiene que ser mayor de edad."<<endl;
	}
	
	cout<<"ingrese fecha de nacimiento \nej :(1954/12/31)\n ";
	cout<<" ingrese anio\n";
	cin>>x.cumple.an;
	cout<<" ingrese mes\n";
	cin>>x.cumple.me;
	cout<<" ingrese dia\n";
	cin>>x.cumple.di;
	d=1;
	system("cls");
}while((x.cumple.an<1900||x.cumple.an>1998)||(x.cumple.di<=0||x.cumple.di>31)||(x.cumple.me<=0||x.cumple.me>12));
	
	
	cout<<" quiere que este dato sea publico? s/n";
	cin>>siono;
	if(siono=='s'||siono=='S'){
		x.mostcumple=true;
	}
	else{
		x.mostcumple=false;
	}
	system("cls");
	
	
	x.edad=2016-x.cumple.an;
	
	cout<<" quiere que su edad sea publica? s/n";
	cin>>siono;
	
	if(siono=='s'||siono=='S'){
		x.mostedad=true;
	}
	else{
		x.mostedad=false;
	}
	
	
	cout<<" Felicidades, ha creado su perfil en MY BOOK\n";
	return x;
}

bool existe (string uss,string cont,usuario base[],int maxus)//busca existencia de usuario y contrasena
{
	bool sesion=true;
	for (int a=0;a<maxus ;a++)
	{
		if (uss==base[a].uss&&cont==base[a].cont)
		{
			sesion=false;
		}
	}
	return sesion;
}


bool buscuss (string uss,usuario base[],int maxus)//busca existencia de usuario
{
	bool usu=false;
	for (int a=0;a<maxus;a++)
	{
		
		if (uss==base[a].uss)
		{
			usu=true;
		}
	}
	return usu;
}

int idbusc (usuario base[],int maxus,string uss)//busca id de usuario
{
	int id=0;
	for (int a=0;a<maxus;a++)
	{
		if (base[a].uss==uss)
		{
			id=a;
		}
	}
	return id;
}

void juegovida()//juego de la vida
{
	
char cells[MAX][MAX];
	int tamx,tamy;
	
	
	cout<<"tamano x : ";
	cin>>tamx;
	
	cout<<"tamano y : ";
	cin>>tamy;
	
	for (int a=0;a<tamx;a++)
	{
		for (int b=0;b<tamy;b++)
		{
			cells[a][b]=' ';
		}
	}
	
	impmat(cells,tamx,tamy);
	
	bool ya=false;
	char des;
	
	while (ya==false)
	{
		cout<<"insertar celula? (s/n) "<<endl;
		cin>>des;
		
		switch (des)
			{
				case 's':
					{
						int x,y;
						
						cout<<"x : ";
						cin>>x;
						
						cout<<"y : ";
						cin>>y;
						
						system("cls");
						
						if (x>tamx||y>tamy)
						{
							cout<<"espacio no diponible"<<endl;
						}
						else
						{
							if (cells[y-1][x-1]=='X')
							{
								cells[y-1][x-1]=' ';
							}
							else
							{
								cells[y-1][x-1]='X';
							}
							
								
						}
						impmat(cells,tamx,tamy);
					}break;
					
				case 'n':
					{
						ya=true;
					}break;
					
				default:
					{
						cout<<"opcion no disponible"<<endl;
					}		
			}
	}
	
	lavida(cells,tamx,tamy);
}

void impmat (char cells[][MAX],int tamx,int tamy)//juego de la vida
{
	cout<<"   ";
	if (tamx>9)
	{
		cout<<" ";
	}
	for (int a=0;a<tamx;a++)
	{
		cout<<a+1<<" ";
	}
	cout<<endl;
	for (int a=0;a<tamy;a++)
	{
			if (tamy>9&&a<9)
			{
				cout<<" ";
			}
		cout<<a+1<<" ";
		for (int b=0;b<tamx;b++)
		{
			
			if (b==0)
			{
				cout<<"|";
			}
			
			cout<<cells[a][b]<<"|";
			
		
		}
		
		cout<<endl;
	}
}


void lavida (char cells[][MAX],int tamx,int tamy)//juego de la vida
{
	int n=1;

	char si='s';
	char celu[MAX][MAX];
	int cant=0,veces=1;
	
	
	while(si=='s')
	{
		cout<<veces<<endl;
		for (int a=0;a<tamy;a++)
		{
			for (int b=0;b<tamx;b++)
			{
				int x=b-1,y=a-1,l=x;
				n=1;
				cant=0;
				while(n<9)
				{
					int o=1;
					x=l;
					
					while(o<=3)
					{
						char cha=cells[y][x];
						if(cells[y][x]=='X')
						{
							cant++;						
						}
						x++;
						o++;
						n++;
					}
					
					y++;
				}
	
				
				if (cells[a][b]=='X')
				{
					cant--;
					if (cant>=2&&cant<4)
					{
						celu[a][b]='X';
					}
					else
					{
						celu[a][b]=' ';
					}
				
				
				}
				else
				{
					if(cant==3)
					{
						celu[a][b]='X';
					}
					else
					{
						celu[a][b]=' ';
					}
				}			
			}
		}
		impmat(celu,tamx,tamy);
		
		cout<<"continuar? (s/n) ";
		cin>>si;
		veces++;
		for (int a=0;a<tamx;a++)
		{
			for (int b=0;b<tamy;b++)
			{
				cells[a][b]=celu[a][b];
			}
		}
		system("cls");
	}
	
}

int triqui()
{
	char trick [3][3];
	int posy,posx,d=0;
	int gan=0;
	for (int a=0;a<3;a++)
	{
		for (int b=0;b<3;b++)
		{
			trick[a][b]=' ';
		}
	}
	
	char l;
	int m=0;
	
	while (m<9&&gan==0)	
	{
		system("cls");
		
			if (m%2==0)
			{
				l='X';
			}
			else 
			{
				l='O';
			}
			
		cout<<l<<endl;	
		cout<<"    1  2  3"<<endl;
		for (int a=0;a<3;a++)
		{
			cout<<a+1<<"  ";
			
			for (int b=0;b<3;b++)
			{
				cout<<"|"<<trick[a][b]<<"|";
			}
			cout<<endl;
		}
		d=0;
		
		while(d==0)
		{
			cout<<"posicion : "<<endl<<"x :";
			cin>>posx;
			cout<<"y :";
			cin>>posy;
		
			posy--;
			posx--;
			if (posy<4&&posy>=0&&posx<4&&posx>=0)
			{
			
				if(trick[posx][posy]!='X'&&trick[posx][posy]!='O')
				{
					trick[posx][posy]=l;
					d=1;	
					gan=verificar(trick);
				}
				else
				{
					cout<<"posicion invalida"<<endl;
				}
			}
			else
			{
				cout<<"limite de 3x3"<<endl;
			}
		}
		
	
		
		
		m++;
	}
	
	cout<<"ha ganado el jugador "<<gan<<endl;
	
 return gan;
	
}

int verificar(char matriz[][3])//triqui
{
	int gana=0;
	        
	for(int b=0; b<3;b++)
	{
		if ((matriz[0][b]=='X')&&(matriz[1][b]=='X')&&(matriz[2][b]=='X'))
		{
			gana=1;
		}
		if ((matriz[0][b]=='O')&&(matriz[1][b]=='O')&&(matriz[2][b]=='O'))
		{
			gana=2;
		}
	}
	for(int b=0; b <3; b++)
	{
		if ((matriz[b][0]=='X')&&(matriz[b][1]=='X')&&(matriz[b][2]=='X'))
		{
			gana=1;
		}
		if ((matriz[b][0]=='O')&&(matriz[b][1]=='O')&&(matriz[b][2]=='O'))
		{
        	gana=2;
		}
	}
				
	if ((matriz[0][2]=='X')&&(matriz[1][1]=='X')&&(matriz[2][0]=='X'))//
	{
		gana=1;
	}
	else
	{
		if ((matriz[0][0]=='X')&&(matriz[1][1]=='X')&&(matriz[2][2]=='X'))
		{
			gana=1;
		}
	}
               
	if ((matriz[0][0]=='O')&&(matriz[1][1]=='O')&&(matriz[2][2]=='O'))
	{
		gana=2;
	}
	else
	{
		if ((matriz[0][2]=='O')&&(matriz[1][1]=='O')&&(matriz[2][0]=='O'))
		{
			gana=2;
		}
	}
	
	
	cout<<"gana : "<<gana<<endl;
	system("pause");
                
	return gana;
}
bool existecorr (string noma,string contras,usuario base[],int maxus)//busca existencia de usuario y contrasena
{
	bool sesion=true;
	for (int a=0;a<maxus ;a++)
	{
		if (noma==base[a].correo)
		{
			sesion=false;
		}
	}
	return sesion;
}

int idbuscor (usuario base[],int maxus,string noma)//busca id de usuario
{
	int id=0;
	for (int a=0;a<maxus;a++)
	{
		if (base[a].correo==noma)
		{
			id=a;
		}
	}
	return id;
}










