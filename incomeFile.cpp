#include "incomeFile.h"

int IncomeFile::getIdOfLastIncome(){
    return idOfLastAddedIncome;
}

void IncomeFile::appendIncomeToFile(Income income){

    xml.Load(NAME_OF_INCOME_FILE.c_str());

    if (ifFileIsEmpty()) {
        xml.AddElem( "INCOMES" );
    }
        xml.FindElem( "INCOMES" );
        xml.IntoElem();
        xml.AddElem( "INCOME" );
        xml.IntoElem();
        xml.AddElem( "INCOME_ID", income.getIncomeId() );
        xml.AddElem( "USER_ID", income.getUserId() );
        xml.AddElem( "DATE", income.getDate() );
        xml.AddElem( "ITEM", income.getItem() );
        xml.AddElem( "AMOUNT", income.getAmount());
        xml.OutOfElem();

    MCD_STR strXML = xml.GetDoc();
    xml.Save(NAME_OF_INCOME_FILE.c_str());

}

vector <Income> IncomeFile::fetchIncomesOfLoggedUserFromFile(int idOfLoggedUser){

    Income income;
    vector <Income> incomes;
    xml.Load(NAME_OF_INCOME_FILE.c_str());

    xml.ResetPos();
    xml.FindElem("INCOMES");
    xml.IntoElem();
    while (xml.FindElem("INCOME")){
        xml.IntoElem();
        xml.FindElem("USER_ID");
        int getUserIdFromXMLfile = atoi( MCD_2PCSZ(xml.GetData()));
        if (getUserIdFromXMLfile == idOfLoggedUser){
            xml.ResetMainPos();
            xml.FindElem("INCOME_ID");
            income.setIncomeId(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("USER_ID");
            income.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("DATE");
            income.setDate(xml.GetData());
            xml.FindElem("ITEM");
            income.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            income.setAmount(xml.GetData());
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}
