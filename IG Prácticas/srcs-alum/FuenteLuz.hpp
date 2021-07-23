#ifndef FUENTELUZ_HPP
#define FUENTELUZ_HPP

#include "aux.hpp" //Constantes GL_LIGHT0, GL_LIGHT0+i
#include "tuplasg.hpp"

class FuenteLuz{
public:
  Tupla4f posvec;       // posición (si w=1) o vector de dirección (si w=0)
  Tupla4f colores[3];   // colores: 0=ambiental, 1=difuso, 2=especular
  float longi,lati;     // ángulos de rotación (si direccional)

  void activar(int i);      // activarla (con ident. OpenGL GL_LIGHT0+i)
  void desactivar(int i);   // desactivarla (con ident. OpenGL GL_LIGHT0+i)
};


class FuenteDireccional : public FuenteLuz{
public:
  FuenteDireccional ( float alpha_inicial, float beta_inicial ) ; // inicializar la fuente de luz
  void variarAngulo ( unsigned angulo, float incremento ) ;       // Cambiar ángulo: (angulo==0 –>variar alpha, angulo==1 –>variar beta)
};


class FuentePosicional : public FuenteLuz{
public:
  FuentePosicional ( const Tupla3f & posicion ) ;
};


#endif
