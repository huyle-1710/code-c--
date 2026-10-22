Giải thuật:
- Biến count là biến đếm.
- Biến target là mục tiêu cần tìm là phần tử chiếm đa số.
- Điều kiện cần của phần tử chiếm đa số:
+ Khi ta dùng biến count đếm số phần tử đa số và sẽ trừ đi khi gặp phần tử khác, khi đó vì target là phần tử đa số nên giá trị của count chắc chắn sẽ lớn hơn 0 khi duyệt hết mảng.
+ Vì vậy ta thiết lập vòng for, chạy hết phần tử mảng để dự đoán target qua điều kiện cần bằng cách mỗi khi giá trị count = 0, ta sẽ gán target với phần tử i, rồi cộng biến count nếu tiếp tục gặp target trong phân tử tiếp theo và trừ biến count nếu gặp phần tử khác target. Phần tử target cuối cùng thu được là phần tử dự đoán.
+ Do đây chỉ là điều kiện cần nên ta cần kiểm tra lại.
- Kiểm tra lại nếu biến đếm target lớn hơn n/2 thì sẽ in ra target, không tức là không tồn tại target.

## Định dạng input và output

- Dòng đầu: số phần tử `n` (`n >= 0`).
- Tiếp theo: `n` số nguyên của mảng. Với `n = 0`, chỉ nhập dòng `0`.
- Nếu có phần tử xuất hiện hơn `n/2` lần, in `Phần tử chiếm đa số là: <giá trị>`.
- Nếu không có, in `Không có phần tử chiếm đa số!`.
- Phần tử xuất hiện nhiều nhất hoặc xuất hiện đúng một nửa số phần tử chưa chắc là phần tử chiếm đa số.

## Ví dụ input/output

### Ví dụ 1: Có phần tử chiếm đa số

Input:
```text
11
2 8 7 2 2 5 2 3 1 2 2
```

Output:
```text
Phần tử chiếm đa số là: 2
```

### Ví dụ 2: Không có phần tử chiếm đa số

Input:
```text
5
1 2 3 4 5
```

Output:
```text
Không có phần tử chiếm đa số!
```

### Ví dụ 3: Xuất hiện đúng một nửa chưa phải đa số

Input:
```text
4
1 1 2 2
```

Output:
```text
Không có phần tử chiếm đa số!
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập: nhập `n` ở dòng đầu, sau đó nhập các phần tử ở dòng tiếp theo.

| Test | Trường hợp | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- |
| 1 | Mảng rỗng | 0 | Không có phần tử | `Không có phần tử chiếm đa số!` |
| 2 | Một phần tử | 1 | `7` | `Phần tử chiếm đa số là: 7` |
| 3 | Tất cả phần tử giống nhau | 4 | `4 4 4 4` | `Phần tử chiếm đa số là: 4` |
| 4 | Đa số là số 0 | 5 | `0 1 0 2 0` | `Phần tử chiếm đa số là: 0` |
| 5 | Đa số là số âm | 5 | `-1 2 -1 3 -1` | `Phần tử chiếm đa số là: -1` |
| 6 | Hai phần tử khác nhau | 2 | `1 2` | `Không có phần tử chiếm đa số!` |
| 7 | Nhiều nhất nhưng chưa quá một nửa | 7 | `1 1 1 2 2 3 4` | `Không có phần tử chiếm đa số!` |
| 8 | Ứng viên cuối không phải đa số | 3 | `1 2 3` | `Không có phần tử chiếm đa số!` |
| 9 | Đa số chỉ hơn một nửa một phần tử | 6 | `2 1 2 1 2 2` | `Phần tử chiếm đa số là: 2` |
| 10 | Phần tử đa số tập trung ở cuối | 7 | `1 2 3 9 9 9 9` | `Phần tử chiếm đa số là: 9` |

Ba ví dụ và 10 testcase trên đã được chạy đối chiếu với `Find_majority_element.cpp`, đều cho kết quả mong đợi.
