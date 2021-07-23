#include "Textura.hpp"

// activa textura en el cauce fijo de OpenGL
void Textura::activar(){
  glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, idText);

	if(mgct == 1){
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR ) ;
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR ) ;
	}
	else if(mgct == 2){
		glEnable( GL_TEXTURE_GEN_S );
		glEnable( GL_TEXTURE_GEN_T );
		glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR ) ;
		glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR ) ;
	}
}

// crea un textura a partir de un archivo
Textura::Textura( const std::string & archivoJPG, int m){
  glGenTextures(1,&idText);
	glBindTexture(GL_TEXTURE_2D,idText);

	img = new jpg::Imagen(archivoJPG.c_str());

	glTexImage2D(GL_TEXTURE_2D, 0, 3, img->tamX(), img->tamY(), 0, GL_RGB, GL_UNSIGNED_BYTE, img->leerPixels());

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	mgct = m;
}
