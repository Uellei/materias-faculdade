const url = "https://edf9-2804-214-8594-a7c9-b88c-3938-f564-89ea.ngrok-free.app/dados"

let menuToggle = document.querySelector(".menuToggle")
let sidebar = document.querySelector(".sidebar")
menuToggle.onclick = function() {
    menuToggle.classList.toggle("active")
    sidebar.classList.toggle("active")
}

let menuList = document.querySelectorAll(".buttons-charts li")
function activeLink() {
    menuList.forEach((item) => 
        item.classList.remove("active"));
        this.classList.add('active');
}
menuList.forEach((item) => 
    item.addEventListener("click", activeLink))

var tempOptions = {
    chart: {
        height: 330,
        type: "area",
        foreColor: "#ccc", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#E05F37"],
    stroke: {
        width: 3
    },
    grid: {
        borderColor: "#555",
        clipMakers: false,
        yaxis: {
            lines: {
                show: false
            }
        }
    },
    dataLabels: {
        enabled: false
    },
    series: [
        {
        name: "Umidade",
        data: [30, 31, 28, 27, 29, 39, 37, 36, 36, 35]
        }
    ],
    fill: {
        gradient: {
            enabled: true,
            opacityFrom: 0.55,
            opacityTo: 0
        }
    },
    markers: {
        size: 5,
        colors: ["white"],
        strokeColor: "#E05F37",
        strokeWidth: 3
      },
    xaxis: {
        categories: ["9h", "10h", "11h", "12h", "13h", "14h", "15h", "16h", "17h", "18h"]
    },
    tooltip: {
        theme: "dark",
        y: {
            formatter: function (val) {
                return val + " °C";
            }
        }
    },
    yaxis: {
        min: 15,
        tickAmount: 2
    } 
};

var umidOptions = {
    chart: {
        height: 330,
        type: "area",
        foreColor: "#ccc", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#00B3E6"],
    stroke: {
        width: 3
    },
    grid: {
        borderColor: "#555",
        clipMakers: false,
        yaxis: {
            lines: {
                show: false
            }
        }
    },
    dataLabels: {
        enabled: false
    },
    series: [
        {
        name: "Umidade",
        data: [30, 27, 28, 29, 27, 25, 24, 22, 21, 20]
        }
    ],
    fill: {
        gradient: {
            enabled: true,
            opacityFrom: 0.55,
            opacityTo: 0
        }
    },
    markers: {
        size: 5,
        colors: ["white"],
        strokeColor: "#00B3E6",
        strokeWidth: 3
      },
    xaxis: {
        categories: ["9h", "10h", "11h", "12h", "13h", "14h", "15h", "16h", "17h", "18h"]
    },
    tooltip: {
        theme: "dark",
        y: {
            formatter: function (val) {
                return val + " %";
            }
        }
    },
    yaxis: {
        min: 15,
        tickAmount: 2
    } 
};

var pressOptions = {
    chart: {
        height: 330,
        type: "area",
        foreColor: "#ccc", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#008080"],
    stroke: {
        width: 3
    },
    grid: {
        borderColor: "#555",
        clipMakers: false,
        yaxis: {
            lines: {
                show: false
            }
        }
    },
    dataLabels: {
        enabled: false
    },
    series: [
        {
        name: "Pressão",
        data: [900, 920, 960, 940, 910, 930, 970, 976, 971, 990]
        }
    ],
    fill: {
        gradient: {
            enabled: true,
            opacityFrom: 0.55,
            opacityTo: 0
        }
    },
    markers: {
        size: 5,
        colors: ["white"],
        strokeColor: "#008080",
        strokeWidth: 3
      },
    xaxis: {
        categories: ["9h", "10h", "11h", "12h", "13h", "14h", "15h", "16h", "17h", "18h"]
    },
    tooltip: {
        theme: "dark",
        y: {
            formatter: function (val) {
                return val + " hPa";
            }
        }
    },
    yaxis: {
        min: 15,
        tickAmount: 2
    } 
};

var lxOptions = {
    chart: {
        height: 330,
        type: "area",
        foreColor: "#ccc", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#FECB2F"],
    stroke: {
        width: 3
    },
    grid: {
        borderColor: "#555",
        clipMakers: false,
        yaxis: {
            lines: {
                show: false
            }
        }
    },
    dataLabels: {
        enabled: false
    },
    series: [
        {
        name: "Luminosidade",
        data: [100, 120, 130, 164, 176, 140, 120, 113, 80, 75]
        }
    ],
    fill: {
        gradient: {
            enabled: true,
            opacityFrom: 0.55,
            opacityTo: 0
        }
    },
    markers: {
        size: 5,
        colors: ["white"],
        strokeColor: "#FECB2F",
        strokeWidth: 3
      },
    xaxis: {
        categories: ["9h", "10h", "11h", "12h", "13h", "14h", "15h", "16h", "17h", "18h"]
    },
    tooltip: {
        theme: "dark",
        y: {
            formatter: function (val) {
                return val + " lux";
            }
        }
    },
    yaxis: {
        min: 15,
        tickAmount: 2
    } 
};

var rotOptions = {
    chart: {
        height: 330,
        type: "area",
        foreColor: "#ccc", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#AEBC3D"],
    stroke: {
        width: 3
    },
    grid: {
        borderColor: "#555",
        clipMakers: false,
        yaxis: {
            lines: {
                show: false
            }
        }
    },
    dataLabels: {
        enabled: false
    },
    series: [
        {
        name: "Temperatura",
        data: [130, 170, 128, 125, 110, 100, 80, 210, 230, 160]
        }
    ],
    fill: {
        gradient: {
            enabled: true,
            opacityFrom: 0.55,
            opacityTo: 0
        }
    },
    markers: {
        size: 5,
        colors: ["white"],
        strokeColor: "#AEBC3D",
        strokeWidth: 3
      },
    xaxis: {
        categories: ["9h", "10h", "11h", "12h", "13h", "14h", "15h", "16h", "17h", "18h"]
    },
    tooltip: {
        theme: "dark",
        y: {
            formatter: function (val) {
                return val + " rpm";
            }
        }
    },
    yaxis: {
        min: 15,
        tickAmount: 2
    } 
};
// AEBC3D


const chart = new ApexCharts(document.querySelector("#chart"), tempOptions);
chart.render();

function changeChartOptions(grandezaOption) {
    chart.updateOptions(grandezaOption);
}

// REQUISIÇÃO
function fetchData() {
    return fetch(`${url}`)
    .then(response => {
        if(!response.ok) {
            throw new Error("Erro ao obter os dados")
        }
        return response.json()
    })
    .then(data => {
        console.log(data)
        return data
    })
    .catch(error => console.log("Erro na requisição:", error))
}

const imgTemp = [
    "https://www.climatempo.com.br/dist/images/v2/svg/1.svg", // SOL
    "https://www.climatempo.com.br/dist/images/v2/svg/2.svg", // SOL COM NUVEM
    "https://www.climatempo.com.br/dist/images/v2/svg/2n.svg", // NUBLADO
    "https://www.climatempo.com.br/dist/images/v2/svg/4.svg" // SOL NUVEM E CHUVA
]

function updateDOM(data) {
    const temp = data.Temperatura.data[data.Temperatura.data.length - 1]
    console.log(temp)
    document.getElementById('weather-temp').textContent = temp
    document.querySelector("#weather-icon > img").src = temp < 32 ? imgTemp[1] : imgTemp[0]
    document.getElementById('weather-condition').textContent = "Poucas Nuvens" 
    document.getElementById('weather-sensation').textContent = temp < 35 ? `${temp - 1}°C` : temp ? +temp - 1 + "°C" : ""
    document.getElementById("weather-wind").textContent = data.Rotacao.data[data.Rotacao.data.length - 1]
    document.getElementById("weather-umid").textContent = data.Umidade.data[data.Umidade.data.length - 1]
}

setInterval(fetchData().then(updateDOM), 120000);

function updateCard(data) {
    if (data.Temperatura.data.length > 0) {
        const maxTemp = Math.max(...data.Temperatura.data)
        const minTemp = Math.min(...data.Temperatura.data)
        document.querySelector('.max-temp').textContent = maxTemp
        document.querySelector('.min-temp').textContent = minTemp
    }
    document.querySelector('.umid-num').textContent = data.Umidade.data.length > 0 ? data.Umidade.data[0] + "%" : ""
    document.querySelector('.lx-num').textContent = data.Luminosidade.data.length > 0 ? data.Luminosidade.data[0] + "lux" : ""
    document.querySelector('.press-num').textContent = data.Pressao.data.length ? data.Pressao.data[0] + "hPa": ""
    document.querySelector('.rot-num').textContent = data.Rotacao.data.length ? data.Rotacao.data[0] + "bpm": ""
}

setInterval(fetchData().then(updateCard), 240000);