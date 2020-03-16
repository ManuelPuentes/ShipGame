#include <iostream>
using namespace std;

template <class T>
class Nodo{

public:
	T obj;
	Nodo<T>* siguiente;
	Nodo<T>* anterior;
	
	
	Nodo(){
		   this->siguiente=NULL;
		   this->anterior=NULL;
	}
		   
	Nodo(T elemento){
		
		this->obj=elemento;
		this->siguiente=NULL;
		this->anterior=NULL;
	}
	~Nodo(){}
	void Imprimir(){
		cout<<obj<<endl;
	}
	void setValor(T object){this->obj=object;}
	void setSiguiente(Nodo<T>*elemento){
		this->siguiente=elemento;
	}
	void setAnterior(Nodo<T>*elemento){
		this->anterior=elemento;
	}
	Nodo<T>* getSiguiente(){return this->siguiente;}
	Nodo<T>* getAnterior(){return this->anterior;}
	
	T getValor(){return this->obj;}
	
	bool operator ==(Nodo nodo){
		if(this->obj==nodo->obj){
			return true;
		}
		return false;
	}
	
	
//		bool operator <(Nodo *nodo){
//			
//		if(this->obj < nodo->obj){
//			return true;
//		}
//		return false;
//	}
};


template<class T>
Nodo<T>* CrearNodo(T elemento){
	
	Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
	
	return nuevoNodo;
}
