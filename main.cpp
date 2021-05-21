#include <iostream>
#include "Pelicula.hpp"
#include "HTHPlus.hpp"
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int submenu(){

	
	while(true){
		cout<<"MENU"<<endl;
		cout<<"1. Modificar Titulo "<<endl<<"2. Modificar Director "<<endl<<"3. Modificar Genero"<<endl<<"4. Modificar Valoracion"<<endl<<"5. regresar"<<endl;
		int valor;
		cin>>valor;
		if(valor > 0&& valor < 6)
			return valor;
		
	}
	
}
int menu(){

	
	while(true){
		cout<<"MENU"<<endl;
		cout<<"1. Agregar pelicula "<<endl<<"2. Modificar Pelicula "<<endl<<"3. Eliminar Pelicula"<<endl<<"4. Imprimir Peliculas"<<endl<<"5. Imprimir por Genero"<<endl<<"6. Buscar" <<endl<<"7. Imprimir por Valoracion"<<endl<<"8. Salir"<<endl;
		int valor;
		cin>>valor;
		if(valor > 0&& valor < 9)
			return valor;
		
	}
	
}
int main(int argc, char** argv) {
	HTHPlus* ht=new HTHPlus();
	int main=0;
	while(main!=8){
		switch(main=menu()){
			case 1:{
	
				string titulo;
				string director;
				string genero;
				cout<<"Ingrese Titulo:  ";
				cin>>titulo;
				cout<<"Ingrese Director: ";
				cin>>director;
				cout<<"Ingrese Genero: ";
				cin>>genero;
				ht->agregarPelicula(new Pelicula(titulo,director,genero));
				cout<<"CREADO"<<endl;
				break;
			}//1
			case 2:{
				int pos;
				cout<<"posicion a modificar: ";
				cin>>pos;
				int main1=0;
				while(main1!=5){
					switch(main1=submenu()){
						case 1:{
							ht->modificarPelicula(1,pos);
							break;
						}
						case 2:{
							ht->modificarPelicula(2,pos);	
							break;
						}
						case 3:{
							ht->modificarPelicula(3,pos);
							break;
						}
						case 4:{
							ht->modificarPelicula(4,pos);
							break;
						}
						case 5:{
							cout<<"regreso"<<endl;
							break;
						}
					
					}
				}
				break;
			}//2
			case 3:{
				int pos;
				cout <<"posicion a eliminar: ";
				cin>>pos;
				ht->eliminarPelicula(pos);
				break;
			}//3
			case 4:{
				ht->imprimir();
				
				break;
			}//4
			case 5:{
				ht->imprimirGenero();
				break;
			}//5
			case 6:{
				string word;
				cout<<"ingrese palabra a buscar: ";
				cin>>word;
				ht->buscarPelicula(word);
				break;
			}//6
			case 7:{
				ht->imprimirValoracion();
				break;
			}//7
			case 8:{
				cout<<"saliendo"<<endl;
				break;
			}
		}//sitwch
	}//while
	
	return 0;
}