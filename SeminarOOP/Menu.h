#pragma once
#include "SelectionSort.h"
#include "InterchangeSort.h"
#include "InsertionSort.h"
#include "BinaryInsertionSort.h"
#include "BubbleSort.h"
#include "ShakerSort.h"
#include "ShellSort.h"
#include "RadixSort.h"
#include "CountingSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "Coordinate.h"
#include <string>
#include <thread>
void check(char&); // in hướng dẫn cho người dùng và kiểm tra người dùng muốn tiếp tục hay thoát

void selection(int); // xử lý các lựa chọn thuật toán của người dùng

void infor(); // thông tin nhóm thực hiện
 
void command(); // điều khiển chương trình

void box(int x, int y, int w, int h,int t_color,int b_color, string text);

void n_box();
