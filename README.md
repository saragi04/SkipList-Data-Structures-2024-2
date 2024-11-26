# SkipList-Data-Structures-2024-2
SKIPLIST Proyecto final: estructura de datos 2024-2 
Presentado por: Santiago Ramirez Giralgo - Yigal Fabricio Rojas Acevedo

En este repositorio encontrarás información sobre la estructura de datos SkipList, implementación en el lenguaje C++, un código en lenguaje python donde se explica un poco el tema de la probabilidad que utiliza una SkipList para la creación de niveles en cada uno de sus nodos. 

Compartimos con ustedes dos videos donde podrán ver la explicación de todo lo que contiene este repositorio, a continuación los links de cada uno:

## Videos

- [![Video 1 - 45 minutos aprox](https://img.youtube.com/vi/U4Xz4a4iLtA/hqdefault.jpg)](https://youtu.be/U4Xz4a4iLtA)
  *Duración aproximada: 45 minutos*

- [![Video 2 - 30 minutos aprox](https://img.youtube.com/vi/yX4ppJlCovo/hqdefault.jpg)](https://youtu.be/yX4ppJlCovo)
  *Duración aproximada: 30 minutos*

A continuación, podrás leer un poco más acercar del skiplist, su concepto, en base a qué surgió, quién fue su creador, algunas aplicaciones y demás.

## ¿QUÉ ES UNA SKIPLIST?

Las SkipLists son una estructura de datos eficiente diseñada para almacenar conjuntos ordenados y realizar operaciones rápidas, como búsquedas, inserciones y eliminaciones. Su rendimiento es comparable al de estructuras más complejas, como los árboles balanceados (AVL o red-black trees), pero con una implementación más sencilla. La clave de su velocidad radica en el uso de múltiples y un enfoque probabilístico. Cada nodo contiene un valor y enlaces hacia otros niveles, lo que permite que algunos nodos “salten” sobre varios elementos, acelerando la búsqueda hacia la posición deseada.

Podemos pensar en la SkipList como una combinación entre una lista enlazada y una lista ordenada. Por un lado, la lista enlazada organiza los datos en nodos conectados entre sí, ofreciendo una estructura flexible. Por otro lado, la lista ordenada organiza los elementos de forma ascendente, lo que facilita dividirla en fragmentos más pequeños y aplicar estrategias de búsqueda rápida, como la búsqueda binaria. 

En las listas ordenadas, aunque las búsquedas pueden ser rápidas, insertar o eliminar elementos tiene un costo mayor, con una complejidad de O(n). Por otro lado, las listas enlazadas permiten inserciones más eficientes. Las SkipLists combinan lo mejor de ambas ideas: mantiene los elementos ordenados y organiza múltiples niveles, donde el nivel superior permite realizar saltos grandes y los inferiores refinan la búsqueda. De esta manera, se logran búsquedas rápidas con una complejidad esperada de O(log n) sin necesidad de realizar operaciones de reequilibrio complejas, como sucede en los árboles balanceados. 

Una implementación de SkipList puede verse en este repositorio en el archivo "skiplist.hh" y su funcionalidad puede verse reflejada ejecutando el código que se encuentra en el archivo "skiplist.cpp"


## ¿QUIÉN FUE SU CREADOR Y POR QUÉ SURGIÓ ESTA IDEA?

Las SkipLists fueron creadas en 1989 por William Pugh como una alternativa simple y eficiente a los árboles balanceados. En ese momento, los árboles como los AVL o red-black trees eran populares por su capacidad para mantener conjuntos ordenados con acceso rápido, pero su implementación era compleja y requería un procesamiento adicional para mantener el balance después de cada inserción o eliminación. Pugh diseñó las SkipLists con el objetivo de simplificar esta tarea, eliminando la necesidad de operaciones de reequilibrio. En su lugar, utilizó un enfoque probabilístico para organizar los datos en múltiples niveles.

Dicho enfoque probabilístico puede verse implementado en el código hecho en lenguaje Python de una manera gráfica y tambien analítica por medio de la consola a la hora de ejecutar el código, te invitamos a ejecutar el código que se ubica en el archivo "prabability_explain.py"

## APLICACIONES DE UNA SKIPLIST

- Bases de datos para manejar grandes volúmenes de datos y operaciones rápidas de búsqueda, inserción y eliminación. Un ejemplo claro de esto Google LevelIDB.
  
- Memtables en bases de datos NoSQL: utilizadas en bases de datos como Cassandra y Redis para gestión de datos en memoria, mejorando la eficiencia en sistemas distribuidos.
  
- Redes y sistemas de archivo: ayudan en el enrutamiento y búsqueda rápida de archivos o nodos en sistemas donde el orden es esencial. 

- Aplicaciones financieras y simulaciones: útiles para la gestión de grandes volúmenes de datos ordenados, como precios de acciones u operaciones comerciales en tiempo real.
