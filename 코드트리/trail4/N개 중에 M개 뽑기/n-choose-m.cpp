#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> selected;

void dfs(int start) {
    // M개를 골랐다면 출력
    if (selected.size() == M) {
        for (int num : selected) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= N; i++) {
        selected.push_back(i);  // i 선택
        dfs(i + 1);            // 다음에는 i보다 큰 숫자만 선택
        selected.pop_back();   // 선택 취소 후 다음 경우 탐색
    }
}

int main() {
    cin >> N >> M;

    dfs(1);

    return 0;
}