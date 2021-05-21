#include "Pelicula.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <string>
using namespace std;
Pelicula::Pelicula(){
	
}
Pelicula::Pelicula(string t,string d,string g){
	this->titulo=t;
	this->director=d;
	this->genero=g;
	srand(time(NULL));
	this->valoracion=rand()%6;
}
string Pelicula::getTitulo(){
	return this->titulo;
	
}
void Pelicula::setTituto(string t){
	this->titulo=t;
}
string Pelicula::getDirector(){
	return this->director;
}
void Pelicula::setDirector(string d){
	this->director=d;
}
string Pelicula::getGenero(){
	return this->genero;
}
void Pelicula::setGenero(string g){
	this->genero=g;
}
int Pelicula::getValoracion(){
	return this->valoracion;
}
void Pelicula::setValoracion(int v){
	this->valoracion=v;
	
}
