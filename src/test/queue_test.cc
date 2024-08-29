#include "test_utils.h"

TEST(Queue, Constructor_Default) {
  s21::queue<int> our_queue;
  std::queue<int> std_queue;
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(Queue, Constructor_List) {
  s21::queue<int> our_queue = {1, 2, 3};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  EXPECT_EQ(our_queue.front(), std_queue.front());
  EXPECT_EQ(our_queue.back(), std_queue.back());
}

TEST(Queue, Operator_Copy) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = our_queue_int;
  std_queue_empty = std_queue_int;
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, Constructor_Move) {
  s21::queue<int> our_queue = {1, 2, 3};
  s21::queue<int> our_move(std::move(our_queue));
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(2);
  std_queue.push(3);
  std::queue<int> std_move(std::move(std_queue));
  EXPECT_EQ(our_move.front(), std_move.front());
  EXPECT_EQ(our_move.back(), std_move.back());
  EXPECT_EQ(our_queue.empty(), std_queue.empty());
}

TEST(Queue, Operator_Move) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty = std::move(our_queue_int);
  std_queue_empty = std::move(std_queue_int);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, FrontAndBack) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<double> our_queue_double = {1.1f, 2.1f, 3.1f};
  std::queue<double> std_queue_double;
  std_queue_double.push(1.1f);
  std_queue_double.push(2.1f);
  std_queue_double.push(3.1f);
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_double.front(), std_queue_double.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
  EXPECT_EQ(our_queue_double.back(), std_queue_double.back());
}

TEST(Queue, Empty) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.empty(), std_queue_empty.empty());
}

TEST(Queue, Size) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.size(), std_queue_int.size());
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  EXPECT_EQ(our_queue_empty.size(), std_queue_empty.size());
}

TEST(Queue, Push) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
}

TEST(Queue, Pop) {
  s21::queue<int> our_queue_int;
  our_queue_int.push(1);
  our_queue_int.push(2);
  our_queue_int.push(3);
  our_queue_int.pop();
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.front(), std_queue_int.front());
  EXPECT_EQ(our_queue_int.back(), std_queue_int.back());
  our_queue_int.pop();
  our_queue_int.pop();
  std_queue_int.pop();
  std_queue_int.pop();
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}

TEST(Queue, Swap) {
  s21::queue<int> our_queue_int = {1, 2, 3};
  std::queue<int> std_queue_int;
  std_queue_int.push(1);
  std_queue_int.push(2);
  std_queue_int.push(3);
  s21::queue<int> our_queue_empty;
  std::queue<int> std_queue_empty;
  our_queue_empty.swap(our_queue_int);
  std_queue_empty.swap(std_queue_int);
  EXPECT_EQ(our_queue_empty.front(), std_queue_empty.front());
  EXPECT_EQ(our_queue_empty.back(), std_queue_empty.back());
  EXPECT_EQ(our_queue_int.empty(), std_queue_int.empty());
}
