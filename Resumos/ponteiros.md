# Ponteiros
## O que é?
  Um ponteiro é uma variável que guarda um **endereço de memória** de outra variável, sendo possível "apontá-la", ou seja, se referir a   ela quando utilizado. Foram abolidos de outras linguagens, mas são um recurso poderoso para àquelas que os permitem, pois manipulam diretamente a memória do computador.
  Utilizamos ponteiros de duas formas:
  1. Referência: obtemos o endereço de memória em si.
  2. Deferência: nos referimos ao conteúdo deste endereço, para isso, utilizamos o indicador * junto ao nome da variável ponteiro.¹
  
 ## Quando utilizar?
  O ponteiro é muito útil quando queremos apontar para outras variáveis em diferentes locais de um programa, sendo mais fácil e rápido do que uma referência por valor, por exemplo. 
  Apesar de ser ótimo recurso, exige um cuidado especial, pois erros de lógica ao mexer com memória podem causar crash ou erro fatal no programa.¹
## Vantagens:
- Alteração indireta do conteúdo de variáveis para qualquer lugar do programa;
- É muito utilizado em processos comuns e úteis como alocação dinâmica;
- Melhor desempenho do programa.²
> Alocação dinâmica é um recurso que possibilita reservar a memória do computador em tempo de execução, permitindo assim que o programador manipule o quanto usa, evitando desperdícios ou erros por falta de memória.³
## Desvantagens:
- Acesso direto a memória te permite fazer coisas que não deveria, como substituir a memória crítica, modificar o código de um aplicativo em execução , ou fazer com que seu aplicativo ou de outro aplicativo se comportar ou sair inesperadamente.
- Ponteiros são confusos e precisam de muita prática para o aprendizado e utilização correta.²

## Como implementar?
 1. Declaramos o ponteiro com o tipo da variável que ele aponta e usamos o caracter '*' para a referência:
 ```c++
 int *ponteiro;
```
2. Atribuimos o endereço de memória a ele através do caracter '&':
```c++
int *ponteiro;
int a = 3;
ponteiro = &a;
```
3. Podemos também passar um ponteiro como parâmetro pra uma função, assim modificamos a variável para a qual ele aponta:
```c++
void func (int *ponteiro){ 
  *ponteiro = 5;
}

int main(){ 
int a = 3;
func(&a);
cout << a;

return 0;
}
```
*Nesse caso, a saída será 5, pois modificamos "a" pelo seu endereço de memória.*

4. Podemos também utilizar um ponteiro para apontar para outro ponteiro, como no caso da declaração para uma matriz de inteiros:
```c++
int **ponteiro;
```
Por fim, ponteiros são utilizados para vários objetivos e funcionam com funções, vetores, classes, e diversas estruturas possibilitando maior flexibilidade para execução e alteração das aplicações.³

> [Referência Bibliográfica 1](http://www.tiexpert.net/programacao/c/ponteiros.php)

> [Referência Bibliográfica 2](http://ptcomputador.com/P/computer-programming-languages/88721.html)

> [Referência Bibliográfica 3](https://www.embarcados.com.br/ponteiro-em-c-alocacao-dinamica/)
