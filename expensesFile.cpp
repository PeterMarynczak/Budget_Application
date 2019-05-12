#include "expensesFile.h"

int ExpensesFile::getIdOfLastExpense(){
    return idOfLastAddedExpense;
}

bool ExpensesFile::appendExpenseToFile(Expense expense){

    xml.Load(NAME_OF_EXPENSES_FILE.c_str());

    if (ifFileIsEmpty()) {
        xml.AddElem( "EXPENSES" );
    }
        xml.FindElem( "EXPENSES" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE_ID", expense.getExpenseId() );
        xml.AddElem( "USER_ID", expense.getUserId() );
        xml.AddElem( "DATE", expense.getDate() );
        xml.AddElem( "ITEM", expense.getItem() );
        xml.AddElem( "AMOUNT", expense.getAmount());
        xml.OutOfElem();

    MCD_STR strXML = xml.GetDoc();
    xml.Save(NAME_OF_EXPENSES_FILE.c_str());
    idOfLastAddedExpense++;
    if (idOfLastAddedExpense > 0)
        return true;
    else return false;
}

vector <Expense> ExpensesFile::fetchExpensesOfLoggedUserFromFile(int idOfLoggedUser){

    Expense expense;
    vector <Expense> expenses;
    int idOfLastExpense = 0;

    xml.Load(NAME_OF_EXPENSES_FILE.c_str());

    xml.ResetPos();
    xml.FindElem("EXPENSES");
    xml.IntoElem();
    while (xml.FindElem("EXPENSES")){
        xml.IntoElem();
        xml.FindElem("USER_ID");
        int getUserIdFromXMLfile = atoi( MCD_2PCSZ(xml.GetData()));
        if (getUserIdFromXMLfile == idOfLoggedUser){
            xml.ResetMainPos();
            xml.FindElem("EXPENSE");
            idOfLastExpense = (atoi( MCD_2PCSZ(xml.GetData())));
            expense.setExpenseId(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("USER_ID");
            expense.setUserId(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem("DATE");
            expense.setDate(xml.GetData());
            xml.FindElem("ITEM");
            expense.setItem(xml.GetData());
            xml.FindElem("AMOUNT");
            expense.setAmount(xml.GetData());
            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    if (idOfLastExpense != 0){
        idOfLastAddedExpense = idOfLastExpense;
    }
    return expenses;
}
