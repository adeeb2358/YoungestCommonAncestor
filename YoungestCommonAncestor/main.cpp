//
//  main.cpp
//  YoungestCommonAncestor
//
//  Created by adeeb mohammed on 01/05/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
// time complexity of the problem is o(d) space complexity is o(1)

#include <iostream>
#include <vector>

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(std::vector<AncestralTree *> descendants);
};

int getHeight(AncestralTree *topAncestor, AncestralTree *descendant){
    int height = 0;
    while (descendant != topAncestor) {
        height++;
        descendant = descendant->ancestor;
    }
    return height;
}

AncestralTree* makeSameLevel(int difference, AncestralTree* node){
    while (difference > 0) {
        node = node->ancestor;
        difference--;
    }
    return node;
}

AncestralTree* findCommonAncestor(AncestralTree* descendantOne,
                                  AncestralTree* descendantTwo){
    
    while (descendantOne != descendantTwo) {
        descendantOne = descendantOne->ancestor;
        descendantTwo = descendantTwo->ancestor;
    }
    return descendantOne;
}


AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
    
    int heightOne = getHeight(topAncestor, descendantOne);
    int heightTwo  = getHeight(topAncestor , descendantTwo);
    if (heightOne < heightTwo) {
        return findCommonAncestor(descendantOne, makeSameLevel(heightTwo-heightOne,descendantTwo));
    }else{
        return findCommonAncestor(descendantTwo, makeSameLevel(heightOne-heightTwo,descendantOne));
    }
}

int main(int argc, const char * argv[]) {
    std::cout << "Youngest Common Ancestor" <<  std::endl;
    return 0;
}
