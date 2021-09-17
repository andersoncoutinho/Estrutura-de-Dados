#include <iostream>
#include <vector>

int main(void) {
    
    std::vector<int> vetor(10);
    vetor.push_back(30);
    std::cout << vetor.size() << std::endl;

    return 0;
}