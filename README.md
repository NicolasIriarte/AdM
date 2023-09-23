# Preguntas orientadoras

## Describa brevemente los diferentes perfiles de familias de microprocesadores/microcontroladores de ARM. Explique alguna de sus diferencias características
A lo largo de los años, ARM ha desarrollado varias familias de microprocesadores y microcontroladores con diferentes perfiles para adaptarse a diversas aplicaciones:
- **Cortex-A**: Son procesadores que están diseñados para aplicaciones de alto rendimiento, como smartphones, tabletas y sistemas embebidos avanzados. Ofrecen un rendimiento excepcional, soporte para sistemas operativos completos como Linux y Windows, y generalmente cuentan con múltiples núcleos para el procesamiento paralelo.
- **Cortex-R**: Se enfocan en aplicaciones de tiempo real y sistemas críticos, como controladores de automóviles, controladores de vuelo y sistemas de comunicación. Ofrecen tiempos de respuesta predecibles y alta confiabilidad. Suelen utilizarse en sistemas que requieren alta velocidad y seguridad.
- **Cortex-M**: Diseñados para sistemas embebidos de bajo consumo de energía y con restricciones de recursos, como microcontroladores en dispositivos IoT, sistemas de control industrial y productos de consumo. Son altamente eficientes en términos de consumo de energía y recursos. Se centran en tiempo real y eficiencia energética.

# Cortex M

## Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4

Las familias de procesadores M0, M3 y M4 son parte de la serie Cortex-M de ARM, diseñadas específicamente para aplicaciones embebidas de bajo consumo de energía.

**Arquitectura ARM**:
- **Cortex-M0:** Utiliza la arquitectura ARMv6-M, que es una arquitectura de 32 bits de Von Neumann.
- **Cortex-M3 y Cortex-M4:** Emplea la arquitectura ARMv7-M, que es una arquitectura de 32 bits de Harvard con un conjunto de instrucciones más amplio.

**Arquitectura de Memoria**:
- **Cortex-M0:** Utiliza una arquitectura de memoria unificada (Von Neumann), donde se comparte una única memoria para instrucciones y datos.
- **Cortex-M3 y Cortex-M4:** Utilizan arquitecturas de memoria separada (Harvard), con memorias separadas para instrucciones y datos, lo que permite un acceso más rápido a ambas.

**Systick Timer**:
- **Cortex-M0:** Tiene soporte para el temporizador Systick, que se utiliza para generar interrupciones periódicas y para medir el tiempo.
- **Cortex-M3 y Cortex-M4:** Contienen el temporizador Systick ya incluidos.

**División por Hardware**:
- **Cortex-M0:** Generalmente, no incluye instrucciones de división por hardware, lo que significa que las operaciones de división son emuladas por software.
- **Cortex-M3 y Cortex-M4:** Suelen incluir instrucciones de división por hardware, lo que permite realizar operaciones de división de manera más eficiente.

**Extensiones DSP**:
- **Cortex-M0:** No incluye extensiones DSP (Procesamiento de Señales Digitales) en su arquitectura.
- **Cortex-M3:** Por lo general, no incluye extensiones DSP en su arquitectura estándar, pero algunas implementaciones pueden incluir extensiones personalizadas para operaciones DSP.
- **Cortex-M4:** Incluye extensiones DSP en su arquitectura, lo que lo hace ideal para aplicaciones de procesamiento de señales y matemáticas complejas, como filtros y transformadas.

