
//Isaiah's Operating System Kernel
//Modified by Tom and Tim
//kernel.c

void printstring(char*);

void main(){
        printstring("Hello World\0");
        while(1);
}

void printstring(char* letters){

	int startVidMem = 0xb800;
	int vidMemOffset = 0x0;
	int white = 0x7;

	while(*letters != 0x0) {
		putInMemory(startVidMem, vidMemOffset, *letters);
		vidMemOffset++;
		putInMemory(startVidMem, vidMemOffset, white);
		vidMemOffset++;
		//advance letters pointer
		letters++;
	}
}
