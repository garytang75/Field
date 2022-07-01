#include "Field.h"

using namespace std;

void printMatrix(const vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{

    vector<vector<int>> v(5, vector<int>(6));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 6; j++)
            v[i][j] = j + 1;

    // Prints the 2D vector 
    printMatrix(v);

    // Invokes the first constructor
    Field field1 = Field(v);
    cout << "\nField 1 \n";
    cout << field1.Weight(1, 5, 4, 0) << "\n";
    cout << field1.PathCost() << "\n";

    // Invokes the second constructor as the value passed is a rvalue reference
    Field field2 = Field({ {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,4,5,6} });
    cout << "\nField 2 \n";
    cout << field2.Weight(1, 1, 1, 1) << "\n";
    cout << field2.PathCost() << "\n";

    return 0;
}