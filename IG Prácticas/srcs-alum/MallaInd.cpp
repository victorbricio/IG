#include "MallaInd.hpp"
using namespace std;

void MallaInd::HacerMallaInd(std::vector<Tupla3f> v, std::vector<Tupla3i> t, int nv, int nt){
  ver = v;
  tri = t;
  num_ver = nv;
  num_tri = nt;
}


void MallaInd::visualizarBE(ContextoVis & cv){
  glBegin(GL_TRIANGLES);

  for (unsigned int i = 0; i < num_tri; i++)
    for (unsigned int j = 0; j < 3; j++){
      unsigned int ind_ver = tri[i][j];
      glVertex3fv(ver[ind_ver]);
    }

  glEnd();
}

/*void MallaInd::visualizarGL(ContextoVis & cv){

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &ver[0]);

  if (cv.modoVisu == modoPuntos)
    glDrawElements(GL_POINTS, 3 * num_tri, GL_UNSIGNED_INT, tri.data());

  else if (cv.modoVisu == modoAlambre){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, 3 * num_tri, GL_UNSIGNED_INT, tri.data());
  }

  else if (cv.modoVisu == modoSolido){
    glShadeModel(GL_FLAT);
    glColor3f(0,0,0);
    glDrawElements(GL_TRIANGLES, 3 * num_tri, GL_UNSIGNED_INT, tri.data());
  }

  else if (cv.modoVisu == modoAjedrez){
    visualizarCarasNormales();

    std::vector<Tupla3i> unos, otros;

    for (int i = 0; i < num_tri; i++){
      if (i%2 == 0)
        unos.push_back(tri[i]);
      else
        otros.push_back(tri[i]);
    }

    glShadeModel(GL_FLAT);
  	glColor3f(1,1,0);
  	glDrawElements(GL_TRIANGLES, 3 * unos.size(), GL_UNSIGNED_INT, unos.data());

  	glColor3f(0,1,1);
  	glDrawElements(GL_TRIANGLES, 3 * otros.size(), GL_UNSIGNED_INT, otros.data());
  }

  else if (cv.modoVisu == modoPlano){
    glShadeModel(GL_FLAT);

    if (cv.numero == 0)
      glColor3f(1,1,0);
    else if (cv.numero == 1)
      glColor3f(0,0,1);
    else if (cv.numero == 2)
      glColor3f(1,0,0);
    else if (cv.numero == 3)
      glColor3f(0.5,0.5,0.5);
    else if (cv.numero == 4)
      glColor3f(1,0,1);
    else if (cv.numero == 5)
      glColor3f(0,0,0);

    glDrawElements(GL_TRIANGLES, 3 * num_tri, GL_UNSIGNED_INT, tri.data());
  }

  else if(cv.modoVisu == modoIluminacion){
    if(tabla_textura.size() != 0){
      glTexCoordPointer(2, GL_FLOAT, 0, tabla_textura.data());
      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    if(vertices_normales.size() != 0){
      glNormalPointer(GL_FLOAT, 0, vertices_normales.data());
      glEnableClientState(GL_NORMAL_ARRAY);
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, ver.data());

    glShadeModel(GL_FLAT);
    glDrawElements(GL_TRIANGLES, num_tri*3, GL_UNSIGNED_INT, &tri[0] );

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
  }

  else if (cv.modoVisu == modoSuave){
    if(tabla_textura.size() != 0){
      for(int i = 0; i < tabla_textura.size(); i++){
        //cout << tabla_textura[i](0) << " " << tabla_textura[i](1) << endl;
      }
      glTexCoordPointer(2, GL_FLOAT, 0, tabla_textura.data());
      glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    if(vertices_normales.size() != 0){
      glNormalPointer(GL_FLOAT, 0, vertices_normales.data());
      glEnableClientState(GL_NORMAL_ARRAY);
    }

    //visualizarCarasNormales();
    glShadeModel(GL_SMOOTH);
    glDrawElements( GL_TRIANGLES, 3 * num_tri, GL_UNSIGNED_INT, &tri[0] );

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
  }

  glDisableClientState(GL_VERTEX_ARRAY);
}
*/
float normaR3(Tupla3f t){
		return abs(sqrt( t[0]*t[0] + t[1]*t[1] + t[2]*t[2] ));
}

