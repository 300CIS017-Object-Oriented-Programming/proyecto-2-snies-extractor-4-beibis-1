#ifndef CONSOLIDADO_H
#define CONSOLIDADO_H

#include <string>
#include <vector>
#include <iostream>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


class Consolidado
{
private:
    int idSexo;
    string sexo;
    int ano;
    int semestre;
    int inscritos;
    int admitidos;
    int matriculados;
    int matriculadosPrimerSemestre;
    int graduados;

public:
    Consolidado();
    Consolidado(int, string, int, int, int, int, int, int, int);

    int getIdSexo() const;
    void setIdSexo(int);

    string getSexo() const;
    void setSexo(string &);

    int getAno() const;
    void setAno(int);

    int getSemestre() const;
    void setSemestre(int);

    int getInscritos() const;
    void setInscritos(int);

    int getAdmitidos() const;
    void setAdmitidos(int);

    int getMatriculados() const;
    void setMatriculados(int);

    int getMatriculadosPrimerSemestre() const;
    void setMatriculadosPrimerSemestre(int);

    int getGraduados() const;
    void setGraduados(int);

};

#endif // CONSOLIDADO_H
