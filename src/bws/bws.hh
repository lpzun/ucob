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

#include "../../../ijit/src/ijit.hh"

using namespace ijit;

namespace ucob {

using antichain = deque<prog_state>;

class BWS {
public:
	BWS();
	~BWS();

	bool coverability_analysis(const string& filename);

private:
	unordered_map<uint, set<local_state>> initl_TS;
	deque<prog_thread> final_TS;

	bool standard_BWS();

	bool is_reached(const prog_state& tau);
	bool is_covered(const prog_state& tau1, const prog_state& tau2);
	bool is_minimal(const prog_state& tau, const antichain& W);
	void minimize(const prog_state& tau, antichain& W);
};

class pri_queue {
public:
	pri_queue() :
			id(0), worklist() {
	}

	~pri_queue() {
	}

	bool empty();
	void enqueue(const prog_state& e);
	prog_state dequeue();
	size_t size();
private:
	size_tc id;
	vector<queue<prog_state, deque<prog_state>>> worklist;
};

} /* namespace ucob */

#endif /* BWS_BWS_HH_ */
