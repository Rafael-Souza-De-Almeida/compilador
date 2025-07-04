Compilador Hahaha
Este documento descreve o compilador desenvolvido utilizando as ferramentas Yacc/Bison. Ele é capaz de processar e executar código escrito em uma linguagem de programação personalizada, demonstrando funcionalidades como controle de fluxo, manipulação de strings, subprogramas e vinculação dinâmica de tipos.

Como Rodar o Compilador
Para compilar e executar um programa com este compilador, siga os passos abaixo:

Crie o arquivo de código: Escreva seu código na linguagem do compilador e salve-o com a extensão .hahaha. Por exemplo: meu_programa.hahaha. Não se esqueça de referenciá-lo no arquivo make.

Execute o comando make: No terminal, navegue até o diretório onde o compilador e seu arquivo .hahaha estão localizados e execute o comando make. Este comando se encarregará de compilar o compilador (se necessário) e executar o seu programa.

make


Exemplos de Código
A seguir, são apresentados diversos exemplos de código que demonstram as capacidades do compilador. Você pode usar esses exemplos para testar as funcionalidades.

1. Laço for Simples
Este exemplo demonstra um laço for básico que itera de 0 a 9, imprimindo o valor de i em cada iteração.

function main() {
  for(i = 0; i < 10; i++) {
    i;
  }
}


2. Manipulação de String
Este exemplo mostra a declaração e o uso de uma variável do tipo string.

function main() {
a = "Essa é a disciplina de compiladores";
a;
}


3. String com Entrada Padrão (stdin)
Este exemplo ilustra como ler uma string da entrada padrão (stdin) usando a função type().

function main() {
string type(x);
x;
}


4. Controle de Laço (continue e break)
Este exemplo demonstra o uso das instruções continue e break dentro de um laço for para controlar o fluxo de execução.

function main() {
for(i = 0; i < 10; i++) {
  if(i == 2){
    continue;
  }
   i;
  if(i == 5){
    break;
  }
}
}


5. Subprogramas (Funções)
Este exemplo mostra a definição e chamada de uma função (foo()) e a realização de operações aritméticas básicas.

function foo() {
  a = "Olá mundo!";
  a;
}

function main() {
a = 20;
b = 40.5;
c = a + b;
foo();
c;
}


6. Operadores Unários e Compostos
Este exemplo demonstra o uso de operadores unários de incremento (++) e decremento (--), bem como operadores de atribuição composta (+=, -=).

function main() {
a = 10;
b = 20;
c = 40;
d = 15;

a++;
b--;

c += 10;
d -= 10;

a;
b;
c;
d;
}


7. Laço foreach (Sintaxe Simplificada)
Este exemplo apresenta uma sintaxe de laço similar ao foreach, iterando sobre um intervalo numérico.

function main() {
for i = 0:10 {
  i;
}
}


8. Vinculação Dinâmica de Tipos
Este exemplo ilustra a capacidade do compilador de lidar com vinculação dinâmica de tipos, onde uma variável pode ter seu tipo alterado várias vezes.

function main() {
a = 10;
a = "rafael";
b = a + " " + "souza";
b;
}


9. break all (Saída de Laços Aninhados)
Este exemplo demonstra a instrução break all, que permite sair de múltiplos laços aninhados de uma só vez.

function main() {
b = 30;
for(i = 0; i < 20; i++) {
  a = "primeiro for";
  a;
  for(j = 0; j < 10; j++) {
    local b = "segundo for";
    b;
    if(j == 1){
      break all;
    }
  }
}
  b;
}


10. Operador Ternário
Este exemplo mostra o uso do operador condicional ternário para atribuição de valores baseada em uma condição.

function main() {
  a = 30;
  b = 20;
  g = true;

  c = (a < 20) ? "A é menor que 20" : "A é maior que 20";
  c;

  d = (b > 10) ? "B é maior que 10" : "B é menor que 10";
  d;

  f = g ? 1 : 0;
  f;
}


🛠 Requisitos
Para compilar e executar o compilador, você precisará das seguintes ferramentas:

Flex

Bison

GCC

Make

🧠 Funcionalidades Suportadas
O compilador suporta as seguintes funcionalidades:

Vinculação dinâmica de tipos: Suporte para tipos inteiro, float, string e booleano.

Laços: Implementação de laços for,foreach, while, do-while.

Controle de fluxo: Instruções if, else, break, continue e break all.

Subprogramas: Definição e chamada de funções (function).

Operações aritméticas e lógicas: Suporte para diversas operações.

Entrada padrão: Leitura de dados da entrada padrão (ex: string type(x)).

Operadores unários e compostos: Operadores como ++, --, +=, -=.

Ternário: Operador condicional ternário (cond ? valor1 : valor2).

📄 Licença
Este é um projeto acadêmico sem fins lucrativos. Desenvolvido com dedicação e paixão por compiladores. ❤️
