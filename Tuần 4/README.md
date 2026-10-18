# Tuần 3 — Giải thuật Tháp Hà Nội

Tài liệu giải thích từng bước theo hai file code hiện tại:

- `Thaphnoidequy.cpp`: giải bằng đệ quy.
- `Thaphanoikhudequy.cpp`: giải bằng vòng lặp, khử đệ quy.

## 1. Bài toán, input và output

Có ba cọc A, B, C. Ban đầu, `n` đĩa nằm trên cọc A, đĩa lớn ở dưới và đĩa nhỏ ở trên. Cần chuyển toàn bộ đĩa từ A sang B, dùng C làm cọc trung gian.

Quy tắc:

1. Mỗi bước chỉ chuyển một đĩa.
2. Chỉ lấy đĩa trên cùng của một cọc.
3. Không đặt đĩa lớn lên đĩa nhỏ.

**Input:** một số nguyên `n`, là số đĩa. Ví dụ:

```text
3
```

**Output:** các đĩa trên cọc B sau khi chuyển xong, theo thứ tự từ đáy lên đỉnh. Với input trên:

```text
3 2 1
```

Hai chương trình chỉ in trạng thái cuối của B; không in từng bước chuyển và không in số bước. Code hiện tại in thêm một dấu cách sau đĩa cuối cùng và không xuống dòng.

## 2. Cấu trúc dữ liệu và khởi tạo

Cả hai chương trình dùng ba `vector<int>` để lưu ba cọc:

- Số `1` là đĩa nhỏ nhất; số `n` là đĩa lớn nhất.
- Phần tử đầu vector nằm ở đáy cọc.
- Phần tử cuối vector nằm ở đỉnh cọc.
- `back()` lấy đĩa trên cùng; `push_back()` đặt đĩa lên đỉnh; `pop_back()` bỏ đĩa khỏi đỉnh.

Các bước trong `main`:

1. Đọc `n` bằng `cin >> n`.
2. Tạo ba vector A, B, C rỗng.
3. Duyệt `i` từ `n` xuống `1`, thêm `i` vào A.
4. Gọi hàm giải Tháp Hà Nội.
5. Duyệt B từ đầu đến cuối và in các đĩa.

Ví dụ `n = 3`, trạng thái ban đầu là:

```text
A = [3, 2, 1]
B = []
C = []
```

## 3. Giải thuật đệ quy — `Thaphnoidequy.cpp`

### 3.1. Ý nghĩa hàm

```cpp
thaphanoi(A, B, C, n)
```

Chuyển `n` đĩa từ tham số thứ nhất sang tham số thứ hai, dùng tham số thứ ba làm trung gian. Các vector được truyền bằng tham chiếu nên hàm thay đổi trực tiếp trạng thái cọc.

### 3.2. Các bước xử lý

**Bước 1: Nếu `n < 1`, kết thúc hàm.**

Không có đĩa cần chuyển nên không thực hiện thao tác nào.

**Bước 2: Nếu `n == 1`, chuyển đĩa trên cùng từ A sang B.**

```cpp
B.push_back(A.back());
A.pop_back();
```

**Bước 3: Nếu `n > 1`, chia thành ba việc theo đúng thứ tự trong code.**

1. Chuyển `n - 1` đĩa trên cùng từ A sang C, dùng B làm trung gian:

   ```cpp
   thaphanoi(A, C, B, n - 1);
   ```

2. Chuyển đĩa còn lại trên A sang B. Đây là đĩa lớn nhất trong nhóm `n` đĩa đang xét:

   ```cpp
   thaphanoi(A, B, C, 1);
   ```

3. Chuyển `n - 1` đĩa từ C sang B, dùng A làm trung gian:

   ```cpp
   thaphanoi(C, B, A, n - 1);
   ```

### 3.3. Mã giả

```text
THAP_HANOI(A, B, C, n):
    Nếu n < 1: kết thúc
    Nếu n == 1:
        Đặt đĩa trên cùng của A lên B
        Bỏ đĩa trên cùng khỏi A
    Ngược lại:
        THAP_HANOI(A, C, B, n - 1)
        THAP_HANOI(A, B, C, 1)
        THAP_HANOI(C, B, A, n - 1)
```

### 3.4. Vì sao đúng?

Một đĩa được chuyển trực tiếp. Với `n > 1`, chuyển nhóm `n - 1` đĩa nhỏ sang C để giải phóng đĩa lớn nhất; chuyển đĩa lớn nhất sang B; rồi chuyển nhóm đĩa nhỏ từ C lên trên đĩa lớn ở B. Nếu lời gọi cho `n - 1` đĩa thực hiện đúng thì lời gọi cho `n` đĩa cũng đúng.

