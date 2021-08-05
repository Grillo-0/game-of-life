#include <vector>

using namespace std;
using std::vector;

class Cell{
    public:
        bool m_currState;
        bool m_nextState;
        vector<Cell*> m_neighbours;

        Cell();
        void updateState();

        void createConection(Cell *node);
};
