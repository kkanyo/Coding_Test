/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    vector<int> result;
    
    for(auto& grade : grades) {
        int remainder = grade%5;
        if (grade >= 35 && remainder >= 3) {    // If grade is upper to 35
            grade += (5-remainder);             // Round to Nearest 5
        }
        result.push_back(grade);
    }
    
    return result;
}