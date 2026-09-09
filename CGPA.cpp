#include <iostream> 
#include <vector> 
using namespace std; 
 
struct Course{
    int credits;
    float grade;
};
void gpaCalc(int totalCredits, float totalGradePoints) { 
 
    if (totalCredits == 0) return; 
    float gpa = totalGradePoints / totalCredits; 
     
    cout << " Total Credit Hours: " << totalCredits << endl; 
    cout << " GPA: " << gpa << endl; 
     
} 
 
int main() { 
    int semC, totC, semCHour; 
    float semCGrade, totCGrade; 
    int semHours = 0; 
    float totSemGrade = 0; 
    vector<Course> allCourses; 
    Course c;
 
    cout << "Please input the number of courses you have taken this semester:" << endl; 
    cin >> semC;                                    //Totale semester course quantity 
 
    cout << "Please input the TOTAL number of courses you have taken throughout your university years:" << endl; 
    cin >> totC;                                    //Total course quantity 
 
    for (int i = 0; i < semC; i++) { 
 
        cout << "Please enter the credit hours of the course number " << i + 1 << " taken in your latest semester:" << endl; 
        cin >> semCHour; 
        semHours += semCHour;                       //Total semester credit Hours Calculated 
        
        cout << "Please enter your grade in this course:" << endl; 
        cin >> semCGrade; 
        totCGrade = semCHour * semCGrade; 
        totSemGrade += totCGrade;                   //Total semester Grades Calculated 
        
        c.credits=semCHour;
        c.grade= semCGrade;

        allCourses.push_back(c);  
 
    } 

    int courseTotCredits = semHours; 
    float totGrade = totSemGrade; 

    for (int i = semC; i < totC; i++) { 
 
        cout << "Please enter the credit hours of the course number " << i + 1 << endl; 
        cin >> semCHour; 
 
        courseTotCredits += semCHour;               //Total credit Hours calculated 
 
        cout << "Please enter your grade in this course:" << endl; 
        cin >> semCGrade; 
 
        totGrade += semCGrade * semCHour;            // Total Grade calculated 
        c.credits=semCHour;
        c.grade= semCGrade;

        allCourses.push_back(c);  
    } 
 
    cout << "\n--- Individual Course Grades ---" << endl; 

    for (auto i = 0; i < allCourses.size(); i++) { 
        cout << "Course " << i + 1 << " | Credits: " << allCourses[i].credits<< " | Grade: " << allCourses[i].grade << endl; 
    } 
 
    cout << "\n--- Semester Results ---" << endl; 
    gpaCalc(semHours, totSemGrade); 
 
    cout << "\n--- Cumulative Results ---" << endl; 
    gpaCalc(courseTotCredits, totGrade); 

}