void MallaInd::visualizarGL(ContextoVis & cv){
  if (cv.modoVisu == modoPuntos){
      //cout << "Modo Puntos" << endl;
      //visualizarCaja();
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      glVertexPointer( 3, GL_FLOAT, 0, &ver[0] ); // establecer dirección y estructura
      // visualizar recorriendo los vértices en el orden de los índices:
      glDrawElements( GL_POINTS, num_tri*3, GL_UNSIGNED_INT, &tri[0] );
      glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
    }

  else if (cv.modoVisu == modoAlambre){
      glDisable(GL_LIGHTING);
      glDisable(GL_TEXTURE_2D);
      //cout << "Modo Alambre" << endl;
      //visualizarCaja();
      //visualizarCarasNormales();
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //(con solido: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);)
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      //glVertexPointer( 4, GL_FLOAT, 0, &ver_cajaenglobante[0] ); // establecer dirección y estructura
      //glDrawElements( GL_QUADS,  4, GL_UNSIGNED_INT, &caras_cajaenglobante[0] );

      glVertexPointer( 3, GL_FLOAT, 0, &ver[0] ); // establecer dirección y estructura
      // visualizar recorriendo los vértices en el orden de los índices:
      glDrawElements( GL_TRIANGLES, num_tri*3, GL_UNSIGNED_INT, &tri[0] );
      glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
    }

    else if (cv.modoVisu == modoSolido){
      glDisable(GL_LIGHTING);
      glDisable(GL_TEXTURE_2D);
      //cout << "Modo Solido" << endl;
      //visualizarCaja();
      glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vértices
      glVertexPointer( 3, GL_FLOAT, 0, &ver[0] ); // establecer dirección y estructura
      // visualizar recorriendo los vértices en el orden de los índices:
      glDrawElements( GL_TRIANGLES, num_tri*3, GL_UNSIGNED_INT, &tri[0] );
      glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
    }

    else if (cv.modoVisu == modoAjedrez){
      //visualizarCarasNormales();
      glDisable(GL_LIGHTING);
      glDisable(GL_TEXTURE_2D);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3, GL_FLOAT, 0, &ver[0]);
      std::vector<Tupla3i> unos, otros;

      for (int i = 0; i < num_tri; i++){
        if (i%2 == 0)
          unos.push_back(tri[i]);
        else
          otros.push_back(tri[i]);
      }

      glShadeModel(GL_FLAT);
    	glColor3f(1,1,0);
    	glDrawElements(GL_TRIANGLES, 3 * unos.size(), GL_UNSIGNED_INT, unos.data());

    	glColor3f(0,1,1);
    	glDrawElements(GL_TRIANGLES, 3 * otros.size(), GL_UNSIGNED_INT, otros.data());
      glDisableClientState(GL_VERTEX_ARRAY);
    }

    else if (cv.modoVisu == modoPlano){
      glDisable(GL_LIGHTING);
      glDisable(GL_TEXTURE_2D);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3, GL_FLOAT, 0, &ver[0]);
      glShadeModel(GL_FLAT);

      if (cv.numero == 0)
        glColor3f(1,1,0);
      else if (cv.numero == 1)
        glColor3f(0,0,1);
      else if (cv.numero == 2)
        glColor3f(1,0,0);
      else if (cv.numero == 3)
        glColor3f(0.5,0.5,0.5);
      else if (cv.numero == 4)
        glColor3f(1,0,1);
      else if (cv.numero == 5)
        glColor3f(0,0,0);

      glDrawElements(GL_TRIANGLES, 3 * num_tri, GL_UNSIGNED_INT, tri.data());
      glDisableClientState( GL_VERTEX_ARRAY ); // deshabilitar array
    }

    else if (cv.modoVisu == modoIluminacion){
      //cout << "Modo iluminacion" << endl;
      if(tabla_textura.size() != 0){
        glTexCoordPointer(2, GL_FLOAT, 0, tabla_textura.data());
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      }
      if(caras_normales.size() != 0){
        glNormalPointer(GL_FLOAT, 0, caras_normales.data());
        glEnableClientState(GL_NORMAL_ARRAY);
      }
      glVertexPointer(3, GL_FLOAT, 0, ver.data());
      glEnableClientState(GL_VERTEX_ARRAY);
      glShadeModel(GL_FLAT);
      glDrawElements(GL_TRIANGLES, num_tri*3, GL_UNSIGNED_INT, &tri[0] );
      glDisableClientState(GL_TEXTURE_COORD_ARRAY);
      glDisableClientState(GL_NORMAL_ARRAY);
      glDisableClientState(GL_VERTEX_ARRAY);
    }

    else if (cv.modoVisu == modoSuave){
      //cout << "Modo Suave" << endl;
      if(tabla_textura.size() != 0){
        for(int i=0; i<tabla_textura.size(); i++){
          //cout << tabla_textura[i](0) << " " << tabla_textura[i](1) << endl;
        }
        glTexCoordPointer(2, GL_FLOAT, 0, tabla_textura.data());
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      }
      if(vertices_normales.size() != 0){
        glNormalPointer(GL_FLOAT, 0, vertices_normales.data()); // Aqui ponia caras
        glEnableClientState(GL_NORMAL_ARRAY);
      }
      glVertexPointer(3, GL_FLOAT, 0, ver.data());

      //visualizarCarasNormales();
      glEnableClientState(GL_VERTEX_ARRAY);
      glShadeModel(GL_SMOOTH);
      glDrawElements( GL_TRIANGLES, num_tri*3, GL_UNSIGNED_INT, &tri[0] );

      glDisableClientState(GL_TEXTURE_COORD_ARRAY);
      glDisableClientState(GL_NORMAL_ARRAY);
      glDisableClientState(GL_VERTEX_ARRAY);
    }
}

