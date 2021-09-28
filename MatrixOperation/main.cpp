#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

class Matrices { //Establishes the class for matrices
    private: // private variables for the Matrices class
        int matrixsize;
        vector <int> matrix;
    public:
        void setSize(int size) { //sets the size of the matrices
            matrixsize = size;
        }
        
        void setMatrix(int** package, int row, int column) { //creates the matrices

            for (int i = 0; i < matrixsize; i++) {
                for (int j = 0; j < matrixsize; j++) {
                    matrix.push_back(package[i][j]); //stores the values from the 2d array into the vector
                }
            }
      
        }

        Matrices operator+(const Matrices& a) { //overloaded operator for addition
            Matrices result; // creates a matrix to store results
            result.matrixsize = a.matrixsize; //sets the resulting matrix's size
            for (int i = 0; i < a.matrix.size(); i++) {
                int add = this->matrix.at(i) + a.matrix.at(i); //adds each element of both matrices together.
                result.matrix.push_back(add); // places the result into the result matrix.

            }

            return result; //returns the result
        }
        Matrices operator-(const Matrices& a) { //overloaded operator for subtraction
            Matrices result; // creates a matrix to store results
            result.matrixsize = a.matrixsize; //sets the resulting matrix's size
            for (int i = 0; i < a.matrix.size(); i++) {
                int subtract = this->matrix.at(i) - a.matrix.at(i); //subtracts each element of both matrices together.
                result.matrix.push_back(subtract); // places the result into the result matrix.
                    
            }

            return result; //returns the result
        }
    
    Matrices operator*(const Matrices& a) { //overloaded operator for multiplication
            Matrices result; // creates a matrix to store results
            result.matrixsize = a.matrixsize; //sets the resulting matrix's size
        for(int i = 0; i < result.matrixsize; ++i) {
            for(int j = 0; j < result.matrixsize; ++j) {
                int multiply = 0;
                for(int k = 0; k < result.matrixsize; ++k) {
                     multiply += this->matrix.at(i * result.matrixsize + k) * a.matrix.at(k * result.matrixsize + j); //multiplies of the elements together.

                }
                result.matrix.push_back(multiply); // places the result into the result matrix.
            }

        }
        return result; //returns the result
        }

    Matrices operator^(int power) { //overloaded operator for exponent
            Matrices result; // creates a matrix to store results
            result.matrixsize = this->matrixsize; //sets the resulting matrix's size
        for(int i = 0; i < result.matrixsize; ++i) { //multiplies matrix^2
            for(int j = 0; j < result.matrixsize; ++j) {
                int multiply = 0;
                for(int k = 0; k < result.matrixsize; ++k) {
                     multiply += this->matrix.at(i * result.matrixsize + k) * this->matrix.at(k * result.matrixsize + j); //multiplies of the elements together.
                }
                result.matrix.push_back(multiply); // places the result into the result matrix.
            }

        }
        power--;
 
        while (power != 0) { // while loop until the operation has been done till it reaches the power.
          Matrices helper; //creates a matrix to help with the operation.
            for(int i = 0; i < result.matrixsize; ++i) {
                for(int j = 0; j < result.matrixsize; ++j) {
                    int multiply = 0;
                    for(int k = 0; k < result.matrixsize; ++k) {
                        multiply += this->matrix.at(i * result.matrixsize + k) * result.matrix.at(k * result.matrixsize + j); //multiplies of the elements together from the previous result and original matrix.

                    }
                    helper.matrix.push_back(multiply); // places the result into the helper matrix.
                }

            }

            for (int i = 0; i < result.matrix.size(); i++) {
                result.matrix.at(i) = helper.matrix.at(i); //copies the helper matrix into the result matrix.

            }
            power--; //decrements power
        }
        
            return result; //returns result
        }
    

    Matrices operator~() {
        Matrices result; // creates a matrix to store results
        result.matrixsize = this->matrixsize; //sets the resulting matrix's size
        for (int i = 0; i < this->matrixsize; i++) {
            for (int j = i; j < this->matrix.size(); j+= matrixsize) {
                int transpose = this->matrix.at(j); //stores a given element into the transpose int
                result.matrix.push_back(transpose); //stores the element into the result matrix.

            }
        }
        return result; //returns result
    }
    
