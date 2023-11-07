#pragma once
#include "misc.h"

uint64_t hash(std::string val);

template<typename T>
class map
{
private:

	class cell
	{
	public:
		T val;
		std::string key;

		cell()
		{
			this->key = "\0";
		}
	};

	size_t _capacity;
	size_t _occupied;

	std::vector<cell> _table;

	uint16_t _get_percentage()
	{
		return this->_occupied * 100 / this->_capacity;
	}

	void _extend(size_t size)
	{
		this->_capacity = size;
		this->_occupied = 0;
		std::vector<cell> old_table = this->_table;
		this->_table.clear();
		this->_table = std::vector<cell>(this->_capacity);

		for (cell _cell : old_table)
			if (_cell.key != "\0" and _cell.key != "\1")
				this->insert(_cell.key, _cell.val);
	}

	void _check_capacity()
	{
		if (_get_percentage() > 75)
			this->_extend(this->_capacity * 2);
	}

	size_t _get_index(std::string key)
	{
		return hash(key) % this->_capacity;
	}

public:
	map()
	{
		this->_capacity = 16;
		this->_occupied = 0;
		this->_table = std::vector<cell>(this->_capacity);
	}

	void remove(std::string key)
	{
		size_t offset = 0;
		size_t index = this->_get_index(key);
		cell *tmp = &this->_table[index];
		for (; tmp->key != key and tmp->key != "\0" and index + offset + 1 < this->_capacity; tmp = &this->_table[index + ++offset]) {}
		if (tmp->key == "\0" or index + offset >= this->_capacity)
			return;
		tmp->val = T();
		tmp->key = "\1";
		this->_occupied--;
	}

	void insert(std::string key, T val)
	{
		size_t offset = 0;
		size_t index = this->_get_index(key);
		cell* tmp = &this->_table[index];
		for (; tmp->key != "\0" and tmp->key != "\1" and index + offset + 1 < this->_capacity; tmp = &this->_table[index + ++offset]) {}

		if (index + offset + 1 >= this->_capacity)
		{
			this->_extend(this->_capacity * 2);
			this->insert(key, val);
			return;
		}

		tmp->val = val;
		tmp->key = key;

		this->_occupied++;
		this->_check_capacity();
	}

	T& operator[](std::string key)
	{
		size_t offset = 0;
		size_t index = this->_get_index(key);
		cell* tmp = &this->_table[index];
		for (; tmp->key != key and tmp->key != "\0" and index + offset + 1 < this->_capacity; tmp = &this->_table[index + ++offset]) {}
		if (tmp->key == "\0" or index + offset >= this->_capacity)
			throw std::invalid_argument("Key not found.");
		return tmp->val;
	}
};

