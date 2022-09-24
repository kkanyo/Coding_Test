#include "stdc++.h"

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

#define DIVISION_STAND 5
#define FAIL_STAND 38

std::vector<int> gradingStudents(std::vector<int> nvOriginalGrades) {    
    int nIndexGrades = 0;
    int nNumStudents = nvOriginalGrades.size();
    std::vector<int> nvFinalGrades(nNumStudents);

    for (const auto &elem : nvOriginalGrades)
    {
        if ( elem < FAIL_STAND) 
        {
            nvFinalGrades[nIndexGrades] = elem;
        }
        else
        {
            int nRemainder = elem % DIVISION_STAND;
        
            if ( nRemainder < 3)
                nvFinalGrades[nIndexGrades] = elem;
            else
                nvFinalGrades[nIndexGrades] = elem + (DIVISION_STAND - nRemainder);
        }
        nIndexGrades++;
    }
    
    return nvFinalGrades;
}