Số bước thỏa `T(0) = 0`, `T(n) = 2T(n - 1) + 1`, nên `T(n) = 2^n - 1`. Đây cũng là số bước tối thiểu: trước khi chuyển đĩa lớn nhất, phải chuyển hết nhóm đĩa nhỏ khỏi cọc nguồn; sau đó phải đưa nhóm ấy lên cọc đích.

## 4. Giải thuật khử đệ quy — `Thaphanoikhudequy.cpp`

### 4.1. Chọn cách gọi hàm theo tính chẵn/lẻ

Trong `main`:

```cpp
if(n % 2 == 1) thaphanoi(A, B, C, n);
else thaphanoi(A, C, B, n);
```

- `n` lẻ: giữ thứ tự tham số A, B, C.
- `n` chẵn: truyền C vào tham số B và truyền B vào tham số C.

Việc đổi thứ tự tham số không hoán đổi dữ liệu hai vector. Nó đổi vai trò hai cọc bên trong hàm để chu kỳ di chuyển phù hợp với số đĩa. Cọc đích cuối cùng vẫn là **B trong `main`**, cũng là vector được in ra.

### 4.2. Tính số bước

```cpp
int buoc = pow(2, n) - 1;
```

Thuật toán thực hiện `2^n - 1` bước, với biến `i` chạy từ `1` đến `buoc`.

### 4.3. Chọn cặp cọc tại mỗi bước

Tên A, B, C trong bảng sau là **tham số bên trong hàm**:

| Điều kiện | Cặp cọc xử lý |
| --- | --- |
| `i % 3 == 1` | A và B |
| `i % 3 == 2` | A và C |
| `i % 3 == 0` | B và C |

Chu kỳ lặp lại sau mỗi ba bước. Xét theo các vector trong `main`:

| Tính chẵn/lẻ của `n` | Cặp thứ nhất | Cặp thứ hai | Cặp thứ ba |
| --- | --- | --- | --- |
| Lẻ | A ↔ B | A ↔ C | B ↔ C |
| Chẵn | A ↔ C | A ↔ B | C ↔ B |

### 4.4. Chọn hướng chuyển hợp lệ trong cặp

Ví dụ với cặp A và B, code kiểm tra:

```cpp
if(B.empty() || (!A.empty() && A.back() < B.back()))
```

1. Nếu B rỗng, chuyển đĩa trên cùng của A sang B.
2. Nếu cả hai có đĩa và đĩa trên A nhỏ hơn đĩa trên B, chuyển A sang B.
3. Trường hợp còn lại, chuyển đĩa trên cùng của B sang A.

Hai cặp A–C và B–C áp dụng cùng nguyên tắc: chuyển đĩa nhỏ lên đĩa lớn hoặc lên cọc rỗng. Với trạng thái khởi tạo đúng và chu kỳ của thuật toán, cặp được xét không đồng thời rỗng khi có bước cần thực hiện.

### 4.5. Mã giả

```text
Trong main:
    Khởi tạo A = [n, n - 1, ..., 1], B = [], C = []
    Nếu n lẻ: gọi LAP(A, B, C, n)
    Nếu n chẵn: gọi LAP(A, C, B, n)
    In B từ đáy lên đỉnh

LAP(A, B, C, n):
    buoc = 2^n - 1
    Với i từ 1 đến buoc:
        Nếu i % 3 == 1: chuyển hợp lệ giữa A và B
        Nếu i % 3 == 2: chuyển hợp lệ giữa A và C
        Nếu i % 3 == 0: chuyển hợp lệ giữa B và C
```

### 4.6. Vì sao cần đổi vai trò B/C khi `n` chẵn?

Để kết thúc trên B, đĩa nhỏ nhất phải đi theo chu kỳ A → B → C → A khi `n` lẻ, và A → C → B → A khi `n` chẵn. Các bước xen kẽ di chuyển hợp lệ giữa hai cọc còn lại. Việc đổi tham số B/C tạo đúng chu kỳ này; sau `2^n - 1` bước, toàn bộ đĩa nằm trên B trong `main`.

Ví dụ `n = 2`, hàm được gọi bằng `thaphanoi(A, C, B, 2)`:

1. Chuyển đĩa 1 từ A sang C.
2. Chuyển đĩa 2 từ A sang B.
3. Chuyển đĩa 1 từ C sang B.

Kết quả `B = [2, 1]`. Nếu giữ lời gọi `thaphanoi(A, B, C, 2)` thì các đĩa sẽ kết thúc trên C, sai cọc đích của chương trình.

## 5. Minh họa từng bước với `n = 3`

Cả hai chương trình thực hiện cùng dãy chuyển dưới đây. Các vector trong bảng được ghi từ đáy lên đỉnh. Bảng là minh họa giải thuật, không phải nội dung chương trình in ra.

