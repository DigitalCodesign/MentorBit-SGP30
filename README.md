# MentorBitSGP30

Librería para la lectura de datos de calidad del aire utilizando el sensor SGP30 en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitSGP30` facilita la lectura de datos de calidad del aire, incluyendo TVOC (Compuestos Orgánicos Volátiles Totales) y eCO2 (dióxido de carbono equivalente), desde el sensor SGP30 en módulos compatibles con MentorBit. Permite obtener mediciones precisas para aplicaciones de monitoreo de la calidad del aire en interiores.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitSGP30" e instálala.
    * **Nota:** Esta librería depende de la librería `Adafruit_SGP30`. Asegúrate de que también esté instalada.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitSGP30.h>

    MentorBit_SGP30 sgp30;

    void setup() {
        Serial.begin(9600);
        if (!sgp30.begin()) {
            Serial.println("Sensor SGP30 no encontrado.");
            while (1);
        }
        Serial.println("Sensor SGP30 inicializado.");
    }

    void loop() {
        if (sgp30.tomarMedidas()) {
            Serial.print("TVOC: ");
            Serial.print(sgp30.obtenerTVOC());
            Serial.print(" ppb, eCO2: ");
            Serial.print(sgp30.obtenerECO2());
            Serial.println(" ppm");

            Serial.print("Raw H2: ");
            Serial.print(sgp30.obtenerH2Crudo());
            Serial.print(", Raw Ethanol: ");
            Serial.print(sgp30.obtenerEthanolCrudo());
            Serial.println();

            Serial.print("Numero de serie: ");
            Serial.println(sgp30.obtenerNumeroSerie());

        } else {
            Serial.println("Error al obtener las medidas.");
        }
        delay(1000);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBit_SGP30()`: Crea un objeto `MentorBit_SGP30`.

### Métodos

* `bool begin()`: Inicializa el sensor SGP30. Retorna `true` si la inicialización es exitosa, `false` en caso contrario.
* `bool tomarMedidas()`: Toma las medidas del sensor. Retorna `true` si las medidas se toman correctamente, `false` en caso contrario.
* `uint16_t obtenerTVOC()`: Obtiene el valor de TVOC en ppb (partes por billón).
* `uint16_t obtenerECO2()`: Obtiene el valor de eCO2 en ppm (partes por millón).
* `uint16_t obtenerH2Crudo()`: Obtiene el valor crudo de H2.
* `uint16_t obtenerEthanolCrudo()`: Obtiene el valor crudo de Ethanol.
* `String obtenerNumeroSerie()`: Obtiene el número de serie del sensor como una cadena de texto.
