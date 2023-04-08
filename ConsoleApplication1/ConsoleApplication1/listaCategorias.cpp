#include "listaCategorias.h"

listaCategorias::listaCategorias()
{
	this->cCab = NULL;
	this->largo = 0;
}

listaCategorias::~listaCategorias()
{
}

void listaCategorias::setCCab(nodoCategoria* ptr)
{
	this->cCab = ptr;
}

nodoCategoria* listaCategorias::getCCab()
{
	return this->cCab;
}

void listaCategorias::setLargo(int pLargo)
{
	this->largo = pLargo;
}

int listaCategorias::getLargo()
{
	return this->largo;
}

nodoCategoria* listaCategorias::dirNodo(Categoria c){
	nodoCategoria* aux = NULL;

	if (!esVacia()){
		aux = getCCab();
		while (aux != NULL && !aux->getCategoria().esIgual(c.getNombre())){
			aux = aux->getCSgte();
		}
	}


	return aux;
}


bool listaCategorias::esVacia()
{
	return cCab == NULL;
}

bool listaCategorias::agregarCategoria(Categoria)
{
	return false;
}

bool listaCategorias::eliminarCategoria(Categoria _categoria){
	bool eliminado = false;
	if (!esVacia()) {}{
		nodoCategoria* aux = NULL;
		if (!getCCab()->getCategoria().esIgual(_categoria.getNombre())) {
			aux = getCCab();

			setCCab(aux->getCSgte());
			setLargo(getLargo() - 1);

			delete aux;
			eliminado = true;
		}else{
		}
	}
	return eliminado;
}

void listaCategorias::listarCategorias() {
	if (esVacia()){
		std::cout << "La lista está vacía, por favor agregue categorías";
	}else {
		nodoCategoria* aux = getCCab();
		while (aux != NULL) {
			std::cout << aux->getCategoria().getNombre() << "-";
			aux = aux->getCSgte();
		}
		std::cout << "Final \n";
	}
}

Categoria listaCategorias::consultarLista(string pNombre) {
	if (esVacia()){
		std::cout << "La lista está vacía, por favor agregue categorías";
	}else{
		bool encontrado = false;
		nodoCategoria* aux = getCCab();
		while (aux != NULL){
			if (aux->getCategoria().esIgual(pNombre)) {
				return aux->getCategoria();
			}
			aux = aux->getCSgte();
		}
	}
}
