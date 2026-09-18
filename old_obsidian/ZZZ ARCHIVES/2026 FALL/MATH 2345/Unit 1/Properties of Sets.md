# Procedural Versions of Set Defs
Let $X$ and $Y$ be subsets of a universal set $U$ and suppose x and y are elements of $U$
1. $x \in X \cup Y \Leftrightarrow x \in X \text{  or  } x \in Y$
2. $x\in X∩Y \Leftrightarrow x\in X \text{  and  } x\in Y$
3. $x \in X-Y \Leftrightarrow x\in X \text{  and  } x \not\in Y$
4. $x\in X^c \Leftrightarrow x\not\in X$
5. $(x,y)\in X * Y \Leftrightarrow x\in X \text{  and  } y \in Y$

# Proof of a distributive Law
Prove that for all sets $A$, $B$, and $C$ $$A\cup (B∩C) = (A\cup B)∩(A\cup C)$$
$x\in A\cup (B∩C) \Rightarrow x \in A or x \in B∩C$
If $x\in A$ then $x\in A\cup B$ and $x \in A \cup B$ 
Now if $x \in B∩C \Rightarrow x\in B$ and $x\in C$ then $x \in A\cup B$ and $x\in A \cup C$

# Proof of a De Morgan's Law for Sets
Prove that for all sets $A$ and $B$, $C$ $$(A\cup B)^c = A^c ∩ B^c$$
First, $x\in(A\cup B)^c \Rightarrow x\not\in A\cup B$ so $x\not\in A$ and $x\not\in B$ which can be written as $x\not\in A\cup B$, so we know that X is not in $A$, its in its complement $A^C$, and the same thing for B, thus $x\in A^c$ and $x\in B^c$ or $x\in (A\cup B)^C$

