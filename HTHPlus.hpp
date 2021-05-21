#ifndef HTHPLUS_HPP
#define HTHPLUS_HPP
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <string>
#include <vector>
#include "Pelicula.hpp"

using namespace std;
class HTHPlus {
	private:
	vector <Pelicula*> listaPeliculas;
	public:
	HTHPlus();
	~HTHPlus();
	void setVector(vector<Pelicula*>);
	vector<Pelicula*> getVector();
	void agregarPelicula(Pelicula*);
	void modificarPelicula(int,int);
	void eliminarPelicula(int);
	void imprimirGenero();
	void buscarPelicula(string);
	void imprimirValoracion();
	void imprimir();
};
#endif