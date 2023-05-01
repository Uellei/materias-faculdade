/*
-- Funções Nativas do Sistema de Gerenciamento de Banco de Dados(SGBD)
-- Funções personalizadas do SGBD

/*ASCII: retorna o valor do código da tabela ASCII do caractere mais à esquerda de uma expressão.*/
select ascii('A') as maiuscula,
ascii('a') as minuscula
-- CHAR: retorna o caractere equivalente ao código ascii passado como parâmetro.
-- CHARINDEX: retorna à posição inicial de uma string em outra. Recebe três parâmetros: os caracteres que serão procurados, a string onde a busca será realizada e a posição inicial da busca
-- LEFT e RIGHT: retornam a parte esquerda e direita, respectivamente, de uma string. O segundo argumento é o número de caracteres que deve ser retornado.
-- LEN - retorna o número de caracteres de uma string.
-- LTRIM E RTRIM: removem os espaçoes em branco da esquerda ou direita da string, respectivamente. Ou simplesmente usar a função TRIM.
-- REPLACE: substitui todas as ocorrências de uma string em outra. Recebe três parâmetros: a string que a busca deverá ser realizada; a string que se quer encontrar e a string que deve ser utilizada na substituição.
-- REPLICATE: repete uma string um certo número de vezes.
-- SUBSTRING: retorna parte de uma string. Recebe três parâmetros: A string da qual se quer retornas parte; a posição inicial e o número de caracteres.
-- GETDATE: retorna a data e a hora atual do servidor.
-- DATTEPART: retorna parte específica(datepart) de uma data específica
/*  datepart    | Abreviações
    year        | yy, yyyy
    quarter     | qq, q
    month       | mm, m
    dayofyear   | dy, y
    day         | dd, d
    week        | wk, ww
    weekday|    | dw
    hour        | hh
    minute      | mi, n
    second      | ss, s
    rnillisecond| ms
    microsecond | mcs
    nanosecond  | ns
    tzoffset    | tz
    iso_week    | isowk, isoww
*/
-- Exemplo de uso
select getdate() as data, datepart(year, getdate()) as ano,
datepart(month, getdate()) as mes, datepart(day, getdate()) as dia,
datepart(hour, getdate()) as hora, datepart(minute, getdate()) as minutos

-- DATEADD: adiciona um intervalo à data passada como parâmetro. Recebe três argumentos: a parte da data a ser icrementada(DatePart), o incremento e a data alvo.
-- Exemplo para adicionar um dia à data atual
Select dateadd(day, 1, getdate()) as dataMaisDia

-- DATADIFF: retorna a diferença entre duas datas. Recebe três parâmetros: a parte da data(DatePart), a data inicial e a data final.
-- Exemplo para saber quantos dias se passaram desde 01 de janeiro de 2022 até a data atual
Select datediff(day, '2022-01-01', getdate()) as dias

-- POWER: calcula a potência(primeiro parâmetro elevado ao segundo parâmetro).
-- ABS: retorna o valor absoluto de uma expressão
-- SQRT: calcula a raiz quadrada do número passado como parâmetro.
-- FLOOR: retorna o menor valor inteiro da expressão passada como parâmetro.
-- ISNULL: substitui o valor nulo pelo valor especificado como segundo parâmetro.
-- ISDATE: retorna 1 cada uma expressão seja uma data válida ou 0 caso contrário.
-- CAST: faz uma conversão entre tipos de dados. 

-- Exemplo
-- Função que receba tipo de operação, e dois numeros operando.
create function fn_operacoes
(
	@tipo_de_operacao int,
	@n1 int,
	@n2 int
)
	returns int
begin
	declare @resultado int
	if @tipo_de_operacao = 1 set @resultado = @n1+@n2
	if @tipo_de_operacao = 2 set @resultado = @n1-@n2
	if @tipo_de_operacao = 3 set @resultado = @n1*@n2
	if @tipo_de_operacao = 4 set @resultado = @n1/@n2
	if @tipo_de_operacao = 5 set @resultado = POWER(@n1,@n2)
	if @tipo_de_operacao = 6 set @resultado = SQRT(@n1)
	return @resultado
end

-- Exemplo 
-- Função que recebe um cpf sem formatação com 11 digitos e retorna no formato XXX-XXX-XXX-XX
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