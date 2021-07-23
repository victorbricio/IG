#include "aux.hpp"
#include "matrices-tr.hpp"
#include <algorithm>
#include <iostream>

#ifndef _CAMARA_H_
#define _CAMARA_H_

/*using namespace std;

// marco de coordenadas (cartesiano) de la vista
class MarcoCoorVista{
public:
    Tupla3f org,        // origen del marco de coordenadas
            eje[3],     // ejes(0=X,1=Y, 2=Z) del marco de cc(ortonormales)
            pvup;       //
    Matriz4f matrizML;  // matriz marco->mundo
    Matriz4f matrizLM;  // matriz marco->mundo

    //foco en origen, mirando hacia Z-, vup=Y+
    MarcoCoorVista();
    // constructor: mismos parámetros que gluLookAt
    MarcoCoorVista( const Tupla3f &pfoco, const Tupla3f &paten, const Tupla3f &pvup);
};


class ViewFrustum{
public:
    bool persp; // true para perspectiva, false para ortográfica
    float left, right,  // extensión en X(left<right)
          bottom, top,  // extensión en Y(bottom<top)
          near, far;    // extensión en Z(rama negativa) (0 < near < far)
    Matriz4f matrizProy; // matriz de proyección P: cc. cámara ===> cc.recortado

    ViewFrustum(); // view-frustum ortográfico de lado 2, centro en (0,0,0)
    // crea view-frustum perspectiva, mismos parámetros que gluPerspective
    ViewFrustum( float hfovy, float aspect, float zNear, float zFar );
};


class Camara{
public:
    MarcoCoorVista mcv; // marco de coordenadas de la vista
    ViewFrustum vf;     // parámetros de la proyección

    Camara();           // usa constructores por defecto para mc y vf
    void fijarMVPOpenGL(); // fijar matrices MODELVIEW y PROJECTION de OpenGL
};

class CamaraInteractiva : public Camara{
	public:
		bool examinar;
		bool perspectiva;
		float ratio_yx_vp;
		float longi, lati;
		Tupla3f aten;
		float dist;

        CamaraInteractiva();

		CamaraInteractiva(bool examinar_ini, int ratio_yx_vp_ini, float longi_ini_grad,
						  float lati_ini_grad, const Tupla3f & aten_ini, bool pers_ini);

		void calcularViewfrustum();
		void calcularMarcoCamara();

		void moverHV(int nh, int nv);
		void desplaZ(int nz);

		void modoExaminar(const Tupla3f & pAten);
		void modoExaminar();
		void modoPrimeraPersona();

		void activar();
};*/

#endif
