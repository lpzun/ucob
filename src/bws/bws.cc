/**
 * @brief BWS.cc
 *
 * @date  : Jun 18, 2016
 * @author: lpzun
 */

#include "bws.hh"

namespace ucob {

BWS::BWS() :
		initl_TS(), final_TS() {
}

BWS::~BWS() {

}

bool BWS::coverability_analysis(const string& filename) {
	const auto& states = parser::parse(filename, mode::PREV);

	cout << "initial states...\n";
	for (const auto& i : states.first) {
		cout << i << endl;
		initl_TS[i.get_s().get_vars().to_ulong()].emplace(i.get_l());
	}

	final_TS = states.second;
	cout << "target states...\n";
	for (const auto& f : final_TS) {
		cout << f << endl;
	}
	return standard_BWS();
}

/**
 * The BWS which operates directly on Boolean programs.
 * @return bool
 *         true : if final state is coverable
 *         false: otherwise
 */
bool BWS::standard_BWS() {
	/// step 0: set up the preliminaries needed for BWS
	///   (1) initialize worklist
	queue<prog_state, deque<prog_state>> worklist;

	for (const auto& final : final_TS) {
		worklist.emplace(final.get_s(), final.get_l());
	}
	/*
	 shared_state s(1);
	 local_state l1(5, 0);
	 local_state l2(10, 0);
	 ca_locals locals;
	 locals.emplace(l1, 1);
	 locals.emplace(l2, 1);
	 worklist.emplace(s, locals);

	 */

	///   (2) the set of already expanded states
	vector<antichain> expanded(1 << ijit::refs::SV_NUM);

	///   (3) declare pre_image computation
	pre_image preimage;

	while (!worklist.empty()) {
		const auto _tau = worklist.front();
		worklist.pop();

		/// step 1: if \exists t \in <expanded> such that
		///         t <= _tau then discard _tau
		const auto& s = _tau.get_s().get_vars().to_ulong();
		if (!is_minimal(_tau, expanded[s])) {
			continue;
		}

		cout << "tau' = " << _tau << endl;

		/// step 2: compute all cover preimages and handle
		///         them one by one
		const auto& images = preimage.step(_tau, prev::COV);
		for (const auto& tau : images) {
			/// if tau \in upward(T_init), return true;
			cout << "  " << tau << endl;
			if (is_reached(tau)) {
				cout << "reachable........." << tau << endl;
				return true;
			}
			/// otherwise, push \tau into the worklist.
			worklist.emplace(tau);
		}
		/// step 5: insert _tau into the expanded states
		minimize(_tau, expanded[s]);
		expanded[s].emplace_back(_tau);
	}
	return false;
}

/**
 * To determine if s belongs to upward-closure of initial states
 *
 * This is not quite correct, need to be rewritten
 *
 * we can build a fake initial thread state, say (0, 0), and let
 * it point to every real initial thread state.
 * @param s
 * @return true : if s is in the upward-closure of initial state
 *         false: otherwise
 */
bool BWS::is_reached(const prog_state& tau) {
	auto ifind = initl_TS.find(tau.get_s().get_vars().to_ulong());
	if (ifind != initl_TS.end()) {
		for (const auto& pl : tau.get_locals()) {
			if (ifind->second.find(pl.first) == ifind->second.end())
				return false;
		}
		return true;
	}
	return false;
}

/**
 * Check whether tau is minimal or not.
 * @param tau:
 * @param W  : the set of expanded program states
 * @return bool
 *         true : if exists w such that w <= tau
 *         false: otherwise
 */
bool BWS::is_minimal(const prog_state& tau, const antichain& W) {
	for (const auto& w : W) {
		if (is_covered(w, tau))
			return false;
	}
	return true;
}

/**
 * To determine if tau is the minimal state in W
 * @param tau:
 * @param W  :
 */
void BWS::minimize(const prog_state& tau, antichain& W) {
	auto iw = W.begin();
	while (iw != W.end()) {
		if (is_covered(tau, *iw)) {
			iw = W.erase(iw);
		} else {
			++iw;
		}
	}
}

/**
 * To determine whether s1 is covered by s2.
 *        NOTE: this function assumes that the local parts of s1 and s2
 *        are ordered.
 * @param s1
 * @param s2
 * @return true : if s1 <= s2
 *         false: otherwise
 */
bool BWS::is_covered(const prog_state& tau1, const prog_state& tau2) {
	if (tau1.get_s() != tau2.get_s()
			|| tau1.get_locals().size() > tau2.get_locals().size())
		return false;

	auto is1 = tau1.get_locals().cbegin();
	auto is2 = tau2.get_locals().cbegin();
	while (is1 != tau1.get_locals().cend()) {
		/// check if is2 reaches to the end
		if (is2 == tau2.get_locals().cend())
			return false;
		/// compare the map's contents
		if (is1->first == is2->first) {
			if (is1->second <= is2->second)
				++is1, ++is2;
			else
				return false;
		} else if (is1->first > is2->first) {
			++is2;
		} else if (is1->first < is2->first) {
			return false;
		}
	}
	return true;
}

} /* namespace ucob */
