/*
Field include the logic from the video lecture but commented
Implemented logic based on the blackboard prompt by using the two coordinates and using its min and max to find the left most and right most coordinate

Throw_excpetion does not work 

future improvement:
improve throw_excpetion error


*/




#include "Field.h"
#include <stdexcept> //std::out_of_range
#include <iostream> //std::cerr


//copy constructor
Field::Field(const std::vector <std::vector<int>>& obj):
	my_vector(obj), row(obj.size()), column(obj[0].size())
{	
	//resize the sum_vector by using my_vector's row and my_vector's column
	sum_vector.resize(my_vector.size(), std::vector<int>(my_vector[0].size()));

	//iterating through the vector
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			//put the first element into the sum_vector
			if (i == 0 && j == 0) {
				sum_vector[i][j] = my_vector[i][j];
			}
			//compute the sum of the first row
			else if (i == 0) {
				sum_vector[i][j] = my_vector[i][j] + sum_vector[i][j - 1];
			}
			//compute the sum of the first column
			else if (j == 0) {
				sum_vector[i][j] = my_vector[i][j] + sum_vector[i - 1][j];
			}
			//for any other sum, we follow the logic of the current cell + the sum computed on the previous row + the sum computed on the previous column - the depulicate sum
			else {
				sum_vector[i][j] = my_vector[i][j] + sum_vector[i - 1][j] + sum_vector[i][j - 1] - sum_vector[i - 1][j - 1];
			}
		}
	}
}

//move constructor
Field::Field(std::vector<std::vector<int>>&& obj):
	my_vector(obj), row(obj.size()),column(obj[0].size())
{
	//resize the sum_vector by using my_vector's row and my_vector's column
	sum_vector.resize(my_vector.size(), std::vector<int>(my_vector[0].size()));

	//iterating through the vector
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			//put the first element into the sum_vector
			if (i == 0 && j == 0) {
				sum_vector[i][j] = my_vector[i][j];
			}
			//compute the sum of the first row
			else if (i == 0) {
				sum_vector[i][j] = my_vector[i][j] + sum_vector[i][j - 1];
			}
			//compute the sum of the first column
			else if (j == 0) {
				sum_vector[i][j] = my_vector[i][j] + sum_vector[i - 1][j];
			}
			//for any other sum, we follow the logic of the current cell + the sum computed on the previous row + the sum computed on the previous column - the depulicate sum
			else {
				sum_vector[i][j] = my_vector[i][j] + sum_vector[i - 1][j] + sum_vector[i][j - 1] - sum_vector[i - 1][j - 1];
			}
		}
	}
}


