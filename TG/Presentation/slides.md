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
## Tipos
NoSQL
---
layout: false
.left-column[
## _Key-Value Stores_
]
.right-column[
- Baseadas em tabelas _hash_.
    
    - Para cada chave há um valor.
    
    - Tipos de valores: lists, sets, hashes, strings, numbers, object (em alguns)
    
    - Tipos de operações: range, diff, union, intersection
]

---
layout: false
.left-column[
## _Key-Value Stores_
### Exemplos
]
.right-column[
- Baseadas em tabelas _hash_

    - Para cada chave há um valor.

    - Tipos de valores: lists, sets, hashes, strings, numbers, object (em alguns)

    - Tipos de operações: range, diff, union, intersection
    
- Exemplos:

    - Redis

    - Riak 

    - BerkeleyDB

    - DynamoDB

    - Voldermot
]
---
layout: false
.left-column[
## _Key-Value Stores_
### Exemplos
### Terminologia
]
.right-column[
| Relacional    |    | Key-Values Stores |
|--------------:|----|:------------------|
| Database      | -> | Cluster           |
| Table         | -> | Bucket (Riak)     |
| Row           | -> | Key-Value         |
| Row Id        | -> | Key               |
]
---
layout: false
.left-column[
## _Key-Value Stores_
### Exemplos
### Terminologia
### Casos de Uso 
]
.right-column[
- Casos de uso típicos:

    - _Session Data_
    
        - Pedidos

    - _Caching_
    
        - Opções do Pedido
]
---
layout: false
.left-column[
## _Key-Value Stores_
### Exemplos
### Terminologia
### Casos de Uso
### Deficiências
]
.right-column[
- Casos de uso típicos:

    - _Session Data_
    
        - Pedidos

    - _Caching_
    
        - Opções do Pedido
- Deficiências:

    - Dados com relacionamentos

    - Transações
    
        - Aplicação precisa implementar _locking_.

    - Consultas por valores ao invés de chaves
]
---
layout: false
.left-column[
## _Document Databases_
]
.right-column[
- Baseados em documents XML, JSON, BSON, etc.

    - Dados auto-descritivos
    
    - Hierárquicos 
    
    - Estruturados
]
---
layout: false
.left-column[
## _Document Databases_
### Exemplos
]
.right-column[
- Baseados em documents XML, JSON, BSON, etc.

    - Dados auto-descritivos
    
    - Hierárquicos 
    
    - Estruturados
    
- Exemplos:
    
    - MongoDB
    
    - CouchDB
    
    - OrientDB
    
    - RavenDB
]
---
layout: false
.left-column[
## _Document Databases_
### Exemplos
### Terminologia
]
.right-column[
| Relacional    |    | Document Databases |
|--------------:|----|:-------------------|
| Table         | -> | Collection         |
| Row           | -> | Document           |
| Row Id        | -> | _id                |
| Join          | -> | DBRef (MongoDB)    |
]

---
layout: false
.left-column[
## _Document Databases_
### Exemplos
### Terminologia
### Casos de Uso
]
.right-column[
- Casos de uso típicos:

    - _Content Management_
    
    - _Event Logging_
    
    - _Analytics_
]
---
layout: false
.left-column[
## _Document Databases_
### Exemplos
### Terminologia
### Casos de Uso
### Deficiências
]
.right-column[
- Dificuldade de agregação de dados na consultas
    - Porém, permitem fazer consultas no conteúdo de documentos.
    - Alguns oferecem suporte a _MapReduce_.

- Transações
    - Atomicidade somente por documento.
    - RavenDB permite transações em mais de uma operação.

- Consistência
    - Cliente pode escolher:
        - O número de _slaves_ de uma escrita antes da operação sem considerada bem-sucedida.
        - Se permite leitura dos _slaves_ ou não.

]
---
layout: false
.left-column[
## _Column Stores_
]
.right-column[
- Armazena dicionários de tuplas.

    - Cada tupla tem uma chave primária.

    - Cada tupla pode ter campos diferentes.
    
    - Estrutura flexível; não é definida por _schema_.
]

---
layout: false
.left-column[
## _Column Stores_
### Exemplos
]
.right-column[
- Armazena dicionários de tuplas.

    - Cada tupla pode ter campos diferentes.
    
    - Cada tupla pode ter campos diferentes.
    
    - Estrutura flexível; não é definida por _schema_.
    
- Exemplos:
    
    - Cassandra
    
    - HBase (Hadoop)
    
    - HyperTable
    
    - SimpleDB 
]
---
layout: false
.left-column[
## _Column Stores_
### Exemplos
### Terminologia
]
.right-column[
| Relacional    |    | Column Stores |
|--------------:|----|:---------------------|
| Database      | -> | Keyspace             |
| Table         | -> | Column Family        |
| Row           | -> | Row                  |
| Column        | -> | Column (pode variar em cada Row) |

```sql
SELECT user_id, top_places 
    FROM users 
    WHERE user_id = 'frodo';

user_id | top_places
--------+----------------------------
  frodo | ['the shire', 'rivendell']
```

]

