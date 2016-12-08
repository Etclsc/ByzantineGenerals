#include "general.h"

void general::requestID(std::vector<general> generals) {
    for(int i = 0; i < generals.size(); i++) {
        IDs.push_back(generals[i].replyID());
    }
}
int general::replyID() {
    // 正常時の処理
    if(state == "normal") {
        return myID;
    }
    // 異常時 : 100~999の乱数を返す
    else {
        std::random_device rd; // 乱数生成器
        std::mt19937 mt(rd()); // メルセンヌツイスタ(32bit)
        std::uniform_int_distribution<int> rndID(100,999); // [100,999]の一様乱数

        return rndID(mt);
    }
}

void general::requestID_vectors(std::vector<general> generals) {
    for(int i = 0; i < generals.size(); i++) {
        ID_vectors.push_back(generals[i].replyID_vectors());
    }
}
std::vector<int> general::replyID_vectors() {
    // 正常時の処理
    if(state == "normal") {
        return IDs;
    }
        // 異常時 : 100~200の乱数を返す
    else {
        std::random_device rd; // 乱数生成器
        std::mt19937 mt(rd()); // メルセンヌツイスタ(32bit)
        std::uniform_int_distribution<int> rndID(100,200); // [100,200]の一様乱数

        std::vector<int> rndID_vector;
        for(int i = 0; i < nGenerals; i++) {
            rndID_vector.push_back(rndID(mt));
        }
        return rndID_vector;
    }
}


std::vector< std::vector<int> > general::getID_vectors() {
    return ID_vectors;
}

void general::compareID_vectors() {
    for(int index = 0; index < nGenerals; index++){
        // 多数決用配列
        std::vector<int> vec;

        for(int p = 0; p < nGenerals; p++) {
            if (p != myID) {
                vec.push_back(ID_vectors[p].at(index));
            }
        }
        std::vector<int> uniVec(vec);
        std::sort(uniVec.begin(), uniVec.end());
        uniVec.erase(std::unique(uniVec.begin(), uniVec.end()), uniVec.end());

        int *count = new int[uniVec.size()];
        for(int i = 0; i < uniVec.size(); i++) {
            count[i] = std::count(vec.begin(), vec.end(), uniVec[i]);
        }

        int maxCounts = 0, maxIndex = 0;
        for(int i = 0; i < uniVec.size(); i++) {
            if(count[i] > maxCounts) {
                maxCounts = count[i];
                maxIndex = i;
            }
        }
        if(maxCounts > vec.size()/2.0)
            rightIDs.push_back(uniVec.at(maxIndex));
        else
            rightIDs.push_back(-1);

        delete[] count;
    }
}

std::string general::getState() {
    return state;
}

int general::getID() {
    return myID;
}

std::vector<int> general::getRightIDs() {
    return rightIDs;
}
