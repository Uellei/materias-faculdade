import requests
import random
import time

# Defina os dados que você deseja enviar

def gerar_dados():
    temp = random.randint(30,40)
    umidade = random.randint(10,20)
    luminosidade = random.randint(10,40)
    pressao = random.randint(800,900)
    rotacao = random.randint(0,10)
    return {
        "Temperatura": temp,
        "Umidade": umidade,
        "Luminosidade": luminosidade,
        "Pressao": pressao,
        "Rotacao": rotacao
    }

dados = {
    "Temperatura": "34",
    "Umidade": "27",
    "Luminosidade": "87",
    "Pressao": "920",
    "Rotacao": "0"
}
# dados = {

# }

# Defina a URL do endpoint onde o servidor Flask está escutando
url = 'https://edf9-2804-214-8594-a7c9-b88c-3938-f564-89ea.ngrok-free.app/dados'  # Atualize com a URL do seu servidor Flask

while True:
    # Faça uma solicitação POST para enviar os dados
    response = requests.post(url, json=gerar_dados())

    # Verifique a resposta do servidor
    if response.status_code == 200:
        print('Dados enviados com sucesso')
    else:
        print('Erro ao enviar os dados:', response.status_code)
        
    time.sleep(120)
