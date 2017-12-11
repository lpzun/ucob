/**
 * @brief using it for debugging
 *
 * @name debug.hh
 *
 * @date  : Oct 2, 2013
 * @author: Peizun Liu
 */

#ifndef DEBUG_HH_
#define DEBUG_HH_

// #define DEBUGGING

#ifdef DEBUGGING
#  define DEBUG_LOG(x) std::cerr << x <<"\n";
#  define DEBUG_STD(x) x;
#  define DEBUG_LOC() std::cerr <<__func__<<" I am here ..."<<"\n";
#else
#  define DEBUG_LOG(x)
#  define DEBUG_STD(x)
#  define DEBUG_LOC();
#endif // DEBUG

namespace ucob {
class debugger {
public:
    debugger();
    virtual ~debugger();
};
}
#endif /* DEBUG_HH_ */
