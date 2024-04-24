#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > ch;
    vector<int> row1_ch;
    row1_ch.push_back(1);
    row1_ch.push_back(2);
    ch.push_back(row1_ch);

    vector<int> row2_ch;
    row2_ch.push_back(1);
    row2_ch.push_back(8);
    ch.push_back(row2_ch);

    vector<int> row3_ch;
    row3_ch.push_back(4);
    row3_ch.push_back(9);
    ch.push_back(row3_ch);

    vector<vector<int> > dg;
    vector<int> row1_dg;
    row1_dg.push_back(1);
    row1_dg.push_back(3);
    dg.push_back(row1_dg);

    vector<int> row2_dg;
    row2_dg.push_back(1);
    row2_dg.push_back(5);
    dg.push_back(row2_dg);

    vector<int> row3_dg;
    row3_dg.push_back(4);
    row3_dg.push_back(9);
    dg.push_back(row3_dg);

    // Insert the second row of dg into ch at the beginning
    ch.insert(ch.begin(), dg[1]);

    // Printing the result
    for (int i = 0; i < ch.size(); ++i) {
        cout << "{" << ch[i][0] << ", " << ch[i][1] << "} ";
    }
    cout << endl;

    return 0;
}

