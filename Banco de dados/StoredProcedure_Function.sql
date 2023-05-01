/*
-- Entender como que a programação pode ser utilizada para construção de procedimentos armazenados e funções e como essas funções e procedimentos podem ser utilizados, em conjunto com SQL, em consultas e demais objetosdo Banco de Dados.

/* Sintaxe básica para criação de procedimentos armazenados
CREATE PROCEDURE nome_procedure
(
    @nome_parametro1 tipo_dado,
    @nome_parametro2 tipo_dado,
    @nome_parametroN tipo_dado
)
AS
BEGIN
COMANDO SQL
END

  Sintaxe básica para sua execução
  EXEC nome_procedure parâmetro1, parâmetro2, ..., parâmetro
*/

-- Exemplo 1
-- Criação de um procedimento armazenado para obter o nome de todos os clientes que realizaram uma compra em uma determinada data passada como parâmetro

CREATE PROCEDURE STP_ConsultaClientesData -- Declara a criação de um Stored Procedure
(
    @data date -- Declaração do parâmetro que será recebido pela Stored Procedure, do tipo "date"
)
AS -- Início do bloco de código do procedimento armazenado
BEGIN
    select nome -- Consulta que será realizada, retornando apenas o nome dos clientes que fizeram uma venda nessa data
    from cliente c inner join venda v on v.idCliente = c.ID_Cliente -- Declaração das tabelas que serão utilizadas na consulta, juntando a tabela "cliente", com a tabela "venda" através da chave estrangeira "idCliente" presente na tabela "venda" e refereciando a chave primária "ID_CLIENTE" presente na tabela "cliente"
    where v.data = @data -- Filtro da consulta para retornar apenas as vendas realizadas na data passada como parâmetro
END
-- Com essa Stored Procedure criada, é possível chamá-la passando uma data como parâmetro e ela retornará o nome dos clientes que fizeram venda nessa data. Isso facilita a reutilização de código, já que não é necessário escrever a mesma consulta várias vezes em diferentes partes do código.
-- Exemplo de execução: exec STP_ConsultaClientesData ‘2022-01-04’

/* Sintaxe para atualizar um procedimento armazenado 
ALTER PROCEDURE nome_procedure
(
    @nome_parametro1 tipo_dado,
    @nome_parametro2 tipo_dado,
    @nome_parametroN tipo_dado
)
AS
BEGIN
COMANDO SQL
END

  Sintaxe para exclusão de um procedimento armazenado
  DROP PROCEDURE nome_procedure
*/


-- Além dos procedimentos armazenados, que não retornam valor, o SQL Server permite, ainda, a criação de funções, cuja principal diferença dos procedimentos armazenados é:
-- Retornam valor
-- Podem ser utilizados como parte de consultas
-- Existem basicamente, dois tipos de funções criados por usuário, as que retornam um valor escalar e podem ser utilizadas na cláusula "SELECT" de consultas ou como parte da clpasula "WHERE" e as que retornam tabelas e podem ser utilizadas na cláusula "FROM" de consultas

/* Sintaxe função escalares
CREATE FUNCTION nome_função
(
    @parametro1 tipo1,
    @parametro2 tipo2,
    @parametron tipoN
)
RETURNS tipo_retorno
AS
BEGIN
Comandos
RETURN
END
*/

-- Exemplo 1
-- Função que retorne o código do cliente passando-se seu nome como parâmetro

CREATE FUNCTION fnc_CodigoCliente
(
    @nome varchar(50)
)

RETURNS int
AS
BEGIN
    declare @id INT
    set @id = (select ID_CLIENTE
    from Cliente
    where nome = @nome)
    RETURN @id
END
-- Uma vez executado o código acima, é criada a função fnc_CodigoCliente, que recebe o nome do cliente como parâmetro e retorna o seu código como número inteiro. Uma vez criada, pode ser utilizada como parte de uma consulta
select data
from venda
where idCliente = dbo.fnc_CodigoCliente('Weslley Marcelo')
-- A consulta que mosta a data do cliente fez uma determinada compra, cujo código foi retornado pela função


-- As funções que retornam tabela estão divididas em dois tipos, aquelas que não criam uma estrutura específica de retorno(funções inline) e aquelas que retornam uma estrutura de tabela específica, com a definição dos tipos de dados(funções multi-statement)

-- Exemplo de função inline
-- Retorna a quantidade de produtos comprado e valor total gasto com cada produto em uma determinada venda
CREATE FUNCTION fcn_ProdutosValores -- Cria uma nova função
(
@idVenda int -- Define um parâmetro de entrada, do tipo "int" e chamado "idVenda"
)
RETURNS table -- Especifica o tipo de retorno da função como uma tabela
AS RETURN (select v.ID_Venda, c.idProduto, p.descricao, c.quantidade,c.quantidade*p.valor as total
from venda v inner join contem c on v.ID_Venda = c.idVenda
inner join produto p on p.ID_Produto = c.idProduto
where v.ID_Venda = @idVenda)
-- Declara a tabela de retorno da função. A tabela terá cinco colunas: "ID_Venda", "idProduto", "descricao", "quantidade" e "total". A tabela é formada pela seleção de dados de três tabelas diferentes("venda", "contem" e "produto"), que são unidas usando a clpasula "inner join". A seleção de dados é filtrada pela condição "where v.ID_Venda = @idVenda", que limita os resultados apenas à venda especificada pelo parâmetro de entrada

-- A partir da execução do código acima, uma função chamada fcn_ProdutoValores é criada, recebe como parâmetro o ID da venda.
-- com isso a função criada pode ser utilizada na cláusula "FROM" de consultas mais complexas como:
select c.nome, v.data, p.*
from venda v inner join cliente c on v.idCliente = c.ID_Cliente inner join dbo.fnc_CodigoCliente(1) p on p.ID_Venda = v.ID_Venda


-- Exemplo função Multi-Statement
CREATE FUNCTION fcn_CidadesEstados
(
    @idPais int
)
RETURNS @CidadeEstado table
(
    idCidade int,
    nomeCidade varchar(100),
    idEstado int,
    nomeEstado varchar(100)
)
AS BEGIN
    insert into @CidadeEstado
    select c.ID_Cidade, c.nome, e.ID_Estado, e.nome
    from Estado e inner join cidade c on e.ID_Estado = c.idEstado
    where e.idPais = @idPais
    RETURN
END
-- A partir da execução do código de criação da função, pode-se utilizá-la como parte de uma clásula FROM, assim como acontece com a função do tipo inline.