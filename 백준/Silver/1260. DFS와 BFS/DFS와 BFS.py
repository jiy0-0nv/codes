from __future__ import annotations
import copy
from collections import deque
from collections import defaultdict
from typing import DefaultDict, List


class Graph:
    def __init__(self, n: int) -> None:
        """
        그래프 초기화
        n: 정점의 개수 (1번부터 n번까지)
        """
        self.n = n
        self.edges = [[] for _ in range(n + 1)]
        self.is_sorted = False
    
    def sort_edges(self):
        if not self.is_sorted:
            for e in self.edges:
                e.sort()
    
    def add_edge(self, u: int, v: int) -> None:
        """
        양방향 간선 추가
        """
        self.edges[u].append(v)
        self.edges[v].append(u)
    
    def dfs(self, start: int) -> list[int]:
        """
        깊이 우선 탐색 (DFS)
        
        구현 방법 선택:
        1. 재귀 방식: 함수 내부에서 재귀 함수 정의하여 구현
        2. 스택 방식: 명시적 스택을 사용하여 반복문으로 구현
        """

        res = [start]
        visited = set([start])

        self.sort_edges()
        
        def dfs_search(s):
            for v in self.edges[s]:
                if v not in visited:
                    visited.add(v)
                    res.append(v)
                    dfs_search(v)
        
        dfs_search(start)

        return res

    
    def bfs(self, start: int) -> list[int]:
        """
        너비 우선 탐색 (BFS)
        큐를 사용하여 구현
        """
        
        res = [start]
        visited = set([start])
        q = deque([start])
        
        self.sort_edges()

        while q:
            n = q.popleft()
            for v in self.edges[n]:
                if v not in visited:
                    visited.add(v)
                    res.append(v)
                    q.append(v)
        
        return res

    
    def search_and_print(self, start: int) -> None:
        """
        DFS와 BFS 결과를 출력
        """
        dfs_result = self.dfs(start)
        bfs_result = self.bfs(start)
        
        print(' '.join(map(str, dfs_result)))
        print(' '.join(map(str, bfs_result)))



from typing import Callable
import sys


"""
-아무것도 수정하지 마세요!
"""


def main() -> None:
    intify: Callable[[str], list[int]] = lambda l: [*map(int, l.split())]

    lines: list[str] = sys.stdin.readlines()

    N, M, V = intify(lines[0])
    
    graph = Graph(N)  # 그래프 생성
    
    for i in range(1, M + 1): # 간선 정보 입력
        u, v = intify(lines[i])
        graph.add_edge(u, v)
    
    graph.search_and_print(V) # DFS와 BFS 수행 및 출력


if __name__ == "__main__":
    main()
