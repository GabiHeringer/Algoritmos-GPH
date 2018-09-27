# Ponteiros
## O que é?
  Um ponteiro é uma variável que guarda um **endereço de memória** de outra variável, sendo possível "apontá-la", ou seja, se referir a   ela quando utilizado. 
  
 ## Quando utilizar?
  O ponteiro é muito útil quando queremos apontar para outras variáveis em diferentes locais de um programa, sendo mais fácil e rápido do que uma referência por valor, por exemplo.
  
## Benefícios:
- Alteração indereta do conteúdo de variáveis para qualquer lugar do programa;
- É muito utilizado em processos comuns e úteis como alocação dinâmica;

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
