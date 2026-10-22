Giải thuật:
Khai báo biến k là biến theo dõi số lượng phần tử 0 có trước phần tử đang xét.
Duyệt từng phần tử trong mảng từ 0 đến (n-1), nếu phần tử thứ i bằng 0 thì xét phần tử thứ i + 1, nếu nó cũng bằng 0 thì cộng thêm 1 cho biến k, ngược lại thì sẽ đổi chỗ phần tử 0 đầu tiên cho phần tử i+1 này. Lúc này ta sẽ có một cụm toàn phần tử 0 trải từ i-k đến i. Cứ thế đến cuối mảng ta sẽ thu được output của đề bài.

## Định dạng input và output

- Dòng đầu: số phần tử `n`.
- Dòng tiếp theo: `n` số nguyên của mảng, cách nhau bằng dấu cách.
- Output: mảng sau khi chuyển tất cả số 0 về cuối, giữ nguyên thứ tự các phần tử khác 0.

## Ví dụ input/output

### Ví dụ 1: Số 0 nằm xen kẽ trong mảng

Input:
```text
9
6 0 8 2 3 0 4 0 1
```

Output:
```text
6 8 2 3 4 1 0 0 0
```

### Ví dụ 2: Nhiều số 0 liên tiếp ở đầu mảng

Input:
```text
4
0 0 1 2
```

Output:
```text
1 2 0 0
```

## Testcase

Mỗi hàng là một lần chạy độc lập: nhập `n` ở dòng đầu và mảng ở dòng tiếp theo.

| Test | Trường hợp | n | Mảng đầu vào | Output mong đợi |
| --- | --- | --- | --- | --- |
| 1 | Không có số 0 | 4 | `1 2 3 4` | `1 2 3 4` |
| 2 | Toàn số 0 | 4 | `0 0 0 0` | `0 0 0 0` |
| 3 | Một phần tử bằng 0 | 1 | `0` | `0` |
| 4 | Một phần tử khác 0 | 1 | `7` | `7` |
| 5 | Số 0 và số khác 0 xen kẽ | 6 | `0 1 0 2 0 3` | `1 2 3 0 0 0` |
| 6 | Số 0 đã nằm cuối mảng | 4 | `1 2 0 0` | `1 2 0 0` |
| 7 | Có số âm | 6 | `-2 0 -5 3 0 -1` | `-2 -5 3 -1 0 0` |
| 8 | Nhiều cụm số 0 liên tiếp | 7 | `0 0 4 0 0 5 0` | `4 5 0 0 0 0 0` |
