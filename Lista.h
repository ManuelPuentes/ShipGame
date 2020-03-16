#include "Nodo.h"
#include <stdlib.h>
#include <string.h>

template <class T>

class Lista{
	
	Nodo<T>* cabeza;
	int tam;
	
	public:
		Lista(){this->cabeza=NULL; this->tam=0;}
		
		bool Buscar(T elemento);//retorna true si el elemento esta dentro de la lista
		void Insertar(T elemento);//metodos insert agg elemento a la lista en la posicion especificada
		void InsertarPrincipio(T elemento);//al principio//en la posicion"x"//al final
		void InsertarFinal(T elemento);
		void InsertarAt(T elemento,int index);
		bool getTope(T &elemento);//los metodos get- elliminan al elemento de la lista en la posicion indicada
		bool getFin(T &elemento);//es decir inicio/en la posicion "index" comenzando en 0 / o al final
		bool getAt(T &elemento,int pos);
		bool At(T&elemento,int pos);// este metodo solo obtiene el valor de la lista en un punto especifico mas no lo saca de lña lista 
		void mostrar();
		bool Drop();//elimina todo el contenido de la lista
		void Sort();//ordena la lista
		void reverse();
		int  getTam(){return this->tam;}		
		T operator[](int index){//la sobrecarga del operdaror [] permite consultar el valor de la lista especificando un index 
		 T aux;
//		 if(index>=this->tam)return NULL;
			At(aux,index);
			return aux;
		}
		void operator=(Lista<T> list){// el operdaor asignamcion permite realizar sentencias como list=list2 haciendo una copia de list2 en list 1
			Nodo<T>* ptrLista=list.cabeza;
			T aux;
				while(ptrLista){
					aux=ptrLista->getValor();
					this->InsertarFinal(aux);
					ptrLista=ptrLista->getSiguiente();	
				}
		}	
};
template<class T>
bool Lista<T>::Drop(){
	T elemento;
	while(this->cabeza!=NULL){
		this->getTope(elemento);
	}
return true;	
}
template<class T>
	bool Lista<T>::getTope(T &elemento){
		Nodo<T>* ptr=this->cabeza;
		
		if(this->cabeza==NULL)return false;
		
		if(this->cabeza->getSiguiente()==NULL){//si la lista solo tiene un elemento no importa si se quiere eliminar por derecha o izquierda
			ptr=this->cabeza;	
			this->cabeza=NULL;
			delete(ptr);
		}else{
			elemento=this->cabeza->getValor();
			this->cabeza=this->cabeza->getSiguiente();
			delete(this->cabeza->getAnterior());
			this->cabeza->setAnterior(NULL);
		}
		tam--;
		return true;
	}
template<class T>
bool Lista<T>::getFin(T &elemento){		
	Nodo<T>*ptrLista=this->cabeza;
	Nodo<T>*anterior; 
	
	if(this->cabeza==NULL)return false;
	
	if(this->cabeza->getSiguiente()==NULL){//si la lista solo tiene un elemento no importa si se quiere eliminar por derecha o izquierda
		ptrLista=this->cabeza;	
		this->cabeza=NULL;
		delete(ptrLista);
	}else{
		
	while(ptrLista->getSiguiente()){
		anterior=ptrLista;
		ptrLista=ptrLista->getSiguiente();
	}
	delete(ptrLista=ptrLista->getAnterior());
	elemento=anterior->getSiguiente()->getValor();
	anterior->setSiguiente(NULL);
	}
	tam--;
	return true;
}
template<class T>
bool Lista<T>::getAt(T &elemento,int pos){
	
	Nodo<T>* ptrLista=this->cabeza;
	Nodo<T>* anterior;
	int vueltas=0;
	
	if(pos>tam)return false;
	if(pos==0){
		getTope(elemento);
	}else if(pos==tam){
		getFin(elemento);
	}else {
		
		while(vueltas<pos){
			anterior=ptrLista;
			ptrLista=ptrLista->getSiguiente();
			vueltas++;
		}
		elemento=ptrLista->getValor();
		ptrLista=ptrLista->getSiguiente();
		delete(ptrLista->getAnterior());
		ptrLista->setAnterior(anterior);
		anterior->setSiguiente(ptrLista);
	}
tam--;
return true;
}
template<class T>
bool Lista<T>::At(T &elemento,int pos){
	Nodo<T>* ptrLista=this->cabeza;
	Nodo<T>* anterior;
	int vueltas=0;
	
	if(pos>tam)return false;
	
	if(pos==0){
		elemento=ptrLista->getValor();
	}else {
		while(vueltas<pos){
			ptrLista=ptrLista->getSiguiente();
			vueltas++;
		}
		elemento=ptrLista->getValor();
	}
return true;
}
template<class T>
	void Lista<T>::Insertar(T elemento){
		Nodo<T>*nuevoNodo= new Nodo<T>(elemento);
		Nodo<T>*Anterior = NULL;
		Nodo<T>*ptrLista=this->cabeza;
		while(ptrLista){
			if(elemento < ptrLista->getValor()){			
				break;	
			}else {
				Anterior=ptrLista;
				ptrLista=ptrLista->getSiguiente();
			}
		}
		if(ptrLista==cabeza){
			InsertarPrincipio(elemento);
		} else {
			if(ptrLista!=NULL){
			nuevoNodo->setSiguiente(ptrLista);
			nuevoNodo->setAnterior(ptrLista->getAnterior());
			Anterior->setSiguiente(nuevoNodo);
			}else{
				InsertarFinal(elemento);
			}
		}
		tam++;
	}
