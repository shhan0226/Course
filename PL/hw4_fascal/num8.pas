program num8 (input, output);

type
  NUMBER = 1..100;
  LIST = ARRAY[NUMBER] OF STRING;

var
  I : integer;
  CH : char;
  X : LIST;
  

begin

  read(CH);
  I:=1;

  WHILE CH <> '*' DO 
   BEGIN
    
      if (CH = ' ') or (CH = '	') or(ord(CH)=10) then
        I += 1
      else 
        X[I] += CH;   

      WRITELN(CH);
      READ(CH);
    END;


  writeln('---------------------');
  FOR I:=1 TO 10 
    DO BEGIN
       WRITELN(X[I]);
       WRITELN(' NEXT');
    END;
       
 
  writeln('---------------------');
  WRITELN(X[1]); 
  WRITELN(X[2]);

end.
