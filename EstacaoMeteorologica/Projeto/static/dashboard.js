const url = "https://edf9-2804-214-8594-a7c9-b88c-3938-f564-89ea.ngrok-free.app/dados"
document.addEventListener('DOMContentLoaded', function() {
    // Obtém o valor do parâmetro de consulta 'option' da URL
    const urlParams = new URLSearchParams(window.location.search);
    const selectedOption = urlParams.get('option');

    // Seleciona a opção correspondente no menu suspenso
    const chartSelector = document.getElementById('chartSelector');
    console.log(chartSelector)
    if (selectedOption) {
        // Define o valor da opção desejada
        const novaOpcao = selectedOption;

        // Altera a opção selecionada
        chartSelector.value = novaOpcao;

        // Dispara o evento 'change'
        const eventoChange = new Event('change');
        chartSelector.dispatchEvent(eventoChange);
    }
});

const chartSelector = document.getElementById("chartSelector");
const charts = document.querySelectorAll(".chart");

chartSelector.addEventListener("change", () => {
    const selectedChartId = chartSelector.value;
    charts.forEach(chart => {
        parentChart = chart.closest(".charts-card")
        parentChart.style.display = "none";
    });
    const selectedChart = document.getElementById(selectedChartId).closest(".charts-card");
    selectedChart.style.display = "block";
});
let menuToggle = document.querySelector(".menuToggle")
let sidebar = document.querySelector(".sidebar")
menuToggle.onclick = function () {
    menuToggle.classList.toggle("active")
    sidebar.classList.toggle("active")
}

let menuList = document.querySelectorAll(".MenuList li")
function activeLink() {
    menuList.forEach((item) =>
        item.classList.remove("active"));
    this.classList.add('active');
}
menuList.forEach((item) =>
    item.addEventListener("click", activeLink))


