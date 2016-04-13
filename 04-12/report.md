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

Verificando o servidor da RNP, minha assinatura agora se encontra no certificado do colega:

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

c) Criar um certificado PGP, incluir tal certificado num servidor remoto e depois revogá-lo.

Abaixo, criamos um novo certificado PGP:

```
$ gpg --gen-key
gpg (GnuPG) 1.4.20; Copyright (C) 2015 Free Software Foundation, Inc.
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.

Please select what kind of key you want:
   (1) RSA and RSA (default)
   (2) DSA and Elgamal
   (3) DSA (sign only)
   (4) RSA (sign only)
Your selection? 1
RSA keys may be between 1024 and 4096 bits long.
What keysize do you want? (2048)
Requested keysize is 2048 bits   
Please specify how long the key should be valid.
         0 = key does not expire
      <n>  = key expires in n days
      <n>w = key expires in n weeks
      <n>m = key expires in n months
      <n>y = key expires in n years
Key is valid for? (0) 2
Key expires at Fri Apr 15 16:16:16 2016 BRT
Is this correct? (y/N) y

You need a user ID to identify your key; the software constructs the user ID
from the Real Name, Comment and Email Address in this form:
    "Heinrich Heine (Der Dichter) <heinrichh@duesseldorf.de>"

Real name: Q S
Name must be at least 5 characters long
Real name: Quenio Santos           
Email address: quenio@me.com
Comment: Temp Key           
You selected this USER-ID:
    "Quenio Santos (Temp Key) <quenio@me.com>"

Change (N)ame, (C)omment, (E)mail or (O)kay/(Q)uit? O
You need a Passphrase to protect your secret key.    

We need to generate a lot of random bytes. It is a good idea to perform
some other action (type on the keyboard, move the mouse, utilize the
disks) during the prime generation; this gives the random number
generator a better chance to gain enough entropy.
......+++++
...+++++
We need to generate a lot of random bytes. It is a good idea to perform
some other action (type on the keyboard, move the mouse, utilize the
disks) during the prime generation; this gives the random number
generator a better chance to gain enough entropy.
....+++++
..+++++
gpg: key FE6C38CE marked as ultimately trusted
public and secret key created and signed.

gpg: checking the trustdb
gpg: 3 marginal(s) needed, 1 complete(s) needed, PGP trust model
gpg: depth: 0  valid:   2  signed:   3  trust: 0-, 0q, 0n, 0m, 0f, 2u
gpg: depth: 1  valid:   3  signed:   0  trust: 2-, 0q, 0n, 0m, 1f, 0u
gpg: next trustdb check due at 2016-04-15
pub   2048R/FE6C38CE 2016-04-13 [expires: 2016-04-15]
      Key fingerprint = 5375 AA33 8DA3 40B7 D6F0  DF72 03B1 8C70 FE6C 38CE
uid                  Quenio Santos (Temp Key) <quenio@me.com>
sub   2048R/6E7FB5EC 2016-04-13 [expires: 2016-04-15]
```

Enviando o novo certificado para o servidor da RNP:

```
gpg --keyserver raxus.rnp.br --send-key FE6C38CE
gpg: sending key FE6C38CE to hkp server raxus.rnp.br
```

Agora, o certificado se encontra no servidor RNP:

```
pub  2048R/FE6C38CE 2016-04-13            uid Quenio Santos (Temp Key) <quenio@me.com>
sig  sig3  FE6C38CE 2016-04-13 __________ 2016-04-15 [selfsig]sub  2048R/6E7FB5EC 2016-04-13            
sig sbind  FE6C38CE 2016-04-13 __________ 2016-04-15 []
```

Gerando o certificado de revogação:

```
gpg --output qs.revoke.asc  --gen-revoke FE6C38CE

sec  2048R/FE6C38CE 2016-04-13 Quenio Santos (Temp Key) <quenio@me.com>

Create a revocation certificate for this key? (y/N) y
Please select the reason for the revocation:         
  0 = No reason specified
  1 = Key has been compromised
  2 = Key is superseded
  3 = Key is no longer used
  Q = Cancel
(Probably you want to select 1 here)
Your decision? 0
Enter an optional description; end it with an empty line:
> Temp key for school exercise.
>                              
Reason for revocation: No reason specified
Temp key for school exercise.
Is this okay? (y/N) y

You need a passphrase to unlock the secret key for
user: "Quenio Santos (Temp Key) <quenio@me.com>"
2048-bit RSA key, ID FE6C38CE, created 2016-04-13

ASCII armored output forced.
Revocation certificate created.

Please move it to a medium which you can hide away; if Mallory gets
access to this certificate he can use it to make your key unusable.
It is smart to print this certificate and store it away, just in case
your media become unreadable.  But have some caution:  The print system of
your machine might store the data and make it available to others!
```

Agora, importamos o certificado de revogação no GnuPG:

```
$ gpg --import qs.revoke.asc
gpg: key FE6C38CE: "Quenio Santos (Temp Key) <quenio@me.com>" revocation certificate imported
gpg: Total number processed: 1
gpg:    new key revocations: 1
gpg: 3 marginal(s) needed, 1 complete(s) needed, PGP trust model
gpg: depth: 0  valid:   2  signed:   3  trust: 0-, 0q, 0n, 0m, 0f, 2u
gpg: depth: 1  valid:   3  signed:   0  trust: 2-, 0q, 0n, 0m, 1f, 0u
gpg: next trustdb check due at 2016-04-15
```

Finalmente, enviamos a revogação para o servidor RNP:

```
gpg --keyserver raxus.rnp.br --send-key FE6C38CE
gpg: sending key FE6C38CE to hkp server raxus.rnp.br
```

Agora, o servidor RNP já confirmou a revogação:

```
pub  2048R/FE6C38CE 2016-04-13            
sig revok  FE6C38CE 2016-04-13 __________ __________ [selfsig]uid Quenio Santos (Temp Key) <quenio@me.com>
sig  sig3  FE6C38CE 2016-04-13 __________ 2016-04-15 [selfsig]sub  2048R/6E7FB5EC 2016-04-13            
sig sbind  FE6C38CE 2016-04-13 __________ 2016-04-15 []
```
