/**
 * @name refs.hh
 *
 * @date: Jun 21, 2015
 * @author: Peizun Liu
 */

#ifndef REFS_HH_
#define REFS_HH_
#include "heads.hh"
namespace ucob {

class refer {
public:
	refer();
	~refer();

	static bool OPT_PRINT_INITL_TS;
	static bool OPT_PRINT_FINAL_TS;

	static bool OPT_PRINT_ALL;
	static bool OPT_PRINT_CMD;
	static bool OPT_PRINT_ADJ;

	static bool OPT_INPUT_TTS;

	/// global variable for elapsed time
	static clock_t ELAPSED_TIME;

	static const ushort omega;

};
} /* namespace SURA */

#endif /* REFS_HH_ */
