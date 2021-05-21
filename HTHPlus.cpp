#include "Pelicula.hpp"
#include "HTHPlus.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
HTHPlus::HTHPlus(){
	
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
void HTHPlus::eliminarPelicula(int pos){
	delete this->listaPeliculas[pos];
	listaPeliculas.erase(listaPeliculas.begin()+pos);
}
void HTHPlus::imprimirGenero(){
	
}
void HTHPlus::buscarPelicula(string palabra){
	
}
void HTHPlus::imprimirValoracion(){
	
}