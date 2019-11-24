Program num13(input, output);

TYPE
  NUMBER = 1..MAXINT;
  LIST = ARRAY[NUMBER] OF STRING;

Var
  I : INTEGER;
  S : string; 
  C : Char;
  F : File of char;
  X : LIST;

begin
  write('file input : ');
  read(S);
  Assign(F,S);
  I :=1;
  Reset(F);
  C:='A';


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
