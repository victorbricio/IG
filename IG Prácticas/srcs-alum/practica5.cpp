#include <cmath>
#include <string>
#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica1.hpp"
#include "practica3.hpp"
#include "NodoGrafoEscena.hpp"
#include "ColeccionFL.hpp"
#include "FuenteLuz.hpp"
//#include "Camara.hpp"
#include "Escena.hpp"

//#include "shaders.hpp"

/*using namespace std;

FuentePosicional * p5_luzPosicional = NULL;
FuenteDireccional * p5_luzDireccional = NULL;

ColeccionFL p5_fuentes;

Escena * p5_escena = NULL;

int p5_angulo = 0;

static vector< CamaraInteractiva > p5_camaras;
static int p5_camara_activa;

static int xant, yant;
enum estado{MOVIENDO_CAMARA_FIRSTPERSON, OTHER};
static estado estadoRaton;

// ---------------------------------------------------------------------
void P5_Inicializar( int argc, char *argv[] ){

	p5_escena = new Escena();
	p5_escena->calcularNormales();
	p5_luzPosicional = new FuentePosicional(Tupla3f(10,15,25));
	p5_luzDireccional = new FuenteDireccional(0,0);

	p5_fuentes.fuentes.push_back(p5_luzPosicional);
	p5_fuentes.fuentes.push_back(p5_luzDireccional);

	// alzado
    p5_camaras.push_back(CamaraInteractiva());
    p5_camaras[0].mcv = MarcoCoorVista(Tupla3f(0.5,1,4), Tupla3f(0.5,1,0), Tupla3f(0,1,0));
    // perfil, con proyección ortográfica
    p5_camaras.push_back(CamaraInteractiva());
    p5_camaras[1].mcv = MarcoCoorVista(Tupla3f(-4,1,0), Tupla3f(0,1,0), Tupla3f(0,1,0));
    // frente, con proyección perspectiva
    p5_camaras.push_back(CamaraInteractiva());
    p5_camaras[2].vf = ViewFrustum(45, 1, 0.4, 30);
    p5_camaras[2].mcv = MarcoCoorVista(Tupla3f(0.1,3,0.1), Tupla3f(0,0,0), Tupla3f(0,1,0));
	p5_camara_activa = 0;
}

// ---------------------------------------------------------------------
bool P5_FGE_PulsarTeclaNormal(  unsigned char tecla ){

	if(tecla == 'C'){
        p5_camara_activa += 1;
        p5_camara_activa %= p5_camaras.size();
		return true;
	}
	else if(tecla == 'V'){
        p5_camaras[p5_camara_activa].examinar = !p5_camaras[p5_camara_activa].examinar;
        return true;
    }
    else if(tecla == '+'){
        p5_camaras[p5_camara_activa].desplaZ(2);
        return true;
    }
    else if(tecla == '-'){
        p5_camaras[p5_camara_activa].desplaZ(-2);
        return true;
    }

	return false;
}


bool P5_FGE_PulsarTeclaEspecial(  unsigned char tecla ){

    if(tecla == GLUT_KEY_LEFT){
        p5_camaras[p5_camara_activa].moverHV(-1,0);
        return true;
    }
    else if(tecla == GLUT_KEY_RIGHT){
        p5_camaras[p5_camara_activa].moverHV(1,0);
        return true;
    }
    else if(tecla == GLUT_KEY_UP){
        p5_camaras[p5_camara_activa].moverHV(0,1);
        return true;
    }
    else if(tecla == GLUT_KEY_DOWN){
        p5_camaras[p5_camara_activa].moverHV(0,-1);
        return true;
    }

    return false;
}

void P5_DibujarObjetos( ContextoVis & cv){
		p5_fuentes.activar();
		p5_escena->visualizarGL(cv);
		p5_fuentes.desactivar();
}

void P5_FijarMVPOpenGL(){
    p5_camaras[p5_camara_activa].activar();
}

void P5_FGE_ClickRaton( int button, int state, int x, int y ){
    if (button == GLUT_RIGHT_BUTTON){
        if (state == GLUT_DOWN){
            // Se pulsa el botón, por lo que se entra en el estado "moviendo cámara"
            estadoRaton = MOVIENDO_CAMARA_FIRSTPERSON;
            xant = x;
            yant = y;
        }
        else{
            // Se levanta el botón, por lo que se sale del estado "moviendo cámara"
            estadoRaton = OTHER;
        }
    }
    else if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN){
            estadoRaton = OTHER;
            GLubyte pixels[3];
            Objeto3D *obj;
            glDisable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
            glDisable(GL_DITHER);
            glShadeModel(GL_FLAT);
            glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glColor3ub(0,0,0);
            p5_escena->modoSeleccion();
            glReadPixels(x, (glutGet( GLUT_WINDOW_HEIGHT ) - y), 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);

            obj = p5_escena->buscarNodoConIdent(pixels[0]);

            if(obj != NULL){
                cout << "Centrando imagen sobre " << obj->nombre() << endl;
                p5_camaras[p5_camara_activa].modoExaminar( obj->centro );
            }
            else
                cout << "Ningún nodo seleccionado" << endl;

            glEnable(GL_DITHER);
        }
        glutPostRedisplay();
    }
}

void P5_FGE_RatonMovido( int x, int y ){
    if ( estadoRaton==MOVIENDO_CAMARA_FIRSTPERSON ){
        int dx = x-xant;
        int dy = y-yant;

        p5_camaras[p5_camara_activa].moverHV(dx, dy);

        xant = x;
        yant = y;
    }
}*/
