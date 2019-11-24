	ORG 0
START:  LD HL, NUM
        LD B, 21
        OTIR

        LD HL, MENU
        LD B, 21
        OTIR
        LD HL, MENU2
        LD B, 20
        OTIR
        LD HL, MENU3
        LD B, 19
        OTIR
        LD HL, MENU4
        LD B, 19
        OTIR
        LD HL, MENU5
        LD B, 9
        OTIR

        IN A, (0)
	IN B, (0)
        CP '1'
        JP NZ, LOOP1

        LD HL, NUM2
        LD B, 23
        OTIR

        CALL INPUT
        POP DE
        LD HL, NUM3
        LD B, 23
        OTIR

        LD B, D
        LD C, E
        CALL INPUT
	POP DE

        LD A, C
        CP 0FFH
        JP NZ, JUM
        LD C, B
 	LD B, '0'
JUM:    LD A, E
        CP 0FFH
        JP NZ, HOO
        LD E, D
        LD D, '0'

HOO:    LD A, B
        CP D
        JP Z, NOO
        JP C, GOO
        JP MOO
NOO:    LD A, C
        CP E
        JP Z, MOO
        JP C, GOO
MOO:
        LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0

        LD HL, ELSE
	LD B, 16
        OTIR
        JP START

GOO:    LD H, 0
        RR C
        JP C, ODD
        RL C

SUK:    LD A, B
        OUT (0), A
        LD A, C
        OUT (0), A
        LD A, ','
        OUT (0), A
        JP DOO
ODD:    RL C
        LD A, C
ODD2:   ADD A, 1
        CP '9'
	JP Z, KXX
        JP NC, NUG
	JP KOO
KXX:	JP ODD2
KOO:    LD C, A
        JP SUK
NUG:    LD C, '0'
        LD A, B
        ADD A, 1
        LD B, A
        JP SUK
DOO:    INC H
        LD A, H
        CP 10
        JP C, GOL
        LD A, 10
        OUT (0), A
        LD H, 0
GOL:    LD A, C
        ADD A, 2
        CP '9'
        JP NC, NUGI
        LD C, A
        JP BGO
NUGI:   LD C, '0'
        LD A, B
        ADD A, 1
        LD B, A
BGO:    LD A, B
 	CP D
        JP Z, BEE
        JP C, RIGH
	JP XXR
BEE:    LD A, C
        CP E
        JP Z, RIGH
        JP C, RIGH
XXR     LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0
        LD A, 10
        OUT (0), A
        JP START
RIGH:   JP SUK

LOOP1:  CP '2'
        JP NZ, LOOP2

        LD HL, NUM2
        LD B, 23
        OTIR
 	CALL INPUT
        POP DE

        LD HL, NUM3
        LD B, 23
        OTIR

        LD B, D
        LD C, E
        CALL INPUT
        POP DE

        LD A, C
        CP 0FFH
        JP NZ, JUM2
        LD C, B
        LD B, '0'
JUM2:   LD A, E
        CP 0FFH
        JP NZ, HOO2
        LD E, D
        LD D, '0'

HOO2:   LD A, B
        CP D
        JP Z, NOO2
        JP C, GOO2
        JP MOO2
NOO2    LD A, C
        CP E
        JP Z, MOO2
        JP C, GOO2

MOO2:   LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0
        LD HL, ELSE
        LD B, 16
        OTIR
        JP START

GOO2:   LD H, 0
        RR C
        JP NC, EVEN
        RL C
SUK2:   LD A, B
        OUT (0), A
        LD A, C
        OUT (0), A
        LD A, ','
        OUT (0), A
        JP DOO2
EVEN:   RL C
        LD A, C
        ADD A, 1
        CP '9'
        JP Z, kxx
        JP NC, NUG2
kxx2:   LD C, A
        JP SUK2
NUG2:   LD C, '0'
        LD A, B
        ADD A, 1
        LD B, A
        JP SUK2
DOO2:   INC H
        LD A, H
        CP 10
	JP C, GOL2
        LD A, 10
        OUT (0), A
        LD H, 0
GOL2:   LD A, C
        ADD A, 2
        CP '9'
        JP Z, KON
        JP NC, NUGI2
KON:    LD C, A
        JP BGO2
NUGI2:  LD C, '1'
        LD A, B
        ADD A, 1
        LD B, A
BGO2:   LD A, B
        CP D
        JP Z, BEE2
        JP C, RIGH2
	jp xxr2
BEE2:   LD A, C
        CP E
        JP Z, RIGH2
        JP C, RIGH2
xxr2:	LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0
        LD A, 10
        OUT (0), A
        JP START
RIGH2:  JP SUK2

LOOP2:  CP '3'
        JP NZ, LOOP3

        LD HL, NUM2
        LD B, 23
        OTIR

        CALL INPUT
        POP DE

        LD HL, NUM3
        LD B, 23
        OTIR
 	LD B, D
        LD C, E
        CALL INPUT
        POP DE

        LD A, C
        CP 0FFH
        JP NZ, JUM3
        LD C, B
        LD B, '0'
JUM3:   LD A, E
        CP 0FFH
        JP NZ, HOO3
        LD E, D
        LD D, '0'

HOO3:   LD A, B
        CP D
        JP Z, NOO3
        JP C, GOO3
        JP MOO3

NOO3:   LD A, C
 	CP E
        JP Z, MOO3
        JP C, GOO3

MOO3:   LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0

        LD HL, ELSE
        LD B, 16
        OTIR
        JP START

