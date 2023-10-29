# 4 Pilares Fundamentais EHPA
## 1. Encapsulamento: 
Envolve a ideia de agrupados os dados(variáveis de instância) e os métodos que operam nesses dados em uma única unidade, chamada de classe. Permite controlar o acesso aos dados, definindo quais partes do código podem interagir com eles e quais não podem. O encapsulamento ajuda a manter a integridade dos dados e oculta os detalhes internos da implementação da classe
### `Resumo:` Ideia que os dados(atributos) e o comportamento(métodos) relacionandos a um objeto devem ser agrupados em uma única chamada.

## 2. Herança
Um mecanismo que permite criar uma nova classe(subclasse ou classe derivada) com base em uma classe existente(superclasse ou classe base). Isso permite reutilizar o código e estabelecer uma hierarquia de classes. A subclasse herda os membros(atributos e métodos) da superclasse e pode adicionar os próprios membros ou substituir os membros herdados, o que é conhecido como sobrescrita de métodos.
### `Resumo:` Permite que uma classe herde os atributos e métodos de outra classe.

## 3. Polimorfismo
Capacidade de uma classe base tratar objetos de suas subclasses de maneira uniforme. Isso é alcançado através da sobrescrita de métodos, onde uma subclasse pode fornecer sua própria implementação para um método que já foi definido na superclasse. Isso permite que diferentes objetos se comportem de maneira específica para suas respectivas classes, mesmo quando são referenciados por meio de uma referência à classe base.
### `Resumo:` Trata objetos de subclasse de forma uniforme usando sobrescrita de métodos, permitindo comportamentos específicos de classe.

## 4. Abstração
Envolve a simplificação de objetos do mundo real em modelos mais simples e representativos em código. Em java, isso é geralmente alcançado por meio da criação de classes abstratas e interfaces, que definem um conjunto de métodos sem fornecer uma implementação completa. Classes concretas derivadas dessas abstrações devem fornecer a implementação completa dos métodos. A abstração permite que você se concentre nos aspectos essencias de um objeto e oculta os detalhes desnecessários.
### `Resumo:` Simplificação de objetos em representações simplificadas nas classes, destacando apenas os detalhes relevantes.

# Média de Alunos
```java
import java.util.Scanner;

public class CalculaMedia {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Quantos alunos? ");
        int numeroAlunos = scanner.nextInt();
        
        double soma = 0.0;
        
        for(int i = 1; i <= numeroAlunos; i++) {
            System.out.print("Nota do aluno " + i + ": ");
            double nota = scanner.nextDouble();
            soma += nota;
        }
        
        double media = soma / numeroAlunos;
        System.out.println("Media: " + media);
    }
}
```

### O que é um objeto em Java?  
`a)` Uma variável  
`b)` Uma função  
`c)` Uma instância de uma classe  
`d)` Uma expressão condicional  
Resposta correta: c

### O que é uma classe em Java?  
`a)` Um objeto  
`b)` Um método  
`c)` Um tipo de dado primitivo  
`d)` Um modelo para criar objetos  
Resposta correta: d

### Qual é o objetivo do encapsulamento em Java?  
`a)` Permitir o acesso direto a variáveis de instância  
`b)` Ocultar detalhes da implementação e proteger os dados  
`c)` Acelerar o código-fonte  
`d)` Facilitar a herança  
Resposta correta: b

### O que é herança em Java?  
`a)` Um mecanismo para criar objetos  
`b)` Uma técnica para ocultar informações  
`c)` Um mecanismo que permite que uma classe derive de outra  
`d)` Um método para encapsular dados  
Resposta correta: c

### O que é polimorfismo em Java?  
`a)` A capacidade de ter muitos construtores em uma classe  
`b)` A capacidade de criar objetos a partir de uma interface  
`c)` A capacidade de tratar objetos de subclasses de forma uniforme  
`d)` A capacidade de dividir uma classe em várias subclasses  
Resposta correta: c

### Qual é a diferença entre sobrecarga (overloading) e sobreposição (overriding) de métodos em Java?
`a)` Sobrecarga é usada para criar construtores, e sobreposição é usada para   criar métodos.  
`b)` Sobrecarga é feita em tempo de compilação, e sobreposição é feita em tempo de execução.  
`c)` Sobrecarga envolve criar métodos com o mesmo nome em uma classe, mas com   parâmetros diferentes; sobreposição envolve substituir um método de uma superclasse em uma subclasse.    
`d)` Sobrecarga é usada em classes abstratas, e sobreposição é usada em classes concretas.  
Resposta correta: c

