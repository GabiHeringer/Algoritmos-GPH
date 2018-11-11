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

## Funcionalidades:
 1. Declaramos o ponteiro com o tipo da variável que ele aponta e usamos o caracter '*' para a referência:
 ```c++
 int *ponteiro;
```
2. Atribuindo o endereço de memória a ele através do caracter '&' e imprimindo este endereço:
```c++
int main(){
  int *ponteiro;
  int a = 3;
  ponteiro = &a;
  cout << ponteiro;
  
  return 0
}
```
*Neste caso, a saída será um número na base hexadecimal, que representa o endereço onde a variável a está na memória.*

3. Imprimindo na tela o conteúdo do ponteiro através do caracter '*':
```c++
int main(){
  int *ponteiro;
  int a = 3;
  ponteiro = &a;
  cout << *ponteiro;
  
  return 0
}
```
*Neste caso, a saída será 3, conteúdo da variável a qual o ponteiro aponta.*

4. Podemos também passar um ponteiro como parâmetro para uma função, assim modificamos a variável para a qual ele aponta:
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
*Neste caso, a saída será 5, pois modificamos "a" pelo seu endereço de memória.*

5. Ponteiros são utilizados com arrays (vetores). Eles são criados e apontam para o primeiro elemento do vetor: (³)
```c++
int main()
{
    int *ponteiro;
    int vetor[5] = {1,2,3,4,5};
    ponteiro = vetor;
    cout << *ponteiro;
    return 0;
}
```
*Aqui, a saída será 1, conteúdo do primeiro elemento do vetor.*

- Para andar pelo vetor e obter seus outros elementos, podemos usar um recurso chamado incremento de ponteiros, que consiste em utilizar os operadores ++/-- com o ponteiro, ou somá-los a números, para que ele alterne o endereço em que aponta para o próximo elemento ou anterior do vetor:
```c++
int main()
{
    int *ponteiro;
    int vetor[5] = {1,2,3,4,5};
    ponteiro = vetor;
    ponteiro++;
    cout << *ponteiro;
    return 0;
}
```
*Neste, a saída será 2, correspondendo ao segundo elemento do vetor.*

6. Ponteiros para funções: (³)
- Um recurso dos ponteiros é fazê-los apontar para funções, pois elas também tem um endereço fixo. Isto pode ser utilizado para uma certa optimização do código, como receber uma função como parâmetro para outra função.
- A declaração é feita através do corpo: tipo_da_função (*ponteiro)(tipo_do_parâmetro), onde o tipo da função é o tipo que ela retorna, e o tipo do parâmetro é o tipo que ela recebe. 

```c++
void soma (int *n){
    *n += 8;
}

void subtrai (int *n){
    *n -= 8;
}

int modifica_numero (void (*func)(int*), int n){ 
    func(&n);
    return n;
}
int main()
{
    int n = 0, m;
    m = modifica_numero(soma, n);
    cout << m;
    return 0;
}
```
*Aqui o usuário escolheria que tipo de modificação a função modifica_numero faria (soma ou subtrai), sem a necessidade de criá-la duas vezes.*

7. Podemos também utilizar um ponteiro para apontar para outro ponteiro, como no caso da declaração para uma matriz de inteiros:
```c++
int **ponteiro;
```
Por fim, ponteiros são utilizados para vários objetivos e funcionam com funções, vetores, classes, e diversas estruturas possibilitando maior flexibilidade para execução e alteração das aplicações.³

> William Xavier, Denys. Ponteiros. TI Expert. Disponível em: <http://www.tiexpert.net/programacao/c/ponteiros.php>. Acesso em: 11 de Novembro, 2018.

> Vantagens e Desvantagens dos Ponteiros. PT Computador. Disponível em: <http://ptcomputador.com/P/computer-programming-languages/88721.html>. Acesso em: 11 de Novembro, 2018.

> Deluno Garcia, Fernando. Ponteiro em C. Embarcados. Disponível em: <https://www.embarcados.com.br/serie/ponteiro-em-c/>. Acesso em: 11 de Novembro, 2018.
