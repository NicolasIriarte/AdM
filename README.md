# Preguntas orientadoras

## 1 - Describa brevemente los diferentes perfiles de familias de microprocesadores/microcontroladores de ARM. Explique alguna de sus diferencias características
A lo largo de los años, ARM ha desarrollado varias familias de microprocesadores y microcontroladores con diferentes perfiles para adaptarse a diversas aplicaciones:
- **Cortex-A**: Son procesadores que están diseñados para aplicaciones de alto rendimiento, como smartphones, tabletas y sistemas embebidos avanzados. Ofrecen un rendimiento excepcional, soporte para sistemas operativos completos como Linux y Windows, y generalmente cuentan con múltiples núcleos para el procesamiento paralelo.
- **Cortex-R**: Se enfocan en aplicaciones de tiempo real y sistemas críticos, como controladores de automóviles, controladores de vuelo y sistemas de comunicación. Ofrecen tiempos de respuesta predecibles y alta confiabilidad. Suelen utilizarse en sistemas que requieren alta velocidad y seguridad.
- **Cortex-M**: Diseñados para sistemas embebidos de bajo consumo de energía y con restricciones de recursos, como microcontroladores en dispositivos IoT, sistemas de control industrial y productos de consumo. Son altamente eficientes en términos de consumo de energía y recursos. Se centran en tiempo real y eficiencia energética.

# Cortex M

## 1 - Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4

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

## 2 - ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código?
Se dice que el conjunto de instrucciones Thumb permite una mayor densidad de código por varias razones:
1. Longitud de las instrucciones: En Thumb, las instrucciones son generalmente más cortas que en el conjunto de instrucciones ARM completo. Las instrucciones Thumb suelen ser de 16 bits de longitud, mientras que las instrucciones ARM pueden ser de 32 bits. Esto significa que se necesita menos espacio de memoria para almacenar el mismo programa en Thumb en comparación con ARM.
2. Menos ciclos de reloj por instrucción: Las instrucciones Thumb a menudo requieren menos ciclos de reloj para ejecutarse en comparación con sus contrapartes ARM.
3. Menor consumo de memoria: Debido a que las instrucciones Thumb son más cortas, ocupan menos espacio en la memoria, lo que es beneficioso para sistemas con limitaciones de memoria, como sistemas integrados y dispositivos móviles.
4. Reducción del tráfico de memoria: Con un código más compacto, hay menos necesidad de acceder a la memoria principal para buscar instrucciones, lo que puede reducir el consumo de energía y mejorar la eficiencia del sistema.

## 3 - ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?
La arquitectura load-store (carga-almacenamiento) es un diseño de arquitectura de computadora que se caracteriza por restringir las operaciones de acceso a la memoria principal (RAM) solo a un conjunto específico de instrucciones, llamadas instrucciones de carga (load) y almacenamiento (store). En una arquitectura load-store, las operaciones aritméticas y lógicas se realizan solo en registros del procesador, y no se pueden realizar directamente en la memoria.

## 4 - ¿Cómo es el mapa de memoria de la familia?

Al tratarse de una arquitectura de 32 bits, es posible direccionar $2^{32} - 1$ posiciones de memoria (4Gb). A continuación se presenta un grafico con el mapa de memeria:


![Mapa de memoria](./assets/memory-map.jpg)

## 5 - ¿Qué ventajas presenta el uso de los "shadowed pointers" del PSP y el MSP?

- PSP (Process Stack Pointer): El PSP es un puntero de pila que se utiliza para gestionar la pila de una tarea específica en un sistema multitarea en tiempo real. Cada tarea tiene su propio PSP para mantener su contexto de ejecución.

- MSP (Main Stack Pointer): El MSP es otro puntero de pila que se utiliza para gestionar la pila principal del sistema. Se utiliza principalmente para manejar interrupciones y cambios de contexto entre tareas. El MSP es manejado por el sistema operativo.

