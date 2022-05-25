
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

    OrgChart::OrgChart() {
        this->_root = nullptr;
    }
     void  OrgChart::freeTree(Node *root) {
        if (this->_root == nullptr) { 
            return;}

        if (!root->get_Vertices().empty()) {
            unsigned int x = root->get_Vertices().size();
            for (unsigned int child = 0; child < x; child++) {
                freeTree(root->get_Vertices()[child]);
            }
        }
        delete root;
    }

       OrgChart::~OrgChart() {
            (*this).freeTree(this->_root);
       }
   


    OrgChart& OrgChart::add_root(const string &name){
    if(name.empty()){
        throw invalid_argument("illegal string");
    }
    if (this->_root == nullptr) {
            Node *newNode = new Node(name); 
            _root = newNode;}
    else
    {
         _root->_name = name;}
    return *this;
}

bool exsitInTree(Node* n,const string &exist,const string &newNode){
    if((*n).get_name()==exist){
            Node* node = new Node(newNode);
         (*n).add_node(node);
            return true;
    }
    for (size_t i = 0; i < n->get_Vertices().size(); i++){

            if (exsitInTree((*n).get_Vertices().at(i), exist, newNode))
            {
                return true;
                }
        }
    return false;
}

OrgChart& OrgChart::add_sub(const string& exist,const string& newNode){

    if(this->_root == nullptr){
        throw invalid_argument("no workers");
    }
    if(exist.empty() || newNode.empty()){
        throw invalid_argument("illegal string");
    }
        if(!exsitInTree(this->_root ,exist,newNode)){
             throw invalid_argument("not found this man");
        }
           
            return *this;
}
 
               

void OrgChart:: Iterator::bylevel(Node* root){
       
    vector<Node*>temp;
    unsigned long j=0;
    temp.push_back(root);
   
    while(j<temp.size()){
        Node *temp2 = temp[j];
        _treeNode.push_back(temp2);
        unsigned long i=0;
            while(i<temp2->get_Vertices().size()){
                temp.push_back(temp2->get_Vertices().at(i));
                i++;

    }
    j++;
    }
}
OrgChart::Iterator OrgChart::begin_level_order()const {
    
        if (this->_root == nullptr) {
            throw invalid_argument("no workers");}

        return Iterator{_root, 0};}

OrgChart::Iterator OrgChart::end_level_order() const{
        if (this->_root == nullptr) {
            throw invalid_argument("no workers");
        }
        return Iterator{nullptr , 0};    
    }
void OrgChart:: Iterator::bypreorder(Node* root){

   this->_treeNode.push_back(root);
        unsigned int x = (*root).get_Vertices().size();
        for(unsigned int i=0; i<x; i++) {
            Node* node = (*root).get_Vertices().at(i);
            bypreorder(node);
        }
}

OrgChart::Iterator OrgChart::begin_preorder()const {
        if (this->_root == nullptr) {
            throw invalid_argument("no workers");
        }
        return Iterator{ _root , 2}; }
    
    OrgChart::Iterator OrgChart::end_preorder() const{
        if (this->_root == nullptr) {
            throw invalid_argument("no workers");
        }
        return Iterator{ nullptr , 2}; 
    }
void OrgChart:: Iterator::byreverse(Node* root){
    vector<Node*> temp;
        temp.push_back(root);

        int size = temp.size();  
        for(unsigned int i= 0;i<size;i++){

            Node* curr =  temp[i];

            for(int  j = (int)(*curr).get_Vertices().size()-1; j >= 0; j--) {
               
                temp.push_back((*curr).get_Vertices().at((unsigned)j));}
                size = temp.size();   
        } 
        for(int i = (int)temp.size()-1; i >= 0; i--) {
            _treeNode.push_back(temp.at((unsigned)i));
        }}

    OrgChart::Iterator OrgChart::begin_reverse_order() const{
        if (this->_root == nullptr) {
            throw invalid_argument("no workers");
        }
        return Iterator{ this->_root , 1};  
    }
    
    OrgChart::Iterator OrgChart::reverse_order() const{
        if (this->_root == nullptr) {
            throw invalid_argument("no workers");
        }
        return Iterator{ nullptr , 1};  
    }
ostream& ariel::operator<<(ostream& out, const OrgChart &original) {
        return out;
    }
     OrgChart::Iterator OrgChart::end() const{
      if (this->_root == nullptr) {
            throw invalid_argument("no workers");
        }
        return Iterator{nullptr , 0};  
    }
  OrgChart::Iterator OrgChart::begin() const{
        if (this->_root == nullptr) {
            throw invalid_argument("no workers");}

        return Iterator{_root, 0};

    }


    