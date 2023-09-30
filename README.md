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

## ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código?
Se dice que el conjunto de instrucciones Thumb permite una mayor densidad de código por varias razones:
1. Longitud de las instrucciones: En Thumb, las instrucciones son generalmente más cortas que en el conjunto de instrucciones ARM completo. Las instrucciones Thumb suelen ser de 16 bits de longitud, mientras que las instrucciones ARM pueden ser de 32 bits. Esto significa que se necesita menos espacio de memoria para almacenar el mismo programa en Thumb en comparación con ARM.
2. Menos ciclos de reloj por instrucción: Las instrucciones Thumb a menudo requieren menos ciclos de reloj para ejecutarse en comparación con sus contrapartes ARM.
3. Menor consumo de memoria: Debido a que las instrucciones Thumb son más cortas, ocupan menos espacio en la memoria, lo que es beneficioso para sistemas con limitaciones de memoria, como sistemas integrados y dispositivos móviles.
4. Reducción del tráfico de memoria: Con un código más compacto, hay menos necesidad de acceder a la memoria principal para buscar instrucciones, lo que puede reducir el consumo de energía y mejorar la eficiencia del sistema.

## ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?
La arquitectura load-store (carga-almacenamiento) es un diseño de arquitectura de computadora que se caracteriza por restringir las operaciones de acceso a la memoria principal (RAM) solo a un conjunto específico de instrucciones, llamadas instrucciones de carga (load) y almacenamiento (store). En una arquitectura load-store, las operaciones aritméticas y lógicas se realizan solo en registros del procesador, y no se pueden realizar directamente en la memoria.

## ¿Cómo es el mapa de memoria de la familia?

Al tratarse de una arquitectura de 32 bits, es posible direccionar $2^{32} - 1$ posiciones de memoria (4Gb). A continuación se presenta un grafico con el mapa de memeria:


![Mapa de memoria](./assets/memory-map.jpg)

## ¿Qué ventajas presenta el uso de los "shadowed pointers" del PSP y el MSP?

- PSP (Process Stack Pointer): El PSP es un puntero de pila que se utiliza para gestionar la pila de una tarea específica en un sistema multitarea en tiempo real. Cada tarea tiene su propio PSP para mantener su contexto de ejecución.

- MSP (Main Stack Pointer): El MSP es otro puntero de pila que se utiliza para gestionar la pila principal del sistema. Se utiliza principalmente para manejar interrupciones y cambios de contexto entre tareas. El MSP es manejado por el sistema operativo.

Los shadowed pointers permiten:

1. Cambio rápido de contexto: Los *shadowed pointers* permiten un cambio rápido y eficiente entre el stack de usuario y la pila principal. Esto es esencial en sistemas multitarea en tiempo real donde es necesario cambiar rápidamente de una tarea a otra.
2. Soporte para interrupciones: En sistemas embebidos, es común manejar interrupciones. Los *shadowed pointers* facilitan la transición de una tarea a una rutina de interrupción y viceversa, garantizando que el contexto de la tarea original se restaure después de que se maneje la interrupción.

## Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado.

Cortex-M de ARM utiliza un modelo de seguridad y protección de recursos basado en modos de privilegio y operación para garantizar la ejecución segura y eficiente de tareas en sistemas embebidos. Los modos de operación en Cortex-M incluyen:

1. Handler Mode (Modo de Manejador): Este modo se utiliza para manejar interrupciones y excepciones. Cuando ocurre una interrupción, el procesador cambia a Handler Mode para ejecutar el código de la rutina de manejo de interrupciones.
2. Privileged Mode (Modo con Privilegios): En este modo, el procesador tiene acceso completo a todas las instrucciones y registros, similar al Thread Mode. Sin embargo, el Privileged Mode se utiliza para ejecutar código con un nivel de privilegio superior, como el kernel de un sistema operativo en sistemas que lo requieran. Se puede acceder al Privileged Mode desde el Thread Mode o el Handler Mode.
3. Unprivileged Mode (Modo sin Privilegios): En este modo, el procesador tiene restricciones en el acceso a ciertos recursos y privilegios, lo que ayuda a implementar la separación entre aplicaciones y sistemas en tiempo real. El código se ejecuta en este modo cuando se asigna un nivel de privilegio inferior a una tarea o proceso. El Unprivileged Mode es una característica de seguridad que puede ayudar a evitar que un código malicioso acceda a recursos críticos.

![Privilegios](./assets/privileges.png)

La conmutación entre estos modos se logra mediante instrucciones de excepción, como las instrucciones `SVC` (*Supervisor Call*) para cambiar al Privileged Mode desde el Thread Mode o las interrupciones que cambian al Handler Mode cuando ocurre una interrupción. La conmutación también puede ser administrada por un sistema operativo en sistemas más avanzados.

Un ejemplo de cambio de privilegio se dá con el uso de sistemas operativos de tiempo real, los cuales corren su kernel en modo privilegiado para contralar todos los recursos del procesador, mientras que las tareas del usuarios se ejecutan en modo sin-privilegios.


## ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo

El término "modelo de registros ortogonal" se refiere a una característica de algunas arquitecturas de procesadores donde los registros generales están diseñados de manera que puedan ser utilizados de manera intercambiable en una amplia variedad de instrucciones sin restricciones específicas en su uso. En un modelo de registros ortogonal, los registros pueden ser operados y direccionados de manera uniforme, lo que simplifica la programación y permite una mayor flexibilidad en la ejecución de instrucciones.

Un ejemplo de registros ortogonales es cualquier arquitectura que posea registros de propósitos generales. (General-Purpose Registers) que se pueden utilizar para una amplia variedad de tareas.

```asm

; Ejemplo de manipulación de registros de propositos generales
; Supongamos que R0, R1 y R2 son registros generales disponibles

; Sumar R1 y R2 y almacenar el resultado en R0
ADD R0, R1, R2

; Multiplicar R2 por 5 y almacenar el resultado en R1
MOV R3, #5       ; Cargar el valor 5 en R3
MUL R1, R2, R3   ; Multiplicar R2 por R3 y almacenar el resultado en R1

; Comparar R0 con un valor inmediato y establecer una bandera
CMP R0, #10      ; Comparar R0 con el valor 10

```

## ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo

Las instrucciones de ejecución condicional (IT, por sus siglas en inglés, *If-Then*) son una característica que permiten ejecutar instrucciones condicionalmente. Esto permite:

1. Ahorro de espacio de código: Las instrucciones de ejecución condicional pueden reducir la cantidad de código necesaria para implementar lógica condicional en comparación con utilizar instrucciones de salto (branch) condicional. Esto puede llevar a un código más compacto y eficiente en términos de memoria.
2. Mejora del rendimiento: Al evitar saltos condicionales (branch), que pueden causar desviaciones en el flujo de ejecución y afectar negativamente el rendimiento de la canalización (pipeline) del procesador, las instrucciones de ejecución condicional pueden ayudar a mantener un flujo de ejecución más predecible y un rendimiento más consistente.
3. Programación más legible: Las instrucciones de ejecución condicional pueden hacer que el código sea más fácil de entender y mantener, ya que la lógica condicional se expresa de manera más directa y se alinea visualmente con la instrucción que se va a ejecutar.


```asm
; Ejemplo en lenguaje ensamblador Cortex-M con instrucciones IT
CMP  R0, #10      ; Compara el valor en R0 con 10
IT   GT           ; Si R0 es mayor que 10, las próximas instrucciones serán condicionales

ADD R1, R2, #2  ; Suma R2 y ${2} y almacena el resultado en R1 si R0 > 10
```

