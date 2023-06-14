/*/**/
-- FUNÇÃO PARA TRATAR OS NOMES TENDO A PRIMEIRA LETRA MAIÚSCULA
CREATE FUNCTION TratarNome (
    @Nome VARCHAR(100)
)
RETURNS VARCHAR(100)
AS
BEGIN
    DECLARE @NomeTratado VARCHAR(100)
    
    SET @NomeTratado = LOWER(@Nome)
    SET @NomeTratado = UPPER(LEFT(@NomeTratado, 1)) + SUBSTRING(@NomeTratado, 2, LEN(@NomeTratado))
    
    RETURN @NomeTratado
END

-- EXEMPLOS DE USO

SELECT dbo.TratarNome('silvio') AS NomeTratado
-- Resultado: Silvio

SELECT dbo.TratarNome('JOAO') AS NomeTratado
-- Resultado: Joao

SELECT dbo.TratarNome('wESllEy') AS NomeTratado
-- Resultado: Weslley
