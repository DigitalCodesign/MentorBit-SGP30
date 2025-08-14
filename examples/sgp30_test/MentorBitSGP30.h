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

#ifndef MentorBitSGP30_h
#define MentorBitSGP30_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SGP30.h>

    class MentorBit_SGP30
    {

        public:

            MentorBit_SGP30();
            bool begin();
            void tomarMedidas();
            uint16_t obtenerTVOC();
            uint16_t obtenerECO2();
            uint16_t obtenerH2Crudo();
            uint16_t obtenerEthanolCrudo();
            String obtenerNumeroSerie();

        private:

            uint8_t _i2c_addr;
            Adafruit_SGP30 sgp;

    };

#endif
