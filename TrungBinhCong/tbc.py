import os
import sys

input_file = os.path.join(sys.path[0], 'tbc.inp')
output_file = os.path.join(sys.path[0], 'tbc.out')

N = 0
B = []

def input_data():
    global N, B
    with open(input_file) as f:
        N = int(f.readline())
        B = list(map(int, f.readline().split()))


def process():
    # Khởi tạo mảng A gồm các phần tử 0
    global N, B
    A = [0 for _ in range(N)]
    A[0] = B[0]
    
    # Lấy tổng suy từ giá trị trung bình trừ đi tổng các phần tử hiện có
    for i in range(1, N):
        # Tính tổng suy từ giá trị trung bình
        total_average = B[i] * (i + 1)

        # Tính tổng các phần tử hiện có trong mảng A
        total_current = sum(A[0: i + 1])

        # Tính A[i]
        A[i] = total_average - total_current

    return A


def output():
    A = process()
    
    with open(output_file, 'w') as f:
        f.write(' '.join(map(str, A)))


if __name__ == '__main__':
    input_data()
    output()