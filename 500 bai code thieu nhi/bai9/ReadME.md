Giải thuật:
Biến low lưu giá trị index của số 1 đầu tiên.
Biến mid là biến chạy duyệt các phần tử.
Biến high lưu giá trị index của số 1 cuối cùng.
Lặp vòng while với điều kiện dừng là mid sẽ lớn hơn high 
- Khi a[mid] = 0 thì ta sẽ swap phần tử vị trí low và mid, sau đó +1 cho biến low để cập nhật lại vị trí của số 1 đầu tiên, +1 cho biến mid để chuyển qua phần tử tiếp theo do phần tử hiện tại đã đúng vị trí.
- Khi a[mid] = 1 thì ta sẽ +1 cho biến mid để chuyển sang phần tử tiếp theo do nó đã ở đúng vị trí của nó
- Khi a[mid] = 2 thì ta sẽ swap phẩn tử ở vị trí mid với vị trí high để chuyển số 2 xuống cuối mảng, cập nhật lại vị trí của phần tử 1 cuối cùng bằng cách high trừ đi 1. Lúc này, ta vẫn tiếp tục xét phần tử mid trong vòng lặp tiếp theo (là phần tử high cũ).
=> Cứ tiếp tục như vậy ta sẽ thu được output của bài toán.

## Định dạng input và output

- Dòng đầu: số phần tử `n` (`n >= 1`).
- Dòng tiếp theo: `n` số nguyên, mỗi số chỉ nhận giá trị `0`, `1` hoặc `2`.
- Output: các phần tử được sắp xếp tăng dần, các số 0 đứng trước số 1 và các số 2 đứng cuối.

## Ví dụ input/output

### Ví dụ 1: Mảng có đủ 0, 1, 2

Input:
```text
12
0 1 2 2 1 0 0 2 0 1 1 0
```

Output:
```text
0 0 0 0 0 1 1 1 1 2 2 2
```

### Ví dụ 2: Trường hợp từng làm phiên bản cũ sai

Input:
```text
4
0 2 1 0
```

Output:
```text
0 0 1 2
```

### Ví dụ 3: Mảng theo thứ tự giảm dần

Input:
```text
6
2 2 1 1 0 0
```

Output:
```text
0 0 1 1 2 2
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập. Nhập `n` ở dòng đầu, sau đó nhập mảng ở dòng tiếp theo.

| Test | Trường hợp | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- |
| 1 | Chỉ có một số 0 | 1 | `0` | `0` |
| 2 | Chỉ có một số 1 | 1 | `1` | `1` |
| 3 | Chỉ có một số 2 | 1 | `2` | `2` |
| 4 | Toàn số 0 | 4 | `0 0 0 0` | `0 0 0 0` |
| 5 | Toàn số 1 | 4 | `1 1 1 1` | `1 1 1 1` |
| 6 | Toàn số 2 | 4 | `2 2 2 2` | `2 2 2 2` |
| 7 | Đã sắp xếp tăng dần | 6 | `0 0 1 1 2 2` | `0 0 1 1 2 2` |
| 8 | Không có số 0 | 5 | `2 1 2 1 1` | `1 1 1 2 2` |
| 9 | Không có số 1 | 5 | `2 0 2 0 0` | `0 0 0 2 2` |
| 10 | Không có số 2 | 5 | `1 0 1 0 1` | `0 0 1 1 1` |
| 11 | Các giá trị xen kẽ | 9 | `2 0 1 2 0 1 2 0 1` | `0 0 0 1 1 1 2 2 2` |
| 12 | Cần kiểm tra lại phần tử đổi từ cuối về | 3 | `1 2 0` | `0 1 2` |

