//
//  generalQuery.hpp
//  Master
//
//  Created by 周华健 on 2019/12/18.
//  Copyright © 2019 周华健. All rights reserved.
//  一个查询语句类

#ifndef generalQuery_hpp
#define generalQuery_hpp

#include "subQuery.hpp"
#include "partitionToQuery.hpp"
#include "client.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string.h>
#include <algorithm>
#include <fstream>
using namespace std;
//查询编号从1开始，0代表无效查询

class generalQuery{
private:
    size_t ID;    //查询ID
    unordered_map<size_t, partitionToSub* > partSub; //分区映射
    unordered_map<size_t, size_t> globalIDRef; //全局ID映射表
    vector<structPlan> plan;   //查询计划树
    string queryStr;      //查询语句
    vector<string> subStr; //子查询语句
    unordered_map<size_t, client* > clRef;  //客户端映射
    unordered_map<size_t,  string> ipRef; //子节点IP映射
    vector<vector<size_t> > result;
    size_t MaxSubID;
    
public:
    generalQuery();
    generalQuery(size_t id, string str);  //生成查询类
    bool decomposeQuery();  //查询语句的分解
    bool createParition();   //创建paritition
    bool createPlan();     //创建查询计划
    bool decomposePaln();   //分解查询计划
    bool sendPlan();        //发送查询计划
    bool createGlobalRef();   //创建全局映射
    bool sendGlobalRef();    //发送全局映射
    bool sendSubqueryToSlave();   //发送子查询语句和ID
    void mystart();
    
    vector<vector<size_t> > getResult();
    
};




#endif /* generalQuery_hpp */
