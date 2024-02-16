#include <iostream>
#include <fstream>
#include <string>
int main() {
	int sum=0, digit_digit, digit_letter, k=0, position_digit, position_letter;
    std::string line;
    std::ifstream infile("puzzle.in");

    std::string temp;

    while (std::getline(infile, temp)) {
    	position_letter = temp.length();
    	position_digit = temp.length();
    	
    	/*ehnii toog haih uildel*/
		for(int i=0; i<temp.length(); i++)
        {
        	if(std::isdigit(temp[i]))
        	{
        		digit_digit = temp[i] - 48;
        		position_digit = i;
        		break;
        	}
		}
		/* Ehnnii usgeer bichigdsen toog haih uildel*/
		for(int i=0; i<position_digit; i++)
        {
			if(i <= temp.length()-3)
        	{
        		if(temp[i] == 'o' && temp[i+1] == 'n' && temp[i+2] == 'e') { digit_letter = 1; position_letter = i; break;}
				if(temp[i] == 't' && temp[i+1] == 'w' && temp[i+2] == 'o') { digit_letter = 2; position_letter = i; break;}
				if(temp[i] == 's' && temp[i+1] == 'i' && temp[i+2] == 'x') { digit_letter = 6; position_letter = i; break;}	
			}
			if(i <= temp.length()-4)
        	{
        		if(temp[i] == 'f' && temp[i+1] == 'o' && temp[i+2] == 'u' && temp[i+3] == 'r') { digit_letter = 4; position_letter = i; break;}
				if(temp[i] == 'f' && temp[i+1] == 'i' && temp[i+2] == 'v' && temp[i+3] == 'e') { digit_letter = 5; position_letter = i; break;}	
				if(temp[i] == 'n' && temp[i+1] == 'i' && temp[i+2] == 'n' && temp[i+3] == 'e') { digit_letter = 9; position_letter = i; break;}
			}
			if(i <= temp.length()-5)
        	{
        		if(temp[i] == 't' && temp[i+1] == 'h' && temp[i+2] == 'r' && temp[i+3] == 'e' && temp[i+4] == 'e') { digit_letter = 3; position_letter = i; break;}
				if(temp[i] == 's' && temp[i+1] == 'e' && temp[i+2] == 'v' && temp[i+3] == 'e' && temp[i+4] == 'n') { digit_letter = 7; position_letter = i; break;}
				if(temp[i] == 'e' && temp[i+1] == 'i' && temp[i+2] == 'g' && temp[i+3] == 'h' && temp[i+4] == 't') { digit_letter = 8; position_letter = i; break;}
			}	
		}
        /*usgeer bichigsen too, toogoor bichigdsen 2iin ali ni ehend baigaag shalgah*/
		if(position_letter < position_digit) {
			k=k*10+digit_letter;
			position_letter = -1;
			position_digit = -1;
		}
		else {
			k=k*10+digit_digit;
			position_letter = -1;
			position_digit = -1; 	}
		
		/*Suuliinhiig haih uildel*/
		for(int i=temp.length()-1; i>=0; i--)
        {
        	if(std::isdigit(temp[i]))
        	{
        		digit_digit = temp[i] - 48;
        		position_digit = i;
        		break;
        	}
		}
		for(int i=temp.length()-1; i>=position_digit; i--)
        {
        	if(i <= temp.length()-3)
        	{
        		if(temp[i] == 'o' && temp[i+1] == 'n' && temp[i+2] == 'e') { digit_letter = 1; position_letter = i; break;}
				if(temp[i] == 't' && temp[i+1] == 'w' && temp[i+2] == 'o') { digit_letter = 2; position_letter = i; break;}
				if(temp[i] == 's' && temp[i+1] == 'i' && temp[i+2] == 'x') { digit_letter = 6; position_letter = i; break;}	
			}
			if(i <= temp.length()-4)
        	{
        		if(temp[i] == 'f' && temp[i+1] == 'o' && temp[i+2] == 'u' && temp[i+3] == 'r') { digit_letter = 4; position_letter = i; break;}
				if(temp[i] == 'f' && temp[i+1] == 'i' && temp[i+2] == 'v' && temp[i+3] == 'e') { digit_letter = 5; position_letter = i; break;}	
				if(temp[i] == 'n' && temp[i+1] == 'i' && temp[i+2] == 'n' && temp[i+3] == 'e') { digit_letter = 9; position_letter = i; break;}
			}
			if(i <= temp.length()-5)
        	{
        		if(temp[i] == 't' && temp[i+1] == 'h' && temp[i+2] == 'r' && temp[i+3] == 'e' && temp[i+4] == 'e') { digit_letter = 3; position_letter = i; break;}
				if(temp[i] == 's' && temp[i+1] == 'e' && temp[i+2] == 'v' && temp[i+3] == 'e' && temp[i+4] == 'n') { digit_letter = 7; position_letter = i; break;}
				if(temp[i] == 'e' && temp[i+1] == 'i' && temp[i+2] == 'g' && temp[i+3] == 'h' && temp[i+4] == 't') { digit_letter = 8; position_letter = i; break;}
			}
		}
		if(position_letter > position_digit) {
			k=k*10+digit_letter;
			position_letter = -1;
			position_digit = -1;
		}
		else {
			k=k*10+digit_digit;
			position_letter = -1;
			position_digit = -1; 	}
			
		printf("%d\n",k);	
		sum += k;
		k = 0;
    }
    

    infile.close();
    
    std::cout << "Sum is" << sum << std::endl;
    return 0;
}
