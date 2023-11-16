#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <omp.h>

#define standard_input std::cin
#define standard_output std::cout

#define NUM_OF_THREADS 400

using Boolean = bool;
using Size = std::size_t;
using String = std::string;

using InStream = std::istream;
using OutStream = std::ostream;

template <typename T, typename U>
using Pair = std::pair<T, U>;

template <typename T, typename C = std::less<T>>
using Set = std::set<T>;

template <typename T, typename C = std::less<T>>
using Vector = std::vector<T>;

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

auto commom_suffix_and_prefix(const String &a, const String &b) -> String
{
    if (_empty(a))
        return "";
    if (_empty(b))
        return "";
        
    SizeType<String> n = _size(a);
    SizeType<String> i = 0;

    String result = "";
    bool found = false;

    while(!found && i < n) {
        String suffix = a.substr(i);
        if (is_prefix(suffix, b))
        {
            result = suffix;
            found = true;
        }
        i++;
    }

    return result;
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

void reduceOverlap(Pair<Pair<String, String>, int> &inout, Pair<Pair<String, String>, int> &in) {
  if (in.second > inout.second) {
    inout.first = in.first;
    inout.second = in.second;
  }
}

#pragma omp declare reduction(reduceOverlap : Pair<Pair<String, String>, int> : reduceOverlap(omp_out, omp_in)) \
    initializer (omp_priv=omp_orig)

auto pair_of_strings_with_highest_overlap_value(const Set<String> &ss) -> Pair<String, String>
{
    // Converte o conjunto em lista para facilitar sua manipulação
    std::vector<String> ssVector(ss.size());
    std::copy(ss.begin(), ss.end(), ssVector.begin());

    String first = ssVector[0];
    String second = ssVector[1];

    // Define as primeiras duas palavras da lista como melhor
    // sobreposição inicial
    Pair<Pair<String, String>, int> biggestOverlap = std::make_pair(
        std::make_pair(first, second), 
        overlap_value(first, second)
    );

    long unsigned int i, j;
    int newOverlapValue;

    // Paraleliza o laço externo, sendo que cada iteração irá calcular
    // a sobreposição para todos os pares que comecem com a palavra i
    #pragma omp parallel for \
        reduction(reduceOverlap : biggestOverlap) \
        private(i, j, newOverlapValue) shared(ssVector)
    for (i = 0; i < ssVector.size(); i++)
    {
        for (j = 0; j < ssVector.size(); j++)
        {
            if (i != j) {
                newOverlapValue = overlap_value(ssVector[i], ssVector[j]);
                if (newOverlapValue > biggestOverlap.second)
                {
                    biggestOverlap = std::make_pair(
                        std::make_pair(ssVector[i], ssVector[j]), 
                        newOverlapValue
                    );
                }
            }
        }
    }

    return biggestOverlap.first;
}

auto shortest_superstring(Set<String> t) -> String
{
    if (_empty(t))
    {
        return "";
    }
    
    while (at_least_two_elements_in(t))
    {
        t = pop_two_elements_and_push_overlap(
            t, 
            pair_of_strings_with_highest_overlap_value(t)
        );
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
    double start_time, end_time;
    
    Set<String> ss = read_strings_from_standard_input();

    omp_set_num_threads(NUM_OF_THREADS);

    start_time = omp_get_wtime();
    String result = shortest_superstring(ss);
    end_time = omp_get_wtime();

    printf("Tempo decorrido: %f segundos\n", end_time - start_time);

    write_string_to_standard_ouput(result);

    return 0;
}