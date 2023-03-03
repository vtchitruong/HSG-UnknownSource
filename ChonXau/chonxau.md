## Đề bài

### Tóm tắt nội dung
Cho hai chuỗi (xâu) s1 và s2 gồm các ký tự từ a đến z.  
Thực hiện xóa một số ký tự trong hai chuỗi và giữ nguyên vị trí tương đối của các ký tự còn lại, nếu hai chuỗi con *s* nhận được sau khi xóa mà giống nhau thì *s* được gọi là chuỗi *chấp nhận được*.  

Tìm chuỗi *s* có thứ tự từ điển lớn nhất.  

### Sample Input
accacca  
abcda  

### Sample Output
ca  

### Giải thích
Các chuỗi con *chấp nhận được* của s1 và s2 là: **a, aa, ac, aca, c, ca**. Trong đó **ca** là chuỗi chấp nhận được có thứ tự từ điển lớn nhất.  

## Ý tưởng

**Bước 1**
Khởi tạo vector v1 và v2 tương ứng với s1 và s2.  
Mỗi vector lưu các ký tự và vị trí của từng ký tự trong chuỗi tương ứng.  

Vector *v1*
| | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
Ký tự | a | c | c | a | c | c | a |
Vị trí | 0 | 1 | 2 | 3 | 4 | 5 | 6 |

Vector *v2*
| | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| Ký tự | a | b | c | d | a |
| Vị trí | 0 | 1 | 2 | 3 | 4 |

**Bước 2**
Sắp xếp mỗi vector theo thứ tự *ký tự* giảm dần, nếu trùng *ký tự* thì *vị trí* tăng dần.  


Vector *v1*
| 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| c | c | c | c | a | a | a |
| 1 | 2 | 4 | 5 | 0 | 3 | 6 |

Vector *v2*
| 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|
| d | c | b | a | a |
| 3 | 2 | 1 | 0 | 4 |


**Bước 3**

Xác định vị trí có ký tự giống nhau đầu tiên trong *v1* và *v2*, đặt vị trí giống nhau này là *p1* và *p2* (*p1* là vị trí trong *v1*, *p2* là vị trí trong *v2*). Đồng thời, nạp ký tự giống nhau này vào vector *res*.  

Trong đó, vector *res* lưu các ký tự giống nhau giữa hai chuỗi theo thứ tự z-a.  

Cho *i1* chạy từ *p1 + 1* đến hết vector *v1*, thực hiện lặp:  
&emsp;Nếu ký tự tiếp theo nằm đằng sau ký tự *p1* (tức có vị trí trong *s1* lớn hơn) thì cho *i2* chạy từ *p2 + 1* đến hết vector *v2*, thực hiện lặp:
&emsp;&emsp;Nếu ký tự tiếp theo nằm đằng sau ký tự *p2* (tức có vị trí trong *s2* lớn hơn)  và ký tự *p2* giống với ký tự *p1* thì:  
&emsp;&emsp;&emsp;&emsp;Ghi nhận vị trí *p1* và *p2* mới.  
&emsp;&emsp;&emsp;&emsp;Nạp ký tự giống nhau này vào vector *res*.  

**Bước 4**
Output chính là vector *res*.  