---
layout: false
.left-column[
## _Column Stores_
### Exemplos
### Terminologia
### Casos de Uso
]
.right-column[
- Casos de uso típicos:

    - _Sensor Data / IoT_ 

    - _Analytics_

    - _Statistics_ / _Data Analysis_

    - Necessidade de Particionamento
        
        - A chave primária de cada tupla já define o particionamento no cluster.
]
    
---
layout: false
.left-column[
## _Column Stores_
### Exemplos
### Terminologia
### Casos de Uso
### Deficiências
]
.right-column[
- Deficiências:

    - Dados com relacionamentos

    - Transações
        - No Cassandra, transação é atomica no nível de _rows_.
        
        - Possui vários níveis de consistência para leitura e escrita.

]
---
layout: false
.left-column[
## _Graph Databases_
]
.right-column[
- Permitem armazenar entidades e seus relacionamentos mais complexos.

    - São baseados grafos com nós e suas ligações.
    
    - Ambos os nodos e ligações podem ter propriedades associadas.
]
---
layout: false
.left-column[
## _Graph Databases_
### Exemplos
]
.right-column[
- Permitem armazenar entidades e seus relacionamentos mais complexos.

    - São baseados grafos com nós e suas ligações.
    
    - Ambos os nodos e ligações podem ter propriedades associadas.
    
- Exemplos: 
    
    - Neo4J
    
    - Infinite Graph
    
    - FlockDB
]
---
layout: false
.left-column[
## _Graph Databases_
### Exemplos
### Terminologia
]
.right-column[
| Relacional    |    | Graph Databases |
|--------------:|----|:----------------|
| Table Row     | -> | Node            |
| Relation Row  | -> | Links           |
| Column        | -> | Property        |
]
---
layout: false
.left-column[
## _Graph Databases_
### Exemplos
### Terminologia
### Casos de Uso
]
.right-column[
- Casos de uso típicos:

    - Relacionamentos complexos de dados
    
    - Aplicações de roteamento
        - Na área de transporte, por exemplo.
        
    - Logística
        
    - Localização
        
    - Serviços de recomendação    
]
---
layout: false
.left-column[
## _Graph Databases_
### Exemplos
### Terminologia
### Casos de Uso
### Deficiências
]
.right-column[
- Deficiências:
        
    - _Bulk update_
        
    - _Bancos de dados muito grandes_
        
    - Transação / Consistência
        - NeoJ oferece ACID no master e replicação para os slaves.
        - Infinite Graph oferece distribuição de nós entre o cluster. 
]
---
layout: false
.left-column[
## _SQL + Documents_
]
.right-column[
- Oracle suporta JSON and XML como tipos de dados nativos
    
    - Provê transações, indices, consultas, views.

    - Permite fazer JOIN entre tabelas e JSON + XML.

    - Também permite projetas dados JSON + XML como se fossem tabelas.

    - Consultar JSON + XML armazenado fora do banco de dados.
]
---
layout: false
.left-column[
## _SQL + Documents_
### Exemplos
]
.right-column[
_Schema_:

```sql
CREATE TABLE j_purchaseorder
   (id          RAW (16) NOT NULL,
    date_loaded TIMESTAMP WITH TIME ZONE,
    po_document CLOB
    CONSTRAINT ensure_json CHECK (po_document IS JSON));
```

Inserir _JSON_:

```sql
INSERT INTO j_purchaseorder
  VALUES (SYS_GUID(),
          SYSTIMESTAMP,
          '{"PONumber"             : 1600,
            "Reference"            : "ABULL-20140421",
            "Requestor"            : "Alexis Bull",
            "User"                 : "ABULL",
            "CostCenter"           : "A50",
            "ShippingInstructions" : {...},
            "AllowPartialShipment" : true,
            "LineItems"            : [...]}');
```

Consultar _JSON_:

```sql
SELECT po.po_document.PONumber 
    FROM j_purchaseorder po;
SELECT po.po_document.ShippingInstructions.Phone 
    FROM j_purchaseorder po;
```
]
---
layout: false
.left-column[
## _Referências_
]
.right-column[
- _NoSQL Distilled_
    - Autores: Pramod J. Sadalage & Martin Fowler

- _Seven Databases in Seven Weeks_
    - Autores: Eric Redmond & Jim R. Wilson
    - Redis, Neo4J, CouchDB, MongoDB, HBase, Riak, and Postgres
    
- http://nosql-database.org
    
    - Lista bem completa dos bancos de dados NoSQL disponíveis. 
]
---
template: inverse
# MongoDB & Redis
