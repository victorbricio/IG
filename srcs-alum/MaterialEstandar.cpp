#include "MaterialEstandar.hpp"
#include <iostream>
using namespace std;

void MaterialEstandar::activar(){
    glEnable( GL_NORMALIZE );
    //glDisable( GL_COLOR_MATERIAL );
    //glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE );
    glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR ) ;

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color[3]);
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente) ;

    if(textura != NULL){
        textura->activar();
        glDisable(GL_COLOR_MATERIAL);
    }
    else{
        glDisable(GL_TEXTURE_2D);
        glDisable( GL_TEXTURE_GEN_S );
        glDisable( GL_TEXTURE_GEN_T );
    }
}

MaterialLata::MaterialLata(){
    textura = new Textura("../imgs/lata-coke.jpg");
    color[0] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.2, 0.1, 0.1, 1.0 );
    color[3] = Tupla4f(1.0, 0.8, 0.8, 1.0);
    exponente = 90;
}

MaterialTapasLata::MaterialTapasLata(){
    textura = NULL;
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.8, 0.8, 0.8, 1.0);
    color[3] = Tupla4f( 0.3, 0.3, 0.3, 1.0 );
    exponente = 90;
}

MaterialPeonBlanco::MaterialPeonBlanco(){
    textura = NULL;
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.5, 0.5, 0.5, 1.0);
    color[3] = Tupla4f( 0, 0, 0, 1.0 );
    exponente = 90;
}


MaterialPeonMadera::MaterialPeonMadera(){
    textura = new Textura("../imgs/text-madera.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[2] = Tupla4f( 0.5, 0.5, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 70;
}


MaterialPeonNegro::MaterialPeonNegro(){
    textura = NULL;
    color[0] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[1] = Tupla4f( 0.0, 0.0, 0.0, 1.0 );
    color[2] = Tupla4f( 0.1, 0.1, 0.1, 1.0 );
    color[3] = Tupla4f(1.0, 1.0, 1.0, 1.0);
    exponente = 50;
}

MaterialSol::MaterialSol(){
    textura = new Textura("sol.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[2] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 100;
}

MaterialTierra::MaterialTierra(){
    textura = new Textura("tierra.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[2] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 100;
}

MaterialMarte::MaterialMarte(){
    textura = new Textura("marte.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[2] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 100;
}

MaterialLuna::MaterialLuna(){
    textura = new Textura("luna.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[2] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 100;
}

MaterialFobos::MaterialFobos(){
    textura = new Textura("fobos.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[2] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 100;
}

MaterialDeimos::MaterialDeimos(){
    textura = new Textura("deimos.jpg", 1);
    color[0] = Tupla4f( 0, 0, 0, 1.0 );
    color[1] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[2] = Tupla4f( 0.6, 0.6, 0.5, 1.0 );
    color[3] = Tupla4f(0.7, 0.5, 0.5, 1.0);
    exponente = 100;
}
