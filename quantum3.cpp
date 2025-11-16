#include <iostream>
#include <qpp/qpp.hpp>
using namespace std;
using namespace qpp;

int main(){
    //Ingat bahwa ket = vektor kolom kompleks dari state quantum
    ket psi = 0_ket;
    cout <<"State awalnya : " << disp(psi) << "\n";

    //Implementasi pauli X gate (Not Gate jika pada logic gate)
    psi = apply(psi,gt.X,{0});
    cout<< " Setelah X_gate, haslnya : "<<disp(psi) << "\n";
    cout<<"Measurementnya ialah : "<<get<0>(measure(psi,gt.Z))<<"\n"; 

    return 0;
}

/*
Basis komputasi (Jadi output dari kode tersebut merupakan operasi NOT dalam basis quantum yang ada)

|0⟩ = [1 0]
|1⟩ = [0 1]
*/