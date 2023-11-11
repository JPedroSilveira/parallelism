#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <iostream>

#define standard_input std::cin
#define standard_output std::cout

int _a = 0, _b = 0;

using Boolean = bool;
using Size = std::size_t;
using String = std::string;
using Time = std::time_t;

using InStream = std::istream;
using OutStream = std::ostream;

template <typename T, typename U>
using Pair = std::pair<T, U>;

template <typename T, typename C = std::less<T>>
using Set = std::set<T>;

template <typename T>
using SizeType = typename T ::size_type;

template <typename C>
inline auto _size(const C &x) -> SizeType<C>
{
    return x.size();
}

template <typename C>
inline auto
at_least_two_elements_in(const C &c) -> Boolean
{
    return _size(c) > SizeType<C>(1);
}

template <typename T>
inline auto
first_element(const Set<T> &x) -> T
{
    return *(x.begin());
}

template <typename T>
inline auto
second_element(const Set<T> &x) -> T
{
    return *(std::next(x.begin()));
}

template <typename T>
inline auto
remove(Set<T> &x, const T &e) -> Set<T> &
{
    x.erase(e);
    return x;
}

template <typename T>
inline auto
push(Set<T> &x, const T &e) -> Set<T> &
{
    x.insert(e);
    return x;
}

template <typename C>
inline auto
_empty(const C &x) -> Boolean
{
    return x.empty();
}

Boolean is_prefix(const String &a, const String &b)
{
    if (_size(a) > _size(b))
        return false;
    if (!(std::mismatch(a.begin(), a.end(), b.begin())
              .first == a.end()))
        return false;
    return true;
}

inline auto
suffix_from_position(const String &x, SizeType<String> i) -> String
{
    return x.substr(i);
}

inline auto
remove_prefix(const String &x, SizeType<String> n) -> String
{
    if (_size(x) > n)
        return suffix_from_position(x, n);
    return x;
}

auto all_suffixes(const String &x) -> Set<String>
{
    Set<String> ss;
    SizeType<String> n = _size(x);
    for (int i = n - 1; i > 0; i--)
    {
        ss.insert(x.substr(i));
    }
    return ss;
}

auto commom_suffix_and_prefix(const String &a, const String &b) -> String
{
    if (_empty(a))
        return "";
    if (_empty(b))
        return "";
    String x = "";
    for (const String &s : all_suffixes(a))
    {
        _b = _b + 1;
        if (is_prefix(s, b) && _size(s) > _size(x))
        {
            x = s;
        }
    }
    return x;
}

inline auto
overlap_value(const String &s, const String &t) -> SizeType<String>
{
    return _size(commom_suffix_and_prefix(s, t));
}

auto overlap(const String &s, const String &t) -> String
{
    String c = commom_suffix_and_prefix(s, t);
    return s + remove_prefix(t, _size(c));
}

inline auto
pop_two_elements_and_push_overlap(Set<String> &ss, const Pair<String, String> &p) -> Set<String> &
{
    ss = remove(ss, p.first);
    ss = remove(ss, p.second);
    ss = push(ss, overlap(p.first, p.second));
    return ss;
}

auto all_distinct_pairs(const Set<String> &ss) -> Set<Pair<String, String>>
{
    Set<Pair<String, String>> x;
    for (const String &s1 : ss)
    {
        for (const String &s2 : ss)
        {
            _a = _a + 1;
            if (s1 != s2)
                x.insert(make_pair(s1, s2));
        }
    }
    return x;
}

auto highest_overlap_value(const Set<Pair<String, String>> &sp) -> Pair<String, String>
{
    Pair<String, String> x = first_element(sp);
    for (const Pair<String, String> &p : sp)
    {
        if (overlap_value(p.first, p.second) > overlap_value(x.first, x.second))
        {
            x = p;
        }
    }
    return x;
}

auto pair_of_strings_with_highest_overlap_value(const Set<String> &ss) -> Pair<String, String>
{
    return highest_overlap_value(all_distinct_pairs(ss));
}

auto shortest_superstring(Set<String> t) -> String
{
    if (_empty(t))
    {
        return "";
    }
    while (at_least_two_elements_in(t))
    {
        t = pop_two_elements_and_push_overlap(t, pair_of_strings_with_highest_overlap_value(t));
    }
    return first_element(t);
}

inline auto
write_string_and_break_line(OutStream &out, String s) -> void
{
    out << s << std::endl;
}

inline auto read_size(InStream &in) -> Size
{
    Size n;
    in >> n;
    return n;
}

inline auto read_string(InStream &in) -> String
{
    String s;
    in >> s;
    return s;
}

auto read_strings_from_standard_input() -> Set<String>
{
    Set<String> x;
    SizeType<Set<String>> n = SizeType<Set<String>>(read_size(standard_input));
    while (n--)
    {
        x.insert(read_string(standard_input));
    }
    return x;
}

inline auto
write_string_to_standard_ouput(const String &s) -> void
{
    write_string_and_break_line(standard_output, s);
}

auto main(int argc, char const *argv[]) -> int
{
    Time start, end;

    Set<String> ss = read_strings_from_standard_input();

    time(&start);

    String result = shortest_superstring(ss);

    time(&end);

    write_string_to_standard_ouput(result);

    double time_taken = double(end - start);

    std::cout << "Time taken by program is : " << std::fixed << time_taken << " sec " << std::endl;

    std::cout << _a << std::endl
              << _b;

    return 0;
}