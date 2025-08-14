# MentorBit-SGP30

Esta librería está diseñada para que puedas **medir la calidad del aire interior (IAQ)** con gran facilidad, utilizando tu placa MentorBit y el módulo de sensor de gases SGP30.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit de Acelerómetro.](https://github.com/DigitalCodesign/MentorBit-SGP30/blob/main/assets/sgp30_module.png)

Con esta librería, tus proyectos podrán "respirar" y analizar el ambiente, monitorizando compuestos orgánicos volátiles y niveles equivalentes de CO₂, para crear entornos más saludables e inteligentes.

---

## Descripción

### ¿Qué es un sensor SGP30?

El **SGP30** es un sensor digital de gases de óxido de metal (MOX) diseñado específicamente para medir la calidad del aire en interiores. Es capaz de detectar una amplia gama de Compuestos Orgánicos Volátiles Totales (TVOC) y de proporcionar una lectura de Dióxido de Carbono equivalente (eCO₂).

Los TVOC son emitidos por pinturas, disolventes, muebles, productos de limpieza e incluso por las personas. El eCO₂ se calcula a partir de la concentración de hidrógeno y suele estar correlacionado con la presencia de personas en una habitación, sirviendo como un indicador clave para la ventilación.

---

### ¿Qué hace esta librería?

La librería **MentorBit-SGP30** facilita al máximo la obtención de datos del sensor. Abstrae la comunicación I2C y los comandos necesarios, permitiéndote obtener los valores de TVOC y eCO₂ con funciones muy sencillas.

Está adaptada para que su uso con MentorBit sea lo más sencillo posible.

---

### ¿Qué puedes construir con este módulo?

- Un monitor de calidad del aire para tu hogar, aula u oficina.
- Un sistema de ventilación inteligente que active un ventilador cuando los niveles de eCO₂ o TVOC sean altos.
- Un dispositivo portátil que te avise cuándo es necesario ventilar una estancia.
- Proyectos de registro de datos (datalogging) para estudiar cómo varía la calidad del aire a lo largo del día.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo SGP30 al puerto marcado como I2C en la sección de comunicaciones de la placa MentorBit.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-SGP30*** y haz clic en "Instalar".
- El IDE también instalará las dependencias necesarias automáticamente.

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-SGP30/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Medir la Calidad del Aire

Este ejemplo inicializa el sensor y luego toma una medida de la calidad del aire cada segundo, mostrando los resultados en el monitor serie.

```cpp
#include <MentorBitSGP30.h>

// Creamos el objeto para nuestro sensor de calidad de aire
MentorBit_SGP30 miSGP30;

// Variables para el temporizador (para medir cada segundo sin usar delay)
unsigned long tiempoAnterior = 0;

void setup() {
    // Inicializamos el monitor serial
    Serial.begin(9600);
    while (!Serial); // Espera a que se abra la consola serie

    // Inicializamos el sensor
    if (!miSGP30.begin()) {
        Serial.println("No se pudo encontrar el sensor SGP30. Revisa las conexiones.");
        while (1);
    }
    Serial.println("Sensor SGP30 encontrado. Calentando...");
}

void loop() {
    // El sensor debe ser leído cada segundo para mantener el algoritmo de calibración
    if (millis() - tiempoAnterior >= 1000) {
        tiempoAnterior = millis();

        // Realizamos una nueva medida
        if (miSGP30.tomarMedidas()) {
            // Nota: Durante los primeros 15 segundos, el sensor devuelve valores fijos (400 ppm eCO2, 0 ppb TVOC) mientras se calibra.
            Serial.print("eCO2: ");
            Serial.print(miSGP30.obtenerECO2());
            Serial.print(" ppm\t");

            Serial.print("TVOC: ");
            Serial.print(miSGP30.obtenerTVOC());
            Serial.println(" ppb");
        } else {
            Serial.println("Error al tomar la medida.");
        }
    }
}
```

---

## Funciones Principales

- `bool begin()`  
  Inicializa el SGP30 y la comunicación I2C. Devuelve <code>true</code> si la inicialización fue exitosa.

- `bool tomarMedidas()`  
  Realiza una nueva lectura de calidad del aire. Debes llamar a esta función cada vez que quieras tomar medidas para que el algoritmo interno del sensor se accione correctamente. Devuelve <code>true</code> si la lectura fue exitosa.

- `uint16_t obtenerTVOC()`  
  Devuelve la última medición de Compuestos Orgánicos Volátiles Totales en partes por billón (ppb). Solo es válido después de llamar a <code>tomarMedidas()</code>.

- `uint16_t obtenerECO2()`  
  Devuelve la última medición de CO₂ equivalente en partes por millón (ppm). Solo es válido después de llamar a <code>tomarMedidas()</code>.

- `uint16_t obtenerH2Crudo()`  
  Devuelve la señal cruda del sensor de Hidrógeno. Útil para aplicaciones avanzadas.

- `uint16_t obtenerEthanolCrudo()`  
  Devuelve la señal cruda del sensor de Etanol. Útil para aplicaciones avanzadas.

- `String obtenerNumeroSerie()`  
  Devuelve el número de serie único del chip del sensor, útil para identificarlo.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo SGP30](https://canarias.digitalcodesign.com/shop/00040046-mentorbit-modulo-sgp30-voc-y-co2-8737)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1CMxJcYyoOhm92eKtMRbG50kB-iZnNlFj/view?usp=drive_link)
- [Modelo 3D del Módulo SGP30 en formato .STEP](https://drive.google.com/file/d/1hPR1DQnDz0C0WbgP9TxohKLjiJZZvktD/view?usp=drive_link)
