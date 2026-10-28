#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int menu = 0;
    vector<string> servicios;
    vector<string> passwords;

    while (menu != 4) {
        cout << "⸻ KeyHasher (Simulacion) ⸻" << endl;
        cout << "[1] Registrar una nueva clave." << endl;
        cout << "[2] Mostrar la Bovedad (con las contraseñas enmascaradas)." << endl;
        cout << "[3] Buscar una clave específica por el nombre del servicio." << endl;
        cout << "[4] Cerrar KeyHasher" << endl;
        cout << "> ";
        cin >> menu;

        if (menu == 1) {
            string NuevoServicio, NuevaClave;
            cout << "Ingresa el nombre de su Servicio." << endl;
            cout << "> ";
            cin >> NuevoServicio;
            cout << "Ingresa su clave (minimo 8 caracteres)." << endl;
            cout << "> ";
            cin >> NuevaClave;

            if (NuevaClave.length() >= 8) {
                passwords.push_back(NuevaClave);
                servicios.push_back(NuevoServicio);
                cout << "[+] Servicio Y Clave Agregadas exitosamente" << endl;
            } else {
                cout << "[x] Error: La contraseña es muy corta (minimo 8 caracteres)." << endl;
            }
            
        } else if (menu == 2) { 
            cout << "⸻⸻ BOVEDA ⸻⸻" << endl;
            if (servicios.empty()) {
                cout << "La bóveda está vacía." << endl;
            } else {
                for (size_t i = 0; i < servicios.size(); i++) { 
                    string masked = string(passwords[i].length(), '*');
                    cout << "Servicio: " << servicios[i] << " | Password: " << masked << endl;
                }
            }
            
        } else if (menu == 3) { 
            string servicioBuscado;
            cout << "Ingresa el nombre del servicio que deseas buscar: ";
            cin >> servicioBuscado;

            bool encontrado = false; 
            for (int i = 0; i < servicios.size(); i++) {
                if (servicios[i] == servicioBuscado) {
                    cout << "[!] ¡Credencial Encontrada!" << endl;
                    cout << "Servicio | " << servicios[i] << endl;
                    cout << "Contraseña: " << passwords[i] << endl;
                    encontrado = true; 
                    break; 
                } 
            } 
            
            if (!encontrado) {
                cout << "[X] Error: El servicio '" << servicioBuscado << "' no existe en la bóveda." << endl;
            }
        }
    } 

    cout << "\nGracias por usar KeyHasher. ¡Adiós!" << endl;
    return 0;
}
