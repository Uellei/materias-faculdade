/*/**/

-- FORMATA UM CPF SEM FORMATAÇÃO
CREATE FUNCTION Trata_CPF
(
	@cpf_sem_formato VARCHAR(11)
)
	RETURNS VARCHAR(14)
BEGIN
	DECLARE @cpf VARCHAR(14)
	SET @cpf = ''
	SET @cpf = concat(@cpf, substring(@cpf_sem_formato,1,3)) -- Pega o cpf até então '' e concatena com os tres primeiros números do cpf sem formato XXX
	SET @cpf = concat(@cpf, '-') -- Adiciona um - dps dos tres numeros, fica XXX-
	SET @cpf = concat(@cpf, substring(@cpf_sem_formato,4,3)) -- Concatena os proximos 3 números do cpf sem formato, XXX-XXX
	SET @cpf = concat(@cpf, '-') -- Concatena um -, XXX-XXX-
	SET @cpf = concat(@cpf, substring(@cpf_sem_formato,7,3)) -- Concatena os proximos 3 números do cpf sem formato, XXX-XXX-XXX
	SET @cpf = concat(@cpf, '-') -- Concatena um -, XXX-XXX-XXX-
	SET @cpf = concat(@cpf, substring(@cpf_sem_formato,10,2)) -- Concatena os últimos 2 números do cpf sem formato, XXX-XXX-XXX-XX
	RETURN @cpf -- Retorna o cpf formatado
END

-- EXEMPLO DE USO

SELECT dbo.Trata_CPF('12345678912') as CPF
-- Resultado: 123.456.789-12