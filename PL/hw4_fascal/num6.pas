program num6 (input, output);

var
  CH :char;
  ST : string;

begin

  ST := '';

  read(CH);
      write('123!');
  while CH <> '*' 
    do Begin
      writeln(CH);
      ST+=CH;
      read(CH);
      writeln('!');
    end;

    writeln(ST);



end.
