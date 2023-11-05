#include "../model/utils/StaffUtils.cpp"

void ManageStaff() {
    char cmd;
    std::cout << "Managing staff..." << std::endl;
    while (true) {
        std::cout << "1. Create staff [-count]" << std::endl
                  << "2. Update staff by id" << std::endl
                  << "3. Delete staff by id" << std::endl
                  << "4. List staff" << std::endl
                  << "5. Return to main menu" << std::endl
                  << std::endl
                  << "Enter option: ";
        std::cin >> cmd;

        unsigned count;
        ResultCode res;
        std::vector<Staff> staff;
        std::string id;

        switch (cmd) {
            case '1':
                count = 1;
                std::cout << "Enter count of staff to create" << std::endl;
                std::cin >> count;
                res = CreateStaff(count);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '2':
                std::cout << "Enter ID of staff to update" << std::endl;
                std::cin >> id;
                res = UpdateStaff(id);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '3':
                std::cout << "Enter ID of staff to delete" << std::endl;
                std::cin >> id;
                res = DeleteStaff(id);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '4':
                std::cout << "List of staff" << std::endl;

                res = ListStaff(&staff);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                for (Staff &s: staff) {
                    std::cout << "Staff: " << std::endl;
                    std::cout << s;
                    std::cout << "-----------------------\n";
                }
                break;
            case '5':
                return;
            default:
                std::cout << "Invalid option!" << std::endl;
        }

    }
}