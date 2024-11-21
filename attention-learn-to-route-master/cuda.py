import torch

if torch.cuda.is_available():
    print("CUDA está disponível!")
    print(f"Número de GPUs disponíveis: {torch.cuda.device_count()}")
    print(f"Nome da GPU: {torch.cuda.get_device_name(0)}")
else:
    print("CUDA não está disponível.")
