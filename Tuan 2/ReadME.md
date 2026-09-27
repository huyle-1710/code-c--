## Thuật toán: Quy hoạch động - Bài toán Cái túi không giới hạn (Unbounded Knapsack)

Chương trình sử dụng phương pháp **Quy hoạch động (Dynamic Programming)** để giải quyết bài toán tối ưu hóa: Tìm tổ hợp các mặt hàng sao cho tổng lượng calo đạt mức tối đa với giới hạn khối lượng cho trước (sức chứa = 1000), trong đó mỗi mặt hàng có thể được chọn với số lượng không giới hạn.

### 1. Cấu trúc dữ liệu lưu trữ
- Mảng `Tongcalo[1001]`: Lưu trữ tổng lượng calo lớn nhất có thể đạt được tại mỗi mức khối lượng $i$ (từ 0 đến 1000). Toàn bộ được khởi tạo giá trị ban đầu là `0`.
- Mảng `toiuuthucan[1001]`: Lưu trữ vết của mặt hàng (đối tượng `Mathang`) cuối cùng được thêm vào túi tại mức khối lượng $i$. Khởi tạo mặc định là đối tượng rỗng (Tên: "Khong co mat hang").

### 2. Quá trình tính toán (Bottom-up)
- **Bước 1:** Duyệt qua các mức khối lượng $i$ tăng dần từ `0` đến `1000`.
- **Bước 2:** Tại mỗi mức khối lượng $i$, duyệt qua toàn bộ danh sách các mặt hàng hiện có.
- **Bước 3:** Kiểm tra xem mặt hàng đang xét (gọi là $j$) có thể nhét vừa vào khối lượng $i$ không (tức là `khối_lượng_j <= i`).
- **Bước 4:** Nếu vừa, ta thử giả định bỏ mặt hàng $j$ vào. Lượng calo đạt được sẽ bằng lượng calo của mặt hàng $j$ cộng với mức calo tối ưu tại khoảng không gian còn dư: `calo_giả_định = Tongcalo[i - khối_lượng_j] + calo_j`.
- **Bước 5:** So sánh `calo_giả_định` với `Tongcalo[i]` hiện tại. Nếu lớn hơn, ta cập nhật `Tongcalo[i] = calo_giả_định` và ghi nhớ mặt hàng vừa chọn vào mảng truy vết `toiuuthucan[i] = mặt_hàng_j`.

*Sau khi vòng lặp kết thúc, `Tongcalo[1000]` chính là lượng calo tối đa cần tìm.*

### 3. Quá trình truy vết ngược (Backtracking)
Để biết được đã chọn những mặt hàng nào, thuật toán tiến hành truy ngược lại từ mảng `toiuuthucan`:
- Bắt đầu từ giới hạn lớn nhất $i = 1000$.
- Nếu `toiuuthucan[i]` khác rỗng, nghĩa là có mặt hàng được chọn tại đây:
  - Thêm mặt hàng đó vào danh sách `truyvet`.
  - Trừ khối lượng của không gian đi một lượng đúng bằng khối lượng món hàng vừa lấy: `i = i - khối_lượng_món_hàng`.
- Lặp lại quá trình trên cho đến khi không còn mặt hàng nào (`toiuuthucan[i] == "Khong co mat hang"`) hoặc $i = 0$.

### 4. Thống kê kết quả
Duyệt qua danh sách các mặt hàng ban đầu, đối chiếu (so khớp) với danh sách `truyvet` thu được ở Bước 3 để đếm số lần xuất hiện của từng mặt hàng và in ra màn hình.

---
### Độ phức tạp thuật toán (Complexity)
- **Độ phức tạp thời gian (Time Complexity):** $O(M \times N)$
  *(Trong đó $M = 1000$ là sức chứa tối đa của túi, $N$ là số lượng mặt hàng)*
- **Độ phức tạp không gian (Space Complexity):** $O(M)$ 
  *(Do sử dụng mảng 1 chiều kích thước $M+1$ để lưu trữ trạng thái DP)*
