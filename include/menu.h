//A file that contains all operations with LiquidMenu lib

#define MENU_ADD_DIGIT 1 //number of the editing function of menu
#define MENU_CLEAN     2 //number of the decreasing function of menu
#define MENU_RETURN    3
#define MENU_INCR      4
#define MENU_DECR      5

namespace menu {
	void addDigitToVar(byte &var, byte numb) {
		var = var*10 + numb;
	}
	
	void returnChar(byte &var) { //removes the last char in a var (like backspace)
		var = var/10;
	}
	
	namespace welcome {
		LiquidLine line1(0, 0, "   Welcome to   ");
		LiquidLine line2(0, 1, "MyMuscle system!");
		
		LiquidScreen scr(line1, line2);
	}
	namespace main {
		LiquidLine titleLine(0, 0, "frequency   duty");
		
		LiquidLine freqLine(0, 1, freq," Hz");
		void freqEdit() {
			addDigitToVar(freq, byte(currentKey-'0'));
		}
		void freqClean() {
			freq = 0;
		}
		void freqReturn() {
			returnChar(freq);
		}
		void freqIncr() {
			freq++;
		}
		void freqDecr() {
			freq--;
		}
		
		LiquidLine dutyLine(11, 1, duty,"%");
		void dutyEdit() {
			addDigitToVar(duty, byte(currentKey-'0'));
		}
		
		void dutyClean() {
			duty = 0;
		}
		void dutyReturn() {
			returnChar(duty);
		}
		void dutyIncr() {
			duty++;
		}
		void dutyDecr() {
			duty--;
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
		main::freqLine.attach_function(MENU_ADD_DIGIT, main::freqEdit);
		main::freqLine.attach_function(MENU_CLEAN, main::freqClean);
		main::freqLine.attach_function(MENU_RETURN, main::freqReturn);
		main::freqLine.attach_function(MENU_INCR, main::freqIncr);
		main::freqLine.attach_function(MENU_DECR, main::freqDecr);
		
		main::dutyLine.set_focusPosition(Position::LEFT);
		main::dutyLine.attach_function(MENU_ADD_DIGIT, main::dutyEdit);
		main::dutyLine.attach_function(MENU_CLEAN, main:: dutyClean);
		main::dutyLine.attach_function(MENU_RETURN, main:: dutyReturn);
		main::dutyLine.attach_function(MENU_INCR, main::dutyIncr);
		main::dutyLine.attach_function(MENU_DECR, main::dutyDecr);
		
		menu.init();
	}
}