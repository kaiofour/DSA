# Hash Tables notes

open hashing - closed adressing
closed hasing - open hashing

linear hashing/mapping?

Double hashing: Use a secondary hash function to probe the table in a different sequence.

Quadratic probing: Use a quadratic function to probe the table, such as index = (index + i^2) % table_size.

Rehashing: Rehash the key and probe the table again if a collision occurs.

Keep in mind that linear probing can suffer from clustering, where a group of keys hash to the same slot, leading to poor performance. Other collision resolution techniques, like chaining or open addressing, can be more efficient in certain scenarios.

