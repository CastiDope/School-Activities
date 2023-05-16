#include <stdio.h>

// Functions Declarations
int getStu   (FILE* spStu,
              int* stuID, int* exam1,
              int* exam2, int* final);
int writeStu  (FILE* spGrades,
               int stuID, int  avrg,  char grade);
void calcGrade (int exam1, int exam2, int final,
                int* avrg, char* grade);

int main (void)
{
// Local Declarations
    FILE* spStu;
    FILE* spGrades;
    
    int stuID;
    int exam1;
    int exam2;
    int final;
    int avrg;
    
    char grade;
    
    //Statements
    printf("Begin student grading\n");
    if (!(spStu = fopen ("student.txt", "r")))
    {
        printf("\aError opening student file\n");
        return 100;
    } // if open input
    
    if (!(spGrades = fopen ("grade.txt", "w")))
    {
        printf("\aError opening grades file\n");
        return 102;
    } // if open output
    
    while (getStu
          (spStu, &stuID, &exam1, &exam2, &final))
    {
        calcGrade (exam1, exam2, final, &avrg, &grade);
        writeStu (spGrades, stuID, avrg, grade);
    } // while
    
    fclose (spStu);
    fclose (spGrades);
    
    printf("End student grading\n");
    return 0;
} // main
          
          int getStu (FILE* spStu, int* stuID, int* exam1,
                     int* exam2, int* final)
  {
      // Local Declaration
      int ioResult;
      
      // Statements
      ioResult = fscanf(spStu, "%d%d%d%d", stuID,
                       exam1, exam2, final);
      if (ioResult == EOF)
          return 0;
      else if (ioResult != EOF)
      {
          printf("\aError reading data\n");
          return 0;
      } // if
      else
          return 1;
  } // getStu
          
  void calcGrade (int exam1, int exam2, int final,
                 int* avrg, char* grade)
  {
 // Statements
      *avrg = (exam1 + exam2 + final) / 3;
      if (*avrg >= 90)
          printf("PASSED")
          *grade = 'A';
      else if (*avrg >= 80)
          printf("PASSED")
          *grade = 'B';
      else if (*avrg >= 70)
          printf("PASSED")
          *grade = 'C';
      else if (*avrg >= 60)
          printf("PASSED")
          *grade = 'D';
      else
          printf("FAILED")
          *grade = 'F';
      return;
  } // calcGrade
          
 int writeStu  (FILE* spGrades, int stuID,
               int avrg,        char grade)
 {
     // Statements
     fprintf(spGrades, "%d &d &c\n",
                       stuID, avrg, grade);
     return 0;
 } //writeStu
 
 void resultDisplay (int* stuID, int* avrg, char* grade)
 {
     int pass;
     int failed;

     pass = 0;
     fail = 0;

    while (pass = 0)
    {
     if (*avrg >= 60)
        pass = i++;
     else
        fail = i++;
    }

     printf("Total passed student: %d", pass);
     printf("Total failed student: %d", fail);

     return;

 }