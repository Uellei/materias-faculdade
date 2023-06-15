/*/**/-- CRIAÇÃO DAS TABELAS
CREATE TABLE Locacao(
	Codigo INT PRIMARY KEY,
	dataPedido DATE,
	CodigoCliente INT,
	DataLocacao DATE,
	CodigoModelo INT,
	CodigoAgenciaRetirada INT,
	CodigoAgenciaDevolucao INT,
	dataDevolucao DATE
)

CREATE TABLE Cliente(
	Codigo INT PRIMARY KEY,
	Nome VARCHAR,
	Endereco VARCHAR,
	Bairro VARCHAR,
	Cidade VARCHAR,
	Cep VARCHAR,
	Estado VARCHAR
)

CREATE TABLE Modelo(
	Codigo INT PRIMARY KEY,
	Descricao VARCHAR,
	Valor INT,
	CodigoMarca INT
)

CREATE TABLE Marca (
	Codigo INT PRIMARY KEY,
	Descricao VARCHAR
)

CREATE TABLE ModeloAgencia(
	CodigoAgencia INT PRIMARY KEY,
	Quantidade INT
)

CREATE TABLE Agencia(
	Codigo INT PRIMARY KEY,
	Nome VARCHAR,
	Endereco VARCHAR,
	Bairro VARCHAR,
	Cidade VARCHAR,
	Cep VARCHAR,
	Estado VARCHAR
)

-- IMPLEMENTAR AS VIEWS
CREATE VIEW DetalhesLocacao AS
SELECT L.Codigo, L.dataPedido, C.Nome AS NomeCliente, L.DataLocacao, M.Descricao AS DescricaoModelo, M.Valor, AR.Nome AS AgenciaRetirada, AD.Nome AS AgenciaDevolucao, L.dataDevolucao
FROM Locacao L
JOIN Cliente C ON L.CodigoCliente = C.Codigo
JOIN Modelo M ON L.CodigoModelo = M.Codigo
JOIN Agencia AR ON L.CodigoAgenciaRetirada = AR.Codigo
JOIN Agencia AD ON L.CodigoAgenciaDevolucao = AD.Codigo;

CREATE VIEW DetalhesCliente AS
SELECT C.Codigo, C.Nome, C.Endereco, C.Bairro, C.Cidade, C.Cep, C.Estado
FROM Cliente C;

CREATE VIEW DetalhesModelo AS
SELECT M.Codigo, M.Descricao, M.Valor, MA.Quantidade, MR.Descricao AS DescricaoMarca
FROM Modelo M
JOIN ModeloAgencia MA ON M.Codigo = MA.CodigoAgencia
JOIN Marca MR ON M.CodigoMarca = MR.Codigo;

CREATE VIEW DetalhesMarca AS
SELECT MR.Codigo, MR.Descricao
FROM Marca MR;

CREATE VIEW DetalhesAgencia AS
SELECT A.Codigo, A.Nome, A.Endereco, A.Bairro, A.Cidade, A.Cep, A.Estado
FROM Agencia A;

