import sys
input = sys.stdin.readline

n = int(input())
tree = {}

for _ in range(n):
    x, y, z = input().split()
    tree[x] = [y, z]

def preorder(node):
    print(node, end='')
    if tree[node][0] != '.':
        preorder(tree[node][0])
    if tree[node][1] != '.':
        preorder(tree[node][1])

preorder('A')
print('')

def inorder(node):
    if tree[node][0] != '.':
        inorder(tree[node][0])
    print(node, end='')
    if tree[node][1] != '.':
        inorder(tree[node][1])

inorder('A')
print('')

def postorder(node):
    if tree[node][0] != '.':
        postorder(tree[node][0])
    if tree[node][1] != '.':
        postorder(tree[node][1])
    print(node, end='')

postorder('A')