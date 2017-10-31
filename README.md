# siv::IndexedIterator
**siv::IndexedIterator** is a header-only indexed iterator library for modern C++.

## Examples

### std::vector

```cpp
std::vector<int> v = { 0, 100, 200, 300, 400, 500 };

for (auto [i, n] : Indexed(v))
{
	std::cout << i << ": " << n << "\n"; 
}  
```
```
0: 0
1: 100
2: 200
3: 300
4: 400
5: 500
```

### std::string

```cpp
std::string s = "Hello, world!";

for (auto [i, ch] : Indexed(v))
{
	std::cout << i << ": " << ch << "\n"; 
}
```
```
0: H
1: e
2: l
3: l
4: o
5: ,
6:  
7: w
8: o
9: r
10: l
11: d
12: !
```

### std::map

```cpp
std::map<std::string, std::string> m = { { "aaa", "AAA" }, { "bbb", "BBB" }, { "ccc", "CCC" } };

for (auto [i, p] : Indexed(m))
{
	std::cout << i << ": " << p.first << ", " << p.second << "\n"; 
} 
```
```
0: aaa, AAA
1: bbb, BBB
2: ccc, CCC
```

## License
siv::IndexedIterator is distributed under the MIT license.

