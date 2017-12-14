//http://www.ibm.com/developerworks/java/library/j-jtp04186/index.html
//A counter using locks

#ifdef SATABS
#define assume(e) __CPROVER_assume(e)
#define assert(e) __CPROVER_assert(e,"error")
#define acquire(m) \
{ \
  __CPROVER_atomic_begin(); \
	assume(m==0); \
	m = 1; \
	__CPROVER_atomic_end(); \
}
#define release(m) \
{ \
  __CPROVER_atomic_begin(); \
	assume(m==1); \
	m = 0; \
	__CPROVER_atomic_end(); \
}
#endif

volatile unsigned value, m = 0;

unsigned thr1() {
	unsigned v = 0;

	acquire(m);
	if(value == 0u-1) {
		release(m);

		return 0;
	}else{

		v = value;
		value = v + 1;
		release(m);

		assert(value > v); 

		return v + 1;
	}
}

#ifdef SATABS
int main(){
	while(1) { __CPROVER_ASYNC_01: thr1(); }
}
#endif
