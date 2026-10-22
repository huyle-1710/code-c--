Giải thuật:

Biến low và high lưu index đầu và cuối của mảng con có tổng lớn nhất.
Biến max lưu giá trị của tổng lớn nhất.
Biến tong lưu giá trị của tong ở vị trí thứ i.
Biến start để lưu vị trí bắt đầu của tong.

- Đầu tiên nếu size của a bằng 0 thì in ra mảng rỗng
- Còn lại thì ta khai báo các biến kể trên, cho biến low, high, start = 0, cho biến tong và max bằng a[0]. Chạy vòng for từ i bằng 1 đến cuối mảng.
- Nếu tong < 0, tức tổng này không có ích thì ta đặt lại vị trí start của tong từ i và gán tong với a[i]
- Nếu tong > 0, tức tổng có ích hay có khả năng chứa hoặc tạo ra max thì ta sẽ cộng thêm tong phần tử a[i].
- Ngoài ra, trong mỗi vòng lặp ta so sánh tong với max hiện tại, nếu lớn hơn cập nhật lại max = tong, low = start và high = i.
Bản chất của thuật toán là nhìn ra điều kiện cần của max là khi ta chạy từ trái sang phải của một mảng thì nếu xét đến phần tử a[i] trong max thì tổng các phần tử trước đó phải lớn hơn 0. Lưu ý đây chỉ là điều kiện cần.

## Định dạng input và output

- Dòng đầu: số phần tử `n` (`n >= 0`).
- Dòng tiếp theo: `n` số nguyên của mảng. Nếu `n = 0`, chỉ cần nhập `0`.
- Với mảng không rỗng: dòng đầu của output là tổng lớn nhất, dòng tiếp theo là các phần tử của mảng con liên tiếp tương ứng.
- Với mảng rỗng: in `Mảng rỗng`.
- Nếu mảng không rỗng, mảng con được chọn phải có ít nhất một phần tử. Vì vậy, mảng toàn số âm có đáp án là phần tử lớn nhất.
- Nếu nhiều đoạn có cùng tổng lớn nhất, output dưới đây ghi đúng đoạn mà code hiện tại chọn: chỉ cập nhật khi tổng mới lớn hơn, và giữ điểm bắt đầu khi tổng tạm thời bằng 0.

## Ví dụ input/output

### Ví dụ 1: Mảng có cả số âm và số dương

Input:
```text
9
-2 1 -3 4 -1 2 1 -5 4
```

Output:
```text
6
4 -1 2 1
```

### Ví dụ 2: Mảng toàn số âm

Input:
```text
3
-5 -2 -8
```

Output:
```text
-2
-2
```

### Ví dụ 3: Mảng rỗng

Input:
```text
0
```

Output:
```text
Mảng rỗng
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập: nhập `n`, sau đó nhập mảng ở dòng tiếp theo. Cột mảng con tương ứng với dòng thứ hai của output.

| Test | Trường hợp | n | Mảng đầu vào | Tổng lớn nhất | Mảng con được in |
| --- | --- | --- | --- | --- | --- |
| 1 | Một phần tử dương | 1 | `7` | `7` | `7` |
| 2 | Một phần tử âm | 1 | `-7` | `-7` | `-7` |
| 3 | Một phần tử bằng 0 | 1 | `0` | `0` | `0` |
| 4 | Toàn số dương | 4 | `1 2 3 4` | `10` | `1 2 3 4` |
| 5 | Toàn số 0 | 4 | `0 0 0 0` | `0` | `0` |
| 6 | Đoạn tốt nhất ở đầu | 4 | `5 4 -20 1` | `9` | `5 4` |
| 7 | Đoạn tốt nhất ở cuối | 5 | `-8 1 -4 3 5` | `8` | `3 5` |
| 8 | Đoạn tốt nhất nằm giữa | 4 | `-5 4 3 -10` | `7` | `4 3` |
| 9 | Giữ số âm để nối hai phần có lợi | 4 | `4 -1 2 1` | `6` | `4 -1 2 1` |
| 10 | Bỏ đoạn có tổng âm để bắt đầu lại | 4 | `2 -5 4 3` | `7` | `4 3` |
| 11 | Nhiều đoạn cùng có tổng lớn nhất | 3 | `1 -1 1` | `1` | `1` |
| 12 | Tổng tạm thời bằng 0 | 4 | `0 2 -2 2` | `2` | `0 2` |

Ba ví dụ và 12 testcase trên đã được chạy đối chiếu với `timmangconcotonglonnhat.cpp`. Tổng lớn nhất được kiểm tra độc lập bằng cách xét tất cả các mảng con không rỗng; tất cả đều đúng.
