Giải thuật:

Ta khai báo một vector kết quả b với toàn 1.
Chỉ số r, l để lưu các giá trị tích phải và trái.
Vòng for thứ nhất cho ta được tích trái của phần tử thứ i.
Vòng for thứ 2 nhân tích trái vào tích phải(cách tính tích phải tương tự tích trái)
=> thu được output

## Đề bài

Cho một mảng số nguyên, tạo mảng kết quả trong đó mỗi phần tử bằng tích của tất cả phần tử còn lại trong mảng ban đầu, ngoại trừ phần tử tại chính vị trí đó. Không sử dụng phép chia.

## Định dạng input và output

- Dòng đầu: số phần tử `n`. Các ví dụ và testcase dưới đây dùng `n >= 1`.
- Dòng tiếp theo: `n` số nguyên của mảng.
- Output: `n` giá trị kết quả theo đúng thứ tự vị trí, cách nhau bằng dấu cách.
- Với mảng có một phần tử, tích của các phần tử còn lại được quy ước bằng `1`.

## Ví dụ input/output

### Ví dụ 1: Các số nguyên dương

Input:
```text
5
1 2 3 4 5
```

Output:
```text
120 60 40 30 24
```

### Ví dụ 2: Mảng có sáu phần tử

Input:
```text
6
5 3 4 2 6 8
```

Output:
```text
1152 1920 1440 2880 960 720
```

### Ví dụ 3: Mảng có một số 0

Input:
```text
4
1 2 0 4
```

Output:
```text
0 0 8 0
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập: nhập `n` ở dòng đầu, sau đó nhập mảng ở dòng tiếp theo.

| Test | Trường hợp | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- |
| 1 | Hai phần tử | 2 | `3 7` | `7 3` |
| 2 | Một phần tử | 1 | `5` | `1` |
| 3 | Một phần tử bằng 0 | 1 | `0` | `1` |
| 4 | Tất cả bằng 1 | 4 | `1 1 1 1` | `1 1 1 1` |
| 5 | Hai số 0 | 4 | `0 2 0 4` | `0 0 0 0` |
| 6 | Toàn số 0 | 3 | `0 0 0` | `0 0 0` |
| 7 | Có số âm | 4 | `-1 2 -3 4` | `-24 12 -8 6` |
| 8 | Toàn số âm | 3 | `-1 -2 -3` | `6 3 2` |
| 9 | Các phần tử giống nhau | 4 | `2 2 2 2` | `8 8 8 8` |
| 10 | Số 0 ở đầu và có số âm | 3 | `0 -2 3` | `-6 0 0` |