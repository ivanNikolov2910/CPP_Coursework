#ifndef COURSEWORK_FLIGHTOPTIONS_H
#define COURSEWORK_FLIGHTOPTIONS_H

#include <limits>
#include "../../model/corp-data/Flight.h"
#include "../../model/plane/CargoPlane.h"
#include "../../model/plane/PassengerPlane.h"
#include "../../model/utils/RunwayUtils.h"
#include "../../model/utils/PlaneUtils.h"

#define FUEL_PRICE_PER_LITER 3.59
#define PILOT_SALARY_PER_FLIGHT 800
#define STEWARD_SALARY_PER_FLIGHT 550

struct ResultData {
    ResultCode res = not_found_error;
    Runway *runway{};
    Plane *plane{};

    ResultData() = default;

    ResultData(ResultCode res, Runway *runway, Plane *plane) {
        this->res = res;
        this->runway = runway;
        this->plane = plane;
    }
};

double calculateExpensesForFlight(const Plane &, const Flight &);

ResultCode assignPlane(const Flight &, const std::vector<Plane *> &, const std::vector<Runway> &);

ResultData *
recommendedPlanesByFlight(const std::vector<Plane *> &, const Flight &, const std::vector<Runway> &);

ResultCode
applicablePlanesPerFlight(const std::vector<Plane *> &, const Flight &, const Runway &, std::vector<Plane *> *out);

ResultCode FlightsManagingOptions(std::vector<Flight> &);

#endif //COURSEWORK_FLIGHTOPTIONS_H
