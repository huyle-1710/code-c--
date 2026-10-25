Giải thuật:

Ý tưởng sẽ có 2 hàm, hàm đầu tiên là một hàm tìm giá trị max (độ dài đoạn 1 lớn nhất của mảng a), index bắt đầu là start và index kết thúc là end. Ta lưu thêm một mảng b chứa index của những số 0, và tính độ dài bằng cách lấy 2 vị trí index của những số 0 liên tiếp trừ đi nhau và cộng thêm 1, ở 2 đầu thì có cách xử lí trong code. Lưu giá trị độ dài này vào 1 biến tạm(tong) rồi so sánh với max, cập nhật lại start và end nếu tong>max. Hàm thứ 2 sẽ có đầu vào là biến k (số lượng số 0 bỏ đi) và mảng a, ta sẽ thay những vị trí liên tiếp của index 0 trong mảng index b thành 1 rồi dùng hàm thứ nhất. Key ở đây chính là việc thay các số 0 liên tiếp chứ không phải là k số 0 bất kì không theo thứ tự bởi vi liên tiếp chắc chắc sẽ cho ra độ dài lớn hơn k vị trí k liên tiếp.

## Đề bài

Cho một mảng nhị phân chỉ chứa `0` và `1`, cùng số nguyên không âm `k`. Được phép thay **tối đa k số 0 thành số 1**. Hãy tìm độ dài lớn nhất của một đoạn liên tiếp toàn số 1 có thể tạo ra, đồng thời in vị trí bắt đầu và kết thúc của đoạn đó.

Không bắt buộc thay đủ `k` số 0. Các vị trí được đánh số từ **0**. Đoạn được in là đoạn có thể biến thành toàn số 1; chương trình khôi phục mảng sau mỗi lần thử.

## Định dạng input và output

### Input

1. Dòng đầu: số `k` (`k >= 0`).
2. Dòng thứ hai: số phần tử `n` (`n >= 0`).
3. Dòng tiếp theo: `n` giá trị `0` hoặc `1`. Nếu `n = 0`, không nhập thêm phần tử.

### Output

Nếu có đoạn hợp lệ có độ dài dương:

```text
Kích thước tối đa là: <độ dài>
Từ vị trí <start> đến <end>
```

Nếu độ dài lớn nhất bằng 0, gồm cả trường hợp mảng rỗng:

```text
Kích thước tối đa là: 0
Không có đoạn số 1
```

Chương trình chỉ in một đoạn tốt nhất. Nếu có nhiều đoạn cùng độ dài, giữ kết quả đã tìm được trước đó trong quá trình thử. Các output bên dưới ghi đúng vị trí mà code hiện tại chọn.

## Ví dụ input/output

### Ví dụ 1: Không thay số 0

Input:

```text
0
12
1 1 0 1 1 0 1 1 1 1 0 0
```

Output:

```text
Kích thước tối đa là: 4
Từ vị trí 6 đến 9
```

### Ví dụ 2: Thay tối đa một số 0

Input:

```text
1
12
1 1 0 1 1 0 1 1 1 1 0 0
```

Output:

```text
Kích thước tối đa là: 7
Từ vị trí 3 đến 9
```

### Ví dụ 3: Thay tối đa hai số 0

Input:

```text
2
12
1 1 0 1 1 0 1 1 1 1 0 0
```

Output:

```text
Kích thước tối đa là: 10
Từ vị trí 0 đến 9
```

### Ví dụ 4: Không tạo được đoạn số 1

Input:

```text
0
3
0 0 0
```

Output:

```text
Kích thước tối đa là: 0
Không có đoạn số 1
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập. Nhập theo thứ tự `k`, `n`, rồi mảng. Mỗi dòng hiển thị trong cột output là một dòng in riêng.

| Test | Trường hợp | k | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- | --- |
| 1 | Mảng rỗng | 0 | 0 | Rỗng | `Kích thước tối đa là: 0`<br>`Không có đoạn số 1` |
| 2 | Một số 1 | 0 | 1 | `1` | `Kích thước tối đa là: 1`<br>`Từ vị trí 0 đến 0` |
| 3 | Một số 0 được thay | 1 | 1 | `0` | `Kích thước tối đa là: 1`<br>`Từ vị trí 0 đến 0` |
| 4 | Toàn số 1 | 2 | 4 | `1 1 1 1` | `Kích thước tối đa là: 4`<br>`Từ vị trí 0 đến 3` |
| 5 | Toàn số 0 | 2 | 4 | `0 0 0 0` | `Kích thước tối đa là: 2`<br>`Từ vị trí 0 đến 1` |
| 6 | k lớn hơn số lượng số 0 | 5 | 3 | `0 1 0` | `Kích thước tối đa là: 3`<br>`Từ vị trí 0 đến 2` |
| 7 | k bằng số lượng số 0 | 2 | 3 | `0 1 0` | `Kích thước tối đa là: 3`<br>`Từ vị trí 0 đến 2` |
| 8 | Đoạn tốt nhất nằm ở cuối | 1 | 8 | `1 0 1 1 0 1 1 1` | `Kích thước tối đa là: 6`<br>`Từ vị trí 2 đến 7` |
| 9 | Các giá trị xen kẽ | 1 | 5 | `1 0 1 0 1` | `Kích thước tối đa là: 3`<br>`Từ vị trí 0 đến 2` |
| 10 | Số 0 ở hai đầu | 1 | 4 | `0 1 1 0` | `Kích thước tối đa là: 3`<br>`Từ vị trí 0 đến 2` |
| 11 | Nhiều đoạn cùng độ dài | 0 | 5 | `1 1 0 1 1` | `Kích thước tối đa là: 2`<br>`Từ vị trí 0 đến 1` |
| 12 | k bằng 0, có nhiều số 0 | 0 | 6 | `0 1 1 0 1 0` | `Kích thước tối đa là: 2`<br>`Từ vị trí 1 đến 2` |

## Độ phức tạp và kiểm tra

- Code hiện tại thử các nhóm số 0 liên tiếp trong danh sách vị trí và tìm lại đoạn số 1 dài nhất, có thời gian `O(n²)` trong trường hợp xấu nhất.
- Bộ nhớ phụ: `O(n)` cho các danh sách vị trí và bản sao mảng trong hàm tìm đoạn.
- Bốn ví dụ và 12 testcase trên đã được chạy với `b27.cpp`. Độ dài được đối chiếu bằng cách xét tất cả các đoạn; vị trí trả về cũng được kiểm tra. Tất cả đều đúng.