template<class T>
	void Lista<T>::InsertarFinal(T elemento){
		
		Nodo<T>*nuevoNodo= new Nodo<T>(elemento);
		Nodo<T>*ptrLista=this->cabeza;
		if(this->cabeza==NULL){this->cabeza=nuevoNodo;}else{
			
		while(ptrLista->siguiente){
			ptrLista=ptrLista->siguiente;
		}
		ptrLista->siguiente=nuevoNodo;
		}
		tam++;
	}
template<class T>
	void Lista<T>::InsertarPrincipio(T elemento){
		Nodo<T>*nuevoNodo= new Nodo<T>(elemento);
		if(nuevoNodo!=NULL){
			nuevoNodo->setSiguiente(this->cabeza);
			this->cabeza=nuevoNodo;
			tam++;
		}
	}
template<class T>
	void Lista<T>::InsertarAt(T elemento,int index){			
		Nodo<T>* ptrLista=this->cabeza;
		Nodo<T>* Anterior;
		Nodo<T>* nuevoNodo= new Nodo<T>(elemento);
		int i=0;	
			while(ptrLista && i<index){
				Anterior=ptrLista;
				ptrLista=ptrLista->getSiguiente();
				i++;
			} 	
		if(ptrLista==cabeza){
				InsertarPrincipio(elemento);
		} else {
			nuevoNodo->setSiguiente(ptrLista);
			nuevoNodo->setAnterior(ptrLista->getAnterior());
			Anterior->setSiguiente(nuevoNodo);
		}
		tam++;
	}	
template<class T>
	bool Lista<T>::Buscar(T elemento){		
		Nodo<T>*nodo= new Nodo<T>(elemento);
		Nodo<T>*aux=this->cabeza;
				
			while(aux){
				if(aux==nodo)return true;
			}
		return false;
	}
template <class T>
	void Lista<T>::mostrar(){
		Nodo<T>* nodo=this->cabeza;
		int i=0;	
		while(nodo){
			cout<<i+1<<"-";
			nodo->Imprimir();
			nodo=nodo->siguiente;
			i++;
		}
	}
template<class T>
void Lista<T>::Sort(){
	
	Nodo<T>*ptrLista=this->cabeza;
	Nodo<T>*aux;
	T temp;
	
	while(ptrLista){
		aux=ptrLista;
		
		while(aux->getSiguiente()){
			aux=aux->getSiguiente();
			if(aux->getValor()<ptrLista->getValor()){
				
				 temp=ptrLista->getValor();
				 ptrLista->setValor(aux->getValor());
				 aux->setValor(temp);
			}
		}
		ptrLista=ptrLista->getSiguiente();
	}
}
template <class T>
void Lista<T>::reverse(){
	int size=this->tam-1;
	T aux;
	for(int i=0;i<size;i++){
		
		this->getFin(aux);
		this->InsertarAt(aux,i);   
		
	}
	
}
	
