// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Carlos Ureña Almagro
// **
// ** Función 'main', inicialización y gestores de eventos
// **
// *********************************************************************

// includes de C/C++

#include <cctype>   // toupper
#include <string>   // std::string
#include <iostream> // std::cout
#include <fstream>  // ifstream
#include <cmath>    // fabs

// includes en ../include
#include "aux.hpp"  // include cabeceras de opengl / glut / glut / glew

// includes de archivos en el directorio de trabajo (de las prácticas)
#include "practicas.hpp"
#include "practica1.hpp"
#include "practica2.hpp"
#include "practica3.hpp"
#include "practica4.hpp"
#include "shaders.hpp"

// evita la necesidad de escribir std::
using namespace std ;

// *********************************************************************
// **
// ** Variables globales
// ** (se inicializan en las funciones de inicialización)
// **
// *********************************************************************

// variables que definen la posicion de la camara en coordenadas polares

float
   camara_angulo_x ,   // angulo de rotación entorno al eje X
   camara_angulo_y ;   // angulo de rotación entorno al eje Y

// ---------------------------------------------------------------------
// variables que definen el view-frustum (zona visible del mundo)

float
   frustum_factor_escala ,  // factor de escala homogeneo que se aplica al frustum (sirve para alejar o acercar)
   frustum_ancho ,          // ancho, en coordenadas del mundo
   frustum_dis_del ,        // distancia al plano de recorte delantero (near)
   frustum_dis_tra ;        // distancia al plano de recorte trasero (far)

// ---------------------------------------------------------------------
// variables que determinan la posicion y tamaño inicial de la ventana
// (el tamaño se actualiza al cambiar el tamaño durante la ejecución)

int
   ventana_pos_x  ,  // posicion (X) inicial de la ventana, en pixels
   ventana_pos_y  ,  // posicion (Y) inicial de la ventana, en pixels
   ventana_tam_x  ,  // ancho inicial y actual de la ventana, en pixels
   ventana_tam_y  ;  // alto inicial actual de la ventana, en pixels

// ---------------------------------------------------------------------

ContextoVis
   contextoVis ; // contexto de visualización actual (modo de visualización)

unsigned
   practicaActual ;  // practica actual (cambiable por teclado) (1,2,3,4,5)

// *********************************************************************
// **
// ** Funciones auxiliares:
// **
// *********************************************************************

//GLuint idProg;

void FGE_Desocupado(){
  bool desactivar = true;

  if (practicaActual == 3)
    desactivar = ! P3_FGE_Desocupado();

  if (desactivar){
    glutIdleFunc(NULL);
  }
}


// fija la transformación de proyeccion (zona visible del mundo == frustum)

void FijarProyeccion()
{
   const GLfloat ratioYX = GLfloat( ventana_tam_y )/GLfloat( ventana_tam_x );

   CError();

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // (3) proyectar en el plano de visión
   glFrustum
   (  -frustum_ancho,
      +frustum_ancho,
      -frustum_ancho*ratioYX,
      +frustum_ancho*ratioYX,
      +frustum_dis_del,
      +frustum_dis_tra
   );


   // (2) situar el origen (0,0,0), en mitad del view frustum
   //     (en la rama negativa del eje Z)
   glTranslatef( 0.0,0.0,-0.5*(frustum_dis_del+frustum_dis_tra));

    // (1) aplicar factor de escala
   glScalef( frustum_factor_escala, frustum_factor_escala,  frustum_factor_escala );

   CError();
}


// ---------------------------------------------------------------------
// fijar viewport y proyección (viewport ocupa toda la ventana)

void FijarViewportProyeccion()
{
   glViewport( 0, 0, ventana_tam_x, ventana_tam_y );
   FijarProyeccion() ;
}

// ---------------------------------------------------------------------
// fija la transformación de vista (posiciona la camara)

void FijarCamara()
{

   CError();
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

   glRotatef(camara_angulo_x,1,0,0);
   glRotatef(camara_angulo_y,0,1,0);

   CError();
}

