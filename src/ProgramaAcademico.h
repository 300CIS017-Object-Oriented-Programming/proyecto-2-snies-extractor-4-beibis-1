#ifndef PROGRAMA_ACADEMICO_H
#define PROGRAMA_ACADEMICO_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Consolidado.h"
#include "Settings.h"

using namespace std;
class ProgramaAcademico
{
    int codigoDeLaInstitucion;
    int iesPadre;
    string institucionDeEducacionSuperiorIes;
    string principalOSeccional;
    int idSectorIes;
    string sectorIes;
    int idCaracter;
    string caracterIes;
    int codigoDelDepartamentoIes;
    string departamentoDeDomicilioDeLaIes;
    int codigoDelMunicipioIes;
    string municipioDeDomicilioDeLaIes;
    int codigoSniesDelPrograma;
    string programaAcademico;
    int idNivelAcademico;
    string nivelAcademico;
    int idNivelDeFormacion;
    string nivelDeFormacion;
    int idMetodologia;
    string metodologia;
    int idArea;
    string areaDeConocimiento;
    int idNucleo;
    string nucleoBasicoDelConocimientoNbc;
    int idCineCampoAmplio;
    string descCineCampoAmplio;
    int idCineCampoEspecifico;
    string descCineCampoEspecifico;
    int idCineCodigoDetallado;
    string descCineCodigoDetallado;
    int codigoDelDepartamentoPrograma;
    string departamentoDeOfertaDelPrograma;
    int codigoDelMunicipioPrograma;
    string municipioDeOfertaDelPrograma;
    vector<Consolidado *> consolidados;
    
    

  
    





public:
    ProgramaAcademico();

    void setCodigoDeLaInstitucion(int);
    int getCodigoDeLaInstitucion() const;

    void setIesPadre(int);
    int getIesPadre() const;

    void setInstitucionDeEducacionSuperiorIes(string &);
    string getInstitucionDeEducacionSuperiorIes() const;

    void setPrincipalOSeccional(string &);
    string getPrincipalOSeccional() const;

    void setIdSectorIes(int);
    int getIdSectorIes() const;

    void setSectorIes(string &);
    string getSectorIes() const;

    void setIdCaracter(int);
    int getIdCaracter() const;

    void setCaracterIes(string &);
    string getCaracterIes() const;

    void setCodigoDelDepartamentoIes(int);
    int getCodigoDelDepartamentoIes() const;

    void setDepartamentoDeDomicilioDeLaIes(string &);
    string getDepartamentoDeDomicilioDeLaIes() const;

    void setCodigoDelMunicipioIes(int);
    int getCodigoDelMunicipioIes() const;

    void setMunicipioDeDomicilioDeLaIes(string &);
    string getMunicipioDeDomicilioDeLaIes() const;

    void setCodigoSniesDelPrograma(int);
    int getCodigoSniesDelPrograma() const;

    void setProgramaAcademico(string &);
    string getProgramaAcademico() const;

    void setIdNivelAcademico(int);
    int getIdNivelAcademico() const;

    void setNivelAcademico(string &);
    string getNivelAcademico() const;

    void setIdNivelDeFormacion(int);
    int getIdNivelDeFormacion() const;

    void setNivelDeFormacion(string &);
    string getNivelDeFormacion() const;

    void setIdMetodologia(int);
    int getIdMetodologia() const;
    void setMetodologia(string &);
    string getMetodologia() const;

    void setIdArea(int);
    int getIdArea() const;
    void setAreaDeConocimiento(string &);
    string getAreaDeConocimiento() const;

    void setIdNucleo(int);
    int getIdNucleo() const;
    void setNucleoBasicoDelConocimientoNbc(string &);
    string getNucleoBasicoDelConocimientoNbc() const;

    void setIdCineCampoAmplio(int);
    int getIdCineCampoAmplio() const;
    void setDescCineCampoAmplio(string &);
    string getDescCineCampoAmplio() const;

    void setIdCineCampoEspecifico(int);
    int getIdCineCampoEspecifico() const;
    void setDescCineCampoEspecifico(string &);
    string getDescCineCampoEspecifico() const;

    void setIdCineCodigoDetallado(int);
    int getIdCineCodigoDetallado() const;
    void setDescCineCodigoDetallado(string &);
    string getDescCineCodigoDetallado() const;

    void setCodigoDelDepartamentoPrograma(int);
    int getCodigoDelDepartamentoPrograma() const;
    void setDepartamentoDeOfertaDelPrograma(string &);
    string getDepartamentoDeOfertaDelPrograma() const;

    void setCodigoDelMunicipioPrograma(int);
    int getCodigoDelMunicipioPrograma() const;
    void setMunicipioDeOfertaDelPrograma(string &);
    string getMunicipioDeOfertaDelPrograma() const;

    void setConsolidado(Consolidado *, int);
    Consolidado *getConsolidado(int) const;

    ~ProgramaAcademico();

};

#endif