
/*-----------------------------------------------------------------------------------
Author: Benziane M.Mohammed El Amine
Company: Bluefruit

Date :20/06/2015
Version:1.0.0.0

Processor: x86/x64/arm/mips
Compiler: gnu gcc compiler

Titolo/Title:Diamonds-print

Description:
Evaluation for making a program in c++ to display a charachter
shaped diamond on the system's console


------------------------------------------------------------------------------------*/
#include <QCoreApplication>
#include <iostream>
#include <cstring>
using namespace std;

/************************* Global variables declaration ***************/
char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char input_letter;
int space_index;
int i=0;
string get_line(int alphabet_index, int diamond_spacing);



/*****************************main program ****************************/
int main(int argc, char *argv[])
{

//while loop to keep the program running
 //while(1){

      //User input on the console
      cout << "Diamonds-print: ";
      cin >> input_letter ;

     // This "for" cycle finds the index of the letter that the user inputs
     for(;alphabet[i]!=input_letter;i++){space_index=i+1;}

     /*** outputing the upper half of the diamond ***/
     for(int j=0;j<=i;j++){
       cout << get_line(j,space_index) <<endl;
       space_index--;
     }

     //reassign the space_index value to use it again with the lower part of the diamond
     space_index=i-1;

     /*** outputing the lower half of the diamond ***/
     for(int x=space_index;x>=0;x--){
       cout << get_line(x,i-space_index) <<endl;
       space_index--;
     }
// }


  //application excute
    QCoreApplication a(argc, argv);
    return a.exec();

}

/*****************************getline function, return a single line of the diamond****************************/
string get_line(int alphabet_index, int diamond_spacing){

    string diamond_H_line;

    //left space appending to create the diamond structure
    for(int l=0;l<diamond_spacing;l++){
          diamond_H_line.append(" ");
    }

    if(alphabet_index==0){  //appending the first letter in the diamond which is allways "A"
        diamond_H_line.append(1,alphabet[alphabet_index]);
    }
    else {                  //appending the mirrored letters in the diamond
       diamond_H_line.append(1,alphabet[alphabet_index]);

       //appending the space in between the mirrored letters
       for(int l=1;l<(alphabet_index*2);l++){
             diamond_H_line.append(" ");
       }
       //appending the last letter on the diamond single line
       diamond_H_line.append(1,alphabet[alphabet_index]);
    }

 return diamond_H_line;
}
