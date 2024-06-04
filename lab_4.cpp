#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ChessPiece 
{
private:
    string name;
    string color;
    char positionX;
    int positionY;

public:
    // The default constructor
    ChessPiece() : name("Pawn"), color("White"), positionX('A'), positionY(2) 
    {
        cout << "The default constructor\n";
    }

    // Constructor with parameters
    ChessPiece(const string& name, const string& color, char positionX, int positionY)
        : name(name), color(color), positionX(positionX), positionY(positionY) 
    {
        cout << "Constructor with parameters\n";
    }

    // Builder with default options
    ChessPiece(const string& name) : ChessPiece(name, "White", 'A', 2) 
    {
        cout << "Builder with default optionsn";
    }

    // Constructor with an initialization list
    ChessPiece(initializer_list<string> initList) 
    {
        if (initList.size() == 4) 
        {
            auto it = initList.begin();
            name = *it++;
            color = *it++;
            positionX = (*it++).at(0);
            positionY = stoi(*it);
        }
        else 
        {
            name = "Pawn";
            color = "White";
            positionX = 'A';
            positionY = 2;
        }
        cout << "Constructor with an initialization list\n";
    }

    // Copy constructor
    ChessPiece(const ChessPiece& other)
        : name(other.name), color(other.color), positionX(other.positionX), positionY(other.positionY) 
    {
        cout << "Copy constructor\n";
    }

    // Destructor
    ~ChessPiece() 
    {
       cout << "Destructor\n";
    }

    // Methods for working with a figure
    void move(char newX, int newY) 
    {
        positionX = newX;
        positionY = newY;
    }

    void print() const {
        cout << "Figure: " << name << ", Ñolor: " << color << ", Position: " << positionX << positionY << endl;
    }

    // Access methods to class elements
    string getName() const { return name; }

    string getColor() const { return color; }

    char getPositionX() const { return positionX; }

    int getPositionY() const { return positionY; }

    void setName(const string& newName) { name = newName; }

    void setColor(const string& newColor) { color = newColor; }

    void setPositionX(char newPositionX) { positionX = newPositionX; }

    void setPositionY(int newPositionY) { positionY = newPositionY; }
};

// A function for working with an array of class instances
void manipulateArray(vector<ChessPiece>& pieces) 
{
    for (auto& piece : pieces) {
        piece.print();
    }
}

int main() {
    // Using the default constructor
    ChessPiece piece1;
    piece1.print();

    // Using a constructor with parameters
    ChessPiece piece2("Rook", "Black", 'H', 8);
    piece2.print();

    // Using the constructor with default parameters
    ChessPiece piece3("Knight");
    piece3.print();

    // Using a constructor with an initialization list
    ChessPiece piece4({ "Bishop", "White", "C", "1" });
    piece4.print();

    // Using the copy constructor
    ChessPiece piece5(piece2);
    piece5.print();

    // Working with an array of class instances
    vector<ChessPiece> pieces = { piece1, piece2, piece3, piece4, piece5 };
    manipulateArray(pieces);

    return 0;
}