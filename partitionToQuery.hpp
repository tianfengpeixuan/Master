//
//  partitionToQuery.hpp
//  Master
//
//  Created by 周华健 on 2019/12/18.
//  Copyright © 2019 周华健. All rights reserved.
//   查询类中的分区，对应每个节点slave

#ifndef partitionToQuery_hpp
#define partitionToQuery_hpp

#include "subQuery.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
//分区编号从1开始，0代表无效分区

//查询计划结构体
struct structPlan{
    size_t ID;  //子查询类ID
    int type;   //0表示查询语句，1表示union，2表示join，3表示分裂
};

class partitionToSub{
private:
    size_t ID;
    unordered_map<size_t, subQuery*> subRef;
    vector<string> subQueryVec;
    vector<struct structPlan> subPlan;
    
public:
    partitionToSub(size_t id, unordered_map<size_t, string> unMap);
    
    bool alterSubPlan(vector<structPlan>& temp);  //赋值查询计划
    
    bool addSubref(size_t id, subQuery * sub);  //增加子查询
    
    vector<structPlan> getSubPlan();
    
    subQuery* getSubQuery(size_t id);
    
    virtual ~partitionToSub();
};


#endif /* partitionToQuery_hpp */
