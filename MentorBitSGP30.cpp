/*

            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Enero de 2024
    Fecha de version: Enero de 2024
    Repositorio: https://github.com/DigitalCodesign/MentorBit-SGP30
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit SGP30
    Metodos principales:
        MentorBitSGP30 -> constructor de la clase
        begin -> inicializador, debe colocarse en el setup
        leerTVOC -> lee el valor de TVOC del sensor
        leerECO2 -> lee el valor de eCO2 del sensor
        leerRawH2 -> lee el valor crudo de Hidrógeno del sensor
        leerRawEthanol -> lee el valor crudo de Etanol del sensor
        obtenerSerialNumber -> lee el número de serie del sensor

*/

#include "MentorBitSGP30.h"

MentorBit_SGP30::MentorBit_SGP30(){

}

bool MentorBit_SGP30::begin(){

    _i2c_addr = 0x58;
    if(sgp.begin(_i2c_addr)) return true;
    else return false;

}

bool MentorBit_SGP30::tomarMedidas(){

    return sgp.IAQmeasure() && sgp.IAQmeasureRaw();

}

uint16_t MentorBit_SGP30::obtenerTVOC(){

    return sgp.TVOC;

}

uint16_t MentorBit_SGP30::obtenerECO2(){

    return sgp.eCO2;

}

uint16_t MentorBit_SGP30::obtenerH2Crudo(){

    return sgp.rawH2;

}

uint16_t MentorBit_SGP30::obtenerEthanolCrudo(){

    return sgp.rawEthanol;

}

String MentorBit_SGP30::obtenerNumeroSerie(){

    return String(sgp.serialnumber[0]) + String(sgp.serialnumber[1]) + String(sgp.serialnumber[2]);

}
