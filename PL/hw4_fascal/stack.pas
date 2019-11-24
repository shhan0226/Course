Program STACK(input, output);

TYPE
  pSTACK = ^tSTACK;
  tSTACK = RECORD
           NAME: STRING;
           PREV: pSTACK;
         END;
VAR
  LAST, CUR : PSTACK;
  S, FILENAME :STRING;
  CH : CHAR;
  F : FILE OF CHAR;

PROCEDURE ADD(NAME:STRING);
BEGIN
  NEW(CUR);
  CUR^.NAME := NAME;
  CUR^.PREV := LAST;
  LAST:=CUR;
END;

PROCEDURE VIEW;
BEGIN
  CUR := LAST;
  WHILE CUR <> NIL DO
    BEGIN
      WRITELN(CUR^.NAME);
      CUR:= CUR^.PREV;
    END;
END;

PROCEDURE DESTROY;
BEGIN
  WHILE CUR <> NIL DO
  BEGIN
    CUR :=LAST^.PREV;
    DISPOSE(LAST);
    LAST :=CUR;
  END;
END;


BEGIN
  
  WRITE('FILE INPUT:');
  READ(FILENAME);
  ASSIGN(F, FILENAME);
  RESET(F);
  LAST := NIL;
  S := '';

  WHILE NOT EOF(F) DO
     BEGIN 
     READ(F,CH);
     WRITE(CH);
      IF(CH=' ')OR(ORD(CH)=10)
        THEN BEGIN
              ADD(S);
              S:='';
        END ELSE
              S+=CH;
      END;
   WRITELN;
   WRITELN('STACK START!!');
   
  VIEW;
  DESTROY;

end.
