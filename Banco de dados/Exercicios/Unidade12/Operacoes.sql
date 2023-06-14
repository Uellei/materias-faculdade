/*/**/-- FUNÇÃO PARA CALCULAR AS 4 OPERAÇÕES FUNDAMENTAIS + EXPONENCIAÇÃO + RAIZ QUADRADA

CREATE FUNCTION Calculadora(
    @Operacao VARCHAR(10),
    @Numero1 DECIMAL(10, 2),
    @Numero2 DECIMAL(10, 2)
)
RETURNS DECIMAL(10, 2)
AS
BEGIN
    DECLARE @Resultado DECIMAL(10, 2)

    IF @Operacao = 'Adicao'
        SET @Resultado = @Numero1 + @Numero2
    ELSE IF @Operacao = 'Subtracao'
        SET @Resultado = @Numero1 - @Numero2
    ELSE IF @Operacao = 'Multiplicacao'
        SET @Resultado = @Numero1 * @Numero2
    ELSE IF @Operacao = 'Divisao'
        SET @Resultado = @Numero1 / @Numero2
    ELSE IF @Operacao = 'Exponenciacao'
        SET @Resultado = POWER(@Numero1, @Numero2)
    ELSE IF @Operacao = 'RaizQuadrada'
        SET @Resultado = SQRT(@Numero1)
    
    RETURN @Resultado
END

-- EXEMPLOS DE USO

SELECT dbo.Calculadora('Adicao', 5, 3) AS Soma
-- Resultado: 8

SELECT dbo.Calculadora('Multiplicacao', 4, 2) AS Multiplicacao
-- Resultado: 8


Aqui está um exemplo de uma função em SQL Server que realiza as quatro operações fundamentais (adição, subtração, multiplicação, divisão), exponenciação e raiz quadrada:

sql
Copy code
CREATE FUNCTION Calculadora(
    @Operacao VARCHAR(10),
    @Numero1 DECIMAL(10, 2),
    @Numero2 DECIMAL(10, 2)
)
RETURNS DECIMAL(10, 2)
AS
BEGIN
    DECLARE @Resultado DECIMAL(10, 2)

    IF @Operacao = 'Adicao'
        SET @Resultado = @Numero1 + @Numero2
    ELSE IF @Operacao = 'Subtracao'
        SET @Resultado = @Numero1 - @Numero2
    ELSE IF @Operacao = 'Multiplicacao'
        SET @Resultado = @Numero1 * @Numero2
    ELSE IF @Operacao = 'Divisao'
        SET @Resultado = @Numero1 / @Numero2
    ELSE IF @Operacao = 'Exponenciacao'
        SET @Resultado = POWER(@Numero1, @Numero2)
    ELSE IF @Operacao = 'RaizQuadrada'
        SET @Resultado = SQRT(@Numero1)
    
    RETURN @Resultado
END
Você pode usar essa função passando o tipo de operação desejada ('Adicao', 'Subtracao', 'Multiplicacao', 'Divisao', 'Exponenciacao' ou 'RaizQuadrada') e os números em que a operação será aplicada. A função retornará o resultado correspondente.

Exemplo de uso:

sql
Copy code
SELECT dbo.Calculadora('Adicao', 5, 3) AS Soma
-- Resultado: 8

SELECT dbo.Calculadora('Multiplicacao', 4, 2) AS Multiplicacao
-- Resultado: 8

SELECT dbo.Calculadora('RaizQuadrada', 16, NULL) AS RaizQuadrada
-- Resultado: 4