program num11 (input, output);

type
  NUMBER = 1..100;
  LIST = ARRAY[NUMBER] OF STRING;
  NODEINFO = RECORD
           TITLE : PACKED ARRAY [1.. 5] OF CHAR;
           COUNT : integer;
         END;

var
  NODE : NODEINFO;
  I,J : integer;


begin
 writeln('title:');
 readln;
 for I := 1 TO 5 DO
  IF NOT EOLN
    THEN READ(NODE.TITLE[I])
    ELSE NODE.TITLE[I] := ' ';
 READLN;
 read(NODE.COUNT);
 
 writeln('title: ', NODE.TITLE);
 writeln('coutn: ', NODE.COUNT);
 
end.
