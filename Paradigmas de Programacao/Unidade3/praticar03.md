# Estudo Comparativo entre Linguagens de Programação.
O objetivo é avaliar três critérios fundamentais - `Legibilidade`, `Facilidade de Escrita` e `Confiabilidade` - para auxiliar na compreensão das vantagens e desvantagens dessas linguagens no contexto do desenvolvimento de software
## 1. Legibilidade
### 1.1 Simplicidade Geral
- `Julia:` Sua sintaxe é limpa e semelhante a outras linguagens de programação como Python e MATLAB, facilitando a compreensão do código.
- `Python:` A legibildiade do python é uma das suas características marcantes, graças a sua ênfase na clareza e no uso de identação para definir blocos de código.
```julia
# Julia
function somar(a, b)
    return a + b
end
```
```py
# Python
def somar(a, b):
    return a + b
```
### 1.2 Ortogonalidade
- `Julia:` Altamente ortogonal, o que significa que as operações são consistentes e previsíveis, realiza a verificação de tipos em tempo de compilação, ajudando a evitar erros de ortogonalidade.
- `Python`: Também é ortogonal, garantindo a consistências nas operações, realiza verificação de tipos em tempo de execução.
```julia
a = 20
b = "W"
c = a + b # Resultaria em um erro do tipo em tempo de compilação
```
```py
a = 20
b = "W"
c = a + b # Resultaria em um erro do tipo em tempo de execução
```
### 1.3 Instruções de Controle
- `Julia:` Oferece estruturas de controle de fluxo familiares, como `if`, `else`, `for` e `while`.
- `Python`: Possui instruções de controle de fluxo claras e concisas, bem semelhante a Julia.
```julia
for i in 1:5
    println(i)
end
```
```py
for i in range(1,6):
    print(i)
```
### 1.4 Tipo de Dados e Estruturas
- `Julia:` Permite a definição de tipos de dados personalizados e oferece suporte a estruturas de dados eficientes, o que pode facilitar a organização do código.
- `Python:` Possui uma ampla gama de estruturas de dados integradas, o que torna a manipulação de dados mais conveniente. No entando, não é tão flexível quanto Julia para definição de tipos de dados personalizados.
```julia
type Pessoa
    nome:: String
    idade:: Int
end

p1 = Pessoa("Waldemar", 20)
```
```py
class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

p1 = Pessoa("Weslley", 20)
```
### 1.5 Sintaxe
- `Julia:` É concisa e intuitiva, tornando o código fácil de entender. A ênfase na vetorização também pode melhorar a legibilidade.
- `Python:` É conhecido por sua sintaxe clara e legível, tornando-a uma escolha popular para iniciantes e desenvolvedores experientes.
```julia
function multiplicar(a::Int, b::Int)
    return a * b
end
```
```py
def multiplicar(a: int, b: int) -> int:
    return a * b
```

## 2. Facilidade de Escrita
### 2.1 Simplicidade e Ortogonalidade
Exemplos no 1.1, 1.2 e 1.5

### 2.2 Suporte para Abstração
- `Julia:` Suporta a abstração de alto nível, tornando-o adequado para desenvolvimento de software de alto desempenho e científico.
- `Python:` Altamente abstrato, com libs extensivas para várias tarefas, o que facilita o desenvolvimento rápido de software
```julia
# abordagem baseada em tipos abstratos
abstract type Animal end

struct Cachorro <: Animal
    nome:: String
end

struct Gato <: Animal
    nome:: String
end
```
```py
# Usa abordagem baseada em classes
from abc import ABC, abstractmethod

class Animal(ABC):
    def __init__(self, nome):
        this.nome = nome

class Cachorro(Animal):
    pass

class Gato(Animal):
    pass
```
### 2.3 Expressividade
- `Julia:` Julia é altamente expressiva, permitindo que os desenvolvedores expressem ideias complexas em código de forma clara e concisa.
- `Python:` Python também é altamente expressiva, tornando-o adequado para prototipagem rápida e desenvolvimento ágil.

## 3. Confiabildiade
### 3.1 Verificação de Tipos
- `Julia:` Possui um sistema de tipos sólido, que pode detectar erros de tipos em tempo de compilação, aumentando a conficabilidade do código.
- `Python:` Python é dinamicamente tipado, o que significa que a verificação de tipos ocorre em tempo de execução, tornando-o menos rígido em termos de segurança de tipos.

### 3.2 Manipulação de Exceções
- `Julia:` Oferece suporte completo para manipulação de exceções, permitindo que os desenvolvedores lidem com erros de forma eficaz.
- `Python:` Também possui um sistema robusto de manipulação de exceções, facilitando o tratamento de erros.
```julia
function dividir(a,b)
    try
        return a / b
    catch e
        println("Erro: ", e)
    end
end
```
```py
def dividir(a,b):
    try:
        return a / b
    except Exception as e:
        print("Erro: ", e)
```
### 3.3 Aliasing
- `Julia:` Oferece controle sobre o aliasing, permitindo que os desenvolvedores gerenciem efetivamente referências a objetos compartilhados.
- `Python:` Também permite aliasing, mas pode ser necessário ter cuidado ao lidas com objetos mutáveis compartilhados.
```julia
a = [1, 2, 3]
b = a
b[1] = 99
println(a) # Imprime [99, 2, 3]
```
```py
a = [1, 2, 3]
b = a
b[0] = 99
print(a) # Imprime [99, 2, 3]
```