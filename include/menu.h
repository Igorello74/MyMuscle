//A file that contains all operations with LiquidMenu lib

#define MENU_ADD_NUMB 1 //number of the editing function of menu
// #define MENU_DECR 2 //number of the decreasing function of menu

namespace menu {
	void addNumbToVar(byte &var, byte numb) {
		var = var*10 + numb;
	}
	
	namespace welcome {
		LiquidLine line1(0, 0, "   Welcome to   ");
		LiquidLine line2(0, 1, "MyMuscle system!");
		
		LiquidScreen scr(line1, line2);
	}
	namespace main {
		LiquidLine titleLine(0, 0, "frequency   duty");
		
		LiquidLine freqLine(0, 1, freq,"Hz");
		void freqEdit() {
			addNumbToVar(freq, byte(currentKey-'0'));
		}
		
		LiquidLine dutyLine(11, 1, duty,"%");
		void dutyEdit() {
			addNumbToVar(duty, byte(currentKey-'0'));
		}

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
		menu=welcome::scr;
		menu.update();
		delay(5000);
		debug("LCD greeting finished");
	}
	
	void init() {
		main::freqLine.set_focusPosition(Position::RIGHT);
		main::freqLine.attach_function(MENU_ADD_NUMB, main::freqEdit);
		
		main::dutyLine.set_focusPosition(Position::LEFT);
		main::dutyLine.attach_function(MENU_ADD_NUMB, main::dutyEdit);
		
		menu.init();
	}
}