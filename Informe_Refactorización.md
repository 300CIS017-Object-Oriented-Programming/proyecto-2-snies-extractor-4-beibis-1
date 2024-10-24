# `Informe de Refactorización Basado en SonarQube`

----------------------------
## Implementación de Manejo de Excepciones con `try`, `catch` y `throw`
------
Para mejorar la robustez del código, implementamos bloques `try`, `catch` y `throw` en diversas partes del proyecto. Esta implementación permite capturar y manejar excepciones de manera más específica, evitando que errores críticos interrumpan el flujo del programa. La captura de excepciones específicas ayuda a proporcionar mensajes de error significativos, lo que mejora la experiencia del usuario y facilita la depuración.

Al implementar esto, el usuario puede recibir mensajes de este estilo en la terminal;
``Por favor, ingrese un año válido: 
Error: El valor ingresado no es un año válido``
---------
## Eliminación de Archivos Duplicados en CMake
-----
Se identificaron configuraciones duplicadas en los archivos de CMake, lo que estaba generando que nuestro proyecto tuviese muy baja "Reliability" en el informe de SonarCloud. Con ayuda del mismo, identificamos que el archivo de CMake se había duplicado érronameante. Para resolver esto, se consolidaron en un solo archivo de configuración que actúa como la fuente principal. Esta unificación reduce la complejidad del mantenimiento y disminuye el riesgo de inconsistencias en las configuraciones de compilación.

Pudimos acceder a los duplicados por medio de la herramienta:
``Duplications
src
—
5.2%
``
--------
## Inicialización en `SNIESController`
------------
Se mejoró la inicialización de las variables miembro de la clase `SNIESController`. Anteriormente, algunas variables no estaban correctamente inicializadas, lo que podía causar errores en tiempo de ejecución. Ahora, las variables se inicializan adecuadamente en el constructor de la clase, lo que asegura un estado consistente del objeto durante su ciclo de vida.

-------
## Fusión de `Ramas` y Seguimiento de `Métricas`
----
Se ha realizado la fusión de las ramas de desarrollo en la rama principal, incorporando mejoras en la complejidad ciclomática, cobertura y duplicación de código. Se han configurado verificaciones automáticas con SonarQube para detectar problemas de manera temprana y garantizar que las métricas de calidad del código se mantengan dentro de los estándares definidos. Estas herramientas permiten un análisis continuo del código, identificando áreas para mejorar y asegurando la sostenibilidad del proyecto a largo plazo.

------

## Integración Continua con `GitHub Actions y CMake`

------
Para garantizar la calidad del código y la estabilidad del proyecto, configuramos GitHub Actions junto con CMake para que, cada vez que se realizara un push al repositorio, se ejecutara automáticamente el proceso de compilación. Esto nos permitió verificar que el código compilara correctamente y que no hubiera errores introducidos por cambios recientes, lo que mejoró significativamente el flujo de desarrollo al proporcionar retroalimentación inmediata a los desarrolladores.

Además, se generó un workflow adicional que se ejecutaba en una rama específica. Esta configuración tenía como objetivo prevenir que los cambios introducidos en la rama de desarrollo rompieran el código en la rama principal. El workflow ejecutaba pruebas y verificaciones adicionales antes de permitir la fusión de los cambios, asegurando que se mantuviera la integridad y calidad del código en todo momento.


`name: CMake on a single platform`
`on:`
 ` push:`
    `branches: `
      `- pruebasProyecto`
  `pull_request:`
    `branches: `
    `  - pruebasProyecto`
------

## Beneficios del `Análisis Automatizado y la Integración Continua`

-----
Las configuraciones implementadas no solo ayudaron a detectar errores de manera temprana, sino que también facilitaron la identificación de problemas de calidad del código, como la duplicación o la complejidad excesiva en algunas funciones. Gracias a las herramientas de integración continua y los análisis automáticos, el equipo pudo centrarse en mejorar el código progresivamente, garantizando que cada cambio contribuía a la calidad general del proyecto.

-----
## Identificación de errores para mantenibilidad `(Issues)`
-----
Con ayuda de la herramienta SonarCloud, fuimos capaces de identificar una gran cantidad de errores, desde errores de "Reliability", "Security", y particularmente de "Maintainability". Identificar estos errores y corregirlos resulta de gran ayuda pues nos permite practicar las buenas prácticas de programación. Un ejemplo de esto se identifica en errores como el siguiente;

### ``FIXME:`` Pasar parámetro por referencia; GestorCSV #21
``vector GestorCsv::leerProgramasCsv(string &ruta)
Make the type of this parameter a reference-to-const. The current type of "ruta" is "std::string &".``

--> Al arreglar errores como este, y el de pasar objetos por referencia para evitar generar copias, se optimiza el rendimiento del código al reducir la sobrecarga de memoria y tiempo asociada con la creación de copias innecesarias de objetos. Adicionalmente, al cambiar el tipo de parámetro a una referencia constante (const std::string&), garantizamos que el valor original no sea modificado, mejorando la seguridad del código al mismo tiempo que mantenemos la eficiencia.

-----



