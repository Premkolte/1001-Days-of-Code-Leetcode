// For numeric limits.
#include <limits>

// Empty positions value in hash table.
static const uint32_t kNone = 0u;
// Hash table size.
// Number 131'072 is specific number according to tests to this problem...
static const uint32_t kHashTableSize = 131'072u;

#define inl_f static inline __attribute__((always_inline))

// Boost i/o.
auto init = []()
{ ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Solution {
public:
    inl_f uint32_t simpleHash(uint32_t x)
    { return x * (kHashTableSize + 1); }

    inl_f uint32_t uint32NextPO2(uint32_t x)
    { --x;
      x |= x >>  1;
      x |= x >> (1 << 1);
      x |= x >> (1 << 2);
      x |= x >> (1 << 3);
      return x + 1;
    }

    #include <cstdlib>

    bool containsDuplicate(vector<int>& nums)
    { size_t hash_size = nums.size() - 1;
      hash_size |= hash_size >>  1;
      hash_size |= hash_size >> (1 << 1);
      hash_size |= hash_size >> (1 << 2);
      hash_size |= hash_size >> (1 << 3);
      ++hash_size;

      int *hash_table = (int*)calloc(hash_size, sizeof(int));
      int* __restrict end = &hash_table[hash_size];

      for (const auto& cur_num : nums) {
        uint32_t not_zero_num = (cur_num != 0)? cur_num : kNone - 1;

        int *try_place = &hash_table[(cur_num * (kHashTableSize + 1)) & (hash_size - 1)];

        while (!(*try_place == not_zero_num || *try_place == kNone)) {
          if (++try_place == end) {
            try_place = hash_table;
          }
        }

        if (*try_place != 0) {
          free(hash_table);
          return true;
        } else {
          *try_place = not_zero_num;
        }
      }

      free(hash_table);
      return false;
    }
};