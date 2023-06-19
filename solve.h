#include <vector>
#include <string>
#include <unordered_map>

namespace solve {

constexpr unsigned length = 3;
const std::string input_file  = "../in_words.txt";
const std::string output_file = "../out_task.txt";

struct weight_word final {
    std::string word;
    unsigned weight;

    weight_word(const std::string &word_, const unsigned weight_ = 0) : word{word_}, weight{weight_} {}
};

bool operator==(const weight_word &lhs, const weight_word &rhs);

class Solve final {
    std::vector<weight_word> words;
    std::unordered_map<std::string, unsigned> triples;

    void get_vector();
    void estimate_triples();
    void estimate_words();
    void sort_words();
    void print_result();

    public:

    void run() {
        get_vector();
        estimate_triples();
        estimate_words();
        sort_words();
        print_result();
    }
};

} // solve