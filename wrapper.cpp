#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

void runAssignment1() {
    while (true) {
        int choice;
        std::cout << "\n--- Assignment 1: Graph Analytics (Buddy Tasks) ---\n";
        std::cout << "1. Breadth-First Search (BFS)\n";
        std::cout << "2. Depth-First Search (DFS)\n";
        std::cout << "3. Single-Source Shortest Path (SSSP)\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter your choice (0-3): ";
        std::cin >> choice;

        if (choice == 0) {
            break; 
        }

        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice! Please try again.\n";
            continue;
        }

        int run_mode;
        std::cout << "\nExecution Mode:\n";
        std::cout << "1. Run a single test case\n";
        std::cout << "2. Run all test files in batch\n";
        std::cout << "0. Cancel / Go back\n";
        std::cout << "Enter mode (0-2): ";
        std::cin >> run_mode;

        if (run_mode == 0) {
            continue;
        }

        std::string exec_filename, compile_cmd;
        if (choice == 1) {
            exec_filename = "bfs_exec";
            compile_cmd = "g++ -O3 Assignment_01/driver/graph_driver.cpp Assignment_01/src/csr_graph.cpp Assignment_01/src/bfs_dfs_algo.cpp -o Assignment_01/driver/" + exec_filename;
        } else if (choice == 2) {
            exec_filename = "dfs_exec";
            compile_cmd = "g++ -O3 Assignment_01/driver/graph_driver.cpp Assignment_01/src/csr_graph.cpp Assignment_01/src/bfs_dfs_algo.cpp -o Assignment_01/driver/" + exec_filename;
        } else {
            exec_filename = "sssp_exec";
            compile_cmd = "g++ -O3 -I Assignment_01/src Assignment_01/driver/main.cpp Assignment_01/src/sssp.cpp -o Assignment_01/driver/" + exec_filename;
        }

        if (system(compile_cmd.c_str()) != 0) {
            std::cerr << "Compilation failed for Assignment 1!\n";
            continue;
        }

        if (run_mode == 1) {
            std::string test_file;
            std::cout << "Enter test file name (e.g., graph_1.txt, sssp_10.txt): ";
            std::cin >> test_file;

            std::string actual_input = test_file;
            if (test_file.find('/') == std::string::npos && test_file.find('\\') == std::string::npos) {
                actual_input = "Assignment_01/tests/" + test_file;
            }

            size_t dot_pos = test_file.find_last_of('.');
            std::string name_no_ext = (dot_pos == std::string::npos) ? test_file : test_file.substr(0, dot_pos); 

            std::string out_file;
            std::string exec_cmd;

            if (choice == 1) {
                out_file = "Assignment_01/outputs/bfs_" + name_no_ext.substr(name_no_ext.find('_') + 1) + "_output.txt";
                exec_cmd = ".\\Assignment_01\\driver\\" + exec_filename + " bfs " + actual_input + " " + out_file;
            } else if (choice == 2) {
                out_file = "Assignment_01/outputs/dfs_" + name_no_ext.substr(name_no_ext.find('_') + 1) + "_output.txt";
                exec_cmd = ".\\Assignment_01\\driver\\" + exec_filename + " dfs " + actual_input + " " + out_file;
            } else {
                out_file = "Assignment_01/outputs/sssp_out_" + name_no_ext.substr(name_no_ext.find('_') + 1) + ".txt";
                exec_cmd = ".\\Assignment_01\\driver\\" + exec_filename + " " + actual_input + " > " + out_file;
            }

            system(exec_cmd.c_str());
            std::cout << "Execution complete. Output saved to " << out_file << "\n";
        } 
        else if (run_mode == 2) {
            std::string sizes[] = {"1", "10", "100", "1000", "10000", "50000", "100000"};

            for (int i = 0; i < 7; ++i) {
                std::string test_file = "Assignment_01/tests/graph_" + sizes[i] + ".txt";
                std::ifstream test_check(test_file.c_str());
                if (!test_check.is_open()) continue;
                test_check.close();

                std::string out_file, exec_cmd;
                if (choice == 1) {
                    out_file = "Assignment_01/outputs/bfs_" + sizes[i] + "_output.txt";
                    exec_cmd = ".\\Assignment_01\\driver\\" + exec_filename + " bfs " + test_file + " " + out_file;
                } else if (choice == 2) {
                    out_file = "Assignment_01/outputs/dfs_" + sizes[i] + "_output.txt";
                    exec_cmd = ".\\Assignment_01\\driver\\" + exec_filename + " dfs " + test_file + " " + out_file;
                } else {
                    out_file = "Assignment_01/outputs/sssp_out_" + sizes[i] + ".txt";
                    exec_cmd = ".\\Assignment_01\\driver\\" + exec_filename + " " + test_file + " > " + out_file;
                }

                system(exec_cmd.c_str());
                std::cout << "Executed test -> Saved to " << out_file << "\n";
            }
        }
        std::cout << "\n";
    }
}

