#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Node.hpp"


using namespace std;
namespace ariel {

    class OrgChart{
        
        private:
           
             Node* _root = nullptr;    
        public:
        //Node* _root = nullptr; 
        class Iterator{
            
            private:
               
                vector<Node*> _treeNode;
                // unsigned long _cuurNode;
                 Node* _cuurNode;
            public:
           
               // Node* _cuurNode;
            Iterator( Node *p, int action) {
                    if (p == nullptr) {
                        this->_cuurNode = nullptr;
                        
                    } 
                    else {
                        if(action==0){
                            bylevel(p);
                        }
                        else if(action==1){
                            byreverse(p);
                        }
                        else if(action==2){
                            bypreorder(p);
                        }
                          
                        this->_cuurNode = (_treeNode.at(0));
                        _treeNode.erase(_treeNode.begin());
                    }
                }

                 bool operator== (const Iterator& it) {
                    return this->_cuurNode == it._cuurNode;
                }
                 bool operator!= (const Iterator& it) {
                    return this->_cuurNode != it._cuurNode;
                }

                Iterator operator++(int) {
                    Iterator tmp = *this;
                    return tmp;
                }

                string operator*() {
                    return (*this->_cuurNode).get_name();
                }

                // Iterator operator++(int) {
                //     Iterator t = *this; 
                //     this->_cuurNode++;
                //     return t;
                // }

                // Iterator& operator++() {
                    
                //     this->_cuurNode++;
                //      return *this;                
                // }
                

                Iterator& operator++() {
                    if (!_treeNode.empty()) {
                        this->_cuurNode = _treeNode.at(0);
                        _treeNode.erase(_treeNode.begin());}

                    else {
                        this->_cuurNode = nullptr;}
                    return *this;                }

                string* operator-> () {
                    return &_cuurNode->_name;
                }
                void bylevel(Node* root);
                void byreverse(Node* root);
                void bypreorder(Node* root);
            };
            OrgChart();
            ~OrgChart();   
            friend ostream& operator<<(ostream& out, const OrgChart &original);
            OrgChart& add_root(const string &name);
            OrgChart& add_sub( const string& exist,const  string& newNode);
             OrgChart &operator=(OrgChart const &other) = default;
            OrgChart &operator=(OrgChart &&other) = default;
            OrgChart(OrgChart&) = default;
            OrgChart(OrgChart&&) = default;
            void freeTree(Node *root);
            Iterator begin_reverse_order()const;
            Iterator reverse_order()const;
            Iterator begin_level_order()const;
            Iterator end_level_order()const;
            Iterator begin_preorder()const;
            Iterator end_preorder()const;
            Iterator begin()const;
            Iterator end()const;
    };
   
}