# Arduino02

- // : Comentario de uma linha.
- /**/ : Comentario de várias linhas.

// esse é um con

/*
Piscar um Ler
Esse é nosso primeiro código
*/

- funções: setup e loop
- setup: código de configuração, a funçã osetup é executa um vez
- loop: é sempre executado, repetido

-pinMode: configura uma porta como entrada ou saída.
ex: pinMode(13, OUTPUT);
- digitalWrite: libera tensão para uma porta, sendo HIGH ou 1 liberar a tensão de 5V e LOW ou 0 apra cortar a tensão. Ex: digitalWrite(13, 1);
- delay: realiza a pausa no código por determinado tempo. Ex: delay(2000);

## Variáveis
Espaço na memória para guardar uma determinada informação
O contéudo da variável pode variar.
Toda variável possui um tipo.
Tipo da variável é a caracterisca da informação que a variável pode armazenar.

### Tipos de variáveis
- int: número inteiro. Ex: 10
- float: número decimal. Ex: 10.5
- char: um caractere. Ex: A
- string: sequência de caracteres. Ex: Aline
- boolean: vardadeiro (1) ouflaso (0). Ex true
- void: tipo vazio, não tipo
Ex. int tempo = 1000;

## Constante
Um espaço reservado na memória com um valor definido onde esse valor será imutável.
Ex: #define ledVermelho 13