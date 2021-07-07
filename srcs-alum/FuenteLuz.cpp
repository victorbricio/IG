#include "FuenteLuz.hpp"

void FuenteLuz::activar(int i){
  glEnable(GL_LIGHT0+i);

  glLightfv( GL_LIGHT0+i, GL_POSITION, posvec);
  glLightfv(GL_LIGHT0+i, GL_AMBIENT, colores[0]);
  glLightfv(GL_LIGHT0+i, GL_DIFFUSE, colores[1]);
  glLightfv(GL_LIGHT0+i, GL_SPECULAR, colores[2]);
}

void FuenteLuz::desactivar(int i){
  glDisable(GL_LIGHT0+i);
}

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial ){
  posvec = Tupla4f(alpha_inicial, beta_inicial, 1, 0); //en este caso w=0
  // colores[]: 0=ambiental, 1=difuso, 2=especular.
  colores[0] = Tupla4f(0 ,0 ,0 , 1.0);
  colores[1] = Tupla4f(1, 1, 1 , 1.0);
  colores[2] = Tupla4f(1, 1, 1 , 1.0);
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento ){
  if(angulo == 0)
      posvec = posvec + Tupla4f(incremento, 0, 0, 0);
  else
      posvec = posvec + Tupla4f(0, 0, incremento, 0);
  std::cout << posvec << std::endl;
}


FuentePosicional::FuentePosicional( const Tupla3f & posicion ){
  posvec = Tupla4f(posicion[0], posicion[1], posicion[2], 1); //en este caso w=1
  // colores[]: 0=ambiental, 1=difuso, 2=especular.
  colores[0] = Tupla4f(0, 0, 0, 1.0);
  colores[1] = Tupla4f(1, 1, 1, 1.0);
  colores[2] = Tupla4f(1, 1, 1, 1.0);
}
