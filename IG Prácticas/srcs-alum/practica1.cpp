// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica1.hpp"

unsigned objeto_activo1 = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

Cubo::Cubo() {

  nombre_obj = "Cubo";

  std::vector<Tupla3f> v;
  std::vector<Tupla3i> t;

  //El Cubo está centrado en el origen.

/*
  ver.push_back(Tupla3f(0.5, -0.5, 0.5));
  ver.push_back(Tupla3f(0.5, -0.5, -0.5));
  ver.push_back(Tupla3f(-0.5, -0.5, -0.5));
  ver.push_back(Tupla3f(-0.5, -0.5, 0.5));
  ver.push_back(Tupla3f(0.5, 0.5, 0.5));
  ver.push_back(Tupla3f(0.5, 0.5, -0.5));
  ver.push_back(Tupla3f(-0.5, 0.5, -0.5));
  ver.push_back(Tupla3f(-0.5, 0.5, 0.5));
*/

  v.push_back(Tupla3f(-0.5, -0.5, -0.5));
  v.push_back(Tupla3f(0.5, -0.5, -0.5));
  v.push_back(Tupla3f(-0.5, 0.5, -0.5));
  v.push_back(Tupla3f(0.5, 0.5, -0.5));
  v.push_back(Tupla3f(0.5, 0.5, 0.5));
  v.push_back(Tupla3f(0.5, -0.5, 0.5));
  v.push_back(Tupla3f(-0.5, -0.5, 0.5));
  v.push_back(Tupla3f(-0.5, 0.5, 0.5));

/*
  tri.push_back(Tupla3i(3, 6, 7));
  tri.push_back(Tupla3i(2, 3, 6));
  tri.push_back(Tupla3i(1, 2, 6));
  tri.push_back(Tupla3i(1, 5, 6));
  tri.push_back(Tupla3i(0, 1, 5));
  tri.push_back(Tupla3i(0, 4, 5));
  tri.push_back(Tupla3i(0, 4, 7));
  tri.push_back(Tupla3i(0, 3, 7));
  tri.push_back(Tupla3i(4, 5, 6));
  tri.push_back(Tupla3i(4, 6, 7));
  tri.push_back(Tupla3i(0, 2, 3));
  tri.push_back(Tupla3i(0, 1, 2));
*/


  t.push_back(Tupla3i(0, 1, 2));
  t.push_back(Tupla3i(1, 2, 3));
  t.push_back(Tupla3i(1, 3, 5));
  t.push_back(Tupla3i(3, 4, 5));
  t.push_back(Tupla3i(4, 5, 6));
  t.push_back(Tupla3i(4, 6, 7));
  t.push_back(Tupla3i(0, 6, 7));
  t.push_back(Tupla3i(0, 2, 7));
  t.push_back(Tupla3i(2, 3, 7));
  t.push_back(Tupla3i(3, 4, 7));
  t.push_back(Tupla3i(0, 1, 6));
  t.push_back(Tupla3i(1, 5, 6));

  HacerMallaInd(v, t, 8, 12);

  //num_ver = 8;
  //num_tri = 12;
};

Cubo *cubo;

Tetraedro::Tetraedro() {
  nombre_obj = "Tetraedro";

  std::vector<Tupla3f> v;
  std::vector<Tupla3i> t;

  //0.5*tg(30) = 0.28867513459. Distancia del centro de una cara al centro de una arista.
  // El Tetraedro está encima de un plano.

  v.push_back(Tupla3f(0.5, 0, 0.28867513459));
  v.push_back(Tupla3f(-0.5, 0, 0.28867513459));
  v.push_back(Tupla3f(0, 0, 0.28867513459 * (-2)));
  v.push_back(Tupla3f(0, 0.28867513459 * 3, 0));


  t.push_back(Tupla3i(0, 1, 2));
  t.push_back(Tupla3i(0, 1, 3));
  t.push_back(Tupla3i(0, 2, 3));
  t.push_back(Tupla3i(1, 2, 3));

  HacerMallaInd(v, t, 4, 4);

  //num_ver = 4;
  //num_tri = 4;
};

Tetraedro *tetraedro;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] ){
  cubo = new Cubo();
  tetraedro = new Tetraedro();
}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla ){
  if (tecla == 'o' || tecla == 'O'){
    objeto_activo1++;
    objeto_activo1 = objeto_activo1%2;

    return true;
  }

   return false ;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// se debe de usar el modo de dibujo que hay en el parámetro 'cv'
// (se accede con 'cv.modoVisu')

void P1_DibujarObjetos( ContextoVis & cv ){
  if (objeto_activo1 == 0)
    cubo->visualizarGL(cv);

  if (objeto_activo1 == 1)
    tetraedro->visualizarGL(cv);
}
