## Đề bài

### Tóm tắt nội dung
*Bài này trích từ đề thi Học sinh giỏi Lớp 9 Thành phố tháng 03.2023*  

Mảng *b* gồm *n* số như sau:  
| 15 | 25 | -25 | 5 | 40 |
|---|---|---|---|---|

Mảng *a* cũng có *n* phần tử, trong đó phần tử thứ *i* là trung bình cộng của *i* phần tử đầu tiên trong mảng *b*.  
| 15 | 20 | 5 | 5 | 12 |
|---|---|---|---|---|

Yêu cầu bài toán là từ mảng *a*, tìm ra mảng *b*.  

### Sample Input
5  
15 20 5	5 12  

### Sample Output
15 25 -25 5 40  

### Giải thích
No explanation available here.  

## Ý tưởng

**Bước 1**
Khởi tạo mảng *res* chứa các số cần tìm (là mảng *b* ban đầu).  
Vì trung bình cộng của 1 phần tử là chính nó, nên gán *a[0]* cho *res[0]*.  

**Bước 2**
Duyệt các phần tử tiếp theo của mảng *a*, lặp các thao tác sau:  
&emsp;Lấy giá trị trung bình cộng *a[i]* nhân với số phần tử để có được tổng các phần tử, đặt là *sum_all*.  
&emsp;Tính tổng các phần tử đã có trước đó trong mảng *res*, đặt là *sum_before*.  
&emsp;Lấy *tổng tất cả* trừ đi *tổng các phần tử đã có*, ra được phần tử *res[i]* cần tìm.  