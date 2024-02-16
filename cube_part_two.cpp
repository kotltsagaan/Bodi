#include <iostream>
#include <fstream>
#include <string>
int main() {
	int sum=0, p, k, number;
	int max_red, max_green, max_blue;
    std::string line;
    std::ifstream infile("cube.in");

    std::string temp;
	
    while (std::getline(infile, temp)) {
    	temp += "  ";
    	k=0;
    	max_red = 0;
    	max_green = 0;
    	max_blue = 0;
    	for (int i=0; i<=temp.length()-5; i++)
    	{
    		p=0;
    		number =0;
    		if( (temp[i] =='r' && temp[i+1] =='e' && temp[i+2] =='d') || 
				(temp[i] =='g' && temp[i+1] =='r' && temp[i+2] =='e' && temp[i+3] =='e' && temp[i+4] =='n') ||
				(temp[i] =='b' && temp[i+1] =='l' && temp[i+2] =='u' && temp[i+3] =='e'))
    		{
    			for (int j=i-2; j>=0; j--)
    			{
    				if(temp[j] != ' '){
    					number ++;
					}
					else break;
				}
				for(int j=i-number-1; j<=i-2; j++)
				{
					p=p*10 + temp[j]-48;
				}
				
				if(temp[i] =='r' && p>max_red) max_red = p;
				if(temp[i] =='g' && p>max_green) max_green =p;
				if(temp[i] =='b' && p>max_blue) max_blue = p;			
				
			}
			
		}
			sum += max_red * max_green * max_blue;
	}

    infile.close();
    printf("Sum is: %d",sum);
    return 0;
}
