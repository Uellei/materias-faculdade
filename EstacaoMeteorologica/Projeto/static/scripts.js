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
menuToggle.onclick = function() {
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
        height: 350,
        type: 'line',
        zoom: {
            enabled: false
        },
    },
    dataLabels: {
        enabled: false
    },
    stroke: {
        width: [5],
        curve: 'straight',
    },
    title: {
        text: 'Temperatura',
        align: 'left',
        colors: "red"
    },
    legend: {
        tooltipHoverFormatter: function(val, opts) {
            return val + ' - ' + opts.w.globals.series[opts.seriesIndex][opts.dataPointIndex] + '';
        }
    },
    xaxis: {
        categories: [],
        style: {
            colors: "red"
        }
    },
    tooltip: {
        x: {
            show: false
        },
        y: {
            title: {
                formatter: function(val) {
                    return val + ": (°C)"
                }
            },
        },
        theme: "dark",
        fixed: {
            enabled: false,
            position: "topLeft"
        },
    },
    fill: {
        colors: "black",
        opacity: 0.9,
        type: "solid",
        pattern: {
            style: 'verticalLines',
            width: 6,
            height: 6,
            strokeWidth: 2,
        },
    },
    grid: {
        borderColor: '#f1f1f1',
    },
    colors: ["red"]
};

var umidadeData = {
    series: [{
        name: "Umidade",
        data: []
    }],
    chart: {
        height: 350,
        type: 'line',
        zoom: {
            enabled: false
        }
    },
    dataLabels: {
        enabled: false
    },
    stroke: {
        curve: 'smooth'
    },
    title: {
        text: 'Gráfico de Umidade',
        align: 'left'
    },
    grid: {
        row: {
            colors: ['#f3f3f3', 'transparent'],
            opacity: 0.5
        }
    },
    xaxis: {
        categories: []
    }
};

var luminosidadeData = {
    series: [{
        name: "Umidade",
        data: []
    }],
    chart: {
        height: 350,
        type: 'line',
        zoom: {
            enabled: false
        }
    },
    dataLabels: {
        enabled: false
    },
    stroke: {
        curve: 'smooth'
    },
    title: {
        text: 'Gráfico de Umidade',
        align: 'left'
    },
    grid: {
        row: {
            colors: ['#f3f3f3', 'transparent'],
            opacity: 0.5
        }
    },
    xaxis: {
        categories: []
    }
};
    
function fetchDataFromServer() {
    return fetch("http://192.168.233.141:5000/dados")
        .then(response => response.json())
        .then(el => {
            const tempData = el.Temperatura
            const umidData = el.Umidade
            const lxData = el.Luminosidade
            const responseData = {
                temperatura: tempData,
                umidade: umidData,
                luminosidade: lxData
            }
            return responseData
        });
        
}
fetchDataFromServer()
    .then(responseData => {
        // TEMPERATURA
        temperatureData.xaxis.categories = responseData.temperatura.time
        temperatureData.series[0].data = responseData.temperatura.data
        // UMIDADE
        umidadeData.xaxis.categories = responseData.umidade.time
        umidadeData.series[0].data = responseData.umidade.data
        // LUMINOSIDADE
        luminosidadeData.xaxis.categories = responseData.luminosidade.time
        luminosidadeData.series[0].data = responseData.luminosidade.data
    })
var chartTemp = new ApexCharts(document.querySelector("#temp-chart"), temperatureData);
chartTemp.render()
var chartUmid = new ApexCharts(document.querySelector("#umid-chart"), umidadeData);
chartUmid.render()
var chartLx = new ApexCharts(document.querySelector("#lx-chart"), luminosidadeData);
chartLx.render()
    

    
    
// TEMPERATURA
var tempLength = 0;

function addTemperaturaPoint() {
    fetch("http://192.168.233.141:5000/dados")
        .then(response => response.json())
        .then(el => {
            const tempData = el.Temperatura.data;
            const timeData = el.Temperatura.time;
            if (tempData.length !== tempLength) {
                temperatureData.xaxis.categories.push(timeData[timeData.length - 1]);
                temperatureData.series[0].data.push(tempData[tempData.length - 1]);
                var updateTempData = JSON.parse(JSON.stringify(temperatureData));
                chartTemp.updateOptions(updateTempData);

                tempLength += 1;
            }
        });
}
setInterval(addTemperaturaPoint, 5500);

// UMIDADE
var umidLength = 0;

function addUmidadePoint() {
    fetch("http://192.168.233.141:5000/dados")
        .then(response => response.json())
        .then(el => {
            const umidData = el.Umidade.data;
            const timeData = el.Umidade.time;
            if (umidData.length !== umidLength) {
                umidadeData.xaxis.categories.push(timeData[timeData.length - 1]);
                umidadeData.series[0].data.push(umidData[umidData.length - 1]);
                var updateUmidData = JSON.parse(JSON.stringify(umidadeData));
                chartUmid.updateOptions(updateUmidData);

                umidLength += 1;
            }
        });
}
setInterval(addUmidadePoint, 60500);

// LUMINOSIDADE
var lxLength = 0;

function addLuminosidadePoint() {
    fetch("http://192.168.233.141:5000/dados")
        .then(response => response.json())
        .then(el => {
            const lxData = el.Luminosidade.data;
            const timeData = el.Luminosidade.time;
            if (lxData.length !== lxLength) {
                luminosidadeData.xaxis.categories.push(timeData[timeData.length - 1]);
                luminosidadeData.series[0].data.push(lxData[lxData.length - 1]);
                var updateLxData = JSON.parse(JSON.stringify(luminosidadeData));
                chartLx.updateOptions(updateLxData);

                lxLength += 1;
            }
        });
}

setInterval(addLuminosidadePoint, 60500);

// JA RESOLVI NO ARDUINO PRA NÃO MANDAR REPETIDO, SO TEM QUE VER AGORA, PQ SE NÃO TIVER DADO AQUI ELE MANDA REPETIDO, FAZER A MESMA VERIFICAÇÃO EM CADA UM
    