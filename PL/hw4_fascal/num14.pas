Program num14(input, output);

TYPE
  NUMBER = 1..MAXINT;
  TITLE = ARRAY[NUMBER] OF STRING;
  NODEPOINTER = ^NODE;
  NODE = RECORD
           NAME: TITLE;
           NEXT: NODE
         END;
VAR
  TOP, LINKLIST : NODESTATE;
  I : INTEGER;
  S : string; 
  C : Char;
  F : File of char;
  X : TITLE;



BEGIN

  TOP = NIL;
  C:='A';
  I :=1;
  NEW(LINKLIST);
 
  LINKLIST^.NEXT := TOP;
  TOP := LINKLIST;
 
  write('file input : ');
  read(S);
  Assign(F,S);
  Reset(F);


  While not Eof(F) do
    Begin
      Read (F,C);
      Write (C);
        IF (C =' ')OR (ORD(C)=10) THEN
          I += 1
        ELSE
          X[I] += C;

    end;
 Writeln;
 Close (F);


 FOR I:=1 TO 10
  DO BEGIN
    WRITELN(X[I]);
    WRITELN(' NET');
  END;

end.
