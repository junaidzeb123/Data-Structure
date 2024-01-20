#include<iostream>
#include<queue>
#include<stack>

class Graph {
    int** matrix;
    int size;
public:
    Graph(int s) {
        size = s;
        matrix = new int* [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new int[size];
            for (int j = 0; j < size; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void addAdge(int start, int end) {
        matrix[start ][end ] = 1;
        matrix[end][start] = 1;
    }

    bool isEdge(int start, int end) {
        return matrix[start ][end];
    }

    void BFS(int root) {
        std::queue<int> q;
        q.push(root );
        bool* visited = new bool[size] {0};
        visited[root] = true;
        while (!q.empty()) {
            std::cout << q.front()<<" ";
            int temp = q.front();
            q.pop();
            for (int i = 0; i < size; i++) {
                if (matrix[temp][i] && visited[i] == false) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        delete[]visited;
    }


    void DFS(int root) {
        std::stack<int> st;
        st.push(root);
        bool* visited = new bool[size] {false};
        visited[root] = true;

        while (!st.empty())  {
            std::cout << st.top() << " ";
            int temp = st.top();
            st.pop();
            for (int i = 0; i < size; i++) {
                if (matrix[temp][i] && visited[i] == false) {
                    st.push(i);
                    visited[i] = true;
                }
            }
        }
        delete[] visited;
    }
};

int main() {
    Graph g(7);
    g.addAdge(0, 1);
    g.addAdge(0, 3);
    g.addAdge(1, 3);
    g.addAdge(1, 2);
    g.addAdge(1, 5);
    g.addAdge(2, 3);
    g.addAdge(2,5);
    g.addAdge(2,4);
    g.addAdge(3,4);
    g.addAdge(4,6);
    
    g.BFS(0);
    std::cout << "\n";

    g.DFS(0);
}