### O que é abstração em Java?  
`a)` Um conceito que não é aplicável a linguagens de programação.  
`b)` A capacidade de criar objetos a partir de classes concretas.  
`c)` O processo de simplificar objetos do mundo real em modelos de código.  
`d)` A capacidade de criar classes abstratas que não podem ser instanciadas.  
Resposta correta: c

### O que é uma classe abstrata em Java?  
`a)` Uma classe que não pode conter métodos abstratos.  
`b)` Uma classe que não pode ser estendida por outras classes.  
`c)` Uma classe que pode ser instanciada diretamente.  
`d)` Uma classe que pode conter métodos abstratos e não abstratos.  
Resposta correta: d

### Quais são as palavras-chave usadas para definir uma classe e seus métodos como públicos?  
`a)` public e class  
`b)` public e private  
`c)` class e void  
`d)` protected e static  
Resposta correta: a

### Qual é a diferença entre uma interface e uma classe abstrata em Java?
`a)` Uma classe abstrata pode conter métodos concretos, enquanto uma interface   não pode.  
`b)` Uma classe abstrata não pode ser estendida, enquanto uma interface pode.      
`c)` Uma interface pode conter variáveis de instância, enquanto uma classe abstrata não pode.    
`d)` Uma classe abstrata não pode conter métodos abstratos, enquanto uma interface   só pode conter métodos abstratos.  
Resposta correta: d

### O que é uma classe anônima em Java?  
`a)` Uma classe que não possui nome.  
`b)` Uma classe que é privada e oculta de outras classes.  
`c)` Uma classe que não pode ser estendida.  
`d)` Uma classe que não pode conter métodos.  
Resposta correta: a

### O que é o construtor em Java?  
`a)` Um método que retorna um valor.  
`b)` Um método usado para destruir objetos.  
`c)` Um método especial usado para inicializar objetos.  
`d)` Um método que deve ser estático.  
Resposta correta: c

### Qual é a palavra-chave usada para chamar o construtor da superclasse em uma subclasse?  
`a)` super()  
`b)` this()  
`c)` base()  
`d)` parent()  
Resposta correta: a

### Quando você deve usar a palavra-chave "final" em Java?
`a)` Para indicar que uma classe não pode ser estendida.    
`b)` Para indicar que um método não pode ser sobrescrito.  
`c)` Para indicar que uma variável de instância não pode ser modificada após sua  inicialização.  
`d)` Todas as opções acima.  
Resposta correta: d

### O que é a sobrecarga de construtores em Java?
`a)` Um erro de compilação.    
`b)` O ato de criar múltiplos construtores com diferentes parâmetros na mesma   classe.  
`c)` Uma maneira de evitar a criação de construtores.  
`d)` A necessidade de estender uma classe com vários construtores.  
Resposta correta: b

### O que é uma variável de instância em Java?  
`a)` Uma variável que é declarada com a palavra-chave "static".  
`b)` Uma variável que é compartilhada por todas as instâncias de uma classe.  
`c)` Uma variável que pertence a uma instância específica de uma classe.  
`d)` Uma variável que não pode ser acessada por nenhum método da classe.  
Resposta correta: c

### O que é a palavra-chave "this" em Java usada para?  
`a)` Para referenciar o objeto atual ou a instância atual da classe.  
`b)` Para criar um novo objeto.  
`c)` Para chamar um método de outra classe.  
`d)` Para declarar uma variável local.  
Resposta correta: a

### O que é o garbage collector em Java?
`a)` Um tipo de coletor de lixo que recicla o plástico.    
`b)` Um mecanismo automático que gerencia a memória, liberando objetos não   utilizados.  
`c)` Um construtor especial usado para criar objetos temporários.  
`d)` Um mecanismo que impede vazamentos de memória.  
Resposta correta: b

### O que é a serialização de objetos em Java?
`a)` A transformação de objetos em séries de números inteiros.  
`b)` O processo de tornar um objeto persistente para armazenamento ou   transmissão.  
`c)` A capacidade de um objeto se comportar de maneira diferente em diferentes   situações.  
`d)` A etapa final no ciclo de vida de um objeto.  
Resposta correta: b

