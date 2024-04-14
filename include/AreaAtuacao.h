#pragma once
#include <string>
#include <ArduinoJson.h>

using namespace std;

class AreaAtuacao
{
    private:
        string areaID;
        int sensorTemperatura;
        int sensorGasesToxicos;
        int sensorFumaca;
        string releAtuador;
        string avisoAlerta;
        bool temFumaca;


    public:
        AreaAtuacao(bool temFumaca, string areaID);
        ~AreaAtuacao();
        string getAreaID();
        int getSensorTemperatura();
        int getSensorGasesToxicos();
        int getSensorFumaca();
        string getReleAtuador();
        string getAvisoAlerta();
        bool getTemFumaca();
        void atualizaSensores();

        JsonObject  toJsonSensores(JsonObject& json);     
        JsonObject  toJsonAtuadores(JsonObject& json);
        JsonObject  toJsonAlertas(JsonObject& json);

};