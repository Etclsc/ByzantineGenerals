#ifndef BYZANTINEGENERALS_GENERAL_H
#define BYZANTINEGENERALS_GENERAL_H

#include <iostream>
#include <vector>
#include <random>

class general {
private:
    int myID;   // 自分のID
    int nGenerals;  // 将軍数
    std::string state;  // 自分の状態(正常or異常)
    std::vector<int> IDs;   // IDベクトル
    std::vector< std::vector<int> > ID_vectors; // 他将軍が生成したIDベクトル
    std::vector<int> rightIDs;  // 最終的なIDベクトル

public:
    general(int id, std::string st, int n) {
        myID = id;
        state = st;
        nGenerals = n;
    }

    void requestID(std::vector<general>);   // 多将軍にIDを聞く
    void requestID_vectors(std::vector<general>);   // 他将軍にIDベクトルを聞く
    int replyID();  // IDを答えてあげる
    std::vector<int> replyID_vectors(); // IDベクトルを答えてあげる
    void compareID_vectors();   // IDベクトルを比較する

    std::string getState(); // 自分が正常か異常か返す
    int getID();    // 自分のIDを返す
    std::vector< std::vector<int> > getID_vectors();  // 自分が持っているIDベクトルを返す
    std::vector<int> getRightIDs(); // 最終判断のベクトルを返す
};


#endif //BYZANTINEGENERALS_GENERAL_H
