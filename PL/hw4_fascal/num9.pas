program  SHOWTEXT ( infile, input, output );
var   ch : char;
    fname : packed array [1..15] of char;
    infile: TEXT;

begin
	    writeln('Please enter name of text file to display.');
	    readln( fname );

	    reset( infile, fname );     {open a file using filename stored in}
	                                {array fname                         }
	    while not eof( infile ) do
	    begin
	       while not eoln( infile ) do
	       begin
	           read( infile, ch );
	           write( ch )
	       end;
	       readln( infile );       {read  eoln character}
	       writeln                 {write eoln character}
	    end;
	    close( infile )             {close filename specified by fname}
end.
