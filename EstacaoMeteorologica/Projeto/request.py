import requests

# Defina os dados que você deseja enviar
dados = {
    "Temperatura": "20",
    "Luminosidade": "15",
    "Umidade": "10"
}
# dados = {

# }

# Defina a URL do endpoint onde o servidor Flask está escutando
url = 'http://10.67.48.5:5000/dados'  # Atualize com a URL do seu servidor Flask

# Faça uma solicitação POST para enviar os dados
response = requests.post(url, json=dados)

# Verifique a resposta do servidor
if response.status_code == 200:
    print('Dados enviados com sucesso')
else:
    print('Erro ao enviar os dados:', response.status_code)
