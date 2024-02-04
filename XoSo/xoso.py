import os
import sys

input_file = os.path.join(sys.path[0], 'xoso.inp')
output_file = os.path.join(sys.path[0], 'xoso.out')

n = k = 0
a = []
choices = [] # Mảng chứa các cách chọn bộ k số


def input_data():
    global n, k, a
    with open(input_file) as f:
        n, k = map(int, f.readline().split())
        a = list(map(int, f.readline().split()))


# Hàm tạo bộ k số từ n số bằng back-tracking và đệ quy
def generate(choice, next):
    # Nếu một bộ đã có đủ k số thì nạp vào choices và dừng đệ quy
    global a, choices
    if len(choice) == k:
        choices.append(choice.copy())
        return

    # Ứng với mỗi số x trong n số:
    # - Nạp số x này vào bộ đang xét chọn
    # - Gọi đệ quy để nạp số tiếp theo vào vị trí tiếp theo của bộ đang xét chọn
    # - Gỡ bỏ x ở vị trí cuối của bộ đang xét chọn 
    for i in range(next, len(a)):
        choice.append(a[i])
        generate(choice, i + 1)
        choice.pop()


def process():
    # Khởi tạo biến choice nhằm phục vụ cho việc gọi đệ quy
    choice = []
    generate(choice, 0)

    # Mảng chứa các điểm thưởng
    bonus = []

    # Tính điểm thưởng của từng bộ số rồi nạp vào bonus
    global choices
    for i in range(len(choices)):
        m = max(choices[i])
        bonus.append(m)

    # Tính tổng điểm thưởng
    sum_bonus = sum(bonus, 0)
    return int(sum_bonus % (10e9 + 7))


def output():
    res = str(process())

    with open(output_file, 'w') as f:
        f.write(res)


def show_choices():
    global choices
    for choice in choices:
        print(*choice)


if __name__ == '__main__':
    input_data()
    output()
    show_choices()