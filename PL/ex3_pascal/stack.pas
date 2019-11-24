program stack;
var
   filename: string;
   myfile: text;
begin
   writeln('Enter the file name: ');
   readln(filename);
   assign(myfile, filename);
   rewrite(myfile);
   writeln(myfile);
   close(myfile);
end.




