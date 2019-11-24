Program num12;
Var S : String;
    C : Char;
    F : File of char;

begin
  read(S);
  Assign (F,S);
  Reset (F);
  C:='A';

  While not Eof(f) do
    Begin
    Read (F,C);
    Write (C);
    end;
 Writeln;
 Close (F);
end.
