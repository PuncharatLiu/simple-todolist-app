#include <stdio.h>

// Function to clear terminal screen and shell history
void clear_terminal() {
    #ifdef _WIN32
		system("cls");  // Windows
	#else
		printf("\033[H\033[J\033[3J"); // macOS/Linux
    	fflush(stdout);
	#endif
}