//
//  manageToMaster.cpp
//  Master
//
//  Created by 周华健 on 2019/12/18.
//  Copyright © 2019 周华健. All rights reserved.
//

#include "manageToMaster.hpp"

size_t manageToMaster::queryId  = 1;

manageToMaster::manageToMaster(){
    
    ifstream in("./host");
    if(! in){
        cout<<""<<endl;
    }
    in>>ID;
    size_t id;
    string str;
    while(in>>id>>str){
        ipRef[id] = str;
    }
}

bool manageToMaster:: addQuery(string str){
    
    generalQuery* query = new generalQuery(manageToMaster::queryId, str);
    
    queryRef[manageToMaster::queryId] = query;
    
    return true;
}

bool manageToMaster:: removeQuery(size_t id1){
    
    queryRef.erase(id1);
    
    return true;
}

unordered_map<size_t, string> manageToMaster:: getIpRef(){
    
    unordered_map<size_t, string> un(ipRef);
    
    return un;
}

size_t manageToMaster::getID(){
    
    return ID;
}

//执行查询
vector<vector<size_t> > manageToMaster:: exeuteQuery(size_t id){
    
    generalQuery* temp = queryRef[id];
    
    temp->mystart();
    
    vector<vector<size_t> > temp1 = temp->getResult();
    
    return temp1;
}

