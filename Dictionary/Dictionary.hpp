#include <iostream>
#include <fstream>
#include "../AVLTreeLib/AVLTree.hpp"

AVLTree<string, int> counter(const string& filename) {
    AVLTree<string, int> tree;

    ifstream file_r;
    file_r.open(filename);
    if(file_r.is_open()){
        string word;
        int* found;
        while(file_r >> word){
            found = tree.find(word);
            if(found != nullptr) {
                *found += 1;
            }else {
                tree.insert(word, 1);
            }
        }
        file_r.close();
    }else{
        throw runtime_error("File couldn't be resolved");
    }

    return tree;
};


void listing(const AVLTree<string, int>& tree, ostream& stream = cout) {
    list<pair<string, int>>& listed = tree.listify();
    AVLTree<int, list<string>> t;

    list<string>* found;
    list<pair<string, int>>::iterator it;
    for(it = listed.begin(); it != listed.end(); ++it){
        found = t.find(it->second);
        if(found != nullptr) {
            found->push_back(it->first);
        }else {
            list<string> words;
            words.push_back(it->first);
            t.insert(it->second, words);
        }
    }
    
    list<pair<int, list<string>>>& dictionary = t.listify();
    list<pair<int, list<string>>>::iterator i;
    for(i = dictionary.begin(); i != dictionary.end(); ++i) {
        list<string>::iterator itw;
        for(itw = (i->second).begin(); itw != (i->second).end(); ++itw) {
            stream << i->first << " " << *itw << endl;
        }
    }

};

void wrapper(const string& lexicographical_out, const string& occurance_out) {
    AVLTree<string, int> tree = counter("The Voyage of the Beagle by Charles Darwin.txt");

    list<pair<string, int>>& listed = tree.listify();

    ofstream file_wl;

    file_wl.open(lexicographical_out);
    if(file_wl.is_open()){
        list<pair<string, int>>::iterator it;
        for(it = listed.begin(); it != listed.end(); ++it)
            file_wl << it->first << " " << it->second << endl;

        file_wl.close();
    }else{
        throw runtime_error("File couldn't be resolved");
    }

    ofstream file_wo;
    file_wo.open(occurance_out);
    if(file_wo.is_open()) {
        listing(tree, file_wo);
        file_wo.close();
    }else{
        throw runtime_error("File couldn't be resolved");
    }
}