# sol for math

## P1661A

 长度为$n$的数列$A$,$B$，通过$swap(a_i,b_i)$使$\sum\limits_{i=1}^{n - 1}{\left(|a_i - a_{i+1}| + |b_i - b_{i+1}|\right)}$最小

结论：交换看似有后效性，实则没有。因为对于$swap(a_i,b_i)$，可以将i后面的所有元素交换规避后效.所以可以直接贪心ans = $\sum\limits_{i=2}^{n}min{(|a_i - a_{i-1}| + |b_i - b_{i-1}|,|b_i - a_{i-1}| + |a_i - b_{i-1}|)}$
