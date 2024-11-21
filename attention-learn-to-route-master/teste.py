import os
import numpy as np

def ler_coordenadas(arquivo):
    coordenadas = []
    highest_range = None
    with open(arquivo, 'r') as f:
        for linha in f:
            partes = linha.split()
            # Verifica coordenadas
            if len(partes) == 3:
                try:
                    x = float(partes[1])
                    y = float(partes[2])
                    coordenadas.append([x, y])
                except ValueError:
                    pass
            # Verifica o valor de Highest range
            elif len(partes) == 3 and partes[0] == "Highest" and partes[1] == "range:":
                try:
                    highest_range = float(partes[2])
                except ValueError:
                    raise ValueError(f"Valor inválido para Highest range na linha: {linha}")
    
    if highest_range is None:
        raise ValueError("O valor de 'Highest range' não foi encontrado no arquivo.")
    
    return coordenadas, highest_range

def normalizar_coordenadas(coordenadas,highest):
    return [[coord[0] / highest, coord[1] / highest] for coord in coordenadas]

def generate_trp_data(dataset_size, trp_size):
    dataset = []
    datasetTest = []

    test_instance = np.random.randint(1,20)

    for i in range(1, 21):
        arquivo = os.path.join('archives/problems/trp', f'TRP-S{trp_size}-R{i}.txt')
        coordenadas,highest_range = ler_coordenadas(arquivo)
        coordenadas_normalizadas = normalizar_coordenadas(coordenadas,highest_range)
        if i == test_instance:
            datasetTest.append(coordenadas_normalizadas)
        else:
            dataset.append(coordenadas_normalizadas)
    
    print(f'Test TRP Instace (R{test_instance})')
    print(datasetTest)
    print('Dataset:')
    print(dataset)

generate_trp_data(0,10)