### Quando ocorre a instanciação de um objeto em Java?  
`a)` Durante a compilação.  
`b)` Durante a execução, quando o construtor é chamado.  
`c)` Quando um objeto é declarado, mas antes de seu construtor ser chamado.  
`d)` Sempre que a palavra-chave "new" é usada.  
Resposta correta: b

## Conceitos de Programação Orientada a Objetos:

### O que é Programação Orientada a Objetos (POO)?
`a)` Um estilo de programação que se concentra em funções.  
`b)` Um paradigma de programação que se concentra em objetos e suas interações.  
`c)` Uma linguagem de programação específica.  
`d)` Um sistema operacional.  
Resposta correta: b

### O que é um objeto em POO?
`a)` Um método.  
`b)` Uma variável.  
`c)` Uma instância de uma classe.  
`d)` Um tipo primitivo.  
Resposta correta: c

## Implementação de Atributos e Métodos:

### Como você declara um atributo em uma classe Java?
`a)` Usando a palavra-chave attribute.  
`b)` Usando a palavra-chave field.  
`c)` Usando a palavra-chave variable.  
`d)` Usando a palavra-chave class.  
Resposta correta: b

### Como você declara um método em uma classe Java?
`a)` Usando a palavra-chave function.  
`b)` Usando a palavra-chave method.  
`c)` Usando a palavra-chave operation.  
`d)` Usando a palavra-chave public.  
Resposta correta: b

## Herança:

### O que é a superclasse em herança?
`a)` A classe que herda os membros de outras classes.  
`b)` A classe que é derivada de outras classes.  
`c)` A classe base da hierarquia de herança.  
`d)` A classe mais complexa.  
Resposta correta: c

### Quais são as palavras-chave em Java para estender uma classe?
`a)` expand e extends.  
`b)` inherit e from.  
`c)` super e class.  
`d)` extends e implements.  
Resposta correta: d

## Encapsulamento:

### Por que o encapsulamento é importante na POO?
`a)` Para tornar o código mais complicado.  
`b)` Para tornar os objetos inacessíveis.  
`c)` Para proteger os detalhes da implementação e controlar o acesso aos dados.  
`d)` Para acelerar o tempo de execução.  
Resposta correta: c

### Quais são os níveis de acesso (modificadores) em Java usados para controlar o encapsulamento?
`a)` Público, privado e protegido.  
`b)` Estático, final e abstrato.  
`c)` Local, global e privado.  
`d)` Atributos, métodos e construtores.  
Resposta correta: a

## Abstração:

### O que é abstração em POO?
`a)` Um processo para complicar objetos do mundo real em modelos de código.  
`b)` Uma técnica para ocultar os objetos.  
`c)` A representação de objetos do mundo real em modelos simplificados no código.  
`d)` Uma técnica para acelerar a execução de programas.  
Resposta correta: c

### O que são classes abstratas em Java?
`a)` Classes que não podem ser instanciadas.  
`b)` Classes que não podem ter atributos.  
`c)` Classes que não podem ter métodos abstratos.  
`d)` Classes que não podem ser estendidas.  
Resposta correta: a

## Instanciação e Destruição de Objetos:

### Quando um objeto é instanciado em Java?
`a)` Durante a compilação.  
`b)` Durante a execução, quando o construtor é chamado.  
`c)` Quando a palavra-chave "new" é usada.  
`d)` Ao declarar a classe.  
Resposta correta: b

### O que é o garbage collector em Java?
`a)` Um mecanismo que coleta lixo nas ruas.  
`b)` Um mecanismo automático que gerencia a memória, liberando objetos não utilizados.  
`c)` Um construtor especial usado para criar objetos temporários.  
`d)` Um mecanismo para forçar a coleta de lixo.  
Resposta correta: b

## Overload e Override:

### O que é o sobrecarga (overloading) de métodos em Java?
`a)` Um erro de compilação.  
`b)` A prática de criar métodos com o mesmo nome, mas com diferentes parâmetros na mesma classe.  
`c)` A necessidade de criar um método com o mesmo nome em diferentes classes.  
`d)` A criação de métodos que não possuem nome.  
Resposta correta: b

### O que é a sobreposição (overriding) de métodos em Java?
`a)` Um erro de compilação.  
`b)` A capacidade de criar um novo método na classe derivada.  
`c)` A substituição de um método da superclasse em uma subclasse com uma implementação diferente.  
`d)` A criação de métodos que não estão relacionados entre si.  
Resposta correta: c