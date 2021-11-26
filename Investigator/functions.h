namespace std {
    template <typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
        tab(basic_ostream<_CharT, _Traits>& __os) {
        return __os.put(__os.widen('\t'));
    }
}
