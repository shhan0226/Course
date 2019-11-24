procedure CopyFile(SrcFileName, DestFileName: String); var 
Buffer: array[1..8192] of Char; 
SrcFile, DestFile: File; 
ReadCount, WriteCount: Integer; 
begin 
AssignFile(SrcFile, SrcFileName); 
Reset(SrcFile, 1); 
AssignFile(DestFile, DestFileName); 
Rewrite(DestFile, 1); 
repeat 
 BlockRead(SrcFile, Buffer, SizeOf(Buffer), ReadCount); 
 BlockWrite(DestFile, Buffer, ReadCount, WriteCount); 
until (ReadCount = 0) or (WriteCount < ReadCount); 
CloseFile(SrcFile); 
CloseFile(DestFile); 
end; 
