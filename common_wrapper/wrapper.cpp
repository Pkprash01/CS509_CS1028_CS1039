#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void showMenu() {
    cout << "\n==============================================" << endl;
    cout << "   CS509 ASSIGNMENT 01: FULL BUDDY WRAPPER    " << endl;
    cout << "==============================================" << endl;
    cout << "1. Compile All Modules (SSSP, BFS, DFS, CSR)" << endl;
    cout << "2. Run SSSP Test" << endl;
    cout << "3. Run BFS Test" << endl;
    cout << "4. Run DFS Test" << endl;
    cout << "5. Run Full Test Suite (All Algorithms)" << endl;
    cout << "6. Exit" << endl;
    cout << "==============================================" << endl;
    cout << "Select an option (1-6): ";
}

bool compileAll() {
    cout << "\n[Compiling All Assignment 01 Modules...]" << endl;

    int statusSSSP = system("g++ -O2 -I Assignment_01/src Assignment_01/driver/main.cpp Assignment_01/src/sssp.cpp -o Assignment_01/sssp_app.exe");
    int statusBFSDFS = system("g++ -O2 -I Assignment_01/src Assignment_01/driver/graph_driver.cpp Assignment_01/src/bfs_dfs_algo.cpp Assignment_01/src/csr_graph.cpp -o Assignment_01/graph_app.exe");

    if (statusSSSP == 0 && statusBFSDFS == 0) {
        cout << "Compilation successful! Executables built in Assignment_01\\" << endl;
        return true;
    }

    cout << "Error during compilation! Check source files in Assignment_01\\src\\" << endl;
    return false;
}

void runSSSPTest() {
    string fileName;
    cout << "\nEnter SSSP test file name (e.g., test_01.txt, sssp_100.txt): ";
    cin >> fileName;

    string command = "Assignment_01\\sssp_app.exe Assignment_01\\tests\\" + fileName;
    cout << "\nExecuting SSSP: " << command << endl;
    cout << "----------------------------------------------" << endl;
    system(command.c_str());
}

void runBFSTest() {
    string fileName;
    cout << "\nEnter BFS test file name (e.g., test_01.txt, graph_10.txt): ";
    cin >> fileName;

    string command = "Assignment_01\\graph_app.exe bfs Assignment_01\\tests\\" + fileName;
    cout << "\nExecuting BFS: " << command << endl;
    cout << "----------------------------------------------" << endl;
    system(command.c_str());
}

void runDFSTest() {
    string fileName;
    cout << "\nEnter DFS test file name (e.g., test_01.txt, graph_10.txt): ";
    cin >> fileName;

    string command = "Assignment_01\\graph_app.exe dfs Assignment_01\\tests\\" + fileName;
    cout << "\nExecuting DFS: " << command << endl;
    cout << "----------------------------------------------" << endl;
    system(command.c_str());
}

void runTestSuite() {
    cout << "\n[Running Complete Test Suite...]" << endl;
    
    string testFiles[] = {"test_01.txt", "sssp_10.txt", "sssp_100.txt"};
    int total = 3;

    for (int i = 0; i < total; i++) {
        cout << "\n==============================================" << endl;
        cout << "Testing File (" << (i + 1) << "/" << total << "): " << testFiles[i] << endl;
        cout << "==============================================" << endl;

        string cmdSSSP = "Assignment_01\\sssp_app.exe Assignment_01\\tests\\" + testFiles[i];
        cout << "-> Running SSSP..." << endl;
        system(cmdSSSP.c_str());

        string cmdBFS = "Assignment_01\\graph_app.exe bfs Assignment_01\\tests\\" + testFiles[i];
        cout << "\n-> Running BFS..." << endl;
        system(cmdBFS.c_str());

        string cmdDFS = "Assignment_01\\graph_app.exe dfs Assignment_01\\tests\\" + testFiles[i];
        cout << "\n-> Running DFS..." << endl;
        system(cmdDFS.c_str());
    }
}

int main() {
    int choice;

    while (true) {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input format! Exiting wrapper." << endl;
            break;
        }

        switch (choice) {
            case 1:
                compileAll();
                break;
            case 2:
                runSSSPTest();
                break;
            case 3:
                runBFSTest();
                break;
            case 4:
                runDFSTest();
                break;
            case 5:
                runTestSuite();
                break;
            case 6:
                cout << "Exiting system. Good luck!" << endl;
                return 0;
            default:
                cout << "Invalid selection! Choose between 1 and 6." << endl;
        }
    }

    return 0;
}