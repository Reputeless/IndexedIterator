# IndexedIterator
Header-only Indexed iterator library for modern C++

## Examples

```cpp
std::vector<int> v = { 100, 200, 300, 400, 500 };

for (auto [i, n] : Indexed(v))
{
	std::cout << i << ": " << n << "\n"; 
}  
```
```
0: 100
1: 200
2: 300
3: 400
4: 500
```

------

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

------

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

