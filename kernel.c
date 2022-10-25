//Isaiah's Operating System Kernel
//Modified by Tom and Tim
//kernel.c

void handleInterrupt21(int,int,int,int); 
void printChar(char);
void printstring(char*);
void readstring(char*);

void main(){
	char line[80];
	printstring("Enter a line: ");
	readstring(line);
	printstring(line);
        while(1);
}

void printChar(char c){
	interrupt(0x10,0xe*256+c,0,0,0);
}

void printstring(char* letters){

	while(*letters != 0x0) {
		interrupt(0x10,0xe*256+*letters,0,0,0);
		//advance letters pointer
		letters++;
	}
}

void readstring(char output[]){
	int i=0;
	output[i] = interrupt(0x16,0,0,0,0);
	interrupt(0x10,0xe*256+output[i],0,0,0);
	while(output[i] != 0xd){
		i++;
		output[i] = interrupt(0x16,0,0,0,0);
		if(output[i] == 0x8 && i>=1){
			i--;
			output[i] = 0x20;
			printChar(0x8);
			printChar(output[i]);
			printChar(0x8);
			i--;
		}
		else if (output[i] != 0x8){
			interrupt(0x10,0xe*256+output[i],0,0,0);
		}
	}
	i++;
	output[i] = 0xa;
	interrupt(0x10,0xe*256+output[i],0,0,0);
	i++;
	output[i] = 0x0;
	interrupt(0x10,0xe*256+output[i],0,0,0);
}

void handleInterrupt21(int AX, int BX, int CX, int DX){
	printChar('T');
}
