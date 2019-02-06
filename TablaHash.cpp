#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;
//Empleado.cpp

class Contacto{
	public:
		int telefono;
		string nombre;
		string email;
		char sexo;
		Contacto(int telefono, string nombre, string email, char sexo){
			this->telefono = telefono;
			this->nombre = nombre;
			this->email = email;
			this->sexo = sexo;
		}
		
};


const int TABLE_SIZE = 128;


class HashEntry
{
    public:
        int key;
        Contacto *value;
        HashEntry(int key, Contacto *value)
        {
            this->key = key;
            this->value = value;
        }
};
 

class HashMap
{
    private:
        HashEntry **table;
    public:   
        HashMap()
  {
            table = new HashEntry * [TABLE_SIZE];
            for (int i = 0; i< TABLE_SIZE; i++)
            {
                table[i] = NULL;
            }
        }
       
        int HashFunc(int key)
        {
        	
            return key % TABLE_SIZE;
        }
       
  void Insert(int key, Contacto *value)
  {
            int hash = HashFunc(key);
            
            while (table[hash] != NULL && table[hash]->key != key)
            {
            	
                hash = HashFunc(hash + 1);
                
            }
            
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashEntry(key, value);
  }
     
        HashEntry* Search(int key)
  		{
      int  hash = HashFunc(key);
      while (table[hash] != NULL && table[hash]->key != key)
      {
          hash = HashFunc(hash + 1);
      }
      if (table[hash] == NULL)
          return NULL;
      else
          return table[hash];
        }
 
      
        void Remove(int key)
  {
      int hash = HashFunc(key);
      while (table[hash] != NULL)
      {
          if (table[hash]->key == key)
              break;
          hash = HashFunc(hash + 1);
      }
            if (table[hash] == NULL)
      {
                cout<<"Elemento no encontrado con esta clave "<<key<<endl;
                return;
            }
            else
            {
                delete table[hash];
            }
            cout<<"Elemento eliminado"<<endl;
        }
        ~HashMap()
  {
            for (int i = 0; i < TABLE_SIZE; i++)
            {
                if (table[i] != NULL)
                    delete table[i];
                delete[] table;
            }
        }
};



class Empleado{
	public:
		string nombre;
		string apellido;
		int edad;
		int codigo;
		int esfuerzo;
		bool nivelado;
		LinkedList<Empleado *> listaHijos;
		HashMap *contactos;
		Empleado(string nombre, string apellido, int edad, int codigo){
			this->nombre = nombre;
			this->apellido = apellido;
			this->edad = edad;
			this->codigo = codigo;
			contactos = new HashMap();
			this->esfuerzo = 0;
			this->nivelado = false;
		}
		
		Empleado(){
			
		}
		
		void auditar(){
			
			int n = listaHijos.size;
			if (n ==0){
				return;
			}
			for(int i =0;i<n;i++){
				
				listaHijos[i]->auditar();
			}
				int max = 0;
			for(int i=0;i<n-1;i++){
				if(listaHijos[i]->esfuerzo > listaHijos[i+1]->esfuerzo){
					max = i;
				}
			}
			
		
			
			
			if(listaHijos[max]->esfuerzo > this->esfuerzo){
				Empleado temp = *listaHijos[max];
				listaHijos[max]->nombre = this->nombre;
				listaHijos[max]->apellido = this->apellido;
				listaHijos[max]->edad = this->edad;
				listaHijos[max]->codigo = this->codigo;
				listaHijos[max]->esfuerzo = this->esfuerzo;
				
				this->nombre = temp.nombre;
				this->apellido = temp.apellido;
				this->edad = temp.edad;
				this->codigo =  temp.codigo;
				this->esfuerzo = temp.esfuerzo;
				
			}
		
		}
		
		void imprimirHijos(){
			cout<<"Soy (["<<this->nombre<<" - "<<"Mi esfuerzo: "<<this->esfuerzo<<"]";
			
			int n = listaHijos.size;
			if (n ==0){
				cout<<" )"<<endl;
				return;
			}
			cout<<endl<<" y mis subordinados son: "<<endl;
			cout<<"{";
			for(int i =0;i<n;i++){
				cout<<"\t";
				listaHijos[i]->imprimirHijos();
			}
			cout<<"}";
			
			
			
		
		}
		
		bool agregarEmpleado(LinkedList<Empleado*> lista){
			
			
			int n = listaHijos.size;
			if (n ==0){
				listaHijos = lista;
				this->nivelado = true;
				
				return true;
			}else{
				return false;
			}
			
			
			
			
		
		}
		
	
		void agregarContacto(Contacto *c){
			
			contactos->Insert(c->telefono,c);
			++esfuerzo;
		}
		
		void buscarContacto(int key){
			HashEntry *c = contactos->Search(key);
			cout<<"Datos del contacto: "<<endl;
			cout<<"Nombre: "<<c->value->nombre<<endl<<"Email: "<<c->value->email<<endl<<endl;
		}
		
		
};


