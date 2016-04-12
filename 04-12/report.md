Aluno: Quenio Cesar Machado dos Santos
Matricula: 14100868
Disciplina: INE5429 - Segurança em Computadores
Data: 04/12/2016

Relatório: Confiança em certificados Digitais PGP

a) Assinar os certificados de todos os seus colegas e do professor.

Para assinar o certificado que os colegas criaram na aula anterior, é preciso primeiro baixá-los do servidor de chaves da RNP usando o comando abaixo:

```
$ gpg --keyserver raxus.rnp.br --recv-key cfafe5bd
gpg: requesting key CFAFE5BD from hkp server raxus.rnp.br
gpg: key CFAFE5BD: public key "Guilherme Nakayama (INE5429) <guilherme.nakayama@hotmail.com>" imported
gpg: 3 marginal(s) needed, 1 complete(s) needed, PGP trust model
gpg: depth: 0  valid:   1  signed:   2  trust: 0-, 0q, 0n, 0m, 0f, 1u
gpg: depth: 1  valid:   2  signed:   0  trust: 1-, 0q, 0n, 0m, 1f, 0u
gpg: next trustdb check due at 2016-08-03
gpg: Total number processed: 1
gpg:               imported: 1  (RSA: 1)
```

Agora, para assinar o certificado do colega, utiliza-se o comando para editar o certificado, verificar sua "fingerprint" e assiná-lo:

```
$ gpg --edit-key guilherme.nakayama@hotmail.com
gpg (GnuPG) 1.4.20; Copyright (C) 2015 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.


pub  2048R/CFAFE5BD  created: 2016-04-05  expires: 2016-07-04  usage: SC  
                     trust: unknown       validity: unknown
sub  2048R/0BAD2D62  created: 2016-04-05  expires: 2016-07-04  usage: E   
[ unknown] (1). Guilherme Nakayama (INE5429) <guilherme.nakayama@hotmail.com>
[ unknown] (2)  Guilherme Nakayama <guilherme.nakayama@hotmail.com>

gpg> fpr
pub   2048R/CFAFE5BD 2016-04-05 Guilherme Nakayama (INE5429) <guilherme.nakayama@hotmail.com>
 Primary key fingerprint: D55C 0679 DA26 5D96 3B9D  F5DC DE27 BE97 CFAF E5BD

gpg> sign
Really sign all user IDs? (y/N) y

pub  2048R/CFAFE5BD  created: 2016-04-05  expires: 2016-07-04  usage: SC  
                     trust: unknown       validity: unknown
 Primary key fingerprint: D55C 0679 DA26 5D96 3B9D  F5DC DE27 BE97 CFAF E5BD

     Guilherme Nakayama (INE5429) <guilherme.nakayama@hotmail.com>
     Guilherme Nakayama <guilherme.nakayama@hotmail.com>

This key is due to expire on 2016-07-04.
Are you sure that you want to sign this key with your
key "Quenio Cesar Machado dos Santos (Ver...) <queniodossantos@gmail.com>" (B03C59BB)

Really sign? (y/N) y

You need a passphrase to unlock the secret key for
user: "Quenio Cesar Machado dos Santos (Ver...) <queniodossantos@gmail.com>"
2048-bit RSA key, ID B03C59BB, created 2016-04-05


gpg> quit
Save changes? (y/N) y
```

b) Verificar como se deve proceder para a atualização dos certificados (conhecidos como anéis de chaves PGP) privados e públicos.

Uma vez assinado o certificado do colega, é preciso enviá-lo para o servidor de chaves da RNP para que seja incluída nossa assinatura:

```
$ gpg --keyserver raxus.rnp.br --send-key CFAFE5BD
gpg: sending key CFAFE5BD to hkp server raxus.rnp.br
```

Verificando o servidor da RNP, minha assinatura se encontra agora no certificado do colega:

```
pub  2048R/CFAFE5BD 2016-04-05            uid Guilherme Nakayama <guilherme.nakayama@hotmail.com>
sig  sig3  CFAFE5BD 2016-04-05 __________ 2016-07-04 [selfsig]
sig  sig   E62976D7 2016-04-12 __________ __________ Ranieri Althoff (Key for INE5429) <ranisalt@gmail.com>
sig  sig   7681F1FB 2016-04-12 __________ __________ Ion JosÃ© de Souza Neto <ionneto@gmail.com>
sig  sig   2F3EE36E 2016-04-12 __________ __________ Lucas Finger Roman <lfrfinger@gmail.com>
sig  sig   0DC62EBB 2016-04-12 __________ __________ Willian de Souza <willianstosouza@gmail.com>
sig  sig   B03C59BB 2016-04-12 __________ __________ Quenio Cesar Machado dos Santos (Ver...) <queniodossantos@gmail.com>uid Guilherme Nakayama (INE5429) <guilherme.nakayama@hotmail.com>
sig  sig3  CFAFE5BD 2016-04-12 __________ 2016-07-04 [selfsig]
sig  sig   0DC62EBB 2016-04-12 __________ __________ Willian de Souza <willianstosouza@gmail.com>
sig  sig   B03C59BB 2016-04-12 __________ __________ Quenio Cesar Machado dos Santos (Ver...) <queniodossantos@gmail.com>sub  2048R/0BAD2D62 2016-04-05            
sig sbind  CFAFE5BD 2016-04-05 __________ 2016-07-04 []
```
