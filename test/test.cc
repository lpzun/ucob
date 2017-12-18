/**
 * test.cc
 *
 *  Created on: Dec 7, 2017
 *      Author: Peizun Liu
 */

#include "../src/bws/bws.hh"

using namespace ucob;

int test_main(int argc, char *argv[]) {
	/*
	 shared_state s(1);
	 local_state l1(5, 0);
	 local_state l2(10, 0);
	 ca_locals locals;
	 locals.emplace(l1, 1);
	 locals.emplace(l2, 1);
	 worklist.emplace(s, locals);
	 */
	int N = 11;
	vector<string> filenames(N, "");
	vector<bool> reachability(N, true);
	for (int i = 0; i < N; ++i) {
		filenames[i] =
				"/users/lpzun/Peizun/Develop/C++/workspace/ucob/examples/test"
						+ std::to_string(i + 1) + ".bp";
	}
	reachability[2] = false;

	BWS bws;
	for (int i = 0; i < N; ++i) {
		bool is_reachable = bws.coverability_analysis(filenames[i]);
		cout << filenames[i] << " " << is_reachable << "\n";
		if (reachability[i] == is_reachable)
			cout << "Testing on " << filenames[i] << " passed!\n";
		else
			throw ucob_runtime_error(
					"Testing on " + filenames[i] + " failed!\n");
	}
	return 0;
}
