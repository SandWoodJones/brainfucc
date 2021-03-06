#include <iostream>
#include <string>

#define MAX_CELLS 10
int main(){
	unsigned char programMemory[MAX_CELLS] = {0};
	char instruction;
	std::string input;
	int index = 0;

	do {
		instruction = getchar();
		input.push_back(instruction);
	} while (instruction != ';');

	for (char c : input){ // range based loop (new in c++11)
		switch (c){
			case '>':
				if(++index > MAX_CELLS){ // upper bound wrapping
					index = 0;
				}
				break;
			case '<':
				if(--index < 0){
					index = MAX_CELLS; // lower bound
				}
				break;
			case '+':
				programMemory[index]++;
				break;
			case '-':
				programMemory[index]--;
				break;
			case '.':
				std::cout << programMemory[index];
				break;
			case ',':
				programMemory[index] = getchar();
				break;
			case '[':
				break;
			case ']':
				break;
			default:
				break;
		}
	}

	std::cout << std::endl;
	return 0;
}