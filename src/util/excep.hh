/**
 * @name excep.hh
 *
 * @date Jan 12, 2015
 * @author Peizun Liu
 */

#ifndef EXCEP_HH_
#define EXCEP_HH_

#include <stdexcept>
#include <exception>
#include <string>

using std::runtime_error;
using std::exception;
using std::string;
namespace ucob {
/**
 * Customized runtime error
 */
class ucob_runtime_error: public runtime_error {
public:
    ucob_runtime_error() :
            runtime_error("") {
    }
    ucob_runtime_error(const std::string& msg) :
            runtime_error(msg) {
    }
};

/**
 * Customized exception
 */
class ucob_exception: public exception {
public:
    string message;
    short code;
    inline ucob_exception() :
            message(""), code(-1) {

    }
    inline ucob_exception(const string& message, const short& code = -1) :
            message(message), code(code) {
    }    // must provide some message

    virtual const char* what() const throw () {
        return message.c_str();
    }
};
}
#endif /* EXCEP_HH_ */