/*
	//if the first coordinate is my_vector[0][0], the sum will be the sum of the second coordinate
	if (x1 == 0 && y1 == 0) {
		sum_of_rect = sum_vector[x2][y2];
	}
	//top left to right bottom
	//the sum of the rectangle will be the sum of the whole rectangle - the previous row sum at the second coordinate column
	//- the previous column sum at second coordniate row + the part we substracted twice
	else if (x1 < x2 && y1 < y2) {
		//if the first coordinate is in column 0
		if (y1 == 0) {
			sum_of_rect = sum_vector[x2][y2] - sum_vector[x1 - 1][y2];
		}
		//if the first coordinate is in row 0
		else if (x1 == 0) {
			sum_of_rect = sum_vector[x2][y2] - sum_vector[y1][x2 - 1];
		}
		else {
			sum_of_rect = sum_vector[x2][y2] - sum_vector[x1 - 1][y2] - sum_vector[x2][y1 - 1] + sum_vector[x1 - 1][y1 - 1];
		}
	}
	//bottom left to right top
	else if (x1 > x2 && y1 < y2) {
		//if the first coordinate is in column 0 
		if (y1 == 0) {
			sum_of_rect = sum_vector[x1][y2] - sum_vector[x2 - 1][y2];
		}
		//if the second coordinate is in row 0
		else if (x2 == 0) {
			sum_of_rect = sum_vector[x1][y2] - sum_vector[x1][y1 - 1];
		}
		else {
			//(x1,y2) = the rectangle whole sum - previous row sum - previous column sum + duplicate
			sum_of_rect = sum_vector[x1][y2] - sum_vector[x2 - 1][y2] - sum_vector[x1][y1 - 1] + sum_vector[x2 - 1][y1 - 1];
		}

	}
	//top right to left bottom
	else if (x1 < x2 && y1 > y2) {
		//if the second coordinate is in column 0
		if (y2 == 0) {
			sum_of_rect = sum_vector[x2][y1] - sum_vector[x1-1][y1]

		}
		else if (x1 == 0) {

		}
		//if the first coordinate is in row 0
		sum_of_rect = sum_vector[x2][y1] - sum_vector[x1 - 1][y1] - sum_vector[x2][y2 - 1] + sum_vector[x1 - 1][y2 - 1];

	}
	//right bottom to left top
	else if (x1 > x2 && y1 > y2) {
		sum_of_rect = sum_vector[x1][y1] - sum_vector[x1][y2 - 1] - sum_vector[x2 - 1][y1] + sum_vector[x2 - 1][y2 - 1];
	}

	//return the sum of the rectangle given by the coordinate
	return sum_of_rect;
	original logic given, when messed up with professor's video logic and the promp logic, in this case x and y should be reversed
*/
int Field::Weight(const int x1, const int y1, const int x2, const int y2) const{
	int sum_of_rect = 0;
	//two error throwing is not working as expected
	//thus breaking from function
	if ( (y1 > row) || (x1 > column)|| (y1<0)||(x1<0)) {
		return 1;
		throw std::out_of_range("\n ERROR: first coordinate is out of range");
		
	}
	if ((y2 > row)||( x2 > column)||(y2 < 0)|| (x2 < 0)) {
		return 1;
		throw std::out_of_range("\n ERROR: second coordinate is out of range");
	}
	else {
		//since x and y is reverse of row and column
		//left top row is the min of the two value 
		//left top column is the min of the two value
		int top_row = Min_of_2(y1, y2);
		int top_column = Min_of_2(x1, x2);
		//right bottom row is the max of the two value
		int bottom_row = Max_of_2(y1, y2);
		//right bottom column is the max of the two value
		int bottom_column = Max_of_2(x1, x2);
		//if it ask for the rectagnle start at 0
		if (top_row == 0 && top_column == 0) {
			sum_of_rect = sum_vector[bottom_row][bottom_column];
		}
		//if the asked rectangle is at the left most _column
		else if (top_column == 0) {
			sum_of_rect = sum_vector[bottom_row][bottom_column] - sum_vector[top_row - 1][bottom_column];
		}
		//if the asked rectangle is at the top row
		else if (top_row == 0) {
			sum_of_rect = sum_vector[bottom_row][bottom_column] - sum_vector[bottom_row][top_column - 1];
		}
		//everything else we subtract the left sum and the top sum and add the duplicate
		else {
			sum_of_rect = sum_vector[bottom_row][bottom_column] - sum_vector[bottom_row][top_column - 1] - sum_vector[top_row - 1][bottom_column] + sum_vector[top_row - 1][top_column - 1];
		}

		return sum_of_rect;

	}

}

//PathCost function
int Field::PathCost() const {
	//create a dp vector
	std::vector<std::vector<int>> cost;
	//resize to my_vector size
	cost.resize(my_vector.size(), std::vector<int>(my_vector[0].size()));
	for (int i = 0; i < my_vector.size(); i++) {
		for (int j = 0; j < my_vector[0].size(); j++) {
			//copy the first element
			if (i == 0 && j == 0) {
				cost[i][j] = my_vector[i][j];
			}
			//compute the element while row is 0 logic is add the previous row value
			else if (i == 0) {
				cost[i][j] = my_vector[i][j] + cost[i][j - 1];
			}
			//compute the element while column i 0 logic is add the previous column value
			else if (j == 0) {
				cost[i][j] = my_vector[i][j] + cost[i - 1][j];
			}
			//everything else we find the min of two precomputed value and add the current value at vector
			else {
				cost[i][j] = my_vector[i][j] + Min_of_2(cost[i - 1][j], cost[i][j - 1]);
			}
		}
	}
	//return the computed value - 1 because the size needs to -1 in the vector
	return cost[my_vector.size()-1][my_vector[0].size() - 1];
}

//function to find min of two int
int Field::Min_of_2(const int x, const int y) const {
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
}
//function to fine max of two int
int Field::Max_of_2(const int x, const int y) const {
	if (x > y) {
		return x;
	}

	else {
		return y;
	}
}
