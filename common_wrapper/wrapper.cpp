#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\n==============================================" << endl;
    cout << "       CS509 ASSIGNMENT 01: SSSP WRAPPER      " << endl;
    cout << "==============================================" << endl;
    cout << "1. Compile SSSP Driver" << endl;
    cout << "2. Run SSSP with a Selected Test File" << endl;
    cout << "3. Run SSSP with All Default Test Files" << endl;
    cout << "4. Exit" << endl;
    cout << "==============================================" << endl;
    cout << "Select an option (1-4): ";
}

bool compileSSSP() {
    cout << "\n[Compiling SSSP Module...]" << endl;
    
    // Compiles executable as sssp_app.exe inside assignment_01
    int status = system("g++ -O2 -I assignment_01/src assignment_01/driver/main.cpp assignment_01/src/sssp.cpp -o assignment_01/sssp_app.exe");
    
    if (status == 0) {
        cout << "Compilation successful! Executable: assignment_01\\sssp_app.exe" << endl;
        return true;
    }
    
    cout << "Error: Compilation failed. Please verify your source files." << endl;
    return false;
}

void runSingleTest() {
    string fileName;
    cout << "\nEnter ONLY the test file name (e.g., sssp_100.txt, test_01.txt): ";
    cin >> fileName;

    // Windows compatible execution path without leading './'
    string command = "assignment_01\\sssp_app.exe assignment_01\\tests\\" + fileName;
    cout << "\nExecuting command: " << command << endl;
    cout << "----------------------------------------------" << endl;
    
    int status = system(command.c_str());
    if (status != 0) {
        cout << "Execution error: Could not run test file. Make sure it exists in assignment_01\\tests\\" << endl;
    }
}

void runAllTests() {
    cout << "\n[Running SSSP Full Test Suite...]" << endl;
    
    string testSuite[] = {"test_01.txt", "sssp_10.txt", "sssp_100.txt", "sssp_1000.txt"};
    int totalFiles = 4;

    for (int i = 0; i < totalFiles; i++) {
        cout << "\n==============================================" << endl;
        cout << "Running Test Case (" << (i + 1) << "/" << totalFiles << "): " << testSuite[i] << endl;
        cout << "==============================================" << endl;
        
        string command = "assignment_01\\sssp_app.exe assignment_01\\tests\\" + testSuite[i];
        system(command.c_str());
    }
}

int main() {
    int userChoice;

    while (true) {
        displayMenu();
        if (!(cin >> userChoice)) {
            cout << "Invalid input format. Exiting wrapper system." << endl;
            break;
        }

        switch (userChoice) {
            case 1:
                compileSSSP();
                break;
            case 2:
                runSingleTest();
                break;
            case 3:
                runAllTests();
                break;
            case 4:
                cout << "Exiting SSSP wrapper system." << endl;
                return 0;
            default:
                cout << "Invalid selection! Enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}