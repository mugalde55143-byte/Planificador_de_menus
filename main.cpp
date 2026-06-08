#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <limits>
using namespace std;

/**
 * @class Receta
 * @brief Representa una receta de comida por dia
 * @details Almacena el nombre de la comida, junto con sus ingredientes y cantidades proporcionadas para cada una
 *
 * @author Maria Carmen Ugalde Cristobal
 * @date 07/06/2026
 * @version 1.0
 *par Ejemplo de uso
 * @code
 * Receta receta;
 * receta.nombre = "Enchiladas Verdes";
 *
 * receta.ingredientes["Tortillas"] = 20;
 * receta.ingredientes["Pollo"] = 2;
 * @endcode
 * @note Proyecto de primer parcial Profesor: Israel Marquez Tapia
 * Cada ingrediente se almacena  con su nombre y la cantidad requerida
 */

class Receta
{
public:

    /**
     * @brief Nombre de la receta
     * @details Guarda el nombre del platillo
     */
    string nombre;            // O(1)

    /**
     * @brief Ingredientes de la receta
     * @details  Almacena el nombre de una comida, ingredientes y cantidades proporcionada para cada una

     */
    map<string, int> ingredientes;                // O(1)
};

/**
 * @class Planificador Semanal
 * @brief Gestiona el menu semanal
 * @details Permite almacenar recetas asociadas a los dias de la semana,
 * mostrar el menu completo y generar una lista consolidada de compras, segun los antojos de la persona
 * @warning No valida ingredientes duplicados escritos con nombres diferentes
 */

class PlanificadorSemanal
{
public:

    /**
     * @brief Menu semanal
     * @details Cada elemento contiene formato por el nombre
     * del dia y la receta correspondiente
     * * * @par Ejemplo
     * @code
     * semana.agregarReceta("Lunes", receta);
     * semana.agregarReceta("Martes", receta);
     * @endcode
     */
    vector<pair<string, Receta>> menu; // O(1)

    /**
     * @brief Agrega una receta al menu
     * @details Inserta al final del vector del menu
     *
     */
    void agregarReceta(string dia, Receta receta)
    {
        menu.push_back({ dia, receta }); // O(1)
    }

    /**
     * @brief Muestra el menu semanal
     * @details Recorre todos los dias y sus ingredientes
     */
    void mostrarMenu()
    {
        cout << "\n=====    PLANIFICADOR SEMANAL =====\n\n"; // O(1)

        for (auto dia : menu) // O(1)     O(7)
        {
            cout << "Dia: " << dia.first << endl; // O(1)
            cout << "Comida: " << dia.second.nombre << endl; // O(1)

            cout << "Ingredientes:" << endl;

            for (auto ingrediente : dia.second.ingredientes) // O((n)
            {
                cout << "- " << ingrediente.first
                    << ": " << ingrediente.second << endl; // O(1)
            }

            cout << endl; // O(1)
        }
    }

    /**
     * @brief Genera lista de compras
     * @details Suma las cantidades de ingredientes de todas las recetas
     * registradas durante la semana y las muestra en la consola
     * * @par Ejemplo de salida
     * @code
     * ===== LISTA DE COMPRAS =====
     *
     * Tortillas: 40
     * Pollo: 4
     * Crema: 2
     * @endcode
     * @note Los ingredientes repetidos se agrupan
     */
    void mostrarListaCompras()
    {
        map<string, int> listaCompras;                                           // O(1)

        for (auto dia : menu)                                                    // O(n)     O(7)
        {
            for (auto ingrediente : dia.second.ingredientes)                   // O(n)
            {
                listaCompras[ingrediente.first] += ingrediente.second;              // O(1)
            }
        }

        cout << "\n===== LISTA DE COMPRAS =====\n\n";                                 // O(1)

        for (auto ingrediente : listaCompras)                                     // O(n)
        {
            cout << ingrediente.first
                << ": " << ingrediente.second << endl; // O(1)
        }
    }
};

