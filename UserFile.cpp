#include "UserFile.h"

vector <User> UserFile::fetchUsersDataFromFile() {

    User user;
    vector <User> users;
    xml.Load(NAME_OF_USER_FILE.c_str());

    xml.FindElem("USER_INFO");
    xml.IntoElem();
    while (xml.FindElem( "USER" )) {
        xml.IntoElem();
        xml.FindElem("USER_ID");
        user.setId(atoi( MCD_2PCSZ(xml.GetData()) ));
        xml.FindElem("LOGIN");
        user.setLogin(xml.GetData());
        xml.FindElem("PASSWORD");
        user.setPassword(xml.GetData());
        xml.FindElem("NAME");
        user.setName(xml.GetData());
        xml.FindElem("SURNAME");
        user.setSurname(xml.GetData());
        users.push_back(user);
        xml.OutOfElem();
    }
    return users;
}

void UserFile::appendUserToFile(User user) {

    xml.Load(NAME_OF_USER_FILE.c_str());
    if (ifFileIsEmpty()) {
        xml.AddElem( "USER_INFO" );
        xml.IntoElem();
        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem( "USER_ID", user.getId() );
        xml.AddElem( "LOGIN", user.getLogin() );
        xml.AddElem( "PASSWORD", user.getPassword() );
        xml.AddElem( "NAME", user.getName() );
        xml.AddElem( "SURNAME", user.getSurname());
        xml.OutOfElem();
    } else {
        xml.FindElem( "USER_INFO" );
        xml.IntoElem();
        xml.AddElem( "USER" );
        xml.IntoElem();
        xml.AddElem( "USER_ID", user.getId() );
        xml.AddElem( "LOGIN", user.getLogin() );
        xml.AddElem( "PASSWORD", user.getPassword() );
        xml.AddElem( "NAME", user.getName() );
        xml.AddElem( "SURNAME", user.getSurname());
        xml.OutOfElem();
    }

    MCD_STR strXML = xml.GetDoc();
    xml.Save("users.xml");
}
