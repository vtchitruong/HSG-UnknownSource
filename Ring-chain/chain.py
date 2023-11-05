import os
import sys

input_file = os.path.join(sys.path[0], 'chain4.inp')
output_file = os.path.join(sys.path[0], 'chain4.out')

n = 0  # Số lượng chuỗi
L = [] # Độ dài của mỗi chuỗi

def input_data():
    with open(input_file) as f:
        global n
        n = int(f.readline())

        global L
        for x in list(map(int, f.readline().split())):
            L.append(x)


def process():
    # Sắp xếp số vòng trong mỗi chuỗi tăng dần
    L.sort()

    # Số lần mở vòng
    remove_times = 0

    # Mở từng vòng, bắt đầu từ chuỗi đầu tiên, có ít vòng nhất (đã sort ở trên)
    while L[0] > 0:
        # Mở 1 vòng
        L[0] -= 1

        # Xóa bỏ chuỗi cuối cùng
        L.pop()

        # Cộng thêm 1 lần mở vòng
        remove_times += 1
        
        # Nếu chỉ còn một chuỗi duy nhất thì dừng thuật toán
        if len(L) == 1:
            return remove_times

        # Nếu chuỗi đầu tiên không còn vòng nào để mở nữa
        # thì "xóa bỏ" chuỗi này khỏi vector L để chuẩn bị mở vòng của chuỗi tiếp theo
        if L[0] == 0:        
            L.pop(0)

            # Nếu chỉ còn một chuỗi duy nhất thì dừng thuật toán
            if len(L) == 1:            
                return remove_times
    
    return remove_times


def output():
    res = str(process())

    with open(output_file, 'w') as f:
        f.write(res)


if __name__ == '__main__':
    input_data()
    output()

