#include <iostream>
#include <qpp/qpp.hpp>

int main() {
    using namespace qpp;
    using namespace std;
    
    // CARA BENAR: 0_ket = |0⟩, 1_ket = |1⟩
    ket psi = 0_ket; // Inisialisasi 1 qubit di state |0⟩
    
    cout << "State awal |0⟩:\n" << disp(psi) << "\n";
    cout << "Dimensi: " << psi.size() << " (harus 2)\n\n";
    
    // Hadamard gate
    psi = apply(psi, gt.H, {0}); // {0} = qubit index 0
    
    cout << "Setelah H|0⟩ (superposisi):\n" << disp(psi) << "\n";
    cout << "Norm: " << norm(psi) << "\n\n";
    
    // Measurement repeated
    size_t shots = 1000;
    size_t count_0 = 0;
    
    for (size_t i = 0; i < shots; i++) {
        ket copy = psi;
        auto measured = measure(copy, gt.Z);
        idx result = get<0>(measured);
        if (result == 0) count_0++;
    }
    
    cout << "Hasil " << shots << " shots:\n";
    cout << "Probabilitas |0⟩: " << (count_0 * 100.0 / shots) << "%\n";
    cout << "Probabilitas |1⟩: " << 100 - (count_0 * 100.0 / shots) << "%\n";
    
    return 0;
}

/*
Cara compile
g++ quantum2.cpp -o quantum2 \
  -I/usr/include/eigen3 \
  -I/usr/local/include \
  -std=c++17 -O3 -pthread && ./quantum2
*/