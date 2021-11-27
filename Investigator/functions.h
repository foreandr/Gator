namespace std {
    template <typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
        tab(basic_ostream<_CharT, _Traits>& __os) {
        return __os.put(__os.widen('\t'));
    }
}
void printOptions() {
    std::cout << "Select an option:" << std::endl << std::tab <<
        "1. Get number of lines in program" << std::endl << std::tab <<
        "2. How many of a particular letter Ascii Char is in your code" << std::endl << std::tab << 
        "0. Press 0 to exit." << std::endl << std::tab
        ;
}
int help() {
    printOptions();
    int value;
    std::cin >> value;
    return value;
}
void process() {
    help();
}
void printIntroText() {
    std::cout << "Thanks for using Gator\nPlease enter the Path you would like to investigate:\n\n";
}