/**
 * @brief Funcion principal del programa
 * @details Menu interactivo para crear y gestionar el plan semanal
 * solicita al usuario la comida correspondiente a cada dia
 * de la semana, junto con sus ingredientes y cantidades, al finalizar,
 * muestra el menu semanal y la lista de compras
 *  @par Flujo principal
 * @code
 * for (int i = 0; i < 7; i++)
 * {
 *     Receta receta;
 *     getline(cin >> ws, receta.nombre);
 *     semana.agregarReceta(dias[i], receta);
 * }
 *
 * semana.mostrarMenu();
 * semana.mostrarListaCompras();
 * @endcode
 * @return 0 si el programa finaliza correctamente
 * @warning Los nombres de ingredientes deben escribirse de forma consistente
 * para evitar duplicados innecesarios en la lista de compras
 */
int main()
{
    string dias[7] =
    {
        "Lunes","Martes","Miercoles",
        "Jueves","Viernes","Sabado","Domingo"
    };                                                                        // O(1)

    PlanificadorSemanal semana;                                               // O(1)
    int opcion;                                                               // O(1)

    do
    {
        cout << "\n===== PLANIFICADOR DE MENUS =====\n";                              // O(1)
        cout << "1. Crear mi propio menu\n";                                   // O(1)
        cout << "2. Ver comidas rapidas\n";                                   // O(1)
        cout << "3. Sugerir comida aleatoria\n";                              // O(1)
        cout << "4. Ver menu semanal\n";                                      // O(1)
        cout << "5. Ver lista de compras\n";                                   // O(1)
        cout << "6. Salir\n";                                                  // O(1)

        cin >> opcion;                                                          // O(1)

        /**
         * @brief Opcion 1 - crear menu
         */
        if (opcion == 1)
        {
            for (int i = 0; i < 7; i++)                                        // O(1)   O(7)
            {
                Receta receta;                                                 // O(1)

                cout << "\nComida para " << dias[i] << ": ";                  // O(1)
                getline(cin >> ws, receta.nombre);                              // O(1)

                int numIngredientes;                                             // O(1)
                cout << "Cantidad de ingredientes: ";                            // O(1)
                cin >> numIngredientes;                                            // O(1)
                /**
       * @brief Captura de ingredientes
       * @details Solicita al usuario el nombre y la cantidad
       * de cada ingrediente de la receta actual
       *@code
       * Ingrediente 1: Tortillas
       * Cantidad: 20
       *
       * Ingrediente 2: Pollo
       * Cantidad: 2
       * @endcode
       */
                for (int j = 0; j < numIngredientes; j++)                                   // O(n)
                {
                    string ingrediente;                                                       // O(1)
                    int cantidad;                                                             // O(1)

                    cout << "Ingrediente " << j + 1 << ": ";                                    // O(1)
                    getline(cin >> ws, ingrediente);                                          // O(1)

                    cout << "Cantidad: ";                                                        // O(1)
                    cin >> cantidad;                                                             // O(1)

                    receta.ingredientes[ingrediente] = cantidad; // O(1)
                }

                semana.agregarReceta(dias[i], receta);                                           // O(1)
            }
        }

        /**
         * @brief Opcion 2 - comidas rapidas
         */
        else if (opcion == 2)
        {
            cout << "\nComidas rapidas:\n";
            cout << "- Tacos\n- Hamburguesa\n- Pizza\n- Quesadillas\n";
        }

        /**
         * @brief Opcion 3 - comida aleatoria
         */
        else if (opcion == 3)
        {
            vector<string> comidas =                    // O(1)
            {
                "Tacos","Pizza","Hamburguesa","Sushi"     // O(1)
            };

            cout << "Te recomiendo: "
                << comidas[rand() % comidas.size()] << endl;      // O(1)
        }

        /**
         * @brief Opcion 4 - mostrar menu
         */
        else if (opcion == 4)
        {
            semana.mostrarMenu();          // O(n)
        }

        /**
         * @brief Opcion 5 - lista de compras
         */
        else if (opcion == 5)
        {
            semana.mostrarListaCompras();  // O(n)
        }

    } while (opcion != 6); // O(1)

    return 0; // O(1)
}
// Complejidad         6n    = O(n)