Los shadowed pointers permiten:

1. Cambio rápido de contexto: Los *shadowed pointers* permiten un cambio rápido y eficiente entre el stack de usuario y la pila principal. Esto es esencial en sistemas multitarea en tiempo real donde es necesario cambiar rápidamente de una tarea a otra.
2. Soporte para interrupciones: En sistemas embebidos, es común manejar interrupciones. Los *shadowed pointers* facilitan la transición de una tarea a una rutina de interrupción y viceversa, garantizando que el contexto de la tarea original se restaure después de que se maneje la interrupción.

## 6 - Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado.

Cortex-M de ARM utiliza un modelo de seguridad y protección de recursos basado en modos de privilegio y operación para garantizar la ejecución segura y eficiente de tareas en sistemas embebidos. Los modos de operación en Cortex-M incluyen:

1. Handler Mode (Modo de Manejador): Este modo se utiliza para manejar interrupciones y excepciones. Cuando ocurre una interrupción, el procesador cambia a Handler Mode para ejecutar el código de la rutina de manejo de interrupciones.
2. Privileged Mode (Modo con Privilegios): En este modo, el procesador tiene acceso completo a todas las instrucciones y registros, similar al Thread Mode. Sin embargo, el Privileged Mode se utiliza para ejecutar código con un nivel de privilegio superior, como el kernel de un sistema operativo en sistemas que lo requieran. Se puede acceder al Privileged Mode desde el Thread Mode o el Handler Mode.
3. Unprivileged Mode (Modo sin Privilegios): En este modo, el procesador tiene restricciones en el acceso a ciertos recursos y privilegios, lo que ayuda a implementar la separación entre aplicaciones y sistemas en tiempo real. El código se ejecuta en este modo cuando se asigna un nivel de privilegio inferior a una tarea o proceso. El Unprivileged Mode es una característica de seguridad que puede ayudar a evitar que un código malicioso acceda a recursos críticos.

![Privilegios](./assets/privileges.png)

La conmutación entre estos modos se logra mediante instrucciones de excepción, como las instrucciones `SVC` (*Supervisor Call*) para cambiar al Privileged Mode desde el Thread Mode o las interrupciones que cambian al Handler Mode cuando ocurre una interrupción. La conmutación también puede ser administrada por un sistema operativo en sistemas más avanzados.

Un ejemplo de cambio de privilegio se dá con el uso de sistemas operativos de tiempo real, los cuales corren su kernel en modo privilegiado para contralar todos los recursos del procesador, mientras que las tareas del usuarios se ejecutan en modo sin-privilegios.


## 7 - ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo

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

## 8 - ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo

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

## 9 - Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).

1. **Reset**: La excepción de reinicio (Reset) es la más prioritaria y se produce cuando el procesador se inicia o se reinicia. Esta excepción es invocada al encender o reiniciar el sistema y establece el estado inicial del procesador y la ejecución del programa comienza desde una dirección de memoria específica, generalmente la dirección de inicio del programa (vector de reinicio).

2. **NMI (Non-Maskable Interrupt)**: La excepción de interrupción no enmascarable es la segunda más prioritaria después del reinicio. Es una interrupción que no puede ser deshabilitada o enmascarada por el software y se utiliza para manejar eventos críticos que deben ser atendidos inmediatamente, como eventos de seguridad o fallos de hardware.

3. **Hard Fault**: La excepción de fallo grave (Hard Fault) es una excepción de alta prioridad que se genera cuando ocurre un error grave en la ejecución del programa, como una violación de acceso a memoria o una instrucción no válida. Puede ser causada por problemas de software o hardware. El Hard Fault es un mecanismo de seguridad que ayuda a proteger el sistema contra comportamientos inesperados.


## 10 - Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?

La pila cumple cuatro funciones principalmente:

