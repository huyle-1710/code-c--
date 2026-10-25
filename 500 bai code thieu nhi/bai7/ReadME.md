Giải thuât: 
Ý tưởng sẽ là xét độ dài từ lớn xuống nhỏ, xét n = size của mảng đến n = 1. Trong đó ta sẽ tính tổng của từng n phần tử liên tiếp trong mảng rồi so sánh với target.

## Đề bài

Cho một mảng số nguyên và giá trị `target`, tìm mảng con liên tiếp dài nhất có tổng bằng `target`.

## Định dạng input và output

### Input

1. Dòng đầu: giá trị `target`.
2. Dòng thứ hai: số phần tử `n` (`n >= 0`).
3. Dòng tiếp theo: `n` số nguyên của mảng. Nếu `n = 0`, không nhập thêm phần tử.

### Output

- Nếu tìm thấy: in **tất cả các mảng con liên tiếp dài nhất** có tổng bằng `target`, mỗi đoạn trên một dòng, theo thứ tự vị trí bắt đầu từ trái sang phải.
- Sau khi in hết các đoạn, in **độ dài chung một lần** trên dòng cuối.
- Hai đoạn ở vị trí khác nhau vẫn được in riêng, kể cả khi có cùng dãy giá trị. Các đoạn có thể chồng lấn.
- Không in các đoạn ngắn hơn, dù chúng cũng có tổng bằng `target`.
- Chỉ xét đoạn không rỗng. Nếu không tìm thấy hoặc mảng rỗng, chỉ in:

```text
Khong ton tai mang con co tong bang target!
```

## Ví dụ input/output

### Ví dụ 1: Ví dụ trong đề

Input:

```text
8
9
5 6 -5 5 3 5 3 -2 0
```

Output:

```text
-5 5 3 5
4
```

### Ví dụ 2: In tất cả các đoạn dài nhất

Input:

```text
3
5
1 2 1 2 9
```

Output:

```text
1 2
2 1
1 2
2
```

Ba đoạn có tổng bằng 3 và độ dài 2 bắt đầu tại các vị trí 0, 1 và 2. Đoạn `1 2` xuất hiện hai lần ở hai vị trí khác nhau nên được in hai lần. Dòng cuối `2` là độ dài chung.

### Ví dụ 3: Cả mảng có tổng bằng target

Input:

```text
6
3
1 2 3
```

Output:

```text
1 2 3
3
```

### Ví dụ 4: Không có mảng con phù hợp

Input:

```text
10
3
1 2 3
```

Output:

```text
Khong ton tai mang con co tong bang target!
```

## Testcase bổ sung

Mỗi hàng là một lần chạy độc lập. Nhập theo thứ tự `target`, `n`, rồi mảng. Trong cột output, mỗi dấu xuống dòng hiển thị là một dòng in riêng; số ở dòng cuối là độ dài chung khi tìm thấy.

| Test | Trường hợp | target | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- | --- |
| 1 | Một phần tử khớp target | 5 | 1 | `5` | `5`<br>`1` |
| 2 | Một phần tử không khớp | 3 | 1 | `5` | `Khong ton tai mang con co tong bang target!` |
| 3 | Toàn số 0 | 0 | 4 | `0 0 0 0` | `0 0 0 0`<br>`4` |
| 4 | Số âm và target âm | -5 | 4 | `-2 -3 4 -1` | `-2 -3`<br>`2` |
| 5 | Đoạn dài nhất ở đầu | 3 | 3 | `1 2 10` | `1 2`<br>`2` |
| 6 | Đoạn dài nhất ở cuối | 5 | 3 | `10 2 3` | `2 3`<br>`2` |
| 7 | Đoạn dài nhất nằm giữa | 5 | 4 | `10 2 3 20` | `2 3`<br>`2` |
| 8 | Nhiều đoạn dài nhất chồng lấn | 3 | 4 | `1 2 1 2` | `1 2`<br>`2 1`<br>`1 2`<br>`2` |
| 9 | Tổng bằng 0 | 0 | 4 | `1 -1 2 -2` | `1 -1 2 -2`<br>`4` |
| 10 | Mảng rỗng | 0 | 0 | Rỗng | `Khong ton tai mang con co tong bang target!` |
| 11 | Toàn số âm | -6 | 4 | `-1 -2 -3 -4` | `-1 -2 -3`<br>`3` |
| 12 | Số 0 kéo dài đoạn hợp lệ | 3 | 5 | `0 1 2 0 8` | `0 1 2 0`<br>`4` |
| 13 | Nhiều đoạn dài nhất không chồng lấn | 3 | 5 | `1 2 10 2 1` | `1 2`<br>`2 1`<br>`2` |

## Độ phức tạp và kiểm tra

- Code hiện tại thử độ dài từ lớn xuống nhỏ và trượt cửa sổ với mỗi độ dài, có thời gian `O(n²)`.
- Hàm `chiamang` nhận vector theo giá trị nên tạo bản sao mảng, dùng thêm `O(n)` bộ nhớ.
- Các phép tính tổng hiện dùng `int`; dữ liệu cần bảo đảm các tổng trung gian không bị tràn số.
- Bốn ví dụ và 13 testcase trên đã được chạy với `mangcondainhatcotongbangtarget.cpp` và đối chiếu với cách xét tất cả mảng con; tất cả đều đúng.
