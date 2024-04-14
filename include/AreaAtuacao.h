#pragma once
#include <string>

using namespace std;

class AreaAtuacao
{
    private:
        int sensorTemperatura;
        int sensorGasesToxicos;
        int sensorFumaca;
        string releAtuador;
        string avisoAlerta;


    public:
        AreaAtuacao(int sensorTemperatura, int sensorGasesToxicos, string releAtuador, string avisoAlerta);
        ~AreaAtuacao();
        int getSensorTemperatura();
        int getSensorGasesToxicos();
        string getReleAtuador();
        string getAvisoAlerta();

        void setSensorTemperatura(int sensorTemperatura);
        void setSensorGasesToxicos(int sensorGasesToxicos);
        void setReleAtuador(string releAtuador);
        void setAvisoAlerta(string avisoAlerta);
        



};