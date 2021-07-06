#include <iostream>
#include <string>

using namespace std;

class StudentResult
{
private:
    static int passingMark;
    int subjectMark[6];
    bool fail;

public:
    void setMarks(int num1, int num2, int num3, int num4, int num5, int num6)
    {
        subjectMark[0] = num1;
        subjectMark[1] = num2;
        subjectMark[2] = num3;
        subjectMark[3] = num4;
        subjectMark[4] = num5;
        subjectMark[5] = num6;
    }

    void displayMarks()
    {
        for (int i = 0; i < 6; i++)
            cout << "Course " << i + 1 << " Marks: "
                 << subjectMark[i] << endl;
    }

    void checkPassing()
    {
        fail = false;

        for (int i = 0; i < 6; i++)
            if (subjectMark[i] < passingMark) fail = true;
        
        if (fail) cout << "The student has failed the semester.\n";
        else cout << "The student has passed the semester.\n";
    }    
};

int StudentResult::passingMark = 30;

int main()
{
    StudentResult demo;

    demo.setMarks(40, 50, 60, 70, 80, 90);
    demo.displayMarks();
    demo.checkPassing();

    StudentResult another;

    another.setMarks(20, 30, 40, 50, 60, 70);
    another.displayMarks();
    another.checkPassing();

    return 0;   
}