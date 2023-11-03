#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

bool pred(int i, int j) {
    // forskjellen er ikke mer enn 2
    return (abs(i-j) <= 2);
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;

    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;


    // a)
    // Bruker anonym fuksjon som argument
    auto it = find_if(v1.begin(), v1.end(), [](int a) -> bool { return a > 15; });
    cout << "Første element i v1 større enn 15: " << *it << endl;

    // b)
    if ( equal(v1.begin(), v1.begin()+5, v2.begin(), pred)) {
        cout << "[v1.begin(), v1.begin() + 5> og v2 er like" << endl;
    } else {
        cout << "[v1.begin(), v1.begin() + 5> og v2 er ikke like" << endl;
    }

    if ( equal(v1.begin(), v1.begin()+4, v2.begin(), pred)) {
        cout << "[v1.begin(), v1.begin() + 4> og v2 er like" << endl;
    } else {
        cout << "[v1.begin(), v1.begin() + 4> og v2 er ikke like" << endl;
    }


    // c)
    // bruker anonym funksjon som argument her og.
    replace_copy_if(v1.begin(), v1.end(), v1.begin(), [](int a) -> bool {return a % 2; }, 100);
    cout << "v1 med 100 i stedet for oddetall: " << v1;

}