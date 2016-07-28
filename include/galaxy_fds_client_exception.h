/**
 * Copyright 2015, Xiaomi.
 * All rights reserved.
 * Author: zhangjunbin@xiaomi.com
 */

#ifndef GALAXY_FSD_CLIENT_EXCEPTION_H_
#define GALAXY_FSD_CLIENT_EXCEPTION_H_

#include <string>
#include <exception>

namespace galaxy {
namespace fds {

class GalaxyFDSClientException : public std::exception {
public:
  GalaxyFDSClientException(const std::string& message) {
		this->status = -1;
    this->message = message;
  }
  GalaxyFDSClientException(const int status,
			                     const std::string& message) {
		this->status = status;
    this->message = message;
  }

	virtual const int code() const throw() {
		return status;
	}

  virtual const char* what() const throw() {
    return message.c_str();
  }

  ~GalaxyFDSClientException() throw() {}

private:
	// http status code, -1 if unavailable
  int status;
  std::string message;
}; // class GalaxyFDSClientException

} // namespace fds
} // namespace galaxy

#endif // GALAXY_FSD_CLIENT_EXCEPTION_H_
