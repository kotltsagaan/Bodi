#include <iostream>
#include <fstream>
#include <string>

int main() {
	int sum=0, digit, k=0;
    std::string line;
    std::ifstream infile("puzzle.in");

    std::string temp;
    while (std::getline(infile, temp)) {
        for(int i=0; i<temp.length(); i++)
        {
        	if(std::isdigit(temp[i]))
        	{
        		digit = temp[i] - 48;
        		k = k*10+digit;
        		break;
        	}
		}
		for(int i=temp.length()-1; i>=0; i--)
        {
        	if(std::isdigit(temp[i]))
        	{
        		digit = temp[i] - 48;
        		k = k*10+digit;
        		break;
        	}
		}
		
		sum += k;
		k = 0;
    }
    

    infile.close();
    std::cout << "Sum is" << sum << std::endl;
    return 0;
}
