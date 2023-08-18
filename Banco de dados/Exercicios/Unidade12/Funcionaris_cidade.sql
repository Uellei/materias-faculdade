/*/**/
-- CONTA A QUANTIDADES DE FUNCIONARIS EM UMA RESPECTIVA CIDADE
CREATE FUNCTION ContarFuncionariosPorCidade (
    @NomeCidade VARCHAR(100)
)
RETURNS INT
AS
BEGIN
    DECLARE @QuantidadeFuncionarios INT

    SELECT @QuantidadeFuncionarios = COUNT(*)
    FROM Funcionario
    WHERE Cidade = @NomeCidade

    RETURN @QuantidadeFuncionarios
END

-- EXEMPLO DE USO

SELECT dbo.ContarFuncionariosPorCidade('São Paulo') AS QuantidadeFuncionarios
-- Resultado: quantidade de funcionários da cidade de São Paulo


SELECT dbo.ContarFuncionariosPorCidade('Belo Horizonte') AS QuantidadeFuncionarios
-- Resultado: quantidade de funcionários da cidade do Rio de Janeiro