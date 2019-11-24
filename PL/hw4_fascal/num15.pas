Program num15(input, output);

TYPE
  pQUEUE = ^tQUEUE;
  tQUEUE = RECORD
           NAME: STRING;
           NEXT: pQUEUE;
         END;
VAR
  HEAD, LAST, CUR : PQUEUE;
  S,FILENAME :STRING;
  CH : CHAR;
  F : FILE OF CHAR;

PROCEDURE ADD(NAME:STRING);
BEGIN
  NEW(CUR);
  CUR^.NAME := NAME;
  CUR^.NEXT :=NIL;
  IF HEAD =NIL THEN
     HEAD:= CUR
  ELSE
     LAST^.NEXT:=CUR;
  LAST:=CUR;
END;

PROCEDURE VIEW;
BEGIN
  CUR := HEAD;
  WHILE CUR <> NIL DO
    BEGIN
      WRITELN(CUR^.NAME);
      CUR:= CUR^.NEXT;
    END;
END;

PROCEDURE DESTROY;
BEGIN
  CUR := HEAD;
  WHILE CUR <> NIL DO
  BEGIN
    CUR :=CUR^.NEXT;
    DISPOSE(HEAD);
    HEAD :=CUR;
  END;
END;


BEGIN
  
  WRITE('FILE INPUT:');
  READ(FILENAME);
  ASSIGN(F,FILENAME);
  RESET(F);
  HEAD := NIL;
  S:=''; 

  WHILE NOT EOF(F) DO
    BEGIN
    READ (F,CH);
    WRITE(CH);
      IF(CH=' ')OR(ORD(CH)=10)
         THEN BEGIN
                ADD(S);
                S :='';
         END ELSE
                S += CH;
      END;
   WRITELN;
   WRITELN('QUEUE START!!');
         

  VIEW;
  DESTROY;

end.
