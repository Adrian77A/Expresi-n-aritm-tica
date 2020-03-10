
//Leer una expresión aritmético en infijo y resolverla empleando pila (debe pasar de infijo a posfijo)
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

//----------------------------------------------------------------------
class Nodo{
	private:
		int dato;
		Nodo *sig;
		friend class Pila;
		
	public:
            Nodo(){//constructor de nodo
                    this->dato=dato;
                    this->sig=NULL;
            }
            ~Nodo(){//destructor de nodo
            	cout<<"Se ha liberado la memoria\n";
			}
};
//----------------------------------------------------------------------------

class Pila{
	private:
		Nodo *tope;
		
	public:
		Pila();//constructor de pila
       	void Apilar(string);
        void DesApilar();
        void VerTope();
        bool PilaVacia();
        void prioridadOperador();
        void prioridadPila();
};


Pila::Pila(){//constructor de pila
 tope=NULL;
}

//void Pila::Apilar(string x){
//}

//-----------------------------------------------------
class Expresion{
	private:
		char expresion[100];
	public:
		char Leer();
		//void Mostrar();
		//void recExpresion(char);
};

char Expresion::Leer(){
	char expresion[100];
	int n=10;
	for(int i;i<n;i++){
		cin>>expresion[i];
		}
	return expresion[i];
}

/*void Expresion::Mostrar(){
	cout<<expresion;
}

void Expresion::recExpresion(char x){
	char exp1[100];
	exp1=x;
	for(int i=0;i<exp1;i++){
		cout<<exp1[i];
	}
}*/
//----------------------------------------------------





int main(){
	
	Expresion exp;
	exp.Leer();
	
}

