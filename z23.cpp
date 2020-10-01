#include <vector>
#include <sstream>
#include <limits.h>
#include <fstream>

using namespace std;

int index_of_1st_greater_elem(vector<int> arr, int elem);
vector<int> read_int_arr_from_line_of_file(ifstream& input);
void print(vector<int> a, ofstream & out_stream) {
    for (int num : a)
        out_stream << num << ' ';
    out_stream << '\n';
}


int main() {
    ifstream input;
    input.open("in.txt");
    vector<int> arr_of_nums = read_int_arr_from_line_of_file(input);
    input.close();

    int n = arr_of_nums.size();

    //max number in sequence of n elements
    vector<int> max_num_in_seq(n, INT_MAX);

    //index of previous element of growing sequence, placed in arr_of_nums. Used when go back
    vector<int> prev_num_index(n, -1);

    //index of number from max_num_in_seq in arr_of_nums. Used to create prev_num_index
    vector<int> max_num_index(n, -1);

    int max_len_index = -1;
    int index_of_last_seq_elem = -1;

    int replace_index;
    //forw prop
    int number;
    for (int current_index = 0; current_index < n; current_index += 1) {
        number = arr_of_nums[current_index];
        replace_index = index_of_1st_greater_elem(max_num_in_seq, number);

        max_num_in_seq[replace_index] = number;
        max_num_index[replace_index] = current_index;
        prev_num_index[current_index] = ((replace_index > 0) ? max_num_index[replace_index - 1] : -1);

        //finding max length
        if (max_len_index < replace_index) {
            max_len_index = replace_index;
            index_of_last_seq_elem = current_index;
        }
    }


    //back prop
    vector<int> output(max_len_index + 1, 100);

    int output_index = max_len_index;
    int current_index = index_of_last_seq_elem;
    while (current_index != -1) {
        output[output_index] = arr_of_nums[current_index];
        current_index = prev_num_index[current_index];
        output_index -= 1;
    }


    ofstream out_stream;
    out_stream.open("out.txt");
    print(output, out_stream);
    out_stream.close();
    return 0;
}


vector<int> read_int_arr_from_line_of_file(ifstream & input) {
    std::string line;
    std::getline(input, line);
    std::stringstream iss(line);

    vector<int> arr;
    int temp_input;

    while (iss >> temp_input)
        arr.push_back(temp_input);
    return arr;
}

int index_of_1st_greater_elem(vector<int> arr, int elem) {
    int left = 0;
    int right = arr.size();
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] <= elem)
            left = mid + 1;
        else if (arr[mid] > elem)
            right = mid;
    }
    return left;
}