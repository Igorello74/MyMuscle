//A file that contains all operations with LiquidMenu lib

namespace menu {
	namespace welcome {
		LiquidLine line1(0, 0, "   Welcome to   ");
		LiquidLine line2(0, 1, "MyMuscle system!");
		
		LiquidScreen scr(line1, line2);
	}
	namespace main {
		LiquidLine titleLine(0, 0, "frequency   duty");
		
		LiquidLine freqLine(0, 1, freq,"Hz");
		freqLine.set_focusPosition(Position::RIGHT);
		
		LiquidLine dutyLine(11, 1, duty,"%");
		dutyLine.set_focusPosition(Position::LEFT);

		LiquidScreen scr(titleLine, freqLine, dutyLine);
		
		/* this screen looks like so, where ← and → are focuses:
			╔═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╗
			║f║r║e║q║u║e║n║c║y║ ║ ║ ║d║u║t║y║
			╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣
			║8║H║z║←║ ║ ║ ║ ║ ║ ║ ║→║5║0║%║ ║
			╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝ */
	}
	LiquidMenu menu(lcd, welcome::scr, main::scr);
}
/*LiquidLine lines[][] = {
	{
		
	}
	{
		//
	}
}
		

LiquidScreen screens[] = {
	LiquidScreen( //welcome screen
		lines[SCR_WELCOME][0],
		lines[SCR_WELCOME][1]
	),
	LiquidScreen( //main screen
		LiquidLine(0, 0, "                "),
		LiquidLine(0, 1, "MyMuscle system!")
	)
}*/