program num10 (input, output);

type
  NUMBER = 1..100;
  LIST = ARRAY[NUMBER] OF STRING;

var
  I,J : integer;
  CH : char;
  X : LIST;
  CASH, TAX : REAL;

function dollar(CASH:REAL):REAL;
  VAR
    PE:REAL;
  BEGIN
    PE := CASH+10;
    dollar :=PE;
  END;
  
PROCEDURE EXCHA (VAR A, B: INTEGER);
  VAR
    SAVE: INTEGER;
  BEGIN
    SAVE := A;
    A:= B;
    B:= SAVE;
  END;

begin
  READ(I,J);
  WRITELN(I,J);
  EXCHA(I,J);
  WRITELN(I,J);
 
  READ(CASH);
  WRITELN(dollar(CASH));
  
  
end.
