/*
/*1)*/
CREATE TABLE Cliente(
	CodigoCliente int primary key,
	Nome varchar(50),
	CPF varchar(11),
	Sexo char(1),
	DataNascimento date,
	CidadeResidencia varchar(30),
	Email varchar(100) unique,
	Senha varchar(50) unique
)

CREATE TABLE Marca(
	CodigoMarca INT PRIMARY KEY,
	Nome VARCHAR(50)
)

CREATE TABLE Modelo(
	CodigoModelo INT PRIMARY KEY,
	CodigoMarca INT REFERENCES Marca (CodigoMarca),
	Nome VARCHAR(50)
)

CREATE TABLE Agencia(
	CodigoAgencia INT PRIMARY KEY,
	Nome VARCHAR(50),
	Cidade VARCHAR(50),
	ESTADO CHAR(2)
)

CREATE TABLE AgenciaModeloDisponivel(
	CodigoAgenciaModeloDisponivel INT PRIMARY KEY,
	CodigoAgencia INT REFERENCES Agencia(CodigoAgencia),
	CodigoModelo INT REFERENCES Modelo(CodigoModelo),
	Placa VARCHAR(10),
	DataHoraEntradaAgencia DATETIME,
)

CREATE TABLE Locacao(
	CodigoLocacao INT PRIMARY KEY,
	DataHoraPedido DATETIME,
	CodigoCliente INT REFERENCES Cliente(CodigoCliente),
	DataInicioLocacao DATE,
	CodigoAgenciaModeloDisponivelRetirada INT REFERENCES AgenciaModeloDisponivel(CodigoAgenciaModeloDisponivel),
	QtdDiasAluguel INT,
	CodigoAgenciaDevolucao INT REFERENCES Agencia(CodigoAgencia),
	DataDevolucaoEfetiva DATE
)
-- 2)
CREATE PROCEDURE STPAgenciaInserir(
	@CodigoAgencia INT,
	@Nome VARCHAR(50),
	@Cidade VARCHAR(50),
	@Estado CHAR(2)
)
AS 
BEGIN
	INSERT INTO Agencia (CodigoAgencia, Nome, Cidade, Estado)
	VALUES (@CodigoAgencia, @Nome, @Cidade, @Estado)
END


-- 3)
EXEC STPAgenciaInserir 1, 'Agencia1', 'São Paulo', 'SP'
EXEC STPAgenciaInserir @CodigoAgencia = 2, @Nome = 'Agencia1', @Cidade = 'São Paulo', @Estado = 'SP'
EXEC STPAgenciaInserir @CodigoAgencia = 3, @Nome = 'Agencia3', @Cidade = 'Rio de Janeiro', @Estado = 'RJ'

-- 4)
CREATE PROCEDURE STPAClienteInserir(
	@CodigoCliente INT,
    @Nome VARCHAR(50),
	@CPF VARCHAR(11),
	@Sexo CHAR(1),
    @DataNascimento DATE,
    @CidadeResidencia VARCHAR(50),
    @Email VARCHAR(50),
    @Senha VARCHAR(50)
)
AS
BEGIN
	INSERT INTO Cliente(CodigoCliente, Nome, CPF, Sexo, DataNascimento, CidadeResidencia, Email, Senha)
	VALUES (@CodigoCliente, @Nome, @CPF, @Sexo, @DataNascimento, @CidadeResidencia, @Email, @Senha)
END

-- 5)
EXEC STPAClienteInserir @CodigoCliente = 1, @Nome = 'Weslley Marcelo', @CPF = '11111111111', @Sexo = 'M', @DataNascimento = '2003-03-15', @CidadeResidencia = 'Sumare', @Email = 'wessmarcelo@gmail.com', @Senha = '123456'
EXEC STPAClienteInserir 2, 'Vanderleia Morais', '22222222222', 'F', '27-08-1975', 'Sumare', 'leia@gmail.com', '1234567'
EXEC STPAClienteInserir 3, 'Ashley', '33333333333', 'F', '11-11-2011', 'Sumare', 'Ashley@gmail.com', '12345'

