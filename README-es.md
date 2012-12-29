INSYDE
------

Descripcion: INSYDE (Intelligent System Designer) es un entorno de desarrollo integrado para la creacion, estudio y
analisis de sistemas inteligentes, le permitira crear sus proyectos donde podra insertar objetos que pueden emular 
condiciones basicas de un entorno, asi como tambien, agregar componentes de procesamiento "inteligente" como 
algun motor de logica difusa, redes neuronales, optimizacion por algoritmos geneticos o colonias de hormigas, entre
otros. El objetivo principal es desarrollar un entorno que le permita de forma intuitiva y muy sencilla crear sus 
propios sistemas inteligentes sin tener un conocimiento muy avanzado de programacion o de los algoritmos 
que componen las distintas tecnicas o paradigmas de inteligencia artificial.

Objetivos del proyecto

- Desarrollar una interfaz sumamente intuitiva, sencilla y amigable para los usuarios sin que estos deban tener
  un conocimiento avanzado sobre Inteligencia Artificial
- Implementar un modelo de integracion de plugins para que los usuarios puedan instalar caracteristicas especiales
  al software
- Implementacion del diversas areas de Inteligencia Artificial como redes neuronales artificiales, algoritmos geneticos,
  logica difusa, sistemas expertos, computacion emergente, entre otros.
- Implementar un sistema de asistentes inteligentes para que el usuario menos experimentado sea dirigido a la hora
  de desarrollar su sistema inteligente

Estado del proyecto

Actualmente el proyecto esta en sus inicios, se esta desarrollando como punto de partida el modulo de Redes Neuronales
Artificiales. En este modulo el usuario podra crear de forma sencilla sus sistemas con aprendizaje mediante redes 
neuronales. 
El metodo sera muy sencillo, el usuario solamente tomara una red neuronal con el raton y la colocara sobre el Visor.
Luego este podra colocar otros objetos de entrada/salida como por ejemplo matrices de puntos para el reconocimiento
de patrones, objetos de imagenes, el cual es un modulo al cual podra asignarle una imagen en distintos formatos; 
esto puede servir para hacer analisis de vision artificial a imagenes. Tambien se introduciran otros objetos cotidianos
como displays digitales, entrada de teclado, entrada de raton, entrada de audio, salida de audio, capturador de video,
capturador de imagen del escritorio, capturador de entradas analogicas.

Alcance de la primera version (1.0.0)

En el primer lanzamiento se tendran las siguientes caracteristicas: 

- Toolbox de redes neuronales:
    Perceptron Multicapa, Hopfield, Kohonen, ADALINE, Perceptron simple
- Editor avanzado de redes neuronales:
    Este editor permite ver graficamente cada una de las conexiones y las entradas que tiene la red neuronal
    en un instante dado. Los pesos sinapticos son representados mediante colores que van desde el rojo al verde; 
    dichos colores pueden ser ajustados en rango para adaptar la representacion grafica.
- Editor avanzado de conjuntos de entrenamiento:
    Este editor permitira crear su conjunto de entrenamiento a partir de datos importado, o capturados de cualquier
    tipo de objeto valido que tenga coherencia con el conjunto de entrenamiento como tal.
- Objetos de entrada:
    Matriz de puntos, Display digital, Regiones, Imagen, Entrada teclado, Entrada raton, Entrada audio
- Objetos de salida:
    Representacion binaria, Dislplay digital, Matriz de puntos, Salida audio, Salida raton, Salida imagen
- Gestor de proyectos:
    Como se viene manejando en la mayoria de los IDEs, este tendra un gestor de proyectos basado en XML. Esto le
    permitira guardar el estado actual de su sistema inteligente, asi como datos de sintonizacion actuales, por ejemplo,
    los pesos de las redes neuronales. Tambien podra exportar los datos de los objetos en distiontos archivos.

Necesidades

El proyecto actualmente esta en pleno desarrollo, por lo cual, se requiere ampliamente el desarrollo de muchas areas, 
algunas necesidades primordiales son:

- Documentacion del codigo fuente: el codigo fuente ha sido desarrollado por mi y lamentablemente soy un mal
  practicante de la buena programacion, por lo cual en ocasiones por rapidez no documento lo que voy programando.
- Traduccion del codigo fuente: para que el proyecto sea ampliamente difundido, es imperativo la publicacion en varios
  idiomas para que distintos desarrolladores a nivel mundial esten en capacidad de trabajar en este proyecto.
- Programacion de la interfaz grafica: la interfaz grafica es una de las partes mas importantes de todo el proyecto,
  sin embargo, mi especializacion esta en el area de inteligencia artificial, por lo cual, me es dificil dedicarme a 
  ambas cosas, lo cual requiere mucho tiempo y dedicacion.
- Distintos algoritmos de IA: en inteligencia artificial existen un gran numero de algoritmos, asi como derivaciones
  y optimizaciones de algunos ya existentes. Estos algoritmos son complejos y toma mucho tiempo implementarlos. Por 
  tal motivo es necesario un aporte de la comunidad en distintas areas de conocimiento de IA.
- Modelado UML: como buena practica de la ingenieria de software es necesario partir de un buen diseño para obtener
  un software bien desarrollado y lo mas optimo posible, sin embargo, actualmente estoy solo en el desarrollo del
  proyecto, entonces, se hace complicado llevar a cabo estas tareas.
