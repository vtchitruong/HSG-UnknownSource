## Đề bài

### Tóm tắt nội dung
*Bài này trích từ đề thi Học sinh giỏi Lớp 9 Thành phố tháng 03.2023*  

Cho N số và chọn K số trong đó. Ứng với mỗi lần chọn một bộ gồm K số, số lớn nhất trong bộ sẽ là điểm thưởng của bộ đó.  

Tính S là tổng điểm thưởng của các bộ, trong đó kết quả là phần dư của phép chia S cho 10^9 + 7.  

### Sample Input
4 2  
6 7 6 5

### Sample Output
39

### Giải thích
N = 4 và K = 2, tức chọn bộ gồm 2 số từ 4 số ban đầu.  
Có tất cả 6 cách chọn, tương ứng với 6 bộ. Tổng của các giá trị lớn nhất là 39.  

## Ý tưởng

**Bước 1**  
Tạo hàm Generate để phát sinh (chọn) một bộ số bằng đệ quy.  
&emsp;- Nếu một bộ đã có đủ *k* số thì dừng đệ quy và nạp bộ này vào vector *cac_cachchon*.  
&emsp;- Ứng với mỗi số *x* trong *n* số:  
&emsp;&emsp;+ Nạp số *x* này vào bộ đang xét chọn (vector *cachchon_hientai*).  
&emsp;&emsp;+ Gọi đệ quy để nạp số tiếp theo vào bộ đang xét chọn tại ví trị *i* kế tiếp.  
&emsp;&emsp;+ Gỡ bỏ số *x* ở vị trị cuối của bộ đang xét chọn (để chuẩn bị nạp *x* kế tiếp trong *n* số).  

**Bước 2**  
Tính giá trị lớn nhất của mỗi bộ. Nạp các giá trị lớn nhất vào vector *diem_thuong*.  

**Bước 3**  
Tính tổng các phần tử trong vector *diem_thuong*.  