// ---------------------------------------------------------------------
// dibuja los ejes utilizando la primitiva grafica de lineas

void DibujarEjes()
{
   const float long_ejes = 30.0 ;

   // establecer modo de dibujo a lineas (podría estar en puntos)
   glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

   // dibujar tres segmentos
   glBegin(GL_LINES);
      // eje X, color rojo
      glColor3f( 1.0, 0.0, 0.0 );
      glVertex3f( -long_ejes, 0.0, 0.0 );
      glVertex3f( +long_ejes, 0.0, 0.0 );
      // eje Y, color verde
      glColor3f( 0.0, 1.0, 0.0 );
      glVertex3f( 0.0, -long_ejes, 0.0 );
      glVertex3f( 0.0, +long_ejes, 0.0 );
      // eje Z, color azul
      glColor3f( 0.0, 0.0, 1.0 );
      glVertex3f( 0.0, 0.0, -long_ejes );
      glVertex3f( 0.0, 0.0, +long_ejes );
   glEnd();

   // bola en el origen, negra
   glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
   glColor3f(0.0,0.0,0.0);
   glutSolidSphere(0.01,8,8);

}

// ---------------------------------------------------------------------
// asigna el color de fondo actual a todos los pixels de la ventana

void LimpiarVentana()
{
   glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

// ---------------------------------------------------------------------
// dibuja los objetos de la escena

void DibujarObjetos()
{
   switch( practicaActual )
   {
      case 1 :
         P1_DibujarObjetos( contextoVis  ) ; // definido en 'practica1.hpp'
         break ;
      case 2 :
        P2_DibujarObjetos( contextoVis  ) ;
        break;
      case 3 :
        P3_DibujarObjetos( contextoVis  ) ;
        break;
      case 4 :
        P4_DibujarObjetos( contextoVis  ) ;
        break;
      default :
         cout << "El valor de 'practicaActual' (" << practicaActual  << ") es incorrecto" << endl ;
         break ;
   }
}


// *********************************************************************
// **
// ** Funciones gestoras de eventos
// **
// *********************************************************************

// F.G. del evento de redibujado (se produce cuando hay que volver a
// dibujar la ventana, tipicamente tras producirse otros eventos)

void FGE_Redibujado()
{

  glUseProgram(0);

  //glUseProgram(idProg);

   using namespace std ;
   //cout << "redibujado......" << endl << flush ;
   FijarViewportProyeccion() ; // necesario pues la escala puede cambiar
   FijarCamara();
   LimpiarVentana();
   DibujarEjes() ;
   DibujarObjetos();
   glutSwapBuffers();
}

// ---------------------------------------------------------------------
// F.G. del evento de cambio de tamaño de la ventana

void FGE_CambioTamano( int nuevoAncho, int nuevoAlto )
{
   // guardar nuevo tamaño de la ventana
   ventana_tam_x  = nuevoAncho;
   ventana_tam_y  = nuevoAlto ;

   // forzar un nuevo evento de redibujado, para actualizar ventana
   glutPostRedisplay();
}

// ---------------------------------------------------------------------
// F.G. del evento de pulsación de la tecla normal
//
// parámetros:
//       tecla: carácter corresondiente a la tecla (minúscula)
//       x_raton, y_raton : posición del ratón al pulsar

void FGE_PulsarTeclaNormal( unsigned char tecla, int x_raton, int y_raton )
{
   bool redibujar = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
   switch (toupper(tecla))
   {
      case 'Q' :
      case 27  :
         exit( 0 );
         break ;
      case '+' :
         frustum_factor_escala *= 1.05;
         break;
      case '-' :
         frustum_factor_escala /= 1.05;
         break;
      case 'm' :
      case 'M':
        if (contextoVis.modoVisu == modoPuntos)
          contextoVis.modoVisu = modoAlambre;
        else if (contextoVis.modoVisu == modoAlambre)
          contextoVis.modoVisu = modoSolido;
        else if (contextoVis.modoVisu == modoSolido)
          contextoVis.modoVisu = modoAjedrez;
        else if (contextoVis.modoVisu == modoAjedrez)
          contextoVis.modoVisu = modoPlano;
        else if (contextoVis.modoVisu == modoPlano)
          contextoVis.modoVisu = modoIluminacion;
        else if (contextoVis.modoVisu == modoIluminacion)
          contextoVis.modoVisu = modoSuave;
        else if (contextoVis.modoVisu == modoSuave)
          contextoVis.modoVisu = modoPuntos;
        break;
      case 'p' :
      case 'P' :
        if (practicaActual == 3)
          glutIdleFunc(FGE_Desocupado);

        if (practicaActual == 4)
            practicaActual = 1;
        else
          practicaActual++;
        break;
      case 'v' :
      case 'V' :
          contextoVis.diferido = !contextoVis.diferido;
        break;
      default:
         redibujar = false ;
         switch( practicaActual )
         {
            case 1 :
               redibujar = P1_FGE_PulsarTeclaNormal( tecla ) ; // true si es necesario redibujar
               break ;
            case 2 :
              redibujar = P2_FGE_PulsarTeclaNormal( tecla ) ;
              break;
            case 3 :
              redibujar = P3_FGE_PulsarTeclaNormal( tecla ) ;

              if(redibujar && tecla == 'a')
                glutIdleFunc(FGE_Desocupado);
              break;
            case 4 :
              redibujar = P4_FGE_PulsarTeclaNormal( tecla ) ;
              break;
            default :
               redibujar = false ; // la tecla no es de la práctica activa (no es necesario redibujar)
         }
         break ;
   }
   using namespace std ;
   //cout << "tecla normal....." << frustum_factor_escala << endl ;

   // si se ha cambiado algo, forzar evento de redibujado
   if (redibujar)
      glutPostRedisplay();
}

// ---------------------------------------------------------------------
// F.G. del evento de pulsación de la tecla especial
//
// parámetros:
//       tecla: código GLUT de la tecla pulsada
//       x_raton, y_raton : posición del ratón al pulsar


void FGE_PulsarTeclaEspecial( int tecla, int x_raton, int y_raton )
{
   bool redisp = true ;
   const float da = 5.0 ; // incremento en grados de ángulos de camara

   switch ( tecla )
   {
      case GLUT_KEY_LEFT:
         camara_angulo_y = camara_angulo_y - da ;
         break;
      case GLUT_KEY_RIGHT:
         camara_angulo_y = camara_angulo_y + da ;
         break;
      case GLUT_KEY_UP:
         camara_angulo_x = camara_angulo_x - da ;
         break;
      case GLUT_KEY_DOWN:
         camara_angulo_x = camara_angulo_x + da ;
         break;
      case GLUT_KEY_PAGE_UP:
         frustum_factor_escala *= 1.05;
         break;
      case GLUT_KEY_PAGE_DOWN:
         frustum_factor_escala /= 1.05;
         break;
      default:
         redisp = false ;
         break ;
	}
   using namespace std ;

   // si se ha cambiado algo, forzar evento de redibujado
   if ( redisp )
      glutPostRedisplay();
}

// *********************************************************************
// **
// ** Funciones de inicialización
// **
// *********************************************************************

// inicialización de GLUT: creación de la ventana, designar FGEs

void Inicializa_GLUT( int argc, char * argv[] )
{

   // inicializa variables globales usadas en esta función (y otras)
   ventana_pos_x  = 50 ;
   ventana_pos_y  = 50  ;
   ventana_tam_x  = 800 ;  // ancho inicial y actual de la ventana, en pixels
   ventana_tam_y  = 800 ;  // alto inicial actual de la ventana, en pixels

   // inicializa glut:
   glutInit( &argc, argv );

   // establece posicion inicial de la ventana:
   glutInitWindowPosition( ventana_pos_x, ventana_pos_y );

   // establece tamaño inicial de la ventana:
   glutInitWindowSize( ventana_tam_x, ventana_tam_y );

   // establece atributos o tipo de ventana:
   glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );

   // crea y visualiza una ventana:
   glutCreateWindow("Practicas IG GIM (16-17)");

   // establece función gestora del evento de redibujado:
   glutDisplayFunc( FGE_Redibujado );

   // establece función gestora del evento de cambio de tamaño:
   glutReshapeFunc( FGE_CambioTamano );

   // establece función gestora del evento de pulsación de tecla normal:
   glutKeyboardFunc( FGE_PulsarTeclaNormal );

   // establece función gestora del evento de pulsación de tecla especial:
   glutSpecialFunc( FGE_PulsarTeclaEspecial );
}

