import random
import matplotlib.pyplot as plt

def simular_skip_list(num_nodos):
    nodos = list(range(1, num_nodos + 1)) 
    niveles = {1: nodos}

    nivel_actual = 1
    while True:
        nodos_superiores = [nodo for nodo in niveles[nivel_actual] if random.choice([True, False])]
        if not nodos_superiores:
            break
        nivel_actual += 1
        niveles[nivel_actual] = nodos_superiores

    return niveles

def mostrar_distribucion(niveles):
    distribucion = {nivel: len(nodos) for nivel, nodos in niveles.items()}
    niveles_keys = sorted(distribucion.keys())
    frecuencias = [distribucion[n] for n in niveles_keys]
    
    plt.bar(niveles_keys, frecuencias, color='skyblue', edgecolor='black')
    plt.title("Distribución de Niveles en la Lista de Salto ")
    plt.xlabel("Nivel")
    plt.ylabel("Número de Nodos")
    plt.show()


NUM_NODOS = 1000000  

niveles = simular_skip_list(NUM_NODOS)

print("Distribución de niveles:")
for nivel, nodos in sorted(niveles.items()):
    print(f"Nivel {nivel}: {len(nodos)} nodos")

mostrar_distribucion(niveles)