void MallaInd::obtenerNormalesCaras(){
  int bar = 0;
	for(int i = 0; i < tri.size(); i++){
		Tupla3f a, b, m1, m2;
		a = ver[tri[i](1)]-ver[tri[i](0)];
		b = ver[tri[i](2)]-ver[tri[i](0)];

		// producto vectorial de a y b
    m1 = a.cross(b);
		m2 = b.cross(a);

		if(m1(0) != 0 && m1(1) != 0 && m1(2) != 0)
			m1 = m1.normalized();
		if(m2(0) != 0 && m2(1) != 0 && m2(2) != 0)
			m2 = m2.normalized();

		if(normaR3(baricentros[bar]+m2) >= normaR3(baricentros[bar]+m1))
			caras_normales.push_back(m2);
		else
			caras_normales.push_back(m1);
		bar++;
	}
}

void MallaInd::obtenerNormalesVertices(){
	for(int i = 0; i < ver.size(); i++){
		Tupla3f m(0,0,0);
		for(int j = 0; j < tri.size(); j++){
			if(tri[j](0) == i || tri[j](1) == i || tri[j](2) == i)
				m = m + caras_normales[j];
		}

		if(m(0) != 0 && m(1) != 0 && m(2) != 0)
			m = m.normalized();
		vertices_normales.push_back(m);
	}
}

void MallaInd::calcularNormales(){
  Baricentros();
	obtenerNormalesCaras();
	obtenerNormalesVertices();
  //std::cout << baricentros.size() << "   " << tri.size() << "   " << caras_normales.size() << std::endl;
}

void MallaInd::Baricentros(){
  for(int i = 0; i < tri.size(); i++){
		Tupla3f aux(ver[tri[i](0)](0) + ver[tri[i](1)](0) + ver[tri[i](2)](0), ver[tri[i](0)](1) + ver[tri[i](1)](1) + ver[tri[i](2)](1), ver[tri[i](0)](2) + ver[tri[i](1)](2) + ver[tri[i](2)](2));
		aux = Tupla3f(aux(0)/3.0, aux(1)/3.0, aux(2)/3.0);
		baricentros.push_back(aux);
	}
}

void MallaInd::visualizarCarasNormales(){
	if(caras_normales.size() != 0){
		for(int i = 0; i < caras_normales.size(); i++){
			glColor3f(0,0,0);
			glBegin(GL_LINE_STRIP);
				glVertex3f(baricentros[i](0) + caras_normales[i](0), baricentros[i](1) + caras_normales[i](1), baricentros[i](2) + caras_normales[i](2));
				glVertex3f(baricentros[i](0), baricentros[i](1), baricentros[i](2));
			glEnd();
		}
	}
}
