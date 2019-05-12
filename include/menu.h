//A file that contains all operations with LiquidMenu lib

#define SCR_WELCOME 0
#define SCR_MAIN 1

namespace menu {
	namespace welcome {
		LiquidLine line1(0, 0, "   Welcome to   ");
		LiquidLine line2(0, 1, "MyMuscle system!");
		
		LiquidScreen scr(line1, line2);
	}
	namespace 
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