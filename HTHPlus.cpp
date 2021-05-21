#include "Pelicula.hpp"
#include "HTHPlus.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
using namespace std;
HTHPlus::HTHPlus(){
	
}
HTHPlus::~HTHPlus(){

		for(int i=0;i<this->listaPeliculas.size();i++){
			delete this->listaPeliculas[i];
		}
	
}
void HTHPlus::setVector(vector<Pelicula*>lista){
	this->listaPeliculas=lista;
}
vector <Pelicula*> HTHPlus::getVector(){
	return this->listaPeliculas;
}
void HTHPlus::agregarPelicula(Pelicula *p){
	this->listaPeliculas.push_back(p);
}
void HTHPlus::modificarPelicula(int menu,int pos){
	if(menu==1){
		string tit;
		cout<<"Ingrese nuevo titulo:  ";
		cin>>tit;
		Pelicula *p=this->listaPeliculas.at(pos);
		p->setTituto(tit);
		cout<<"modifico exitosamente"<<endl;
	}
	if(menu==2){
		string dir;
		cout<<"Ingrese nuevo director:  ";
		cin>>dir;
		Pelicula *p=this->listaPeliculas.at(pos);
		p->setDirector(dir);
		cout<<"modifico exitosamente"<<endl;
	}
	if(menu==3){
		string gen;
		cout<<"Ingrese nuevo genero:  ";
		cin>>gen;
		Pelicula *p=this->listaPeliculas.at(pos);
		p->setGenero(gen);
		cout<<"modifico exitosamente"<<endl;
	}
	if(menu==4){
		srand(time(NULL));
		int nuevo=rand()%6;
		Pelicula *p=this->listaPeliculas.at(pos);
		p->setValoracion(nuevo);
		cout<<"modifico exitosamente"<<endl;
	}
}
void HTHPlus::imprimir(){

	for(int i=0;i<this->listaPeliculas.size();i++){
		Pelicula *p=this->listaPeliculas[i];
		cout<<"Pelicula: "<<i <<"-";
		cout<<"Titulo: "<< p->getTitulo()<<"-";
		cout<<"Director: "<<p->getDirector()<<"-";
		cout<<"Genero:"<<p->getGenero()<<"-";
		cout<<"Valoracion: "<<p->getValoracion()<<endl;
	}
}
void HTHPlus::eliminarPelicula(int pos){
	delete this->listaPeliculas[pos];
	listaPeliculas.erase(listaPeliculas.begin()+pos);
}
void HTHPlus::imprimirGenero(){
	vector <string> listagen;
	int c=0;
	for(int i=0;i<this->listaPeliculas.size();i++){
		Pelicula *p=this->listaPeliculas[i];
		listagen.push_back(p->getGenero());
		
	}
	
	vector <string> listagen1;
	listagen1.push_back(listagen[0]);
	for(int i=1;i<listagen.size();i++){
		for(int k=0;k<listagen1.size();k++){
			if(listagen[i]!=listagen1[k]){
				listagen1.push_back(listagen[i]);
			}
		}
		
	}
	for(int i=0;i<listagen1.size();i++){
		cout<<"generos unicos: "<<i<<" : "<<listagen1[i]<<endl;
	}

	for(int i=0;i<this->listaPeliculas.size();i++){
		Pelicula *p=this->listaPeliculas.at(i);
		for(int j=0;j<listagen1.size();j++){
			if(p->getGenero()==listagen1[j]){
				cout<<"GENERO: "<<listagen[i]<<"-";
				cout<<"Pelicula: "<<"-";
				cout<<"Titulo: "<< p->getTitulo()<<"-";
				cout<<"Director: "<<p->getDirector()<<"-";
				cout<<"Valoracion: "<<p->getValoracion()<<endl;
			}
		}
	}

}
void HTHPlus::buscarPelicula(string palabra){
	vector<Pelicula*> listatemp;
	for(int i=0;i<this->listaPeliculas.size();i++){
		Pelicula *p=this->listaPeliculas.at(i);
		string movie=p->getTitulo(); 
		if(strstr (movie.c_str(),palabra.c_str())){
			listatemp.push_back(p);
		}	
	}
	for(int i=0;i<listatemp.size();i++){
		Pelicula *p=listatemp[i];
		cout<<"Pelicula: "<<i <<"-";
		cout<<"Titulo: "<< p->getTitulo()<<"-";
		cout<<"Director: "<<p->getDirector()<<"-";
		cout<<"Genero:"<<p->getGenero()<<"-";
		cout<<"Valoracion: "<<p->getValoracion()<<endl;
	}
}
void HTHPlus::imprimirValoracion(){
	vector <int> listaval;
	
	vector<Pelicula*>listapel;
	for(int i=0;i<this->listaPeliculas.size();i++){
		Pelicula *p=this->listaPeliculas.at(i);
		listaval.push_back(p->getValoracion());
	}
	//unicos 

	
	vector <int> listaval2;
	listaval2.push_back(listaval[0]);
	for(int i=1;i<listaval.size();i++){
		for(int k=0;k<listaval2.size();k++){
			if(listaval[i]!=listaval2[k]){
				listaval2.push_back(listaval[i]);
			}
		}
		
	}

	int maxind,temp;
	for(int i=0;i<listaval2.size();i++){
		maxind=i;
		for(int j=i+1;j<listaval2.size();j++){
			if(listaval2[j]>listaval2[maxind]){
				maxind=j;
			}
			
		}
		temp=listaval2[maxind];
		listaval2[maxind]=listaval2[i];
		listaval2[i]=temp;
	}
	for(int i=0;i<listaval2.size();i++){
		
		cout<< " Valoracion con orden:    "<<i<<" : "<<listaval2.at(i)<<endl;
	}
	for(int i=0;i<listaval2.size();i++){
		for(int j=0;j<this->listaPeliculas.size();j++){
			Pelicula *p=this->listaPeliculas[j];
			int n=p->getValoracion();
			
			int n22;
			n22=listaval2[i];
			if(n22==n){
				//cout<<" numero: "<<n22<<" es igual a : "<<n<<endl;
				listapel.push_back(p);
			}
		}
	}
	cout<<"ordenadas"<<endl;
	for(int i=0;i<listapel.size();i++){
		Pelicula *p=listapel.at(i);
		
		cout<<"Pelicula:  "<<p->getTitulo()<<" - "<<"Titulo: "<<p->getTitulo()<<"- "<<"Genero: "<<p->getGenero()<<"- Valoracion: "<<p->getValoracion()<<"/5"<<endl;
	}
	
	
}
