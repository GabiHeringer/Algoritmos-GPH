# Introdução
   Atualmente, com o avanço crescente da tecnologia, é imprescindível a busca pela eficiência, desempenho e capacidade de armazenamento. Neste contexto, os profissionais da área tentam cada vez mais otimizar seus algoritimos a fim de reduzir custos não só financeiros mas também que englobam tempo e dificuldade de uso.
   
   Um **algoritimo** é uma sequência de instruções utilizadas para resolver um problema específico, que depois pode ser implementado computacionalmente. Em casos mais complexos, com problemas reais e trabalhosos, dependendo do jeito da implementação do alogrítimo, ele pode não ser aceitável por sua execução demandar muito tempo e/ou exigir muitos recursos computacionais.
  
  Diante disso, surge a necessidade de realizar uma análise de complexidade de algorítimo, a qual permite ao implementador analisar e realizar os possíveis testes, os quais vão dizer se seu código é viável para a resolução de tal problema. Geralmente, estas análises são feitas levando em consideração os seguintes fatores:
  
  - *Tempo de execução.*
  - *Utilização de memória.*
  - *Custo de implementação.*
  - *Portabilidade.*
  
  Na maioria dos casos, o **tempo de execução** é a maior preocupação. Em relação a este fator, existem dois tipos de análises que podem ser feitas: Análise Experimental e Análise Teória (Assintótica). Antes de falar sobre elas, introduziremos o conceito de classificação quanto a Entrada de Dados.
  
  # Entrada de dados
  Para os dados que vão compor o conjunto de entrada necessários para a execução do algoritimo e resolução do problema, existem 3 tipos de classificação:
  
  - Melhor caso: o qual o problema leva o menor tempo de execução. Por exemplo, se tivermos uma busca em uma lista, o elemento a ser buscado está na primeira posição, ou seja, a entrada de dados facilitou.
  - Caso médio: média dos tempos de execução ou número de operações.
  - Pior caso: o qual o problema leva o maior número de operações possíveis, como por exemplo, o elemento a ser buscado na lista esteja na última posição, assim, a entrada de dados dificultou.
  
  # Análise Experimental
  Neste tipo de análise, o algoritimo em questão é implementado e executado com um conjunto de dados de tamanho aleatório. O tempo que o algoritimo leva para executar com esses tamanhos aleatórios é representado muitas vezes pelo **número de operações** que ele fez. Dessa maneira, esses resultados podem ser utilizados na construção de um gráfico ou uma tabela (número de operações x tamanho), onde pode ser observado seu comportamento a medida que os dados crescem. A partir deste comportamento, pode-se comparar a uma curva (função que define) específica e ser denotado de acordo com ela.
  ## Desvantagem
  Um problema neste tipo de análise é que só pode ser utilizada para determinar o desempenho do algorítimo em uma máquina específica, pois depende da linguagem, compilador e hardware utilizados. Além disso, o conjunto de dados de entrada utilizado é limitado e possivelmente não abrange todas as possibilidades de uso.
  
  Por este motivo, a análise apenas executando o algorítimo pode ser falha, pois não se controla a entrada de dados.
  
  # Análise Teórica
  Neste tipo, o algoritimo em questão não precisa ser implementado, pois se utiliza de abordagens matemáticas para avaliar o desempenho do código, assim, não se faz necessário levar em conta a máquina, linguagem e hardware. Deste modo, tenta entender como o algorítimo se comporta com a quantidade de dados n de entrada grandes. Assim, são englobados todos os tipos de entrada como uma generalização. Este processo também é chamado de **análise assintótica**, que prevê o comportamento do algoritimo no seus limites e não envolve nada experimental.
  
  Existem várias notações assintóticas, cada uma se referindo a algo específico. A mais utilizada é a **Big O Notation**, que expressa o limite superior da execução do algoritimo, ou seja, prevê o pior caso, onde ele pode se comportar de forma mais demorada.
  
  Listadas a seguir estão as notações mais utilizadas para diferentes comportamentos:
  1. *O(1): tempo constante para todos os tamanhos, a melhor.*
  2. *O(log n): tempo de execução avaliado em log(n).*
  3. *O(n): linear, tempo de execução avaliado proporcionalmente ao tamanho de entrada.*
  4. *O(n log n): maior que a linear e menor que a quadrática.*
  5. *O(n²): Quadrática ao tamanho do problema.*
  
  Deste modo, **n** é o tamanho de entrada e a função corresponde ao comportamento do código de acordo com n.
  
  # Análise de Buscas: Binária e Ingênua
  As duas buscas ditas acima, servem para localizar um elemento em um conjunto de dados ou para dizer que ele não está lá, seja em um vetor, uma lista e etc. Entretanto, funcionam de formas diferentes.
  ## Busca Binária
  Seja em um vetor de números como exemplo, esta divide o vetor ao meio para saber se o elemento buscado é menor ou maior que o meio. Se for maior, divide-se a segunda metade ao meio novamente, se for menor, a primeira. Assim diminuindo a entrada até achar (ou não) o elemento.
  ## Busca Ingênua
  No mesmo exemplo acima, esta busca compara cada elemento do vetor ao elemento buscado, até achar (ou não).
  
  ## Análise
  Vamos utilizar agora, a análise experimental para encontrar a complexidade de cada um dos algoritimos acima e chegar à conclusão de qual é o melhor para se utilizar. 
  
  Para isso, os algoritimos serão executados contando o número de comparações realizadas para achar um elemento em um vetor de tamanho n. Assim, utilizaremos as buscas para achar elementos aleatórios em vetores de tamanhos aleatórios que vão de 10 até 100 0000, de 500 em 500. Em um arquivo, será impresso três colunas: a primeira, o tamanho do vetor; a segunda, o número de comprações que a busca ingênua fez; a terceira, o número de comparações que a binária fez. Os códigos das buscas e scripts dos gráficos no gnuplot encontram-se na pasta buscas_e_custos. 
  
  Assim, plotaremos dois gráficos tamanho x número de comparações e estudaremos o comportamento de cada uma.
  
  ### Ingênua
  ![Gráfico 1](https://github.com/GabiHeringer/Algoritmos-GPH/blob/master/buscas_e_custo/Graficos/ingenua-1.jpg)
  
  Analisando o gráfico, vemos que apesar dos pontos fora da curva, a busca ingênua apresenta um corportamento linear. Fitamos a curva f(x) = ax + b e assim chegamos à f(x) no gráfico com os parâmetros:
  
  a = 0.689093
  
  b = 1.00625
  
  Como o comportamento vai ficando cada vez mais linear conforme n aumenta, desprezamos os fatores multiplicativos e somatórios, obtendo uma relação com a Big O Notation. Por fim, chegamos à conclusão de que a busca ingênua tem uma complexidade de O(n).
  
  ### Binária
  ![Gráfico 2](https://github.com/GabiHeringer/Algoritmos-GPH/blob/master/buscas_e_custo/Graficos/binaria-1.jpg)
  
  Analisando o gráfico, podemos perceber que o comportamento da busca binária é logarítimico. Foi fitada a curva f(x) = a log (x) + b e assim chegamos à f(x) no gráfico com os parâmetros:
  
  a = 1.41012
  
  b = 0.354509
  
  Do mesmo jeito que na ingênua, como os valores de n ficam muito grandes e o comportamento vai se moldando cada vez mais, podemos desprezar os fatores multiplicativos e somatórios. Assim, relacionando com a Big O Notation temos que a complexidade da Busca Binária é O(log n).
  
  # Conclusão
  Apesar de os gráficos não serem muito precisos, o que já se espera de uma análise experimental com entrada aleatória. Foi possível chegar a uma notação Big O Notation que molda o comportamento do algoritimo. Devemos lembrar que estes resultados podem ser diferentes em outras máquinas, mas os valores sempre seguirão o padrão linear para a ingênua e logarítimica para a binária.
  
  Assim, concluímos que a busca binária é mais eficiente que a ingênua, demanda menos tempo e menos recursos computacionais, o que já era esperado já que a binária diminui o tamanho da entrada de dados continuamente.
  
  Conclui-se, dessa forma, que as análises apresentadas aqui e tantas outras que existem se fazem fundamental na escolha da melhor solução para qualquer problema. Há uma infinidade de maneiras de se usar a tecnologia e a partir da teoria por trás dela conseguimos utilizar da melhor maneira.
  
  # Referências Bibliográficas
  Análise de Complexidade de Algorítimos. Universidade de São Paulo. Disponível em: http://wiki.icmc.usp.br/images/d/de/Analise_complexidade.pdf. Acesso em: 01 de Janeiro, 2019.
  
  Análise de Algorítimos. Universidade Federal de Uberlândia. Disponível em: http://www.facom.ufu.br/~backes/gsi011/Aula01-AnaliseAlgoritmos_01.pdf. Acesso em: 01 de Janeiro, 2019.
  
  Barrére, Eduardo. Análise e Projeto de Algorítimos. Universidade Federal de Juiz de Fora. Disponível em: http://www.ufjf.br/eduardo_barrere/files/2013/03/APA_2013_aula2.pdf. Acesso em: 01 de Janeiro, 2019.
  
  Peter Laube, Klaus. Análise de algoritmos: Análise Assintótica.  Profissionais TI. Disponível em: https://www.profissionaisti.com.br/2016/10/analise-de-algoritmos-analise-assintotica/. Acesso em: 01 de Janeiro, 2019.
  
