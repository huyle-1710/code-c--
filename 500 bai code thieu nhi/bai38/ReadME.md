# Bài 38: Mảng con có tích lớn nhất

## Đề bài

Cho một mảng số nguyên, tìm tích lớn nhất trong tất cả các mảng con liên tiếp không rỗng. Mảng có thể chứa số âm và số 0. Chỉ cần in giá trị tích lớn nhất, không cần in mảng con hoặc vị trí.

Ví dụ, với `{-6, 4, -5, 8, -10, 0, 8}`, đoạn `{4, -5, 8, -10}` có tích lớn nhất bằng `1600`.

## Giải thuật

Duyệt mảng và lưu ba biến:

- `maxEnd`: tích lớn nhất của một đoạn kết thúc tại vị trí hiện tại.
- `minEnd`: tích nhỏ nhất của một đoạn kết thúc tại vị trí hiện tại.
- `best`: tích lớn nhất tìm được trong toàn bộ phần đã duyệt.

Khởi tạo cả ba biến bằng `a[0]`. Với mỗi phần tử `x` tiếp theo:

1. Tính `p = maxEnd * x`, `q = minEnd * x` bằng các giá trị cũ.
2. Chọn `maxEnd` là giá trị lớn nhất trong `x`, `p`, `q`.
3. Chọn `minEnd` là giá trị nhỏ nhất trong `x`, `p`, `q`.
4. Nếu `maxEnd > best`, cập nhật `best`.

Cần lưu cả tích nhỏ nhất vì nhân một số âm có thể biến nó thành tích lớn nhất. Việc xét riêng `x` cho phép bắt đầu đoạn mới. Số 0 được xử lý trực tiếp bởi các bước trên.

## Định dạng input và output

### Input

1. Dòng đầu: số phần tử `n`.
2. Dòng tiếp theo: `n` số nguyên của mảng. Với `n = 0`, không nhập thêm phần tử.

### Output

- Nếu `n > 0`: in một số nguyên là tích lớn nhất.
- Nếu `n <= 0`: chương trình hiện tại in `Mang rong!`.

## Ví dụ input/output

### Ví dụ 1: Ví dụ đã phân tích

Input:

```text
7
-6 4 -5 8 -10 0 8
```

Output:

```text
1600
```

### Ví dụ 2: Số 0 ngăn cách các đoạn

Input:

```text
4
40 0 -20 -10
```

Output:

```text
200
```

### Ví dụ 3: Mảng rỗng

Input:

```text
0
```

Output:

```text
Mang rong!
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập: nhập `n` ở dòng đầu, sau đó nhập mảng ở dòng tiếp theo.

| Test | Trường hợp | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- |
| 1 | Một số dương | 1 | `7` | `7` |
| 2 | Một số âm | 1 | `-7` | `-7` |
| 3 | Một số 0 | 1 | `0` | `0` |
| 4 | Toàn số dương | 4 | `1 2 3 4` | `24` |
| 5 | Hai số âm | 2 | `-2 -3` | `6` |
| 6 | Số lượng số âm lẻ | 3 | `-2 -3 -4` | `12` |
| 7 | Âm nhân âm tạo tích lớn | 3 | `-2 3 -4` | `24` |
| 8 | Bắt đầu lại ở phần tử hiện tại | 2 | `-2 3` | `3` |
| 9 | Toàn số 0 | 3 | `0 0 0` | `0` |
| 10 | Số 0 giữa hai số âm | 3 | `-2 0 -3` | `0` |
| 11 | Đoạn tốt nhất nằm giữa | 5 | `0 -2 -3 4 0` | `24` |
| 12 | Nhiều đoạn cùng tích lớn nhất | 4 | `2 3 0 6` | `6` |
