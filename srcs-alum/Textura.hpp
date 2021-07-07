#ifndef TEXTURA_HPP
#define TEXTURA_HPP

#include "jpg_imagen.hpp"
#include "aux.hpp"

using namespace std;

class Textura{
public:
  GLuint idText;         //identificador OpenGL de la textura
  jpg::Imagen * img;     //puntero a objeto imagen con los texels en RAM
  unsigned mgct;         //modo generación cc.tt.: 0 = desactivado, 1 = objeto, 2 = mundo.
  float cs[4],           //coeficientes (S) para generación de cc.tt. (si mgct != 0)
        ct[4];           //coeficientes (T) para generación de cc.tt. (si mgct != 0)

  void activar();    // activar la textura: habilita texturas y activa esta en concreto
	Textura(const string &archivoJPG, int m = 0);
};


#endif
