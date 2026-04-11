# Report 1 Page – FIT4012 Lab 1

## 1. Mục tiêu
Tóm tắt ngắn gọn mục tiêu của bài lab.

## 2. Cách làm
- Đọc hiểu chương trình entropy mẫu.
- Bổ sung hàm tính redundancy.
- Hoàn thiện hàm mod_inverse().
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Entropy và redundancy
| Input | Entropy | Redundancy | Nhận xét |
|---|---:|---:|---|
| aaaa | 0.0 | 8.0 | Entropy thấp, redundancy cao |
| abcd | 2.0 | 6.0 | Entropy cao hơn `aaaa` |
| hello world | 2.845 | 5.155 | Entropy và redundancy hợp lệ |

### 3.2 Modulo inverse
| a | m | Kết quả mong đợi | Kết quả chương trình |
|---:|---:|---|---|
| 3 | 7 | 5 | 5 |
| 10 | 17 | 12 | 12 |
| 6 | 9 | Không tồn tại | Không tồn tại |

## 4. Kết luận
- Em đã hiểu rõ hơn về entropy và cách tính toán.
- Em đã học được cách triển khai thuật toán Euclid mở rộng để tìm nghịch đảo modulo.
- Việc kiểm thử và ghi log giúp em phát hiện và sửa lỗi hiệu quả.