// ---------------------------------------------------------------------
// Inicialización de las variables globales del programa

void Inicializa_Vars( )
{
   // inicializar parámetros del frustum
   frustum_dis_del         = 0.1 ;
   frustum_dis_tra         = 10.0;
   frustum_ancho           = 0.5*frustum_dis_del ;
   frustum_factor_escala   = 2.0 ;

   // inicializar parámetros de la cámara
   camara_angulo_x = 0.0 ;
   camara_angulo_y = 0.0 ;

   // inicializar práctica actual
   practicaActual = 4 ;
}

// ---------------------------------------------------------------------
// inicialización de OpenGL

void Inicializa_OpenGL( )
{
   // borrar posibles errores anteriores
   CError();

   #ifdef LINUX
   ExigirGLEW("");
   #endif

	//idProg = CrearPrograma("fragmentShader.glsl","vertexShader.glsl");

   // habilitar test de comparación de profundidades para 3D (y 2D)
   // es necesario, no está habilitado por defecto:
   // https://www.opengl.org/wiki/Depth_Buffer
   glEnable( GL_DEPTH_TEST );

   // establecer color de fondo: (1,1,1) (blanco)
   glClearColor( 1.0, 1.0, 1.0, 1.0 ) ;

   // establecer color inicial para todas las primitivas
   glColor3f( 0.7, 0.2, 0.4 ) ;

   // establecer ancho de línea
   glLineWidth( 1.0 );

   // establecer tamaño de los puntos
   glPointSize( 2.0 );

   // establecer modo de visualización de prim.
   // (las tres posibilidades son: GL_POINT, GL_LINE, GL_FILL)
   glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

   // imprimir datos del hardware y la implementación de OpenGL
   using namespace std ;
   cout  << "Datos de versión e implementación de OpenGL" << endl
         << "  implementación de : " << glGetString(GL_VENDOR)  << endl
         << "  hardware          : " << glGetString(GL_RENDERER) << endl
         << "  version de OpenGL : " << glGetString(GL_VERSION) << endl
         << "  version de GLSL   : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl
         << flush ;

   // ya está
   CError();
}

// ---------------------------------------------------------------------
// Código de inicialización (llama a los dos anteriores, entre otros)

void Inicializar( int argc, char *argv[] )
{
   // inicializa las variables del programa
   Inicializa_Vars() ;

   // glut (crea la ventana)
   Inicializa_GLUT( argc, argv ) ;

   // opengl: define proyección y atributos iniciales
   Inicializa_OpenGL() ;

   // inicializar práctica 1.
   P1_Inicializar( argc, argv ) ;
   P2_Inicializar( argc, argv ) ;
   P3_Inicializar( argc, argv ) ;
   P4_Inicializar( argc, argv ) ;

}

// *********************************************************************
// **
// ** Función principal
// **
// *********************************************************************


int main( int argc, char *argv[] )
{
   // incializar el programa
   Inicializar( argc, argv ) ;

   // llamar al bucle de gestión de eventos de glut, tiene el
   // control hasta el final de la aplicación
   glutMainLoop();

   // ya está
   return 0;
}
