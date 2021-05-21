#ifndef PELICULA_HPP
#define PELICULA_HPP
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <string>

using namespace std;
class Pelicula {
	private:
	string titulo;
	string director;
	string genero;
	int valoracion;
	public:
	Pelicula();
	Pelicula(string,string,string);
	string getTitulo();
	void setTituto(string);
	string getDirector();
	void setDirector(string);
	string getGenero();
	void setGenero(string);
	int getValoracion();
	void setValoracion(int);
	

  
};
#endif