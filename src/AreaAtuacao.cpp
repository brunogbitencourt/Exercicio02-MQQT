#include "AreaAtuacao.h"


AreaAtuacao::AreaAtuacao(int sensorTemperatura, int sensorGasesToxicos, string releAtuador, string avisoAlerta)
{
    this->sensorTemperatura = sensorTemperatura;
    this->sensorGasesToxicos = sensorGasesToxicos;
    this->releAtuador = releAtuador;
    this->avisoAlerta = avisoAlerta;
}

AreaAtuacao::~AreaAtuacao()
{
}


int AreaAtuacao::getSensorTemperatura()
{
    return this->sensorTemperatura;
}

int AreaAtuacao::getSensorGasesToxicos()
{
    return this->sensorGasesToxicos;
}

string AreaAtuacao::getReleAtuador()
{
    return this->releAtuador;
}

string AreaAtuacao::getAvisoAlerta()
{
    return this->avisoAlerta;
}

void AreaAtuacao::setSensorTemperatura(int sensorTemperatura)
{
    this->sensorTemperatura = sensorTemperatura;
}

void AreaAtuacao::setSensorGasesToxicos(int sensorGasesToxicos)
{
    this->sensorGasesToxicos = sensorGasesToxicos;
}

void AreaAtuacao::setReleAtuador(string releAtuador)
{
    this->releAtuador = releAtuador;
}

void AreaAtuacao::setAvisoAlerta(string avisoAlerta)
{
    this->avisoAlerta = avisoAlerta;
}
