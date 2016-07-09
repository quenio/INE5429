name: inverse
layout: true
class: center, middle, inverse
---
template: inverse
# SHA-3
.footnote[Quenio - Ranieri]
---
layout: false
.left-column[
## Hash Criptográfico
]
.right-column[
- Algoritmo de hash criptográfico adotado pelo NIST para complementar o SHA-2, seu predecessor. 
]
---
layout: false
.left-column[
## Hash Criptográfico
## Algoritmo Keccak
]
.right-column[
- Algoritmo de hash criptográfico adotado pelo NIST para complementar o SHA-2, seu predecessor. 

- SHA-3 é a aplicação da função Keccak.

    - Autores: Guido Bertoni, Joan Daemen, Michaël Peeters, Gilles Van Assche
    
    - Vencedores da competição promovida pelo NIST para escolher o algoritmo do SHA-3.
]
---
template: inverse
## Estrutura
SHA-3
---
layout: false
.left-column[
### Função Esponja
]
.right-column[
- A estrutura do algoritmo Keccak é definida pela função Esponja.
 
    - A função Esponja tem duas fases.
     
    - Absorção: onde blocos da mensagem de entrada são "absorvidos" pela função.
    
    - Squeezing: onde o valor de _hash_ é gerado
    
    - Em ambas fases, ocorrem permutações e subsituições em cada bloco de entrada.

]

