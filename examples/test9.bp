decl b0;                   // 1 == (signed int)MTX
decl b1_FALSE_eq_LOADED;   // FALSE == LOADED
decl b3_FALSE_eq_LOADING;  // FALSE == LOADING
void main() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
b0:=*;
b1_FALSE_eq_LOADED:=*;
b3_FALSE_eq_LOADING:=*;
0: skip; // location only
1: skip; // no predicates changed
2: skip; // no predicates changed
3: skip; // no predicates changed
4: b0 := 0;
5: b2_FALSE_eq_COND := 1;
6: b1_FALSE_eq_LOADED := 1;
7: b3_FALSE_eq_LOADING := 1;
8: skip; // location only
9: skip; // location only
10: if 0 then goto 136; fi;
11: start_thread goto 13;
12: goto 135;
13: skip; // location only
14: atomic_begin;
15: assume(*);
16: b0 := *;
17: atomic_end;
18: assert(b0);
19: skip; // no predicates changed
20: skip; // location only
21: skip; // no predicates changed
22: if * then goto 29; fi;
23: if * then goto 34; fi;
24: if * then goto 38; fi;
25: if * then goto 104; fi;
26: if * then goto 123; fi;
27: if * then goto 133; fi;
28: goto 134;
29: skip; // location only
30: assert(b0);
31: skip; // no predicates changed
32: skip; // location only
33: goto 134;
34: skip; // location only
35: assert(b0);
36: skip; // location only
37: goto 134;
38: if b3_FALSE_eq_LOADING then goto 62; fi;
39: skip; // location only
40: assert(b0);
41: if b3_FALSE_eq_LOADING then goto 55; fi;
42: assert(b1_FALSE_eq_LOADED);
43: b2_FALSE_eq_COND := 1;
44: atomic_begin;
45: assume(!(*));
46: b0 := *;
47: atomic_end;
48: assume(!b2_FALSE_eq_COND);
49: atomic_begin;
50: assume(*);
51: b0 := *;
52: atomic_end;
53: assert(!b2_FALSE_eq_COND);
54: goto 41;
55: atomic_begin;
56: assume(*);
57: b0 := *;
58: atomic_end;
59: assert(b0);
60: skip; // location only
61: goto 103;
62: if !b1_FALSE_eq_LOADED then goto 102; fi;
63: skip; // location only
64: assert(b0);
65: assert(b1_FALSE_eq_LOADED);
66: assert(b3_FALSE_eq_LOADING);
67: b3_FALSE_eq_LOADING := 0;
68: atomic_begin;
69: assume(!(*));
70: b0 := *;
71: atomic_end;
72: atomic_begin;
73: assume(*);
74: b0 := *;
75: atomic_end;
76: assert(b0);
77: skip; // no predicates changed
78: skip; // location only
79: skip; // no predicates changed
80: if * then goto 100; fi;
81: atomic_begin;
82: assume(!(*));
83: b0 := *;
84: atomic_end;
85: atomic_begin;
86: assume(*);
87: b0 := *;
88: atomic_end;
89: assert(b0);
90: skip; // no predicates changed
91: skip; // location only
92: skip; // no predicates changed
93: if !(*) then goto 100; fi;
94: goto 77;
95: skip; // no predicates changed
96: skip; // location only
97: skip; // no predicates changed
98: if * then goto 101; fi;
99: b1_FALSE_eq_LOADED := 0;
100: b3_FALSE_eq_LOADING := 1;
101: b2_FALSE_eq_COND,b2_FALSE_eq_COND$ := b2_FALSE_eq_COND,0;
102: skip; // no predicates changed
103: skip; // location only
104: goto 103;
105: skip; // location only
106: assert(b0);
107: b1_FALSE_eq_LOADED := 1;
108: assert(b0);
109: skip; // location only
110: goto 134;
111: skip; // location only
112: skip; // no predicates changed
113: skip; // location only
114: skip; // no predicates changed
115: if * then goto 117; fi;
116: assert(b0);
117: skip; // no predicates changed
118: skip; // location only
119: skip; // no predicates changed
120: skip; // no predicates changed
121: skip; // location only
122: goto 134;
123: skip; // location only
124: assert(b0);
125: skip; // no predicates changed
126: skip; // location only
127: skip; // no predicates changed
128: if * then goto 130; fi;
129: goto 132;
130: skip; // no predicates changed
131: skip; // location only
132: skip; // no predicates changed
133: if * then goto 131; fi;
134: skip; // no predicates changed
135: skip; // location only
136: skip; // no predicates changed
137: if * then goto 130; fi;
138: skip; // no predicates changed
139: skip; // location only
140: skip; // no predicates changed
141: if * then goto 151; fi;
142: atomic_begin;
143: assume(!(*));
144: b0 := *;
145: atomic_end;
146: atomic_begin;
147: assume(*);
148: b0 := *;
149: atomic_end;
150: assert(b0);
151: goto 134;
152: goto 130;
153: skip; // no predicates changed
154: skip; // location only
155: skip; // no predicates changed
156: if * then goto 132; fi;
157: atomic_begin;
158: assume(!(*));
159: b0 := *;
160: atomic_end;
161: atomic_begin;
162: assume(*);
163: b0 := *;
164: atomic_end;
165: assert(b0);
166: skip; // location only
167: goto 134;
168: skip; // location only
169: assert(b0);
170: skip; // location only
171: assert(b0);
172: atomic_begin;
173: assume(!(*));
174: b0 := *;
175: atomic_end;
176: skip; // location only
177: end_thread;
178: goto 10;
179: skip; // no predicates changed
180: skip; // location only
181: skip;
end
void c$$__CPROVER_initialize() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_contains() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_walk() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_load_wait() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_load() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$nondet() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_unload() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_alloc() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_sync() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$space_map_ref_generate_map() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$thr1() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
void c$$main() begin
decl b2_FALSE_eq_COND;  // LOCAL -- FALSE == COND
end