void runAssignment2() {
    while (true) {
        int choice;
        std::cout << "\n--- Assignment 2: Graph Analytics ---\n";
        std::cout << "1. Triangle Counting (TC)\n";
        std::cout << "2. Betweenness Centrality (BC)\n";
        std::cout << "3. Connected Components (CC)\n";
        std::cout << "0. Back to Main Menu\n"; 
        std::cout << "Enter your choice (0-3): ";
        std::cin >> choice;

        if (choice == 0) {
            break; 
        }

        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice! Please try again.\n";
            continue;
        }

        std::string driver_src, prefix, src_file, exec_filename;
        if (choice == 1) {
            driver_src = "Assignment_02/driver/tc_driver.cpp";
            prefix = "tc";
            src_file = "triangle_counting.cpp";
            exec_filename = "tc_exec";
        } else if (choice == 2) {
            driver_src = "Assignment_02/driver/bc_driver.cpp";
            prefix = "bc";
            src_file = "betweenness_centrality.cpp";
            exec_filename = "bc_exec";
        } else if (choice == 3) {
            driver_src = "Assignment_02/driver/cc_driver.cpp";
            prefix = "cc";
            src_file = "connected_components.cpp";
            exec_filename = "cc_exec";
        }

        std::string exec_path = "Assignment_02/driver/" + exec_filename;
        std::string compile_cmd = "g++ -O3 " + driver_src + " buddy_csr.cpp Assignment_02/src/" + src_file + " -o " + exec_path;
        if (system(compile_cmd.c_str()) != 0) {
            std::cerr << "Compilation failed!\n";
            continue;
        }

        int run_mode;
        std::cout << "\nExecution Mode:\n";
        std::cout << "1. Run a single test case\n";
        std::cout << "2. Run all test files in batch\n";
        std::cout << "0. Cancel / Go back\n"; 
        std::cout << "Enter mode (0-2): ";
        std::cin >> run_mode;

        if (run_mode == 0) {
            continue; 
        }

        if (run_mode == 1) {
            std::string test_file;
            std::cout << "Enter test file path (e.g., tc_1.txt or tc_10.txt): ";
            std::cin >> test_file;

            std::string actual_input = test_file;
            if (test_file.find('/') == std::string::npos && test_file.find('\\') == std::string::npos) {
                actual_input = "Assignment_02/tests/" + test_file;
            }

            size_t last_slash = actual_input.find_last_of("/\\");
            std::string filename = (last_slash == std::string::npos) ? actual_input : actual_input.substr(last_slash + 1);
            
            size_t dot_pos = filename.find_last_of('.');
            std::string name_no_ext = (dot_pos == std::string::npos) ? filename : filename.substr(0, dot_pos);

            std::string out_file = "Assignment_02/outputs/" + name_no_ext + "_out.txt";
            
            std::string exec_cmd = ".\\Assignment_02\\driver\\" + exec_filename + " " + actual_input + " > " + out_file;
            system(exec_cmd.c_str());

            std::cout << "Execution complete. Output saved to " << out_file << "\n";
        } 
        else if (run_mode == 2) {
            std::string sizes[] = {"10", "100", "10000", "50000", "100000"};
            if (choice == 2) { 
                sizes[2] = "1000"; sizes[3] = "5000"; sizes[4] = "10000";
            }
            
            for (int i = 0; i < 5; ++i) {
                std::string test_file = "Assignment_02/tests/" + prefix + "_" + sizes[i] + ".txt";
                std::ifstream test_check(test_file.c_str());
                if (!test_check.is_open()) continue;
                test_check.close();

                std::string out_file = "Assignment_02/outputs/" + prefix + "_" + sizes[i] + "_out.txt";
                std::string exec_cmd = ".\\Assignment_02\\driver\\" + exec_filename + " " + test_file + " > " + out_file;
                system(exec_cmd.c_str());
                std::cout << "Executed " << test_file << " -> Saved to " << out_file << "\n";
            }
        }
        std::cout << "\n";
    }
}

