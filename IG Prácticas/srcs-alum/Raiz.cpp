#include "Raiz.hpp"
#include "matrices-tr.hpp"
#include "MallaRevol.hpp"
#include <vector>

Raiz::Raiz(){

  agregar (new Sistema(0.0, 2.0, 2, false, false), -1);

  parametros.push_back(Parametro("movimiento del Sol",
              ((NodoGrafoEscena*)entradas[0].objeto)->entrada(1).matriz,
              [=](float p){return MAT_Traslacion(p, 0.0, 0.0);}, true, 0.0, 0.5, 1.0));

  parametros.push_back(Parametro("movimiento de la Tierra",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(4).objeto)->entrada(0).matriz,
              [=](float p){return MAT_Rotacion(p, 0.0, 0.0, 1.0);}, false, 0.0, 125, 1.0));

  parametros.push_back(Parametro("movimiento de Marte",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(5).objeto)->entrada(0).matriz,
              [=](float p){return MAT_Rotacion(p, 0.0, 0.0, 1.0);}, false, 0.0, 75, 1.0));

  parametros.push_back(Parametro("movimiento de la Luna",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(4).objeto)->entrada(4).objeto)->entrada(1).matriz,
              [=](float p){return MAT_Rotacion(p, 0.0, 0.0, 1.0);}, false, 0.0, 90, 1.0));

  parametros.push_back(Parametro("oscilación de la Luna",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(4).objeto)->entrada(4).objeto)->entrada(0).matriz,
              [=](float p){return MAT_Rotacion(p, 1.0, 1.0, 0.0);}, true, 0.0, 50, 5));

  parametros.push_back(Parametro("movimiento de Fobos",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(5).objeto)->entrada(4).objeto)->entrada(1).matriz,
              [=](float p){return MAT_Rotacion(p, 0.0, 0.0, 1.0);}, false, 0.0, 100, 1.0));

  parametros.push_back(Parametro("oscilación de Fobos",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(5).objeto)->entrada(4).objeto)->entrada(0).matriz,
              [=](float p){return MAT_Rotacion(p, 1.0, 1.0, 0.0);}, true, 0.0, 60, 5));

  parametros.push_back(Parametro("movimiento de Deimos",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(5).objeto)->entrada(5).objeto)->entrada(1).matriz,
              [=](float p){return MAT_Rotacion(p, 0.0, 0.0, 1.0);}, false, 0.0, 75, 1.0));

  parametros.push_back(Parametro("oscilación de Deimos",
              ((NodoGrafoEscena*)((NodoGrafoEscena*)((NodoGrafoEscena*)entradas[0].objeto)->entrada(5).objeto)->entrada(5).objeto)->entrada(0).matriz,
              [=](float p){return MAT_Rotacion(p, 1.0, 1.0, 0.0);}, true, 0.0, 40, 5));
}

Astro::Astro(int p){
  if (p == 0)
    agregar(new MaterialSol());
  if (p == 1)
    agregar(new MaterialTierra());
  if (p == 2)
    agregar(new MaterialMarte());
  if (p == 3)
    agregar(new MaterialLuna());
  if (p == 4)
    agregar(new MaterialFobos());
  if (p == 5)
    agregar(new MaterialDeimos());

  agregar(new MallaRevol("sol", 20, true, false), -1);

  this->calcularNormales();
}

Sistema::Sistema(float t, float e, int subsistemas, bool marte, bool fobos){
  if (subsistemas == 0)
    agregar(MAT_Rotacion(0.0, 1.0, 1.0, 0.0));

  agregar(MAT_Rotacion(0.0, 0.0, 0.0, 1.0));
  agregar(MAT_Traslacion(t, 0.0, 0.0));
  agregar(MAT_Escalado(e, e, e));
  if (subsistemas == 0){
    if (marte && fobos)
      agregar(new Astro(4), 4);
    else if (marte && !fobos)
      agregar(new Astro(5), 5);
    else if (!marte)
      agregar(new Astro(3), 3);
  }
  else if (subsistemas == 1){
    agregar(new Astro(1), 1);
    agregar(new Sistema(0.125, 0.55, 0, false, false), -1);
  }
  else if (subsistemas == 2 && !marte){
    agregar(new Astro(0), 0);
    agregar(new Sistema(0.2, 0.65, 1, false, false), -1);
    agregar(new Sistema(0.5, 0.5, 2, true, false), -1);
  }
  else if (subsistemas == 2 && marte){
    agregar(new Astro(2), 2);
    agregar(new Sistema(0.15, 0.5, 0, true, true), -1);
    agregar(new Sistema(0.24, 0.375, 0, true, false), -1);
  }
}
