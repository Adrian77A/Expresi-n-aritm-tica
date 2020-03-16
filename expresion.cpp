
//Leer una expresión aritmético en infijo y resolverla empleando pila (debe pasar de infijo a posfijo)
#include<iostream>
#include<stdio.h>
#include<string>
#include<cstdlib>
#include<string.h>
#define max 50

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


//---------------------------2--------------------------------

class nodo { //ESTRUCTURA DE LA PILA   
       private: 	       
       char palabra;
       struct nodo *sgte;
       nodo *Ptrpila;//Definimos estructura tipo Pila
	nodo *Tlista; //Definimos estructura tipo Lista
	
       public:
	nodo();
	void push(Ptrpila &,char);
        char pop(Ptrpila &);
        void agregar_atras(Tlista &,char);
        void destruir(Ptrpila &);
        int  prioridad_infija(char );
       int  prioridad_pila(char );
       void imprimir( Tlista &);
        void balanceoSimbolos( Ptrpila &, char []);
       };

nodo::nodo{ //constructor
}






/*                 Funcion Principal
-----------------------------------------------------*/
  int main(void)
    {   Ptrpila p=NULL;
        Ptrpila M=NULL;
        Tlista lista=NULL;
        char cad[max], c,x;
        int tam;

        system("color 2E");   //0b
		cout<<"\n\t\t___________________________________________________________________"<<endl;
        cout<<"\n\t\tCONVERSION DE EXPRESIONES MATEMATICAS DE INFIJA A POSTFIJA\n\n";
        cout<<"\n\t\t____________________________________________________________________"<<endl;
        do{
           cout<<"\n\tINGRESE LA EXPRESION:";
           gets(cad);
              if(M!=NULL)
                 destruir(M);
           balanceoSimbolos(M,cad); //verificamos si los simbolos de agrupacion estan
           }while(M!=NULL);         //correctamente valanceados

        tam=strlen(cad);
        for(int i=0;i<tam;i++)
        {
            if((cad[i]>=49&&cad[i]<=57)||(cad[i]>=97&&cad[i]<=122))//validado para numeros de 1-9 y letras
                agregar_atras(lista,cad[i]);
            if(cad[i]=='+'||cad[i]=='-'||cad[i]=='*'||cad[i]=='/'||cad[i]=='('||cad[i]=='^')
            {   if(p==NULL)
                    push(p,cad[i]);
                else
                {
                    if(prioridad_infija(cad[i])>prioridad_pila(p->palabra))//compara prioridad de operadores
                        push(p,cad[i]);
                    else
                    {   if(prioridad_infija(cad[i])==prioridad_pila(p->palabra))
                          {
                            c=pop(p);
                            agregar_atras(lista,c);
                            push(p,cad[i]);
                          }
                        else
                          {
                            c=pop(p);
                            agregar_atras(lista,c);
                          }
                    }
                }
            }
            if(cad[i]==')')
               {
                while(p->palabra!='('&&p!=NULL)//desempilamos y agregamos a lista
                   {
                       c=pop(p);
                       agregar_atras(lista,c);
                    }
                if(p->palabra=='(')
                        c=pop(p);
                }
        }
        while(p!=NULL)//si es que la pila aun no esta nula pasamos los operadores a lista
            {
                c=pop(p);
                agregar_atras(lista,c);
            }

        imprimir(lista);
        system("pause");
        return 0;
    }
/*                 Apilar
-------------------------------------------------*/
void nodo:: push(Ptrpila &p,char a)
{
    Ptrpila q=new struct nodo;
    q->palabra=a;
    q->sgte=p;
    p=q;
 }

/*                 Desempilar
-------------------------------------------------*/
char nodo:: pop(Ptrpila &p)
{
    int n;
    Ptrpila aux;

    n=p->palabra;
    aux=p;
    p=p->sgte;
    delete(aux);
    return n;

}
/*                 Agregar a la Lista
--------------------------------------------------
funcion para agregar caracter a la lista de salida*/
void nodo::agregar_atras(Tlista &lista,char a)
{
    Tlista t, q = new(struct nodo);

    q->palabra  = a;
    q->sgte = NULL;

    if(lista==NULL)
      {
        lista = q;
      }
    else
      {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
      }

}
/*                 Destruir Pila
--------------------------------------------------*/
void nodo :: destruir(Ptrpila &M)
{    Ptrpila aux;

     if(M !=NULL)
     {
         while(M!=NULL)
         {
             aux=M;
             M=M->sgte;
             delete(aux);
         }

      }
}

/*          Prioridad en Notacion Infija
----------------------------------------------------
esta prioridad se usa al momento de leer el caracter
de la cadena*/
int nodo:: prioridad_infija(char a)
{
    if(a=='^')
        return 4;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 5;
}

/*                 Prioridad en Pila
---------------------------------------------------
esta prioridad es usada para los elementos que se
encuentran en la pila */
int nodo:: prioridad_pila(char a)
{
    if(a=='^')
        return 3;
    if( a=='*')
        return 2;
    if( a=='/')
        return 2;
    if( a=='+')
        return 1;
    if( a=='-')
        return 1;
    if(a=='(')
        return 0;
}
/*               Imprimir Lista
----------------------------------------------------*/
void nodo:: imprimir( Tlista &lista)
{
    Ptrpila aux;
    aux=lista;

    if(lista!=NULL)
     {    cout<<"\t\nNOTACION POSTFIJA\n\n";
          while(aux!=NULL)
          {    cout<<aux->palabra;
               aux = aux->sgte;
          }
      }
      cout<<endl<<endl;
}

/*                Balanceo de simbolos de agrupacion
---------------------------------------------------------------------*/
void nodo:: balanceoSimbolos( Ptrpila &p, char cad[])
{
     Ptrpila aux;
     int i = 0;

     while( cad[i] != '\0')
     {
            if( cad[i]=='(' || cad[i]=='[' || cad[i]=='{' )
            {
                 push( p, cad[i] );
            }
            else if( cad[i]==')' || cad[i]==']' || cad[i]=='}' )
            {
                 aux = p;

                 if(aux!=NULL)
                 {
                      if( cad[i]==')' )
                      {
                           if( aux->palabra == '(')
                              pop( p );
                      }
                      else if( cad[i]==']' )
                      {
                           if( aux->palabra == '[')
                              pop( p );
                      }
                      else if( cad[i]=='}' )
                      {
                           if( aux->palabra == '{')
                              pop( p );
                      }
                 }
                 else
                     push( p, cad[i] );
            }
            i++;
     }

     if(p==NULL)
         cout<<"\n\tBalanceo CORRECTO..."<<endl<<endl;
     else
         cout<<"\n\t Balanceo INCORRECTO, faltan simbolos de agrupacion..."<<endl;
}












