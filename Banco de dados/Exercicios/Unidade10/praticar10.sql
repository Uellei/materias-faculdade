/*/**/
/*Exercício 1*/
create function fn_cpf
(
	@cpf_sem_formato varchar(11)
)
	returns varchar(14)
begin
	declare @cpf varchar(14)
	set @cpf = ''
	set @cpf = concat(@cpf, substring(@cpf_sem_formato,1,3)) -- Pega o cpf até então '' e concatena com os tres primeiros números do cpf sem formato XXX
	set @cpf = concat(@cpf, '-') -- Adiciona um - dps dos tres numeros, fica XXX-
	set @cpf = concat(@cpf, substring(@cpf_sem_formato,4,3)) -- Concatena os proximos 3 números do cpf sem formato, XXX-XXX
	set @cpf = concat(@cpf, '-') -- Concatena um -, XXX-XXX-
	set @cpf = concat(@cpf, substring(@cpf_sem_formato,7,3)) -- Concatena os proximos 3 números do cpf sem formato, XXX-XXX-XXX
	set @cpf = concat(@cpf, '-') -- Concatena um -, XXX-XXX-XXX-
	set @cpf = concat(@cpf, substring(@cpf_sem_formato,10,2)) -- Concatena os últimos 2 números do cpf sem formato, XXX-XXX-XXX-XX
	return @cpf -- Retorna o cpf formatado
end

-- Exercício 2
create function confere_email
(
	@email varchar(100)
)
	returns varchar(10)
as
begin
	declare @confere varchar(10)
	if CHARINDEX('@', @email) > 1 and (RIGHT(@email, 4) = '.com' or RIGHT(@email, 7) = '.com.br')
		set @confere = 'Válido'
	else
		set @confere = 'Inválido'

	return @confere
end