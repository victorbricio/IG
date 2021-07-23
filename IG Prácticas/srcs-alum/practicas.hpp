// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones públicas auxiliares, comunes a todas las prácticas
// **
// *********************************************************************

#ifndef IG_PRACTICAS_HPP
#define IG_PRACTICAS_HPP

#include <cstring>
#include "MaterialEstandar.hpp"
#include <vector>

//p12.zip

// ---------------------------------------------------------------------
// tipo de datos enumerado para los modos de visualización:

typedef enum
{
   modoPuntos,
   modoAlambre,
   modoSolido,
   modoAjedrez,
   modoPlano,
   modoIluminacion,
   modoSuave
}
   ModosVisu;

const int numModosVisu = 7 ; // numero de modos distintos

// --------------------------------------------------------------------

class PilaMateriales{
private:
  Material * actual ; // material actualmente activado (NULL al inicio)
  vector<Material *> pila ; // materiales activados antes
public:
  PilaMateriales(){ // pone actual a NULL, pila está vacía
    actual = NULL;
  }
  void push(){      // añade una copia de actual en el tope de pila
    pila.push_back(actual);
  }
  void pop(){       // copia tope de pila en actual, elimina el tope, activa actual
    actual = pila[pila.size()-1];
    actual->activar();
  }
  void activarMaterial( Material * material ){  // activa material y lo copia en actual
    actual = material;
    if(actual != NULL){
      actual->activar();
    }
  }
} ;

class ContextoVis
{
   public:
      ModosVisu modoVisu ; // modo de visualización actual
      bool diferido;
      int numero;
      PilaMateriales pilaMateriales;
      ContextoVis() { modoVisu = modoAlambre; diferido = false;  numero = -1;} // poner alambre por defecto
      void setNumero(int n){numero = n;}
};

void FGE_Desocupado();

#endif
