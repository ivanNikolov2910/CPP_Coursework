#include "../../constants/constants.h"

ResultCode validateId(const string &id, const regex &reg) {
    if (std::regex_match(id, reg)) {
        return success;
    }
    return validation_error;
}