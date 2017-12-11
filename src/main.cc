/******************************************************************************
 * Synopsis	 [UCOB Unbounded-thread COverability analysis for Boolean programs]
 *
 * Developer     [Peizun Liu]
 *
 * (C) 2015 - 2018 Peizun Liu, Northeastern University, United States
 *
 * All rights reserved. Redistribution and use in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgment:
 *
 *    This product includes software developed by Peizun Liu @ Thomas Wahl's
 *    group, Northeastern University, United States and its contributors.
 *
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS `AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#include <iostream>

#include "util/cmd.hh"
#include "util/refs.hh"
#include "bws/bws.hh"

using namespace ucob;
using namespace std;

int main(const int argc, const char * const * const argv) {
	try {
		cmd_line cmd;
		try {
			cmd.get_command_line(argc, argv);
		} catch (cmd_line::Help) {
			return 0;
		}

//		refer::OPT_PRINT_ADJ = cmd.arg_bool(cmd_line::prob_inst_opts(),
//				"--adj-list");
//		refer::OPT_PRINT_ALL = cmd.arg_bool(cmd_line::other_opts(), "--all");
		const string& filename = cmd.arg_value(cmd_line::prob_inst_opts(),
				"--input-file");
//		const string& initl_ts = cmd.arg_value(cmd_line::prob_inst_opts(),
//				"--initial");
//		const string& final_ts = cmd.arg_value(cmd_line::prob_inst_opts(),
//				"--target");

		BWS bws;
		bool is_reachable = bws.coverability_analysis(filename);
		cout << "======================================================\n";
		cout << " final state ";
		if (is_reachable)
			cout << "is reachable: verification failed!\n";
		else
			cout << "is unreachable: verification successful!\n";
		cout << "======================================================"
				<< endl;

	} catch (const ucob_exception & e) {
		e.what();
	} catch (const std::exception& e) {
		std::cerr << e.what() << endl;
	} catch (...) {
		std::cerr << ucob_exception("main: unknown exception occurred").what()
				<< endl;
	}
}
