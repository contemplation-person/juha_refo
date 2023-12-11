#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>

typedef enum
{
    RED,
    GREEN,
    WHITE,
} t_color;

int ft_print(std::string message, t_color color)
{
    std::string print[] = {"\033[31m", "\033[32m", "\033[0m"};
    std::cout << print[color] << message << std::endl;
    return (color);
}

bool norm_test()
{
    std::ifstream ifs;
    std::string line;

    ft_print("Norm test", WHITE);
	system("norminette ex00 | grep Error > result/norm.txt");
    sleep(1);
    ifs.open("result/norm.txt");
    if(std::getline(ifs, line))
        exit(ft_print("Norm error", RED));
    ifs.close();
    return ft_print("Norm ok", GREEN);
}

bool compile_test()
{
    std::ifstream ifs; 
    std::string name;

    ft_print("compile test", WHITE);
    system("cd ex00 && cc -Wall -Werror -Wextra *.c 2> ../result/compile.txt");
    sleep(1);
    ifs.open("result/compile.txt");
    std::getline(ifs, name);
    if (name.size())
        exit(ft_print("compile error", RED));
    ifs.close();
    return ft_print("compile ok", GREEN);
}

std::string create_input(std::string input, std::string file_name)
{
    std::ofstream ofs;
    ofs.open("input/" + file_name, std::ios::trunc);
    ofs << input;
    ofs.close();
    return (file_name);
}

void create_expect(std::string expect_str, std::string file_name)
{
    std::ofstream ofs;
    ofs.open("expect/" + file_name, std::ios::trunc);
    ofs << expect_str;
    ofs.close();
}

std::vector<std::string> create_test_case()
{
    // create input expect
    std::vector<std::string> test_name_group;
    std::string file_name;
    
    file_name = "empty_file";
    test_name_group.push_back(create_input("", file_name));
    create_expect("Error", file_name);
    
    file_name = "subject";
    test_name_group.push_back(create_input(" 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 ", file_name));
    create_expect("1 2 3 4$\n2 3 4 1$\n3 4 1 2$\n4 1 2 3", file_name);

    file_name = "1_argc_error";
    test_name_group.push_back(create_input(" 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 42", file_name));
    create_expect("Error", file_name);

    file_name = "2_argc_error";
    test_name_group.push_back(create_input("\" 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2\" \"42\"", file_name));
    create_expect("Error", file_name);

    file_name = "3_argc_error";
    test_name_group.push_back(create_input("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 ", file_name));
    create_expect("Error", file_name);

    file_name = "4_argc_error";
    test_name_group.push_back(create_input(" 1 1 1 1 ", file_name));
    create_expect("Error", file_name);

    file_name = "1_argv_error";
    test_name_group.push_back(create_input(" 2147483652 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 ", file_name));
    create_expect("Error", file_name);

    file_name = "2_argv_error";
    test_name_group.push_back(create_input("asdf", file_name));
    create_expect("Error", file_name);

    return test_name_group;
}

std::string exec_program(std::string test_name)
{
    // ./ex00/a.out input/test_name > output/test_name
    std::string cmd = "./ex00/a.out " ;
    cmd += "./input/" + test_name + "|cat -e > ";
    cmd += "./output/" + test_name;
    system(cmd.c_str());
    return test_name;
}

void diff(std::string& test_name)
{
    // diff expect/test_name output/test_name > result/test_name
    std::ifstream ifs;
    std::string line;
    std::string cmd = "diff expect/" + test_name;
    cmd += " output/" + test_name;
    cmd += " > result/" + test_name;
    system(cmd.c_str());

    sleep(1);
    ifs.open("result/" + test_name);
    if (getline(ifs, line))
        exit(ft_print(test_name + " error", RED));
    ifs.close();
    ft_print(test_name + " ok", GREEN);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        system("rm -rf result && mkdir result");
        system("rm -rf expect && mkdir expect");
        system("rm -rf output && mkdir output");
        system("rm -rf input && mkdir input");
        
        norm_test();
        compile_test();
        std::vector<std::string> test_group = create_test_case();
        for (int i = 0; i < test_group.size();i++)
        {
            ft_print(test_group[i] + " test", WHITE);
            exec_program(test_group[i]);
            diff(test_group[i]);
        }
        std::cout << "\033[32m\nall clear\n";
        std::cout << "\033[0myou shuld be code review\n";
    }
    else
    {
        // bonus
    }
}
