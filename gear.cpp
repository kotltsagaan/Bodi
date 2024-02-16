#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
	int k, start, end, sum =0, count;
    std::ifstream infile("gear.in");

    std::vector<std::string> lines; 

	//Shine array uusgeh
    std::string line;
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }
	
    infile.close();

   
    const int rows = lines.size() + 2; 
    const int cols = (rows > 2) ? lines[0].size() + 2 : 0;
    char array[rows][cols]; 


    for (int i=0; i<rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                array[i][j] = '.'; 
            } else {
                array[i][j] = ' '; 
            }
        }
    }

    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            array[i + 1][j + 1] = lines[i][j]; 
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }

	//undsen uildluud
	
	for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < cols-1; j++) {
        	count = 0;
        	k = 0;
            if(std::isdigit(array[i][j]))
        	{
        		start = j-1;
        		end = j+1;
        		k=k*10 + array[i][j]-48;
        		while(std::isdigit(array[i][end]))
        		{
        			k=k*10 + array[i][end]-48;
        			end++;
				}
				j = end;
				for (int x = start; x <= end; x++){
					if(array[i-1][x] != '.') count ++;
					if(array[i+1][x] != '.') count ++;
				}
				if(array[i][start] != '.') count ++;
				if(array[i][end] != '.') count ++;
				
				//if(count == (start-end+2)*2) sum -= k;
				if(count > 0) {sum += k; printf ("Part is --------: %d\n",k);}
        	} 
        }
    }
	
	printf("Sum is: %d",sum);
    return 0;
}
