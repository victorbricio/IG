#include "MallaRevol.hpp"
#include <cmath>
#include <cstring>
#include "matrizg.hpp"

MallaRevol::MallaRevol(const std::string & nombre_arch, unsigned int nperfiles,
  bool crear_tapas, bool cerrar_malla){
      std::vector<float> aux;
      char* aux2 = new char[nombre_arch.length() + 1];
      std::strcpy(aux2, nombre_arch.c_str());

      ply::read_vertices(aux2, aux);

      for (int i = 0; i < aux.size(); i = i + 3)
        ver.push_back(Tupla3f(aux[i], aux[i + 1], aux[i + 2]));

      num_ver = ver.size();

      double angulo = 2 * 3.141592653 / nperfiles;
      bool entrado = false;

      for (int i = 0; i < nperfiles; i++){
        if (!cerrar_malla && i == nperfiles - 1){
          for (int j = 0; j < num_ver - 1; j++){
            tri.push_back(Tupla3i(j, j + 1, i * num_ver + j + 1));
            tri.push_back(Tupla3i(j, i * num_ver + j, i * num_ver + j + 1));
            entrado = true;
          }
        }
        if (!entrado){
          for (int j = 0; j < num_ver; j++){
            ver.push_back(Tupla3f(cos(angulo) * ver[j + i * num_ver](0) + sin(angulo) * ver[j + i * num_ver](2),
                                  ver[j + i * num_ver](1),
                                  -sin(angulo) * ver[j+ i * num_ver](0) + cos(angulo) * ver[j + i * num_ver](2)));
            if (j != 0){
              tri.push_back(Tupla3i((i + 1) * num_ver + j - 1, (i + 1) * num_ver + j, i * num_ver + j));
              tri.push_back(Tupla3i((i + 1) * num_ver + j - 1, i * num_ver + j - 1, i * num_ver + j));
            }
          }
        }
      }

      if (crear_tapas){
          ver.push_back(Tupla3f(0, ver[num_ver - 1](1), 0));
          ver.push_back(Tupla3f(0, ver[0](1), 0));

          for (int i = 0; i < nperfiles; i++){
            if (i == nperfiles - 1)
              tri.push_back(Tupla3i(num_ver * i, 0, ver.size() - 1));
            else
              tri.push_back(Tupla3i(num_ver * i, num_ver * (i + 1), ver.size() - 1));
          }
          for (int i = 0; i < nperfiles; i++){
            if (i == nperfiles - 1)
              tri.push_back(Tupla3i(num_ver * (i + 1) - 1, num_ver - 1, ver.size() - 2));
            else
              tri.push_back(Tupla3i(num_ver * (i + 1) - 1, num_ver * (i + 2) - 1, ver.size() - 2));
          }
      }

      num_ver = ver.size();
      num_tri = tri.size();
}

MallaRevol::MallaRevol(const std::string & nombre_arch, unsigned int nperfiles,
  bool crear_tapas, bool cerrar_malla, bool texturas){
      std::vector<float> aux;
      char* aux2 = new char[nombre_arch.length() + 1];
      std::strcpy(aux2, nombre_arch.c_str());

      ply::read_vertices(aux2, aux);

      for (int i = 0; i < aux.size(); i = i + 3)
        ver.push_back(Tupla3f(aux[i], aux[i + 1], aux[i + 2]));

      num_ver = ver.size();

      double angulo = 2 * 3.141592653 / nperfiles;
      bool entrado = false;

      for (int i = 0; i < nperfiles; i++){
        if (!cerrar_malla && i == nperfiles - 1){
          for (int j = 0; j < num_ver - 1; j++){
            tri.push_back(Tupla3i(j, j + 1, i * num_ver + j + 1));
            tri.push_back(Tupla3i(j, i * num_ver + j, i * num_ver + j + 1));
            entrado = true;
          }
        }
        if (!entrado){
          for (int j = 0; j < num_ver; j++){
            ver.push_back(Tupla3f(cos(angulo) * ver[j + i * num_ver](0) + sin(angulo) * ver[j + i * num_ver](2),
                                  ver[j + i * num_ver](1),
                                  -sin(angulo) * ver[j+ i * num_ver](0) + cos(angulo) * ver[j + i * num_ver](2)));
            if (j != 0){
              tri.push_back(Tupla3i((i + 1) * num_ver + j - 1, (i + 1) * num_ver + j, i * num_ver + j));
              tri.push_back(Tupla3i((i + 1) * num_ver + j - 1, i * num_ver + j - 1, i * num_ver + j));
            }
          }
        }
      }

      if (crear_tapas){
          ver.push_back(Tupla3f(0, ver[num_ver - 1](1), 0));
          ver.push_back(Tupla3f(0, ver[0](1), 0));

          for (int i = 0; i < nperfiles; i++){
            if (i == nperfiles - 1)
              tri.push_back(Tupla3i(num_ver * i, 0, ver.size() - 1));
            else
              tri.push_back(Tupla3i(num_ver * i, num_ver * (i + 1), ver.size() - 1));
          }
          for (int i = 0; i < nperfiles; i++){
            if (i == nperfiles - 1)
              tri.push_back(Tupla3i(num_ver * (i + 1) - 1, num_ver - 1, ver.size() - 2));
            else
              tri.push_back(Tupla3i(num_ver * (i + 1) - 1, num_ver * (i + 2) - 1, ver.size() - 2));
          }
      }

    float s;
    float t;
    vector<float> d;
    d.push_back(0);
    //cout << "distinta figura" << endl;
    //cout << "d " << d[0] << endl;
    for(int j = 1; j < num_ver; j++){
      d.push_back(d[j-1] + abs(ver[j](1) - ver[j-1](1)));
      //cout << "d " << d[j] << endl;
    }

    for(float i = 0; i < nperfiles; i++){
      s = i / (nperfiles - 1);
      //cout << "s " << s << endl;
      for(int j = 0; j < num_ver; j++){
        t = 1.0 - d[j]/d[num_ver - 1];
        //cout <<j<< " t " << t << endl;
        Tupla2f aux(s,t);
        tabla_textura.push_back(aux);
      }

    }

    num_ver = ver.size();
    num_tri = tri.size();
}
