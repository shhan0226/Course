program minmax(output);

var
  intarr       : array[1..10] of integer;
  i, min, max  : integer;

begin
  for i:=1 to 10 do
  begin
    intarr[i] := random(100)+1;
  end;

  write('set num ');
  i:=1;
  while i<11 do begin
    if i = 10 
      then
        writeln(intarr[i])
      else
        begin
          write(intarr[i],', ');
        end;
    i := i+1;
  end;
min := intarr[1];
  max := intarr[1];

  i := 1;
  repeat
    i := i + 1;
    if max < intarr[i] then
      max := intarr[i];
    if min > intarr[i] then
      min := intarr[i];
  until i=10;

  writeln('min num is ',min:3);
  writeln('max num is ',max:3)
end.

