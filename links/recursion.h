#pragma once
#include "utils.h"
#include "lists.h"

int recur_max(const std::vector<int>& arr, size_t left, size_t right);

int lin_max(const std::vector<int>& arr);

void recur_push_back(sll::list<int>& list, size_t depth);

void recur_pop_front(sll::list<int>& list);

void recur_queue();