| Bước | Đĩa và hướng chuyển | A | B | C |
| --- | --- | --- | --- | --- |
| 0 | Khởi tạo | `[3, 2, 1]` | `[]` | `[]` |
| 1 | Đĩa 1: A → B | `[3, 2]` | `[1]` | `[]` |
| 2 | Đĩa 2: A → C | `[3]` | `[1]` | `[2]` |
| 3 | Đĩa 1: B → C | `[3]` | `[]` | `[2, 1]` |
| 4 | Đĩa 3: A → B | `[]` | `[3]` | `[2, 1]` |
| 5 | Đĩa 1: C → A | `[1]` | `[3]` | `[2]` |
| 6 | Đĩa 2: C → B | `[1]` | `[3, 2]` | `[]` |
| 7 | Đĩa 1: A → B | `[]` | `[3, 2, 1]` | `[]` |

## 6. Input/output để kiểm tra

Chạy từng chương trình riêng với mỗi input dưới đây. Bỏ qua dấu cách cuối khi đối chiếu output.

| Input | Output của cả hai chương trình | Số bước theo giải thuật |
| --- | --- | --- |
| `0` | Không in ký tự nào | 0 |
| `1` | `1` | 1 |
| `2` | `2 1` | 3 |
| `3` | `3 2 1` | 7 |
| `4` | `4 3 2 1` | 15 |
| `5` | `5 4 3 2 1` | 31 |
| `10` | `10 9 8 7 6 5 4 3 2 1` | 1023 |

Ví dụ kiểm tra số đĩa chẵn:

**Input:**

```text
4
```

**Output:**

```text
4 3 2 1
```

Biên dịch và chạy từ thư mục `Tuan 3`:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic Thaphnoidequy.cpp -o /tmp/thaphanoi_dequy
g++ -std=c++17 -Wall -Wextra -Wpedantic Thaphanoikhudequy.cpp -o /tmp/thaphanoi_khudequy
printf '4\n' | /tmp/thaphanoi_dequy
printf '\n'
printf '4\n' | /tmp/thaphanoi_khudequy
printf '\n'
```

### Kết quả kiểm tra thực tế

Đã biên dịch và chạy cả hai file với từng giá trị `n = 0..12`. Tất cả đều có output đúng. Khi chèn kiểm tra sau mỗi lần chuyển đĩa vào bản kiểm thử tạm thời, cả hai đều giữ đúng thứ tự đĩa trên mỗi cọc, giữ đủ các đĩa `1..n`, thực hiện đúng `2^n - 1` bước và kết thúc với A, C rỗng, B chứa `[n, ..., 1]`. Hai file nguồn gốc không bị thay đổi.

## 7. Đánh giá logic và giới hạn của code hiện tại

**Logic chính của hai chương trình đúng với input là số đĩa không âm, đủ nhỏ để hoàn tất và không tràn số.** Bản đệ quy chia đúng ba công việc; bản khử đệ quy chọn đúng cặp cọc, hướng chuyển và xử lý đúng tính chẵn/lẻ.

Các điểm cần lưu ý khi sử dụng đúng code hiện tại:

1. Chưa kiểm tra việc đọc `cin` có thành công hay không và chưa từ chối số đĩa âm. Không dùng input âm hoặc không phải số nguyên làm ca kiểm tra hợp lệ.
2. Bản khử đệ quy dùng `pow`, trả về số thực, rồi gán số bước vào `int`. Trên môi trường kiểm tra có `int` 32 bit, `n = 32` làm kết quả vượt miền biểu diễn của `int`. Với `n = 31`, số bước còn vừa `int`, nhưng `i++` sau bước cuối sẽ tràn số. Vì vậy không dùng `n >= 31` với bản này.
3. Số bước tăng theo hàm mũ. Dù chưa tràn số, `n` lớn vẫn chạy rất lâu; nên dùng các input nhỏ trong bảng để kiểm tra.
4. Cả hai file có cảnh báo khi so sánh chỉ số `int` với `B.size()` thuộc kiểu không dấu. Cảnh báo này không làm sai kết quả với các ca nhỏ đã kiểm tra.

Tài liệu mô tả nguyên trạng code; các giới hạn trên chưa được sửa trong hai file nguồn.

## 8. Độ phức tạp

| Phương pháp | Thời gian | Bộ nhớ |
| --- | --- | --- |
| Đệ quy | `O(2^n)` | `O(n)` để lưu đĩa và `O(n)` ngăn xếp đệ quy; tổng `O(n)` |
| Khử đệ quy | `O(2^n)` | `O(n)` để lưu đĩa; biến điều khiển vòng lặp dùng `O(1)` |

Mỗi phương pháp chuyển đĩa `2^n - 1` lần và in `n` đĩa khi kết thúc.
