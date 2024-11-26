#include <vector>
#include <random>
#include <ctime>

using namespace std;

template <typename T>
class SkipList {
private:
    class Node {
    public:
        T value;
        vector<Node*> forward;
        Node(T value, int level) : value(value), forward(level + 1, nullptr) {}
    };

    Node* header;
    int maxLevel;
    int currentLevel;
    float probability;

    int randomLevel() {
        static random_device rd;
        static mt19937 gen(rd());
        static bernoulli_distribution dis(probability);

        int level = 0;
        while (dis(gen) && level < maxLevel) {
            level++;
        }
        return level;
    }

public:
    SkipList(int maxLevel = 16, float probability = 0.5)
        : maxLevel(maxLevel), currentLevel(0), probability(probability) {
        header = new Node(T(), maxLevel); // Nodo cabecera con valor por defecto
    }

    ~SkipList() {
        Node* current = header;
        while (current) {
            Node* temp = current;
            current = current->forward[0];
            delete temp;
        }
    }

    void insert(T value) {
        vector<Node*> update(maxLevel + 1, nullptr);
        Node* current = header;

        for (int i = currentLevel; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr || current->value != value) {
            int newLevel = randomLevel();

            if (newLevel > currentLevel) {
                for (int i = currentLevel + 1; i <= newLevel; i++) {
                    update[i] = header;
                }
                currentLevel = newLevel;
            }

            Node* newNode = new Node(value, newLevel);

            for (int i = 0; i <= newLevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    bool search(T value) {
        Node* current = header;

        for (int i = currentLevel; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];
        return current != nullptr && current->value == value;
    }

    void remove(T value) {
        vector<Node*> update(maxLevel + 1, nullptr);
        Node* current = header;

        for (int i = currentLevel; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current != nullptr && current->value == value) {
            for (int i = 0; i <= currentLevel; i++) {
                if (update[i]->forward[i] != current) {
                    break;
                }
                update[i]->forward[i] = current->forward[i];
            }

            while (currentLevel > 0 && header->forward[currentLevel] == nullptr) {
                currentLevel--;
            }

            delete current;
        }
    }

    void print() {
        for (int i = currentLevel; i >= 0; i--) {
            Node* current = header->forward[i];
            cout << "Level " << i << ": ";
            while (current != nullptr) {
                cout << current->value << " ";
                current = current->forward[i];
            }
            cout << endl;
        }
    }
};