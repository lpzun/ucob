/**
 * @name refs.cc
 *
 * @date: Jun 21, 2015
 * @author: Peizun Liu
 */

#include "refs.hh"

namespace ucob {

refer::refer() {

}

refer::~refer() {

}
bool refer::OPT_INPUT_TTS = false;

bool refer::OPT_PRINT_ADJ = false;
bool refer::OPT_PRINT_CMD = false;
bool refer::OPT_PRINT_ALL = false;

clock_t refer::ELAPSED_TIME = clock();

const ushort refer::omega = std::numeric_limits<ushort>::max();

} /* namespace SURA */
