from flask import Flask, render_template, jsonify, request
from datetime import datetime

app = Flask(__name__)

paylaod = {
    "Temperatura": {
        "data": [],
        "time": []
        },
    "Umidade": {
        "data": [],
        "time": []
        },
    "Luminosidade": {
        "data": [],
        "time": []
        },
    "Pressao": {
        "data": [],
        "time": []
        },
    "Direcao": {
        "data": [],
        "time": []
        },
    "Rotacao": {
        "data": [],
        "time": []
        }
}

@app.route('/')
def index():
    return render_template('home.html')  # Renderize o template

@app.route('/home.html')
def home():
    return render_template('home.html')  # Renderize o template

@app.route('/dashboard.html')
def dashboard():
    return render_template("dashboard.html")

@app.route("/AboutUs.html")
def about():
    return render_template("AboutUs.html")

# @app.route('/dados-enviador', methods=['GET', 'POST'])
# def minha_paginaa():
#     if request.method == 'GET':
#         return jsonify(paylaod)
#     elif request.method == 'POST':
#         # Recebe e armazena os dados da requisição junto com o horário
#         time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
#         paylaod["Temperatura"]["time"].append(time)

@app.route("/dados", methods=['GET', 'POST'])    
def dados_temperatura():
    if request.method == "GET":
        return jsonify(paylaod)
    elif request.method == "POST":
        data = request.get_json()
        print(data)
        for key in data.keys():
            name = key
            value = data[key]
            time = datetime.now().strftime('%d/%m %H:%M')
            paylaod[name]["time"].append(time)
            paylaod[name]["data"].append(value)
    else:
        return jsonify({"error": "Método não suportado"})

if __name__ == '__main__':
    # app.run(host='0.0.0.0', port=5000)
    app.run()
