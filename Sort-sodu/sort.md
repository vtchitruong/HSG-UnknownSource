Giả sử dãy số *n* gồm các số bắt đầu từ 0 đến *n*.
Ta có thể lần lượt đặt từng số vào *chỗ ngồi* trong bảng gồm *m* cột như Mảng 1.

**Mảng 1**
|     | 0 | 1 | 2 | 3 |
|-----|-----|-----|-----|-----|
| **0** | 0   | 1   | 2   | 3   |
| **1** | 4   | 5   | 5   | 7   |
| **2** | 8   | 9   | 10  |     |


Số phần tử của dãy *n* lúc này là *n + 1* phần tử, vì có số 0. Số *hàng ghế* mà dãy *n* chiếm dụng là trong trường hợp này lả 3, theo phép tính sau:
*rowNumber = (n + 1) / m*
-- Nếu chia hết, thì giữ nguyên *rowNumber*.
-- Nếu chia có dư, thì tăng thêm 1 *hàng ghế*: *rowNumber = rowNumber + 1*

Tiếp theo, chuyển vị Mảng 1 từ hàng-cột thành cột-hàng, được Mảng 2 (Tương tự lệnh Paste Transpose trong Excel):

**Mảng 2**
|   | 0 | 1 | 2  |
|---|---|---|----|
| **0** | 0 | 4 | 8  |
| **1** | 1 | 5 | 9  |
| **2** | 2 | 6 | 10 |
| **3** | 3 | 7 |    |

Lúc này, mỗi hàng đã chứa các số có cùng số dư trong phép chia cho *m* (Hàng 0 chứa các số chia *m* dư 0; hàng 1 chứa các số chia *m* dư 1, v.v.), và *rowNumber* không còn là số hàng của Mảng 1, mà trở thành số lượng phần tử (tức số cột) trong mỗi hàng của Mảng 2.

Do đó, để xác định số nằm ở vị trí *t*, trước hết ta tính hàng và cột của vị trí *t*:
-- Hàng: là thương của phép chia *t* cho *rowNumber*.
-- Cột: là số dư của phép chia *t* cho *rowNumber*.

Cụ thể:
*row =  t / rowNumber*
*col = t % rowNumber*

Sau đó, tính số cần tìm theo phép tính: *row + (col * m)*.

Một cách diễn đạt khác, *row* có thể được xem là **vị trí xuất phát** (xuất phát hoặc từ 0, hoặc từ 1, hoặc từ 2, v.v.), *col* là **số lần nhảy** sang cột khác, *m* là **khoảng cách** của mỗi lần nhảy.