/**
 * @brief BWS.hh
 *
 * @date  : Jun 18, 2016
 * @author: lpzun
 */

#ifndef BWS_BWS_HH_
#define BWS_BWS_HH_

#include "../util/excep.hh"
#include "../util/debug.hh"
#include "../util/refs.hh"

#include "ijit.hh"

using namespace ijit;

namespace ucob {

using antichain = deque<prog_state>;

class BWS {
public:
    BWS();
    ~BWS();

private:
    deque<prog_thread> initl_TS;
    deque<prog_thread> final_TS;

    bool standard_BWS();

    bool is_reached(const prog_state& tau);
    bool is_covered(const prog_state& tau1, const prog_state& tau2);
    bool is_minimal(const prog_state& tau, const antichain& W);
    void minimize(const prog_state& tau, antichain& W);

};

} /* namespace ucob */

#endif /* BWS_BWS_HH_ */