void runAssignment3() {
    while (true) {
        int choice;
        std::cout << "\n--- Assignment 3: Buddy Tasks ---\n";
        std::cout << "1. Gradient Descent\n";
        std::cout << "2. Maxflow-Mincut\n";
        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter your choice (0-2): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > 2) {
            std::cout << "Invalid choice! Please try again.\n";
            continue;
        }

        std::string driver_src, src_file, exec_filename;
        if (choice == 1) {
            driver_src = "Assignment_03/driver/gradient_descent_driver.cpp";
            src_file = "Assignment_03/src/gradient_descent.cpp";
            exec_filename = "gd_exec";
        } else {
            driver_src = "Assignment_03/driver/maxflow_driver.cpp";
            src_file = "Assignment_03/src/maxflow_mincut.cpp";
            exec_filename = "maxflow_exec";
        }

        std::string exec_path = "Assignment_03/driver/" + exec_filename;
        std::string compile_cmd = "g++ -O3 " + driver_src + " " + src_file + " -o " + exec_path;

        if (system(compile_cmd.c_str()) != 0) {
            std::cerr << "Compilation failed for Assignment 3 task!\n";
            continue;
        }

        int run_mode;
        std::cout << "\nExecution Mode:\n";
        std::cout << "1. Run a single test case\n";
        std::cout << "2. Run all test files in batch\n";
        std::cout << "0. Cancel / Go back\n";
        std::cout << "Enter mode (0-2): ";
        std::cin >> run_mode;

        if (run_mode == 0) {
            continue;
        }

        if (run_mode == 1) {
            std::string test_file;
            std::cout << "Enter test file name (e.g., gd_01.txt or maxflow_10.txt): ";
            std::cin >> test_file;

            std::string actual_input = test_file;
            if (test_file.find('/') == std::string::npos && test_file.find('\\') == std::string::npos) {
                actual_input = "Assignment_03/tests/" + test_file;
            }

            size_t last_slash = actual_input.find_last_of("/\\");
            std::string filename = (last_slash == std::string::npos) ? actual_input : actual_input.substr(last_slash + 1);
            size_t dot_pos = filename.find_last_of('.');
            std::string name_no_ext = (dot_pos == std::string::npos) ? filename : filename.substr(0, dot_pos);

            std::string out_file = "Assignment_03/outputs/" + name_no_ext + "_out.txt";
            std::string exec_cmd;

            if (choice == 1) {
                exec_cmd = ".\\Assignment_03\\driver\\" + exec_filename + " " + actual_input + " > " + out_file;
            } else {
                exec_cmd = ".\\Assignment_03\\driver\\" + exec_filename + " " + actual_input + " " + out_file;
            }

            system(exec_cmd.c_str());
            std::cout << "Execution complete. Output saved to " << out_file << "\n";
        } 
        else if (run_mode == 2) {
            if (choice == 1) {
                std::string gd_tests[] = {"gd_01.txt", "gd_02.txt", "gd_03.txt", "gd_04.txt", "gd_05.txt"};
                for (int i = 0; i < 5; ++i) {
                    std::string test_file = "Assignment_03/tests/" + gd_tests[i];
                    std::ifstream test_check(test_file.c_str());
                    if (!test_check.is_open()) continue;
                    test_check.close();

                    std::string out_file = "Assignment_03/outputs/gd_0" + std::to_string(i+1) + "_out.txt";
                    std::string exec_cmd = ".\\Assignment_03\\driver\\" + exec_filename + " " + test_file + " > " + out_file;
                    system(exec_cmd.c_str());
                    std::cout << "Executed " << test_file << " -> Saved to " << out_file << "\n";
                }
            } else {
                std::string mf_sizes[] = {"10", "100", "1000", "10000", "50000"};
                for (int i = 0; i < 5; ++i) {
                    std::string test_file = "Assignment_03/tests/maxflow_" + mf_sizes[i] + ".txt";
                    std::ifstream test_check(test_file.c_str());
                    if (!test_check.is_open()) continue;
                    test_check.close();

                    std::string out_file = "Assignment_03/outputs/maxflow_" + mf_sizes[i] + "_out.txt";
                    std::string exec_cmd = ".\\Assignment_03\\driver\\" + exec_filename + " " + test_file + " " + out_file;
                    system(exec_cmd.c_str());
                    std::cout << "Executed " << test_file << " -> Saved to " << out_file << "\n";
                }
            }
        }
        std::cout << "\n";
    }
}

int main() {
    while (true) {
        int assignment;
        std::cout << "===============================\n";
        std::cout << "  CS509 Common Wrapper Menu    \n";
        std::cout << "===============================\n";
        std::cout << "1. Assignment 1\n";
        std::cout << "2. Assignment 2\n";
        std::cout << "3. Assignment 3\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter Assignment No: ";
        std::cin >> assignment;

        if (assignment == 1) {
            runAssignment1();
        } else if (assignment == 2) {
            runAssignment2();
        } else if (assignment == 3) {
            runAssignment3();
        } else if (assignment == 4) {
            std::cout << "Exiting wrapper. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid assignment number selected.\n";
        }
        std::cout << "\n";
    }
    return 0;
}