#ifndef _FIELD_HPP_
#define _FIELD_HPP_

#include <iostream>
#include <vector>


class Field {
public:
	//copy constructor
	Field(const std::vector <std::vector<int>>& obj);
	//move constructor
	Field(std::vector<std::vector<int>>&& obj);
	//weight function, return the sum of the rectangle by given coordinates
	int Weight( const int x1, const int y1, const int x2, const int y2) const;
	//return the minium cost path
	int PathCost() const; 
	//self-made function return the min
	int Min_of_2(const int x, const int y) const;
	//self-made functon return the max
	int Max_of_2(const int x, const int y) const;




private:
	//my_vector
	std::vector<std::vector<int>> my_vector;
	//dp_ sum_vector
	std::vector<std::vector<int>> sum_vector;
	int row, column;
};





#endif