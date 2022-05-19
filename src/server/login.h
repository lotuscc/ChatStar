#include <iostream>
#include <mysqlx/xdevapi.h>
#include <string>

using namespace ::mysqlx;

class ell_login {
public:
    static bool login(std::string name, std::string passwd) {
        {
            Session sess("localhost", 33060, "root", "123");
            Schema db = sess.getSchema("ell_db");

            Table employees = db.getTable("user_login");

            RowResult res = employees.select("user_name", "user_passwd")
                                .where("user_name=:name")
                                .bind("name", name)
                                .execute();
            Row row;
            while ((row = res.fetchOne())) {
                std::cout << "user_name: " << row[0] << std::endl;
                std::cout << "user_passwd: " << row[1] << std::endl;

                return ((std::string)row[0] == name) &&
                       ((std::string)row[1] == passwd);
            }

            return false;
        }
    }
};