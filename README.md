# 42
42 Projet
# Projet Corewar

## Gestion d'erreur parsing:

### Nom du champion:

http://aymericdev.fr/img/GITHUB_COREWAR_05.png

<img src="http://aymericdev.fr/img/GITHUB_COREWAR_05.png"/>


### Commentaire du champion:

http://aymericdev.fr/img/GITHUB_COREWAR_04.png

<img src="http://aymericdev.fr/img/GITHUB_COREWAR_04.png"/>


## Parsing champion v2:
http://aymericdev.fr/img/GITHUB_COREWAR_03.png

<img src="http://aymericdev.fr/img/GITHUB_COREWAR_03.png"/>


## Parsing champion:

http://aymericdev.fr/img/GITHUB_COREWAR_02.png

<img src="http://aymericdev.fr/img/GITHUB_COREWAR_02.png"/>


## Parsing:

http://aymericdev.fr/img/GITHUB_COREWAR_01.png
<img src="http://aymericdev.fr/img/GITHUB_COREWAR_01.png"/>


## Gestion d'erreur:

http://aymericdev.fr/img/GITHUB_COREWAR_00.png
<img src="http://aymericdev.fr/img/GITHUB_COREWAR_00.png"/>

--- header

magic octet : 4 octets (unsigned int)
prog_name : 128 octets + 1 padding(int value == 0)
prog_size : 4 octets (unsigned int)
prog_comment : 2048 octets + 1 padding (int value == 0)

--- instructions

architecture :
		- opcode 1 octet
		- octet d'encodage 1 octet
		- parametres varie avec l'octet d'encodage

exemple instructions :

		- 0b opcode (0b == 11)
		- 68 binaire == 01 10 10 00
		- 01 00 45 00 01

https://docs.google.com/spreadsheets/d/1pFwSCne-mh-u5ZLsjZS8VI9QvecYk-gWTyNaPstjpLE/edit#gid=0


function that modifie carry --> -ld
								-add
								-sub
								-and
								-or
								-xor
								-lld
								-lldi

