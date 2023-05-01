/*  Modelo 1
    IF condição BEGIN
    comandoIF
    END
    ELSE IF condição BEGIN
    ComandoElseIF
    END
    ELSE BEGIN
    ComandoElse
    END
*/
declare @valor money -- Declara a variavel valor como tipo money
set @valor = 0.8 -- Atribui um valor para a variavel
if @valor < 1 begin -- Se valor for menor que 1, o bloco de código dentro do 'begin' será executado
			set @valor = @valor*1.05 -- Atribui um novo valor a variavel "valor"
	end -- Termina o bloco de comando, começado pelo begin
	else begin -- Executa o bloco de código dentro do "begin"
		set @valor = @valor*1.03 -- Atribui um novo valor a variavel "valor"
	end -- Termina o bloco de comando
select @valor as Valor -- Exibe o valor da variável "@valor" na tela renomeando a coluna como "Valor"


/*  Modelo 2
    WHILE condição BEGIN
    comando
    incrementa variável de controle
    END
*/

declare @num int, @i int -- Declara as variáveis @num e @i e seus tipos
set @num = 4 -- Atribui o valor 4 para a variável
set @i = 1 -- Atribui o valor 1 para a variável

while @i<=10 begin -- Enquanto a condição for verdadeira vai rodar o bloco de código do "begin"
	print cast(@num as varchar) + 'x' + cast(@i as varchar) + '=' + cast (@num*@i as varchar)
    -- A função cast tem como objetivo converter um tipo de dado para outro tipo de dado, nesse caso inteiro para varchar
    -- Impressão no console da expressão "@num x @i = @num*@i" no formato string 
	set @i=@i+1 -- Incrementa 1 na variavel "@i"
end -- Fim do laço while


/*  Modelo 3
    BEGIN TRY
    Comando passível de erro
    END TRY
    BEGIN CATCH
    Comando a ser executado caso ocorra erro
    END CATCH
*/
-- Dentro do CATCH, as funções para obter informações sobre o erro que causou desse blocl:
-- ERROR_NUMBER() - retorna o número do erro
-- ERROR_SEVERITY() - retorna a severidade do erro
-- ERROR_STATE() - retorna o número do estado do erro
-- ERROR_PROCEDURE() - retorna o nome do procedimento no qual o erro ocorreu
-- ERROR_LINE() - retorna o número de linha dentro da rotina que causou o erro
-- ERROR_MESSAGE() - retorna o texto completo da mensagem de erro

declare @num int, @den int, @res int
set @num = 4
set @den = 0
begin try -- Início do bloco "try" que trata possíveis erros durante a execução do código
	set @res = @num/@den -- Tentativa de realizar uma divisão por zero, o que irá gerar uma exceção
	print cast(@num as varchar) + '/' + cast(@den as varchar) + ' = ' + cast(@res as varchar) -- Caso a divisão seja realizada, exibe a operação com o resultado
end try -- Fim do bloco "try"
begin catch -- Início do bloco "catch" que trata as exceções geradas durante a execução do código
	print cast(ERROR_NUMBER() as varchar) + ' - ' + ERROR_MESSAGE()
    -- Caso haja uma exceção gerada no bloco "try", será exibido na tela o número do erro(ERRO_NUMBER()) e a mensagem correspondente(ERROR_MESSAGE())
end catch -- Fim do bloco "catch"

-- Além de utilizar o "print" para imprimir o erro, é possível fazer o lançamento do erro com o comando "THROW"
-- A instrução "THROW" possui 3 parâmetros, sendo:
-- erro_number: uma constante ou variável que represente a exceção. >= 50000 ou <= 2147483647. A definição desse número é de responsabilidade do usuário
-- message: uma cadeia de caracteres ou variável que descreve a exceção
-- state: uma constante ou variável entre 0 e 255 que indica o estado a ser associado à mensagem

declare @num int, @den int, @res int
set @num = 4
set @den = 0
begin try
	set @res = @num/@den
	print cast(@num as varchar) + '/' + cast(@den as varchar) + ' = ' + cast(@res as varchar)
end try
begin catch
	throw 50000, 'Erro de divisão por zero', 3
    -- Lança na tela uma exceção com o número 50000, a mensagem "Erro de divisão por zero", e o nível de severidade(Estado) 3
end catch
-- Esse código lança uma exceção do tipo "throw", é útil em situações em que é necessário tratar a exceção em um nível superior do código
