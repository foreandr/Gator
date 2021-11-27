namespace std {
    template <typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
        tab(basic_ostream<_CharT, _Traits>& __os) {
        return __os.put(__os.widen('\t'));
    }
}
/*path currentPath = "."; // Path object knows the right kind of string
path canonicalpath = canonical(currentPath).string(); // path of current directory
path parentPath = current_path().parent_path(); // Give me path to parent folder
if (!(exists(parentPath)))
        cout << "NOT OK  - file doesnt exists" << endl;
*/