GOO3:   LD H, 0
GAJA:   LD A, B
        SUB 30H
        LD B, A
        LD A, C
        SUB 30H
        LD C, A

        LD A, B
	ADD A, C
        CP 3
        JP NZ, LOP
        JP MULO
LOP:    CP 6
        JP NZ, LOP2
        JP MULO
LOP2:   CP 9
        JP NZ, LOP3
        JP MULO
LOP3:   CP 12
        JP NZ, LOP4
        JP MULO
LOP4:   CP 15
        JP NZ, LOP5
        JP MULO
LOP5:   CP 18
        JP NZ, DUGH

MULO:   LD A, B
        ADD A, 30H
        LD B, A
        LD A, C
 	ADD A, 30H
        LD C, A

        LD A, B
        OUT (0), A
        LD A, C
        OUT (0), A
        LD A, ','
        OUT (0), A

        INC H
        LD A, H
        CP 10
        JP C, DU
        LD A, 10
        OUT (0), A
        LD H, 0
        JP DU

DUGH:   LD A, B
        ADD A, 30H
        LD B, A
        LD A, C
	ADD A, 30H
        LD C, A

DU:     LD A, C
        ADD A, 1
        CP '9'
        JP Z, DAUM
        JP NC, OLPS
DAUM:   LD C, A
        JP BGGO
OLPS:   LD C, '0'
        LD A, B
        ADD A, 1
        LD B, A
        JP BGGO
BGGO:   LD A, B
        CP D
        JP Z, DAU
        JP C, RIG
	JP XXR3
DAU:    LD A, C
        CP E
        JP Z, RIG
        JP C, RIG
XXR3:	LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0
        LD A, 10
        OUT (0), A
        JP START
RIG:    JP GAJA

LOOP3:  CP '4'
        JP NZ, LOOP4

        LD HL, NUM2
        LD B, 23
        OTIR

        CALL INPUT
        POP DE

        LD HL, NUM3
        LD B, 23
        OTIR
 LD B, D
        LD C, E
        CALL INPUT
        POP DE
        LD A, C
        CP 0FFH
        JP NZ, JUM4
        LD C, B
        LD B, '0'

JUM4:   LD A, E
        CP 0FFH
        JP NZ, HOO4
        LD E, D
        LD D, '0'

HOO4:   LD A, B
        CP D
        JP Z, NOO4
        JP C, GOO4
        JP MOO4
NOO4:   LD A, C
        CP E
	JP Z, MOO4
        JP C, GOO4
MOO4:   LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0
        LD HL, ELSE
        LD B, 16
        OTIR
        JP START

GOO4:   LD H, 0
GAJA2:  LD A, C
        CP '4'
        JP Z, TEN
        CP '8'
        JP Z, TEN
        CP '2'
        JP Z, TEN2
        CP '6'
        JP Z, TEN2
        CP '0'
        JP Z, TEN3
	JP DU2

TEN:    LD A, B
        CP '0'
        JP Z, MULO2
        CP '2'
        JP Z, MULO2
        CP '4'
        JP Z, MULO2
        CP '6'
        JP Z, MULO2
        CP '8'
        JP Z, MULO2
        JP DU2
TEN2:   LD A, B
        CP '1'
        JP Z, MULO2
        CP '3'
        JP Z, MULO2
        CP '5'
        JP Z, MULO2
        CP '7'
        JP Z, MULO2
  CP '9'
        JP Z, MULO2
        JP DU2

TEN3:   LD A, B
        CP '2'
        JP Z, MULO2
        CP '4'
        JP Z, MULO2
        CP '6'
        JP Z, MULO2
        CP '8'
        JP DU2
MULO2:  LD A, B
        OUT (0), A
        LD A, C
        OUT (0), A
        LD A, ','
        OUT (0), A

        INC H
        LD A, H
        CP 10
 JP C, DU2
        LD A, 10
        OUT (0), A
        LD H, 0
DU2:    LD A, C
        ADD A, 1
        CP '9'
        JP Z, NE1
        JP NC, OLPS2
NE1:    LD C, A
        JP BGGO2
OLPS2:  LD C, '0'
        LD A, B
        ADD A, 1
        LD B, A
        JP BGGO2
BGGO2:  LD A, B
        CP D
        JP Z, NE2
        JP C, RIG2
NE2:    LD A, C
        CP E
        JP Z, RIG2
	JP C, RIG2

        LD A, 0
        LD BC, 0
        LD DE, 0
        LD HL, 0
        LD A, 10
        OUT (0), A
        JP START

RIG2:   JP GAJA2

LOOP4:  CP 'q'
        JP Z, QUIT

QUIT:   HALT
MENU:   DEFM '(1) FIND EVEN NUMBER'
        DEFB 10
MENU2:  DEFM '(2) FIND ODD NUMBER'
        DEFB 10
MENU3:  DEFM '(3) A MULTIPLE OF3'
        DEFB 10
MENU4:  DEFM '(4) A MULTIPLE OF4'
 DEFB 10
MENU5:  DEFM '(q) QUIT'
        DEFB 10
ELSE:   DEFM 'WRONG COMMAND!!'
        DEFB 10

INPUT:  POP HL
        IN A, (0H)
        LD D, A

        IN A, (0H)
        CP 10
        JP Z, RUN
        LD E, A
        IN A, (0)
        JP RUN2
RUN:    LD E, 0FFH
RUN2:   PUSH DE
        PUSH HL
        RET

NUM:    DEFM '<<MIN & MAX SYSTEM>>'
        DEFB 10

NUM2:   DEFM 'MIN NUMBER INPUT(1~99)'
        DEFB 10
NUM3:   DEFM 'MAX NUMBER INPUT(1~99)'
        DEFB 10
        END


























