with Ada.Text_IO; use Ada.Text_IO;
procedure CallParameters is
    procedure PassModes (A: in Integer;
                        B: out Integer;
                        C: in out Integer) is
    begin
        Put_line("Enter Procedure ------");
        Put_line("A X in: :"&Integer'Image(A));
        Put_line("B Y out: :"&Integer'Image(B));
        Put_line("C Z in out: :"&Integer'Image(C));
        --A := 100;
        B := 100;
        C := 100;
        Put_line("A: :"&Integer'Image(A));
        Put_line("B: :"&Integer'Image(B));
        Put_line("C: :"&Integer'Image(C));

       Put_line("Leaving Procedure ------");   
    end PassModes;
		X : Integer := 12;
		Y : Integer := 44;
		Z : Integer := 30;
-- Main
begin
        Put_line("In Main Before Call ------");   
        Put_line("X: :"&Integer'Image(X));
        Put_line("Y: :"&Integer'Image(Y));
        Put_line("Z: :"&Integer'Image(Z));
        PassModes(X,Y,Z);
        Put_line("In Main After Call ------");   
        Put_line("X: :"&Integer'Image(X));
        Put_line("Y: :"&Integer'Image(Y));
        Put_line("Z: :"&Integer'Image(Z));
        
end CallParameters;