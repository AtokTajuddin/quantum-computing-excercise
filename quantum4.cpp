//Belajar multi qubit pada quantum computing
#include <iostream>
#include <qpp/qpp.hpp>

int main() {
    using namespace qpp;
    using namespace std;
    // |1⟩ & |0⟩ merupakan basis standar qubit 
    // 1. State |00⟩ (4x1 vector)
    ket psi(4);
    psi << 1, 0, 0, 0; // |00⟩ = [1, 0, 0, 0]^T
    cout << "State awal |00⟩:\n" << disp(psi) << "\n";
    
    // 2. H pada qubit 0 = H x I (4x4 matrix)
    auto HI = kron(gt.H, gt.Id2);
    psi = HI * psi;
    cout << "Setelah H(0):\n" << disp(psi) << "\n";
    
    // 3. X pada qubit 1 = I x X (4x4 matrix)
    auto IX = kron(gt.Id2, gt.X);
    psi = IX * psi;
    cout << "Setelah X(1):\n" << disp(psi) << "\n";
    
    // 4. Probabilitas manual (|psi|^2)
    cout << "\nProbabilitas:\n";
    cout << "  |00⟩: " << norm(psi(0)) << "\n";
    cout << "  |01⟩: " << norm(psi(1)) << "\n";
    cout << "  |10⟩: " << norm(psi(2)) << "\n";
    cout << "  |11⟩: " << norm(psi(3)) << "\n";
    
    // 5. Measurement qubit 0
    auto m0 = measure(psi, gt.Z, {0});
    cout << "\nMeasurement qubit 0: " << get<0>(m0) << "\n";
    
    // 6. Measurement full
    auto mAll = measure(psi, gt.Z, {0, 1});
    cout << "Measurement full: |" << get<0>(mAll) << "⟩\n";
    
    return 0;
}