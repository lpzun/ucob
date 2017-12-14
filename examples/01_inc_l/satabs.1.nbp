void main() begin
0: skip; // location only
1: skip; // no predicates changed
2: skip; // no predicates changed
3: skip; // no predicates changed
4: skip; // no predicates changed
5: skip; // no predicates changed
6: skip; // location only
7: skip; // location only
8: if 0 then goto 37; fi;
9: start_thread goto 11;
10: goto 36;
11: skip; // location only
12: skip; // no predicates changed
13: skip; // no predicates changed
14: atomic_begin;
15: assume(*);
16: skip; // no predicates changed
17: atomic_end;
18: if !(*) then goto 25; fi;
19: atomic_begin;
20: assume(*);
21: skip; // no predicates changed
22: atomic_end;
23: skip; // no predicates changed
24: goto 34;
25: skip; // no predicates changed
26: skip; // no predicates changed
27: atomic_begin;
28: assume(*);
29: skip; // no predicates changed
30: atomic_end;
31: assert(!(*));
32: skip; // no predicates changed
33: goto 34;
34: skip; // location only
35: end_thread;
36: goto 8;
37: skip; // no predicates changed
38: skip; // location only
39: skip;
end
void c$$__CPROVER_initialize() begin
end
void c$$thr1() begin
end
void c$$main() begin
end