---
layout: false
.left-column[
### Função Esponja
### Função Keccak-p
]
.right-column[
- A função Keccak-p é executada pela função Esponja em cada bloco da mensagem de entrada. 

    - Para cada bloco, são executadas 24 rodadas das função de permutação e substituição.
    
    - O estado destas rodadas vai sendo mantido numa estrutura chamada `state array`.
    
    - As função de permutação e substituição são executadas na seguinte sequência:
    
        - Theta
        
        - Rho
         
        - Pi 
         
        - Chi 
         
        - Iota 
]
---
template: inverse
## Permutações & Substituições
SHA-3
---
layout: false
.left-column[
## Theta
]
.right-column[
- Theta é uma função de substituição que utiliza bits das colunas anteriores e posteriores, além dos bits da célula sendo substituída. 

    - Cada bit substituído depende de outros 11 bits, o que provê uma difusão de alto grau.
]
---
layout: false
.left-column[
## Theta
## Rho
]
.right-column[
- _Rho_ é uma função de permutação dos bits dentro de cada célula. 

    - Sem esta função, a difusão entre as células, ocorreria de forma muito lenta.
]
---
layout: false
.left-column[
## Theta
## Rho
## Pi
]
.right-column[
- _Pi_ é também uma função de permutação, mas entre células. 

    - A permutação não se dá nos _bits_ de uma célula, mas entre as células da matriz.
]
---
layout: false
.left-column[
## Theta
## Rho
## Pi
## Chi
]
.right-column[
- _Chi_ é uma função de substituição baseada no valor do _bit_ corrente e dos _bits_ em posições correspondentes das duas próximas células.
 
    - Sem esta função, SHA-3 seria completamente linear.    
]
---
layout: false
.left-column[
## Theta
## Rho
## Pi
## Chi
## Iota
]
.right-column[
- _Iota_ é uma função de substituição baseada numa tabela - chamada RC, ou seja, constantes de rodada.
 
    - Usa um valor constante e diferente para cada rodada do SHA-3.
    
    - As constantes são geradas num algoritmo de shift linear.
    
    - Somente a célula (0,0) da _state array_ é transformada por esta função.
]
---
template: inverse
## Funções Hash 
SHA-3
---
layout: false
.left-column[
## SHA3-224 
]
.right-column[
```
SHA3-224(M) = KECCAK[448] (M || 01, 224)
```

|_Hash_|||Capacidade|||Bloco|||_State Array_|
|:-:|-|-|:--:|-|-|:-:|-|-|:-:|
|224|||448|||1152|||1600|
]
---
layout: false
.left-column[
## SHA3-224 
## SHA3-256 
]
.right-column[
```
SHA3-224(M) = KECCAK[448] (M || 01, 224)
SHA3-256(M) = KECCAK[512] (M || 01, 256)
```
|_Hash_|||Capacidade|||Bloco|||_State Array_|
|:-:|-|-|:--:|-|-|:-:|-|-|:-:|
|224|||448|||1152|||1600|
|256|||512|||1088|||1600|
]
---
layout: false
.left-column[
## SHA3-224 
## SHA3-256 
## SHA3-384 
]
.right-column[
```
SHA3-224(M) = KECCAK[448] (M || 01, 224)
SHA3-256(M) = KECCAK[512] (M || 01, 256)
SHA3-384(M) = KECCAK[768] (M || 01, 384)
```

|_Hash_|||Capacidade|||Bloco|||_State Array_|
|:-:|-|-|:--:|-|-|:-:|-|-|:-:|
|224|||448|||1152|||1600|
|256|||512|||1088|||1600|
|384|||768|||832|||1600|
]
---
layout: false
.left-column[
## SHA3-224 
## SHA3-256 
## SHA3-384 
## SHA3-512 
]
.right-column[
```
SHA3-224(M) = KECCAK[448] (M || 01, 224)
SHA3-256(M) = KECCAK[512] (M || 01, 256)
SHA3-384(M) = KECCAK[768] (M || 01, 384)
SHA3-512(M) = KECCAK[1024] (M || 01, 512)
```

|_Hash_|||Capacidade|||Bloco|||_State Array_|
|:-:|-|-|:--:|-|-|:-:|-|-|:-:|
|224|||448|||1152|||1600|
|256|||512|||1088|||1600|
|384|||768|||832|||1600|
|512|||1024|||576|||1600|
]
---
template: inverse
## Funções de Saída Variável 
SHA-3
---
layout: false
.left-column[
## SHAKE128 
]
.right-column[
```
SHAKE128(M, D) = KECCAK[256] (M || 1111, D)
```

|_Hash_|||Capacidade|||Bloco|||_State Array_|
|:-:|-|-|:--:|-|-|:-:|-|-|:-:|
|D|||256|||1344|||1600|
]
---
layout: false
.left-column[
## SHAKE128 
## SHAKE256 
]
.right-column[
```
SHAKE128(M, D) = KECCAK[256] (M || 1111, D)
SHAKE256(M, D) = KECCAK[512] (M || 1111, D)
```

|_Hash_|||Capacidade|||Bloco|||_State Array_|
|:-:|-|-|:--:|-|-|:-:|-|-|:-:|
|D|||256|||1344|||1600|
|D|||512|||1088|||1600|
]
---
layout: false
.left-column[
## SHAKE128 
## SHAKE256 
## RawSHAKE
]
.right-column[
```
SHAKE128(M, D) = KECCAK[256] (M || 1111, D)
SHAKE256(M, D) = KECCAK[512] (M || 1111, D)
```

|_Hash_|||Capacidade|||Bloco|||_State Array_|
|:-:|-|-|:--:|-|-|:-:|-|-|:-:|
|D|||256|||1344|||1600|
|D|||512|||1088|||1600|

```
RawSHAKE128(M, D) = KECCAK[256] (M || 11, D)
RawSHAKE256(M, D) = KECCAK[512] (M || 11, D)
```
]
---
template: inverse
## Benefícios 
SHA-3
---
layout: false
.left-column[
## Aplicações 
]
.right-column[
- Keccak permite a configuração da taxa de vazão (throughput). 

    - Melhorando _performance_ em detrimento da segurança.
    
    - Ou vice-versa. 
]
---
layout: false
.left-column[
## Aplicações 
]
.right-column[
- Keccak permite a configuração da taxa de vazão (throughput). 

    - Melhorando _performance_ em detrimento da segurança.
    
    - Ou vice-versa. 

- Ele também permite um tamanho variável do hash gerado.

    - Abrindo o leque de aplicações além das aplicações usuais de algoritmos de hash.
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
]
.right-column[
- Comparado ao SHA-2, e a outros algoritmos, Keccak tem uma margem de segurança bem alta.
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
]
.right-column[
- Comparado ao SHA-2, e a outros algoritmos, Keccak tem uma margem de segurança bem alta.
    
    - Suas funções de permutação o tornam menos vulnerável a ataques do que algoritmos tradicionais de hash, como o SHA-2. 
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
]
.right-column[
- Comparado ao SHA-2, e a outros algoritmos, Keccak tem uma margem de segurança bem alta.
    
    - Suas funções de permutação o tornam menos vulnerável a ataques do que algoritmos tradicionais de hash, como o SHA-2. 
    
    - Quase 80 por cento das funções que fazem parte do Keccak ainda não foram quebradas, enquanto 40 por cento das funções do SHA-2 já foram.
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
]
.right-column[
- Comparado ao SHA-2, e a outros algoritmos, Keccak tem uma margem de segurança bem alta.
    
    - Suas funções de permutação o tornam menos vulnerável a ataques do que algoritmos tradicionais de hash, como o SHA-2. 
    
    - Quase 80 por cento das funções que fazem parte do Keccak ainda não foram quebradas, enquanto 40 por cento das funções do SHA-2 já foram.
    
    - Os autores provaram matematicamente que o Keccak é seguro contra pré-imagem, segunda pré-imagem e colisões.
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
## Performance 
]
.right-column[
 - Implementado em software, a performance do SHA-3 é comparável ao SHA-2.
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
## Performance 
]
.right-column[
- Implementado em software, a performance do SHA-3 é comparável ao SHA-2.
  
- Sua performance em hardware, em termos de thoughput, é muito superior ao SHA-2.
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
## Performance 
## Design 
]
.right-column[
- Seu design simples, orientado a bits: 
    
    - Torna sua especificação bem clara.
     
    - Facilita seu entendimento e implementação. 
        
]
---
layout: false
.left-column[
## Aplicações 
## Segurança 
## Performance 
## Design 
]
.right-column[
- Seu design simples, orientado a bits: 
    
    - Torna sua especificação bem clara.
     
    - Facilita seu entendimento e implementação. 
        
- Seu design baseado em permutações, e na função de esponja, também permitirá:
     
    - O surgimento de algoritmos alternativos.
         
    - Ou algoritmos para outras aplicações.
]
---
