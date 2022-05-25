#pragma once
#include <iostream>
#include <string>
#include <vector>        

using namespace std;

namespace ariel {

class Node {

    
    public:
        string _name;
        std::vector<Node*> _Vertices;
        Node(const string &name) {
            this->_name = name;
        }

        string get_name() const{ return this->_name;}
        std::vector<Node*> get_Vertices() const{return this->_Vertices;}
        Node& add_node(Node* node) {
            this->_Vertices.push_back(node);
            return *this;
        }
       
};
}