1. **Almacenamiento temporal de datos**: La pila se utiliza para almacenar temporalmente datos, como valores de registros, direcciones de retorno y variables locales, durante la ejecución de una función o una rutina.

2. **Gestión de llamadas a funciones**: La pila se utiliza para administrar la secuencia de llamadas a funciones y el retorno de estas funciones. Cada vez que se llama a una función, su estado actual, como los registros y la dirección de retorno, se almacena en la pila para que la función pueda ejecutarse y, posteriormente, restaurar su estado cuando regresa.

3. **Almacenamiento de contexto de interrupciones**: La pila se utiliza para almacenar el contexto actual del procesador cuando ocurre una interrupción o una excepción. Esto permite que el procesador atienda la interrupción y, una vez completada, regrese al punto donde se interrumpió.

4. **Gestión de variables locales**: Las variables locales, que son específicas de una función, se almacenan en la pila para que estén disponibles durante la ejecución de la función. Esto garantiza que cada instancia de la función tenga su propia área de almacenamiento para sus variables locales.


El proceso de llamado de funciones se puede dividir en tres grandes etapas:

1. **Llamada a función**: Cuando se llama a una función, se almacenan en la pila los valores de los registros que puedan ser modificados por la función llamada, así como la dirección de retorno, que es la dirección de la instrucción siguiente a la llamada a la función. Luego, se ajusta el puntero de pila (stack pointer) para reservar espacio para estos datos en la parte superior de la pila.
2. **Ejecución de la función**: La función se ejecuta utilizando los registros y los datos almacenados en la pila. Las variables locales de la función también se almacenan en la pila y se acceden desde allí durante la ejecución de la función.
3. **Retorno de función**: Cuando la función termina su ejecución, se restaura el estado original almacenado en la pila, incluyendo los valores de los registros y la dirección de retorno. puntero de pila se ajusta nuevamente para eliminar los datos de la función de la pila.

## 11 - Describa la secuencia de reset del microprocesador.

La secuencia de reset es una tarea compleja la cual está dividida en multiple etapas:

1. **Alimentación o reinicio del sistema**: El proceso de reset comienza cuando se aplica alimentación eléctrica al microprocesador (por ejemplo, al encender el dispositivo) o cuando se genera un reinicio del sistema.

2. **Inicialización del hardware**: En esta etapa, los circuitos internos del microprocesador se inicializan y configuran para un estado conocido y predecible. Esto puede incluir la configuración de relojes, registros internos, y otros componentes.

3. **Carga de vectores de reinicio**: Los microprocesadores Cortex-M utilizan una tabla de vectores de interrupción para determinar cómo se manejan las interrupciones y las excepciones, incluido el vector de reinicio. En esta etapa, se cargan los valores de los vectores de reinicio que apuntan a las direcciones iniciales de las rutinas de manejo de reinicio.

4. **Configuración de registros de pila**: Se establece el puntero de pila (Stack Pointer, SP) en una ubicación válida de memoria. El valor del SP puede provenir de una ubicación específica de memoria o estar predefinido en el hardware. La pila se utiliza para almacenar datos temporales y registros de contexto durante la ejecución del programa.

5. **Salto a la dirección de reinicio**: Una vez que todos los ajustes iniciales se han realizado y los vectores de reinicio están configurados, el microprocesador realiza un salto a la dirección de reinicio. La dirección de reinicio suele ser la primera entrada en la tabla de vectores de interrupción, que apunta a la rutina de manejo de reinicio.

6. **Ejecución de la rutina de manejo de reinicio**: La rutina de manejo de reinicio (Reset Handler) se encarga de inicializar variables, configurar periféricos y llevar a cabo tareas necesarias para poner el sistema en un estado coherente y prepararlo para la ejecución del programa principal.

7. **Llamada al programa principal**: Una vez que la rutina de manejo de reinicio ha realizado todas las tareas necesarias, puede llamar al programa principal (main) o a la aplicación principal del dispositivo.
