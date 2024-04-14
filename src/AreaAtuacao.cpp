#include "AreaAtuacao.h"


AreaAtuacao::AreaAtuacao(bool temFumaca, string areaID)
{
    this->areaID = areaID;
    this->sensorTemperatura = getSensorTemperatura();
    this->sensorGasesToxicos = getSensorGasesToxicos();
    this->releAtuador = getReleAtuador();
    this->avisoAlerta = getAvisoAlerta();
    this->temFumaca = temFumaca;
    this->sensorFumaca = (temFumaca) ? getSensorFumaca() : NULL;

}

AreaAtuacao::~AreaAtuacao()
{
}

string AreaAtuacao::getAreaID()
{
    return this->areaID;
}

int AreaAtuacao::getSensorTemperatura()
{
    return this->sensorTemperatura = (rand() % 100) + 1;
}

int AreaAtuacao::getSensorGasesToxicos()
{
    return this->sensorGasesToxicos = (rand() % 100) + 1;
}


int AreaAtuacao::getSensorFumaca()
{
    return this->sensorFumaca = (rand() % 100) + 1; 
}

string AreaAtuacao::getReleAtuador()
{
    return this->releAtuador = (rand() % 2) == 0 ? "Ligar Rele" : "Desligar Rele";
}

string AreaAtuacao::getAvisoAlerta()
{
    return this->avisoAlerta = (rand() % 2) == 0 ? "Alerta" : "Sem Alerta";
}

bool AreaAtuacao::getTemFumaca()
{
    return this->temFumaca;
}

void AreaAtuacao::atualizaSensores()
{
    this->sensorTemperatura = getSensorTemperatura();
    this->sensorGasesToxicos = getSensorGasesToxicos();
    this->releAtuador = getReleAtuador();
    this->avisoAlerta = getAvisoAlerta();
    this->sensorFumaca = (temFumaca) ? getSensorFumaca() : NULL;
}



JsonObject  AreaAtuacao::toJsonSensores(JsonObject& json)
{   
    json["sensorTemperatura"] = this->sensorTemperatura;
    json["sensorGasesToxicos"] = this->sensorGasesToxicos;
    json["sensorFumaca"] = this->sensorFumaca;
    return json;
}

JsonObject  AreaAtuacao::toJsonAtuadores(JsonObject& json)
{
    json["releAtuador"] = this->releAtuador;
    return json;
}

JsonObject  AreaAtuacao::toJsonAlertas(JsonObject& json)
{
    json["avisoAlerta"] = this->avisoAlerta;
    return json;
}