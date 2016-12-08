#include <iostream>
#include <iomanip>
#include "general.h"

using namespace std;

// 将軍の状態を示す (この変数を変更する)
std::string states[] = {"normal", "normal", "broken", "normal", "normal", "broken"};

int main(int argc, char* argv[]) {

    int nGenerals = sizeof(states)/sizeof(states[0]);
    vector<general> generals;

    // 将軍を生成
    for(int i = 0; i < nGenerals; i++) {
        generals.push_back( *new general(i, states[i], nGenerals));
    }

    // 将軍が他将軍へIDを通知 (他将軍から取得)
    for(int i = 0; i < nGenerals; i++) {
        generals[i].requestID(generals);
    }

    // 将軍が他将軍へIDベクトルを通知 (他将軍から取得)
    for(int i = 0; i < nGenerals; i++) {
        generals[i].requestID_vectors(generals);
    }

    // 将軍がIDベクトルを比較
    for(int i = 0; i < nGenerals; i++) {
        generals[i].compareID_vectors();
    }

    /* ---  以下出力 --- */
    // 他将軍から受け取ったベクトルを表示
    printf(" --- 受け取った情報 ---\n");
    for(int id = 0; id < nGenerals; id++) {
        cout << "general[" << id << "]"  << endl;

        for(int index = 0; index < nGenerals; index++){
            vector< vector<int> > rsVec = generals[id].getID_vectors();

            if(index != generals[id].getID()) {
                cout << " >> from gen[" << index << "]: {";
                for (int l = 0; l < nGenerals; l++) {
                    cout << setw(4) << rsVec[index].at(l);
                }
                cout << "}" << endl;
            }
        }
        cout << endl;
    }

    // 最終的な情報を表示
    printf(" --- 最終的な情報(正常な将軍のみ表示, -1は不明を表す)  ---\n");
    for(int id = 0; id < nGenerals; id++) {
        if(generals[id].getState() == "normal") {
            vector<int> currentID_vector = generals[id].getRightIDs();

            cout << " >> general[" << id << "]: {";
            for(int index = 0; index < nGenerals; index++) {
                cout << setw(4) << currentID_vector.at(index);
            }
            cout <<  "}" << endl;
        }
    }

    return 0;
}
