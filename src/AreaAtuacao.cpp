#include "AreaAtuacao.h"


AreaAtuacao::AreaAtuacao(bool temFumaca, string areaID)
{
    this->areaID = areaID;
    this->sensorTemperatura = (temFumaca) ? getSensorTemperatura() : NULL;
    this->sensorGasesToxicos = (temFumaca) ? getSensorGasesToxicos() : NULL;
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
    return this->sensorTemperatura = (!this->temFumaca) ? (rand() % 100) + 1 : NULL; 
}

int AreaAtuacao::getSensorGasesToxicos()
{
    return this->sensorGasesToxicos = (!this->temFumaca) ? (rand() % 100) + 1 : NULL;
}


int AreaAtuacao::getSensorFumaca()
{
    return this->sensorFumaca = (this->temFumaca) ? (rand() % 100) + 1 : NULL;
}

string AreaAtuacao::getReleAtuador()
{
    return this->releAtuador = (rand() % 2) == 0 ? "Ligar Rele" : "Desligar Rele";
}

string AreaAtuacao::getAvisoAlerta()
{
    return this->avisoAlerta = (rand() % 2) == 0 ? "Limite Ultrapassado" : "Operacao Normal";
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