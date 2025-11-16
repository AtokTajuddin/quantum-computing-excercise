#include <iostream>
#include <qpp/qpp.hpp>

int main() {
    using namespace qpp;
    
    // Buat state |0>
    ket psi = 0_ket;
    std::cout << "Initial state |0>:\n" << disp(psi) << "\n\n";
    
    // Apply Hadamard gate -> supesrposisi
    ket psi_super = gt.H * psi;
    std::cout << "After Hadamard (superposition):\n" << disp(psi_super) << "\n\n";
    
    // Measurement
    auto result = measure(psi_super, gt.Id2);
    std::cout << "Measurement result: " << std::get<0>(result) << "\n";
    std::cout << "Probabilities: " << disp(std::get<1>(result)) << "\n";
    
    return 0;
}
