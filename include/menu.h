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
		LiquidLine dutyLine(11, 1, duty,"%");

		LiquidScreen scr(titleLine, freqLine, dutyLine);
		
		/* this screen looks like so, where ← and → are focuses:
			╔═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╦═╗
			║f║r║e║q║u║e║n║c║y║ ║ ║ ║d║u║t║y║
			╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣
			║8║H║z║←║ ║ ║ ║ ║ ║ ║ ║→║5║0║%║ ║
			╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝ */
	}
	
	LiquidMenu menu(lcd, welcome::scr, main::scr);
	
	void greeting() {
		debug("LCD greeting started");
		menu::menu=menu::welcome::scr;
		menu::menu.update();
		delay(5000);
		debug("LCD greeting finished");
	}
	
	void init() {
		main::freqLine.set_focusPosition(Position::RIGHT);
		main::dutyLine.set_focusPosition(Position::LEFT);
		menu.init();
	}
}