/* Дано невзвешенное дерево. Расстоянием между двумя вершинами будем называть
 * количество ребер в пути, соединяющем эти две вершины.
 * Для каждой вершины определите сумму расстояний до всех остальных вершин.
 * Время работы должно быть O(n).
 */
#include <bits/stdc++.h>

using namespace std;

long long way(int v, vector<int>& subtree_node_number, vector<vector<int> >& g) {
    int len = 0;
    for (int i = 0, sz = int(g[v].size()); i < sz; i++) {
        int u = g[v][i];
        len += way(u, subtree_node_number, g) + subtree_node_number[u];
        subtree_node_number[v] += subtree_node_number[u];
    }
    subtree_node_number[v]++;
    return len;
}

int main() {
    // Ввод данных
    int n;
    cin >> n;

    vector<vector<int> > g(n);
    vector<int> pred(n);
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        g[a].push_back(b);
        pred[b] = a;
    }

    // Нахождение ответа по описанному алгоритму и вывод ответа
    vector<int> subtree_node_number (n, 0);
    vector<long long > sub_vertex_dist (n, 0);

    // Предподсчет расстояния и количества вершин
    vector<long long > rast(n);
    rast[0] = way(0, subtree_node_number, g);
    cout << rast[0] << '\n';

    // Пересчет ответа
    for (int v = 1; v < n; ++v) {
        rast[v] = rast[pred[v]] - subtree_node_number[v] + (n - subtree_node_number[v]);
        cout << rast[v] << '\n';
    }

    return 0;
}