-- 6)
CREATE PROCEDURE STPAgenciaModeloDisponivelInserir(
    @CodigoAgenciaModeloDisponivel INT,
    @CodigoAgencia INT,
    @CodigoModelo INT, 
    @Placa VARCHAR(10),
    @DataHoraEntradaAgencia DATETIME
)
AS
BEGIN
    INSERT INTO STPAgenciaModeloDisponivelInserir(CodigoAgenciaModeloDisponivel, CodigoAgencia, CodigoModelo, Placa, DataHoraEntradaAgencia)
    VALUES (@CodigoAgenciaModeloDisponivel, @CodigoAgencia, @CodigoModelo, @Placa, @DataHoraEntradaAgencia)
END

-- 7)
EXEC STPAgenciaModeloDisponivelInserir '1', '1', 'ABC1234', '2023-05-04 14:30:00';
EXEC STPAgenciaModeloDisponivelInserir '1', '2', 'DEF5678', '2023-05-05 09:00:00';
EXEC STPAgenciaModeloDisponivelInserir '2', '3', 'GHI9012', '2023-05-06 12:15:00';

-- 8)
CREATE PROCEDURE STPLocacaoInserir (
	@CodigoLocacao INT,
	@DataHoraPedido DATETIME,
	@CodigoCliente INT,
	@DataInicioLocacao DATE,
	@CodigoAgenciaModeloDisponivelRetirada INT,
	@QtdDiasAluguel INT,
	@CodigoAgenciaDevolucao INT
)
AS
BEGIN
	IF DATEDIFF(YEAR, (SELECT DataNascimento FROM Cliente WHERE CodigoCliente = @CodigoCliente), GETDATE()) < 18
	BEGIN
		PRINT 'Cliente não tem idade para aluguel'
		RETURN
	END

	IF @QtdDiasAluguel < 10
	BEGIN
		PRINT 'Aluguel deve ter no mínimo 10 dias'
		RETURN
	END
	INSERT INTO Locacao(CodigoLocacao,DataHoraPedido,CodigoCliente,DataInicioLocacao,CodigoAgenciaModeloDisponivelRetirada,QtdDiasAluguel,CodigoAgenciaDevolucao,DataDevolucaoEfetiva)
	VALUES (@CodigoLocacao,@DataHoraPedido,@CodigoCliente,@DataInicioLocacao,@CodigoAgenciaModeloDisponivelRetirada,@QtdDiasAluguel,@CodigoAgenciaDevolucao,NULL)
END

-- 9)
EXEC STPLocacaoInserir @CodigoLocacao = 1, @DataHoraPedido = '2023-05-10 10:00:00', @CodigoCliente = 1, @DataInicioLocacao = '2023-05-10', @CodigoAgenciaModeloDisponivelRetirada = 1, @QtdDiasAluguel = 15, @CodigoAgenciaDevolucao = 2
-- Tentativa de inserir com dias de aluguel menos que 10, e retornou o print e nao inseriu
EXEC STPLocacaoInserir @CodigoLocacao = 2, @DataHoraPedido = '2022-04-11 17:32:21', @CodigoCliente = 2, @DataInicioLocacao = '2022-04-11', @CodigoAgenciaModeloDisponivelRetirada = 1, @QtdDiasAluguel = 9, @CodigoAgenciaDevolucao = 1
EXEC STPLocacaoInserir @CodigoLocacao = 2, @DataHoraPedido = '2022-04-11 17:32:21', @CodigoCliente = 2, @DataInicioLocacao = '2022-04-11', @CodigoAgenciaModeloDisponivelRetirada = 1, @QtdDiasAluguel = 12, @CodigoAgenciaDevolucao = 1
-- Tentativa com o CodigoCliente três que é uma mulher menos de idade e retornou o print sem inserir
EXEC STPLocacaoInserir @CodigoLocacao = 3, @DataHoraPedido = '2022-04-11 17:32:21', @CodigoCliente = 3, @DataInicioLocacao = '2022-04-11', @CodigoAgenciaModeloDisponivelRetirada = 1, @QtdDiasAluguel = 12, @CodigoAgenciaDevolucao = 1
EXEC STPLocacaoInserir @CodigoLocacao = 3, @DataHoraPedido = '2022-04-11 17:32:21', @CodigoCliente = 1, @DataInicioLocacao = '2022-04-11', @CodigoAgenciaModeloDisponivelRetirada = 1, @QtdDiasAluguel = 12, @CodigoAgenciaDevolucao = 1