var temperatureData = {
    series: [{
        name: "Temperatura",
        data: []
    }],
    chart: {
        height: 480,
        type: 'line',
        foreColor: "#14161E", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#E05F37"],
    dataLabels: {
        enabled: false
    },
    stroke: {
        width: [3],
        curve: 'straight',
    },
    grid: {
        clipMakers: false,
    },
    // legend: {
    //     tooltipHoverFormatter: function(val, opts) {
    //         return val + ' - ' + opts.w.globals.series[opts.seriesIndex][opts.dataPointIndex] + '';
    //     }
    // },
    xaxis: {
        categories: [],
    },
    tooltip: {
        x: {
            show: false
        },
        yaxis: {
            min: 15
        },
        y: {
            formatter: function (val) {
                return val + " °C";
            }
        },
        theme: "dark",
    },
    fill: {
        type: "solid",
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
};

var umidadeData = {
    series: [{
        name: "Umidade",
        data: []
    }],
    chart: {
        height: 480,
        type: 'line',
        foreColor: "#14161E", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#00B3E6"],
    dataLabels: {
        enabled: false
    },
    stroke: {
        width: [3],
        curve: 'straight',
    },
    grid: {
        clipMakers: false,
    },
    // legend: {
    //     tooltipHoverFormatter: function(val, opts) {
    //         return val + ' - ' + opts.w.globals.series[opts.seriesIndex][opts.dataPointIndex] + '';
    //     }
    // },
    xaxis: {
        categories: [],
    },
    tooltip: {
        x: {
            show: false
        },
        yaxis: {
            min: 15
        },
        y: {
            formatter: function (val) {
                return val + " %";
            }
        },
        theme: "dark",
    },
    fill: {
        type: "solid",
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
};

var luminosidadeData = {
    series: [{
        name: "Luminosidade",
        data: []
    }],
    chart: {
        height: 480,
        type: 'line',
        foreColor: "#14161E", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#FECB2F"],
    dataLabels: {
        enabled: false
    },
    stroke: {
        width: [3],
        curve: 'straight',
    },
    grid: {
        clipMakers: false,
    },
    // legend: {
    //     tooltipHoverFormatter: function(val, opts) {
    //         return val + ' - ' + opts.w.globals.series[opts.seriesIndex][opts.dataPointIndex] + '';
    //     }
    // },
    xaxis: {
        categories: [],
    },
    tooltip: {
        x: {
            show: false
        },
        yaxis: {
            min: 15
        },
        y: {
            formatter: function (val) {
                return val + " lux";
            }
        },
        theme: "dark",
    },
    fill: {
        type: "solid",
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
};

var pressaoData = {
    series: [{
        name: "Pressão",
        data: []
    }],
    chart: {
        height: 480,
        type: 'line',
        foreColor: "#14161E", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#008080"],
    dataLabels: {
        enabled: false
    },
    stroke: {
        width: [3],
        curve: 'straight',
    },
    grid: {
        clipMakers: false,
    },
    // legend: {
    //     tooltipHoverFormatter: function(val, opts) {
    //         return val + ' - ' + opts.w.globals.series[opts.seriesIndex][opts.dataPointIndex] + '';
    //     }
    // },
    xaxis: {
        categories: [],
    },
    tooltip: {
        x: {
            show: false
        },
        yaxis: {
            min: 15
        },
        y: {
            formatter: function (val) {
                return val + " hPa";
            }
        },
        theme: "dark",
    },
    fill: {
        type: "solid",
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
};

var rotacaoData = {
    series: [{
        name: "Rotação",
        data: []
    }],
    chart: {
        height: 480,
        type: 'line',
        foreColor: "#14161E", // COR DAS LABELS X E Y,
        toolbar: {
            autoSelected: "pan",
            show: false
        }
    },
    colors: ["#AEBC3D"],
    dataLabels: {
        enabled: false
    },
    stroke: {
        width: [3],
        curve: 'straight',
    },
    grid: {
        clipMakers: false,
    },
    // legend: {
    //     tooltipHoverFormatter: function(val, opts) {
    //         return val + ' - ' + opts.w.globals.series[opts.seriesIndex][opts.dataPointIndex] + '';
    //     }
    // },
    xaxis: {
        categories: [],
    },
    tooltip: {
        x: {
            show: false
        },
        y: {
            formatter: function (val) {
                return val + " rpm";
            }
        },
        theme: "dark",
    },
    fill: {
        type: "solid",
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
};

function fetchDataFromServer() {
    return fetch(`${url}`)
        .then(response => {
            if (!response.ok) {
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
var chartTemp
var chartUmid
var chartLx
var chartPress
var chartRot
function updateCharts(data) {
    // TEMPERATURA
    if (data.Temperatura.data.length != 0) {
        temperatureData.series[0].data = data.Temperatura.data;
        temperatureData.xaxis.categories = data.Temperatura.time;
        chartTemp = new ApexCharts(document.querySelector("#temp-chart"), temperatureData);
        chartTemp.render();
    }

    // UMIDADE
    if (data.Umidade.data.length != 0) {
        umidadeData.series[0].data = data.Umidade.data;
        umidadeData.xaxis.categories = data.Umidade.time;
        chartUmid = new ApexCharts(document.querySelector("#umid-chart"), umidadeData);
        chartUmid.render();
    }

    // LUMINOSIDADE
    if (data.Luminosidade.data.length != 0) {
        luminosidadeData.series[0].data = data.Luminosidade.data;
        luminosidadeData.xaxis.categories = data.Luminosidade.time;
        chartLx = new ApexCharts(document.querySelector("#lx-chart"), luminosidadeData);
        chartLx.render();
    }

    // PRESSÃO
    if (data.Pressao.data.length != 0) {
        pressaoData.series[0].data = data.Pressao.data;
        pressaoData.xaxis.categories = data.Pressao.time;
        chartPress = new ApexCharts(document.querySelector("#press-chart"), pressaoData);
        chartPress.render();
    }

    // ROTAÇÃO
    if (data.Rotacao.data.length != 0) {
        rotacaoData.series[0].data = data.Rotacao.data;
        rotacaoData.xaxis.categories = data.Rotacao.time;
        chartRot = new ApexCharts(document.querySelector("#rot-chart"), rotacaoData);
        chartRot.render();
    }
}

fetchDataFromServer().then(updateCharts);

// TEMPERATURA
var tempAnt = null;

function addTemperaturaPoint() {
    fetch(url)
        .then(response => {
            if (!response.ok) {
                throw new Error('Erro ao obter os dados');
            }
            return response.json();
        })
        .then(el => {
            if (!el || !el.Temperatura || !el.Temperatura.data || !el.Temperatura.time) {
                console.error('Dados ausentes ou em formato incorreto.');
                return;
            }
            const tempData = el.Temperatura.data[el.Temperatura.data.length - 1]
            const timeData = el.Temperatura.time[el.Temperatura.time.length - 1]
            if (tempData !== tempAnt && el.Temperatura.data.length != 0) {
                if (temperatureData.series[0].data.length === 0) {
                    temperatureData.xaxis.categories.push(timeData);
                    temperatureData.series[0].data.push(tempData);
                } else {
                    const ultimoDado = temperatureData.series[0].data[temperatureData.series[0].data.length - 1];
                    if (ultimoDado !== tempData) {
                        temperatureData.xaxis.categories.push(timeData);
                        temperatureData.series[0].data.push(tempData);
                    }
                }
                var updateTempData = JSON.parse(JSON.stringify(temperatureData));
                if (chartTemp) {
                    chartTemp.updateOptions(updateTempData);
                } else {
                    chartTemp = new ApexCharts(document.querySelector("#temp-chart"), temperatureData);
                    chartTemp.render();
                }
                tempAnt = tempData
            }
        });
}
setInterval(addTemperaturaPoint, 4000);

// UMIDADE
var umidAnt = null;

function addUmidadePoint() {
    fetch(url)
        .then(response => {
            if (!response.ok) {
                throw new Error('Erro ao obter os dados');
            }
            return response.json();
        })
        .then(el => {
            if (!el || !el.Umidade || !el.Umidade.data || !el.Umidade.time) {
                console.error('Dados ausentes ou em formato incorreto.');
                return;
            }
            const umidData = el.Umidade.data[el.Umidade.data.length - 1]
            const timeData = el.Umidade.time[el.Umidade.time.length - 1]
            if (umidData !== umidAnt && el.Umidade.data.length != 0) {
                if (umidadeData.series[0].data.length === 0) {
                    umidadeData.xaxis.categories.push(timeData);
                    umidadeData.series[0].data.push(umidData);
                } else {
                    const ultimoDado = umidadeData.series[0].data[umidadeData.series[0].data.length - 1];
                    if (ultimoDado !== umidData) {
                        umidadeData.xaxis.categories.push(timeData);
                        umidadeData.series[0].data.push(umidData);
                    }
                }
                var updateData = JSON.parse(JSON.stringify(umidadeData));
                if (chartUmid) {
                    chartUmid.updateOptions(updateData);
                } else {
                    chartUmid = new ApexCharts(document.querySelector("#umid-chart"), umidadeData);
                    chartUmid.render();
                }
                umidAnt = umidData
            }
        });
}

setInterval(addUmidadePoint, 4000);

// LUMINOSIDADE
var lxAnt = null;

function addLuminosidadePoint() {
    fetch(url)
        .then(response => {
            if (!response.ok) {
                throw new Error('Erro ao obter os dados');
            }
            return response.json();
        })
        .then(el => {
            if (!el || !el.Luminosidade || !el.Luminosidade.data || !el.Luminosidade.time) {
                console.error('Dados ausentes ou em formato incorreto.');
                return;
            }
            const lxData = el.Luminosidade.data[el.Luminosidade.data.length - 1]
            const timeData = el.Luminosidade.time[el.Luminosidade.time.length - 1]
            if (lxData !== lxAnt && el.Luminosidade.data.length != 0) {
                if (luminosidadeData.series[0].data.length === 0) {
                    luminosidadeData.xaxis.categories.push(timeData);
                    luminosidadeData.series[0].data.push(lxData);
                } else {
                    const ultimoDado = luminosidadeData.series[0].data[luminosidadeData.series[0].data.length - 1];
                    if (ultimoDado !== lxData) {
                        luminosidadeData.xaxis.categories.push(timeData);
                        luminosidadeData.series[0].data.push(lxData);
                    }
                }
                var updateData = JSON.parse(JSON.stringify(luminosidadeData));
                if (chartLx) {
                    chartLx.updateOptions(updateData);
                } else {
                    chartLx = new ApexCharts(document.querySelector("#lx-chart"), luminosidadeData);
                    chartLx.render();
                }
                lxAnt = lxData
            }
        });
}

setInterval(addLuminosidadePoint, 4000);

// PRESSÃO
var pressAnt = null;

function addPressaoPoint() {
    fetch(url)
        .then(response => {
            if (!response.ok) {
                throw new Error('Erro ao obter os dados');
            }
            return response.json();
        })
        .then(el => {
            if (!el || !el.Pressao || !el.Pressao.data || !el.Pressao.time) {
                console.error('Dados ausentes ou em formato incorreto.');
                return;
            }
            const pressData = el.Pressao.data[el.Pressao.data.length - 1]
            const timeData = el.Pressao.time[el.Pressao.time.length - 1]
            if (pressData !== pressAnt && el.Pressao.data.length != 0) {
                if (pressaoData.series[0].data.length === 0) {
                    pressaoData.xaxis.categories.push(timeData);
                    pressaoData.series[0].data.push(pressData);
                } else {
                    const ultimoDado = pressaoData.series[0].data[pressaoData.series[0].data.length - 1];
                    if (ultimoDado !== pressData) {
                        pressaoData.xaxis.categories.push(timeData);
                        pressaoData.series[0].data.push(pressData);
                    }
                }
                var updateData = JSON.parse(JSON.stringify(pressaoData));
                if (chartPress) {
                    chartPress.updateOptions(updateData);
                } else {
                    chartPress = new ApexCharts(document.querySelector("#press-chart"), pressaoData);
                    chartPress.render();
                }
                pressAnt = pressData
            }
        });
}

setInterval(addPressaoPoint, 4000);

// ROTAÇÃO
var rotAnt = null

function addRotacaoPoint() {
    fetch(url)
        .then(response => {
            if (!response.ok) {
                throw new Error('Erro ao obter os dados');
            }
            return response.json();
        })
        .then(el => {
            if (!el || !el.Rotacao || !el.Rotacao.data || !el.Rotacao.time) {
                console.error('Dados ausentes ou em formato incorreto.');
                return;
            }
            const rotData = el.Rotacao.data[el.Rotacao.data.length - 1]
            const timeData = el.Rotacao.time[el.Rotacao.time.length - 1]
            if (rotData !== rotAnt && el.Rotacao.data.length != 0) {
                if (rotacaoData.series[0].data.length === 0) {
                    rotacaoData.xaxis.categories.push(timeData);
                    rotacaoData.series[0].data.push(rotData);
                } else {
                    const ultimoDado = rotacaoData.series[0].data[rotacaoData.series[0].data.length - 1];
                    if (ultimoDado !== rotData) {
                        rotacaoData.xaxis.categories.push(timeData);
                        rotacaoData.series[0].data.push(rotData);
                    }
                }
                var updateData = JSON.parse(JSON.stringify(rotacaoData));
                if (chartRot) {
                    chartRot.updateOptions(updateData);
                } else {
                    chartRot = new ApexCharts(document.querySelector("#rot-chart"), rotacaoData);
                    chartRot.render();
                }
                rotAnt = rotData
            }
        });
}
setInterval(addRotacaoPoint, 4000);

// JA RESOLVI NO ARDUINO PRA NÃO MANDAR REPETIDO, SO TEM QUE VER AGORA, PQ SE NÃO TIVER DADO AQUI ELE MANDA REPETIDO, FAZER A MESMA VERIFICAÇÃO EM CADA UM
