#pragma once
#include "nodoCategoria.h"

class listaCategorias
{
private:
	nodoCategoria* cCab;
	int largo;
public:
	listaCategorias();
	~listaCategorias();

	void setCCab(nodoCategoria*);
	nodoCategoria* getCCab();
	void setLargo(int);
	int getLargo();

	nodoCategoria* dirNodo(Categoria);

	bool esVacia();

	bool agregarCategoria(Categoria);
	bool eliminarCategoria(Categoria);

	void listarCategorias();
	Categoria consultarLista(string);
};

