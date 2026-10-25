# Bài 3: In tất cả mảng con có tổng bằng 0

## Đề bài

Cho một mảng số nguyên, hãy in tất cả các mảng con **liên tiếp, không rỗng** có tổng bằng `0`. Mảng có thể chứa số âm, số dương và số 0.

Các đoạn ở vị trí khác nhau được xem là các kết quả riêng, kể cả khi có cùng dãy giá trị. Các đoạn được phép chồng lấn.

Giải thuật

- Hàm `inMang` in các phần tử từ vị trí `start` đến `end`, bao gồm cả hai đầu.
- Vòng lặp ngoài chọn vị trí bắt đầu `i`. Mỗi lần đổi `i`, đặt `tong = 0`.
- Vòng lặp trong cho vị trí kết thúc `j` chạy từ `i` đến cuối mảng, cộng `a[j]` vào `tong`.
- Nếu `tong == 0`, in đoạn từ `i` đến `j` và gán `found = true`.
- Không dừng sau khi tìm được một đoạn vì đoạn dài hơn có cùng vị trí bắt đầu vẫn có thể có tổng bằng 0.
- Sau khi xét hết, nếu `found` vẫn là `false`, in thông báo không có đoạn phù hợp.

## Định dạng input và output

### Input

1. Dòng đầu: số phần tử `n` (`n >= 0`).
2. Dòng tiếp theo: `n` số nguyên của mảng. Nếu `n = 0`, không nhập thêm phần tử.

### Output

- Mỗi mảng con có tổng bằng 0 được in trên một dòng, các phần tử cách nhau bằng dấu cách.
- Thứ tự in: vị trí bắt đầu từ trái sang phải; với cùng vị trí bắt đầu, vị trí kết thúc tăng dần.
- In tất cả các đoạn, không chỉ các đoạn dài nhất. Không in thêm độ dài hoặc vị trí.
- Nếu không có đoạn phù hợp, gồm cả mảng rỗng, in:

```text
Khong co mang con co tong bang 0!
```

## Ví dụ input/output

### Ví dụ 1: Ví dụ trong đề

Input:

```text
6
4 2 -3 -1 0 4
```

Output:

```text
-3 -1 0 4
0
```

### Ví dụ 2: Nhiều đoạn cùng vị trí bắt đầu

Input:

```text
3
1 -1 0
```

Output:

```text
1 -1
1 -1 0
0
```

### Ví dụ 3: Không có đoạn phù hợp

Input:

```text
3
1 2 3
```

Output:

```text
Khong co mang con co tong bang 0!
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập: nhập `n`, sau đó nhập mảng. Mỗi dòng hiển thị trong cột output là một dòng in riêng.

| Test | Trường hợp | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- |
| 1 | Mảng rỗng | 0 | Rỗng | `Khong co mang con co tong bang 0!` |
| 2 | Một số 0 | 1 | `0` | `0` |
| 3 | Một số dương | 1 | `5` | `Khong co mang con co tong bang 0!` |
| 4 | Một số âm | 1 | `-5` | `Khong co mang con co tong bang 0!` |
| 5 | Hai số đối nhau | 2 | `2 -2` | `2 -2` |
| 6 | Toàn số dương | 3 | `1 2 4` | `Khong co mang con co tong bang 0!` |
| 7 | Toàn số âm | 3 | `-1 -2 -3` | `Khong co mang con co tong bang 0!` |
| 8 | Hai số 0 | 2 | `0 0` | `0`<br>`0 0`<br>`0` |
| 9 | Các đoạn chồng lấn | 3 | `1 -1 1` | `1 -1`<br>`-1 1` |
| 10 | Đoạn nằm giữa | 4 | `5 2 -2 9` | `2 -2` |
| 11 | Đoạn kết thúc ở cuối | 4 | `5 2 -3 1` | `2 -3 1` |
| 12 | Số 0 ở hai đầu | 3 | `0 2 0` | `0`<br>`0` |

Với `{0, 0}`, hai dòng `0` tương ứng với hai đoạn một phần tử ở hai vị trí khác nhau, nên đều phải được in.