    Matrices operator++(int) {
        Matrices original; // creates a original matrix
        original.matrixsize = this->matrixsize; //saves the size of matrix into original.
        for (int i = 0; i < this -> matrix.size(); i++) {
            original.matrix.push_back(this->matrix.at(i)); // copies elements of the matrix before incrementing them.
            this->matrix.at(i) = this->matrix.at(i) + 1; //increments each element of the matrix.

        }
        
        return original; // returns original matrix
    }
    Matrices operator++() {
        Matrices result; // creates a result matrix
        result.matrixsize = this->matrixsize; //saves the size of the matrix into result.
        for (int i = 0; i < this -> matrix.size(); i++) {
            this->matrix.at(i) = this->matrix.at(i) + 1; //increments each element of the matrix.
            result.matrix.push_back(this->matrix.at(i)); //stores each element of the matrix into result.
        }
        return result; // returns result matrix
    }


    Matrices operator--(int) {
        Matrices original; // creates a original matrix
        original.matrixsize = this->matrixsize; //saves the size of matrix into original.
        for (int i = 0; i < this -> matrix.size(); i++) {
            original.matrix.push_back(this->matrix.at(i)); // copies elements of the matrix before decrementing them.
            this->matrix.at(i) = this->matrix.at(i) - 1; //decrements each element of the matrix.

        }
        
        return original; // returns original matrix
    }
    
    Matrices operator--() {
        Matrices result; // creates a result matrix
        result.matrixsize = this->matrixsize; //saves the size of the matrix into result.
        for (int i = 0; i < this -> matrix.size(); i++) {
            this->matrix.at(i) = this->matrix.at(i) - 1; //decrements each element of the matrix.
            result.matrix.push_back(this->matrix.at(i)); //stores each element of the matrix into result.
        }
        return result; // returns result matrix
    }

        friend ostream& operator<<(ostream& printer, const Matrices& z); //friend function for printing matrix.
        
};


 
ostream& operator<<(ostream& printer, const Matrices& z) { //prints the matrix
  int size = z.matrixsize; // stores matrix size into size.
  int helper = 0;
    for (int i = 0; i < z.matrix.size(); i++) {
        cout << z.matrix.at(i) << " "; //prints elements of the matrix.
        helper++;
        if (helper == size) { //checks if it reaches the end of a row.
          cout << " " << endl; //ends the line.
          helper = 0; //resets helper
        }
    }
        return printer; //ends the function

}


