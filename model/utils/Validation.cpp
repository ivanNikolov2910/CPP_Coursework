#include "../../constants/constants.h"

ResultCode validateId(string id, std::regex reg) {
    if (std::regex_match(id, reg)) {
        return success;
    }
    return validation_error;
}