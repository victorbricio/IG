#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica2.hpp"

unsigned objeto_activo2 = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

MallaPLY *mply;
MallaRevol *revol;

void P2_Inicializar( int argc, char *argv[] ){
  mply = new MallaPLY("../plys/ant");
  revol = new MallaRevol("../plys/peon", 24, true, true);
}

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla ){
  if (tecla == 'o' || tecla == 'O'){
    objeto_activo2++;
    objeto_activo2 = objeto_activo2%2;

    return true;
  }

   return false ;
 }

 void P2_DibujarObjetos( ContextoVis & cv ){
   if (objeto_activo2 == 0)
      mply->visualizarGL(cv);
   if (objeto_activo2 == 1)
      revol->visualizarGL(cv);
 }
