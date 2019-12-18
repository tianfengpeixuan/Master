//
//  generalQuery.cpp
//  Master
//
//  Created by 周华健 on 2019/12/18.
//  Copyright © 2019 周华健. All rights reserved.
//

#include "generalQuery.hpp"

generalQuery::generalQuery(){
    
    ID = 0;
    MaxSubID = 1;  //初始化ID值
}

generalQuery::generalQuery(size_t id, string str){
    
    ID = id;
    queryStr =str;
    MaxSubID = 1;
    
    //生成ip映射和客户端映射
    ifstream in("./host");
    
    if(! in){
        cout<<"Master节点打开配置文件失败"<<endl;
        exit(0);
    }
    
    size_t id1 ;
    size_t id2;
    string str1;
    in>>id1;
    while(in>>id2>>str1){
        
        if(id1 == id2) continue;
        else{
            ipRef[id2] = str1;
            clRef[id2] = new client(str1, 10000);
        }
    }
}

//查询分解
bool generalQuery:: decomposeQuery(){ //赋值子查询语句
    
    
    return true;
}


//创建partition
bool generalQuery:: createParition(){
    
    for(size_t i = 1; i < ipRef.size(); i++){   //根据节点个数创建分区
        
        unordered_map<size_t, string> umap;
        
        for(size_t j = 0; j < subStr.size(); j++){
            
            //调用接口得到该查询语句大概有多少条
            size_t temp = 0;
            //temp = judge();
            
            if(temp == 0){
                continue;
            }
            else{
                umap[MaxSubID] = subStr.at(j);
            }
        }
        partSub[i] = new partitionToSub(i, umap);
    }
    
    return true;
}

 //创建查询计划
bool generalQuery::createPlan(){
    
    
    return true;
}

//分解查询计划，直接将查询计划复制到分区的子查询计划中
bool generalQuery::decomposePaln(){
    
    return true;
}

//发送查询计划
bool generalQuery::sendPlan(){
    
    return true;
}