int main() {
    //creates two matrices, one for storing input, and one for result.
    Matrices a;
    Matrices finale;
    //creates ifstream
    ifstream operate;
    
    //asks the user what file they want to open and stores it into input
    string input;
    cout << "Which file would you like to open?" << endl;
    cin >> input;
    
    //opens input file
    operate.open(input);
    //gets the size of the matrix
    string copy;
    getline(operate, copy);
    //converts the size into an int and stores it.
    stringstream convert(copy);
    int size;
    convert >> size;
    if (size == 1) { //checks if the matrix is a 1x1
        //gets the content of the matrix and stores it
        string oneline;
        getline(operate, oneline);
        // converts the matrix number into an int
        stringstream oneconverter(oneline);
        int matrix;
        oneconverter >> matrix;
        
        // gets the operator choice and stores it
        string operatorone;
        getline(operate, operatorone);
        
        if (operatorone == "op 1") { //checks if the user wants to add matrices.
            //gets the content of the matrix and stores it
            string einline;
            getline(operate, einline);
            // converts the matrix number into an int
            stringstream einconverter(einline);
            int matrix2;
            einconverter >> matrix2;
            
            int finalmatrix = matrix + matrix2; //adds the matrix
            cout << finalmatrix << endl; //prints matrix
	    exit(0);
        }
        if (operatorone == "op 2") { //checks if the user wants to subtract matrices.
            //gets the content of the matrix and stores it
            string einline;
            getline(operate, einline);
            // converts the matrix number into an int
            stringstream einconverter(einline);
            int matrix2;
            einconverter >> matrix2;
            
            int finalmatrix = matrix - matrix2; //subtract the matrix
            cout << finalmatrix << endl; //prints matrix
	    exit(0);
        }
        

        if (operatorone == "op 3") { //checks if the user wants to multiply matrices.
            //gets the content of the matrix and stores it
            string einline;
            getline(operate, einline);
            // converts the matrix number into an int
            stringstream einconverter(einline);
            int matrix2;
            einconverter >> matrix2;
            
            int finalmatrix = matrix * matrix2; //multiply the matrix
            cout << finalmatrix << endl; //prints matrix
	    exit(0);
        }
        if (operatorone == "op 4") { //checks if the user wants to increment the matrix
            int finale = matrix++;
            cout << "finale: " << finale << endl;
            cout << "matrix: " << matrix << endl;
	    exit(0);
        }
        if (operatorone == "op 5") { //checks if the user wants to decrement the matrix
            int finale = matrix--;
            cout << "finale: " << finale << endl;
            cout << "matrix: " << matrix << endl;
	    exit(0);
        }
        if (operatorone == "op 6" || operatorone == "op 8" ) { //checks if the user wants to transpose the matrix or just print the matrix.
            cout << matrix << endl;
	    exit(0);
            
        }
        if (operatorone == "op 7") { //checks if the user wants to increase the matrix by a power.
            //asks what power the user want to increase the matrix by and stores it.
            int powah;
            cout << "What exponent would you like to increase the matrices by?" << endl;
            cin >> powah;
            //does the operation and prints it
            int finale = pow(matrix, powah);
            cout << finale << endl;
	    exit(0);
        }
    }
    
    //stores the size into the Matrices class
    a.setSize(size);
    
    // creates 2d array to store the matrix values from the input as ints.
    int** matrix1 = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix1[i] = new int[size];
    }

    
    for (int i = 0; i < size; i++) {
        int j = 0;
        while(j < size) { //while loop until it reaches end of the row.
            string line;
            getline(operate, line); //gets next line from file.
            int getter = 0;
            int where = 0;
            long linesize = line.length();
            if (line.at(linesize - 1) != ' ') { //checks if there is no space at the end of the matrix row
                line += ' ';
            }
            while (getter < size) { //while loop until it reaches end of the row.
                string cursive;
                while (line.at(where) != ' ') { //while loop until it gets a number.
                    cursive += line.at(where); // stores the number into to the cursive string
                    where++;

                }
                where++; //increments location of cursor on string
                getter++; //increments where the getter is in the row.
                 
                //converts the number into an int and stores it into place.
                stringstream converter(cursive);
                int place;
                converter >> place;
                
                matrix1[i][j] = place; //stores the number into matrix
                j++; //increments array location
            }
            
            
        }
        

    }

    a.setMatrix(matrix1, size, size); //sets the matrix and stores it.


    string opchoice;
    getline(operate, opchoice); //gets the operator and stores it into opchoice
    
    if (opchoice == "op 1") { //checks if the user wants to add two matrices
        Matrices b; //creates another Matrices to store the second matrix.
        b.setSize(size); //stores size into Matrices class
        
    // creates 2d array to store the matrix values from the input as ints.
    int** matrix2 = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix2[i] = new int[size];
    }

    
    for (int i = 0; i < size; i++) {
        int j = 0;
        while(j < size) { //while loop until it reaches end of the row.
            string line;
            getline(operate, line); //gets next line from file.
            int getter = 0;
            int where = 0;
            long linesize = line.length();
            if (line.at(linesize - 1) != ' ') { //checks if there is no space at the end of the matrix row
                line += ' ';
            }
            while (getter < size) { //while loop until it reaches end of the row.
        string cursive;
                while (line.at(where) != ' ') { //while loop until it gets a number.
                    cursive += line.at(where); // stores the number into to the cursive string
                    where++;

                }
                where++; //increments location of cursor on string
                getter++; //increments where the getter is in the row.
                 
                //converts the number into an int and stores it into place.
                stringstream converter(cursive);
                int place;
                converter >> place;
                
                matrix2[i][j] = place; //stores the number into matrix
                j++; //increments array location
            }
            
            
        }
        

    }
        b.setMatrix(matrix2, size, size); //sets the matrix and stores it.
        finale = a + b; //adds the matrices.
        cout << finale; //prints the resulting matrix.


        
    }
    
    if (opchoice == "op 2") { //checks if the user wants to subtract two matrices
        Matrices b; //creates another Matrices to store the second matrix.
        b.setSize(size); //stores size into Matrices class
        
    // creates 2d array to store the matrix values from the input as ints.
    int** matrix2 = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix2[i] = new int[size];
    }

    
    for (int i = 0; i < size; i++) {
        int j = 0;
        while(j < size) { //while loop until it reaches end of the row.
            string line;
            getline(operate, line); //gets next line from file.
            int getter = 0;
            int where = 0;
            long linesize = line.length();
            if (line.at(linesize - 1) != ' ') { //checks if there is no space at the end of the matrix row
                line += ' ';
            }
            while (getter < size) { //while loop until it reaches end of the row.
        string cursive;
                while (line.at(where) != ' ') { //while loop until it gets a number.
                    cursive += line.at(where); // stores the number into to the cursive string
                    where++;

                }
                where++; //increments location of cursor on string
                getter++; //increments where the getter is in the row.
                 
                //converts the number into an int and stores it into place.
                stringstream converter(cursive);
                int place;
                converter >> place;
                
                matrix2[i][j] = place; //stores the number into matrix
                j++; //increments array location
            }
            
            
        }
        

    }
        b.setMatrix(matrix2, size, size); //sets the matrix and stores it.
        finale = a - b; //subtracts the matrices.
        cout << finale; //prints the resulting matrix.


        
    }
    
    
      if (opchoice == "op 3") { //checks if the user wants to multiply two matrices
          Matrices b; //creates another Matrices to store the second matrix.
          b.setSize(size); //stores size into Matrices class
          
      // creates 2d array to store the matrix values from the input as ints.
      int** matrix2 = new int*[size];
      for (int i = 0; i < size; i++) {
          matrix2[i] = new int[size];
      }
      
      for (int i = 0; i < size; i++) {
          int j = 0;
          while(j < size) { //while loop until it reaches end of the row.
              string line;
              getline(operate, line); //gets next line from file.
              int getter = 0;
              int where = 0;
              long linesize = line.length();
              if (line.at(linesize - 1) != ' ') { //checks if there is no space at the end of the matrix row
                  line += ' ';
              }
              while (getter < size) { //while loop until it reaches end of the row.
          string cursive;
                  while (line.at(where) != ' ') { //while loop until it gets a number.
                      cursive += line.at(where); // stores the number into to the cursive string
                      where++;

                  }
                  where++; //increments location of cursor on string
                  getter++; //increments where the getter is in the row.
                   
                  //converts the number into an int and stores it into place.
                  stringstream converter(cursive);
                  int place;
                  converter >> place;
                  
                  matrix2[i][j] = place; //stores the number into matrix
                  j++; //increments array location
              }
              
              
          }
          

      }
          b.setMatrix(matrix2, size, size); //sets the matrix and stores it.
          finale = a * b; //multiplies the matrices.
          cout << finale; //prints the resulting matrix.
          
      }
      
    
    if (opchoice == "op 4") { //checks if the user wants to increment the matrix
        finale = a++; //increments the matrix.
        //prints both matrices.
        cout << "a: " << endl;
        cout << a;
        cout << "finale: " << endl;
        cout << finale;
    }
    
    if (opchoice == "op 5") { //checks if the user wants to increment the matrix
        finale = a--; //decrements the matrix.
        //prints both matrices.
        cout << "a: " << endl;
        cout << a;
        cout << "finale: " << endl;
        cout << finale;

        
    }
    if (opchoice == "op 6") { //checks if the user wants to transpose the matrix
        finale = ~a; //transposes the matrix
        cout << finale; //prints the matrix.
    }
    
  if (opchoice == "op 7") { //checks if the user wants to increase the matrix by a power.
      //asks what power the user want to increase the matrix by and stores it.
      int powah;
      cout << "What exponent would you like to increase the matrices by?" << endl;
      cin >> powah;
      
      //checks if the user just wants to raise by power by 1
      if (powah == 1) {
        cout << a; // prints the matrix
      }
      else {
      powah = powah - 1; // decrements powah by 1 given the nature of the operator
    
      finale = a^powah; // increases a by the user-inputted power.
      cout << finale; //prints the matrix.
      }
  }

  if (opchoice == "op 8") { //checks if the user just wants to print the matrix.
    cout << a; // prints the matrix
  }
    operate.close(); //closes the file.
    return 0;
}
 
