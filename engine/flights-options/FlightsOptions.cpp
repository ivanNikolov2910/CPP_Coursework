#include <limits>
#include "../../constants/constants.h."
#include "../../model/Plane.h"
#include "../../model/utils/PlaneUtils.cpp"
#include "../../model/utils/RunwayUtils.cpp"
#include "../../model/Runway.h"

#define FUEL_PRICE_PER_LITER 3.59
#define PILOT_SALARY_PER_FLIGHT 800
#define STEWARD_SALARY_PER_FLIGHT 550

struct resultData
{
    ResultCode res;
    Runway runway;
    Plane *plane;
};

resultData *recommendedPlanesByFlight(std::vector<Plane> &, const Flight &);

double calculateExpensesForFlight(const Plane &, const Flight &);

ResultCode assignPlane(Flight *, std::vector<Plane> &);

ResultCode FlightsManagingOptions(std::vector<Flight> &flights)
{
    char cmd;
    ResultCode res;
    resultData *pResultData;
    std::vector<Plane> planes;
    std::vector<Plane> planesFilterdByType;
    Flight *flightToAssign;
    std::string flightId;

    while (true)
    {
        std::cin >> cmd;
        switch (cmd)
        {
        case '1':
            std::cout << "Assign plane to flight" << std::endl;
            res = ListPlanes(&planes);
            if (res != success)
            {
                std::cout << "No planes found to list" << std::endl;
                break;
            }
            for (const Flight &f : flights)
            {
                std::cout << "Flight:" << std::endl;
                std::cout << f;
                std::cout << "-----------------------\n";
            }
            std::cout << "Enter flight id: ";
            while (true)
            {
                std::cin >> flightId;
                if (!std::regex_match(flightId, FLIGHT_ID_PATTER))
                {
                    std::cout << "FLight id not valid" << std::endl;
                    continue;
                }
                break;
            }
            for (Flight &f : flights)
            {
                if (f.getId() == flightId)
                {
                    flightToAssign = &f;
                    break;
                }
            }

            if (flightToAssign == nullptr)
            {
                std::cout << "Flight not found" << std::endl;
                break;
            }

            res = assignPlane(flightToAssign, planes);
            if (res != success)
            {
                std::cout << "An error happened, flight is not assign" << std::endl;
                break;
            }
            std::cout << "Flight is assign to file" << std::endl;
            break;
        case '2':
            std::cout << "Search for recommended plane for flight" << std::endl;
            for (const Flight &f : flights)
            {
                std::cout << "Flight:" << std::endl;
                std::cout << f;
                std::cout << "-----------------------\n";
            }
            std::cout << "Enter flight id: ";
            while (true)
            {
                std::cin >> flightId;
                if (!std::regex_match(flightId, FLIGHT_ID_PATTER))
                {
                    std::cout << "FLight id not valid" << std::endl;
                    continue;
                }
                break;
            }
            for (Flight &f : flights)
            {
                if (f.getId() == flightId)
                {
                    flightToAssign = &f;
                    break;
                }
            }

            if (flightToAssign == nullptr)
            {
                std::cout << "Flight not found" << std::endl;
                break;
            }

            for (Plane &p : planes)
            {
                if (flightToAssign->getType() == cargo)
                {
                    if (instanceof <CargoPlane>(&p))
                    {
                        planesFilterdByType.push_back(p);
                    }
                }
                if (flightToAssign->getType() == passenger)
                {
                    if (instanceof <PassengerPlane>(&p))
                    {
                        planesFilterdByType.push_back(p);
                    }
                }
            }

            pResultData = recommendedPlanesByFlight(planesFilterdByType, *flightToAssign);
            if (pResultData == nullptr || pResultData->res == internal_error)
            {
                std::cout << "Could not process data to find best plane" << std::endl;
                break;
            }
            std::cout << "Plane: " << pResultData->plane << " on Runway: " << pResultData->runway << std::endl;

            std::cout << "Do you want to assign this plane: [y/n]";
            std::cin >> cmd;
            if (cmd == 'y')
            {
                std::fstream file;
                file.open(ASSIGN_FLIGHTS_FILE_PATH, std::fstream::app);
                if (!file)
                {
                    std::cout << "Failed to open the file." << std::endl;
                    break;
                }
                file << pResultData->plane << flightToAssign << pResultData->runway << "\n";
                file.close();
            }
            break;
        case '3':
            return success;
        default:
            std::cout << "Invalid option" << std::endl;
        }
    }
}

ResultCode assignPlane(Flight *flight, std::vector<Plane> &planes)
{
    Runway runwayToAssign;
    Type flightType = flight->getType();
    std::fstream file;

    std::vector<Runway> runways;

    ResultCode res = ListRunway(&runways);
    if (res != success)
    {
        std::cout << "Could not list runways" << std::endl;
        return internal_error;
    }

    std::sort(runways.begin(), runways.end());

    file.open(ASSIGN_FLIGHTS_FILE_PATH, std::fstream::app);
    if (!file)
    {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (Plane &p : planes)
    {
        if (flightType == cargo && instanceof <CargoPlane>(&p))
        {
            for (const Runway &r : runways)
            {
                if (flight->getDistance() >= r.getLength())
                {
                    file << p << flight << r << "\n";
                    break;
                }
            }
        }
        else if (flightType == passenger && instanceof <PassengerPlane>(&p))
        {
            for (const Runway &r : runways)
            {
                if (flight->getDistance() >= r.getLength())
                {
                    file << p << flight << r << "\n";
                    break;
                }
            }
        }
        else
        {
            std::cout << "Unknown plane type" << std::endl;
            file.close();
            return internal_error;
        }
    }

    if (file.is_open())
    {
        file.close();
    }

    return success;
}

resultData *recommendedPlanesByFlight(std::vector<Plane> &planes, const Flight &flight)
{
    auto *result = new resultData;
    result->res = internal_error;

    double minExpense = std::numeric_limits<double>::max();
    std::vector<Runway> runways;

    ResultCode res = ListRunway(&runways);
    if (res != success)
    {
        std::cout << "Could not list runways" << std::endl;
        return nullptr;
    }

    for (Plane &p : planes)
    {
        double totalExpense = calculateExpensesForFlight(p, flight);
        for (const Runway &r : runways)
        {
            int runwayLengthDiff = p.getRunwayLength() - r.getLength();

            if (totalExpense < minExpense && runwayLengthDiff >= 0)
            {
                minExpense = totalExpense;
                result->res = success;
                result->plane = &p;
                result->runway = r;
            }
        }
    }

    return result;
}

double calculateExpensesForFlight(const Plane &plane, const Flight &flight)
{
    double fuelCost = flight.getDistance() * plane.getFuelPerKilometer() * FUEL_PRICE_PER_LITER;
    double staffSalary = flight.getDistance() * ((static_cast<int>(flight.getDistance() / 1000) + 1 * STEWARD_SALARY_PER_FLIGHT) * plane.getStewardCount() + (static_cast<int>(flight.getDistance() / 1000) + 1 * PILOT_SALARY_PER_FLIGHT)) * plane.getPilotCount();

    return fuelCost + staffSalary;
}
